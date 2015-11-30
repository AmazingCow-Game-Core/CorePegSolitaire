//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        FileLevelLoader.cpp                       //
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

//Header
#include "../include/FileLevelLoader.h"

//std
#include <fstream>

//Usings
USING_NS_COREPEG;

// Constants/Enums/Typedefs //
const char FileLevelLoader::kCharPeg     = 'o';
const char FileLevelLoader::kCharHole    = '.';
const char FileLevelLoader::kCharBlocked = 'x';

// CTOR/DTOR //
FileLevelLoader::FileLevelLoader(const std::string &filename) :
    m_filename(filename)
{
    std::ifstream infile(m_filename.c_str());
    CoreCoord::Coord currCoord;

    for(std::string line; std::getline(infile, line); /*None*/ )
    {
        //Create a row of pegs...
        m_board.push_back(std::vector<PegType>());
        for(auto &ch : line)
        {
            //Peg.
            if(ch == FileLevelLoader::kCharPeg)
            {
                m_board[currCoord.y].push_back(PegType::Peg);
                m_pegCoords.push_back(currCoord);
            }
            //Hole.
            else if(ch == FileLevelLoader::kCharHole)
            {
                m_board[currCoord.y].push_back(PegType::Hole);
                m_holeCoords.push_back(currCoord);
            }
            //Blocked.
            else if(ch == FileLevelLoader::kCharBlocked)
            {
                m_board[currCoord.y].push_back(PegType::Blocked);
                m_blockedCoords.push_back(currCoord);
            }

            //Increment the X of current coord since we are
            //reading from left to right.
            ++currCoord.x;
        }

        //Increment the Y of current coord since we are reading
        //from top to bottom and reset the X to 0.
        ++currCoord.y;
        currCoord.x = 0;
    }
}

FileLevelLoader::~FileLevelLoader()
{
    //Empty...
}

// Overriden Methods //
const Board& FileLevelLoader::getBoard() const
{
    return m_board;
}

int FileLevelLoader::getPegsCount() const
{
    return static_cast<int>(m_pegCoords.size());
}

const CoreCoord::Coord::Vec& FileLevelLoader::getPegCoords() const
{
    return m_pegCoords;
}
const CoreCoord::Coord::Vec& FileLevelLoader::getHoleCoords() const
{
    return m_holeCoords;
}
const CoreCoord::Coord::Vec& FileLevelLoader::getBlockedCoords() const
{
    return m_blockedCoords;
}
