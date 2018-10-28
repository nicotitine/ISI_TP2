#include "corner_cube.h"
#include "QDebug"

CornerCube::CornerCube()
  : TriMesh()
{
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

  // triangle normals
  static const GLint nt[16][3] = {
    {0,0,1},{0,-1,0}, // bottom triangle normals
    {0,-1,0},{0,0,1},{0,0,1},{1,1,1},{1,0,0},{1,0,0},{1,0,0},{0,1,0}, // side triangle normals
      {0,1,0},{0,1,0}, {0, 0, -1}, {0, 0, -1}, {-1, 0, 0}, {-1, 0, 0}    // top triangle normals
  };

  // triangle vertex normals
  static const GLint nv[36][3] = {
    {0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1}, // bottom triangle vertex normals

    {0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},       // side triangle vertex normals
    {1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},
    {0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},
    {-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},

    {0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1}        // top triangle vertex normals
  };


  //--- Fill vertices and triangles vectors

  // Fill vertices vector
  for (int i=0; i<10 ; ++i)
    this->addVertex(v[i][0], v[i][1], v[i][2]);

  // Fill triangles vector
  for (int i=0; i<16; ++i)
    this->addTriangle(t[i][0], t[i][1], t[i][2]);

  // Fill normals vectors
  bool use_computed_normals = true;

  if (use_computed_normals) {
      qDebug() << "corner_cube";
      computeNormalsT();  // to be fixed
      computeNormalsV();  // to be fixed

    } else { // use manually defined normals

      // set triangle normals
      for (int i=0; i<16; ++i) {
          Normal nT(nt[i][0], nt[i][1], nt[i][2]);
          this->addNormalT(nT);
        }
      // set triangle vertex normals
      for (int i=0; i<36; ++i) {
          Normal nV(nv[i][0], nv[i][1], nv[i][2]);
          this->addNormalV(nV);
        }
   }

}
