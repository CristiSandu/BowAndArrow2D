#include "Arrow.h"


using namespace std;


Arrow::Arrow() {
	{
		arrowM = new Mesh("arrow");

		std::vector<VertexFormat> vertices = {
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

		std::vector<unsigned short> indices = {
			1,5,2,
			1,8,2,
			9,10,11,
			11,10,12,
			4,7,3,
			3,6,4
		};
		

		arrowM->InitFromData(vertices, indices);

	}
}

Arrow::~Arrow() {
	delete arrowM;
}

Mesh* Arrow::GetArrow() {
		return arrowM;
}
