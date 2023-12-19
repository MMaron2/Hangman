#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>

void show_word(std::vector<char> letters, std::string drawn_word);

int main()
{

    const char * NAMES[] {
        "pies", 
        "laptop", 
        "lampa", 
        "dom",
        "kwiat", 
        "słońce", 
        "drzewo", 
        "morze", 
        "motyl", 
        "zamek"
    };


    char try_again{};
    bool cPlay{true};

    int points{0}; // how many points player get


    srand(time(NULL));

    std::cout << "\n\n\n\n\n";

    while (cPlay)
    {
        short int counter{1}; // counts the number of times the user entered an auxiliary word

        std::vector<char> letters; // array that contains single leeter of word

        size_t random_number = static_cast<size_t>(std::rand() % std::size(NAMES));
        const std::string drawn_word = static_cast<std::string>(NAMES[random_number]);
        
        char user_input{};
        char try_to_answer{'N'};

        // 
        std::cout << drawn_word << "\n";
        show_word(letters, drawn_word);

        while (counter <= 5)
        {
            std::cout << "wpisz litere: ";
            std::cin >> user_input;
            std::cout << "user input: " << user_input << std::endl;
            letters.push_back(user_input);
            std::cout << "haslo: ";
            show_word(letters, drawn_word);

            std::cout << "chcesz sprobowac odgadnac haslo? (Y | N): ";
            std::cin >> try_to_answer;
            if (try_to_answer == 'Y' || try_to_answer == 'y') 
            {
                std::string user_answer{};
                std::cout << "podaj haslo: ";
                std::cin.sync(); // flushing the buffer
                while (std::getline(std::cin, user_answer))
                {
                    if (user_answer != "") break;    //we got something
                }

                if (user_answer == drawn_word)
                {
                    std::cout << "Brawo, udalo ci sie odgadnac haslo!\n";
                    break;
                } 
                else 
                {
                    std::cout << "niestety podales nieprawidlowe haslo, Probuj dalej";
                }
            }
            counter++;
        }
        break;
    }
    return 0;

}

void show_word(std::vector<char> letters, std::string drawn_word)
{
    char sign{'_'};
    for (char word_letter : drawn_word)
        {

			if (word_letter == ' ')
			{
				std::cout << " ";
				continue;
			}
        	
            if (letters.size() == 0)
            {
                std::cout << "_" << " ";
                continue;
            }

            for (char letter : letters)
            {
                if (word_letter == letter) 
                {
                    sign = word_letter;
                    break;
                }
                sign = '_';
            }
            std::cout << sign << " ";
        }
    std::cout << "\n";    
}
