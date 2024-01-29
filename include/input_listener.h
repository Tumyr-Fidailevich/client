#ifndef INPUT_LISTENER_H
#define INPUT_LISTENER_H

#include "pch.h"
#include "shared_buffer.h"

class InputListener {
public:
    InputListener(SharedBuffer& buffer) : buffer_(buffer) {}

    void run();

private:
    void replaceEven(std::string &input) noexcept;

    SharedBuffer& buffer_;
};

#endif //INPUT_LISTENER_H