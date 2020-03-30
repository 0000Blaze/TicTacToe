
using namespace std;

class display
{
private:
    char cells[9];
    bool ch=true;
    int position;

public:
    display(){
        //constructor initializes cells
        for (int i=0;i<9;i++){
            //ANSCII value of 1 is 49
            cells[i]=(49+i);
        }
    }

    void displayinit()
    {
        //display playing board
        cout<<"  Player 1 <X>    ,   Player 2 <O>"<<endl<<endl;
        cout<<endl;
        cout<<"    "<<cells[0]<<"\t|\t"<<cells[1]<<"\t|\t"<<cells[2]<<"\t"<<endl;
        cout<<"________________________________________"<<endl<<endl;
        cout<<"    "<<cells[3]<<"\t|\t"<<cells[4]<<"\t|\t"<<cells[5]<<"\t"<<endl;
        cout<<"________________________________________"<<endl<<endl;
        cout<<"    "<<cells[6]<<"\t|\t"<<cells[7]<<"\t|\t"<<cells[8]<<"\t"<<endl<<endl;
    }

    void choices()
    {
        //choice for the player where to mark
        if (ch)
        {
            cout<<" Player 1 ,enter position:";
            cin>>position;

            if (cells[position-1]=='0')
            {
                cout<<"Invalid move"<<endl;
                system("pause");
            }
            else
                cells[position-1]='X';

            ch=false;
        }
        else if(!ch)
        {
            cout<<" Player 2 ,enter position:";
            cin>>position;
            if(cells[position-1]=='X')
            {
                cout<<"Invalid move"<<endl;
                system("pause");
            }
            else
                cells[position-1]='O';

            ch=true;
        }
      //clear the screen
      system("cls");
      //re-display after marking is done by player
      displayinit();
    }

    int checker()
    {
        //checks if the wining condition has been satisfied
        if(
           (((cells[0]=='X')&&(cells[1]=='X'))&&(cells[2]=='X')) ||
           (((cells[0]=='X')&&(cells[3]=='X'))&&(cells[6]=='X')) ||
           (((cells[0]=='X')&&(cells[4]=='X'))&&(cells[8]=='X')) ||
           (((cells[1]=='X')&&(cells[4]=='X'))&&(cells[7]=='X')) ||
           (((cells[3]=='X')&&(cells[4]=='X'))&&(cells[5]=='X')) ||
           (((cells[2]=='X')&&(cells[5]=='X'))&&(cells[8]=='X')) ||
           (((cells[2]=='X')&&(cells[4]=='X'))&&(cells[6]=='X')) ||
           (((cells[6]=='X')&&(cells[7]=='X'))&&(cells[8]=='X')))
            {
               return 1; //player 1 wins
            }
        else if(
                ((cells[0]=='O')&&(cells[1]=='O')&&(cells[2]=='O')) ||
                ((cells[0]=='O')&&(cells[3]=='O')&&(cells[6]=='O')) ||
                ((cells[0]=='O')&&(cells[4]=='O')&&(cells[8]=='O')) ||
                ((cells[1]=='O')&&(cells[4]=='O')&&(cells[7]=='O')) ||
                ((cells[3]=='O')&&(cells[4]=='O')&&(cells[5]=='O')) ||
                ((cells[2]=='O')&&(cells[5]=='O')&&(cells[8]=='O')) ||
                ((cells[2]=='O')&&(cells[4]=='O')&&(cells[6]=='O')) ||
                ((cells[6]=='O')&&(cells[7]=='O')&&(cells[8]=='O')))
                {
                    return -1; //player 2 wins
                }
         else
            return 0; //draw case
    }

    bool game()     //game run time function
    {
        if(cells[0]!='1'&&  cells[1]!='2'&& cells[2]!='3'&&  cells[3]!='4'&&
           cells[4]!='5'&&  cells[5]!='6'&& cells[6]!='7'&&  cells[7]!='8'&&
           cells[8]!='9')
        {
            return false;
        }
        else
            return true;
    }
};
