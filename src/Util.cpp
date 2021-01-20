#include "CLEOImGui.h"
#include "Util.h"

void ConvertToProperCase(char * text)
{
    if (CLEOImGui::text_case == CAPITAL_CASE)
    {
        text[0]= toupper(text[0]);

        for(int i=1;text[i]!='\0';i++)
            text[i] = tolower(text[i]);
    }

    if (CLEOImGui::text_case == LOWER_CASE)
    {
        for(int i=0;text[i]!='\0';i++)
            text[i] = tolower(text[i]);
    }

    if (CLEOImGui::text_case == TITLE_CASE)
    {
        text[0] = toupper(text[0]);
        for(int i=1;text[i]!='\0';i++)
        {
            if(text[i-1] != ' ')
                text[i] = tolower(text[i]);
        }
    }
    
};