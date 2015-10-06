//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        GameCore.h                                //
//             ████████████         Peg Solitaire Core                        //
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

#ifndef __PegSolitaireCore_include_GameCore_h__
#define __PegSolitaireCore_include_GameCore_h__

//std
#include <string>
//PegSolitaireCore
#include "PegSolitaireCore_Utils.h"
#include "PegSolitaireCore_Types.h"
#include "ILevelLoader.h"

NS_PEGCORE_BEGIN

class GameCore
{
    // CTOR/DTOR //
public:
    ///@brief Constructs a PegSolitaire Game Core with the 
    ///board loaded by the LevelLoader.
    ///@param loader A reference of a Board loader.
    ///@see ILevelLoader.
    GameCore(const ILevelLoader &loader);


    // Public Methods //
public:
    ///@brief Make a move, checking first if all the coords are valid,
    ///if them are of the correct types and if them represents a valid 
    ///movement. If a valid movement is represented it will update the
    ///game status and the affected coords and pegs.
    ///After each call of makeMove the user should call the getStatus
    ///method to check if game is over.
    ///@param sourceCoord Any coord, but if it isn't representing a peg 
    ///(PegType::Peg) movement won't be valid.
    ///@param targetCoord Any coord, but if it isn't representing a hole
    ///(PegType::Hole) and if isn't in a range of valid movements 
    ///of the sourceCoord the movement won't be valid.
    ///@returns true if the movement was performed, false otherwise.
    ///@see Coord, PegType, Status, getStatus, getMovesForPeg, isValidMove.
    bool makeMove(const Coord &sourceCoord, const Coord &targetCoord);

    
    ///@brief Gets the current board representation.
    ///@returns The current board representation.
    const Board& getBoard() const;

    ///@brief Get the type of the Peg at Coord. 
    ///If coord isn't valid returns Peg::Invalid.
    ///@param Coord the coord of queried peg.
    ///@returns The type of peg. 
    ///@see PegType, Coord.
    PegType getPegAt(const Coord &coord) const;


    ///@brief Gets the current status of the game.
    ///Should be called each time that makeMove is called.
    ///@returns The current status of game.
    ///@see Status, makeMove.
    Status getStatus() const;

    ///@brief Gets how many Pegs (PegType::Peg) is remaining.
    ///@returns The pegs count.
    int getPegsCount() const;

    ///@brief Gets how many moves player had performed. 
    ///@returns How many moves player did.
    int getMovesCount() const;


    ///@brief Gets all the target coords that this peg
    ///can be placed. This is useful if you want to 
    ///highlight the possible destination of this peg.
    ///If the coord doesn't represents a PegType::Peg
    ///an empty vector will be returned.
    ///@param The coord of Peg that will be queried.
    ///@returns All target coords that the peg at coord
    ///can be placed, or an empty vector if coord doesn't 
    ///represents a peg (PegType::Peg).
    ///@see PegType, isValidCoord, makeMove
    CoordVec getMovesForPeg(const Coord &coord) const;

    ///@brief Get all coords thats represents a Peg (PegType::Peg).
    ///@returns A coords vector with all Pegs coords.
    ///@see PegType
    const CoordVec& getPegCoords() const;

    ///@brief Get all coords thats represents a Hole (PegType::Hole).
    ///@returns A coords vector with all Hole coords.
    ///@see PegType
    const CoordVec& getHoleCoords() const;

    ///@brief Get all coords thats represents a Blocked (PegType::Blocked).
    ///@returns A coords vector with all Blocked coords.
    ///@see PegType
    const CoordVec& getBlockedCoords() const;


    ///@brief Check if a coord is valid i.e. is inside of Board bounds.
    ///@param coord A Coord that will be queried.
    ///@returns True if coord is inside of Board bounds, false otherwise.
    ///@see Coord, Board.
    bool isValidCoord(const Coord &coord) const;

    ///@brief Check if the two coords can represent a valid move.
    ///@param sourceCoord Any coord, but if it isn't valid or isn't representing
    ///a Peg (PegType::Peg) the movement is not valid.
    ///@param targetCoord Any coord, but if it isn't valid or isn't representing
    ///a Hole (PegType::Hole) the movement is not valid. Furthermore the 
    ///targetCoord must be in range of the sourceCoord.
    ///@returns True is is valid movement, false otherwise.
    ///@see Coord, PegType, getMovesForPeg, isValidCoord.
    bool isValidMove(const Coord &sourceCoord, const Coord &targetCoord) const;


    ///@brief Turn the current board into a string representation.
    ///@returns The string representation of the board.
    std::string ascii() const;


    // Private Methods //
private:
    void setPegAt(const Coord &coord, PegType type);
    void checkStatus();

    // iVars //
private:
    Status m_status;
    int    m_movesCount;

    Board  m_board;

    CoordVec m_pegCoords;
    CoordVec m_holeCoords;
    CoordVec m_blockedCoords;
};

NS_PEGCORE_END
#endif // defined(__PegSolitaireCore_include_GameCore_h__) //
