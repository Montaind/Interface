#include <iostream>
#include "IShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <vector>
#include "SDL.h"
#include <cstdio>
typedef std::vector<IShape*> IShapeVector;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	IShapeVector shapes;
	shapes.push_back(new Rectangle(5, 5, 30, 10));
	shapes.push_back(new Rectangle(50, 100, 200, 100));
	shapes.push_back(new Rectangle(300, 200, 100, 40));
	shapes.push_back(new Circle(150, 300, 45));
	shapes.push_back(new Triangle(*new Point(350, 241), *new Point(500, 300), *new Point(400, 400)));
    SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event* e = new SDL_Event();
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		printf("SDL doesnt work! SDL_Error: %s\n", SDL_GetError());
	}

	else
	{
		window = SDL_CreateWindow("Gitler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (window)
		{
			while (true)
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
				SDL_RenderClear(renderer);
				SDL_PollEvent(e);

				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

				for (int i = 0; i < shapes.size(); i++)
				{
					shapes[i]->draw(renderer);
				}

				SDL_RenderPresent(renderer);
			}
		}
		else
		{
			printf("Window cannot release! SDL_Error: %s\n", SDL_GetError());
		}
	}
	delete e;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}


	