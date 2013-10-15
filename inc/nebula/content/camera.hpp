#ifndef __NEBULA_CONTENT_CAMERA_HPP__
#define __NEBULA_CONTENT_CAMERA_HPP__

#include <jess/shared_ptr.hpp>

namespace nebula
{
	namespace content
	{
		/// camera
		class camera
		{
		public:
			/// ctor
			camera();
			/// render
			void									render( jess::shared_ptr<n23000::base> );

			/// controller
			jess::shared_ptr<n34100::controller>		controller_;
		};
	}
}



#endif

