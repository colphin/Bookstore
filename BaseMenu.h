/* 
 * File:   BaseMenu.h
 * Author: kim
 *
 * Created on July 30, 2014, 10:44 PM
 */

#ifndef BASEMENU_H
#define	BASEMENU_H
#include <iostream>
#include <string>

using namespace std;

class BaseMenu {
protected:
    void clearScreen()
    {
        cout << string(50, '\n');    
    }
public:
  
    
    // Virtual function
    virtual void printMenu(); // Will be used to demonstrate dynamic binding
    virtual void displayOptions();

};

#endif	/* BASEMENU_H */
