#include "data_processor.h"
#include "shared_buffer.h"
#include "input_listener.h"
#include "sync_ostream.h"


using namespace boost::asio::ip;

const std::string IP_ADDRESS = "127.0.0.1";

const short PORT = 1234;

int main(int argc, char* argv[])
{
    boost::asio::io_service ioService;
    tcp::socket socket(ioService);
    socket.connect(tcp::endpoint(address::from_string(IP_ADDRESS), PORT));

    
    SharedBuffer buffer;
    SyncOstream ostream(std::cout);
    InputListener listener(buffer, ostream);
    DataProcessor dataProcessor(buffer, socket, ostream);

    std::thread inputThread(&InputListener::run, listener);
    std::thread processingThread(&DataProcessor::run, dataProcessor);

    inputThread.join();
    processingThread.join();
}