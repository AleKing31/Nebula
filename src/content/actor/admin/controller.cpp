#include <nebula/define.hpp>

#include <nebula/utilities/free.hpp>

#include <nebula/platform/renderer/base.hpp>

#include <nebula/platform/key.hpp>

#include <nebula/platform/window/base.hpp>

#include <nebula/content/actor/physics/controller.hpp>

//#include <framework/Communication/Message/FR_COM_MSG_Message.h>
//#include <framework/Communication/Message/FR_COM_MSG_Data.h>



#include <nebula/content/actor/physics/controller.hpp>
#include <nebula/content/actor/renderer/controller.hpp>




#include <nebula/content/actor/admin/controller.hpp>




ncaa::controller::controller()
{
}
ncaa::controller::~controller()
{
}
void	ncaa::controller::init( const boost::shared_ptr<nc_sc_a::base>& parent )
{
	ncaa::base::init(parent);


	flag_ = 0;

	yaw_ = 0;
	pitch_ = 0;
	
	pos_ = bnu::zero_vector<FLOAT>(3);
	
	
	key_flag_[nebula::platform::key::w] = flag::eNORTH;
	key_flag_[nebula::platform::key::s] = flag::eSOUTH;
	key_flag_[nebula::platform::key::a] = flag::eWEST;
	key_flag_[nebula::platform::key::d] = flag::eEAST;

	// physics
	//physics_.create<ncap::controller>( boost::bind( &ncap::controller::init, _1, shared_from_this() ) );
	
	// renderer
	//renderer_.create<ncap::controller>( boost::bind( &ncap::controller::init, _1, shared_from_this() ) );
}
void	ncaa::controller::shutdown()
{
	//PRINTSIG;
	
}
void	ncaa::controller::update()
{
	ncaa::base::update();
}
void	ncaa::controller::step( FLOAT dt )
{
	ncaa::base::step( dt );
}
void	ncaa::controller::render( const boost::shared_ptr<npr::base>& rnd )
{
}
void	ncaa::controller::create_shapes()
{

}
void	ncaa::controller::look_at( const boost::shared_ptr<npr::base>& rnd )
{
	pose_ = bnu::identity_matrix<FLOAT>( 4 );
	
	pose_ = prod( pose_, nebula::utilities::matrix_pitch( pitch_ ) );
	
	pose_ = prod( pose_, nebula::utilities::matrix_yaw( yaw_ ) );
	
	nebula::utilities::matrix_set_pos( pose_ , pos_ ); 
	
	rnd->mult_matrix( pose_ );
	
	//bnu::  math::quaternion rot(0,0,0,1);
	
	//boost::math::quaternion	yaw( 0, 1, 0, yaw_ );
	//boost::math::quaternion pitch( 1, 0, 0, pitch_ );
	
	//rot *= pitch;
	//rot *= yaw;
	
	//up_ = Math::Vec3f(0,1,0);
	//look_ = Math::Vec3f(0,0,-1);
	
	//up_ *= rot;
	//look_ *= rot;

	//AR_Render* r = DynCast<Void,AR_Render>(v);

	//r->renderer->VLookAt( m_pos, m_pos + m_look, m_up );
}
void	ncaa::controller::process_event(int evnt)
{
	switch ( evnt )
	{
	case event::eRESET_VIEW_ANGLES:
		printf("reset viewing angles\n");
		yaw_ = 0;
		pitch_ = 0;
		break;
	}
}
void	ncaa::controller::handle_key_up(int k, int window_no)
{
	// unset flag
	UINT f = key_flag_[k];
	flag_ &= ~( f );
	
	// trigger event
	int evnt = key_up_event_[k];
	process_event(evnt);

}
void	ncaa::controller::handle_key_down(int k, int window_no)
{
	// set flag
	UINT f = key_flag_[k];
	flag_ |= f;
	
	// trigger event
	int evnt = key_down_event_[k];
	process_event(evnt);
}
void	ncaa::controller::handle_pointer_motion( int x, int y )
{
	//PRINTSIG;
	yaw_ -= x * 0.001;
	pitch_ -= y * 0.001;
}

























