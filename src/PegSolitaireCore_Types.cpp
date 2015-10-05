//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        PegSolitaireCore_Types.cpp                //
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

//Header
#include "../include/PegSolitaireCore_Types.h"

//Usings
USING_NS_PEGCORE;

// Enums //
std::ostream& PegCore::operator <<(std::ostream &os, Status status)
{
    os << ((status == Status::Continue) ? "Status::Continue" :
           (status == Status::Defeat  ) ? "Status::Defeat"   :
                                          "Status::Victory");

    return os;
}
std::ostream& PegCore::operator <<(std::ostream &os, PegType type)
{
    os << ((type == PegType::Peg    ) ? "PegType::Peg"     :
           (type == PegType::Hole   ) ? "PegType::Hole"    :
           (type == PegType::Blocked) ? "PegType::Blocked" :
                                        "PegType::Invalid");
    return os;
}


// Classes //

// Friends //
bool PegCore::operator ==(const Coord &lhs, const Coord rhs)
{
    return (lhs.y == rhs.y) && (lhs.x == rhs.x);
}
bool PegCore::operator !=(const Coord &lhs, const Coord rhs)
{
    return !(lhs == rhs);
}

// CTOR/DTOR //
Coord::Coord(int _y /* = 0 */, int _x /* = 0 */) :
    y(_y),
    x(_x)
{
    //Empty...
}

// Static Methods //
Coord Coord::getUp(int offset) const
{
    return Coord(this->y - offset, this->x);
}
Coord Coord::getDown(int offset) const
{
    return Coord(this->y + offset, this->x);
}
Coord Coord::getLeft(int offset) const
{
    return Coord(this->y, this->x - offset);
}
Coord Coord::getRight(int offset) const
{
    return Coord(this->y, this->x + offset);
}

Coord Coord::getMiddleCoord(const Coord &otherCoord) const
{
    return Coord((this->y + otherCoord.y) / 2,
                 (this->x + otherCoord.x) / 2);
}
