#pragma once
#include "pch.h"

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
