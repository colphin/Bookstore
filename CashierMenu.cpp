/* 
 * File:   CashierMenu.cpp
 * Author: kim
 * 
 * Created on July 30, 2014, 10:45 PM
 */

#include "CashierMenu.h"
#define _CRT_SECURE_NO_WARNINGS

// Virtual function
void CashierMenu::printMenu()
{
//    clearScreen();
    BaseMenu::printMenu();
    cout << "1. Sell a book" << endl;
    cout << "2. Return a book" << endl;
    cout << "3. Price check" << endl;
    cout << "4. Return to Main Menu" << endl;

}