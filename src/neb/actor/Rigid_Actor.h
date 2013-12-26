#ifndef __NEBULA_CONTENT_ACTOR_PHYSICS_RIGID_ACTOR_HPP__
#define __NEBULA_CONTENT_ACTOR_PHYSICS_RIGID_ACTOR_HPP__

#include <neb/actor/Actor.h>

namespace neb
{
	class shape;
	namespace actor
	{
		class Rigid_Actor:
			public neb::actor::Actor
		{
			public:
				virtual void			init() = 0;
				virtual void			add_force() = 0;
				
			
				virtual void			step_remote(double);
				virtual void			setupFiltering();
				
				virtual neb::actor::desc	get_projectile();
				virtual neb::actor::desc	get_desc();

				int				create_shapes();
		};
	}
}

#endif








