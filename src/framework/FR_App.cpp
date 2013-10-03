#include <stdio.h>

#include <boost/bind.hpp>

#include <jess/free.hpp>
#include <jess/ostream.hpp>

#include <nebula/define.hpp>
#include <nebula/content/base.hpp>
#include <nebula/asio/network/base.hpp>
//#include <nebula/platform/platform/base.h>

#if defined(__LIN__)
	#include <nebula/platform/platform/lin/base.hpp>
#elif defined(__WIN__)
	#include <nebula/platform/platform/win/base.hpp>
#else
	#error "__WIN__ or __LIN__ must be defined"
#endif






#include <nebula/framework/app.hpp>


template class jess::shared_ptr<nc::base>;
template void jess::shared_ptr<nc::base>::create( boost::function<void(boost::shared_ptr<nc::base>)> );



//template class jess::shared_ptr<nc::base>;
//template void jess::shared_ptr<nc::base>::create( boost::function<void(boost::shared_ptr<nc::base>)> );


nf::app::app()
{
	jess::clog << NEB_FUNCSIG << std::endl;
	
	//m_content = 0;
	//m_network = 0;
	//m_platform = 0;
}
nf::app::~app()
{
	jess::clog << NEB_FUNCSIG << std::endl;//jess::clog.funcsig();//m_platform->ShutDown();
}
void	nf::app::MainLoopSequ()
{
	while(1)
	{
		ContinueLoopSequ();
	}
}
void	nf::app::MainLoopMulti()
{

}
void	nf::app::ContinueLoopSequ()
{
	jess::clog << NEB_FUNCSIG << std::endl;
	
	content_.pointer_->update();
	platform_.pointer_->update();
	//m_network->Update(NULL);
	
}
void	nf::app::ContinueLoopMulti()
{

}
void	nf::app::init()
{
	jess::clog << NEB_FUNCSIG << std::endl;//.funcsig();//PRINTSIG;
	
	content_.create<nc::base>( boost::bind( &nc::base::init, _1, shared_from_this() ) );
	
	#ifdef __LIN__
		platform_.create<nppl::base>( boost::bind( &nppl::base::init, _1, shared_from_this() ) );
	#elif defined(__WIN__)
		platform_.create<nppw::base>( boost::bind( &nppw::base::init, _1, shared_from_this() ) );
	#endif
	
}
void	nf::app::shutdown()
{
	jess::clog << NEB_FUNCSIG << std::endl;//jess::clog.funcsig();

	content_.pointer_->shutdown();
	//network->Shutdown(NULL);
	platform_.pointer_->shutdown();
}
















