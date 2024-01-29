#include "data_processor.h"
#include "shared_buffer.h"
#include "input_listener.h"


int main(int argc, char* argv[])
{
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 12345);
    boost::asio::ip::tcp::acceptor acceptor(ioService, endpoint);
    boost::asio::ip::tcp::socket socket(ioService);

    acceptor.accept(socket);
    SharedBuffer buffer;
    InputListener listener(buffer);
    DataProcessor dataProcessor(buffer, socket);

    std::thread inputThread(&InputListener::run, listener);
    std::thread processingThread(&DataProcessor::run, dataProcessor);

    inputThread.join();
    processingThread.join();
}