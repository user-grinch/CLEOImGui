#pragma once
class Util
{
public:
    Util() = delete;
    Util operator=(Util& x) = delete;
    static void ConvertToProperCase(CScriptThread *thread, char *text);
};
