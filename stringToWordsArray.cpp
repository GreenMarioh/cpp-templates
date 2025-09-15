#include <bits/stdc++.h>
using namespace std;

vector<string> resolve(string &text)
{
    vector<string> words;
    istringstream iss(text);
    string word;
    while (iss >> word)
    {
        words.push_back(word);
    }
    return words;
}