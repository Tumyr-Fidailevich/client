#include "shared_buffer.h"

void SharedBuffer::setData(const std::string& data) noexcept
{
    std::unique_lock<std::mutex> lock(mutex_);
    data_ = data;
    condition_.notify_one();
}

std::string SharedBuffer::getData() const noexcept
{
    std::unique_lock<std::mutex> lock(mutex_);
    condition_.wait(lock, [this] { return !data_.empty(); });
    return data_;
}

void SharedBuffer::clear() noexcept
{
    std::unique_lock<std::mutex> lock(mutex_);
    data_.clear();
}