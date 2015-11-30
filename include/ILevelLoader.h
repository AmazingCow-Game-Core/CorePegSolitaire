//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        ILevelLoader.h                            //
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

#ifndef __PegSolitaireCore_include_ILevelLoader_h__
#define __PegSolitaireCore_include_ILevelLoader_h__

//CorePegSolitaire
#include "CorePegSolitaire_Utils.h"
#include "CorePegSolitaire_Types.h"

NS_PEGCORE_BEGIN

class ILevelLoader
{
    // CTOR/DTOR //
public:
    ///@brief CTOR for ILevelLoader.
    ILevelLoader() { /* Empty */ }

    ///@brief Virtual DTOR for ILevelLoader.
    virtual ~ILevelLoader() { /* Empty */ }


    // Public Methods //
public:
    ///@brief All subclasses must override this and return 
    ///the complete board representation.
    ///@returns The board loaded.
    ///@see Board.
    virtual const Board& getBoard() const = 0;
    
    ///@brief All subclasses must override this and return 
    ///how many pegs the board has.
    ///@returns How many pegs the board loaded has.
    virtual int getPegsCount() const = 0;

    
    ///@brief All subclasses must override this and return 
    ///all coords that represents a Peg (PegType::Peg).
    ///@returns The coords vector with all coords that are Pegs.
    ///@see Coord, CoordVec, PegType.
    virtual const CoordVec& getPegCoords() const = 0;

    ///@brief All subclasses must override this and return 
    ///all coords that represents a Hole (PegType::Hole).
    ///@returns The coords vector with all coords that are Holes.
    ///@see Coord, CoordVec, PegType.
    virtual const CoordVec& getHoleCoords() const = 0;

    ///@brief All subclasses must override this and return 
    ///all coords that represents a Blocked (PegType::Blocked).
    ///@returns The coords vector with all coords that are Blocked.
    ///@see Coord, CoordVec, PegType.
    virtual const CoordVec& getBlockedCoords() const = 0;    
};

NS_COREPEG_END
#endif // defined(__PegSolitaireCore_include_ILevelLoader_h__) //
