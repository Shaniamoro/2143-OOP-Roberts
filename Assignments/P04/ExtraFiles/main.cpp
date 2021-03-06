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
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
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
	RectangleShape Rect;
	int Width;
	int Height;
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
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Cyan);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}
	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}
	void changeColor(Color nameOfColor) {
		Rect.setFillColor(nameOfColor);
	}
};

// Default 
class GameOfLife {
private:
	golCell* World;
	int nums[10];
	int id;
public:
	golCell ** W;
	int Width;		// Width f a cell
	int Height;		// Height of a cell
	int worldRows;	// Row count in the world
	int worldCols;	// Column count in  the World
	int frameCount;	// Used to count the frames 
	int frameRate;	// the rate at which they are to be printed
	RenderWindow Window;
	string outfileName;
	void printWorld(string);
	bool onWorld(int, int);
	int countNeighbors(int, int);
	void changeState(int, int);
	ifstream readFromFile(string);
	golCell** buildArray(ifstream&);
	void refreshGeneration(int);
	void run(string, string, string);
	~GameOfLife();
	GameOfLife(int width, int height);
	GameOfLife(int width, int height, int rate);
	void drawWorld();
	// How to make one cell change color  if its alive or dead 
};


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
		W[row][col].changeColor(Color:: Black);
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


int main(int argc, char *argv[]) {
	// goes to default constructer
	// gameOfLife Gol(1000,1000);
	//User inputs iterations  
	int rate = 10;
	GameOfLife Gol(400, 500, rate);

	//GameOfLife World;
	string infileName;
	string numOfGenerations;
	string outFileName;

	if (argc < 4) {
		// We print argv[0] assuming it is the program name
		cout << "usage: " << argv[0] << " <filename>\n";
	}
	else {
		infileName = argv[1];
		numOfGenerations = argv[2];
		outFileName = argv[3];
		// Runs the driver fuction of the program 
		//Gol.run(infileName, numOfGenerations, outFileName);
	}
	while (Gol.Window.isOpen()) {
		Event event;
		while (Gol.Window.pollEvent(event)) {
			if (Gol.frameCount % Gol.frameRate == 0) {
				//Gol.drawWorld();
				Gol.run(infileName, numOfGenerations, outFileName);
			}
			//Gol.drawWorld();
			if (event.type == Event::Closed) {
				Gol.Window.close();
			}

		}
		Gol.frameCount++;
	}

	return 0;
}
