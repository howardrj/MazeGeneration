#ifndef _MAZE_H_
#define _MAZE_H_

#include <map>

class Maze 
{
public:
    Maze (int numCellsX, int numCellsY);
    ~Maze ();

    void printMaze ();

    // Generate maze from grid setup using Eller's algorithm
    int generate ();

private:
    // 2d char array storing our maze configuration grid
    char** m_maze;
    
    // Size of m_maze in x and y directions (includes cells and links between cells)
    int m_dimX;
    int m_dimY;

    double m_bias;

    struct SetInfo 
    {
        int cellCount;
        int firstNodePosition;
    };

    typedef std::map<int, SetInfo*>::iterator SetItr;
};

#endif
