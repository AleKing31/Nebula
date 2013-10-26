#ifndef __NEBULA_CONTENT_ACTOR_PHYSICS_RIGID_DYNAMIC_BOX_HPP__
#define __NEBULA_CONTENT_ACTOR_PHYSICS_RIGID_DYNAMIC_BOX_HPP__

#include <nebula/content/actor/physics/rigid_dynamic.hpp>

namespace nebula
{
	namespace content
	{
		namespace actor
		{
			namespace physics
			{
				/** \brief rigid dynamic
				*/
				class rigid_dynamic_box:
					public nebula::content::actor::physics::rigid_dynamic
				{
					protected:
						/** \brief copy ctor
						*/
						rigid_dynamic_box( rigid_dynamic_box const & );
						/** \brief assignment
						*/
						rigid_dynamic_box&				operator=( rigid_dynamic_box const & ) = default;
						/** \brief ctor
						*/
						rigid_dynamic_box( jess::shared_ptr<n34100::base> );
					public:
						/** \brief dtor
						*/
						~rigid_dynamic_box();
						/** \brief init
						*/
						virtual	void					init();
						/** \brief shutdown
						*/
						virtual	void					shutdown();
						/** \brief update
						*/
						virtual	void					update();
						/** \brief step
						*/
						virtual	void					step( float );
						/** \brief render
						*/
						virtual	void					render( n23000::base::shared_t );
						/** \brief create shapes
						*/
						virtual	void					create_shapes();
				};
			}
		}
	}
}

#endif








