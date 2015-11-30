//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        GameCore.cpp                              //
//             ████████████         CorePegSolitaire                          //
//           █              █       Copyright (c) 2015 AmazingCow             //
//          █     █    █     █      www.AmazingCow.com                        //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgmentopensource@AmazingCow.com               //
//     3. Altered source versions must be plainly marked as such,             //
//        and must notbe misrepresented as being the original software.       //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

//Header
#include "../include/GameCore.h"

//std
#include <sstream>

//Usings
USING_NS_COREPEG;

// CTOR/DTOR //
GameCore::GameCore(const ILevelLoader &loader) :
    m_movesCount   (0),
    m_status       (Status::Continue),
    m_board        (loader.getBoard        ()),
    m_pegCoords    (loader.getPegCoords    ()),
    m_holeCoords   (loader.getHoleCoords   ()),
    m_blockedCoords(loader.getBlockedCoords())
{

}


// Public Methods //
bool GameCore::makeMove(const Coord &sourceCoord, const Coord &targetCoord)
{
    //Users of this class is who should call this, but any way...
    if(!isValidMove(sourceCoord, targetCoord))
        return false;

    //Set the pegs on board.
    auto middleCoord = sourceCoord.getMiddleCoord(targetCoord);
    setPegAt(sourceCoord, PegType::Hole);
    setPegAt(middleCoord, PegType::Hole);
    setPegAt(targetCoord, PegType::Peg);

    //Update the coords vectors.
    //First update the Pegs Coords Vector.
    m_pegCoords.erase(std::find(begin(m_pegCoords), end(m_pegCoords), sourceCoord));
    m_pegCoords.erase(std::find(begin(m_pegCoords), end(m_pegCoords), middleCoord));
    m_pegCoords.push_back(targetCoord);
    //Next update the Holes Coords Vector.
    m_holeCoords.erase(std::find(begin(m_holeCoords), end(m_holeCoords), targetCoord));
    m_holeCoords.push_back(sourceCoord);
    m_holeCoords.push_back(middleCoord);

    //Increment the moves.
    ++m_movesCount;

    checkStatus();

    return true;
}

const Board& GameCore::getBoard() const
{
    return m_board;
}
PegType GameCore::getPegAt(const Coord &coord) const
{
    if(!isValidCoord(coord))
        return PegType::Invalid;

    return m_board.at(coord.y).at(coord.x);
}

Status GameCore::getStatus() const
{
    return m_status;
}
int GameCore::getPegsCount() const
{
    return static_cast<int>(m_pegCoords.size());
}
int GameCore::getMovesCount() const
{
    return m_movesCount;
}

CoordVec GameCore::getMovesForPeg(const Coord &coord) const
{
    //Coord isn't valid there's no moves.
    if(!isValidCoord(coord))
        return CoordVec();

    //If coord isn't a peg there's no moves.
    if(getPegAt(coord) != PegType::Peg)
        return CoordVec();

    //Create the vector possible moves.
    auto possibleMoves = CoordVec();
    possibleMoves.reserve(4); //4 is the max moves for a peg.

    //Get the orthogonal coords.
    //THE NAME OF VARS ARE IMPORTANT TO USE THE MACRO BELLOW.
    //SO THE FIRST LETTER IN UPPERCASE IS NEEDED TO MATCH THE
    //Coord METHOD NAME.
    auto coordUp    = coord.getUp   (1);
    auto coordDown  = coord.getDown (1);
    auto coordLeft  = coord.getLeft (1);
    auto coordRight = coord.getRight(1);

    //This macro is a short hand for check if a move is valid or not based
    //on the Peg's coord. Since all logic is equal, only changing is the
    //method's name that will be called, I think that's a good use for a macro.
    //See (A Arte de Escrever Programs Legiveis - ISBN 978-85-7522-294-2)
    //Chapter 8, pag 105 for more :)
#define __CHECK_MOVE__(_dir_)                              \
    if(getPegAt(coord##_dir_) == PegType::Peg &&           \
    getPegAt(coord##_dir_.get##_dir_(1)) == PegType::Hole) \
{                                                          \
    possibleMoves.push_back(coord##_dir_.get##_dir_(1));   \
}

    __CHECK_MOVE__(Up);
    __CHECK_MOVE__(Down);
    __CHECK_MOVE__(Left);
    __CHECK_MOVE__(Right);

//We don't want it polluting...
#undef __CHECK_MOVE__

    return possibleMoves;
}
const CoordVec& GameCore::getPegCoords() const
{
    return m_pegCoords;
}
const CoordVec& GameCore::getHoleCoords() const
{
    return m_holeCoords;
}
const CoordVec& GameCore::getBlockedCoords() const
{
    return m_blockedCoords;
}

bool GameCore::isValidCoord(const Coord &coord) const
{
    //Here we set that a coord is valid if it's inside the
    //board bounds. This doesn't means that we can move it.
    return (coord.y >= 0 && coord.y < m_board.size())
        && (coord.x >= 0 && coord.x < m_board[coord.y].size());
}
bool GameCore::isValidMove(const Coord &sourceCoord,
                           const Coord &targetCoord) const
{
    //Game is over, move is not allowed anymore.
    if(getStatus() != Status::Continue)
        return false;

    //One (or both) of the coords isn't valid.
    if(!isValidCoord(sourceCoord) || !isValidCoord(targetCoord))
        return false;

    //Check if the first one is a Peg and
    //the second one is a hole.
    auto sourcePeg = getPegAt(sourceCoord);
    auto targetPeg = getPegAt(targetCoord);

    if(sourcePeg != PegType::Peg || targetPeg != PegType::Hole)
        return false;

    //Check if coord2 is on the possible moves for coord1.
    auto possibleMoves = getMovesForPeg(sourceCoord);
    auto it = std::find(begin(possibleMoves), end(possibleMoves), targetCoord);
    if(it == end(possibleMoves))
        return false;

    return true;
}

std::string GameCore::ascii() const
{
    std::stringstream ss;

    //Print the while board in a string.
    for(auto& line : m_board)
    {
        for(auto &peg : line)
        {
            ss << ((peg == PegType::Peg)  ? "o " :
                   (peg == PegType::Hole) ? ". " :
                                            "  ");
        }
        ss << std::endl;
    }

    return ss.str();
}


// Private Methods //
void GameCore::setPegAt(const Coord &coord, PegType type)
{
    m_board[coord.y][coord.x] = type;
}

void GameCore::checkStatus()
{
    //Left on peg alone. Game is won.
    if(getPegsCount() == 1)
    {
        m_status = Status::Victory;
        return;
    }

    //Check if there any movement for the remaining pegs.
    for(int i = 0; i < m_board.size(); ++i)
    {
        for(int j = 0; j < m_board[i].size(); ++j)
        {
            //We found a peg that can still move,
            //there's no need to keep the search.
            if(getMovesForPeg(Coord(i, j)).size() != 0)
            {
                m_status = Status::Continue;
                return;
            }
        }
    }

    //There's more than one peg, but any of them can move.
    m_status = Status::Defeat;
}

