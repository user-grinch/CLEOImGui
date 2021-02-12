#pragma once
#include "Util.h"
#include "Table.hpp"
#include "CLEO.h"
#include <utility>
#include <vector>

class ScriptExData
{
private:
    ScriptExData(CScriptThread* data): data(data){}

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
    Table<std::string,float> frame_cache; // Cached data of previous frame
    static std::vector<ScriptExData*> scripts;
    static bool show_cursor;

    static ScriptExData* Get(CScriptThread* data)
    {
        // create the object if it doesn't exist
        for (auto it = scripts.begin(); it != scripts.end(); ++it)
        {
            // return the exisitng data
            if ((*it)->data == data)
                return *it;
        }

        // return the new data
        ScriptExData* script = new ScriptExData(data);
        scripts.push_back(script);
        return script;
    }

    static void DrawFrames()
    {
        for (auto it = scripts.begin(); it != scripts.end(); ++it)
        {   
            Util::StyleColorsDefault();
            (*it)->imgui.DrawFrames();
            (*it)->imgui.ClearFrames();
        }
    }
};