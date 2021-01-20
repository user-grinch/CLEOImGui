/*
	Required:
		CLEO SDK
		DirectX 9 SDK
		Plugin SDK
		Visual Studio 2019 (v142)
		Windows SDK
*/

#pragma once
#include "Hook.h"

class FrameData
{
public:
    using Function = std::function<void()>;

    FrameData() = default;
    template<typename Fn>
    FrameData(Fn f) { functions.push_back(f); }

    FrameData& operator+=(Function f)
    {
        functions.push_back(f);
        return *this;
    }

    void operator()()
    {
        for (auto& f: functions)
        {
            f();
        }
    }

	void clear()
	{
		functions.clear();
	}
private:
    std::vector<Function> functions;
};

class CLEOImGui : Hook
{
private:
	static void DrawImGui();

public:
	static FrameData frames;
    static int text_case;
    static void ShowMouse(bool show);
	CLEOImGui();
	~CLEOImGui();
};

extern CLEOImGui cleoimgui;

