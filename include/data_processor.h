#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include "pch.h"
#include "shared_buffer.h"
#include "sync_ostream.h"

class DataProcessor
{
public:
    DataProcessor(SharedBuffer &buffer, boost::asio::io_context &ioContext, boost::asio::ip::tcp::endpoint endpoint, SyncOstream& ostream) : 
    buffer_(buffer), socket_(ioContext), ioContext_(ioContext), endpoint_(endpoint), ostream_(ostream) {} 
    
    void run();

protected:

    void connect();

    void reconnect();

    void processing();

    int calculateAmount(const std::string &receivedData) noexcept;

    void send();

private:
    boost::asio::io_context& ioContext_;
    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::endpoint endpoint_;
    SharedBuffer& buffer_;
    std::string data_;
    SyncOstream& ostream_;
};

#endif //DATA_PROCESSOR_H