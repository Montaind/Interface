#include <iostream>
#include "IShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <vector>
#include "SDL.h"
#include <cstdio>
typedef std::vector<IShape*> IShapeVector;
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int main(int argc, char* args[]) {
	IShapeVector shapes;
	shapes.push_back(new Rectangle(5, 5, 30, 10, Color(230, 255, 0, 0)));
	shapes.push_back(new Rectangle(50, 100, 200, 100, Color(230,255, 0, 0)));
	shapes.push_back(new Rectangle(300, 200, 100, 40, Color(107, 31, 89, 0)));
	/*shapes.push_back(new Circle(150, 300, 45, Color(83, 223, 191, 0)));
	shapes.push_back(new Triangle(*new Point(350, 241), *new Point(500, 300), *new Point(400, 400), Color(216, 239, 5, 0)));*/
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

				switch (e->type) {
				case SDL_KEYDOWN:
					switch (e->key.keysym.sym) {
					case SDLK_i:
						for (int i = 0; i < shapes.size(); i++) {
							if (shapes[i]->isSelected()) shapes[i]->scale(1.01);
						}
						break;
					case SDLK_o:
						for (int i = 0; i < shapes.size(); i++) {
							if (shapes[i]->isSelected()) shapes[i]->scale(0.99);
						}
						break;
					case SDLK_RIGHT:
						for (int i = 0; i < shapes.size(); i++) {
							if (shapes[i]->isSelected()) shapes[i]->relocate(0.01, 0);
						}
						break;
					case SDLK_LEFT:
						for (int i = 0; i < shapes.size(); i++) {
							if (shapes[i]->isSelected()) shapes[i]->relocate(-0.01, 0);
						}
						break;
					case SDLK_UP:
						for (int i = 0; i < shapes.size(); i++) {
							if (shapes[i]->isSelected()) shapes[i]->relocate(0, -0.01);
						}
						break;
					case SDLK_DOWN:
						for (int i = 0; i < shapes.size(); i++) {
							if (shapes[i]->isSelected()) shapes[i]->relocate(0, 0.01);
						}
						break;
					}
					break;
				case SDL_MOUSEMOTION:
					//printf("Mouse moved from (%d, %d), to (%d, %d)", e->motion.xrel, e->motion.yrel, e->motion.x, e->motion.y);
					//std::cout << "\n";
					break;
				case SDL_MOUSEBUTTONDOWN:
					printf("Mouse button %d pressed at (%d, %d)\n", e->button.button, e->button.x, e->button.y);
					for (int i = 0; i < shapes.size(); i++) {
						shapes[i]->setSelection(false);
						shapes[i]->setSelection(shapes[i]->contains(Point(e->button.x, e->button.y)));
					}
					break;
				case SDL_QUIT:
					exit(0);
				}




				/*SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);*/

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


	