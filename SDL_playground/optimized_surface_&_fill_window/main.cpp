
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

						}

						SDL_Rect stretch_rect;
						stretch_rect.x = 0;
						stretch_rect.y = 0;
						stretch_rect.w = WINDOW_WIDTH;
						stretch_rect.h = WINDOW_HEIGHT;

										// src			 // destination
						SDL_BlitScaled(G_surface_img, NULL, Gsurface, &stretch_rect);
						SDL_UpdateWindowSurface(Gwindow);

					}
				
				}

			}	
	
	OUT :
	EndSDL();
	return 0;
}