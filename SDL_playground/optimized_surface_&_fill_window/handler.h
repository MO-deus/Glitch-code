
#pragma once

#ifndef SDL_HANDLER_H
#define SDL_HANDLER_H



#include<iostream>	// for handling i/o streams and displaying errors
#include <stdio.h>	// for printing errors on console , use it when using printf()
#include "SDL.h"

// constants :
constexpr int WINDOW_RUNNING = 1L;			// 'L' to tell the compiler not to truncate the value, 
constexpr int WINDOW_HEIGHT = 480L;			// 'L' means long data_type will be used
constexpr int WINDOW_WIDTH = 640L;
constexpr bool IS_WINDOW_RUNNING = true;	// flag for window running(true) or not(false)

// global variables : 
SDL_Window* Gwindow = NULL;				// Declaring the window, which will be used to render 
SDL_Surface* Gsurface = NULL;			// a surface is a layer containing an image, 
										// which can be loaded from a file or an image inside the window
SDL_Surface* G_surface_img = NULL;		// a surface is a layer containing an image
SDL_Event G_event_handler;	

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
			printf("Window cannot be created. SDL Error : %s \n", SDL_GetError());
			success_flag = false;
		}

		else {
			// takes the surface from the current window to write to the surface 
			Gsurface = SDL_GetWindowSurface(Gwindow);
		}

		return success_flag;
	}
}

bool EndSDL()
{
	// destroys the specified window
	SDL_DestroyWindow(Gwindow);

	// quits all the subsystem 
	SDL_Quit();

	return true;
}

SDL_Surface* LoadSurface(std::string path)
{
	// surface for getting the image at the time of loading in the format of the window
	// in order to decrease the number of time an image is loaded(pixel by pixel) on a surface.
	SDL_Surface* optimized_file_surface = NULL;

	SDL_Surface* file = SDL_LoadBMP(path.c_str());
	if (file == NULL)
	{
		printf("Unable to get image on screen from path %s. Error : %s \n", path.c_str(), SDL_GetError());
	}

	else 
	{
		optimized_file_surface = SDL_ConvertSurface(file, file->format, 0);
		if (optimized_file_surface == NULL)
		{
			printf("Unable to get the optimized surface. Error : %s \n", SDL_GetError());
		}
		// free the unwanted surface of the image (copy)
		SDL_FreeSurface(file);
	}
	

	return optimized_file_surface;
}

bool LoadMedia()
{
	bool success_flag = true;

	G_surface_img = LoadSurface("eugen_abstract.bmp");
	if (G_surface_img == NULL)
	{
		printf("Unable to get the image \n");
		success_flag = false;
	}

	return success_flag;
}



#endif // !SDL_HANDLER_H