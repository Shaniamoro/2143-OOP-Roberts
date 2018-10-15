#include "gol.h"


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