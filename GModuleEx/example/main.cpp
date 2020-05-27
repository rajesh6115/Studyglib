#include <Logger.hpp>

#include <gmodule.h>
typedef int (*init_fun_t)();
int main (int argc, char *argv[]) {
    LogInfo() << "GModule Example" << std::endl;
    GModule *module = NULL;
    gpointer func;
    init_fun_t init_fun;
    int retVal;
    const char *module_name = (argc==2) ? argv[1] : "../src/libstudygmodule.dll";
    if (!g_module_supported())
    {
        LogDebug() << "Dynamic Opening of modules is not supported\n";
        return 1;
    }

    /* G_MODULE_BIND_LAZY is overridden and the module is opened with
     * flag G_MODULE_BIND_LOCAL
     */
    module = g_module_open(module_name, G_MODULE_BIND_LAZY);

    // 1 is the ordinal number for gplugin_a_func1
    if(module && g_module_symbol(module, "plugin_init" ,&func))
    {
        init_fun = (init_fun_t)func;
        retVal = init_fun();
        LogDebug() << "Function Returns " << retVal << std::endl;
    }
    else
    {
        LogDebug() << "Error plugin_init symbol not found";
        return 1;
    }

    if(module) {
        if(g_module_close(module)){
            LogDebug() << "Module Unloaded properly\n";
        }
    }
    return 0;
}
