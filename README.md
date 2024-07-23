# 🕹️ **so_long** - 42 Cursus Project

![Build Status](https://img.shields.io/github/actions/workflow/status/zeniDlaw/so_long/CI.yml)
![License](https://img.shields.io/github/license/zeniDlaw/so_long)
![Stars](https://img.shields.io/github/stars/zeniDlaw/so_long)

## 📜 **Project Overview**

**so_long** is a 2D game developed as part of the 42 Cursus. The game involves navigating a player character through a maze-like map to collect collectibles and reach a designated exit. The project emphasizes basic game development principles, including handling user input, rendering graphics, and managing game state.

## 🎯 **Goals**

- Implement basic game mechanics and physics.
- Manage user input and game state effectively.
- Utilize the MiniLibX graphics library for rendering.

## 🌟 **Features**

- **Maze Navigation:** Move through a maze with a player character.
- **Collectibles:** Gather items scattered throughout the maze.
- **Exit:** Reach the exit to complete the level.
- **Score Tracking:** Keep track of collectibles and game progress.

## 🛠️ **Installation**

### **Prerequisites**

- **MiniLibX:** Make sure you have the MiniLibX graphics library installed. You can follow the instructions [here](https://github.com/42Paris/minilibx-linux) to install it.

- **Compile the Project:** 'Make' This will compile the source files and generate the executable file named "so_long'

### 🚀 **Usage**
*Run the Game*

```bash
./so_long map.ber
```
Replace map.ber with the path to your map file or just create a map in the folder maps.

*Controls*

W: Move Up
A: Move Left
S: Move Down
D: Move Right

🧩 *Map Format*
The game uses a custom map format. The map file (.ber) should follow these rules:

Walls: Represented by 1
Player: Represented by P
Collectibles: Represented by C
Exit: Represented by E
Empty Space: Represented by 0

*'Example Map:'*
```c
111111
100C01
101P01
100E01
111111
```

### **Clone the Repository**

```bash
git clone https://github.com/yourusername/so_long.git
cd so_long
```
### 🏆 **Acknowledgments**
- 42 Paris for the foundational curriculum.
- Contributors and mentors who provided guidance and support.

