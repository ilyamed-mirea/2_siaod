#ifndef Printer_h
#define Printer_h

#include "base.h"

class Printer : public base {
public:
    Printer(base *head = nullptr, string name = "", int state = 0) : base(head,name,state) {};
    void pointerHandler(base* obj, string& text) {
        if (getState()) {
            cout << text;
            if (text!="Turn off the ATM")
                cout << endl;// << endl;//<< " "+getRoot(this)->curStatus << endl;
        }
    }
};

#endif