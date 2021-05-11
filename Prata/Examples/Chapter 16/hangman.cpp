// hangman.cpp -- использование некоторых методов работы со строками
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using std::string;
const int NUM = 26;
const string wordlist[NUM] = {"apiary", "beetle", "cereal",
    "danger", "ensign", "florid", "garage", "health", "insult",
    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
    "plaid", "quilt", "remote", "stolid", "train", "useful",
    "valid", "whence", "xenon", "yearn", "zippy"};

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    
    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";            // запуск игры в слова
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % NUM];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;           // вывод слова
    // перегрузка операций отношения позволяет работать со строками так же,
        while (guesses > 0 && attempt != target) // как с числовыми переменными
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
    /* find() для проверки на повторное использование символа; если символ уже вводился, 
    то он будет присутствовать либо в строке badchars (неудачные попытки), либо в строке 
    attempt (удачные попытки): */
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                    continue;
            }
            int loc = target.find(letter);  // проверка на наличие введенного символа в загаданном слове
            if (loc == string::npos) // если достиг максимума size_t, значит введенной буквы нет в слове
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;                         // добавить к строке
            }
            else
            { // Если переменная Іос имеет допустимое значение, буква может быть помещена в
                cout << "Good guess!\n"; // соответствующую позицию строки ответа:
                attempt[loc] = letter;
                // Проверить, не появляется ли буква еще раз
                loc = target.find(letter, loc + 1); // Поскольку буква была найдена в позиции
                while (loc != string::npos)         // loc, следующий поиск должен начаться с позиции loc + 1
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
           }
            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";
        cout << "Will you play another? <y/n> ";
        cin  >> play;
        play = tolower(play);
    }
    cout << "Bye\n";
    return 0; 
}
