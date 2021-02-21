#include "Balloon.h"


Balloon::Balloon() {
	{
		balloon = new Mesh("balloon");
		glm::vec3  color = glm::vec3((rand() % 100) / 100.0, (rand() % 100) / 100.0, (rand() % 100) / 100.0);
		std::vector<VertexFormat> vertices =
		{
			VertexFormat(corner, color),//0
			VertexFormat(corner + glm::vec3(10, 0, 0), color),//1
			VertexFormat(corner + glm::vec3(0, 5, 0), color),//2
			VertexFormat(corner + glm::vec3(10, 15, 0), color),//3
			VertexFormat(corner + glm::vec3(0, 20, 0), color),//4
			VertexFormat(corner + glm::vec3(5, 30, 0), color),//5
			VertexFormat(corner + glm::vec3(15, 30, 0), color),//6
			VertexFormat(corner + glm::vec3(5, 40, 0), color),//7
			VertexFormat(corner + glm::vec3(-5, 30, 0), color),//8
			VertexFormat(corner + glm::vec3(5, 85, 0), color),//9

		};

		std::vector<unsigned short> indices = { 1,2,3,4,5,6
											   ,7 };
		GLfloat degree, DEG2RAD = 3.14159 / 180.0;
		for (int i = 9; i < spaceBow + 10; i++)
		{
			degree = i * DEG2RAD;
			vertices.emplace_back(glm::vec3(5 + (squareSide / 4) * cos(degree), 90 + (squareSide / 2) * sin(degree), 0), color);
			indices.push_back(i);
		}

		indices.push_back(spaceBow + 10);
		indices.push_back(9);

		indices.push_back(7);

		indices.push_back(8);
		indices.push_back(5);
		indices.push_back(4);
		indices.push_back(3);
		indices.push_back(2);
		indices.push_back(1);


		balloon->SetDrawMode(GL_LINE_LOOP);
		balloon->InitFromData(vertices, indices);
	}

	{
		balloon2 = new Mesh("balloon2");
		
		glm::vec3  color = glm::vec3((rand() % 100) / 100.0, (rand() % 100) / 100.0, (rand() % 100) / 100.0);

		std::vector<VertexFormat> vertices
		{
			VertexFormat(glm::vec3(0, 0, 0), glm::vec3(2, 1, 1)),

		};
		std::vector<unsigned short> indices;

		GLfloat degree;

		for (int i = 0; i < nrPCT; i++)
		{
			degree = 6.28318531f * i / nrPCT;
			vertices.emplace_back(glm::vec3((squareSide / 4) * cos(degree), (squareSide / 2) * sin(degree), 0), glm::vec3((rand() % 100) / 100.0, (rand() % 100) / 100.0, (rand() % 100) / 100.0));
			indices.push_back(i);
		}

		indices.push_back(nrPCT);
		indices.push_back(1);
		balloon2->SetDrawMode(GL_TRIANGLE_FAN);
		balloon2->InitFromData(vertices, indices);

	}
	{
		rope = new Mesh("rope");
		glm::vec3  color = glm::vec3((rand() % 100) / 100.0, (rand() % 100) / 100.0, (rand() % 100) / 100.0);
		std::vector<VertexFormat> vertices =
		{
			VertexFormat(corner, color),//0
			VertexFormat(corner + glm::vec3(10, 0, 0), color),//1
			VertexFormat(corner + glm::vec3(15, 5, 0), color),//2
			VertexFormat(corner + glm::vec3(10, 10, 0), color),//3
			VertexFormat(corner + glm::vec3(15, 15, 0), color),//4
			VertexFormat(corner + glm::vec3(20, 20, 0), color),//5
			VertexFormat(corner + glm::vec3(15, 25, 0), color),//6
			VertexFormat(corner + glm::vec3(10, 30, 0), color),//7
			VertexFormat(corner + glm::vec3(20, 40, 0), color),//8
			VertexFormat(corner + glm::vec3(20, 45, 0), color),//9
			VertexFormat(corner + glm::vec3(30, 45, 0), color),//10
			VertexFormat(corner + glm::vec3(17, 60, 0), color),//11
			VertexFormat(corner + glm::vec3(5, 45, 0), color),//12
			VertexFormat(corner + glm::vec3(15, 45, 0), color),//13
			VertexFormat(corner + glm::vec3(0, 30, 0), color),//14
			VertexFormat(corner + glm::vec3(10, 20, 0), color),//15

			VertexFormat(corner + glm::vec3(0, 10, 0), color),//16
			VertexFormat(corner + glm::vec3(5, 5, 0), color),//17




		};

		std::vector<unsigned short> indices = {2,1,16,
		16,6,5,
			5,14,6,
			14,13,8,
			9,8,13,
			12,11,10,
		};
		

		rope->InitFromData(vertices, indices);
	}
}

Balloon::~Balloon() {
	delete balloon;
}

Mesh* Balloon::GetBalloon() {
	return balloon2;
}

Mesh* Balloon::GetRope() {
	return rope;
}