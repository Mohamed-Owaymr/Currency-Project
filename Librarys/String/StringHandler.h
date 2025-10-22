#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include <algorithm>
using namespace std;

class StringHandler
{
private:
    string data;
    static bool isPunctuation(const char& ch);
    static bool isDelimiter(const char& ch);
    static bool isUpper(const char& letter);
    static bool isLower(const char& letter);
    static char toUpper(const char& letter);
    static char toLower(const char& letter);
    static char invertLetter(const char& letter);
    static bool isVowel(const char& ch);
    static size_t countCharactersInArrayOfWords(const vector<string>& words);
    static size_t countCharactersInArrayOfWords(const string words[] , const size_t& length);
    static vector<string> replaceWordInVector(const vector<string>& words , const string& orignalWord , const string& newWord , bool caseSecitive = true);



public:
    StringHandler();
    StringHandler(const string& data);

    static string upperizTheFirstLetterInEachWord(const string& str);
    string upperizTheFirstLetterInEachWord();

    static string upperAllString(const string& str);
    string upperAllString();

    static string lowerAllString(const string& str);
    string lowerAllString();

    static string invertAllLetters(const string& str);
    string invertAllLetters();

    static size_t countCapitalLetters(const string& str);
    size_t countCapitalLetters();

    static size_t countSmallLetters(const string& str);
    size_t countSmallLetters();

    static size_t countCharacter(const string& str , const char& targetChar , const bool& caseSensitive);
    size_t countCharacter(const char& targetChar , const bool& caseSensitive);

    static size_t countVowels(const string& str); 
    size_t countVowels(); 

    static vector<string> splitWordsInVector(const string& str);
    vector<string> splitWordsInVector();

    static size_t countWordsInString(const string& str);
    size_t countWordsInString();

    static string trimLeft(const string& str);
    string trimLeft();
    
    static string trimRight(const string& str);
    string trimRight();

    static string trimAll(const string& str);
    string trimAll();

    static string joinString(const vector<string>& words , const string& delimiter = " ");
    static string joinString(const string words[] , const size_t& length , const string& delimiter);

    static string reverse(const string & baseString);
    string reverse();



    static vector<string> reverseWordsInVector(const vector<string>& words);
    static void reverseWordsInArray(string words[] , const size_t& length);
    static string reverseWordsInString(const string & words , const string& delimiter = " ");
    string reverseWords(const string& delimiter = " ");

    static string replaceWordInString(const string& baseString , const string& orignalWord , const string& newWord , const string& delimiter = " " , bool caseSencitive = true);
    string replaceWordInString(const string& orignalWord , const string& newWord , const string& delimiter = " " , bool caseSencitive = true);

    static string removeAllPunctuations(const string& baseString);
    string removeAllPunctuations();



};


