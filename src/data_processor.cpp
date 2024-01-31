#include "data_processor.h"

void DataProcessor::run()
{
    connect();

    processing();
}

void DataProcessor::connect()
{
    boost::system::error_code ec;
    socket_.connect(endpoint_, ec);
}

void DataProcessor::reconnect()
{
     if (socket_.is_open())
    {
        boost::system::error_code ignore;
        socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignore);
        socket_.close(ignore);
    }
    connect();
}

void DataProcessor::processing()
{
    while(true)
    {
        ioContext_.poll();

        auto receivedData = buffer_.getData();
        buffer_.clear();
        
        ostream_ << "Data received: " << receivedData << std::endl;

        auto sum = calculateAmount(receivedData);

        ostream_ << "Calculated sum: " << sum << std::endl;

        data_ = std::to_string(sum);

        send();

        ioContext_.reset();
    }
}

int DataProcessor::calculateAmount(const std::string &receivedData) noexcept
{
    return std::accumulate(receivedData.begin(), receivedData.end(), 0, [](int acc, char c) {
                if (std::isdigit(c)) {
                    acc += c - '0';
                }
                return acc;
            });
}

void DataProcessor::send()
{
    boost::asio::async_write(socket_, boost::asio::buffer(data_),
        [this](const boost::system::error_code& ec, std::size_t /*bytes_transferred*/) {
            if (ec) {
                reconnect();
            }
        }
    );
}