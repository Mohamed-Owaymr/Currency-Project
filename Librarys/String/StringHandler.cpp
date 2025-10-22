#include "StringHandler.h"

StringHandler::StringHandler(){data = "";}
StringHandler::StringHandler(const string& data){this->data = data;}


bool StringHandler::isPunctuation(const char& ch)
{
    return ispunct(static_cast<unsigned char>(ch));
}
bool StringHandler::isDelimiter(const char& ch)
{
    return ch == ' ' || ch == '\t' || ch == '\n';   
}
bool StringHandler::isUpper(const char& letter)
{
    return (letter >= 'A' && letter <= 'Z');
}
bool StringHandler::isLower(const char& letter)
{
    return (letter >= 'a' && letter <= 'z');
}
char StringHandler::toUpper(const char& letter)
{
    if(isLower(letter))
        return letter - 32;
    else
        return letter;
}
char StringHandler::toLower(const char& letter)
{
    if(isUpper(letter))
        return letter + 32;
    else
        return letter;
}
char StringHandler::invertLetter(const char& letter)
{
    if(isUpper(letter))
        return toLower(letter);
    else if(isLower(letter))
        return toUpper(letter);
    else
        return letter;
}
bool StringHandler::isVowel(const char& ch)
{
    switch (ch)
    {
        case 'a': return true;
        case 'A': return true;
        case 'e': return true;
        case 'E': return true;
        case 'u': return true;
        case 'U': return true;
        case 'i': return true;
        case 'I': return true;
        case 'o': return true;
        case 'O': return true;

        default : return false;
    }
}

string StringHandler::upperizTheFirstLetterInEachWord(const string& str)
{
    if(str.empty())
        throw runtime_error("Uppercase operation failed: cannot process an empty string. Please provide a non-empty string.");

    string upperizedString = "";
    bool isFirstLetterInWord = true;

    for(size_t i = 0; i < str.length(); ++i)
    {
        if(isFirstLetterInWord && !(isspace(str[i]) || isPunctuation(str[i])))
        {
            upperizedString[i] += toUpper(str[i]);
            isFirstLetterInWord = false;
        }
            
        else 
        {
            upperizedString[i] += str[i];
            if((isspace(str[i]) || isPunctuation(str[i])))
                isFirstLetterInWord = true;
        }
    }
    return upperizedString;
        
}
string StringHandler::upperizTheFirstLetterInEachWord()
{
    this->data = upperizTheFirstLetterInEachWord(this->data);
    return this->data;
}

string StringHandler::upperAllString(const string& str)
{
    if(str.empty())
        throw runtime_error("Uppercase operation failed: cannot process an empty string. Please provide a non-empty string.");

    string upperizedString;
    upperizedString.reserve(str.size());
    for(const char& ch : str)
    {
        if(isLower(ch))
            upperizedString += toUpper(ch);
        else    
            upperizedString += ch;
    }
    return upperizedString;
}
string StringHandler::upperAllString()
{
    this->data = upperAllString(this->data);
    return this->data;
}

string StringHandler::lowerAllString(const string& str)
{
    if(str.empty())
        throw runtime_error("Lowercase operation failed: cannot process an empty string. Please provide a non-empty string.");


    string lowerizedString;
    lowerizedString.reserve(str.size());

    for(const char& ch : str)
    {
        if(isUpper(ch))
            lowerizedString += toLower(ch);
        else    
            lowerizedString += ch;
    }
    return lowerizedString;
}
string StringHandler::lowerAllString()
{
    this->data = lowerAllString(this->data);
    return this->data;
}

string StringHandler::invertAllLetters(const string& str)
{
    if(str.empty())
        throw runtime_error("Invert operation failed: cannot process an empty string. Please provide a non-empty string.");

    string invertedString;
    invertedString.reserve(str.size());

    for(const char& ch : str)
        invertedString += invertLetter(ch);

    return invertedString;
}
string StringHandler::invertAllLetters()
{
    this->data = invertAllLetters(this->data);
    return this->data;
}

size_t StringHandler::countCapitalLetters(const string& str)
{

    size_t counter = 0;
    for(const char& ch : str)
        if(isUpper(ch)) ++counter;

    return counter;

}
size_t StringHandler::countCapitalLetters()
{
    return countCapitalLetters(this->data);
}

size_t StringHandler::countSmallLetters(const string& str)
{
    size_t counter = 0;
    for(const char& ch : str)
        if(isLower(ch)) ++counter;

    return counter;
}
size_t StringHandler::countSmallLetters()
{
    return countSmallLetters(this->data);
}

size_t StringHandler::countCharacter(const string& str , const char& targetChar , const bool& caseSensitive)
{
    size_t counter = 0;

    for(const char& ch : str)
    {
        if(caseSensitive)
        {
            if(ch == targetChar)
                ++counter;
        }
        else
        {
            if(toLower(ch) == toLower(targetChar))
                ++counter;
        }
    }

    return counter;
}
size_t StringHandler::countCharacter(const char& targetChar , const bool& caseSensitive)
{
    return countCharacter(this->data , targetChar , caseSensitive);
}

size_t StringHandler::countVowels(const string& str)
{
    size_t counter = 0;
    for(const char& ch : str)
        if(isVowel(ch)) ++counter;
    return counter;
}
size_t StringHandler::countVowels()
{
    return countVowels(this->data);
}

vector<string> StringHandler::splitWordsInVector(const string& str)
{
    if(str.empty())
        return {};

    vector<string> words;

    string wordTemporary;
    wordTemporary.reserve(str.size());

    for(const char& ch : str)
    {
        if(isDelimiter(ch))
        {
            if(!wordTemporary.empty())
            {
                words.push_back(wordTemporary);
                wordTemporary.clear();
            }
        }
        else
            wordTemporary += ch;

    }

    if(!wordTemporary.empty())
        words.push_back(wordTemporary);

    return words;
}
vector<string> StringHandler::splitWordsInVector()
{
    return splitWordsInVector(this->data);
}

size_t StringHandler::countWordsInString(const string& str)
{
    vector<string> words = splitWordsInVector(str);
    return words.size();
}
size_t StringHandler::countWordsInString()
{
    return countWordsInString(this->data);
}

string StringHandler::trimLeft(const string& str)
{
    // Optimization: if the string is empty or the first character is not a space, 
    // then no trimming is needed, just return the original string
    if(str.empty() || !isspace(str[0]))
        return str;

    size_t firstNonSpacePos  = 0;

    while(isspace(str[firstNonSpacePos]))
        ++firstNonSpacePos;

    return str.substr(firstNonSpacePos);
}
string StringHandler::trimLeft()
{
    this->data = trimLeft(this->data);
    return this->data;
}
string StringHandler::trimRight(const string& str) 
{
    // Optimization: if the string is empty or the last character is not a space, 
    // then no trimming is needed, just return the original string
    if(str.empty() || !isspace(str[str.length() - 1]))
        return str;

    int trimmedStringLength = str.length();

    for(int i = str.length() - 1; i >= 0; --i)
    {
        if(isspace(str[i]))
            --trimmedStringLength;
        else
            break;
    }


    return str.substr(0 , trimmedStringLength);
}
string StringHandler::trimRight()
{
    this->data = trimRight(this->data);
    return this->data;
}
string StringHandler::trimAll(const string& str)
{
    if(str.empty())
        return str;

    string trimmedString = trimLeft(str);

    trimmedString = trimRight(trimmedString);

    return trimmedString;

}
string StringHandler::trimAll()
{
    this->data = trimAll(this->data);
    return this->data;
}
size_t StringHandler::countCharactersInArrayOfWords(const vector<string>& words)
{
    size_t totalSize = 0;
    for(const string& word : words)
        totalSize += word.length();
    return totalSize;
}
size_t StringHandler::countCharactersInArrayOfWords(const string words[] , const size_t& length)
{
    size_t totalSize = 0;
    for(size_t i = 0; i < length; ++i)
        totalSize += words[i].length();
    return totalSize;
}
string StringHandler::joinString(const vector<string>& words , const string& delimiter)
{
    if(words.empty())
        return "";

    string joinString;
    joinString.reserve(countCharactersInArrayOfWords(words) + delimiter.size() * (words.size() - 1));
    for(size_t i = 0; i < words.size(); ++i)
    {
        joinString += words[i];

        if(i != (words.size() - 1))
        {
            joinString += delimiter;
        }
    }
    return joinString;

}
string StringHandler::joinString(const string words[] , const size_t& length , const string& delimiter)
{
    if(length == 0)
        return "";

    string joinString;
    joinString.reserve(countCharactersInArrayOfWords(words , length) + delimiter.size() * (length - 1));
    for(size_t i = 0; i < length; ++i)
    {
        joinString += words[i];

        if(i != (length - 1))
        {
            joinString += delimiter;
        }
    }
    return joinString;
}

string StringHandler::reverse(const string & baseString)
{
    string reversedString = "";
    for(short i = baseString.length() - 1; i >= 0; --i)
    {
        reversedString += baseString[i];
    }
    return reversedString;
}
string StringHandler::reverse()
{
    this->data = reverse(this->data);
    return this->data;
}


vector<string> StringHandler::reverseWordsInVector(const vector<string>& words)
{
    vector<string> reversedWords = words;

    std::reverse(reversedWords.begin(), reversedWords.end());

    return reversedWords;
}
void StringHandler::reverseWordsInArray(string words[] , const size_t& length)
{
    std::reverse(words, words + length);
}
string StringHandler::reverseWordsInString(const string & words , const string& delimiter)
{
    vector<string> reversedWords = reverseWordsInVector(splitWordsInVector(words));
    return joinString(reversedWords , delimiter);
}
string StringHandler::reverseWords(const string& delimiter)
{
    this->data = reverseWordsInString(this->data , delimiter);
    return this->data;
}

vector<string> StringHandler::replaceWordInVector(const vector<string>& words , const string& orignalWord , const string& newWord , bool caseSecitive)
{
    if(words.empty() || orignalWord.empty())
        return words;

    vector<string> wordsAfterReplace = words;

    string lowerOrignalWord = lowerAllString(orignalWord);

    for(string& word : wordsAfterReplace)
    {
        if(caseSecitive)
        {
            if(word == orignalWord)
                word = newWord;
        }
        else
        {
            if(lowerAllString(word) == lowerOrignalWord)
                word = newWord;
        }
    }

    return wordsAfterReplace;
}
string StringHandler::replaceWordInString(const string& baseString , const string& orignalWord , const string& newWord , const string& delimiter , bool caseSensitive)
{
    if(baseString.empty() || orignalWord.empty())
        return baseString;

    vector<string> words = splitWordsInVector(baseString);
    words = replaceWordInVector(words , orignalWord , newWord , caseSensitive);
    return joinString(words , delimiter);
}
string StringHandler::replaceWordInString(const string& orignalWord , const string& newWord , const string& delimiter , bool caseSensitive)
{
    this->data = replaceWordInString(this->data , orignalWord , newWord , delimiter , caseSensitive);
    return this->data;
}
string StringHandler::removeAllPunctuations(const string& baseString)
{
    string stringAfterRemovePunc = "";
    for(const char &ch : baseString) if( !ispunct(ch) ) stringAfterRemovePunc += ch;
    return stringAfterRemovePunc;
}
string StringHandler::removeAllPunctuations()
{
    this->data = removeAllPunctuations(this->data);
    return this->data;
}

