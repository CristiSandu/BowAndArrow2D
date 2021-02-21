#include "Shuriken.h"

Shuriken::Shuriken() {
	{
		std::vector<VertexFormat> vertices =
		{
			
			VertexFormat(corner, color),//0
			VertexFormat(corner + glm::vec3((squareSide / 2) / 2, 0, 0), color),//1
			VertexFormat(corner + glm::vec3((squareSide / 2), 0, 0), color),//2

			VertexFormat(corner + glm::vec3((squareSide / 2), (squareSide / 2) / 2, 0), color),//3
			VertexFormat(corner + glm::vec3((squareSide / 2) / 2, (squareSide / 2) / 2, 0), color),//4
			VertexFormat(corner + glm::vec3(0, (squareSide / 2) / 2, 0), color),//5

			VertexFormat(corner + glm::vec3(0,(squareSide / 2), 0), color),//6
			VertexFormat(corner + glm::vec3((squareSide / 2) / 2,(squareSide / 2), 0), color),//7
			VertexFormat(corner + glm::vec3((squareSide / 2),(squareSide / 2), 0), color),//8
		};

		std::vector<unsigned short> indices = {
			4,5,0,
			4,3,8,
			4,7,6,
			4,1,2
		};

		shuriken = new Mesh("shuriken");
		indices.push_back(0);
		indices.push_back(2);
	

		shuriken->InitFromData(vertices, indices);

	}
}

Shuriken::~Shuriken() {
	delete shuriken;
}

Mesh* Shuriken::GetShuriken() {
	return shuriken;
}