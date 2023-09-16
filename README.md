# Game of Life

## Description

This repository features an implementation of Conway's Game of Life, a cellular automaton devised by John Conway, using the C programming language and Raylib graphics library. This interactive, real-time simulation allows you to watch cells evolve over time based on a set of simple rules. You can start, pause, and modify the grid seamlessly, making it ideal for educational and entertainment purposes.

## Dependencies

- C Compiler (gcc, clang)
- [Raylib](https://www.raylib.com/)

## How to Compile and Run

1. Make sure you have Raylib installed on your system.
2. Clone the repository.
    ```bash
    git clone https://github.com/yourusername/ConwayGameOfLife_Raylib_C.git
    ```
3. Navigate to the project directory.
    ```bash
    cd ConwayGameOfLife_Raylib_C
    ```
4. Compile the program.
    ```bash
    gcc -o game_of_life main.c -lraylib
    ```
5. Run the program.
    ```bash
    ./game_of_life
    ```

## Usage

- The simulation starts as soon as you run the program.
- Cells are drawn as white squares on a black background.

## Code Explanation

- `setup()`: Initializes the grid with random live or dead cells.
- `countNeighbors(int x, int y)`: Counts the number of live neighbors around a given cell.
- `update()`: Updates the grid based on the Game of Life rules.
- `draw()`: Draws the current state of the grid on the screen.
  
## Contributing

Feel free to fork this repository, add your own features, and create a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details. 

## Acknowledgments

- John Conway, for creating the Game of Life.
- Raylib, for making it easy to create this simulation in C.

Enjoy simulating life!
