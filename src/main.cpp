#include <csignal>
#include "data_processor.h"
#include "shared_buffer.h"
#include "input_listener.h"
#include "sync_ostream.h"


using namespace boost::asio::ip;

const std::string IP_ADDRESS = "127.0.0.1";

const short PORT = 1234;

void signalHandler(int signum) {
    std::cout << "Shutdown client" << std::endl;
    exit(signum);
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RU");
    SharedBuffer buffer;
    SyncOstream ostream(std::cout);

    try
    {
        boost::asio::io_context ioContext;
    
        InputListener listener(buffer, ostream);
        DataProcessor dataProcessor(buffer, ioContext, tcp::endpoint(address::from_string(IP_ADDRESS), PORT), ostream);

        std::thread inputThread(&InputListener::run, &listener);
        std::thread processingThread(&DataProcessor::run, &dataProcessor);

        std::signal(SIGINT, signalHandler);

        inputThread.join();
        processingThread.join();
    }
    catch(const std::exception& e)
    {
        ostream << "Error during starting client" << std::endl;
    }
}