#pragma once

#include <cstdint>
#include <vector>

template <typename T>
class StoreInterface
{
public:
    virtual std::vector<T> &GetData() = 0;
    virtual void Save() const = 0;
    virtual ~StoreInterface() {};

protected:
    std::vector<T> m_data;
};
