#include<SFML/Graphics.hpp>
#include"Game.h"
#include<iostream>

constexpr auto WINDOW_WIDTH = 640;
constexpr auto WINDOW_HEIGHT = 480;

int main(int argc, char** argv[]) {
	// Program entry point.
	Game game; // Creating our game object.
	while (!game.GetWindow()->IsDone()) {
		// Game loop.
		game.HandleInput();
		game.Update();
		game.Render();
	}

	return 0;
}