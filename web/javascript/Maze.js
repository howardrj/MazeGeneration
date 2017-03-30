// Maze class defintion
function Maze (numCellsX, numCellsY, bias, cellWidth)
{
    // Define default values
    this.numCellsX = typeof numCellsX !== 'undefined' ? numCellsX : 5; 
    this.numCellsY = typeof numCellsY !== 'undefined' ? numCellsY : 5; 
    this.bias      = typeof bias      !== 'undefined' ? bias      : 0.5; 
    this.cellWidth = typeof cellWidth !== 'undefined' ? cellWidth : 20; // Pixel dimensions of cell 
};

Maze.prototype.initializeGrid = function ()
{
    var maze_container = document.getElementById("maze_container");

    // Remove all children
    while (maze_container.hasChildNodes()) 
    {
        maze_container.removeChild(maze_container.lastChild);
    }

    var grid_height = this.cellWidth * this.numCellsY;
    var grid_width  = this.cellWidth * this.numCellsX;

    maze_container.style.height = grid_height.toString() + 'px'; 
    maze_container.style.width  = grid_width.toString()  + 'px'; 

    for (var i = 0; i < this.numCellsY; i++)
    {
        // Create cell row
        var cell_row = document.createElement("div");

        // Add class, height and width
        cell_row.classList.add("cell_row");
        cell_row.style.height = (this.cellWidth).toString() + 'px';
        cell_row.style.width  = maze_container.style.width;

        // Append to maze_container
        maze_container.appendChild(cell_row);

        for (var j = 0; j < this.numCellsX; j++)
        {
            // Create cell
            var cell = document.createElement("div");

            // Add class, height and width
            cell.classList.add("cell");
            cell.style.height = (this.cellWidth).toString() + 'px';
            cell.style.width  = (this.cellWidth).toString() + 'px';

            // If last cell in row, remove right border
            if (j == this.numCellsX - 1)
                cell.style.borderRight = "0px";

            // If cell is in last row, remove bottom border
            if (i == this.numCellsY - 1)
                cell.style.borderBottom = "0px";

            // Append to cell row
            cell_row.appendChild(cell);
        }
    }
};

Maze.prototype.generateMaze = function ()
{
    // Implement Eller's algorithm


};

// Create dat.GUI
(function (){

    var maze = new Maze();

    maze.initializeGrid();

    var gui  = new dat.GUI();

    // Add fields to gui
    gui.add(maze, 'numCellsX', 1, 20, 1);
    gui.add(maze, 'numCellsY', 1, 20, 1);
    gui.add(maze, 'bias',      0, 1, 0.1);
    gui.add(maze, 'cellWidth', 10, 100, 1);

    // Add buttons 
    gui.add(maze, 'initializeGrid');
    gui.add(maze, 'generateMaze');

})();

