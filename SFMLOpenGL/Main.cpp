#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GlU32.lib")
#pragma comment (lib, "glew32.lib")
#pragma comment (lib, "glew32s.lib")  

/// <summary>
/// Joshua Dunne
/// C00241588
/// </summary>

#include <Game.h>

int main(void)
{
	Game& game = Game();
	game.run();
}