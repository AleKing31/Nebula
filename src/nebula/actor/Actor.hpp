#ifndef __NEBULA_CONTENT_ACTOR_PHYSICS_ACTOR_HPP__
#define __NEBULA_CONTENT_ACTOR_PHYSICS_ACTOR_HPP__

#include <PxPhysicsAPI.h>

#include <gru/actor/actor.hpp>

#include <nebula/actor/Base.hpp>

namespace neb {
	namespace Actor {
		class Actor:
			public neb::Actor::Base
		{
			public:
				Actor(glutpp::actor::parent_s);


				virtual void			init(glutpp::actor::desc_s);
				virtual void			release();
				virtual void			add_force(double) {abort();}
				virtual void			set_pose(physx::PxTransform);
				virtual int			fire();

				virtual glutpp::actor::desc_s	get_projectile() {abort(); return NULL;}
				
				
				virtual void			create_physics() {abort();}
				virtual void			init_physics() {abort();}
				
				
				virtual void			step_local(double);
				virtual void			step_remote(double);

				virtual void			print_info();
				
				physx::PxActor*			px_actor_;
				
				//std::shared_ptr<glutpp::actor>		object_;
		};
	}
}

#endif


