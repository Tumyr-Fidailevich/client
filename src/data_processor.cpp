#include "data_processor.h"

void DataProcessor::run()
{
    while(true)
    {
        auto receivedData = buffer_.getData();
        buffer_.clear();
        
        std::cout << receivedData << std::endl;

        auto sum = calculateAmount(receivedData);

        socket_.write_some(boost::asio::buffer(&sum, sizeof(int)));
    }
    
}

int DataProcessor::calculateAmount(const std::string &receivedData) const
{
    return std::accumulate(receivedData.begin(), receivedData.end(), 0, [](int acc, char c) {
                if (std::isdigit(c)) {
                    acc += c - '0';
                }
                return acc;
            });
}