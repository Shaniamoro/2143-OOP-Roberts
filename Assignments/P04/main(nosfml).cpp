/**
	*  Course: CMPS 2143 - OOP
	*  Program: Program 2
	*
	*  Purpose: Game of Life Solution
	*
	*  @author Shania Roberts
	*  @version 1.1 10/08/18
	*  @github repo: https://github.com/Shaniamoro/2143-OOP-Roberts
	*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>
using namespace std;

//defining global row and column
int worldRows;
int worldCols;

/**
  * Creates the data structure golCell
  *
  * @param  {None}
  * @return {NULL}
  */
struct golCell {
	bool isAlive;
	int neighbors;

	/**
	* Constrctor for GOL cell which contains the neighbours
	* and if the cell is alive or not
	*
	* @param  {None}
	* @return {NULL}
	*/
	golCell() {
		isAlive = 0;
		neighbors = 0;
	}
};

/**
 * Class: GameofLife
 *
 * Purpose: Implements our game board
 * Methods:
 *
 */
class GameOfLife {
private:
	golCell* World;
	int nums[10];
	int id;

public:
	/**
	 * Creates our game of life world
	 *
	 * @param {int} size:
	 * @return {NULL}
	 */
	GameOfLife(int size) {
		World = new golCell[size];
		id = 0;
	}
};

/**
  * Prints the current state of the GOL world
  *
  * @param {object , int} W: cell we're looking at r: row we're looking at c: column we're looking at
  * @return {NULL}
  */
void printWorld(golCell** W, int Rows, int Cols) {
	for (int row = 0; row < Rows; row++) {
		for (int col = 0; col < Cols; col++) {
			cout << W[row][col].isAlive;
		}
		cout << endl;
	}
}
/**
  * Checks to see if a cell is on the World
  *
  * @param {object , int} W: cell we're looking at r: row we're looking at c: column we're looking at
  * @return {int} neighbors: sum of neighbours
  */
bool onWorld(int row, int col) {
	// Checks if the location is within the range of the matrix 
	if ((row >= 0 && row < worldRows) && (col >= 0 && col < worldCols)) {
		return true;
		cout << "Pass " << "row" << row << "col" << col << endl;
	}
	else {
		return false;
		cout << "Fail" << "row" << row << "col" << col << endl;
	}
}

/**
 * Counts the live neighbors for a given cell
 *
 * @param {object , int} W: cell we're looking at r: row we're looking at c: column we're looking at
 * @return {int} neighbors: sum of neighbours
 */

int countNeighbors(golCell** W, int r, int c) {
	int neighbors = 0;
	if (onWorld(r - 1, c - 1) && W[r - 1][c - 1].isAlive) {
		neighbors++;
	}
	if (onWorld(r - 1, c) && W[r - 1][c].isAlive) {
		neighbors++;
	}
	if (onWorld(r - 1, c + 1) && W[r - 1][c + 1].isAlive) {
		neighbors++;
	}
	if (onWorld(r, c - 1) && W[r][c - 1].isAlive) {
		neighbors++;
	}
	if (onWorld(r, c + 1) && W[r][c + 1].isAlive) {
		neighbors++;
	}
	if (onWorld(r + 1, c - 1) && W[r + 1][c - 1].isAlive) {
		neighbors++;
	}
	if (onWorld(r + 1, c) && W[r + 1][c].isAlive) {
		neighbors++;
	}
	if (onWorld(r + 1, c + 1) && W[r + 1][c + 1].isAlive) {
		neighbors++;
	}
	return neighbors;
}

/**
 * Apply rules to kill the cell or bring it to life
 *
 * @param {object , int} W: cell we're looking at r: row we're looking at c: column we're looking at
 * @return {NULL}
 */
void changeState(golCell** W, int row, int col) {
	W[row][col].neighbors;
	// Any live cell with fewer than two live neighbors dies,as if caused by under-population.
	if (W[row][col].isAlive == true && W[row][col].neighbors < 2) {
		W[row][col].isAlive = false;
	}
	// Any live cell with more than three live neighbors dies, as if by overcrowding.
	if (W[row][col].isAlive == true && W[row][col].neighbors > 3) {
		W[row][col].isAlive = false;
	}
	// Any live cell with two or three live neighbors lives on to the next generation.
	if (W[row][col].isAlive == true && W[row][col].neighbors == 2 || W[row][col].neighbors == 3) {
		W[row][col].isAlive = true;
	}
	// Any dead cell with exactly three live neighbors becomes a live cell.
	if (W[row][col].isAlive == false && W[row][col].neighbors == 3) {
		W[row][col].isAlive = true;
	}
	else {
		W[row][col].isAlive = W[row][col].isAlive;
	}
}

ifstream readFromFile(string fileName) {
	ifstream infile;
	infile.open(fileName);
	if (!infile) {
		cout << "Error, file couldn't be opened" << endl;
		exit(1);
	}
	return infile;
}

golCell** buildArray(ifstream& streamService) {
	golCell** World;
	int row;
	int column;
	//Reading the initial state (generation 0) for our game to be played. 
	//Along with the number of rows and columns 
	streamService >> row >> column;


	World = new golCell*[column];

	for (int i = 0; i < row; i++) {
		World[i] = new golCell[column];
	}
	//declaring array to store integer 2d array from char array

	int** worldArray = new int *[column];

	for (int i = 0; i < row; i++) {
		worldArray[i] = new int[column];
	}

	char x;
	string myString = "";
	//while the character is 1 or 0, concatenate to string
	while (true) {
		x = streamService.get();
		if (x == '1' || x == '0') {
			myString = myString + x;
		}
		if (streamService.eof()) {
			streamService.close();
			break;
		}
	}
	//convert string into character array
	char * characterArray = new char[myString.length() + 1];
	strcpy_s(characterArray, myString.length() + 1, myString.c_str());
	//convert character array into int array
	int k = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			worldArray[i][j] = (int)characterArray[k] - 48;
			k++;
		}
	}
	//convert int array to World array
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			World[i][j].isAlive = worldArray[i][j];
		}
	}
	return World;
}
/**
* Run Game of Life n amount of times
*
* @param {int} n: number of times we're running it for
* @return {NULL}
*/
void run(string inputFileName, string numberOfRuns, string outputFileName) {
	ifstream fileStream;
	try {
		fileStream = readFromFile(inputFileName);
		cout << "read";
	}
	catch (exception& e) {
		cout << "Error reading from the file" << endl;
		exit(0);
	}

	fileStream = readFromFile(inputFileName);
	cout << inputFileName;
	golCell** World = buildArray(fileStream);
	printWorld(World, worldRows, worldCols);

	//Change the states 20 times 
	for (int x = 1; x < 2; x++) {
		for (int i = 0; i < worldRows; i++) {
			for (int j = 0; j < worldCols; j++) {
				World[i][j].neighbors = countNeighbors(World, i, j);
			}

		}
		for (int i = 0; i < worldRows; i++) {
			for (int j = 0; j < worldCols; j++) {
				changeState(World, i, j);
			}
		}
		printWorld(World, worldRows, worldCols);
		cout << "New World" << endl;
		
	}
}

int main(int argc, char *argv[]) {

	//golCell** World;
	string infileName;
	string numOfGenerations;
	string outFileName;
	if (argc != 4) {
		cout << "ARGUMENTS: \n";
		for (int i = 0; i < argc; i++) {
			cout << argv[i] << endl;
		}
		// We print argv[0] assuming it is the program name
		cout << "usage: " << argv[0] << " <filename>\n";
	}
	else {
		infileName = argv[1];
		numOfGenerations = argv[2];
		outFileName = argv[3];
		
		run(infileName, numOfGenerations, outFileName);
	}
}
