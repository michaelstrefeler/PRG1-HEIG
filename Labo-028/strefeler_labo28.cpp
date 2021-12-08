/**
 * @file strefeler_labo28.cpp
 * @author Michael Strefeler
 * @brief Use a Word class to count how many words are in a text
 * @version 0.1
 * @date 07-12-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Word.hpp"
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

/**
 * @brief Spearates text into words and puts the words in the vector
 *
 * @param words vector of words
 * @param text text to use
 */
void put_words_in_vector(vector<string> &words, string text)
{
    string word;
    for (size_t i = 0; i < text.length(); ++i)
    {
        if (isalpha(text.at(i)))
        {
            word.push_back(text.at(i));
        }
        else
        {
            // Accent support
            if (text.at(i) == '\xC3' or text.at(i) == '\xC5' or text.at(i) == '\xC2')
            {
                word.push_back(text.at(i));
                word.push_back(text.at(i + 1));
                ++i;
            }
            else if (text.at(i) == '\xE2') // Unwanted characters
            {
                i += 2;
                if (word != "")
                {
                    words.push_back(word);
                }
                word.clear();
            }
            else
            {
                // Add word to vector unless it's a blank string
                if (word != "")
                {
                    words.push_back(word);
                }
                word.clear();
            }
        }
    }
}

/**
 * @brief Count all words and cout them
 *
 * @param words vector of words to count
 */
void count_and_output(vector<string> words, vector<string>& final, vector<int>& counts)
{
    sort(words.begin(), words.end());

    // Creates a vector of all words without duplicates
    for (size_t i = 0; i < words.size(); i++)
    {
        if (!count(final.begin(), final.end(), words.at(i)))
        {
            final.push_back(words.at(i));
        }
    }

    // Creates a vector with the number of occurences of each word
    for (size_t i = 0; i < final.size(); ++i)
    {
        counts.push_back((int)count(words.begin(), words.end(), final.at(i)));
    }
}
int main(){
    string text;
    text = "Tant qu il existera, par le fait des lois et des mœurs, une damnation sociale créant artificiellement, en pleine civilisation, des enfers, et compliquant d une fatalité humaine la destinée qui est divine ; tant que les trois problèmes du siècle, la dégradation de l homme par le prolétariat, la déchéance de la femme par la faim, l atrophie de l enfant par la nuit, ne seront pas résolus ; tant que, dans de certaines régions, l asphyxie sociale sera possible ; en d autres termes, et à un point de vue plus étendu encore, tant qu il y aura sur la terre ignorance et misère, des livres de la nature de celui-ci pourront ne pas être inutiles.";
    //getline(ifstream("les_miserables.txt"), text, '\0');
    vector<string> words{};
    vector<string> final;
    vector<int> counts;
    vector<Word> word_vector;
    put_words_in_vector(words, text);
    count_and_output(words, final, counts);
    for(size_t i = 0; i < final.size(); ++i){
        string word = final.at(i);
        int count = counts.at(i);
        word_vector.emplace_back(word, count);
    }

    //sort(word_vector.begin(), word_vector.end(), Word::get_count);
    for (size_t i = 0; i < final.size(); ++i)
        word_vector.at(i).show();
}