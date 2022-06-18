
#include "SDLHandler.h"

int main(int argc, char* argv[])		// for comapatibility with other platforms 
{



	if (!init())
	{
		printf("Unable to create/initialize window.\n");
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

			// clearing the window with the 
			SDL_SetRenderDrawColor(G_renderer, 255, 255, 0, 255);
			SDL_RenderClear(G_renderer);

			SDL_Rect rect_fill = { WINDOW_WIDTH / 4,WINDOW_HEIGHT / 4, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };

			// filled rectangle
			SDL_SetRenderDrawColor(G_renderer, 0x00, 0x00, 0xff, 0xff);
			SDL_RenderFillRect(G_renderer, &rect_fill);

			// outline rect
			SDL_Rect rect_outline = { WINDOW_WIDTH / 6,WINDOW_HEIGHT / 6, WINDOW_WIDTH * 2 / 3, WINDOW_HEIGHT * 2 / 3 };
			SDL_SetRenderDrawColor(G_renderer, 0xff, 0x00, 0xff, 0xff);
			SDL_RenderDrawRect(G_renderer, &rect_outline);

			// Drawing a horizontal line 
			SDL_SetRenderDrawColor(G_renderer, 0x00, 0x00, 0x00, 0xff);
			SDL_RenderDrawLine(G_renderer, 0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2);
			SDL_RenderPresent(G_renderer);
		}

	}

OUT:
	EndSDL();
	return 0;
}