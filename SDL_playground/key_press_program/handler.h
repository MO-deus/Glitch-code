
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

// enumeration for key_events
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//an array which contains pointers to all the KeyEvents
SDL_Surface* G_key_press_surfaces[KEY_PRESS_SURFACE_TOTAL];

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
	SDL_Surface* file = SDL_LoadBMP(path.c_str());
	if (file == NULL)
	{
		printf("Unable to get image on screen from path %s. Error : %s \n", path.c_str(), SDL_GetError());
	}

	return file;
}

bool LoadMedia()
{
	bool success_flag = true;

	// Loads an bmp image into the surface
	// the directory is where .vcxproj is located
	G_key_press_surfaces[KEY_PRESS_SURFACE_DEFAULT] = LoadSurface("keypresses/default.bmp");
	if (G_key_press_surfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Unable to get the image \n");
		success_flag = false;
	}

	G_key_press_surfaces[KEY_PRESS_SURFACE_UP] = LoadSurface("keypresses/up.bmp");
	if (G_key_press_surfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Unable to get the image \n");
		success_flag = false;
	}

	G_key_press_surfaces[KEY_PRESS_SURFACE_DOWN] = LoadSurface("keypresses/down.bmp");
	if (G_key_press_surfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("Unable to get the image \n");
		success_flag = false;
	}

	G_key_press_surfaces[KEY_PRESS_SURFACE_LEFT] = LoadSurface("keypresses/left.bmp");
	if (G_key_press_surfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Unable to get the image \n");
		success_flag = false;
	}

	G_key_press_surfaces[KEY_PRESS_SURFACE_RIGHT] = LoadSurface("keypresses/right.bmp");
	if (G_key_press_surfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Unable to get the image \n");
		success_flag = false;
	}

	return success_flag;
}



#endif // !SDL_HANDLER_H