//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        FileLevelLoader.h                         //
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

#ifndef __PegSolitaireCore_include_FileLevelLoader_h__
#define __PegSolitaireCore_include_FileLevelLoader_h__

//std
#include <string>
//CorePegSolitaire
#include "CorePegSolitaire_Utils.h"
#include "CorePegSolitaire_Types.h"
#include "ILevelLoader.h"
//CoreCoord
#include "CoreCoord.h"


NS_COREPEG_BEGIN

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
    ///@returns A CoreCoord::Coord vector with all coords that are Pegs.
    ///@see CoreCoord::Coord.
    ///@see CoreCoord::Coord::Vec.
    ///@see PegType.
    const CoreCoord::Coord::Vec& getPegCoords() const override;

    ///@brief Get all the coords that has a Hole (PegType::Hole) in this board.
    ///@returns A CoreCoord::Coord vector with all coords that are Holes.
    ///@see CoreCoord::Coord.
    ///@see CoreCoord::Coord::Vec.
    ///@see PegType.
    const CoreCoord::Coord::Vec& getHoleCoords() const override;

    ///@brief Get all the coords that is blocked (PegType::Blocked) in this board.
    ///@returns A CoreCoord::Coord vector with all coords that are blocked.
    ///@see CoreCoord::Coord.
    ///@see CoreCoord::Coord::Vec.
    ///@see PegType.
    const CoreCoord::Coord::Vec& getBlockedCoords() const override;

    // iVars //
private:
    std::string m_filename;
    
    Board m_board;

    CoreCoord::Coord::Vec m_pegCoords;
    CoreCoord::Coord::Vec m_holeCoords;
    CoreCoord::Coord::Vec m_blockedCoords;
};

NS_COREPEG_END
#endif // defined(__PegSolitaireCore_include_FileLevelLoader_h__) //
