#include <iostream>
#include <string>
#include "GrandHelper.h"










int main()
{


    std::string name;

    name = GrandHelper::UserInputString("What's your name? ");

    GrandHelper::WriteLine(name);



    std::cin.get();
}
