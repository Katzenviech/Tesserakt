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
inside cloned source folder:
On Linux:
```
    cmake -Bbuild -S.
```

On Windows:
```
    cmake -G"MinGW Makefiles" -Bbulid -S.
```

then
```
    cmake --build build
```

## run
On windows copy over SDL2.dll to your Tesserakt.exe from %SDL2_PATH%/bin or add this directory to your System PATH