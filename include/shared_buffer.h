#ifndef SHARED_BUFFER_H
#define SHARED_BUFFER_H

#include "pch.h"

class SharedBuffer
{
public:
    SharedBuffer() {}

    void setData(const std::string& data) noexcept;

    std::string getData() const noexcept;

    void clear() noexcept;

private:
    mutable std::mutex mutex_;
    mutable std::condition_variable condition_;
    std::string data_;
};


#endif //SHARED_BUFFER_H