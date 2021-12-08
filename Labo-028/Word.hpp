#ifndef WORD_HPP
#define WORD_HPP
#include <string>
/**
 * @brief Word in a text with it's occurences
 *
 */
class Word
{
    std::string word;
    int count;
    public:
    Word(std::string word, int count);
    void show();
    int get_count();
};

#endif