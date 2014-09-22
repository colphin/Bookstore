/* 
 * File:   ReportMenu.h
 * Author: kim
 *
 * Created on July 30, 2014, 10:45 PM
 */

#ifndef REPORTMENU_H
#define	REPORTMENU_H
#include "BaseMenu.h"

class ReportMenu:public BaseMenu
{
private:
    
public:
   // Virtual function
    virtual void printMenu(); // Will be used to demonstrate dynamic binding

    

};

#endif	/* REPORTMENU_H */
