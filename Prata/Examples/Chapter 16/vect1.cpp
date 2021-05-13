// vect1.cpp -- пример работы с шаблоном vector
#include <iostream>
#include <string>
#include <vector>

const int NUM = 2;
int main()
{
    std::vector<int> ratings(NUM);
    std::vector<std::string> titles(NUM);
    std::cout << "You will do exactly as told. You will enter\n"
              << NUM << " book titles and your ratings (0-10).\n";
    int i;
    for (i = 0; i < NUM; i++)
    {
        std::cout << "Enter title #" << i + 1 << ": ";
        std::getline(std::cin, titles[i]);
        std::cout << "Enter your rating (0-10): ";
        std::cin >> ratings[i];
        std::cin.get();
    }
    std::cout << "Thank you. You entered the following:\n"
              << "Rating\tBook\n";
    for (i = 0; i < NUM; i++)
    {
        std::cout << ratings[i] << "\t"
                  << titles[i] << '\n';
    }
    return 0; 
}