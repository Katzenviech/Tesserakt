# Tesserakt

Build Status: ![Build Status](https://github.com/Katzenviech/Tesserakt/workflows/build/badge.svg)
  

  
## prerequisite to compile with MinGW64 on Windows
Download MinGW64 e.g. from https://github.com/brechtsanders/winlibs_mingw or https://winlibs.com/ and extract e.g. to C:\MINGW64

Add MINGW64\bin to System-PATH variable (log out or restart your computer)

Test in cmd-window with g++ --version

Download SDL2-devel-2.0.20-mingw.tar.gz (or newer) from https://www.libsdl.org/download-2.0.php

Extract to a directory (e.g. using 7zip)
Copy files for 64bit version from e.g. C:\SDL2\SDL2-2.0.20\x86_64-w64-mingw32 to e.g. C:\SDL2\  (do not use spaces in the directory name)

Set system environment variable called SDL2_PATH to where you copied the SDL2 devel files
e.g. C:/SDL2 (there should be a lib, include and bin folder in this directory) - use a **forward** slash!!


## build using CMake
inside cloned folder with CMakeLists.txt:

On Linux:
```
    cmake -Bbuild -S.
```

On Windows:
```
    cmake -G"MinGW Makefiles" -Bbuild -S.
```

then
```
    cmake --build build
```

## run
On windows copy over SDL2.dll to your Tesserakt.exe from %SDL2_PATH%/bin or add this directory to your System PATH


## gameplay  
WASD - move  
ARROW - shoot  
Run Away!  

![tesserakt-gif](https://github.com/Katzenviech/Tesserakt/blob/main/Tesserakt.gif)

----
inspired by:
Tesserakt in Java https://www.youtube.com/watch?v=c3EZUMRyMkY

----
Rubric points addressed for the Udacity Capstone Project (Base: Snake-Game with SDL2)  

* A README with instructions is included with the project: See above
* The README indicates which project is chosen: Snake-Game based on SDL2, but rewritten to be a different game play: Tesserakt  

* The submission must compile and run: Builds on Linux, see badge above. Project compiled for each push to Github using Github Actions
  
* The project demonstrates an understanding of C++ functions and control structures: member-functions and encapsulation used  
* The project accepts user input and processes the input: Keys WASD to run around, Arrow-Keys to shoot in direction, ESC-Key to quit game  

* The project uses Object Oriented Programming techniques: Class: Asset (parent), Bullet,Enemy,Player (child-classes). MVC as Game, Renderer, Controller
* Classes use appropriate access specifiers for class members: private and public choosen as required (encapsulation)
* Class constructors utilize member initialization lists: Yes
* Classes abstract implementation details from their interfaces: Yes, some methods also private
* Classes encapsulate behavior: Yes
* Classes follow an appropriate inheritance hierarchy: Asset-base-class (Object in Game). Inherited: Bullet, Player, Enemy-Class
* Overloaded functions allow the same function to operate on different parameters: Yes, e.g. the color of the assets  

* The project uses destructors appropriately: virtual destructors used, Renderer-destructor cleans up SDL with SDL_destroy and quit 
* The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate: RAII used, SDL2 takes care of pointers internally
* The project uses smart pointers instead of raw pointers: No, SDL2 written in C, takes care of the pointers used internally

* Concurrency: Basic game loop Input - Update - Render. Threading used by SDL2 and call to SDL_Delay()  


