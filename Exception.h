#ifndef WORKING_EX4_EXCEPTION_H
#define WORKING_EX4_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>
using namespace std;

/**
 * An exception that gets thrown when the deck file is not found.
 */
class DeckFileNotFound : public exception{
    const char * what () const noexcept override {
        return "Deck File Error: File not found";
    }
};

/**
 * An exception that gets thrown when there is a format error in a specific line.
 */
class DeckFileFormatError : public std::exception {
public:
    DeckFileFormatError(int line_number) : line_number(line_number) {
        error_message = "Deck File Error: File format error in line " + std::to_string(line_number);
    }

    const char* what() const noexcept override {
        return error_message.c_str();
    }

private:
    int line_number;
    std::string error_message;
};

/**
 * An exception that gets thrown when the deck size is invalid.
 */
class DeckFileInvalidSize : public exception{
    const char * what() const noexcept override{
        return "Deck File Error: Deck size is invalid";
    }
};
#endif //WORKING_EX4_EXCEPTION_H