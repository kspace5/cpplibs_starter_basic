# cpplibs_starter_basic
Basic CPP cmake with static and dynamic libs. Use this as a boilerplate to get started.
Output executable and shared libs are in the bin folder.

## GIT Tips
Ref: https://www.vogella.com/tutorials/GitSubmodules/article.html
### Clone
git clone --recursive https://github.com/krexspace/cpplibs_starter_basic.git
### Update - Downloading multiple submodules at once
If there are nested submodules:  
git submodule update --init --recursive
### Pull -  Pulling with submodules
git submodule foreach git pull origin main

Note: The following is not working when main and not master in the primary branch in git.
pull all changes in the repo including changes in the submodules  
git pull --recurse-submodules

pull all changes for the submodules  
git submodule update --remote

## Build and Run Instructions
### Visual Studio Code
This is the easiest way to build and run. You don't even need to run CMake 'configure' and 'generate'. VS Code does it all.  
Just open root folder, set the right CMake active kit, build and run. It should build all libs and run the executable.

### Linux Build
Cmake 3.10.2 does not have a -B<build dir> option. Solution is to upgrade to latest.  
Ref: https://stackoverflow.com/questions/49859457/how-to-reinstall-the-latest-cmake-version  
Simple steps:  
mkdir build  
cd build  
../build_linux.sh  

### Visual Studio 2019 - Steps to create a solution
Simple steps:  
mk build  
build_*.cmd

Build solution from the command line:  
Example: Compile with Visual Studio 2017 (Add msbuild to path -> path=%path%;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\amd64)  

msbuild abc.sln /property:Configuration=Release (or Debug)  

### Mingw64 and Cygwin in Windows 
Just run the exe built in Windows. The exe and dll should work in Mingw as well.
