/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Basically only print the game board every Xth iteration.
*
*  @author : Shania Roberts
*  @version 1.1: 10/5/18
*  @github repo: https://github.com/Shaniamoro/2143-OOP-Roberts
*/
#include <SFML/Graphics.hpp>

using namespace sf;

struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int Width;
	int Height;

	golCell() {
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Green);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}

	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}

};
// Default 
struct gameOfLife {
	int Width;
	int Height;
	// Used to count the frames 
	int frameCount;
	// the rate at which they are to be printed
	int frameRate;

	RenderWindow Window;
	golCell** World;
	gameOfLife(int width, int height) {
		frameCount = 0;
		// Game board will be printed ever 5th iteration 
		frameRate = 5;
		Width = width;
		Height = height;
		Window.create(VideoMode(Width, Height), "Game of Life");
		World = new golCell*[height];

		for (int i = 0; i < height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j < width; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}
	//User inputs the rate for the iterations 
	gameOfLife(int width, int height, int rate) {
		Width = width;
		Height = height;
		frameCount = 0;
		//Gameboard would be printed the number of iterations given 
		frameRate = rate;
		Window.create(VideoMode(Width, Height), "Game of Life");

		World = new golCell*[height];

		for (int i = 0; i < height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j < width; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}

	void drawWorld() {
		Window.clear();
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				Window.draw(World[i][j].Rect);
			}
		}
		Window.display();
	}
};



int main() {

	// goes to default constructer
	// gameOfLife Gol(1000,1000);

	//User inputs iterations  
	int rate = 10;
	gameOfLife Gol(500, 500, rate);

	while (Gol.Window.isOpen()) {
		Event event;
		while (Gol.Window.pollEvent(event)) {
			if (Gol.frameCount % Gol.frameRate == 0) {
				Gol.drawWorld();
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
