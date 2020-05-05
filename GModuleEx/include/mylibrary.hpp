/*
 * mylibrary.hpp
 *
 *  Created on: 04-May-2020
 *      Author: Rajesh
 */

#pragma once

#include <Logger.hpp>
#include <gmodule.h>

#ifdef __cplusplus
extern "C" {
#endif
G_MODULE_EXPORT int plugin_init() ;
G_MODULE_EXPORT const gchar * g_module_check_init(GModule *module);
G_MODULE_EXPORT void g_module_unload(GModule *module);
#ifdef __cplusplus
}
#endif

