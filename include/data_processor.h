#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include "pch.h"
#include "shared_buffer.h"
#include "sync_ostream.h"

class DataProcessor
{
public:
    DataProcessor(SharedBuffer &buffer, boost::asio::ip::tcp::socket &socket, SyncOstream& ostream) : 
    buffer_(buffer), socket_(socket),  ostream_(ostream) {} 
    
    void run();

protected:

    static int calculateAmount(const std::string &receivedData) noexcept;

private:
    boost::asio::ip::tcp::socket& socket_;
    SharedBuffer& buffer_;
    SyncOstream& ostream_;
};

#endif //DATA_PROCESSOR_H