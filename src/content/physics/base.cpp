#include <nebula/define.hpp>
#include <nebula/content/scene/admin/base.hpp>
#include <nebula/content/scene/physics/base.hpp>
#include <nebula/content/actor/admin/rigid_dynamic.hpp>
#include <nebula/content/actor/physics/rigid_dynamic_box.hpp>
#include <nebula/content/actor/physics/controller.hpp>
#include <nebula/content/actor/physics/material.hpp>

#include <nebula/content/physics/base.hpp>

physx::PxFilterFlags	DefaultFilterShader(
		physx::PxFilterObjectAttributes attributes0,
		physx::PxFilterData filterData0,
		physx::PxFilterObjectAttributes attributes1,
		physx::PxFilterData filterData1,
		physx::PxPairFlags& pairFlags,
		const void* constantBlock,
		physx::PxU32 constantBlockSize )
{
	return physx::PxFilterFlag::eDEFAULT;
}

n36000::base::base( jess::shared_ptr<n30000::base> parent ):
	parent_(parent)
{
	jess::clog << NEB_FUNCSIG << std::endl;
}
n36000::base::~base()
{
	jess::clog << NEB_FUNCSIG << std::endl;
}
void	n36000::base::init()
{
	jess::clog << NEB_FUNCSIG << std::endl;
	
	// Physx
	// Foundation
	px_foundation_ = PxCreateFoundation( PX_PHYSICS_VERSION, px_default_allocator_callback_, px_default_error_callback_ );
	jess::assertion( px_foundation_ );

	bool recordMemoryAllocations = true;

	// Profile Zone Manager
	px_profile_zone_manager_ = &::physx::PxProfileZoneManager::createProfileZoneManager( px_foundation_ );
	jess::assertion( px_profile_zone_manager_ );

	// Physics
	px_physics_ = PxCreatePhysics( PX_PHYSICS_VERSION, *px_foundation_, ::physx::PxTolerancesScale(), recordMemoryAllocations, px_profile_zone_manager_ );
	jess::assertion( px_physics_ );

	// cooking
	px_cooking_ = PxCreateCooking( PX_PHYSICS_VERSION, *px_foundation_, ::physx::PxCookingParams() );
	jess::assertion( px_cooking_ );

	// Extensions
	jess::assertion( ::PxInitExtensions( *px_physics_ ) );

	// character controller manager
	px_character_controller_manager_ = ::PxCreateControllerManager( *px_foundation_ );
	jess::assertion( px_character_controller_manager_ );
	
	
	// default material
	default_material_ = create_physics_material();
}
void	n36000::base::shutdown()
{
	jess::clog << NEB_FUNCSIG << std::endl;

	px_physics_->release();
	px_foundation_->release();
}
jess::shared_ptr<n32200::base>		n36000::base::create_scene()
{
	jess::clog << NEB_FUNCSIG << std::endl;

	jess::shared_ptr<n32200::base> scene( new n32200::base() );

	physx::PxSceneDesc scene_desc( px_physics_->getTolerancesScale() );

	scene_desc.gravity = physx::PxVec3(0,-9.81,0);

	scene->customize_scene_desc( scene_desc );

	int m_nbThreads = 1;

	// cpu dispatcher
	if( !scene_desc.cpuDispatcher )
	{
		::physx::PxDefaultCpuDispatcher* cpuDispatcher = ::physx::PxDefaultCpuDispatcherCreate( m_nbThreads );
		jess::assertion( cpuDispatcher );

		scene_desc.cpuDispatcher = cpuDispatcher;
	}

	// filter shader
	if( !scene_desc.filterShader )
	{
		if ( scene->px_default_filter_shader_ )
		{
			scene_desc.filterShader = scene->px_default_filter_shader_;
		}
		else
		{
			scene_desc.filterShader = DefaultFilterShader;
		}
	}

	// gpu dispatcher
#ifdef PX_WINDOWS
	if( !scene_desc.gpuDispatcher && m_cudaContextManager )
	{
		sceneDesc.gpuDispatcher = m_cudaContextManager->getGpuDispatcher();
	}
#endif

	jess::assertion( scene_desc.isValid() );

	scene->px_scene_ = px_physics_->createScene( scene_desc );

	jess::assertion( scene->px_scene_ );

	return scene;
}
jess::shared_ptr<n34200::rigid_dynamic>		n36000::base::create_rigid_dynamic(
		jess::shared_ptr<n32100::base> scene,
		jess::shared_ptr<n34100::base> actor
		)
{
	jess::clog << NEB_FUNCSIG << std::endl;

	// create
	jess::shared_ptr<n34200::rigid_dynamic> act( new n34200::rigid_dynamic( actor ) );

	// create
	physx::PxRigidDynamic* px_actor = px_physics_->createRigidDynamic( physx::PxTransform() );

	act->px_actor_ = px_actor;

	return act;
}
jess::shared_ptr<n34200::rigid_dynamic_box>	n36000::base::create_rigid_dynamic_box(
		jess::shared_ptr<n32100::base> scene,
		jess::shared_ptr<n34100::base> actor
		)
{
	jess::clog << NEB_FUNCSIG << std::endl;
	
	// create
	jess::shared_ptr<n34200::rigid_dynamic_box> physics( new n34200::rigid_dynamic_box( actor ) );
	
	// create
	physx::PxRigidDynamic* px_actor = px_physics_->createRigidDynamic( physx::PxTransform() );

	physics->px_actor_ = px_actor;

	return physics;
}
jess::shared_ptr<n34200::controller>		n36000::base::create_controller(
		jess::shared_ptr<n32100::base> scene,
		jess::shared_ptr<n34100::base> actor
		)
{
	jess::clog << NEB_FUNCSIG << std::endl;

	

	// create
	jess::shared_ptr<n34200::controller> physics ( new n34200::controller( actor ) );
	
	physics->material_ = request_physics_material();
	NEB_ASSERT( physics->material_->px_material_ );
	
	// description 
	physx::PxExtendedVec3 position(0,0,0);
	
	physx::PxCapsuleControllerDesc desc;
	desc.position = position;
	desc.height = 1.0;
	desc.radius = 0.5;
	desc.scaleCoeff = 1.0;
	desc.volumeGrowth = 2.0;
	desc.density = 1000.0;
	desc.slopeLimit = 0.707;
	desc.stepOffset = 1.0;
	desc.contactOffset = 1.0;
	desc.material = physics->material_->px_material_;
	desc.climbingMode = physx::PxCapsuleClimbingMode::eEASY;
	
	// assert
	jess::assertion( px_character_controller_manager_ );
	jess::assertion( px_physics_ );
	jess::assertion( scene->physics_->px_scene_ );
	NEB_ASSERT( desc.isValid() );

	physx::PxController* px_cont = px_character_controller_manager_->createController( *px_physics_, scene->physics_->px_scene_, desc );

	physics->px_controller_ = px_cont;

	jess::assertion( px_cont );

	return physics;
}
jess::shared_ptr<n34200::material>		n36000::base::request_physics_material()
{
	NEB_ASSERT( bool( default_material_ ) );
	return default_material_;
}
jess::shared_ptr<n34200::material>		n36000::base::create_physics_material()
{
	jess::shared_ptr<n34200::material> material( new n34200::material );
	
	material->px_material_ = px_physics_->createMaterial(1,1,1);
	
	return material;
}


void 	DefaultErrorCallback::reportError( physx::PxErrorCode::Enum code, char const * message, char const * file, int line)
{
	printf("%s:%i: %s\n",file,line,message);
}

