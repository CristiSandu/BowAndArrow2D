#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace RanderItems
{

	Mesh* CreateArrow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);

	Mesh* CreateBow(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, int spaceBow, int scale);

	Mesh* CreateShuriken(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill, int spaceBow, int scale);

	Mesh* CreateBalloon(std::string name, glm::vec3 leftBottomCorner, float x, float y, glm::vec3 color, bool fill, int spaceBow, int scale);

}

