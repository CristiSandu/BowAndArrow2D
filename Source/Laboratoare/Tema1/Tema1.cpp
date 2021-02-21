#include "Tema1.h"

#include <vector>
#include <iostream>
#include "Transform2D.h"
#include "RanderItems.h"
#include <Laboratoare\Tema1\Transform2D.h>

using namespace std;


Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init()
{
	resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;

	arrow = new Arrow();
	bow = new Bow();
	shuriken = new Shuriken();
	balloon = new Balloon();
	powerBar = new PowerBar();


	start = std::clock();
	startArrow = std::clock();
	startShuriken = std::clock();



	// compute coordinates of square center
	float cx = corner.x + squareSide / 2;
	float cy = corner.y + squareSide / 2;

	// initialize tx and ty (the translation steps)
	translateX = 0;
	translateY = 0;

	// initialize sx and sy (the scale factors)
	scaleX = 1;
	scaleY = 1;

	// initialize angularStep
	angularStep = 0;
}

void Tema1::FrameStart()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{

	glClearColor(0, 128, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::vec2 positionCursor = window->GetCursorPosition();
	GLfloat mouseNouY = resolution.y - positionCursor.y;
	degre2 = atan((mouseNouY - translationy) / (positionCursor.x - translationx));

	if (lives == 0) {
		std::cout << "GAME OVER! ============================= Score: " << score << " \n\n";
		RanderFinalSceen();
	}
	else {

		if (verify == 1) {
			arrowX += 100 * deltaTimeSeconds;
		}

		if (arrowX > 1280)
		{
			verify = 0;
			arrowX = 100;
			translationyArrow = translationy;
		}


		int w = rand() % 2;
		double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		if (duration >= 2) {
			baloonsCoord.push_back(glm::vec4((rand() % 480 + 800), 0, 1, w));
			start = std::clock();
		}

		duration = (std::clock() - startShuriken) / (double)CLOCKS_PER_SEC;
		if (duration >= 5) {
			shurikenCoord.push_back(glm::vec4(1280, (rand() % 780), 1, 1));
			startShuriken = std::clock();
		}
		RanderScene(deltaTimeSeconds);

	}
}

void Tema1::FrameEnd()
{
}


void Tema1::RanderScene(float deltaTimeSeconds) {
	//arrow Transaltion / Render
	RanderArrow(deltaTimeSeconds);

	//Bow Transaltion / Render
	RanderBow(deltaTimeSeconds);

	//Shuriken Transaltion / Render
	RanderShuricken(deltaTimeSeconds);

	//balloon Transaltion / Render
	RanderBalloon(deltaTimeSeconds);

	//rander powerindicator
	RanderPowerBar(deltaTimeSeconds);
	RanderPowerLine(deltaTimeSeconds);

	//rander lives
	RanderPowerHeart(deltaTimeSeconds);

	//check colision 
	CheckColision();
}

void Tema1::RanderFinalSceen() {

	float skullCenterX = 600;
	float skullCenterY = 300;

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(skullCenterX + 10, skullCenterY + 70);
	modelMatrix *= Transform2D::Scale(3, 3);
	RenderMesh2D(powerBar->GetEye(), shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(skullCenterX + 64, skullCenterY + 70);
	modelMatrix *= Transform2D::Scale(3, 3);
	RenderMesh2D(powerBar->GetEye(), shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(skullCenterX, skullCenterY);
	modelMatrix *= Transform2D::Scale(3, 3);
	RenderMesh2D(powerBar->GetSkull(), shaders["VertexColor"], modelMatrix);
}

void Tema1::RanderPowerBar(float detlaTimeSeconds) {

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(30, 50);
	modelMatrix *= Transform2D::Scale(2, 2);
	RenderMesh2D(powerBar->GetPowerBar(), shaders["VertexColor"], modelMatrix);

}


void Tema1::RanderPowerLine(float detlaTimeSeconds) {

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(30, powerBarStartY);
	modelMatrix *= Transform2D::Scale(powerBarStartX2 / 2, 2);
	RenderMesh2D(powerBar->GetPowerLine(), shaders["VertexColor"], modelMatrix);

}

void Tema1::RanderPowerHeart(float deltaTImeSeconds) {

	if (lives == 3) {
		//if i have 3 lives rander 3 hearts
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(heartX, heartY);
		modelMatrix *= Transform2D::Scale(2, 2);
		RenderMesh2D(powerBar->GetPowerHeart(), shaders["VertexColor"], modelMatrix);


		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(heartX + defaze, heartY);
		modelMatrix *= Transform2D::Scale(2, 2);
		RenderMesh2D(powerBar->GetPowerHeart(), shaders["VertexColor"], modelMatrix);
		modelMatrix = glm::mat3(1);

		modelMatrix *= Transform2D::Translate(heartX + defaze * 2, heartY);
		modelMatrix *= Transform2D::Scale(2, 2);
		RenderMesh2D(powerBar->GetPowerHeart(), shaders["VertexColor"], modelMatrix);

		startLife = std::clock();
	}
	else if (lives == 2)
	{
		//if i have 3 lives rander 2 hearts and 
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(heartX, heartY);
		modelMatrix *= Transform2D::Scale(2, 2);
		RenderMesh2D(powerBar->GetPowerHeart(), shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(heartX + defaze, heartY);
		modelMatrix *= Transform2D::Scale(2, 2);
		RenderMesh2D(powerBar->GetPowerHeart(), shaders["VertexColor"], modelMatrix);


		//push extra lives to come to player direction  
		float duration = (std::clock() - startLife) / (double)CLOCKS_PER_SEC;
		if (duration >= 10) {
			lifeCoord.push_back(glm::vec4(1280, (rand() % 780), 1, 1));
			startLife = std::clock();
		}
		RanderLife(deltaTImeSeconds);
	}
	else {
		//if i have 1 lives rander skull
		RanderFinalSceen();

		// rander last heart and 
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(heartX, heartY);
		modelMatrix *= Transform2D::Scale(2, 2);
		RenderMesh2D(powerBar->GetPowerHeart(), shaders["VertexColor"], modelMatrix);

		//push extra lives to come to player direction  
		float duration = (std::clock() - startLife) / (double)CLOCKS_PER_SEC;
		if (duration >= 10) {
			lifeCoord.push_back(glm::vec4(1280, (rand() % 780), 1, 1));
			startLife = std::clock();
		}

		RanderLife(deltaTImeSeconds);
	}
}


void Tema1::CheckColision() {
	//check colision with baloons
	for (int i = 0; i < arrowsCoord.size(); i++)
	{
		for (int j = 0; j < baloonsCoord.size(); j++)
		{
			GLfloat first = (arrowsCoord[i].x + 40) - baloonsCoord[j].x;
			GLfloat second = (arrowsCoord[i].y) - baloonsCoord[j].y;

			if (((first * first) / (25 * 25)) + ((second * second) / (50 * 50)) <= 1)
			{
				if (baloonsCoord[j].z == 1) {
					baloonsCoord[j].z = 0.90;
					if (baloonsCoord[j].w == 1)
						score += 30;
					else
					{
						if (score <= 0)
							score -= 30;
					}

				}
			}
		}
	}

	//check colision with shuriken
	for (int i = 0; i < arrowsCoord.size(); i++)
	{
		for (int j = 0; j < shurikenCoord.size(); j++)
		{
			GLfloat first = (arrowsCoord[i].x - 30) - shurikenCoord[j].x;
			GLfloat second = (arrowsCoord[i].y) - shurikenCoord[j].y;

			if (((first * first) / (50 * 50)) + ((second * second) / (50 * 50)) <= 1)
			{
				if (shurikenCoord[j].z == 1) {
					shurikenCoord[j].z = 0.90;
					score += 40;
				}

			}
		}
	}


	//check colision shuriken with player
	for (int i = 0; i < shurikenCoord.size(); i++)
	{
		GLfloat firstS = translationx - shurikenCoord[i].x;
		GLfloat secondS = translationy - shurikenCoord[i].y;
		if (((firstS * firstS) / (37.5 * 37.5)) + ((secondS * secondS) / (75 * 75)) <= 1)
		{
			lives--;
			shurikenCoord[i].x -= 1000;
		}
	}

	//check colision extre life with player
	for (int i = 0; i < lifeCoord.size(); i++)
	{
		GLfloat firstS = translationx - lifeCoord[i].x;
		GLfloat secondS = translationy - lifeCoord[i].y;
		if (((firstS * firstS) / (37.5 * 37.5)) + ((secondS * secondS) / (75 * 75)) <= 1)
		{
			lives++;
			lifeCoord[i].x -= 1000;
		}
	}


}

void Tema1::RanderArrow(float deltaTimeSeconds) {

	for (int i = 0; i < arrowsCoord.size(); i++)
	{
		modelMatrix = glm::mat3(1);
		arrowsCoord[i].x += cos(arrowsCoord[i].z) * deltaTimeSeconds * arrowsCoord[i].w * (450 / 100);
		arrowsCoord[i].y += sin(arrowsCoord[i].z) * deltaTimeSeconds * arrowsCoord[i].w * (450 / 100);
		modelMatrix *= Transform2D::Translate(arrowsCoord[i].x, arrowsCoord[i].y);
		modelMatrix *= Transform2D::Rotate(arrowsCoord[i].z);
		modelMatrix *= Transform2D::Scale(1, 1);
		Mesh* mes = arrow->GetArrow();
		RenderMesh2D(mes, shaders["VertexColor"], modelMatrix);
	}
}

void Tema1::RanderBow(float deltaTimeSeconds) {

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(translationx, translationy);
	modelMatrix *= Transform2D::Scale(1, 1);
	modelMatrix *= Transform2D::Rotate(-1.5708);
	modelMatrix *= Transform2D::Rotate(degre2);
	RenderMesh2D(bow->GetBow(), shaders["VertexColor"], modelMatrix);
}

void Tema1::RanderShuricken(float deltaTimeSeconds) {
	for (int i = 0; i < shurikenCoord.size(); i++)
	{
		if (shurikenCoord[i].z <= 0.99) {

			if (shurikenCoord[i].z >= 0) {
				shurikenCoord[i].z -= deltaTimeSeconds * 2;
			}

			shurikenCoord[i].y -= deltaTimeSeconds * 500;
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(shurikenCoord[i].x, shurikenCoord[i].y);
			modelMatrix *= Transform2D::Scale(1, 1);
			degre += deltaTimeSeconds;
			RenderMesh2D(shuriken->GetShuriken(), shaders["VertexColor"], modelMatrix);

		}
		else {
			shurikenCoord[i].x -= deltaTimeSeconds * 500;
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(shurikenCoord[i].x, shurikenCoord[i].y);
			modelMatrix *= Transform2D::Scale(1, 1);
			degre += deltaTimeSeconds;
			modelMatrix *= Transform2D::Translate(squer_l / 4.f, squer_l / 4.f);
			modelMatrix *= Transform2D::Rotate(degre);
			modelMatrix *= Transform2D::Translate(-squer_l / 4.f, -squer_l / 4.f);
			RenderMesh2D(shuriken->GetShuriken(), shaders["VertexColor"], modelMatrix);
		}
	}

}

void Tema1::RanderLife(float deltaTImeSeconds) {
	for (int i = 0; i < lifeCoord.size(); i++)
	{
		lifeCoord[i].x -= deltaTImeSeconds * 500;
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(lifeCoord[i].x, lifeCoord[i].y);
		modelMatrix *= Transform2D::Scale(2, 2);
		RenderMesh2D(powerBar->GetPowerHeart(), shaders["VertexColor"], modelMatrix);
	}
}

void Tema1::RanderBalloon(float deltaTimeSeconds) {

	for (int i = 0; i < baloonsCoord.size(); i++)
	{
		Mesh* mes = balloon->GetBalloon();
		Mesh* rope = balloon->GetRope();


		if (baloonsCoord[i].z <= 0.99) {

			if (baloonsCoord[i].z >= 0) {
				baloonsCoord[i].z -= deltaTimeSeconds * 2;
			}

			baloonsCoord[i].y -= 400 * deltaTimeSeconds;
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(baloonsCoord[i].x, baloonsCoord[i].y);
			modelMatrix *= Transform2D::Translate(squer_l / 2.f, squer_l / 2.f);
			modelMatrix *= Transform2D::Scale(baloonsCoord[i].z, baloonsCoord[i].z);
			modelMatrix *= Transform2D::Translate(-squer_l / 2.f, -squer_l / 2.f);

			modelMatrixR = glm::mat3(1);
			modelMatrixR *= Transform2D::Translate(baloonsCoord[i].x - 20, baloonsCoord[i].y - 95);
			modelMatrixR *= Transform2D::Translate(squer_l / 2.f, squer_l / 2.f);
			modelMatrixR *= Transform2D::Scale(baloonsCoord[i].z, baloonsCoord[i].z);
			modelMatrixR *= Transform2D::Translate(-squer_l / 2.f, -squer_l / 2.f);

			if (baloonsCoord[i].w == 0) {
				RenderMesh2D(mes, modelMatrix, glm::vec3(255, 242, 0));
				RenderMesh2D(rope, modelMatrixR, glm::vec3(255, 242, 0));
			}
			else
			{
				RenderMesh2D(mes, modelMatrix, glm::vec3(1, 0, 0));
				RenderMesh2D(rope, modelMatrixR, glm::vec3(1, 0, 0));
			}
		}
		else {
			baloonsCoord[i].y += 200 * deltaTimeSeconds;
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(baloonsCoord[i].x, baloonsCoord[i].y);
			modelMatrix *= Transform2D::Scale(1, 1);

			modelMatrixR = glm::mat3(1);
			modelMatrixR *= Transform2D::Translate(baloonsCoord[i].x - 20, baloonsCoord[i].y - 95);
			modelMatrixR *= Transform2D::Scale(0.8, 0.8);


			if (baloonsCoord[i].w == 0) {
				RenderMesh2D(mes, modelMatrix, glm::vec3(255, 242, 0));
				RenderMesh2D(rope, modelMatrixR, glm::vec3(255, 242, 0));
			}
			else
			{
				RenderMesh2D(mes, modelMatrix, glm::vec3(1, 0, 0));
				RenderMesh2D(rope, modelMatrixR, glm::vec3(1, 0, 0));
			}
		}
	}
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_W))
	{
		if (verify == 0) {
			translationyArrow += 150 * deltaTime;
			translationy += 300 * deltaTime;

		}
		else
		{
			translationy += 300 * deltaTime;
		}

		if (translationy >= 720)
		{
			translationy = 720;
		}
	}

	if (window->KeyHold(GLFW_KEY_S))
	{
		if (verify == 0) {
			translationyArrow -= 150 * deltaTime;
			translationy -= 300 * deltaTime;
		}
		else
		{
			translationy -= 300 * deltaTime;
		}

		if (translationy <= 0)
		{
			translationy = 0;
		}
	}

	if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
	{
		if (powerBarStartX <= powerBarENDX) {
			powerBarStartX += 150 * deltaTime;
			powerBarStartX2 += 150 * deltaTime;

		}

	}
}


void Tema1::ArrowRelese(GLfloat relese)
{

}

void Tema1::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_SPACE)
	{
		switch (polygonMode)
		{
		case GL_POINT:
			polygonMode = GL_FILL;
			break;
		case GL_LINE:
			polygonMode = GL_POINT;
			break;
		default:
			polygonMode = GL_LINE;
			break;
		}
	}
}

void Tema1::OnKeyRelease(int key, int mods)
{

}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{

}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{

}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	double duration = (std::clock() - startArrow) / (double)CLOCKS_PER_SEC;
	if (duration >= 1) {
		startArrow = std::clock();
		if (!window->MouseHold(GLFW_MOUSE_BUTTON_LEFT)) {

			arrowsCoord.push_back(glm::vec4(translationx, translationy, degre2, powerBarStartX));
		}
		powerBarStartX = 30;
		powerBarStartX2 = 2;
	}
	powerBarStartX = 30;
	powerBarStartX2 = 2;
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{

}

void Tema1::OnWindowResize(int width, int height)
{

}


