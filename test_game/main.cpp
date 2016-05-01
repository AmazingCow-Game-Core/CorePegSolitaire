//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        main.cpp                                  //
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

//This guard is to ease the usage of the CorePegSolitaire,
//so it's users won't need to worry about removing any files
//since is very unlikely that this flag is defined elsewhere.
#ifdef __AMAZINGCORE_COREPEGSOLITAIRE_TEST_ENABLED__

#include <iostream>
#include <vector>
#include <cstdlib>

#include "../include/CorePegSolitaire.h"
#include "CoreCoord.h"


USING_NS_COREPEG;
using namespace std;


void usage()
{
    cout << "Amazing Cow - CorePegSolitaire Test Game" << endl;
    cout << "Usage:" << endl;
    cout << "  <binary-name> <path-for-board>" << endl;
    cout << "Ex: ./testgame english.txt" << endl;

    exit(1);
}

int main(int argc, const char *argv[])
{
    if(argc != 2)
        usage();

    FileLevelLoader loader(argv[1]);
    GameCore core(loader);

    while(core.getStatus() == Status::Continue)
    {
        //Display board info.
        cout << core.ascii() << endl;
        cout << "Status     : " << core.getStatus    () << endl;
        cout << "PegsCount  : " << core.getPegsCount () << endl;
        cout << "MovesCount : " << core.getMovesCount() << endl;

        CoreCoord::Coord source;
        CoreCoord::Coord target(-1, -1);

        cout << "Source coord : ";
        cin >> source.y >> source.x;

        char c;
        cout << "Move type [u]p [d]down [l]eft [r]ight : ";
        cin >> c;

        if(c == 'u') target = source.getUp   (2);
        if(c == 'd') target = source.getDown (2);
        if(c == 'l') target = source.getLeft (2);
        if(c == 'r') target = source.getRight(2);

        if(target.x == -1 && target.y == -1)
        {
            cout << "invalid move!" << endl;
            continue;
        }

        core.makeMove(source, target);
    }

}

#endif // __AMAZINGCORE_COREPEGSOLITAIRE_TEST_ENABLED__ //
