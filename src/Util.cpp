#include "pch.h"
#include "Util.h"
#include "ScriptExtender.hpp"

void Util::ConvertToProperCase(CScriptThread *thread, char *text)
{
    ScriptExData *data = ScriptExData::Get(thread);

    if (data->text_case == CAPITAL_CASE)
    {
        text[0]= toupper(text[0]);

        for(int i=1;text[i]!='\0';i++)
            text[i] = tolower(text[i]);
    }

    if (data->text_case == LOWER_CASE)
    {
        for(int i=0;text[i]!='\0';i++)
            text[i] = tolower(text[i]);
    }

    if (data->text_case == TITLE_CASE)
    {
        text[0] = toupper(text[0]);
        for(int i=1;text[i]!='\0';i++)
        {
            if(text[i-1] != ' ')
                text[i] = tolower(text[i]);
        }
    }
    
};