// fowl.cpp  -- неудачный выбор
#include <string>
#include <memory>
#include <iostream>

int main()
{
    using namespace std;
    std::auto_ptr<string> films[5] =
    {
        std::auto_ptr<string> (new string("Fowl Balls")),
        std::auto_ptr<string> (new string("Duck Walks")),
        std::auto_ptr<string> (new string("Chicken Runs")),
        std::auto_ptr<string> (new string("Turkey Errors")),
        std::auto_ptr<string> (new string("Goose Eggs"))
    };
    std::auto_ptr<string> pwin;
    pwin = films[2];   // films[2] утрачивает права владения

    std::cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        std::cout << *films[i] << std::endl;
    std::cout << "The winner is " << *pwin << "!\n";
    return 0;
}
