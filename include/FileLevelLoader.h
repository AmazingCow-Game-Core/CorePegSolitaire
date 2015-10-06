//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        FileLevelLoader.h                         //
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

#ifndef __PegSolitaireCore_include_FileLevelLoader_h__
#define __PegSolitaireCore_include_FileLevelLoader_h__

//std
#include <string>
//PegSolitaireCore
#include "PegSolitaireCore_Utils.h"
#include "PegSolitaireCore_Types.h"
#include "ILevelLoader.h"

NS_PEGCORE_BEGIN

class FileLevelLoader : public ILevelLoader
{
    // Contants/Enums/Typedefs //
public:
    static const char kCharPeg;
    static const char kCharHole;
    static const char kCharBlocked;    

    // CTOR/DTOR //
public:
    ///@brief Loads a board from a disk file.
    ///Using the FileLevelLoader::kCharPeg,
    ///FileLevelLoader::kCharHole and 
    ///FileLevelLoader::kCharPeg as the chars that
    ///represents the Board elements.
    ///@param filename The fullpath of the Board file.
    FileLevelLoader(const std::string &filename);

    ///@brief A virtual Destructor.
    virtual ~FileLevelLoader();


    // Overriden Methods //
public:
    ///@brief Gets the Board from loaded file.
    //@returns The loaded Board.
    //@see Board.
    const Board& getBoard() const override;
    

    ///@brief Gets how many Pegs (PegType::Peg) this board has.
    ///@returns The pegs count.
    ///@see PegType.
    int getPegsCount() const override;
    

    ///@brief Get all the coords that has a Peg (PegType::Peg) in this board.
    ///@returns A Coord vector with all coords that are Pegs.
    ///@see Coord.
    ///@see CoordVec.
    ///@see PegType.
    const CoordVec& getPegCoords() const override;

    ///@brief Get all the coords that has a Hole (PegType::Hole) in this board.
    ///@returns A Coord vector with all coords that are Holes.
    ///@see Coord.
    ///@see CoordVec.
    ///@see PegType.
    const CoordVec& getHoleCoords() const override;

    ///@brief Get all the coords that is blocked (PegType::Blocked) in this board.
    ///@returns A Coord vector with all coords that are blocked.
    ///@see Coord.
    ///@see CoordVec.
    ///@see PegType.
    const CoordVec& getBlockedCoords() const override;

    // iVars //
private:
    std::string m_filename;
    
    Board    m_board;    
    CoordVec m_pegCoords;
    CoordVec m_holeCoords;
    CoordVec m_blockedCoords;
};

NS_PEGCORE_END
#endif // defined(__PegSolitaireCore_include_FileLevelLoader_h__) //
