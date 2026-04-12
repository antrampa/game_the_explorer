To build
> Open a terminal and run
> g++ main.cpp Animal.cpp Player.cpp

How to run
> Open a terminal and run

./theexplorer.out 



just run:

> make

And to clean:

> make clean


With CMake

mkdir build
cd build
cmake ..

For debug
cmake --build .
For release
cmake --build . --config Release

Or for using g++

rm -rf build
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .