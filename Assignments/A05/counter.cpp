/**
	 *  Course: CMPS 2143 - OOP
	 *
	 *  Purpose: Counter Class - Creating a counter for our game
	 *
	 *  @author Shania Roberts
	 *  @version 1.1 11/02/18
	 *  @github repo: https://github.com/Shaniamoro/2143-OOP-Roberts
	 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;


class Counter {
private:
	sf::Text text;
	sf::Font font;
	sf::Clock clock;
	sf::Time start;
	sf::Time end;
	sf::Time elapsed;
	sf::Event event;
	string outToScreen;
public:
	void getFont(string);
	Counter();
	Counter(int, int);
	Counter(int);
	void printToWindow();//Display as integer values 
	string increment();// count up to a value or have no end 
	string decrement();//count down to a value or have no end
	void run();
	void startCounter(); // start a timer 
	void resetClock();// reset a timer 
	bool closeWindow();

};

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
	cout << "Incrementing Clock: " << start.asSeconds() + elapsed.asSeconds() << endl;
	outToScreen = to_string(int(start.asSeconds() + elapsed.asSeconds()));
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
	cout << "Decrementing Clock: " << start.asSeconds() - elapsed.asSeconds() << endl;
	outToScreen = to_string(int(start.asSeconds() - elapsed.asSeconds()));
	return outToScreen;
}
/**
  * Start Counter
  * Decides weather it is an incremental or decremental function based
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
  * Restes the time to the start time
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
  * Print to Window
  * Prints the time to the window
  *
  * @param {None}
  * @return {NULL}
  */
void Counter::printToWindow() {
	// set the string to display
	text.setString(outToScreen);
	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::Red);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//return text;
}
/**
  * Close window
  * Checks if the endtime is met
  *
  * @param {None}
  * @return {bool} true of false
  */
bool Counter::closeWindow() {
	if (outToScreen == to_string(int(end.asSeconds()))) {
		return 1;
	}
	return 0;
}

/**
  * Driver function
  * Creates sfml window and utilizes all the functions
  *
  * @param {None}
  * @return {NULL}
  */
void Counter::run() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "Shania Roberts");

	getFont("font.otf");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		startCounter();
		printToWindow();
		// clock resets when the mouse is clicked
		if (event.type == sf::Event::MouseButtonPressed) {
			resetClock();
		}

		window.clear();
		// inside the main loop, between window.clear() and window.display()
		window.draw(text);
		window.display();

		// Close window
		if (closeWindow() == true) {
			window.close();
		}

	}

}


int main()
{
	Counter C(0, 5);
	C.run();
  Counter C2( 5, 0);
  C2.run();
	return 0;
}
