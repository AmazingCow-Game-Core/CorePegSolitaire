//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        FileLevelLoader.h                         //
//            █ █        █ █        CorePegSolitaire                          //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
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
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __CorePegSolitaire_include_FileLevelLoader_h__
#define __CorePegSolitaire_include_FileLevelLoader_h__

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
    ///@brief The char that represents the PegType::Peg.
    ///@note To this class loads the board correctly the file MUST
    ///      represents the peg with this char.
    ///@see PegType.
    static const char kCharPeg;
    ///@brief The char that represents the PegType::Hole.
    ///@note To this class loads the board correctly the file MUST
    ///      represents the hole with this char.
    ///@see PegType.
    static const char kCharHole;
    ///@brief The char that represents the PegType::Blocked.
    ///@note To this class loads the board correctly the file MUST
    ///      represents the hole with this char.
    ///@see PegType.
    static const char kCharBlocked;


    // CTOR/DTOR //
public:
    ///@brief Loads the Board from file located in filename.
    ///@param
    ///     filename The fullpath of the Board file.
    ///@throws
    ///     std::system_error exception if it cannot open a
    ///     file with the given filename.
    ///@see
    ///     kCharPeg, kCharHole, kCharBlocked, PegType.
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
    ///@see CoreCoord::Coord, CoreCoord::Coord::Vec, PegType.
    const CoreCoord::Coord::Vec& getPegCoords() const override;

    ///@brief Get all the coords that has a Hole (PegType::Hole) in this board.
    ///@returns A CoreCoord::Coord vector with all coords that are Holes.
    ///@see CoreCoord::Coord, CoreCoord::Coord::Vec, PegType.
    const CoreCoord::Coord::Vec& getHoleCoords() const override;

    ///@brief Get all the coords that is blocked (PegType::Blocked) in this board.
    ///@returns A CoreCoord::Coord vector with all coords that are blocked.
    ///@see CoreCoord::Coord, CoreCoord::Coord::Vec, PegType.
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
#endif // defined(__CorePegSolitaire_include_FileLevelLoader_h__) //
