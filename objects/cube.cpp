#include "cube.h"

Cube::Cube() : TriMesh() {
  _name = "Cube";

  // vertex coordinates
  static const GLfloat v[8][3] = {
    {-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},
    {-1,-1, 1},{-1,1, 1},{1,1, 1},{1,-1, 1}
  };

  // triangles vertex indices
  static const GLint t[12][3] = {
    {1,2,0},{3,0,2},
    {1,5,6},{2,1,6},{2,6,3},{3,6,7},{3,7,0},{0,7,4},{0,4,1},{1,4,5},
    {4,7,5},{7,6,5}
  };

  // Fill vertices vector
  for (int i=0; i<8 ; ++i)
    this->addVertex(v[i][0], v[i][1], v[i][2]);

  // Fill triangles vector
  for (int i=0; i<12; ++i)
    this->addTriangle(t[i][0], t[i][1], t[i][2]);

  computeNormalsT();  // to be fixed
  computeNormalsV();  // to be fixed
}
