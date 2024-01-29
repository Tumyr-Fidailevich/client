#ifndef SHARED_BUFFER_H
#define SHARED_BUFFER_H

#include "pch.h"

class SharedBuffer
{
public:
    SharedBuffer() : dataReady_(false) {}

    void setData(const std::string& data);

    std::string getData();

    void clear();

private:
    std::mutex mutex_;
    std::condition_variable condition_;
    bool dataReady_;
    std::string data_;
};


#endif //SHARED_BUFFER_H