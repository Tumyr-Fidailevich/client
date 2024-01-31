#ifndef SYNC_OSTREAM_H
#define SYNC_OSTREAM_H

#include "pch.h"

class SyncOstream : public std::ostream
{
public:
    SyncOstream(std::ostream& os) : std::ostream(os.rdbuf()) {}

    template <typename T>
    SyncOstream& operator<<(const T& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        static_cast<std::ostream&>(*this) << value;
        return *this;
    }

    SyncOstream& operator<<(std::ostream& (*manip)(std::ostream&));

private:
    std::mutex mutex_;
};

#endif