// Maze class defintion
function Maze (numCellsX, numCellsY, bias, cellWidth)
{
    // Define default values
    this.numCellsX = typeof numCellsX !== 'undefined' ? numCellsX : 5; 
    this.numCellsY = typeof numCellsY !== 'undefined' ? numCellsY : 5; 
    this.bias      = typeof bias      !== 'undefined' ? bias      : 0.5; 
    this.cellWidth = typeof cellWidth !== 'undefined' ? cellWidth : 20; // Pixel dimensions of cell 
};

Maze.prototype.clearMaze = function ()
{


};

Maze.prototype.generateMaze = function ()
{


};

// Create dat.GUI
(function (){

    var maze = new Maze();

    maze.clearMaze();

    var gui  = new dat.GUI();

    // Add fields to gui
    gui.add(maze, 'numCellsX', 1, 50, 1);
    gui.add(maze, 'numCellsY', 1, 50, 1);
    gui.add(maze, 'bias',      0, 1, 0.1);
    gui.add(maze, 'cellWidth', 10, 50, 1);

    // Add buttons 
    gui.add(maze, 'clearMaze');
    gui.add(maze, 'generateMaze');

})();

