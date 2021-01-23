#pragma once
class Util
{
public:
    Util() = delete;
    Util operator=(Util& x) = delete;
    static void ConvertToProperCase(CScriptThread *thread, char *text);
    static void* LoadTextureFromPath(const char *path);
    static void StyleColorsDefault();
};


