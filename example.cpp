// getinputcpp is a header file that is used for simple input validation

#include <iostream>
#include <sstream>
#include "./getinputcpp.hpp"


void print_main_menu();
void clear_input_example();
void interactive_clear_input_example();
void get_input_example();
void interactive_get_input_example();


int main() {
    int choice = 0;
    bool keep_going = true;
    while (keep_going) {
        print_main_menu();
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 5) {
            clear_input(std::cin);
        }
        switch (choice) {
            case 1:
                clear_input_example();
                break;
            case 2:
                interactive_clear_input_example();
                break;
            case 3:
                get_input_example();
                break;
            case 4:
                interactive_get_input_example();
                break;
            case 5:
                keep_going = false;
                break;
        }
    }
    return 0;
}


void print_main_menu() {
    std::cout << "\n+----------------------| Main Menu |-----------------------+\n"
              << "|----------------------------------------------------------|\n"
              << "| 1. clear_input example                                   |\n"
              << "| 2. interactive clear_input example                       |\n"
              << "| 3. get_input example                                     |\n"
              << "| 4. interactive get_input                                 |\n"
              << "| 5. quit                                                  |\n"
              << "+----------------------------------------------------------+\n"
              << "Select an option: ";
}


void clear_input_example() {
    std::cout << "\n+----------------| Clear Input Example |-------------------+\n"
              << "| Initializing variable user_int for storing user input    |\n"
              << "| Simulating user input of \"12\\n\"                          |\n";
    int user_int;
    std::istringstream input("12\n");
    input >> user_int;
    std::cout << "| user_int is: " << user_int
              << " after reading into the variable.         |\n"
              << "| This leaves the \\n in the input buffer which we can see  |\n"
              << "| using peek(): " << input.peek() << ", which is the ASCII character for LF.   |\n"
              << "| LF is the control character for newline on Linux.        |\n";
    clear_input(input);
    if (input.peek() == EOF) {
    std::cout << "| After calling clear_input on the input buffer, it now    |\n"
              << "| reads EOF or end of file.                                |\n"
              << "+----------------------------------------------------------+\n";
    }
}


void interactive_clear_input_example() {
    std::cout << "\n+-----------| Interactive Clear Input Example|-------------+\n"
              << "|----------------------------------------------------------|\n"
              << "| Your input is going to get stored as an int in user_int. |\n"
              << "| Try entering whatever you like, -1 is to exit.           |\n"
              << "| Enter some additional text after the -1 to see how the   |\n"
              << "| clear_input function clears the buffer.                  |\n"
              << "+----------------------------------------------------------+\n"
              << "Enter: ";
    int user_int;
    const std::string prompt = "Try entering anything you like (-1 to exit): ";
    std::cin >> user_int;
    while (std::cin.fail() || user_int != -1) {
        clear_input(std::cin);
        std::cout << prompt;
        std::cin >> user_int;
    }
    std::string remainder = "";
    getline(std::cin, remainder);
    if (remainder.size() > 38) {
        remainder = remainder.substr(0, 38) + "...";
    }
    std::cout << "You entered -1 and "
              << (remainder.size() != 0 ? remainder : " \\n") << "\n"
              << "Calling clear_input removes everything after the -1 and\n"
              << "leaves a clear buffer for the next cin, getline, or\n"
              << "get input call\n";
}


void get_input_example() {
    std::cout << "\n+------------------| Get Input Example |------------------+\n"
              << "|----------------------------------------------------------|\n"
              << "| Initializing user_double for storing input and           |\n"
              << "| simulating user input of \"1.35\\n\".                       |\n";
    double user_double;
    std::istringstream input("1.35\n");
    user_double = get_input<double>(input, "");
    std::cout << "| The value in user_double is: " << user_double;
    if (input.peek() == EOF) {
        std::cout << " and there's nothing    |\n"
                  << "| left in the input buffer                                 |\n"
                  << "+----------------------------------------------------------+\n";
    }
}


void interactive_get_input_example() {
    std::cout << "\nNot Implemented\n";
}
