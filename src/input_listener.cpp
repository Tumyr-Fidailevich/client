#include "input_listener.h"

void InputListener::run()
{
    while(true)
    {
        std::string input;
        std::getline(std::cin, input);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(!std::all_of(input.begin(), input.end(), ::isdigit) || input.length() > 64)
        {
            std::cerr << "Incorrect input" << std::endl;
            continue;
        }

        std::sort(input.begin(), input.end());

        replaceEven(input);

        buffer_.setData(input);
    }
}

void InputListener::replaceEven(std::string &input)
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