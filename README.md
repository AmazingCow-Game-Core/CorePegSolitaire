Core Peg Solitaire
====
Made with <3 by [Amazing Cow](http://www.amazingcow.com).

## Intro:
This is a Game Core for Peg Solitaire Game.   
You can use it as a "lib" for making Peg Solitaire Game in C++ concentrating 
your efforts in making a cool game interface and letting the logic of the 
game alone.

This is not a complete implementation, but instead is very naive one. 
The core doesn't support triangular boards and so on, but with the regular
ones it is very cool.

## Files:
We tried to separated the files in a very organized form.   
Here is a list of them and it's intend.

```PegSolitaireCore.h``` : The main header, is a umbrella header that includes all other stuff that is needed to use this Core.   
While is possible to include each file separately, we find that is easier to just include this file.

```PegSolitaireCore_Utils.h``` : This file will define some utilities used across the other files of this Core.   
Now it just define a namespace macro that is used for this Core. (We learned this from cocos2d-x and liked a lot)

```PegSolitaireCore_Types.h``` : This define some constants, enum, typedef and types that this Core uses.   
All types that is used in more than one place is, or defined here, or included here.   
So all Core can include this file and serve itself from all types.

```ILevelLoader.h``` : A pure virtual class that defines a API to load the board that will used in GameCore.

```FileLevelLoader.h``` : A concrete subclass of ILevelLoader that let us load a game board from a disk file.

```GameCore.h``` : The game itself. 

## More info:
We tried to document the Core extensively, so we think that is pretty ease to get what the Core is doing,
the API calls and stuff.   
Anyway if you didn't understand something let us know sending a mail to ***help_opensource@amazingcow.com*** 
with the subject filled with the name of this repo.


## License:
This software is released under GPLv3.

## TODO:
Check the TODO file.

## Others:
Check our repos and take a look at our [open source site](http://opensource.amazingcow.com).
