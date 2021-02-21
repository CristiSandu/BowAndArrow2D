#include "RanderItems.h"

#include <Core/Engine.h>
#include <iostream>

Mesh* RanderItems::CreateArrow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),//0
		VertexFormat(corner + glm::vec3(5, 0, 0), color),//1
		VertexFormat(corner + glm::vec3(10, 0, 0), color),//2
		VertexFormat(corner + glm::vec3(70, 0, 0), color),//3
		VertexFormat(corner + glm::vec3(80, 0, 0), color),//4

		VertexFormat(corner + glm::vec3(0, -2.5, 0), color),//5
		VertexFormat(corner + glm::vec3(60, -5, 0), color),//6
		VertexFormat(corner + glm::vec3(60, 5, 0), color),//7
		VertexFormat(corner + glm::vec3(0, 2.5, 0), color),//8
		VertexFormat(corner + glm::vec3(9, 0.3, 0), color),//9
		VertexFormat(corner + glm::vec3(9, -0.3, 0), color),//10
		VertexFormat(corner + glm::vec3(70, 0.3, 0), color),//11
		VertexFormat(corner + glm::vec3(70, -0.3, 0), color),//12


	};

	Mesh* arrow = new Mesh(name);
	std::vector<unsigned short> indices = { 
		1,5,2,
		1,8,2,
		9,10,11,
		11,10,12,
		4,7,3,
		3,6,4
		};

	if (!fill) {
		arrow->SetDrawMode(GL_LINE_LOOP);

	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	arrow->InitFromData(vertices, indices);
	return arrow;
}

Mesh* RanderItems::CreateBow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, int spaceBow, int scale)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),//0
	};

	std::vector<unsigned short> indices;

	GLfloat degree;

	for (int i = 0; i < spaceBow; i++)
	{
		degree = 3.14318531f * i / spaceBow;
		vertices.emplace_back(glm::vec3(scale * cos(degree), scale/2 * sin(degree), 0), color);
		
		indices.push_back(i);
	}
	indices.push_back(spaceBow);



	Mesh* bow = new Mesh(name);

	if (!fill) {
		bow->SetDrawMode(GL_LINE_LOOP);

	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	bow->InitFromData(vertices, indices);
	return bow;
}


Mesh* RanderItems::CreateShuriken(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, int spaceBow, int scale)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),//0
		VertexFormat(corner + glm::vec3(length/2, 0, 0), color),//1
		VertexFormat(corner + glm::vec3(length, 0, 0), color),//2

		VertexFormat(corner + glm::vec3(length, length/2, 0), color),//3
		VertexFormat(corner + glm::vec3(length/2, length/2, 0), color),//4
		VertexFormat(corner + glm::vec3(0, length/2, 0), color),//5

		VertexFormat(corner + glm::vec3(0,length, 0), color),//6
		VertexFormat(corner + glm::vec3(length/2,length, 0), color),//7
		VertexFormat(corner + glm::vec3(length,length, 0), color),//8
	};

	std::vector<unsigned short> indices = {
		4,5,0,
		4,3,8,
		4,7,6,
		4,1,2
	};

	Mesh* Shuriken = new Mesh(name);

	if (!fill) {
	}
	else {
		indices.push_back(0);
		indices.push_back(2);
	}

	Shuriken->InitFromData(vertices, indices);
	return Shuriken;
}

Mesh* RanderItems::CreateBalloon(std::string name, glm::vec3 leftBottomCorner, float x, float y, glm::vec3 color, bool fill, int spaceBow, int scale)
{
	glm::vec3 corner = leftBottomCorner;

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
	
	std::vector<unsigned short> indices = {1,2,3,4,5,6
										   ,7};
	GLfloat degree, DEG2RAD = 3.14159 / 180.0;
	for (int i = 9; i < spaceBow + 10; i++)
	{
		degree = i * DEG2RAD;
		vertices.emplace_back(glm::vec3(5 +y * cos(degree), 90 + x * sin(degree), 0), color);
		std::cout << y * cos(degree)<< ","<< x * sin(degree) << std::endl;
		indices.push_back(i);
		std::cout << i<< std::endl;

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


	Mesh* balloon = new Mesh(name);

	if (!fill) {
			balloon->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	balloon->InitFromData(vertices, indices);
	return balloon;
}