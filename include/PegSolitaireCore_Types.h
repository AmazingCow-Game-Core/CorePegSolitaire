//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        PegSolitaireCore_Types.h                  //
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

#ifndef __PegSolitaireCore_include_PegSolitaireCore_Types_h__
#define __PegSolitaireCore_include_PegSolitaireCore_Types_h__

//std
#include <vector>
#include <ostream>

//PegSolitaireCore
#include "PegSolitaireCore_Utils.h"

NS_PEGCORE_BEGIN

// Enums //

///@brief Defines the possible states of Game Core.
///@see GameCore.
enum class Status 
{
    Victory, ///< Game is over - Player won, i.e. has only one peg remaining.
    Defeat,  ///< Game is over - Player lose i.e. no valid moves, more than one peg.
    Continue ///< Game is not over - Keep playing...
};

///@brief Output the name of status. (ex: Status::Victory)
///@see Status.
std::ostream& operator <<(std::ostream &os, Status status);


///@brief Defines the possible types of Pegs in Peg Solitaire.
enum class PegType
{
    Peg,     ///< An actual peg.
    Hole,    ///< A place that peg can be placed 
    Blocked, ///< This is not a type per se, but used due our limitation
             ///of the board being in matrix form. So if we want a board
             ///in a "T" or "Cross" shape we must fill the gaps with this
             ///type. 
    Invalid  ///< This is not a type per se, but used to indicate that coord
             ///doesn't represents any other Peg Type in case of user pass
             ///a invalid coord to GameCore.
};

///@brief Output the name of PegType. (ex: PegType::Peg)
///@see Status.
std::ostream& operator <<(std::ostream &os, PegType type);



// Classes //
class Coord
{
    // Friends //
public:
    ///@brief Output a string representation in for of (y, x).
    friend std::ostream& operator <<(std::ostream &os, const Coord &coord);

    ///@brief Check if two coords have the same y and x.
    friend bool operator ==(const Coord &lhs, const Coord rhs);

    ///@brief Check if two coords have the different y and x.
    friend bool operator !=(const Coord &lhs, const Coord rhs);
    

    // CTOR/DTOR //
public:
    ///@brief Constructs a Coord.
    ///@param y The Y coordinate - Default is 0.
    ///@param x The X coordinate - Default is 0.
    Coord(int y = 0, int x = 0);


    // Public Methods //
public:
    ///@brief Gets a Coord that is top of this coord.
    ///@param offset How many times it will be on top.
    ///@returns A coord that have the y coordinate "offset" times less 
    ///than this coord.
    Coord getUp(int offset) const;

    ///@brief Gets a Coord that is bottom of this coord.
    ///@param offset How many times it will be on bottom.
    ///@returns A coord that have the y coordinate "offset" times more
    ///than this coord.
    Coord getDown(int offset) const;

    ///@brief Gets a Coord that is on left of this coord.
    ///@param offset How many times it will be on left.
    ///@returns A coord that have the x coordinate "offset" times less
    ///than this coord.
    Coord getLeft(int offset) const;

    ///@brief Gets a Coord that is on right of this coord.
    ///@param offset How many times it will be on right.
    ///@returns A coord that have the x coordinate "offset" times more
    ///than this coord.
    Coord getRight(int offset) const;
    
    ///@brief Gets the Coord that is on middle of two coord.
    ///@param otherCoord The second coord that will be calculated.
    ///@returns A coord that is on the middle of these coord.    
    Coord getMiddleCoord(const Coord &otherCoord) const;
    
    // iVars //
public:
    int x, y;
};


// Typedefs //
///@brief Typedef to ease the typing of "a vector of Coords".
///@see Coord
typedef std::vector<Coord> CoordVec;

///@brief Typedef to ease the typing of "a matrix of PegTypes".
///@see PegType
typedef std::vector<std::vector<PegType>> Board;


NS_PEGCORE_END
#endif // defined(__PegSolitaireCore_include_PegSolitaireCore_Types_h__) //
