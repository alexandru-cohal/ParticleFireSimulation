#include <iostream>
#include <SDL.h>

#include "Screen.h"

using namespace std;
using namespace particuleSimulator;

int main()
{
	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error in the initialization of the SDL" << endl;
	}

	// The application loop
	while (true)
	{
		if (screen.processEvents() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}
