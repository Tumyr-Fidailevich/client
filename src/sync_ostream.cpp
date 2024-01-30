#include "sync_ostream.h"


SyncOstream& SyncOstream::operator<<(std::ostream& (*manip)(std::ostream&)) {
        std::lock_guard<std::mutex> lock(mutex_);
        manip(*this);
        return *this;
}