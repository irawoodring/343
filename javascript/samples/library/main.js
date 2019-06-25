/**
 * Othello
 * Javascript project for CIS 343.
 * Command-line version of Othello.
 */

// Import our board definitions
const board = require('./board.js');
// Import a synchronous prompt library
const prompt = require('prompt-sync')();

/**
 * saveFile
 * SYNCHRONOUS (blocking) file save function.
 * @param file - The full filename path we want to save to.
 * @param contents - The object we wish to save as a JSON file.
 */
function saveFile(file, contents){
	let fs = require('fs');
	fs.writeFileSync(file, JSON.stringify(contents));
}

/**
 * loadFile
 * SYNCHRONOUS (blocking) file read function.
 * @param file - The full filename path we wish to load an object from.
 * @return contents - The object converted from JSON.
 */
function loadFile(file){

}

/**
 * Driver function.  "main" method, if you will.
 */
function start(){
 	// Local variables
	let height = prompt('What height for your board? ');
	let width = prompt('What width for your board? ');

	// SYNCHRONOUSLY read from keyboard
	console.log('Creating a board with size ' + height + ' x ' + width + '.');
	// Create new board object
	let myBoard = new board(height, width);

	// Print board
	myBoard.printBoard();

	// Loop, asking user input, calling appropriate functions.

	// Save board example code.
	saveFile("test.json", myBoard);
}

console.clear();
start();
