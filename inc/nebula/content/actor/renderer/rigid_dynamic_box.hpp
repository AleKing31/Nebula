#ifndef __NEBULA_CONTENT_ACTOR_RENDERER_RIGID_DYNAMIC_BOX_HPP__
#define __NEBULA_CONTENT_ACTOR_RENDERER_RIGID_DYNAMIC_BOX_HPP__



#include <nebula/content/actor/renderer/rigid_dynamic.hpp>

namespace nebula
{
	namespace content
	{
		namespace actor
		{
			namespace renderer
			{
				/// rigid dynamic
				class rigid_dynamic_box:
					public n34300::rigid_dynamic
				{
				public:
					/// ctor
					rigid_dynamic_box( std::shared_ptr<n34100::base> );
					/// Copy Ctor
					rigid_dynamic_box(const rigid_dynamic_box&);
					/// Dtor
					~rigid_dynamic_box();
					/// assignment
					rigid_dynamic_box&							operator=(const rigid_dynamic_box&);

				

					/// init
					virtual	void								init();
					/// shutdown
					virtual	void								shutdown();
					/// update
					virtual	void								update();
					/// step
					virtual	void								step();
					/// render
					virtual	void								render( std::shared_ptr<n23000::base> );
				
				
				
				
					/// create shapes
					virtual	void								create_shape();
				};
			}
		}
	}
}

#endif








