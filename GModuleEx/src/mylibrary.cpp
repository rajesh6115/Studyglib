/*
 * mylibrary.cpp
 *
 *  Created on: 04-May-2020
 *      Author: Rajesh
 */

#include <mylibrary.hpp>

int plugin_init() {
    LogDebug() << "Hello From Plugin init" << std::endl;
    return 0;
}

const gchar* g_module_check_init(GModule *module) {
    LogDebug() << "MYLIBRARY Plugin Loaded" << std::endl;
    return NULL;
}

void g_module_unload(GModule *module) {
    LogDebug() << "MYLIBRARY Plugin UnLoading" << std::endl;
}
