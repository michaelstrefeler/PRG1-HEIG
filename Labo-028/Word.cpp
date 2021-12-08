#include <iostream>
#include <string>
#include "Word.hpp"

Word::Word(std::string word, int count)
{
    this->word = word;
    this->count = count;
}

void Word::show(){
    std::cout << this->word << ":" << this->count << std::endl;
}

int Word::get_count()
{
    return this->count;
}