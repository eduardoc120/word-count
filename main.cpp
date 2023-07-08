#include <iostream>
#include <cctype>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Function to delete special characters from a string
string deleteSpecialChars(string str) {
    char specialChars[11] = 
    {
        '!', '.', ',', '?', '(', ')', '$', '#', '%', '@', '*' 
    };
    for (size_t i = 0; i < sizeof(specialChars) / sizeof(specialChars[0]); i++)
    {
        size_t pos = str.find(specialChars[i]); // Find the position of the character
        if (pos != string::npos) 
        {
            str.erase(pos, 1); // Erase the character at the found position
        }
    }
    return str;
}


// Function to convert a string to lowercase
string toLowerCase(string str) 
{
    for (string::size_type i = 0; i < str.length(); i++) 
    {
        str[i] = tolower(str[i]); // Convert each character to lowercase
    }
    return str;
}

// Function to update the word count in the map
void updateWordCount(map<string, int>& existingWords, string newWord)
{
    map<string, int>::iterator it = existingWords.find(newWord);

    if (it != existingWords.end())
    {
        it->second++; // Increment the count if the word already exists
    }
    else
    {
        existingWords[newWord] = 1; // Add a new word with count 1
    }
}

// Function to display the word count
void displayWordCount(vector<pair<string, int> > sortedWords) 
{
    cout << "Word Frequency:" << endl;
    for (vector<pair<string, int> >::iterator it = sortedWords.begin(); it != sortedWords.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

// Comparison function for sorting by value in descending order
bool compareByValue(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

int main() 
{

    bool validFile = false;
    map<string, int> words;

    // Repeating the cycle until we have a valid input

    while (!validFile)
    {
        string fileName = " ";

        cout << "Enter filename to open (or 'q' to quit): ";
        cin >> fileName;

        if (fileName == "q") {
            break;
        }

        ifstream inputText(fileName);
        if (inputText.is_open())
        {
            validFile = true;
            string line = " ";

            while (getline(inputText, line))
            {
                for(string::size_type i = 0; i < line.length(); i++)
                {
                    string word = "";
                    while (i < line.length() && line[i] != ' ')
                    {
                        word += line[i];
                        i++;
                    }
                    word = toLowerCase(word); // Convert the word to lowercase
                    word = deleteSpecialChars(word); // Delete special characters from the word
                    updateWordCount(words, word); // Update the word count in the map
                }
            }

            // Create a vector of pairs from the words map
            vector<pair<string, int> > vec(words.begin(), words.end());

            // Sort the vector by values
            sort(vec.begin(), vec.end(), compareByValue);

            displayWordCount(vec); // Display the word count

        }
        else
        {
            cout << "Invalid file!" << endl; // Display an error message for invalid file
        }
    }

    return 0;
}
