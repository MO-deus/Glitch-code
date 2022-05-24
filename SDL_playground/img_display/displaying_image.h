
#pragma once

#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H



#include<iostream>	// for handling i/o streams and displaying errors
#include <stdio.h>	// for printing errors on console , use it when using printf()
#include "SDL.h"

constexpr int WINDOW_RUNNING = 1L;		// 'L' to tell the compiler not to truncate the value, 
constexpr int WINDOW_HEIGHT = 480L;		// 'L' means long data_type will be used
constexpr int WINDOW_WIDTH = 640L;

SDL_Window* Gwindow = NULL;			// Declaring the window, which will be used to render 
SDL_Surface* Gsurface = NULL;		// a surface is a layer containing an image, 
									// which can be loaded from a file or an image inside the windo
SDL_Surface* G_surface_img = NULL;		// a surface is a layer containing an image, 

#include<iostream>	// for handling i/o streams and displaying errors
#include <stdio.h>	// for printing errors on console , use it when using printf()
#include "SDL.h"

bool init()
{
	bool success_flag = true;
	// Initializing SDL [for video]
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to initialize SDL. SDL error : %s\n", SDL_GetError());
		success_flag = false;
	}

	else {
		// creates a window 
		Gwindow = SDL_CreateWindow("foo's tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (Gwindow == NULL)
		{
			printf("Window cannot be created. SDL Error : %s", SDL_GetError());
			success_flag = false;
		}

		else {
			// takes the surface from the current window to write to the surface 
			Gsurface = SDL_GetWindowSurface(Gwindow);
		}

		return success_flag;
	}
}

bool LoadMedia()
{
	bool success_flag = true;

	// Loads an bmp image into the surface
	// the directory is where .vcxproj is located
	G_surface_img = SDL_LoadBMP("eugen_abstract.bmp");

	if (G_surface_img == NULL)
	{
		printf("Unable to load image. Error : %s", SDL_GetError());
		success_flag = false;
	}
	return success_flag;
}

bool EndSDL()
{
	// destroys the specified window
	SDL_DestroyWindow(Gwindow);

	// quits all the subsystem 
	SDL_Quit();

	return true;
}



#endif // !SDL_HANDLER_H