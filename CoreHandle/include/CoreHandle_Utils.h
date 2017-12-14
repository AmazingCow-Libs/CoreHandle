#pragma once

//----------------------------------------------------------------------------//
// Namespaces                                                                 //
//----------------------------------------------------------------------------//
// All classes of this core is placed inside this namespace.
// We use MACROS so is easier to change if needed.
// Is (in our opinion) more explicit.
// And finally the editors will not reformat the code.
#define NS_COREHANDLE_BEGIN namespace CoreHandle {
#define NS_COREHANDLE_END   }
#define USING_NS_COREHANDLE using namespace CoreHandle


//----------------------------------------------------------------------------//
// Version                                                                    //
//----------------------------------------------------------------------------//
#define COW_COREHANDLE_VERSION_MAJOR    "0"
#define COW_COREHANDLE_VERSION_MINOR    "1"
#define COW_COREHANDLE_VERSION_REVISION "0"

#define COW_COREHANDLE_VERSION       \
    COW_COREHANDLE_VERSION_MAJOR "." \
    COW_COREHANDLE_VERSION_MINOR "." \
    COW_COREHANDLE_VERSION_REVISION


//----------------------------------------------------------------------------//
// Includes                                                                   //
//----------------------------------------------------------------------------//
// sqlite3
#include "sqlite3.h"
