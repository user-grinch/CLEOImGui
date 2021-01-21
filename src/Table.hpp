#pragma once

class Table 
{
private:
    std::vector<std::pair<std::string,bool>> _data;
public:

    bool& operator[](std::string str)
    {
        for (auto it = _data.begin(); it != _data.end(); ++it)
        {
            // value exists, return ref
            if (it->first == str)
                return it->second;
        }
        
        // push the value into vector and return a ref
        _data.push_back({str,false});
        return _data.back().second;
    }
};