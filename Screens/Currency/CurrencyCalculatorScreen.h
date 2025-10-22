#pragma one
#include <iostream>
#include "../Screen.h"
#include "../../HeaderFiles/Currency.h"
#include "../../Librarys/Input/InputValidation.cpp"
using namespace std;

class CurrencyCalculatorScreen : protected Screen {
private:
    static string readExistCurrencyCode(const string& msg) {
        string code = Input_Validation::readString(msg);
        while (!Currency::isCurrencyExist(code))
        {
            cout << "\nCurrency Was Not Found\n";
            code = Input_Validation::readString(msg);
        }
        return code;
    }

    static float readAmount(const string& msg) {
        float amount = Input_Validation::readPositiveNumber(msg);
        return amount;
    }

    static void displayExchangeResult(const string& fromCode , const string& toCode , const float& amount , const float& exchangeResult) {
        cout << "\n--------------------------------------------------------------\n";
        cout << amount << " " << fromCode << " = " << exchangeResult << " " << toCode;
        cout << "\n--------------------------------------------------------------\n\n";
    }
public:
    static void displayCurrencyCalculatorScreen() {
        bool performAnotherCalculation = false;
        do
        {
            Screen::displayHeader("Currency Calculator Screen");
            string exchangeFromCode = readExistCurrencyCode("Please Enter Exchange From Currency Code Here");
            string exchangeToCode   = readExistCurrencyCode("\nPlease Enter Exchange To Currency Code Here");
            float amount = readAmount("\nPlease Enter Amount Here");
            Currency fromCurrency = Currency::findByCode(exchangeFromCode);
            Currency toCurrency   = Currency::findByCode(exchangeToCode);
            float exchangeResult = fromCurrency.exchangeTo(toCurrency , amount);
            displayExchangeResult(fromCurrency.getCode() , toCurrency.getCode() , amount , exchangeResult);
            performAnotherCalculation = Input_Validation::readYesNoAsBool("Do You Want To Perform Another Calculation [Y , N]");
            Screen::clearScreenTerminal();
        } while (performAnotherCalculation);
           
    }
};