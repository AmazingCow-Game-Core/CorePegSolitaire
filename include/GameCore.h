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
    GameCore(const ILevelLoader &loader);
    ~GameCore();

    // Public Methods //
public:
    bool makeMove(const Coord &sourceCoord, const Coord &targetCoord);

    const Board& getBoard() const;
    PegType getPegAt(const Coord &coord) const;

    Status getStatus() const;
    int getPegsCount() const;
    int getMovesCount() const;

    CoordVec getMovesForPeg(const Coord &coord) const;
    const CoordVec& getPegCoords() const;
    const CoordVec& getHoleCoords() const;
    const CoordVec& getBlockedCoords() const;

    bool isValidCoord(const Coord &coord) const;
    bool isValidMove(const Coord &sourceCoord, const Coord &targetCoord) const;

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
