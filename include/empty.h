#pragma once
#include <iostream>
#include "nlohmann/json.hpp"

namespace ns {
    struct person {
        std::string name;
        std::string address;
        int age;
    };
}


void do_smth();