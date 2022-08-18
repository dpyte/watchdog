
#include "Xml.hxx"

Result<WdData::DisplayConfig> WdData::parse_system_config(String const &path_to_sys_config) {
    auto *document = new XMLDocument;
    document->LoadFile(path_to_sys_config.c_str());

    auto *root = document->FirstChildElement("system-config");
    if (root == nullptr) return ReturnResult(DisplayConfig(),
                             String("Failed to find root's element node - system config, in system_config.xml"));

    auto *display = root->FirstChildElement("display");
    if (display == nullptr) return ReturnResult(DisplayConfig(),
                                String("Failed to find element `display` in element's root node"));

    auto *height = display->FirstChildElement("height");
    if (height == nullptr) return ReturnResult(DisplayConfig(),
                               String("Failed to find element `height` in element's display node"));

    auto *width = display->FirstChildElement("width");
    if (width == nullptr) return ReturnResult(DisplayConfig(),
                              String("Failed to find element `width` in element's display node"));

    const auto x_height = std::stoi(height->GetText());
    const auto x_width  = std::stoi(width->GetText());

    return ReturnResult(DisplayConfig(x_height, x_width, document), String());
}
