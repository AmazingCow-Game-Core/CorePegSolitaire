
#include <iostream>
#include <cstdlib>
#include "../include/PegSolitaireCore.h"

using namespace std;
USING_NS_PEGCORE;

void setCursorXY(int x, int y)
{
//    char buffer[512];
//    sprintf(buffer, "tput cup %d %d", x, y);
//    system(buffer);
}
void clearScreen()
{
//    system("tput clear");
}

void play(int type)
{
    FileLevelLoader loader("english.txt");
    GameCore core(loader);

    while(true)
    {
        //Clear the screen and print the board info.
        clearScreen();
        
        cout << core.ascii() << endl;
        cout << "Pegs Count  : " << core.getPegsCount()  << endl;
        cout << "Moves Count : " << core.getMovesCount() << endl;
        cout << "Status      : " << core.getStatus()     << endl;
        

        //Prompt player to enter the coords.
        cout << "Type the two coords - To quit type -1 -1" << endl;
        
        //Coord1.
        cout << "Coord 1 (y) (x): ";
        
        Coord coord1(0, 0);
        cin >> coord1.y >> coord1.x;
        
        //Check if player wants to quit.
        if(coord1.x == -1 && coord1.y == -1) return;
        
        //Coord2.
        cout << "Coord 2 (y) (x): ";
        
        Coord coord2(0, 2);
        cin >> coord2.y >> coord2.x;

        //Check if coord is valid.
        cout << "Coord1 is Valid: " << core.isValidCoord(coord1) << endl; 
        cout << "Coord2 is Valid: " << core.isValidCoord(coord2) << endl; 

        //Check if them make a valid move.
        cout << "Is a valid move: " << core.isValidMove(coord1, coord2) << endl;
        
        //Make the move.
        core.makeMove(coord1, coord2);
    }
}
void presentByeBye()
{
    clearScreen();
    cout << "Bye bye..." << endl;
}

void presentMenu()
{
    while(true)
    {
        clearScreen();
        setCursorXY(0, 0);
        
        cout << "AmazingCow - PegSolitaireCore - Test Game"     << endl;
        cout << "Version 0.1 - www.AmazingCow.com"              << endl;
        cout << "Developed by N2OMatt - n2omatt@amazingcow.com" << endl;

        cout << endl; 

        cout << "Games: "            << endl;
        cout << " 1 - English Pegs"  << endl;
        cout << " 2 - American Pegs" << endl;
        cout << " 3 - French Pegs"   << endl;
        cout << " q - Quit"          << endl; 

        cout << endl;

        cout << "Select: ";
        
        std::string selection;
        cin >> selection;

        if(selection == "q") 
        {
            presentByeBye();
            return;
        }        
        else if(selection == "1") play(1);
        else if(selection == "2") play(2);
        else if(selection == "3") play(3);
        else
        {
            cout << "Invalid information" << endl;
            std::string a;
            cin >> a;
        }
    }//while(true)
}

int main()
{
//    presentMenu();
    play(1);
}
