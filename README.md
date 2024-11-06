https://github.com/Gabriela-de-sa/42-So-Long/assets/84455552/e47c00ed-89a9-4ca4-aa68-38d433a9ee82

<h1 align="center">
	SO-LONG
</h1>
<div align="center">
	<br>
  <img  height="130em"  width="15%" src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/so_longm.png" />
    <br>
</div>
<p align="center">
	<b><i>And thanks for all the fish!</i></b><br>
</p>

## 💡 About the project

This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.
I titled my project: Pirate Island.

---

### Mandatory

Create a basic computer graphics project. 
Use the school graphical library: the MiniLibX! This library was
developed internally and includes basic necessary tools to open a window, create images
and deal with keyboard and mouse events.

Construction of a Makefile to compile all libraries and files made in the project.

The mandatory part is divided into 3 parts:

1 - Game

  - The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
  - The W, A, S, and D keys must be used to move the main character.
  - The player should be able to move in these 4 directions: up, down, left, right.
  - The player should not be able to move into walls.
  - At every move, the current number of movements must be displayed in the shell.

2 - Graphic management

   - Your program has to display the image in a window.
   - Pressing ESC must close the window and quit the program in a clean way.
   - Use of the images of the MiniLibX

3 - Map

  - The map has to be constructed with 3 components: walls, collectibles, and free space.
  - The map can be composed of only these 5 characters:
    0 for an empty space,
    1 for a wall,
    C for a collectible,
    E for a map exit,
    P for the player’s starting position
  - Map validations
    - The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
    - You have to check if there is a valid path on the map using the flood fill algorithm.
    - The map must be rectangular.
    - The map must be closed/surrounded by walls. If it’s not, the program must return an error.

The entire project cannot under any circumstances have memory leaks.
I used some projects that I had already done, which were get next line and libft that I used as an aid.

NOTE - In the CMakeLists.txt file in the MLX42 directory, change the MLX version to 3.16.0 on line eight before compiling the project.

### Bonus part

There was only an increase in functionality

- The character cannot touch the enemy, in this case the snake, otherwise he will die.
- The character's step counter is in the game window itself.

## 💡 Execute

Compile using the Makefile. Use the name of the executable and as a second argument the full path of the file where the maps are located.

