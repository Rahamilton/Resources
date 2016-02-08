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

//int for background
int bkgdSpeed = 100;

//create the SDL rectangle for the background textures position and size background 1 and 2
SDL_Rect bkgd1Pos, bkgd2Pos;

//Background float vars for movement
float BG1pos_X = 0, BG1pos_Y = 0;
float BG2pos_X = 0, BG2pos_Y = 0;


//code for frame rate independence
float deltaTime = 0.0;
int thisTime = 0;
int lastTime = 0;

//move the background
void UpdateBackGround()
{

	//Update background 1
	BG1pos_Y += (bkgdSpeed * 1) * deltaTime;


	//set the new bkgd position
	bkgd1Pos.y = (int)(BG1pos_Y + 0.5f);

	//reset when off the bottom of the screen
	if(bkgd1Pos.y >= 768){

		bkgd1Pos.y = -768;

		BG1pos_Y = bkgd1Pos.y;
	}

	//Update background 2
	BG2pos_Y += (bkgdSpeed * 1) * deltaTime;

	//set the new bkgd position
	bkgd2Pos.y = (int)(BG2pos_Y + 0.5f);

	//reset when off the bottom of the screen
	if(bkgd2Pos.y >= 768){

		bkgd2Pos.y = -768;

		BG2pos_Y = bkgd2Pos.y;
	}

}


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

    //****** Create Background - Start ******

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
    SDL_FreeSurface(surface);

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


//************ Create Backgrounds - END *****************

//*********** Create Main Menu - Start **************

//************ Create Title - Start *****************

	string BKGDpath = s_cwd_images + "/title.png";

	//create a SDL surface to hold the background image
	SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

	//create a SDL texture
	SDL_Texture *title;

	//place surface into the texture bkgd1
	title = SDL_CreateTextureFromSurface(renderer, surface);

    //free the SDL surface
    SDL_FreeSurface(surface);

    //create SDL Rectangle for the title graphic
    SDL_Rect titlePos;

    //Set the X, Y, W, and H for the Rectangle
    titlePos.x = 264;
    titlePos.y = 0;
    titlePos.w = 532;
    titlePos.h = 71;

    //******** Title - End **********

    //******** 1 Player - Start ********

	string BKGDpath = s_cwd_images + "/one_n.png";

	//create a SDL surface to hold the background image
	SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

	//create a SDL texture
	SDL_Texture *players1N;

	//place surface into the texture bkgd1
	players1N = SDL_CreateTextureFromSurface(renderer, surface);

    //free the SDL surface
    SDL_FreeSurface(surface);

	string BKGDpath = s_cwd_images + "/one_o.png";

	//create a SDL surface to hold the background image
	SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

	//create a SDL texture
	SDL_Texture *players10;

	//place surface into the texture bkgd1
	players10 = SDL_CreateTextureFromSurface(renderer, surface);

    //free the SDL surface
    SDL_FreeSurface(surface);

    //create SDL Rectangle for the title graphic
    SDL_Rect players1NPos;

    //Set the X, Y, W, and H for the Rectangle
    players1NPos.x = 380;
    players1NPos.y = 261;
    players1NPos.w = 311;
    players1NPos.h = 42;

    //******** 1 Player - End ***********

    //******** 2 Player - Start ********

	string BKGDpath = s_cwd_images + "/two_n.png";

	//create a SDL surface to hold the background image
	SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

	//create a SDL texture
	SDL_Texture *players2N;

	//place surface into the texture bkgd1
	players2N = SDL_CreateTextureFromSurface(renderer, surface);

    //free the SDL surface
    SDL_FreeSurface(surface);

	string BKGDpath = s_cwd_images + "/two_o.png";

	//create a SDL surface to hold the background image
	SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

	//create a SDL texture
	SDL_Texture *players20;

	//place surface into the texture bkgd1
	players20 = SDL_CreateTextureFromSurface(renderer, surface);

    //free the SDL surface
    SDL_FreeSurface(surface);

    //create SDL Rectangle for the title graphic
    SDL_Rect players2NPos;

    //Set the X, Y, W, and H for the Rectangle
    players2NPos.x = 360;
    players2NPos.y = 243;
    players2NPos.w = 352;
    players2NPos.h = 42;

    //******** 2 Player - End ***********

    //******** Instructions - Start ********

	string BKGDpath = s_cwd_images + "/intruct_n.png";

	//create a SDL surface to hold the background image
	SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

	//create a SDL texture
	SDL_Texture *instructN;

	//place surface into the texture bkgd1
	instructN = SDL_CreateTextureFromSurface(renderer, surface);

    //free the SDL surface
    SDL_FreeSurface(surface);

	string BKGDpath = s_cwd_images + "/instruct_o.png";

	//create a SDL surface to hold the background image
	SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

	//create a SDL texture
	SDL_Texture *instruct0;

	//place surface into the texture bkgd1
	instruct0 = SDL_CreateTextureFromSurface(renderer, surface);

    //free the SDL surface
    SDL_FreeSurface(surface);

    //create SDL Rectangle for the title graphic
    SDL_Rect instructNPos;

    //Set the X, Y, W, and H for the Rectangle
    instructNPos.x = 351;
    instructNPos.y = 424;
    instructNPos.w = 374;
    instructNPos.h = 42;

    //******** Instructions - End ***********

    //******** Quit Game - Start ********

	string BKGDpath = s_cwd_images + "/quit_n.png";

	//create a SDL surface to hold the background image
	SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

	//create a SDL texture
	SDL_Texture *quitN;

	//place surface into the texture bkgd1
	quitN = SDL_CreateTextureFromSurface(renderer, surface);

    //free the SDL surface
    SDL_FreeSurface(surface);

	string BKGDpath = s_cwd_images + "/quit_o.png";

	//create a SDL surface to hold the background image
	SDL_Surface *surface = IMG_Load(BKGDpath.c_str());

	//create a SDL texture
	SDL_Texture *quit0;

	//place surface into the texture bkgd1
	quit0 = SDL_CreateTextureFromSurface(renderer, surface);

    //free the SDL surface
    SDL_FreeSurface(surface);

    //create SDL Rectangle for the title graphic
    SDL_Rect quitNPos;

    //Set the X, Y, W, and H for the Rectangle
    quitNPos.x = 391;
    quitNPos.y = 503;
    quitNPos.w = 288;
    quitNPos.h = 42;

    //******** Quit Game - End ***********

    //*********** Create Main Menu - End ****************

    //******** Create Cursor - Start **********

    string CURSORpath = s_cwd_images +"/Cursor.png";

    // create a SDL surface to hold the background image
    SDL_Surface *surface = IMG_Load(CURSORpath.c_str());

    // create a SDL texture - background 1
    SDL_Texture *cursor;

    //place surface into texture
    cursor = SDL_CreateTextureFromSurface(renderer, surface);

    //create the SDL_Cursor for the texture's position and size -x,y,w,h
    SDL_Rect cursorPos, activePos;

    //Set the X, Y, W, and H for the Cursor
    cursorPos.x = 0;
    cursorPos.y = 0;
    cursorPos.w = 58;
    cursorPos.h = 52;

    //Set the X, Y, W, and H for the Cursor
    activePos.x = 10;
    activePos.y = 10;
    activePos.w = 10;
    activePos.h = 10;

    //var from cursor speed
    int cursorSpeed = 400;

    //********** Create Cursor - End *************


// set up Game controller variable
SDL_GameController *gGameController = NULL;

// Open controller
gGameController = SDL_GameControllerOpen(0);

//turn on controller events
SDL_GameControllerEventState(SDL_ENABLE);

//SDL Event to handle input
SDL_Event event;

//state up our enum to handle the multiple gae states
enum GameState { MENU, INSTRUCTIONS, PLAYERS1, PLAYERS2, WIN, LOSE};

//var enum to track where we are in game
GameState gameState = MENU;

//bool values to allow movement through the individual states
bool menu, instructions, players1, players2, win, lose, quit;

while(!quit)
{

	switch(gameState)
	{
	case MENU:

		menu = true;
		cout << "The Game State is MENU" << endl;
		cout << "Press the A Button for Instructions" << endl;
		cout << "Press the B Button for 1 Player Game" << endl;
		cout << "Press the X Button for 2 Player Game" << endl;
		cout << "Press the Y Button for Quit Game" << endl;
		cout << endl;

		while(menu)
		{
			//set up frame rate for the section, or CASE
			thisTime + SDL_GetTicks();
			deltaTime = (float)(thisTime - lastTime)/1000;
			lastTime = thisTime;

			//check for input
			if(SDL_PollEvent(&event))
			{
				//see if the player closes the window via the windows 'X' button
				if(event.type == SDL_QUIT)
				{
					quit = true;
					menu = false;
					break;
				}

				//test for controller input
				switch(event.type)
				{

					case SDL_CONTROLLERBUTTONDOWN;

					//checks to see if this is controller 0
					if(event.cdevice.which == 0)
					{

						//if A button - instructions
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_A)
						{
							menu = false;
							gameState = INSTRUCTIONS;
						}

						//if B button - 1 player game
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_B)
						{
							menu = false;
							gameState = PLAYERS1;
						}
						//if X button 2 player game
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_X)
						{
							menu = false;
							gameState = PLAYERS2;
						}
						//if Y button - quit
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_Y)
						{
							menu = false;
							quit = true;
						}


					}// end joystick 0 check
					break;

				}// end button for input checks
			}// end menu poll event

			//update section
			UpdateBackGround();


			//Start drawing

			//Clear SDL renderer
			SDL_RenderClear(renderer);

			//Draw the bkgd image 1
			SDL_RenderCopy(renderer, bkgd1, NULL, &bkgd1Pos);

			//Draw the bkgd image 2
			SDL_RenderCopy(renderer, bkgd2, NULL, &bkgd2Pos);

			//Draw the title image
			SDL_RenderCopy(renderer, title, NULL, &titlePos);

			//Draw the 1 player image
			SDL_RenderCopy(renderer, players1N, NULL, &players1NPos);

			//Draw the 2 player image
			SDL_RenderCopy(renderer, players2N, NULL, &players2NPos);

			//Draw the 2 player image
			SDL_RenderCopy(renderer, instructN, NULL, &instructNPos);

			//Draw the Quit image
			SDL_RenderCopy(renderer, quitN, NULL, &quitNPos);

			//Draw the Cursor image
			SDL_RenderCopy(renderer, cursor, NULL, &cursorPos);

			//SDL Render present
			SDL_RenderPresent(renderer);

			};
			break;



		}// ends menu screen
		break;

	case INSTRUCTIONS:

		instructions = true;
		cout << "The Game State is INSTRUCTIONS" << endl;
		cout << "Press the A Button for Main Menu" << endl;
		cout << endl;

		while(instructions)
		{

			//set up frame rate for the section, or CASE
			thisTime + SDL_GetTicks();
			deltaTime = (float)(thisTime - lastTime)/1000;
			lastTime = thisTime;

			//check for input
			if(SDL_PollEvent(&event))
			{
				//see if the player closes the window via the windows 'X' button
				if(event.type == SDL_QUIT)
				{
					quit = true;
					instructions = false;
					break;
				}

				//test for controller input
				switch(event.type)
				{

				case SDL_CONTROLLERBUTTONDOWN;

					//checks to see if this is controller 0
					if(event.cdevice.which == 0)
					{

						//if A button - instructions
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_A)
						{
							instructions = false;
							gameState = MENU;
						}

					}// end joystick 0 check
					break;

				}// end button for input checks
			}// end instructions poll event

			//update section
			UpdateBackGround();

			//Clear SDL renderer
			SDL_RenderClear(renderer);

			//Draw the bkgd image 1
			SDL_RenderCopy(renderer, bkgd1, NULL, &bkgd1Pos);

			//Draw the bkgd image 2
			SDL_RenderCopy(renderer, bkgd2, NULL, &bkgd2Pos);

			//Draw the title image
			SDL_RenderCopy(renderer, title, NULL, &titlePos);

			//Draw the Cursor image
			SDL_RenderCopy(renderer, cursor, NULL, &cursorPos);

			//SDL Render present
			SDL_RenderPresent(renderer);





		}// ends instructions screen
		break;

	case PLAYERS1:

		players1 = true;
		cout << "The Game State is PLAYERS1" << endl;
		cout << "Press the A Button for WIN Screen" << endl;
		cout << "Press the B Button for LOSE Screen" << endl;
		cout << endl;

		while(players1)
		{
			//check for input
			if(SDL_PollEvent(&event))
			{
				//see if the player closes the window via the windows 'X' button
				if(event.type == SDL_QUIT)
				{
					quit = true;
					players1 = false;
					break;
				}

				//test for controller input
				switch(event.type)
				{

				case SDL_CONTROLLERBUTTONDOWN;

					//checks to see if this is controller 0
					if(event.cdevice.which == 0)
					{

						//if A button - WIN
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_A)
						{
							players1 = false;
							gameState = WIN;
						}

						//if B button - LOSE
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_B)
						{
							players1 = false;
							gameState = LOSE;
						}

					}// end joystick 0 check
					break;
				}// end button for input checks
			}// end players1 poll event
		}// ends players1 screen
		break;

	case PLAYERS2:

		players2 = true;
		cout << "The Game State is PLAYERS2" << endl;
		cout << "Press the A Button for WIN Screen" << endl;
		cout << "Press the B Button for LOSE Screen" << endl;
		cout << endl;

		while(players2)
		{
			//check for input
			if(SDL_PollEvent(&event))
			{
				//see if the player closes the window via the windows 'X' button
				if(event.type == SDL_QUIT)
				{
					quit = true;
					players2 = false;
					break;
				}

				//test for controller input
				switch(event.type)
				{

				case SDL_CONTROLLERBUTTONDOWN;

					//checks to see if this is controller 0
					if(event.cdevice.which == 0)
					{

						//if A button - WIN
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_A)
						{
							players2 = false;
							gameState = WIN;
						}

						//if B button - LOSE
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_B)
						{
							players2 = false;
							gameState = LOSE;
						}

					}// end joystick 0 check
					break;
				}// end button for input checks
			}// end players2 poll event
		}// ends players2 screen
		break;

	case WIN:

		win = true;
		cout << "The Game State is WIN" << endl;
		cout << "Press the A Button for Main Menu" << endl;
		cout << "Press the B Button to Quit" << endl;
		cout << endl;

		while(win)
		{
			//check for input
			if(SDL_PollEvent(&event))
			{
				//see if the player closes the window via the windows 'X' button
				if(event.type == SDL_QUIT)
				{
					quit = true;
					win = false;
					break;
				}

				//test for controller input
				switch(event.type)
				{

				case SDL_CONTROLLERBUTTONDOWN;

					//checks to see if this is controller 0
					if(event.cdevice.which == 0)
					{

						//if A button - MENU
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_A)
						{
							win = false;
							gameState = MENU;
						}

						//if B button - Quit
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_B)
						{
							win = false;
							quit = true;
						}

					}// end joystick 0 check
					break;
				}// end button for input checks
			}// end win poll event
		}// ends win screen
		break;

	case LOSE:

		lose = true;
		cout << "The Game State is LOSE" << endl;
		cout << "Press the A Button for Main Menu" << endl;
		cout << "Press the B Button to Quit" << endl;
		cout << endl;

		while(lose)
		{
			//check for input
			if(SDL_PollEvent(&event))
			{
				//see if the player closes the window via the windows 'X' button
				if(event.type == SDL_QUIT)
				{
					quit = true;
					lose = false;
					break;
				}

				//test for controller input
				switch(event.type)
				{

				case SDL_CONTROLLERBUTTONDOWN;

					//checks to see if this is controller 0
					if(event.cdevice.which == 0)
					{

						//if A button - MENU
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_A)
						{
							lose = false;
							gameState = MENU;
						}

						//if B button - QUIT
						if(event.cbutton.button == SDL_CONTROLLER_BUTTON_B)
						{
							lose = false;
							quit = true;
						}

					}// end joystick 0 check
					break;
				}// end button for input checks
			}// end lose poll event
		}// ends lose screen
		break;





	}//ends switch for gameState

}//ends game loop

    // The window is open: could enter program loop here (see SDL_PollEvent())
    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}







