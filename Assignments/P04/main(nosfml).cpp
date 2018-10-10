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
#include <string>
using namespace std;


/**
  * Creates the data structure that has its own methods that works on the data golCell
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
 *	GameOfLife();
 *	GameOfLife(int);
 *	void printWorld( int, int);
 *	bool onWorld(int, int);
 *	int countNeighbors(int, int);
 *	void changeState(int, int);
 *	ifstream readFromFile(string);
 *	golCell** buildArray(ifstream&);
 *	void refreshGeneration(int);
 *	void run(string, string, string);
 *
 */
class GameOfLife {
private:
	golCell* World;
	int nums[10];
	int id;

public:
	int worldRows;
	int worldCols;
	golCell** W;
	GameOfLife();
	GameOfLife(int);
	void printWorld( int, int);
	bool onWorld(int, int);
	int countNeighbors(int, int);
	void changeState(int, int);
	ifstream readFromFile(string);
	golCell** buildArray(ifstream&);
	void refreshGeneration(int);
	void run(string, string, string);

};

	/**
	* Default Constructor which creates our game of life world
	*
	* @param {int} size:
	* @return {NULL}
	*/
	GameOfLife::GameOfLife() {
		World = new golCell[10];
		id = 0;
	}
	/**
	* Creates our game of life world
	*
	* @param {int} size:
	* @return {NULL}
	*/
	GameOfLife::GameOfLife(int size) {
			World = new golCell[size];
			id = 0;
		}

/**
  * Prints the current state of the GOL world
  *
  * @param {object , int} row: row we're looking at col: column we're looking at
  * @return {NULL}
  */
void GameOfLife::printWorld(int row, int col) {
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			cout << W[x][y].isAlive;
		}
		cout << endl;
	}
}
/**
  * Checks to see if a cell is on the World
  *
  * @param {object , int} row: row we're looking at col: column we're looking at
  * @return {int} neighbors: sum of neighbours
  */
bool GameOfLife::onWorld(int row, int col) {
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
 * @param {int} r: row we're looking at c: column we're looking at
 * @return {int} neighbors: sum of neighbours
 */

int GameOfLife::countNeighbors( int r, int c) {
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
 * @param {object , int} row: row we're looking at col: column we're looking at
 * @return {NULL}
 */
void GameOfLife::changeState(int row, int col) {
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
/**
 * Attempting to open the file 
 *
 * @param {string} fileName: the name of the file to be read in
 * @return {ifstream} infile: reference to the file we will be using 
 */

ifstream GameOfLife::readFromFile(string fileName) {
	ifstream infile;
	cout <<"Our filename is :"<< fileName<< endl;
	infile.open(fileName);
	if (!infile) {
		cout << "Error, file couldn't be opened" << endl;
		exit(1);
	}
	return infile;
}

/**
 * Attempting to build our initial Array 
 *
 * @param {ifstream } infile: the file we will be using
 * @return {object} W: initial world 
 */

golCell** GameOfLife::buildArray(ifstream& infile) {
	//Reading the initial state (generation 0) for our game to be played. 
	//Along with the number of rows and columns 
	infile >> worldRows >> worldCols;
	W = new golCell*[worldRows];
	for (int i = 0; i < worldRows; i++) {
		W[i] = new golCell[worldCols];
	}
	//declaring array to store integer 2d array from char array
	int** worldArray = new int *[worldRows];

	for (int i = 0; i < worldRows; i++) {
		worldArray[i] = new int[worldCols];
	}
	char x;
	string myString = "";
	//while the character is 1 or 0, concatenate to string
	while (!infile.eof()) {
		x = infile.get();
		if (x == '1' || x == '0') {
			myString = myString + x;
		}
	}
	//convert string into character array
	char * characterArray = new char[myString.length() + 1];
	strcpy_s(characterArray, myString.length() + 1, myString.c_str());
	//convert character array into int array
	int k = 0;
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			worldArray[i][j] = (int)characterArray[k] - 48;
			k++;
		}
	}
	//convert int array to World array
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			W[i][j].isAlive = worldArray[i][j];
		}
	}
	return W;
}
	void GameOfLife::refreshGeneration(int runAmt){
		//Change the states ntimes 
		for (int x = 1; x < runAmt; x++) {
			for (int i = 0; i < worldRows; i++) {
				for (int j = 0; j < worldCols; j++) {
					W[i][j].neighbors = countNeighbors(i, j);
				}

			}
			for (int i = 0; i < worldRows; i++) {
				for (int j = 0; j < worldCols; j++) {
					changeState(i, j);
				}
			}

			cout << "New World" << x + 1 << endl;
			printWorld(worldRows, worldCols);
		}
	}

/**
* Driver for the Game of life program , accepts arguements
*
* @param {string} inputFileName: name of the file we're accessing
*				  numberOfRuns:  the number of generations we will generate
*				  outputFileName: output file for the program
* @return {NULL}
*/
void GameOfLife::run(string inputFileName, string numberOfRuns, string outputFileName) {
	// Exception Handling 
	ifstream fileStream;
	try {
		fileStream = readFromFile(inputFileName);
	}
	catch (exception& e) {
		cout << "Error reading from the file" << endl;
		exit(0);
	}
	// Reading from the file 
	fileStream = readFromFile(inputFileName);
	// Builds the Initial World 
	golCell** World = buildArray(fileStream);
	cout << "initial world" << endl;
	printWorld(worldRows, worldCols);
	// Converting to integer
	int numOfGenerations = stoi(numberOfRuns);
	// Calling function to Generate a new Generation
	refreshGeneration(numOfGenerations);
}

int main(int argc, char *argv[]) {

	GameOfLife World;
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
		// Runs the driver fuction of the program 
		World.run(infileName, numOfGenerations, outFileName);
	}
	system("pause");
}
