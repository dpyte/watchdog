#ifndef WATCHDOG_DATA_HXX
#define WATCHDOG_DATA_HXX

#include "Result.hxx"
#include "tinyxml2.h"
#include "WdTypes.hxx"

namespace {
    using namespace tinyxml2;
}

namespace WdData {
    extern Result<XMLDocument*> parse_system_config(String const &path_to_sys_config);
}


#endif//WATCHDOG_DATA_HXX
