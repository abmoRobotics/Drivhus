## Downloading the project
**git clone https://github.com/abmoRobotics/Drivhus.git**
## Updating submodules
1. cd Drivhus
2. git submodule update --init --recursive
## Opening and running the project in Visual Studio Code
1. Open project with root in "\Drivhus".
2. Configure project: Wait for the project to auto-configure or Ctrl+Shift+P and type: CMake: Configure
3. Build project: Ctrl+Shift+P and type: CMake: Build
## Navigating in the folders 
All folder except "Simulering" are to be ignored.  
The file ".vscode" contains the launch file. 
"include" and "libs" contains header filee. The "include" folder contains header files created by us and "libs" contains headers fildes from Imgui and SFML. 
Lastly the "src" folder contains all the cpp files. 
