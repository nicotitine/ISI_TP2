#include "corner_cube.h"

CornerCube::CornerCube() : TriMesh() {
  _name = "Corner Cube";

  // vertex coordinates
  static const GLfloat v[10][3] = {
    {-1,-1,1},{-1,1,1},{1,-1, 1},
      {-1,-1, -1},{-1,1, -1},{1,1, -1},{1,-1, -1}, {0.33, 1, 1}, {1, 0.33, 1}, {1, 1, 0.33}
  };

  // triangles vertex indices
  static const GLint t[16][3] = {
      {0,7,1}, {0,3,2}, {2,3,6}, {0,8,7}, {0,2,8}, {7, 8, 9}, {5, 9, 6}, {6, 9, 8}, {2, 6, 8}, {1, 7, 4}, {4, 7, 9}, {4, 9, 5}, {3, 4, 5}, {3, 5, 6}, {0, 1, 3}, {1, 4, 3}   // top triangles
  };

  for (int i=0; i<10 ; ++i)
    this->addVertex(v[i][0], v[i][1], v[i][2]);

  for (int i=0; i<16; ++i)
    this->addTriangle(t[i][0], t[i][1], t[i][2]);

  computeNormalsT();  // to be fixed
  computeNormalsV();  // to be fixed
}
