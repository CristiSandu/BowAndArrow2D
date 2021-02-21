#pragma once
#include <Core/Engine.h>

class Balloon {
public:
	Balloon();
	~Balloon();

	Mesh* GetBalloon();

	Mesh* GetRope();

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;
	Mesh* shuriken;
	int nrPCT=100;
	
	int spaceBow = 360;
private:
	Mesh* balloon;
	Mesh* balloon2;
	Mesh* rope;
};