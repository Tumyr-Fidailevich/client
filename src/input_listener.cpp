#include "input_listener.h"

void InputListener::run()
{
    while(true)
    {
        std::string input;
        ostream_ << "Input your data: ";
        std::getline(std::cin, input);
        if(!std::all_of(input.begin(), input.end(), ::isdigit) || input.length() > 64 || input.length() == 0)
        {
            std::cerr << "Incorrect input" << std::endl;
            continue;
        }

        std::sort(input.begin(), input.end());

        replaceEven(input);

        buffer_.setData(input);

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void InputListener::replaceEven(std::string &input) noexcept
{
    for(auto it = input.begin(); it != input.end(); ++it)
    {
        if((*it - '0') % 2 == 0)
        {
            *it = 'K';
            it = input.insert(it + 1, 'B');
        }
    }
}