#pragma once
#include "InputManager.h"
#include "Camera2D.h"
#include "Music.h"
#include "Zombie.h"
#include "Agent.h"

#include <vector>

class Zombie;

class Player: public Agent
{
private:
	InputManager* _inputManager;
	Camera2D* _camera;

public:
	std::string spriteActual;
	Player();
	~Player();
	void init(float speed, glm::vec2 position, InputManager* inputManager, Camera2D* camera);
	void update(const std::vector<std::string>& levelData, std::vector<Zombie*>& zombies, glm::vec2 player_position);
	void collideWithZombies(std::vector<Zombie*>& zombies);
};

