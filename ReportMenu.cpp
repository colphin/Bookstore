/* 
 * File:   ReportMenu.cpp
 * Author: kim
 * 
 * Created on July 30, 2014, 10:45 PM
 */

#include "ReportMenu.h"
#define _CRT_SECURE_NO_WARNINGS

// Virtual function
void ReportMenu::printMenu()
{
//    clearScreen();
    BaseMenu::printMenu();
    cout << "1. Inventory Listing" << endl;
    cout << "2. Inventory Wholesale Listing" << endl;
    cout << "3. Inventory Retail Value" << endl;
    cout << "4. Listing by Quantity" << endl;
    cout << "5. Listing by Cost"<< endl;
    cout << "6. Listing by Age" << endl;
    cout << "7. Return to Main Menu" << endl;
}