#pragma once

#include "../GrObject.H"
#include "../DrawingState.H"
#include <glm/glm.hpp>

class Surface : public GrObject {
public:
  Surface(glm::vec3 t, glm::vec3 s, std::vector<glm::vec3> points, int divs, char* vert, char* frag);
  Color color;
  std::vector<glm::vec3> points;
  std::vector<glm::vec3> normals;
  int divs;
  int shader;
  bool triedShader = false;
  char* frag;
  char* vert;
  virtual void draw(DrawingState*);
};

// Define some surfaces below to make things easier

// A Building
const std::vector<glm::vec3> S_BUILDING = {
  glm::vec3(0.0, 43.0, 0.0),
  glm::vec3(1.0, 35.0, 0.0),
  glm::vec3(2.0, 34.0, 0.0),
  glm::vec3(3.0, 34.0, 0.0),
  glm::vec3(5.0, 35.0, 0.0),
  glm::vec3(4.0, 32.0, 0.0),
  glm::vec3(3.0, 31.0, 0.0),
  glm::vec3(3.0, 27.0, 0.0),
  glm::vec3(5.0, 26.0, 0.0),
  glm::vec3(5.0, 22.0, 0.0),
  glm::vec3(6.0, 21.0, 0.0),
  glm::vec3(6.0, 15.0, 0.0),
  glm::vec3(7.0, 14.0, 0.0),
  glm::vec3(7.0, 9.0, 0.0),
  glm::vec3(8.0, 5.0, 0.0),
  glm::vec3(9.0, 2.0, 0.0),
  glm::vec3(9.5, 1.0, 0.0),
  glm::vec3(10.0, 0.0, 0.0)
};

// A fountain
const std::vector<glm::vec3> S_FOUNTAIN = {
  glm::vec3(0.0, .70, 0.0),
  glm::vec3(1.0, 7.0, 0.0),
  glm::vec3(1.0, 3.0, 0.0),
  glm::vec3(2.0, 3.0, 0.0),
  glm::vec3(2.0, 1.0, 0.0),
  glm::vec3(12.0, 1.0, 0.0),
  glm::vec3(12.0, 2.0, 0.0),
  glm::vec3(13.0, 3.0, 0.0),
  glm::vec3(14.0, 3.0, 0.0),
  glm::vec3(15.0, 2.0, 0.0),
  glm::vec3(15.0, 1.0, 0.0),
  glm::vec3(14.0, 0.0, 0.0),
  glm::vec3(0.0, 0.0, 0.0)
};

// A UFO
const std::vector<glm::vec3> S_UFO = {
  glm::vec3(0.0, 17.0, 0.0),
  glm::vec3(1.0, 17.0, 0.0),
  glm::vec3(1.0, 12.0, 0.0),
  glm::vec3(5.0, 12.0, 0.0),
  glm::vec3(9.0, 11.5, 0.0),
  glm::vec3(14.0, 10.25, 0.0),
  glm::vec3(18.0, 8.25, 0.0),
  glm::vec3(21.0, 6.0, 0.0),
  glm::vec3(22.5, 4.0, 0.0),
  glm::vec3(23.5, 2.0, 0.0),
  glm::vec3(24.0, 0.0, 0.0),
  glm::vec3(20.0, 0.0, 0.0),
  glm::vec3(13.0, 2.0, 0.0),
  glm::vec3(0.0, 2.0, 0.0)
};