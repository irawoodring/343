/**
 * Board
 * Defines a board "class" for an Othello game.
 */

module.exports = class Board {
	/**
	 * Construct the object with required state
	 */
	constructor(height, width){
		this.height = height;
		this.width = width;
		this.board = [];
		for(let i=0; i<this.height; ++i){
			let tmp = [];
			for(let j=0; j<this.width; ++j){
				tmp.push(-1);
			}
			this.board.push(tmp);
		}
	}

	/**
	 * Print a representation of the board to the terminal.
	 */
	printBoard(){
		for(let i=0; i<this.height; ++i){
			for(let j=0; j<this.width; ++j){
				if(this.board[i][j] == -1){
					process.stdout.write('.\t')
				} else {
					process.stdout.write(this.board[i][j] + "\t")
				}
			}
			console.log();
		}
	}

	/**
	 * isValidMove
	 * @param row An integer row number.
	 * @param col An integer column number.
	 * @param disc A character for the disc color.
	 * @return A boolean indicating whether the move is valid.
	 */
	
	isValid(row, col, disc){

	}

	/**
	 * placeDiscAt
	 * @param row An integer number for row.
	 * @param col An integer number for column.
	 * @param disc A character standing for disc color.
	 */
	placeDiskAt(row, col, disc){

	}

	/**
	 * isValidMoveAvailable
	 * @param disc A character pertaining to a disc color.
	 * @return bool A boolean telling the user whether there are
	 *	 	valid moves availabe for that disc.
	 */
	isValidMoveAvailable(disc){

	}

	/**
	 * isBoardFull
	 * @return boolean Whether or not the board is full.
	 */
	isBoardFull(){

	}

	/**
	 * isGameOver
	 * @return bool Whether or not the game is over.
	 */
	isGameOver(){

	}

	/**
	 * checkWinner
	 * @return char Which player has won.  Return null if
	 * 		a tie exists.
	 */
	checkWinner(){

	}
}

//let board = new Board(10, 10);
//board.printBoard();
