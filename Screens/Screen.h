#pragma once
#include<iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class Screen
{
private:

protected:

    static void displayHeader(const string &title) {
        cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
        Tap(7);
        cout << title << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
    }

    static void displayList(const string listItems[] , const size_t& size) {
        for(size_t i = 0; i < size; ++i)
        {
            cout << "[" << i + 1 << "] ";
            cout << listItems[i] << endl << endl;
        }
        cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
    }

    static void clearScreenTerminal() {
        cout << "\033[2J\033[1;1H";
    }

    static bool clickOnAnyKey(const string& msg) {
        cout << msg;
        return getch();
    }

    static void Tap(short taps) {
        for(int i = 0; i < taps; ++i) cout << '\t';
    }

    static void displayTableNavBar(const string lables[] , short totlaLablesSize , const short widths[] , short totalWidthsSize) {

        for(size_t i = 0; i < totlaLablesSize; ++i)
            cout << "| " << left << setw(widths[i]) << lables[i];  

        cout << "\n---------------------------------------------------------------------------------------------------------------------------------------\n";
    }


};

