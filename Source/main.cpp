/*
 * main.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: RaHamilton
 */

#if defined(__APPLE__)

	#include "SDL2/SDL.h"
	#include "SDL2_image/SDL_image.h"

#endif

#if defined(__linux__)

	#include "SDL2/SDL.h"
	#include "SDL2_image/SDL_image.h"

#endif

#if defined(_WIN32_) || (_WIN64_)

	#include "SDL2/SDL.h"
	#include "SDL2_image/SDL_image.h"

#endif

#include <stdio.h>
#include <iostream>
using namespace std;


//code for frame rate independence
float deltaTime = 0.0;
int thisTime = 0;
int lastTime = 0;

int main(int argc, char* argv[])
{

#if defined(__APPLE__)

	cout << "running on apple" << endl;
	//get the current working directory
	string s_cwd(getcwd(NULL,0));

	//create a string linking to the mac's images folder
	string s_cwd_images = s_cwd + "/Resources/Images";

	//Test
	cout << s_cwd_images << endl;

#endif

#if defined(__linux__)

<<<<<<< Updated upstream
	cout << "running on linux"  << endl;
	cout << "Added on linux" << endl;
=======
	cout << "running on linux" << endl;
>>>>>>> Stashed changes

#endif

#if defined(_WIN32_) || (_WIN64_)

	cout << "running on windows" << endl;

#endif

    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        1024,                               // width, in pixels
        768,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    //declare renderer
    SDL_Renderer *renderer = NULL;

    //create the renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //****** Create Background ******
    string BKGDpath = s_cwd_images + "/bkgd.png";

    //create a SDL surface to hold the background image
    SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

    //create a SDL texture
    SDL_Texture *bkgd1;

    //place surface into the texture bkgd1
    bkgd1 = SDL_CreateTextureFromSurface(renderer, surface);

    //create a SDL texture - background 2
    SDL_Texture *bkgd2;

    //free the SDL surface
    //SDL_FreeSurface(surface);

//create the SDL_Rectangle for the texture's position and size -x,y,w,h
SDL_Rect bkgd1Pos;

//Set the X, Y, W, and H for the Rectangle
bkgd1Pos.x = 0;
bkgd1Pos.y = -768;
bkgd1Pos.w = 1024;
bkgd1Pos.h = 768;

//create the SDL_Rectangle for the texture's position and size -x,y,w,h
SDL_Rect bkgd2Pos;

//Set the X, Y, W, and H for the Rectangle
bkgd2Pos.x = 0;
bkgd2Pos.y = -768;
bkgd2Pos.w = 1024;
bkgd2Pos.h = 768;

//set speed for background
int bkgdSpeed = 100;

//set temp variables to hold movement 1
float BG1pos_X = 0, BG1_Y = 0;

//set temp variables to hold movement 2
float BG2pos_X = 0, BG2_Y = 0;

//create cursor
stringCURSORpath = s_cwd_images +"/cursor.png";

// create a SDL surface to hold the background image
surface = IMG_LOAD(CURSORpath.c_str());

// create a SDL texture - background 1
SDL_Texture *cursor;

//place surace into texture
cursor = SDL_CreateTextureFromSurface(renderer, surface);

//create the SDL_Cursor for the texture's position and size -x,y,w,h
SDL_Rect cursorPos;

//Set the X, Y, W, and H for the Cursor
cursorPos.x = 0;
cursorPos.y = 0;
cursorPos.w = 64;
cursorPos.h = 64;

// set up Game controller variable
SDL_GameController *gGameController = NULL;

// Open controller
//gGameController = SDL_


while(menu)
{
	//set up frame rate for the section, or CASE
	thisTime + SDL_GetTicks();
	deltaTime = (float)(thisTime - lastTime)/1000;
	lastTime = thisTime;


	//check for input events
	//if(SDL)_PollEvent

//update

//Update background 1
BG1pos_Y += (bkgdSpeed * 1) * deltaTime;

//set the new bkgd position
bkgd1Pos.y = (int)(BG1Pos_Y + 0.5f);

//reset when off the bottom of the screen
if(bkgd1Pos.y >= 768){

	bkgd1Pos.y = -768;

	BG1pos_Y = bkgd1Pos.y;
}

//Update background 2
BG2pos_Y += (bkgdSpeed * 1) * deltaTime;

//set the new bkgd position
bkgd2Pos.y = (int)(BG2Pos_Y + 0.5f);

//reset when off the bottom of the screen
if(bkgd2Pos.y >= 768){

	bkgd2Pos.y = -768;

	BG2pos_Y = bkgd2Pos.y;
}

//Start drawing

//Clear SDL renderer
SDL_RenderClear(renderer);

//Draw the bkgd image 1
SDL_RenderCopy(renderer, bkgd1, NULL, &bkgd1Pos);

//Draw the bkgd image 2
SDL_RenderCopy(renderer, bkgd2, NULL, &bkgd2Pos);

//SDL Render present
SDL_RenderPresent(renderer);

};
break;

    // The window is open: could enter program loop here (see SDL_PollEvent())
    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}







