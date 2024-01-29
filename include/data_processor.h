#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include "pch.h"
#include "shared_buffer.h"

class DataProcessor
{
public:
    DataProcessor(SharedBuffer &buffer, boost::asio::ip::tcp::socket &socket) : buffer_(buffer), socket_(socket) {} 
    
    void run();

private:
    int calculateAmount(const std::string &receivedData) const noexcept;

    boost::asio::ip::tcp::socket& socket_;
    SharedBuffer& buffer_;
};

#endif //DATA_PROCESSOR_H