
#include "handler.h"

int main(int argc, char *argv[])		// for comapatibility with other platforms 
{

	if (!init())
	{
		printf("Unable to create/initialize window ");
	}

	else
	{
		if (!LoadMedia())
		{
			printf("Unable to load media. Error : %s \n", SDL_GetError());
		}

		else
		{
			SDL_BlitSurface(G_surface_img, NULL, Gsurface, NULL);
			SDL_UpdateWindowSurface(Gwindow);
			SDL_Delay(10000);
		}

	}
	
	EndSDL();
	return 0;
}