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
