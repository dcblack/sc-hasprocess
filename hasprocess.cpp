#if __cplusplus < 201402L
#  error __cplusplus is #__cplusplus and it does not meet the minimum requirement of C++14
#endif

#include <systemc>
#if SYSTEMC_VERSION < 20181013
#  error SYSTEMC_VERSION is #SYSTEMC_VERSION and it does not meet the minimum requirement of SystemC 2.3.2
#endif

//------------------------------------------------------------------------------
// Reporting convenience
#include <sstream>
std::ostringstream mout;
#define INFO( stream ) do { \
  mout << stream << std::ends;\
  SC_REPORT_INFO( "/Doulos/Example/HasProcess", mout.str().c_str() ); \
  mout.str("");\
} while(0)

//------------------------------------------------------------------------------
SC_MODULE( Classic_module ) {
  SC_CTOR( Classic_module ) {
    SC_THREAD( Classic_thread );
  }
  void Classic_thread( void ) { INFO( "Hello from " <<  __func__ ); }
};

//------------------------------------------------------------------------------
struct NoCtor1Macro_module : sc_core::sc_module {
  NoCtor1Macro_module( sc_core::sc_module_name instance ) {
    SC_HAS_PROCESS( NoCtor1Macro_module );
    SC_THREAD( NoCtor1Macro_thread );
  }
  void NoCtor1Macro_thread( void ) { INFO( "Hello from " <<  __func__ ); }
};

//------------------------------------------------------------------------------
struct NoCtor2Macro_module : sc_core::sc_module {
  NoCtor2Macro_module( sc_core::sc_module_name instance ) {
    SC_THREAD( NoCtor2Macro_thread );
  }
  SC_HAS_PROCESS( NoCtor2Macro_module );
  void NoCtor2Macro_thread( void ) { INFO( "Hello from " <<  __func__ ); }
};

//------------------------------------------------------------------------------
struct NoCtor3Macro_module : sc_core::sc_module {
  NoCtor3Macro_module( sc_core::sc_module_name instance ) {
    SC_THREAD( NoCtor3Macro_thread );
  }
  void NoCtor3Macro_thread( void ) { INFO( "Hello from " <<  __func__ ); }
  SC_HAS_PROCESS( NoCtor3Macro_module );
};

//------------------------------------------------------------------------------
#ifdef MISSING_HAS_PROCESS_WONT_COMPILE
struct NoProcessMacro_module : sc_core::sc_module {
  NoProcessMacro_module( sc_core::sc_module_name instance ) {
    SC_THREAD( NoProcessMacro_thread );
  }
  void NoProcessMacro_thread( void ) { INFO( "Hello from " <<  __func__ ); }
};
#endif

//------------------------------------------------------------------------------
struct NoMacro_module : sc_core::sc_module {
  NoMacro_module( sc_core::sc_module_name instance ) {
    sc_core::sc_spawn( sc_core::sc_bind( &NoMacro_module::NoMacro_thread, this ) );
  }
  void NoMacro_thread( void ) { INFO( "Hello from " <<  __func__ ); }
};

//------------------------------------------------------------------------------
#define MY_THREAD( METHOD ) sc_core::sc_spawn( sc_core::sc_bind( &METHOD, this ) )
struct AltMacro_module : sc_core::sc_module {
  AltMacro_module( sc_core::sc_module_name instance ) {
    MY_THREAD( AltMacro_module::AltMacro_thread );
  }
  void AltMacro_thread( void ) { INFO( "Hello from " <<  __func__ ); }
};

//------------------------------------------------------------------------------
SC_MODULE( Top_module ) {
  Classic_module         classic         { "classic"         };
  NoCtor1Macro_module    noCtor1Macro    { "noCtor1Macro"    };
  NoCtor2Macro_module    noCtor2Macro    { "noCtor2Macro"    };
  NoCtor3Macro_module    noCtor3Macro    { "noCtor3Macro"    };
//NoProcessMacro_module  noProcessMacro  { "noProcessMacro"  };
  NoMacro_module         noMacro         { "noMacro"         };
  AltMacro_module        altMacro        { "altMacro"        };
  SC_CTOR( Top_module ) { } //< just need declaration
};

//------------------------------------------------------------------------------
Top_module top{ "top" };
int sc_main( int argc, char* argv[] ) {
  sc_core::sc_start();
  return 0;
}

