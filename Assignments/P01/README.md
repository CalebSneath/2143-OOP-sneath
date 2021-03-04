## P01 - Game: Game
### Caleb Sneath
### Description:

This folder displays the introductory use of SFML programming and classes with an unnamed game created under instructions from my OOP class that I'm currently referring to as, "Asteroid Dodger". 

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [main.cpp](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/main.cpp)         | Main program that compiles game      |
|   2   | [Asteroid Dodger Screenshot.png](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/Asteroid%20Dodger%20Screenshot.png)  | A screenshot that shows gameplay         |
|   3   | [Banner.txt](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/Banner.txt) | My banner |
|   4   | [main.exe](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/main.exe)     | Game executable |
|   5   | [main.o](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/main.o)     | File you should get while following compile instructions |
|   6   | [arial.ttf](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/arial.ttf)     | Game font file, obtained from zyedidia |
|   7   | Everything else | Miscellaneous SFML libraries |


### Instructions

- Make sure to install SFML, visual studios code, and miniGW.
- If the above is already done from previous assignments, make sure to grab "arial.ttf". It is a file that contains the game's font.
  - Font obtained from [zyedidia](https://github.com/zyedidia/SFML.jl/blob/master/assets/arial.ttf), although a copy is in this folder.
- Place appropriate bin files in the same directory as main.cpp
- Ensure the terminal is set to the command line in VS Code
- Type the following into the command line:
- g++ -c main.cpp
- g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system
- main.exe

- The game should now run. Have fun. Use up, down, w, or s to move vertically. 
- Dodge asteroids to gain one point for every asteroid that leaves the screen.
- Lose twenty points for bumping into an asteroid.


<img src="Asteroid Dodger Screenshot.png" width="800">

