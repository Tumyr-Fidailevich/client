#ifndef INPUT_LISTENER_H
#define INPUT_LISTENER_H

#include "pch.h"
#include "shared_buffer.h"
#include "sync_ostream.h"

class InputListener {
public:
    InputListener(SharedBuffer& buffer, SyncOstream& ostream) : buffer_(buffer), ostream_(ostream) {}

    void run();

protected:
    static void replaceEven(std::string &input) noexcept;

private:
    SharedBuffer& buffer_;
    SyncOstream& ostream_;
};

#endif //INPUT_LISTENER_H