#include "empty.h"

void do_smth()
{

    ns::person p = {"Ned Flanders", "744 Evergreen Terrace", 60};
    std::cout << "smth" << std::endl;
    nlohmann::json j;
    j["name"] = p.name;
    j["address"] = p.address;
    j["age"] = p.age;
}