#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    int ender;              //get int from wining case checker
    display obj;            //create object
    obj.displayinit();      //playing board display

    do{
        obj.choices();         //mark done by player
        ender=obj.checker();
        if (ender==1 || ender==(-1))
            break;
    }while(obj.game());

        if(ender==1)
            cout<<endl<<"Player 1 wins";
        else if(ender==(-1))
            cout<<endl<<"Player 2 wins";
        else if(ender==0)
            cout<<endl<<"Game is a draw";

    return 0;
}
