#pragma once
#include <Component\SimpleScene.h>
#include <Core/Engine.h>


class Bow {
public :
	Bow();
	~Bow();
	Mesh* GetBow();
	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;
	glm::vec3  color = glm::vec3(0,0,0);
	int spaceBow = 100;
	int scale = 75;
	Mesh* bow;

};