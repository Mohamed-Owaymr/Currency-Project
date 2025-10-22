#pragma once 
#include <iostream>
#include <fstream>
#include <vector>
#include "../Librarys/String/StringHandler.cpp"
using namespace std;

class Currency {
private:
    enum Mode { Empty = 1 , Update = 2 };

    Mode mode;
    string country;
    string code;
    string name;
    float rate;

    static vector<string> splitLineToWords(string line, const string& delimiter = "#//#") {
        vector<string> words = {};
        string wordTemporary = "";
        short delimiterPosition = 0;
        while ((delimiterPosition = line.find(delimiter)) != string::npos)
        {
            wordTemporary = line.substr(0, delimiterPosition);

            if (wordTemporary != "")
                words.push_back(wordTemporary);

            line.erase(0, delimiterPosition + delimiter.length());
        }
        if (line != "")
            words.push_back(line);
        return words;
    }

    static Currency convertCurrencyLineToObject(const string& line , const string& delimiter = "#//#") {
        vector<string> words = splitLineToWords(line , delimiter);
        return Currency(words[0] , words[1] , words[2] , stod(words[3]));
    }

    static vector<Currency> loadCurrenciesFileToVector(const string& currenciesFilePath = "../DataFiles/Currencies.txt" , const string& delimiter = "#//#") { 
        vector<Currency> currencies;
        ifstream currenciesFile; 
        currenciesFile.open(currenciesFilePath);
        if(currenciesFile.is_open())
        {
            string line;
            while(getline(currenciesFile , line)) {
                currencies.push_back(convertCurrencyLineToObject(line , delimiter));
            }
            currenciesFile.close();
        }
        return currencies;
    }

    static string convertCurrencyObjectToLine(const Currency& currency , const string& delimiter = "#//#") {
        string line;

        line += currency.country + delimiter;
        line += currency.code    + delimiter;
        line += currency.name    + delimiter;
        line += to_string(currency.rate);

        return line;

    }

    static bool loadCurrenciesVectorToFile(const vector<Currency>& currencies , const string& currenciesFilePath = "../DataFiles/Currencies.txt" , const string& delimiter = "#//#")
    {
        ofstream currenciesFile;
        currenciesFile.open(currenciesFilePath , ios::out);
        if(currenciesFile.is_open()) {
            for(const Currency& currency : currencies) {
                currenciesFile << convertCurrencyObjectToLine(currency , delimiter) << endl;
            }
            currenciesFile.close();
            return true;
        }
        else
            return false;
    }

    bool updateInFile(const string& currenciesFilePath = "../DataFiles/Currencies.txt" , const string& delimiter = "#//#") {
        ifstream currenciesFile;
        currenciesFile.open(currenciesFilePath);
        if(currenciesFile.is_open()) {
            vector<Currency> currencies = loadCurrenciesFileToVector(currenciesFilePath , delimiter);
            for(Currency& currency : currencies) {
                if(currency.getCode() == this->code) {
                    currency = *this;
                    break;
                }
            }
            return loadCurrenciesVectorToFile(currencies , currenciesFilePath  , delimiter);
        }
        else 
            return false;
    }

    static Currency getEmptyCurrencyObject() {
        return Currency();
    }


public:
    Currency()
    {
        mode = Empty;
        country = "";
        code = "";
        name= "";
        rate = 0;
    }

    Currency(const string& country, const string& code, const string& name, float rate)
    : country(country), code(code), name(name), rate(rate) {
        if(rate <= 0)
            throw invalid_argument("Rate must be positive value");
        mode = Update;
    }

    // Read Only
    string getCountry() const {
        return country;
    }

    // Read Only
    string getCode() const {
        return code;
    }

    // Read Only
    string getName() const {
        return name;
    }    

    float getRate() const {
        return rate;
    }

    bool updateRate(const float& newRate) {
        if(newRate <= 0)
            return false;
        rate = newRate;
        return updateInFile();
    }

    bool isEmpty() {
        return mode == Empty;
    }

    static bool isCurrencyExist(const string& code , const string& currenciesFilePath = "C:/Users/alawael/Desktop/Currency_Project/DataFiles/Currencies.txt" , const string& delimiter = "#//#") {
        Currency currency = findByCode(code , currenciesFilePath , delimiter);
        return !currency.isEmpty();
        
    }

    static Currency findByCountry(const string& country , const string& currenciesFilePath = "C:/Users/alawael/Desktop/Currency_Project/DataFiles/Currencies.txt" , const string& delimiter = "#//#") {
        ifstream currenciesFile; 
        currenciesFile.open(currenciesFilePath);
        if(currenciesFile.is_open())
        {
            string line;
            Currency currencyTemporary;
            while(getline(currenciesFile , line)) {
                currencyTemporary = convertCurrencyLineToObject(line , delimiter);
                if(StringHandler::upperAllString(currencyTemporary.getCountry()) == StringHandler::upperAllString(country))
                    return currencyTemporary;
            }
            currenciesFile.close();
            return getEmptyCurrencyObject();
        }
        return getEmptyCurrencyObject();
    }

    static Currency findByCode(const string& code , const string& currenciesFilePath = "C:/Users/alawael/Desktop/Currency_Project/DataFiles/Currencies.txt" , const string& delimiter = "#//#") {
        ifstream currenciesFile; 
        currenciesFile.open(currenciesFilePath);
        if(currenciesFile.is_open())
        {
            string line;
            Currency currencyTemporary;
            while(getline(currenciesFile , line)) {
                currencyTemporary = convertCurrencyLineToObject(line , delimiter);
                if(StringHandler::upperAllString(currencyTemporary.getCode()) == StringHandler::upperAllString(code))
                    return currencyTemporary;
            }
            currenciesFile.close();
            return getEmptyCurrencyObject();
        }
        return getEmptyCurrencyObject();
    }

    static vector<Currency> getCurrenciesList(const string& currenciesFilePath = "C:/Users/alawael/Desktop/Currency_Project/DataFiles/Currencies.txt" , const string& delimiter = "#//#") {
        return loadCurrenciesFileToVector(currenciesFilePath , delimiter);
    }

    float exchangeTo(const Currency& toCurrency , const float& amount) const {
        return amount * toCurrency.getRate() / this->rate;
    }
};