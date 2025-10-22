#pragma once
#include <iostream>
#include "../Screen.h"
#include "../../HeaderFiles/Currency.h"
using namespace std;

class ListCurrenciesScreen : protected Screen {
private:

    static void displayCurrencyRecordLine(const Currency& currency) {

        cout << "| " << left << setw(40) << currency.getCountry();
        cout << "| " << left << setw(15) << currency.getCode();
        cout << "| " << left << setw(60) << currency.getName();
        cout << "| " << left << setw(15) << currency.getRate();
        cout << endl;
    }
    static void displayTableBody(const vector<Currency>& currencies) {
        if(currencies.size() == 0)
        {
            Screen::Tap(7);
            cout << "NO AVAILABLE Currencies FOUND\n";
        }
        else
        {
            for (const Currency &currency : currencies)
            {
                displayCurrencyRecordLine(currency);
            }
                
        }
            
        cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";

    }

    static void displayTableHeader(const string& title) {
        Screen::displayHeader(title);
    }


public:
    static void displayListCurrenciesScreen() {
        vector<Currency> currencies = Currency::getCurrenciesList();
        displayTableHeader("Currencies List (" + to_string(currencies.size()) + ") Currency(s)");
        string lables[] = {"Country" , "Code" , "Name" , "Rate/(1$)"};
        short widths[]  = {     40   ,   15   ,   60   ,     15     };
        size_t lablesSize = sizeof(lables) / sizeof(lables[0]); 
        size_t widthsSize = sizeof(widths) / sizeof(widths[0]); 
        Screen::displayTableNavBar(lables , lablesSize , widths , widthsSize);
        displayTableBody(currencies);
    }
};