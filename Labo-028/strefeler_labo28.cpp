/**
 * @file strefeler_labo28.cpp
 * @author Michael Strefeler
 * @brief Opens text file and makes a list of all of the words in order of most used
 * @version 0.1
 * @date 10-12-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Word
{
private:
    string text;
    int count;

public:
    Word(const string &initWord = "", int initCount = 1);
    string getText() const;
    void setText(const string &setWord);
    int getCount() const;
    void setCount(int setCount);
    bool operator<(Word const &w) const;
    bool operator!=(Word const &w) const;
};

Word::Word(const string &initWord, int initCount) : text(initWord), count(initCount) {}

string Word::getText() const
{
    return text;
}

void Word::setText(const string &setWord)
{
    text = setWord;
}

void Word::setCount(int setCount)
{
    count = setCount;
}

int Word::getCount() const
{
    return count;
}

bool Word::operator<(Word const &w) const
{
    return text < w.getText();
}

bool Word::operator!=(Word const &w) const
{
    return text != w.getText();
}

/** @brief Parses a string, separates it's words and put them in a vector
 * @details Does not take the punctuation, spaces and non-printable char
 * @param text String that contains the words to separate
 * @return The vector filled by separated words */
vector<Word> separateWords(string &text);

/** @brief Counts occurences of a Word in a vector<Word> and erase them
 * @details Sort the vector by count and lexicograpgically
 * @param v The vector to be counted
 * @return vector<Word> without any occurences*/
vector<Word> countWordOccurences(vector<Word> &v);

/** @brief Outputs a formatted vector<Words> in the std:cout stream
 * @param w The vector*/
void outputText(const vector<Word> &w);

/** @brief Compares 2 words to be sorted by occurence and lexicographically
 * @details Used as predicate for the sort function
 * @param w1 The first word
 * @param w2 The second word
 * @return true if w1 < w2 in terms of predicate */
bool compareOccurences(const Word &a, const Word &b);

int main()
{
    string text;

    // Reads the file
    getline(ifstream("la_comedie_humaine.txt"), text, '\0');

    // Separate all words and put it in a vector
    vector<Word> words = separateWords(text);

    // Count occurences, delete them, sort the vector by count and output it to a file
    outputText(countWordOccurences(words));
}

bool compareOccurences(const Word &w1, const Word &w2)
{
    // Sort lexicographically if counts are identical
    if (w1.getCount() == w2.getCount())
        return w1.getText() < w2.getText();

    // Sort by count
    return w1.getCount() > w2.getCount();
}

void outputText(const vector<Word> &w)
{
    ofstream output_file("output.txt");

    for (auto i = w.begin(); i != w.end(); ++i)
    {
        // Write to the file
        output_file << (*i).getText() << " : " << (*i).getCount() << endl;
    }
    // Close the file
    output_file.close();
}

vector<Word> countWordOccurences(vector<Word> &w)
{
    // Sort the vector lexicographically
    sort(w.begin(), w.end());

    vector<Word> sortedVector;
    int cnt = 1;
    for (auto i = w.begin(); i != w.end(); ++i)
    {
        // Checks if the next word is different
        if (*i != *(i + 1))
        {
            // Puts the count in the last Word object
            (*i).setCount(cnt);

            // Push it back in the sorted vector
            sortedVector.push_back(*i);

            // Reset the count
            cnt = 1;
        }
        else
            cnt++;
    }
    // Sort the vector by count and lexicographically
    sort(sortedVector.begin(), sortedVector.end(), compareOccurences);
    return sortedVector;
}

vector<Word> separateWords(string &text)
{
    vector<Word> words;
    string word;
    for (auto i = text.begin(); i != text.end(); ++i)
    {
        // Push special characters with a length of 2 bytes
        if (*i == '\xC3' || *i == '\xC5' || *i == '\xC2')
        {
            word.push_back(*i);
            word.push_back(*(i + 1));
            ++i;
        }
        // Ignore special char with a length of 3 bytes
        else if (*i == '\xE2')
        {
            i += 2;

            // If a word was previously composed, push it
            if (word != "")
                words.emplace_back(Word(word));

            word.clear();
        }
        // Push all normal letters / digits
        else if (isalnum(*i))
        {
            word.push_back(*i);
        }
        // All other characters are ignored
        else
        {
            if (word != "")
            {
                words.emplace_back(Word(word));
                word.clear();
            }
        }
    }
    return words;
}