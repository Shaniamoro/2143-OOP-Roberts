/**
	 *  Course: CMPS 2143 - OOP
	 *
	 *  Purpose: Counter Class - Bouncing Clock
	 *
	 *  @author Shania Roberts
	 *  @version 1.1 11/14/18
	 *  @github repo: https://github.com/Shaniamoro/2143-OOP-Roberts
	 */


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Group.h"
using namespace std;

/**
* DrawMe Class extending from Group 
* 
*
*Functions: 
*		 DrawMe() 
*		 changeClockPosition()
*/

class DrawMe : public Group {
protected:
	sf::RectangleShape CountRect;
	sf::Text text;
public:

	/**
	  * Default Constructor
	  *	Groups the Rectangle and the Texts as an object
	  *
	  *
	  * @param {None}
	  * @return {NULL}
	  */
	DrawMe() {

		text.setPosition(sf::Vector2f(110, 110));
		text.setOrigin(25, 25);
		CountRect.setSize(sf::Vector2f(100, 100));
		CountRect.setFillColor(sf::Color::White);
		CountRect.setOutlineColor(sf::Color::Green);
		CountRect.setOutlineThickness(2);
		CountRect.setOrigin(50, 50);
		CountRect.setPosition(100, 100);
		this->push_back(CountRect);
		this->push_back(text);
	}
	/**
	  * Change clock position
	  *	Changes the location of the clock
	  *
	  *
	  * @param {int} newRectOrigin, newRectPositionX, newRectPositionX : all coordinates needed
	  * @return {NULL}
	  */
	void changeClockPosition(int newRectOrigin, int newRectPositionX, int newRectPositionY) {
		text.setPosition(sf::Vector2f(newRectPositionX + 10, newRectPositionY + 10));
		text.setOrigin(newRectOrigin / 2, newRectOrigin / 2);
		CountRect.setOrigin(newRectOrigin, newRectOrigin);
		CountRect.setPosition(newRectPositionX, newRectPositionY);
	}
};
/**
* Counter Class extending from DrawMe
*
*Functions:
	getFont(string) 
	Counter()
	Counter(int, int)
	Counter(int)
	updateString()
	increment()
	decrement()
	startCounter()
	resetClock()
	changeFontColor(sf::Color)
	changeFontSize(int)
	adjustBackColor(sf::Color)
	adjustBorderColor(sf::Color)
	createRectangle()
	printShapes(sf::RenderWindow &)
	bounceAround()	 
*/
class Counter :public DrawMe {
private:
	sf::Font font;
	sf::Clock clock;
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;
	sf::Vector2f pos;
	sf::Event event;
	string outToScreen; // text to output to the screen
	string typeOfClock; // is it incrementing or decrementing 
	int compareThis; // the current time for comparison purposes 

public:
	float dx;// change in x
	float dy;// change in y 
	int decider; //So we can check if all timers are done 
	void getFont(string); // load the font from file and set text characteristics 
	Counter();
	Counter(int, int);
	Counter(int);
	void updateString();//Display as integer values in window
	string increment();// count up to a value or have no end 
	string decrement();//count down to a value or have no end
	void startCounter(); // start a timer 
	void resetClock();// reset a timer 
	void changeFontColor(sf::Color); // Configure the font color 
	void changeFontSize(int); //Configure the font size 
	void adjustBackColor(sf::Color); //Configure the background color 
	void adjustBorderColor(sf::Color); // Configure the border color
	void createRectangle(); // Create the Rectangle Shape paired with the text 
	void printShapes(sf::RenderWindow &); // Print both the text and the Rectangle 
	void bounceAround(); //makes the ball bounce around the screen

};


/**
  * Create Rectangle
  * Create a Base Rectangle
  *
  * @param {None}
  * @return {NULL}
  */
void Counter::createRectangle() {
	CountRect.setSize(sf::Vector2f(100.f, 100.f));
	CountRect.setFillColor(sf::Color::Black);
	CountRect.setOutlineThickness(5);
	CountRect.setOutlineColor(sf::Color::Green);
}

/**
  * Load Font
  * Loading the font from the file
  *
  * @param {string} name: name of the font to be loaded
  * @return {NULL}
  */

void Counter::getFont(string name) {

	//sf::Font font;
	if (!font.loadFromFile(name))
	{
		// error...
	}
	text.setFont(font); // font is a sf::Font
	// set the character size
	changeFontSize(24); // in pixels, not points!
	// set the color
	changeFontColor(sf::Color::Green);
	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//return text;
}
/**
  * Default Constructor
  * Defaults to an incremental clock
  *
  * @param {None}
  * @return {NULL}
  */
Counter::Counter() {
	start = sf::seconds(0);
	end = sf::seconds(10);
	//elapsed = clock.getElapsedTime();
	getFont("font.otf");
	createRectangle();
	dx = .1;
	dy = .1;
}
/**
  * Parameterized Constructor
  * sets the values for the start and end of the timer
  *
  * @param {int, int} begin: start time, end: end time
  * @return {NULL}
  */
Counter::Counter(int begin, int  endtime) {
	start = sf::seconds(begin);
	end = sf::seconds(endtime);
	//elapsed = clock.getElapsedTime();
	getFont("font.otf");
	createRectangle();
	dx = .1;
	dy = .1;
}
/**
  * Parameterized Constructor
  * sets the values for the start with no given end time, default value is set
  *
  * @param {int } begin: start time
  * @return {NULL}
  */
Counter::Counter(int begin) {
	start = sf::seconds(begin);
	end = sf::seconds(10000000);
	//elapsed = clock.getElapsedTime();
	getFont("font.otf");
	createRectangle();
	dx = .1;
	dy = .1;
}
/**
  * Increment Function
  * Clock that counts up to a value from the start value
  *
  * @param {None}
  * @return {string} outToScreen: the current time of the clock
  */
string Counter::increment() {
	elapsed = clock.getElapsedTime();
	//cout << "Incrementing Clock: " << start.asSeconds() + elapsed.asSeconds() << endl;
	outToScreen = to_string(int(start.asSeconds() + elapsed.asSeconds()));
	compareThis = int(start.asSeconds() + elapsed.asSeconds());
	typeOfClock = "i";
	return outToScreen;
}
/**
  * Decrement Function
  * Clock that counts down to a value from the start value
  *
  * @param {None}
  * @return {string} outToScreen: the current time of the clock
  */
string Counter::decrement() {
	elapsed = clock.getElapsedTime();
	//cout << "Decrementing Clock: " << start.asSeconds() - elapsed.asSeconds() << endl;
	outToScreen = to_string(int(start.asSeconds() - elapsed.asSeconds()));
	compareThis = int(start.asSeconds() - elapsed.asSeconds());
	typeOfClock = "d";
	return outToScreen;
}
/**
  * Start Counter
  * Decides wether it is an incremental or decremental function based
  * on the start and end times
  *
  * @param {None}
  * @return {NULL}
  */
void Counter::startCounter() {
	if (start < end) {
		increment();
	}
	else if (start > end) {
		decrement();
	}
}
/**
  * Reset Clock
  * Resets the time to the start time
  *
  * @param {None}
  * @return {NULL}
  */
void Counter::resetClock() {
	{
		clock.restart();
	}

}
/**
  * Change Font Color
  * To change the color of the font
  *
  * @param {sf::Color} Color: color to be used
  * @return {NULL}
  */
void Counter::changeFontColor(sf::Color color) {
	text.setFillColor(color);
}

/**
  * Change Font Color
  * To change the color of the size of the text
  *
  * @param {int} Size: size of font
  * @return {NULL}
  */
void Counter::changeFontSize(int size) {
	text.setCharacterSize(size);
}
/**
  * Change Background Color
  * To change the color of the Rectange
  *
  * @param {sf:Color } Color
  * @return {NULL}
  */

void Counter::adjustBackColor(sf::Color color) {
	CountRect.setFillColor(color);
}
/**
  * Change Border Color
  * To change the color of the Rectange Border
  *
  * @param {sf:Color } Color
  * @return {NULL}
  */
void Counter::adjustBorderColor(sf::Color color) {
	CountRect.setOutlineColor(color);
}

/**
  * update string in the Window
  * Prints the time to the window
  *
  * @param {None}
  * @return {NULL}
  */
void Counter::updateString() {
	decider = 0;
	// if its an incrementing clock 
	if (typeOfClock == "i") {
		if (compareThis < int(end.asSeconds())) {
			// set the string to display
			text.setString(outToScreen);
		}
		else {
			text.setString("FIN");
			decider = 1;
		}
	}
	// if its a decrementing clock 
	if (typeOfClock == "d") {
		if (compareThis > int(end.asSeconds())) {
			// set the string to display
			text.setString(outToScreen);
		}
		else {
			text.setString("FIN");
			decider = 1;
		}

	}

}

/**
  * Draws the text and rectangle to Window
  * Prints the time to the window
  *
  * @param {object} window
  * @return {NULL}
  */

void Counter::printShapes(sf::RenderWindow &window) {
	window.draw(CountRect);
	window.draw(text);
}
/**
  * Bounce Around
  *	Makes the clock bounce around the screen
  *
  *
  * @param {None}
  * @return {NULL}
  */
void Counter::bounceAround() {
	int Upperbound = 50;
	int lowerBound = 350;
	int leftBound = 50;
	int rightBound = 450;
	pos = CountRect.getPosition();
	//Checking if they hit the walls
	// If the rectangle hits the wall negates the value
	if (pos.x < leftBound) {
		dx *= -1;
	}
	else if (pos.x > rightBound) {
		dx *= -1;
	}

	if (pos.y < Upperbound) {
		dy *= -1;
	}
	else if (pos.y > lowerBound) {
		dy *= -1;
	}
	// moving the objects 
	CountRect.move(dx, dy);
	text.move(dx, dy);

}


int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 400), "Shania Roberts");

	// Creating instances of the Clock
	Counter C(-1, 20);
	Counter C2(20, -1);
	Counter C3(0, 1);

	//Changing the position of the clocks
	C2.changeClockPosition(50, 250, 250);
	C3.changeClockPosition(50, 400, 100);

	//Showing that I can configure border/ background/ font 
	C.adjustBorderColor(sf::Color::Blue);
	C2.adjustBackColor(sf::Color::White);
	C3.adjustBorderColor(sf::Color::Magenta);

	//Getting the font
	C.getFont("font.otf");
	C2.getFont("font.otf");
	C3.getFont("font.otf");

	//Game loop 
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Starting the counters and printing to window
		C.startCounter();
		C.updateString();
		C2.startCounter();
		C2.updateString();
		C3.startCounter();
		C3.updateString();

		// Making them bounce 
		C.bounceAround();
		C2.bounceAround();
		C3.bounceAround();

		// Font is changed within the game loop
		C2.changeFontColor(sf::Color::Red);

		// clock resets when the mouse is clicked
		if (event.type == sf::Event::MouseButtonPressed) {
			C.resetClock();
			C2.resetClock();
			C3.resetClock();
		}

		window.clear();
		// draw inside the main loop, between window.clear() and window.display()
		C.printShapes(window);
		C2.printShapes(window);
		C3.printShapes(window);
		window.display();

		//Checks if all the clocks are finished. 
		if (C.decider == 1 && C2.decider == 1 && C3.decider == 1) {
			window.close();
		}
	}
	return 0;

}
