#pragma once
#include <Core/Engine.h>

class PowerBar {
public:

	PowerBar();
	~PowerBar();

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;
	Mesh* shuriken;

	int spaceBow = 360;
	
	Mesh* GetPowerBar();
	Mesh* GetPowerLine();
	Mesh* GetPowerHeart();
	Mesh* GetSkull();
	Mesh* GetEye();
private:
	Mesh* powerBar;
	Mesh* powerLine;
	Mesh* heart;
	Mesh* skull;
	Mesh* eye;


};