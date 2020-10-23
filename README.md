# cpplibs_starter_basic
Basic CPP cmake with static and dynamic libs. Use this as a boilerplate to get started.
Output executable and shared libs are in the bin folder.

## GIT
Ref: https://www.vogella.com/tutorials/GitSubmodules/article.html
### Clone
git clone --recursive https://github.com/krexspace/cpplibs_starter_basic.git
### Update - Downloading multiple submodules at once
If there are nested submodules:  
git submodule update --init --recursive
### Pull -  Pulling with submodules
pull all changes in the repo including changes in the submodules  
git pull --recurse-submodules

pull all changes for the submodules  
git submodule update --remote

## Build and Run Instructions
### Visual Studio Code
This is the easiest way to build and run. You don't even need to run CMake 'configure' and 'generate'. VS Code does it all.  
Just open root folder, set the right CMake active kit, build and run. It should build all libs and run the executable.

### Linux Build
mkdir build  
cd build  
../build_linux.sh  




