# GetInputCPP

## Summary
getinputcpp is a header file with a function template and function for ease of
getting input for beginner C++ students. It's designed to take out some of the 
overhead for input validation.

## How to include in your .cpp file
- Copy the header(getinputcpp.hpp) file into your project directory
- add `#include "getinputcpp.hpp"`
- compile your project like normal

## How to use clear_input()
Clear input is designed to empty the associated input buffer after inserting
text into the stream. It is most effective to use after cin to clear the buffer
of any unanticipated or unwanted input. It will also reset any flags on the 
buffer so you can use it to create your own input validation

### Example
```cpp
#include <iostream>
#include "getinputcpp.hpp"

using namespace std;

int main() {
    int user_input;
    cin >> user_input;
    // If the user enters something that is not an integer up to the first
    // space character in the input, cin.fail() will be true, otherwise check
    // to see if the input meets the condition (not required for all use cases)
    while (cin.fail() || (condition)) {
        clear_input(cin);
        cin >> user_input;
    }
    // It's a good idea to just clear the cin buffer after having the user enter
    // anything, as you can't limit what they type before they press enter.
    clear_input(cin);
    return 0;
}
```

## How to use get_input
- get_input requires you to specify the type of the input you're trying to receive
    (e.g. int, double).
- get_input doesn't accept string or bool as types and it's recommended that you
    use getline and create your own input validation.
- get_input has basic validation to ensure that the user enters the type of
    input that you're trying to get and that the buffer is clear afterwards

The basic structure of get_input is as follows:
`type variable = get_input<type>(input_stream, prompt);`
You can declare the variable befor the call to get_input.
You have to put the type of the variable in angle brackets after get_input.
You have to tell the function what stream to use, which will likely be cin.
You have to give the function a prompt to display before asking for input.

### Example
```cpp
#include <iostream>
#include "getinputcpp.hpp"

using namespace std;

int main() {
    double user_double = get_input<double>(cin, "Enter a double: ");
    return 0;
}
```
