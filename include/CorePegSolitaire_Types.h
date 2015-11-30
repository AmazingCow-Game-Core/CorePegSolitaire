//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        CorePegSolitaire_Types.h                  //
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

#ifndef __PegSolitaireCore_include_PegSolitaireCore_Types_h__
#define __PegSolitaireCore_include_PegSolitaireCore_Types_h__

//std
#include <vector>
#include <ostream>
//CorePegSolitaire
#include "CorePegSolitaire_Utils.h"

NS_COREPEG_BEGIN

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

///@brief Typedef to ease the typing of "a matrix of PegTypes".
///@see PegType
typedef std::vector<std::vector<PegType>> Board;


NS_COREPEG_END
#endif // defined(__PegSolitaireCore_include_PegSolitaireCore_Types_h__) //
