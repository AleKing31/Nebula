#ifndef __NEBULA_CONTENT_SHAPE_RENDERER_BOX_HPP__
#define __NEBULA_CONTENT_SHAPE_RENDERER_BOX_HPP__

#include <nebula/content/shape/renderer/base.hpp>

namespace nebula
{
	namespace content
	{
		namespace shape
		{
			namespace renderer
			{
				/// box
				class box:
					public n35300::base
				{
					public:
						/// ctor
						box();
						/// dtor
						~box();
						/// init
						void								init( jess::shared_ptr<n35100::box> );
						/// shutdown
						void								shutdown();
						/// render
						void								render( jess::shared_ptr<n23000::base> );

				};
			}
		}
	}
}


#endif
