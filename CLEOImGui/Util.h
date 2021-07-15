#pragma once
#include "CLEO.h"

class Util
{
public:
    Util() = delete;
    Util operator=(Util& x) = delete;
    
    template<typename T>
    static void GetProperTypeData(CScriptThread* thread, T*& var)
    {
        bool pointer = (bool)CLEO_GetIntOpcodeParam(thread);

        if (pointer)
            var = (T*)CLEO_GetIntOpcodeParam(thread);
        else
            var = (T*)CLEO_GetPointerToScriptVariable(thread);
    }

    static void* LoadTextureFromPath(const char *path);
    static void StyleColorsDefault();
};


