/*
 * main.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: RaHamilton
 */

#if defined(__APPLE__)

	#include "SDL2/SDL.h"

#endif

#if defined(__linux__)

	#include "SDL2/SDL.h"

#endif

#if defined(_WIN32_) || (_WIN64_)

	#include "SDL2/SDL.h"

#endif

#include <stdio.h>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{

#if defined(__APPLE__)

	cout << "running on apple";

#endif

#if defined(__linux__)

	cout << "running on linux"  << endl;
	cout << "Added on linux" << endl;

#endif

#if defined(_WIN32_) || (_WIN64_)

	cout << "running on windows";

#endif

    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}



