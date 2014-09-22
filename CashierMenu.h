/* 
 * File:   CashierMenu.h
 * Author: kim
 *
 * Created on July 30, 2014, 10:45 PM
 */

#ifndef CASHIERMENU_H
#define	CASHIERMENU_H
#include "BaseMenu.h"

class CashierMenu:public BaseMenu
{
    
private:

public:
    // Virtual function
    virtual void printMenu(); // Will be used to demonstrate dynamic binding

    
};

#endif	/* CASHIERMENU_H */
