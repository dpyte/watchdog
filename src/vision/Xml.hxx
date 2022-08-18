#ifndef WATCHDOG_XML_HXX
#define WATCHDOG_XML_HXX

#include "Result.hxx"
#include "tinyxml2.h"
#include "WdTypes.hxx"

namespace {
    using namespace tinyxml2;
}

namespace WdData {
    struct DisplayConfig {
        usize       height;
        usize       width;
        XMLDocument *document;

        DisplayConfig() = default;
        explicit DisplayConfig(usize ht, usize wd, XMLDocument *doc) : height(ht), width(wd), document(doc) {}
    };

    Result<DisplayConfig> parse_system_config(String const &path_to_sys_config);
}


#endif//WATCHDOG_XML_HXX
