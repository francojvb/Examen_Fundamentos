#pragma once
#include <SDL\SDL.h>
#include "Camera2D.h"
#include "IGameScreen.h"
#include "GLS_Program.h"
#include "Window.h"
#include "GLTexture.h"
#include "SpriteBacth.h"
#include "Level.h"
#include "Zombie.h"
#include "Player.h"
#include "Background.h"
#include "InputManager.h"
#include <vector>
#include <GL\glew.h>
#include <SDL\SDL_mixer.h>
#include "SpriteFont.h"
#include "Button.h"
#include <time.h>

class GamePlayScreen : public IGameScreen
{
private:
	GLS_Program _program;
	Camera2D _camera;
	Window* _window = nullptr;
	SpriteBacth _spriteBatch;
	GLTexture _texture;
	InputManager _inputManager;
	vector<Level*> _levels;
	vector<Zombie*> _zombies;
	Player* _player;
	int _currenLevel;	
	SpriteFont* spriteFont;
	Background* _background;
	time_t start;	
	int count = 0;
	int maxpuntaje=0;

	bool _gamePlay;
	bool _gameRetry;
	void updateAgents();

public:
	GamePlayScreen(Window* window);
	~GamePlayScreen();

	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;
	virtual void draw()override;
	virtual void update()override;
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;
	void checkInput();
	void updatePuntaje(int tecla, int tipo);

};

