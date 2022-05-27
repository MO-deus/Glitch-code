
#include "handler.h"

int main(int argc, char *argv[])		// for comapatibility with other platforms 
{


			if (!init())
			{
				printf("Unable to create/initialize window.\n");
			}

			else
			{
				if (!LoadMedia())
				{
					printf("Unable to load media. Error : %s \n", SDL_GetError());
				}

				else
				{
					G_surface_img = G_key_press_surfaces[KEY_PRESS_SURFACE_DEFAULT];

					// until the application is running 
					while (IS_WINDOW_RUNNING)
					{
						// SDL_PollEvent() works on an event queue
						// It reads from that queue and executes until the queue is empty 
						while (SDL_PollEvent(&G_event_handler) != 0)
						{
							if (G_event_handler.type == SDL_QUIT)
								//SDL_QUIT occurs when user X's out of the window
							{
								goto OUT;
							}

							// if a key is pressed
							else if (G_event_handler.type == SDL_KEYDOWN)
							{
								switch (G_event_handler.key.keysym.sym)
								{
								case SDLK_UP:
									G_surface_img = G_key_press_surfaces[KEY_PRESS_SURFACE_UP];
									break;

								case SDLK_DOWN:
									G_surface_img = G_key_press_surfaces[KEY_PRESS_SURFACE_DOWN];
									break;

								case SDLK_LEFT:
									G_surface_img = G_key_press_surfaces[KEY_PRESS_SURFACE_LEFT];
									break;

								case SDLK_RIGHT:
									G_surface_img = G_key_press_surfaces[KEY_PRESS_SURFACE_RIGHT];
									break;

								default:
									G_surface_img = G_key_press_surfaces[KEY_PRESS_SURFACE_DEFAULT];
									break;
								}
							}
						}
										// src			 // destination
						SDL_BlitSurface(G_surface_img, NULL, Gsurface, NULL);
						SDL_UpdateWindowSurface(Gwindow);

					}
				
				}

			}	
	
	OUT :
	EndSDL();
	return 0;
}