#pragma once
#include "Table.hpp"
#include "vendor/CLEO.h"
#include <utility>
#include <vector>

class ScriptExData
{
private:
    ScriptExData(CScriptThread* data)
    : data(data)
    {
    }

public:
    struct ImGuiFrame
    {
        std::vector<std::function<void()>> frames;
        ImGuiFrame& operator+=(std::function<void()> f)
        {
            frames.push_back(f);
            return *this;
        }
        void DrawFrames()
        {
            for (auto& func: frames)
                func();
        }

        void ClearFrames()
        {
            frames.clear();
        }
    } imgui;

    CScriptThread* data;
    Table prev_frame; // stores the func return values of previous frame
    int text_case = 0; // CAPITAL_CASE
    static std::vector<ScriptExData*> scripts;
    static bool show_cursor;

    static ScriptExData* Get(CScriptThread* data)
    {
        // create the object if it doesn't exist
        for (auto it = scripts.begin(); it != scripts.end(); ++it)
        {
            // script already in vector
            if ((*it)->data == data)
                return *it;
        }

        // script isn't it vector so create it
        ScriptExData* script = new ScriptExData(data);
        scripts.push_back(script);
        return script;
    }

    static void DrawFrames()
    {
        for (auto it = scripts.begin(); it != scripts.end(); ++it)
        {
            (*it)->imgui.DrawFrames();
            (*it)->imgui.ClearFrames();
        }
    }
};