#ifndef __NEBULA_NS_HPP__
#define __NEBULA_NS_HPP__

/// %nebula
namespace nebula
{
	/** \breif %framework
	 * Contains the application class.
	 */
	namespace framework
	{
		class app;
		class renderable;
	}

	/** \breif %platform
	 *
	 */
	namespace platform
	{
		class key;

		/** \breif %platform
		 *
		 */
		namespace platform
		{
			class base;

			/** \breif %linux
			 *
			 */
			namespace lin
			{
				class base;
			}
			namespace win
			{
				class base;
			}
		}
		namespace window
		{
			class base;

			namespace lin
			{
				class base;
			}
			namespace win
			{
				class base;
			}
		}
		namespace renderer
		{
			class base;
			class scoped_matrix;
			class scoped_render;
			class scoped_2d_environment;
			class scoped_3d_environment;

			namespace gl
			{
				class base;	

				namespace glx
				{
					class base;
				}
			}
		}
	}

	namespace content
	{
		class base;
		class camera;

		namespace physics
		{
			class base;
		}
		namespace universe
		{
			namespace admin
			{
				class base;
			}
		}
		namespace scene
		{
			namespace admin
			{
				class base;
			}
			namespace physics
			{
				class base;	

			}
			namespace renderer
			{
				class base;
			}
		}
		namespace view
		{
			namespace admin
			{
				class base;
			}
		}
		namespace actor
		{
			namespace admin
			{
				class base;
				class actor;
				class rigid_actor;
				class rigid_body;
				class rigid_dynamic;
				class rigid_dynamic_box;
				class rigid_static;
				class rigid_static_plane;
				class controller;
				class vehicle;

				class material;
			}
			namespace physics
			{
				class base;
				class actor;
				class rigid_actor;
				class rigid_body;
				class rigid_dynamic;
				class rigid_dynamic_box;
				class rigid_static;
				class rigid_static_plane;
				class controller;
				class vehicle;


				class material;

			}
			namespace renderer
			{
				class base;
				class actor;
				class rigid_actor;
				class rigid_body;
				class rigid_dynamic;
				class rigid_dynamic_box;
				class rigid_static;
				class rigid_static_plane;
				class controller;
				class vehicle;

				class material;
			}
		}
		namespace shape
		{
			namespace admin
			{
				class base;
				class box;
				class plane;
			}
			namespace physics
			{
				class base;
				class box;
				class plane;

			}
			namespace renderer
			{
				class base;
				class box;
				class plane;
			}
		}
	}

	/** \breif %asio
	 * Asyn30000hronous in/out using boost::asio
	 */
	namespace asio
	{
		class message;
		class mailbox;
		class destination;

		/** \breif %network
		 *
		 */
		namespace network
		{
			class base;
		}
	}

	/** \breif %user %interface
	 *
	 */
	namespace ui
	{
		namespace layout
		{
			class base;
		}
		namespace object
		{
			class base;
			class button;
			class textview;
		}
	}
}

namespace n00000 = nebula;

namespace n10000 = nebula::framework;

namespace n20000 = nebula::platform;
namespace n21000 = nebula::platform::platform;
namespace n21100 = nebula::platform::platform::lin;
namespace n21200 = nebula::platform::platform::win;
namespace n22000 = nebula::platform::window;
namespace n22100 = nebula::platform::window::lin;
namespace n22200 = nebula::platform::window::win;
namespace n23000 = nebula::platform::renderer;
namespace n23100 = nebula::platform::renderer::gl;
namespace n23110 = nebula::platform::renderer::gl::glx;

namespace n30000 = nebula::content;
namespace n31000 = nebula::content::universe;
namespace n31100 = nebula::content::universe::admin;
namespace n32000 = nebula::content::scene;
namespace n32100 = nebula::content::scene::admin;
namespace n32200 = nebula::content::scene::physics;
namespace n32300 = nebula::content::scene::renderer;
namespace n33000 = nebula::content::view;
namespace n33100 = nebula::content::view::admin;

namespace n34000 = nebula::content::actor;
namespace n34100 = nebula::content::actor::admin;
namespace n34200 = nebula::content::actor::physics;
namespace n34300 = nebula::content::actor::renderer;
namespace n35100 = nebula::content::shape::admin;
namespace n35200 = nebula::content::shape::physics;
namespace n35300 = nebula::content::shape::renderer;
namespace n36000 = nebula::content::physics;

namespace n40000 = nebula::asio;

namespace n50000 = nebula::ui;
namespace n51000 = nebula::ui::layout;
namespace n52000 = nebula::ui::object;

#endif

