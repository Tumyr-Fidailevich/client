#include <iostream>
#include <cassert>
#include "input_listener.h"
#include "data_processor.h";

class InputListenerTest : public InputListener
{
public:
    static void replaceEven(std::string &input)
    {
        InputListener::replaceEven(input);
    }
};

int main(int argc, char* argv[])
{
    std::string test = "121";
    InputListenerTest::replaceEven(test);
    assert(test == "1KB1");
    std::cout << test << std::endl;
}