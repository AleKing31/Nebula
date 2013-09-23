#ifndef __NEBULA_CONTENT_SHAPE_PHYSICS_PHYSX_BASE_HPP__
#define __NEBULA_CONTENT_SHAPE_PHYSICS_PHYSX_BASE_HPP__

#include <boost/shared_ptr.hpp>

#include <nebula/utilities/types/content/shape/types.hpp>

namespace nebula
{
	namespace content
	{
		namespace shape
		{
			namespace physics
			{
				namespace physx
				{
					class base
					{
					public:
						base();
						~base();
						void						init(const boost::shared_ptr<nebula::content::shape::admin::base>&);
						void						shutdown();
						void						create_shape();
					};
				}
			}
		}
	}
}


#endif


