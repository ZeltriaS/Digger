#include "pch.h"
#pragma comment(lib,"xinput.lib")

// ReSharper disable once CppUnusedIncludeDirective
#include <iostream>
#include "Minigin.h"
#include "Game.h"

#pragma warning( push )  
#pragma warning( disable : 4100 )  
int main(int argc, char* argv[]) 
{
#pragma warning( pop )

	engine::Game game;
	game.Run();
    return 0;
}

