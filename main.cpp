#include <iostream>

#include "Maze.h"

int main (int argc, char* argv[])
{
    int num_cells_x;
    int num_cells_y;

    if (argc == 1) 
    {
        num_cells_x = 5;
        num_cells_y = 5;

        std::cout << "Defaulting to a 5 by 5 maze. To specify number of cells in x and y direction use: ./main num_x num_y" << std::endl;
    }
    else if (argc != 1 && argc != 3)
    {
        std::cout << "Error: Correct usage: ./main num_x num_y or ./main which defaults to a 5 by 5 maze" << std::endl;
        return 0;
    }
    else
    {
        num_cells_x = atoi(argv[1]);
        num_cells_y = atoi(argv[2]);
    }

    // Create new cell with number of cells in x and y diretion
    Maze *maze = new Maze(num_cells_x, num_cells_y);

    maze->printMaze();

    if (maze->generate() == -1)
    {
        std::cout << "Failed to generate maze" << std::endl;
        exit(-1);
    }

    maze->printMaze();

    return 0;
}
