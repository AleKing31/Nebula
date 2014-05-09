#ifndef __RENDERABLE_H__
#define __RENDERABLE_H__

#include <memory>

#include <Nebula/Flag.hpp>

#include <Nebula/Types.hpp> // gru/config.hpp.in
#include <Nebula/Graphics/gui/layout.hpp>
#include <Nebula/Graphics/window/window.hpp>
#include <Nebula/scene/scene.hpp>

namespace Neb {
	/** @brief Renderable.
	 * @todo eventually replace this with Context and allow multiple Contexts per window and allow scene and layout to have different and overalpping Contexts.
	 */
	class renderable: public gal::flag, public std::enable_shared_from_this<renderable> {
		public:
			renderable(Neb::window::window_s window);
			renderable&			operator=(renderable const & r);
			unsigned int			f();
			void				f(unsigned int flag);
			void				init(Neb::window::window_s window);
			Neb::window::window_s	getWindow();
			void				resize(int w, int h);
			void				render(double time, Neb::window::window_s window);
		private:
			unsigned int			flag_;


			Neb::window::window_w	window_;
		public:
			Neb::Scene::scene_u				scene_;
			Neb::gui::layout_u				layout_;
			Neb::Camera::View::Base_u			view_;
			Neb::Camera::Projection::Base_u			proj_;
	};
}

#endif



