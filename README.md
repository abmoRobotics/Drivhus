## Downloading the project
**git clone https://github.com/abmoRobotics/Drivhus.git**
## Updating submodules
To run the code, the required external packages must be downloaded, this is done by following the steps listed below:
1. Navigate to the drivhus folder (cd drivhus)
2. git submodule update --init --recursive
## Opening and running the project in Visual Studio Code
1. Open project with root in "\Drivhus".
2. Configure project: Wait for the project to auto-configure or Ctrl+Shift+P and type: CMake: Configure
3. Build project: Ctrl+Shift+P and type: CMake: Build
## Navigating in the folders 
All folder and files are to be ignored except "Simulering" and "SSP". 
In "SSP" you will find all the relevant documents. 
The folder "Simulering" contains all documents that are related to the programing. 
The file ".vscode" contains the launch file. 
"include" and "libs" contains header file. The "include" folder contains header files created by us and "libs" contains headers fildes from Imgui and SFML. 
Lastly the "src" folder contains all the cpp files. 
