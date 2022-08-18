
#include "Xml.hxx"


Result<XMLDocument*> WdData::parse_system_config(String const &path_to_sys_config) {
    auto *document = new XMLDocument;
    document->LoadFile(path_to_sys_config.c_str());

    auto *root = document->FirstChildElement("system-config");
    if (root == nullptr)
        return ReturnResult(nullptr, String("Failed to find root's element node - system config, in system_config.xml"));

    auto *display = root->FirstChildElement("display");
    if (display == nullptr)
        return ReturnResult(nullptr, String("Failed to find element `display` in element's root node"));

    for (auto *disp = display->FirstChildElement(); disp != nullptr; disp = display->NextSiblingElement()) {
    }

    return ReturnResult(document, String());
}
