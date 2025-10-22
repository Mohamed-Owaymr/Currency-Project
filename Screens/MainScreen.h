#pragma once
#include <iostream>
#include "Screen.h"
#include "Currency/ListCurrenciesScreen.h"
#include "Currency/FindCurrencyScreen.h"
#include "Currency/UpdateCurrencyRateScreen.h"
#include "Currency/CurrencyCalculatorScreen.h"
#include "../Librarys/Input/InputValidation.cpp"
using namespace std;

class MainScreen : protected Screen { 
private:
    enum MainScreenOptions { 
        ListCurrencies = 1 ,
        FindCurrency       ,
        UpdateCurrencyRate ,
        CurrencyCalculator ,
        Exit 
    };

    static void listCurrencies() {
        ListCurrenciesScreen::displayListCurrenciesScreen();
    }
    static void findCurrency() {
        FindCurrencyScreen::displayFindCurrencyScreen();
    }
    static void updateCurrencyRate() {
        UpdateCurrencyRateScreen::displayUpdateCurrencyRateScreen();
    }
    static void currencyCalculator() {
        CurrencyCalculatorScreen::displayCurrencyCalculatorScreen();
    }

    static void performMainMenuOption(const MainScreenOptions& option) {
        switch (option) {
            case ListCurrencies: {
                listCurrencies();
                Screen::clickOnAnyKey("\n\nClick On Any key To Go Back To Main Currency Extchange Menu Screen...");
                break;
            }
            case FindCurrency: {
                findCurrency();
                break;
            }
            case UpdateCurrencyRate: {
                updateCurrencyRate();
                Screen::clickOnAnyKey("\n\nClick On Any key To Go Back To Main Currency Extchange Menu Screen...");
                break;
            }
            case CurrencyCalculator: {
                currencyCalculator();
                break;
            }
                
            default:
                break;
        }
    }

public:
    static void displayMainMenuScreen()
    {
        string items[] = {"List Currencies" , "Find Currency" , "Update Currency Rate" , "Currency Calculator" , "Exit"};
        size_t sizeOfItems = sizeof(items) / sizeof(items[0]);
        MainScreenOptions option;
        bool exitConfirm = false;
        Screen::clearScreenTerminal();
        do
        {
            Screen::displayHeader("Currency Extchange Menu Screen");
            Screen::displayList(items , sizeOfItems);
            option = Input_Validation::readOptionNumber<MainScreenOptions>("\nChoose What Do You Want To Do? [1 to " + to_string(Input_Validation::getEnumSizeUsingMagicEnumCount<MainScreenOptions>()) + "]");
            Screen::clearScreenTerminal();
            if(option != Exit) {
                performMainMenuOption(option);
            }
            else {
                exitConfirm = Input_Validation::readYesNoAsBool("Are You Sure You Want To Exit [Y , N]");
            }
            Screen::clearScreenTerminal();
        } while (!exitConfirm);
        
    }
};


