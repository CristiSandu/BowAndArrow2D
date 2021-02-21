#include "Bow.h"

using namespace std;


Bow::Bow() {
	{

		bow = new Mesh("bow");

		std::vector<VertexFormat> vertices =
		{
			VertexFormat(corner, color),//0
		

		};

		std::vector<unsigned short> indices;

		GLfloat degree;

		for (int i = 0; i < spaceBow; i++)
		{
			degree = 3.14318531f * i / spaceBow;
			vertices.emplace_back(glm::vec3(scale * cos(degree), scale / 2 * sin(degree), 0), color);

			indices.push_back(i);
		}
		indices.push_back(spaceBow);


		bow->SetDrawMode(GL_LINE_LOOP);
		bow->InitFromData(vertices, indices);
	}

}


Bow::~Bow() {
	delete bow;
}


Mesh* Bow::GetBow() {
	return bow;
}