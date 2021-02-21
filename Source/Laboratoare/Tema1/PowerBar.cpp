#include "PowerBar.h"


PowerBar::PowerBar() {
	{
		powerBar = new Mesh("powerBar");
		glm::vec3  color = glm::vec3((rand() % 100) / 100.0, (rand() % 100) / 100.0, (rand() % 100) / 100.0);

		std::vector<VertexFormat> vertices =
		{
			VertexFormat(corner, color),//0
			VertexFormat(corner + glm::vec3(75, 0, 0), color),//1
			VertexFormat(corner + glm::vec3(75, 10, 0), color),//3
			VertexFormat(corner + glm::vec3(0, 10, 0), color),//2

		};

		std::vector<unsigned short> indices = { 0,1,2,3,0 };
		powerBar->SetDrawMode(GL_LINE_LOOP);
		powerBar->InitFromData(vertices, indices);
	}

	{
		powerLine = new Mesh("powerLine");
		glm::vec3  color = glm::vec3((rand() % 100) / 100.0, (rand() % 100) / 100.0, (rand() % 100) / 100.0);

		std::vector<VertexFormat> vertices =
		{
			VertexFormat(corner, color),//0
			VertexFormat(corner + glm::vec3(2, 0, 0), color),//1
			VertexFormat(corner + glm::vec3(2, 10, 0), color),//2
			VertexFormat(corner + glm::vec3(0, 10, 0), color),//3
		};

		std::vector<unsigned short> indices = { 1,0,3,
			3,2,1 };
		powerLine->InitFromData(vertices, indices);
	}

	{
		heart = new Mesh("heart");
		glm::vec3  color = glm::vec3(1, 0, 0);

		std::vector<VertexFormat> vertices =
		{
			VertexFormat(corner, color),//0
			VertexFormat(corner + glm::vec3(10, 0, 0), color),//1
			VertexFormat(corner + glm::vec3(20, 10, 0), color),//2
			VertexFormat(corner + glm::vec3(20, 15, 0), color),//3
			VertexFormat(corner + glm::vec3(15, 20, 0), color),//4
			VertexFormat(corner + glm::vec3(10, 15, 0), color),//5
			VertexFormat(corner + glm::vec3(5, 20, 0), color),//6
			VertexFormat(corner + glm::vec3(0, 15, 0), color),//7
			VertexFormat(corner + glm::vec3(0, 10, 0), color),//7
		};

		std::vector<unsigned short> indices = { 2,1,8,
			8,7,2,
			2,7,3,
			4,3,5,
			5,7,6,7,8,1 };

		heart->InitFromData(vertices, indices);
	}

	{
		skull = new Mesh("skull");
		glm::vec3  color = glm::vec3(1, 1, 1);
		std::vector<VertexFormat> vertices =
		{
			VertexFormat(corner, color),//0
			VertexFormat(corner + glm::vec3(10, 0, 0), color),//1
			VertexFormat(corner + glm::vec3(25, 0, 0), color),//2
			VertexFormat(corner + glm::vec3(25, 10, 0), color),//3
			VertexFormat(corner + glm::vec3(35, 10, 0), color),//4
			VertexFormat(corner + glm::vec3(35, 40, 0), color),//5
			VertexFormat(corner + glm::vec3(0, 40, 0), color),//6
			VertexFormat(corner + glm::vec3(0, 10, 0), color),//7
			VertexFormat(corner + glm::vec3(10, 10, 0), color),//8
		};

		std::vector<unsigned short> indices = { 3,2,1,
			3,1,8,
			5,4,7,
			7,6,5,
		};

		skull->InitFromData(vertices, indices);
	}

	{
		eye = new Mesh("eye");

		glm::vec3  color = glm::vec3(1, 0, 0);
		std::vector<VertexFormat> vertices =
		{
			VertexFormat(corner, color),//0
			VertexFormat(corner + glm::vec3(10, 0, 0), color),//1
			VertexFormat(corner + glm::vec3(10, 10, 0), color),//2
			VertexFormat(corner + glm::vec3(0, 10, 0), color),//3

		};

		std::vector<unsigned short> indices = { 2,1,0,
			0,3,2,
		};

		eye->InitFromData(vertices, indices);
	}

}

PowerBar::~PowerBar() {
	delete powerLine;
	delete powerBar;
}

Mesh* PowerBar::GetPowerBar() {
	return powerBar;
}

Mesh* PowerBar::GetPowerLine() {
	return powerLine;
}

Mesh* PowerBar::GetPowerHeart() {
	return heart;
}

Mesh* PowerBar::GetSkull() {
	return skull;
}

Mesh* PowerBar::GetEye() {
	return eye;
}