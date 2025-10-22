#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../HeaderFiles/Currency.h"
#include "../../Librarys/Input/InputValidation.cpp"
using namespace std;

class UpdateCurrencyRateScreen : protected Screen {
private:
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

    static string readExistCurrencyCode(const string& msg) {
        string code = Input_Validation::readString(msg);
        while (!Currency::isCurrencyExist(code))
        {
            cout << "\nCurrency Was Not Found\n";
            code = Input_Validation::readString(msg);
        }
        return code;
    }

    static float readCurrencyRate(const string& msg) {
        float rate = Input_Validation::readPositiveNumber(msg);
        return rate;
    }
public:
    static void displayUpdateCurrencyRateScreen() {
        Screen::displayHeader("Update Currency Rate Screen");
        string code = readExistCurrencyCode("Please Enter Currency Code Here");
        Currency currency = Currency::findByCode(code);
        displayCurrencyInfo(currency);
        float newRate = readCurrencyRate("\nPlease Enter New Rate Here");
        bool confirmUpdate = Input_Validation::readYesNoAsBool("\nAre You Sure Perform This Update[Y ,N]");
        if(confirmUpdate) {
            if(currency.updateRate(newRate))
                cout << "\nRate Updated Successifuly:-)\n";
            else
                cout << "\nCan NOT Perform This Update:-(\n";
        }
    }
};