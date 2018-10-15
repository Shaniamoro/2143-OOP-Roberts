#include "gol.h"
/**
* Constructor which creates our game of life world.
* Creates a window
*
* @param {int}  width: width of the Window
*				height: height of the window
* @return {NULL}
*/
GameOfLife::GameOfLife(int width, int height) {
	World = new golCell[height];
	id = 0;
	frameCount = 0;
	frameRate = 50; // Game board will be printed ever 5th iteration 
	Width = width;
	Height = height;
	// Creating a window with the specifications 
	Window.create(VideoMode(Width, Height), "Game of Life");

	for (int i = 0; i < height; i++) {
		W[i] = new golCell[width];
		for (int j = 0; j < width; j++) {
			W[i][j].setCellPos(i, j);
		}
	}
}
/**
* Constructor which creates our game of life world.
* Creates a window
*
* @param {int}  width: width of the Window
*				height: height of the window
*				rate: User inputs the rate for the iterations
* @return {NULL}
*/

GameOfLife::GameOfLife(int width, int height, int rate) {
	Width = width;
	Height = height;
	frameCount = 0;
	//Gameboard would be printed the number of iterations given 
	frameRate = rate;
	Window.create(VideoMode(Width, Height), "Game of Life");

	W = new golCell*[height];
	id = 0;

	for (int i = 0; i < height; i++) {
		W[i] = new golCell[width];
		for (int j = 0; j < width; j++) {
			W[i][j].setCellPos(i, j);
		}
	}
}
/**
* Deconstructor
*
*
* @param {int}
* @return {NULL}
*/
GameOfLife::~GameOfLife() {
	for (int i = 0; i < worldRows; i++) {
		//deletes the elements of the rows 
		delete[]W[i];
	}
	//delete rows 
	delete[]W;
}

/**
  * Prints the current state of the GOL world
  * Both to the Console and to the SFML screen
  *
  * @param {None}
  * @return {NULL}
  */
void  GameOfLife::drawWorld() {
	Window.clear();
	// Printing to the window 
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			Window.draw(W[i][j].Rect);
		}
	}
	// Printing to the console
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			cout << *(&W[i][j].isAlive) << "";
		}
		cout << endl;
	}
	// Make the thread wait
	sleep(milliseconds(500));
	Window.display();
}
/**
  * Prints the Final World to File
  *
  * @param {None}
  * @return {NULL}
  */
void  GameOfLife::printWorld(string outfilename) {
	ofstream myfile;
	myfile.open(outfilename);
	myfile << " Shania Roberts" << endl;
	myfile << " The 338th generation" << endl;
	// Printing to the file
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			myfile << *(&W[i][j].isAlive) << "";
		}
		myfile << endl;
	}
	myfile.close();
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
		//cout << "Pass " << "row" << row << "col" << col << endl;
	}
	else {
		return false;
		//cout << "Fail" << "row" << row << "col" << col << endl;
	}
}
/**
	* Counts the live neighbors for a given cell
	*
	* @param {int} r: row we're looking at c: column we're looking at
	* @return {int} neighbors: sum of neighbours
	*/

int GameOfLife::countNeighbors(int r, int c) {
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
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Black);
	}
	// Any live cell with more than three live neighbors dies, as if by overcrowding.
	if (W[row][col].isAlive == true && W[row][col].neighbors > 3) {
		W[row][col].isAlive = false;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Black);
	}
	// Any live cell with two or three live neighbors lives on to the next generation.
	if (W[row][col].isAlive == true && W[row][col].neighbors == 2 || W[row][col].neighbors == 3) {
		W[row][col].isAlive = true;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Magenta);
	}
	// Any dead cell with exactly three live neighbors becomes a live cell.
	if (W[row][col].isAlive == false && W[row][col].neighbors == 3) {
		W[row][col].isAlive = true;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Magenta);
	}
	else {
		W[row][col].isAlive = W[row][col].isAlive;

		if (W[row][col].isAlive == true) {
			W[row][col].setCellPos(row, col);
			W[row][col].changeColor(Color::Magenta);
		}
		else if (W[row][col].isAlive == false) {
			W[row][col].setCellPos(row, col);
			W[row][col].changeColor(Color::Black);
		}

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
	//cout << "Our filename is :" << fileName << endl;
	infile.open(fileName);
	if (!infile) {
		//cout << "Error, file couldn't be opened" << endl;
		exit(1);
	}
	return infile;
}

/**
 * Attempting to build our initial Array and print it to the screen
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
	int** tempArray = new int *[worldRows];

	for (int i = 0; i < worldRows; i++) {
		tempArray[i] = new int[worldCols];
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
			tempArray[i][j] = (int)characterArray[k] - 48;
			k++;
		}
	}
	//convert int array to World array
	for (int i = 0; i < worldRows; i++) {
		for (int j = 0; j < worldCols; j++) {
			W[i][j].isAlive = tempArray[i][j];
			if (W[i][j].isAlive == true) {
				W[i][j].setCellPos(i, j);
				W[i][j].changeColor(Color::Magenta);
			}
			else if (W[i][j].isAlive == false) {
				W[i][j].setCellPos(i, j);
				W[i][j].changeColor(Color::Black);
			}
		}
	}

	drawWorld();
	return W;

}
/**
 * Refreshes the generations then prints the new generation.
 *
 * @param {int} runAmt: the number of times the program will run
 * @return {Null}
 */
void GameOfLife::refreshGeneration(int runAmt) {
	//Change the states x times 
	for (int x = 0; x < runAmt; x++) {
		for (int i = 0; i < worldRows; i++) {
			for (int j = 0; j < worldCols; j++) {
				W[i][j].neighbors = countNeighbors(i, j);
			}

		}
		for (int i = 0; i < worldRows; i++) {
			for (int j = 0; j < worldCols; j++) {
				changeState(i, j);
			}

			if (x == 337) {
				printWorld(outfileName);
			}
		}
		//Print the new world 
		cout << "Printing Array to Draw: " << endl;
		cout << "This is the  : " << x + 1 << " run" << endl;
		drawWorld();
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
	outfileName = outputFileName;
	// Exception Handling 
	ifstream fileStream;
	try {
		fileStream = readFromFile(inputFileName);
	}
	catch (exception& e) {
		//cout << "Error reading from the file" << endl;
		exit(1);
	}

	// Reading from the file 
	fileStream = readFromFile(inputFileName);
	// Builds the Initial World 
	golCell** World = buildArray(fileStream);
	// Converting to integer
	int numOfGenerations = stoi(numberOfRuns);
	// updating generations 
	refreshGeneration(numOfGenerations);

}