
#include <iostream>
#include <cstdlib>
#include "../include/PegSolitaireCore.h"

using namespace std;
USING_NS_PEGCORE;

#define ASSERT(cond) do { \
    if(!cond) {           \
        cout << "Assert - " #cond << endl; \
        abort();                            \
    }                                       \
} while(0);

#define CHECK(input, expected) do { \
    if(input != expected) { \
        cout << "Expected: " << expected << endl \
             << "Have    : " << input << endl;   \
        abort(); \
    } \
} while(0);

enum class Direction { Left, Right, Up, Down };

Coord createMove(const Coord &first,  Direction d)
{
    Coord second;
    
    if     (d == Direction::Left ) second = first.getLeft (2);
    else if(d == Direction::Right) second = first.getRight(2);
    else if(d == Direction::Up   ) second = first.getUp   (2);
    else if(d == Direction::Down ) second = first.getDown (2);
    
    return second;
}

std::pair<Coord, Coord> createMovePair(const Coord &first, Direction d)
{
    return make_pair(first, createMove(first, d));
}



void test_WinEnglishPegs()
{
    FileLevelLoader loader("english.txt");
    GameCore core(loader);
    
    std::vector<std::pair<Coord, Coord>> moves;
    
    //Moves 1 and 2 : The First T
    moves.push_back(createMovePair(Coord(3, 1), Direction::Right)); //1
    moves.push_back(createMovePair(Coord(5, 2), Direction::Up));    //2
    //Moves 3 and 4 : The First Back and Forth
    moves.push_back(createMovePair(Coord(4, 0), Direction::Right)); //3
    moves.push_back(createMovePair(Coord(4, 3), Direction::Left )); //4
    //Moves 5 and 6 : The Second T (Reverse)
    moves.push_back(createMovePair(Coord(4, 5), Direction::Left)); //5
    moves.push_back(createMovePair(Coord(6, 4), Direction::Up  )); //6
    //Moves 7 and 8: Set-up For A Double Jump
    moves.push_back(createMovePair(Coord(3, 4), Direction::Down )); //7
    moves.push_back(createMovePair(Coord(6, 2), Direction::Right)); //8.1
    moves.push_back(createMovePair(Coord(6, 4), Direction::Up   )); //8.2
    //Moves 9 and 10 : The Waterfall Setup
    moves.push_back(createMovePair(Coord(2, 2), Direction::Down)); //9
    moves.push_back(createMovePair(Coord(0, 2), Direction::Down)); //10
    //Moves 11 and 12 : The Backwards U and The Lazy L
    moves.push_back(createMovePair(Coord(1, 4), Direction::Down)); //11.1
    moves.push_back(createMovePair(Coord(3, 4), Direction::Down)); //11.2
    moves.push_back(createMovePair(Coord(5, 4), Direction::Left)); //11.3
    moves.push_back(createMovePair(Coord(5, 2), Direction::Up  )); //11.4
    moves.push_back(createMovePair(Coord(3, 2), Direction::Up  )); //11.5
    
    moves.push_back(createMovePair(Coord(2, 0), Direction::Down )); //12.1
    moves.push_back(createMovePair(Coord(4, 0), Direction::Right)); //12.2
    moves.push_back(createMovePair(Coord(4, 2), Direction::Right)); //12.3
    
    //Moves 13 and 14 : The Second Back and Forth (Reverse)
    moves.push_back(createMovePair(Coord(2, 6), Direction::Left )); //13
    moves.push_back(createMovePair(Coord(2, 3), Direction::Right)); //13
    
    //Moves 15 and 16 : The Two Double Jump Setups
    moves.push_back(createMovePair(Coord(4, 6), Direction::Up  )); //15.1
    moves.push_back(createMovePair(Coord(2, 6), Direction::Left)); //15.2
    
    moves.push_back(createMovePair(Coord(0, 4), Direction::Left)); //16.1
    moves.push_back(createMovePair(Coord(0, 2), Direction::Down)); //16.2
    
    //Moves 17 and 18 : There's No Place Like Home
    moves.push_back(createMovePair(Coord(2, 1), Direction::Right)); //17.1
    moves.push_back(createMovePair(Coord(2, 3), Direction::Right)); //17.2
    moves.push_back(createMovePair(Coord(2, 5), Direction::Down )); //17.3
    moves.push_back(createMovePair(Coord(4, 5), Direction::Left )); //17.4
    moves.push_back(createMovePair(Coord(4, 3), Direction::Up   )); //17.5
    
    moves.push_back(createMovePair(Coord(1, 3), Direction::Down   )); //18
    
    int initialPegsCount = core.getPegsCount();
    for(auto move : moves)
    {
        //Print the Board...
        cout << core.ascii() << endl;
        
        //Print the Game Info and check.
        cout << "Pegs Count  : " << core.getPegsCount() << endl;
        CHECK(core.getPegsCount(), initialPegsCount - core.getMovesCount());
        
        cout << "Moves Count : " << core.getMovesCount() << endl;
        CHECK(core.getMovesCount(), initialPegsCount - core.getPegsCount());
        
        cout << "Status      : " << core.getStatus() << endl;
        CHECK(core.getStatus(), Status::Continue);
        
        //Print the Coord1 info and check.
        cout << "Coord1 "     << move.first
             << " is Valid: " << core.isValidCoord(move.first)
             << endl;
        CHECK(core.isValidCoord(move.first), true);

        //Print the Coord2 info and check.
        cout << "Coord2 "     << move.second
             << " is Valid: " << core.isValidCoord(move.second)
            << endl;
        CHECK(core.isValidCoord(move.first), true);
        
        //Print if Move is valid and check.
        cout << "Is a valid move: "
             << core.isValidMove(move.first, move.second)
             << endl;
        CHECK(core.isValidMove(move.first, move.second), true);
        
        
        core.makeMove(move.first, move.second);
    }
    
}
void play(int type)
{
    FileLevelLoader loader("english.txt");
    GameCore core(loader);
    
    while(true)
    {
        cout << core.ascii() << endl;

        Coord coord1(3, 2);
        Coord coord2 = createMove(coord1, Direction::Right);
        
        //Check if coord is valid.


        //Check if them make a valid move.
        cout << "Is a valid move: " << core.isValidMove(coord1, coord2) << endl;
        
        //Make the move.
        core.makeMove(coord1, coord2);
    }
}

int main()
{
//    presentMenu();
    test_WinEnglishPegs();
}
