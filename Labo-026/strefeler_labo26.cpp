/**
 * @file strefeler_labo26.cpp
 * @author Michael Strefeler
 * @brief Read a text file and make an array of all the worlds
 * @version 0.1
 * @date 30-11-2021
 *
 * @copyright Copyright (c) 2021
 * use this commmand to run program
 * a.exe < les_miserables.txt > out.txt
 */
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

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
void count_and_output(vector<string> words){
    sort(words.begin(), words.end());
    vector<string> final;
    vector<int> counts;

    // Creates a vector of all words without duplicates
    for (size_t i = 0; i < words.size(); i++)
    {
        if(!count(final.begin(), final.end(), words.at(i))){
            final.push_back(words.at(i));
        }
    }

    // Creates a vector with the number of occurences of each word
    for(size_t i = 0; i < final.size(); ++i){
        counts.push_back((int)count(words.begin(), words.end(), final.at(i)));
    }

    // Outputs each word with how many times it shows up in the text
    for (size_t i = 0; i < final.size(); ++i)
    {
        cout << final.at(i) << " : " << counts.at(i) << endl;
    }
}

int main()
{
    string text;
    getline(cin, text, '\0');
    vector<string> words{};
    put_words_in_vector(words, text);
    count_and_output(words);
}