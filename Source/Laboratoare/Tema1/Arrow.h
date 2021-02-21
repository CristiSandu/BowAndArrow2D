#pragma once
#include <Component\SimpleScene.h>
#include <Core/Engine.h>

class Arrow {
public:
	Arrow();
	~Arrow();

	Mesh* GetArrow();
	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;
	Mesh* arrowM;
	glm::vec3  color = glm::vec3(0,0,0);
	
private:


};