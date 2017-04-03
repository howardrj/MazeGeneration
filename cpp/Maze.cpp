#include <time.h>
#include <iostream>

#include "Maze.h"

// Note:: i, j convention used throughout follows matrix notation convention

Maze:: Maze (int numCellsX, int numCellsY)
    : m_dimX (2 * numCellsX - 1), 
      m_dimY (2 * numCellsY - 1),
      m_bias (0.5)
{
    // Dynamically allocate 2d array 
    m_maze = new char* [m_dimX];
    for (int j = 0; j < m_dimX; j++)
        m_maze[j] = new char[m_dimY];

    // Fill up maze grid with X's and empty links
    for (int i = 0; i < m_dimY; i++)
    {    
        for (int j = 0; j < m_dimX; j++)
        {    
            if (i % 2 == 0 && j % 2 == 0)    
                m_maze[i][j] = 'X';
            else 
                m_maze[i][j] = ' ';
        }
    }
}

Maze::~Maze ()
{
    for (int j = 0 ; j < m_dimX; j++)
        delete [] m_maze[j];

    delete [] m_maze;    
}

void Maze::printMaze ()
{
    for (int i = 0; i < m_dimY; i++)
    {
        for (int j = 0; j < m_dimX; j++)
        {
            std::cout << m_maze[i][j] << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n\n";
}    

int Maze::generate ()
{
    srand48(time(NULL));
    srand(time(NULL));

    // Loop over each row of cells (except last)
    for (int i = 0; i < m_dimY - 2; i += 2)
    {
        // Map to store sets on each row
        // Probably doesn't need to be map anymore since key is not important
        // (key, value) == (set_id, {num_cells, first_node_position})
        std::map <int, SetInfo*> row_sets;

        // Randomly join cells in the first row. Only consider link grid points
        // This groups the row into groups of sets
        int set_id     = 0;
        int cell_count = 1;
        int first_node = 0;

        for (int j = 1; j < m_dimX; j += 2)
        {
            if (drand48() < m_bias)
            {
                m_maze[i][j] = '-';
                cell_count++;
            }
            else
            {
                // We have come to the end of a set. Add info to map
                SetInfo *set_info = new SetInfo();
                set_info->cellCount         = cell_count;
                set_info->firstNodePosition = first_node; 

                row_sets.insert(std::pair<int, SetInfo*> (set_id, set_info));
                
                // Increment set id, reset cell_count and mark position of first node of next set
                set_id++;
                cell_count = 1;
                first_node = j + 1; 
            }
        }    

        // Gather info when we are on last link
        // Probably more elegant way to do this
        SetInfo *set_info = new SetInfo();
        set_info->cellCount         = cell_count;
        set_info->firstNodePosition = first_node; 

        row_sets.insert(std::pair<int, SetInfo*> (set_id, set_info));

        SetItr it = row_sets.begin();

        // Randomly connect cells in the row downwards
        while (it != row_sets.end())
        {
            int count = 0;

            // Add up to cellCount downward links
            // Need to add at least one per set
            while (count < it->second->cellCount)
            {
                int down_link_position  = (it->second->cellCount == 1) ? 0 : 2 * (rand() % (it->second->cellCount - 1));

                m_maze[i + 1][it->second->firstNodePosition + down_link_position] = '|';

                count++;
            }    
            
            // Clean up map as we iterate
            delete (it++)->second;
        }        
    }

    // Join up links in last row
    for (int i = 1; i <= m_dimX - 2; i += 2)
        m_maze[m_dimY - 1][i] = '-';

    return 0;
}
