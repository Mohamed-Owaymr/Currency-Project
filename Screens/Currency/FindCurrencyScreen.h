#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../HeaderFiles/Currency.h"
#include "../../Librarys/Input/InputValidation.cpp"
using namespace std;

class FindCurrencyScreen : protected Screen {
private:
    enum FindCurrencyOptions {Country = 1 , CurrencyCode = 2 , BackToMainCurrencyMenu = 3};

    static void displayCurrencyInfo(const Currency& currency) {
        cout << "\n-------------------------------------\n";
        cout << "Currency Info";
        cout << "\n-------------------------------------\n";
        cout << "Country  : " << currency.getCountry() << endl;
        cout << "Code     : " << currency.getCode()    << endl;
        cout << "Name     : " << currency.getName()    << endl;
        cout << "Rate(1$) : " << currency.getRate();
        cout << "\n-------------------------------------\n";
    }

    static void displayCurrencyInfoByCountry(const string& country) {
        Currency currency = Currency::findByCountry(country);
        if(currency.isEmpty())
            cout << "\nCurrency Was Not Found\n";
        else 
            displayCurrencyInfo(currency);
    }

    static void displayCurrencyInfoByCode(const string& code) {
        Currency currency = Currency::findByCode(code);
        if(currency.isEmpty())
            cout << "\nCurrency Was Not Found\n";
        else 
            displayCurrencyInfo(currency);
    }

    static void performFindCurrencyOption(const FindCurrencyOptions& option) {
        switch (option)
        {
        case Country: {
            
            string country = Input_Validation::readString("Please Enter The Country Here");
            displayCurrencyInfoByCountry(country);
            Screen::clickOnAnyKey("\n\nClick On Any key To Go Back To Find Currency Screen...");
            break;
        }
        case CurrencyCode: {
            string code = Input_Validation::readString("Please Enter The Currency Code Here");
            displayCurrencyInfoByCode(code);
            Screen::clickOnAnyKey("\n\nClick On Any key To Go Back To Find Currency Screen...");
            break;
        }
        default:
            break;
        }
    }

public:
    static void displayFindCurrencyScreen() {
        string items[] = {"Find By Country" , "Find By Currency Code" , "Back To Main Menu"};
        size_t sizeOfItems = sizeof(items) / sizeof(items[0]);
        FindCurrencyOptions findCurrencyOption;
        do
        {
            Screen::displayHeader("Find Currency Screen");
            Screen::displayList(items , sizeOfItems);
            findCurrencyOption = Input_Validation::readOptionNumber<FindCurrencyOptions>("\nChoose What Do You Want To Do? [1 to " + to_string(Input_Validation::getEnumSizeUsingMagicEnumCount<FindCurrencyOptions>()) + "]");  
            Screen::clearScreenTerminal(); 
            if(findCurrencyOption != BackToMainCurrencyMenu) {
                performFindCurrencyOption(findCurrencyOption);
            }
            Screen::clearScreenTerminal();
        } while (findCurrencyOption != BackToMainCurrencyMenu);
        
    }
};