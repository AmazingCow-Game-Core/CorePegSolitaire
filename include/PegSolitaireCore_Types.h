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
enum class Status 
{
    Victory,
    Defeat,
    Continue
};
std::ostream& operator <<(std::ostream &os, Status status);

enum class PegType
{
    Peg,
    Hole,
    Blocked,
    Invalid
};
std::ostream& operator <<(std::ostream &os, PegType type);


// Classes //
class Coord
{
    // Friends //
public:
    friend bool operator ==(const Coord &lhs, const Coord rhs);
    friend bool operator !=(const Coord &lhs, const Coord rhs);
    
    // CTOR/DTOR //
public:
    Coord(int y = 0, int x = 0);

    // Public Methods //
public:
    Coord getUp(int offset) const;
    Coord getDown(int offset) const;
    Coord getLeft(int offset) const;
    Coord getRight(int offset) const;
    
    Coord getMiddleCoord(const Coord &otherCoord) const;
    
    // iVars //
public:
    int x, y;
};


// Typedefs //
typedef std::vector<Coord>                CoordVec;
typedef std::vector<std::vector<PegType>> Board;


NS_PEGCORE_END
#endif // defined(__PegSolitaireCore_include_PegSolitaireCore_Types_h__) //
