#include_guard(GLOBAL)

include(common_function)

include_once()

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set( CMAKE_VERBOSE_MAKEFILE on )
## compile flag
if(WIN32)
    set(COMMON_CONF "/wd\"4091\"")
    set(CMAKE_CXX_FLAGS_RELEASE  "${COMMON_CONF} /bigobj /Zi /nologo /W3 /WX- /MP /O2 /D \"WIN32\" /D \"_CONSOLE\"   /D \"POCO_NO_AUTOMATIC_LIBS\"  /Gm- /EHa /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /openmp /Fp\"x64\\Release\\rostering.pch\" /Fa\"x64\\Release\" /Fo\"x64\\Release\" /Fd\"x64\\Release\\vc100.pdb\" /Gd /errorReport:queue" )
    set(CMAKE_CXX_FLAGS_DEBUG "${COMMON_CONF} /bigobj /Zi /nologo /W3 /WX- /MP /Od /D \"WIN32\" /D \"_DEBUG\" /D \"_CONSOLE\"  /D \"POCO_NO_AUTOMATIC_LIBS\" /Gm- /EHa /RTC1 /MDd /GS /fp:precise /Zc:wchar_t /Zc:forScope /openmp /Fp\"x64\\Debug\\rostering.pch\" /Fa\"x64\\Debug\" /Fo\"x64\\Debug\" /Fd\"x64\\Debug\\vc100.pdb\" /Gd /errorReport:queue" )

##win target posifx
    set(CMAKE_DEBUG_POSTFIX "d")
    set(CMAKE_RELEASE_POSTFIX "")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

else()
    set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated-declarations -g -O2 -Wall  -fdiagnostics-show-option -fopenmp -Werror -fPIC")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath='$ORIGIN'")

endif()

set(LIB_PATH ${CMAKE_BINARY_DIR}/lib)

if(WIN32)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${LIB_PATH})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${LIB_PATH})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
else(WIN32)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_PATH})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif(WIN32)

## 3pp library base PATH
if(DEFINED ENV{BOOST_HOME})
    set(BOOST_HOME $ENV{BOOST_HOME})
else()
    MESSAGE(FATAL_ERROR  "boost not found!")
endif()


## 3pp include path
include_directories (SYSTEM ${BOOST_HOME}/include)
LINK_DIRECTORIES (${BOOST_HOME}/lib)
LINK_DIRECTORIES(${LIB_PATH})

set(boost_libs boost_coroutine boost_thread boost_locale boost_date_time)
generate_boost_lib("${boost_libs}" 1_75_0 boost_libs)
set(common_depend_libs ${boost_libs})
#generate_gen_lib("${gen_libs}" gen_libs "d")


