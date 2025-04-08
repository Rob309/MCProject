# MCProject

Project made in a team of 4 as part of Transilvania Univeresity's Modern C++ course

# MonkeyBusyness (also known as Monkey Madness)  

## 🐵 Overview  
**MonkeyBusyness** is a fast-paced 2D multiplayer game inspired by classic arcade-style battles, similar to *Battle City*. In this chaotic and fun-filled game, each player takes control of a monkey engaged in combat against three other players, using bananas as their primary weapons.  

## 🎮 Gameplay & Features  
- **Multiplayer Action** – Up to four players compete against each other in an intense battle.  
- **Banana Warfare** – Players throw bananas at their opponents to eliminate them and gain an advantage.  
- **Unique Special Abilities** – Each monkey possesses a special power that can be used strategically to turn the tide of battle.  
- **2D Battle Arena** – The game features dynamic levels with obstacles, hiding spots, and strategic points that players can use to their advantage.  

## 🔥 Objective  
The goal is to be the last monkey standing! Players must use their agility, special abilities, and well-aimed banana throws to outplay their opponents.  

## 🔧⚙️ Technologies & Components Used  
**MonkeyBusyness** is a **multiplayer** game designed with modern C++ and various powerful frameworks, supporting **multigaming** functionality for seamless player interactions.  

- **Modern C++ (C++17/20)** – Efficient, high-performance code with modern practices.  
- **Template DLL Architecture** – Enhances modularity and reusability.  
- **Qt Framework** – Provides a smooth and intuitive graphical interface.  
- **SQLite** – Used for managing player data, game statistics, and settings.  
- **WebSockets (ixwebsocket)** – Enables real-time multiplayer gameplay.  
- **Crow & CPR Libraries** – Used for handling HTTP requests and networking. 

## 🚀 How to Play  
1. Select your monkey and special ability.  
2. Move through the arena, avoiding attacks and finding the best angles to strike.  
3. Use your bananas wisely to eliminate enemies.  
4. Take advantage of the environment for cover and strategic plays.  
5. The last monkey remaining wins the round!  

## 🛠️ Future Improvements  
- **A dedicated interface for choosing monkeys**, as the selection is currently random.  
- **A replay system** to review and analyze past matches.  
- **New monkeys with unique abilities** to add variety and strategy.  
- **New weapons with special powers** to enhance gameplay.  
- **New game modes** such as *Single Player* and *Team Battles* for a richer experience.  

Are you ready to embrace the madness and prove you're the ultimate monkey warrior? 🍌🐵  

## ⚙️ Setting Up Dependencies

This is the handout for setting up dependencies.

INSTALLING LIBRARIES:

To use vcpkg and the necessary libraries, the following steps were performed:

- Clone the vcpkg repository from: https://github.com/microsoft/vcpkg or
- Open the command prompt.
- Run the following command: .\vcpkg\bootstrap-vcpkg.bat.
- For using the Crow routes, follow these steps:

- Run the following command: vcpkg install crow:x64-windows.
  If the command is not recognized, try the following: .\vcpkg.exe install crow:x64-windows.
  For using HTTP routes, the CPR library is used, and the following steps should be taken:

- Run the following command: vcpkg install cpr:x64-windows.
  If the command is not recognized, try the following: .\vcpkg.exe install cpr:x64-windows.
  For using SQL databases (SQLite), the following steps should be taken:

- Run the following command: vcpkg install sqlite-orm:x64-windows.
  If the command is not recognized, try the following: .\vcpkg.exe install sqlite-orm:x64-windows.
  To use libraries in Visual Studio, run the following command: vcpkg integrate install.

For using websockets, follow these steps:

- Run the following command: vcpkg install ixwebsocket.
  If the command is not recognized, try the following: .\vcpkg install ixwebsocket.
  To create interfaces, use Qt, and install Qt version 6.8.0 from Qt Creator.

SETTING UP DEPENDENCIES:

For Qt elements, the following dependencies should be set:

- Add the include directory for Qt:
  Property > Configuration Properties > VC++ Directories > Include Directories > C:\Qt6.8\6.8.0\msvc2022_64\include

- Add the library directory for Qt:
  Property > Configuration Properties > VC++ Directories > Library Directories > C:\Qt6.8\6.8.0\msvc2022_64\lib

- Add the path to the Qt folder for the application version:
  Property > Configuration Properties > Qt Project Settings > Qt Installation > QT 6_8

- Add the modules following the path:
  Property > Configuration Properties > Qt Project Settings > Qt Modules, and select: core, gui, quick, widgets.

- Link the library by adding the path to the library directory in the Qt folder:
  Property > Linker > General > Additional Library Directories > C:\Qt6.8\6.8.0\msvc2022_64\lib

- Add the additional dependencies:
  Property > Linker > General > Additional Dependencies > Qt6Core.lib; Qt6Widgets.lib; Qt6Gui.lib; Qt6Cored.lib

To add a Qt version, follow these steps:

- Go to the main menu in Visual Studio: Qt VS Tools > Qt Versions, and click Add.
- Select the main directory of the installed Qt version: C:\Qt6.8\6.8.0.

For websocket elements, the following dependencies should be set:

These dependencies differ for Release and Debug configurations.

RELEASE:

- Add the include directory for websocket: Property > Configuration Properties > VC++ Directories > Include Directories > C:\Computers\vcpkg-2024.12.16\vcpkg-2024.12.16\installed\x64-windows\include

- Add the library directory for websocket: Property > Configuration Properties > VC++ Directories > Library Directories > C:\Computers\vcpkg-2024.12.16\vcpkg-2024.12.16\installed\x64-windows\lib

DEBUG:

- Add the include directory for websocket: Property > Configuration Properties > VC++ Directories > Include Directories > C:\Computers\vcpkg-2024.12.16\vcpkg-2024.12.16\installed\x64-windows\include

- Add the library directory for websocket: Property > Configuration Properties > VC++ Directories > Library Directories > C:\Computers\vcpkg-2024.12.16\vcpkg-2024.12.16\installed\x64-windows\debug\lib

- Add the additional dependencies:
  Property > Linker > General > Additional Dependencies > ixwebsocket.lib; mbedtls.lib; mbedx509.lib; mbedcrypto.lib; Crypt32.lib; bcrypt.lib

For Vector2 DLL elements, the following dependencies should be set:

RELEASE:

- Add the include directory for Vector2 DLL :
  Property > Configuration Properties > VC++ Directories > Include Directories > C:\Computers\MCProject\TheMonkeyBusyness\Vector2

- Add the library directory for Vector2 DLL :
  Property > Configuration Properties > VC++ Directories > Library Directories > C:\Computers\MCProject\TheMonkeyBusyness\x64\Release

DEBUG:

- Add the include directory for Vector2 DLL :
  Property > Configuration Properties > VC++ Directories > Include Directories > C:\Computers\MCProject\TheMonkeyBusyness\Vector2

- Add the library directory for Vector2 DLL :
  Property > Configuration Properties > VC++ Directories > Library Directories > C:\Computers\MCProject\TheMonkeyBusyness\x64\Debug


  #Please use ipconfig command in cmd and put http://yourIpAdressGoesHere:8080 in  MCProjectMonkeyBusyness\TheMonkeyBusyness\TheMonkeyBusynessVisual\config.txt for local pvp on multiple devices

## 🎬▶️  Video Project
  Video Project: [https://youtu.be/u4TCsvCAms](https://youtu.be/u4TCsvCAmss)
