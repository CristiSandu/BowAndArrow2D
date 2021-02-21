#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>
#include "Arrow.h"
#include "Bow.h"
#include "Shuriken.h"
#include "Balloon.h"
#include "PowerBar.h"
#include <vector>
#include <cstdio>
#include <ctime>


class Tema1 : public SimpleScene
{
	public:
		Tema1();
		~Tema1();

	void Init() override;
	int spaceBow = 100;
	int scale = 75;
	glm::ivec2 resolution;
	GLfloat degre, arrowSpeed = 0, translationx = 25, translationy = 250, translationyArrow = 250, arrowX = 100, squer_l = 100, scaleX = 1, scaleY = 1;
	int verify = 0;
	std::clock_t start,startArrow, startShuriken, startLife;
	std::vector<glm::vec4> arrowsCoord;
	std::vector<glm::vec4> baloonsCoord;
	std::vector<glm::vec4> shurikenCoord;
	std::vector<glm::vec4> lifeCoord;
	GLfloat degre2;

	int colisionBowCheck= 0;
	int lives = 3;
	int score = 0;
	float powerBarStartX = 30, powerBarStartY = 50;
	float powerBarStartX2 = 2;
	float powerBarENDX =175, powerBarENDY = 50;
	float heartY = 650 , heartX = 20, defaze = 40;
	

	GLfloat baloonX = 0, balloonY = 0;

	void ArrowRelese(GLfloat relese);

private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;
	void RanderScene(float deltaTimeSeconds);
	void RanderFinalSceen();
	void RanderPowerBar(float detlaTimeSeconds);
	void RanderPowerLine(float detlaTimeSeconds);
	void RanderPowerHeart(float deltaTImeSeconds);
	void RanderLife(float deltaTImeSeconds);
	void CheckColision();
	void RanderArrow(float deltaTimeSeconds);
	void RanderBow(float deltaTimeSeconds);
	void RanderShuricken(float deltaTimeSeconds);
	void RanderBalloon(float deltaTimeSeconds);
	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;
protected:
	Arrow* arrow;
	Bow* bow;
	Shuriken* shuriken;
	Balloon* balloon;
	PowerBar* powerBar;


	
	glm::mat3 modelMatrix ;
	glm::mat3 modelMatrixR;

	float translateX, translateY;
	//float scaleX, scaleY;
	float angularStep;
	GLenum polygonMode;

};