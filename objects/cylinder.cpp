#include "cylinder.h"

Cylinder::Cylinder(int nvertices): TriMesh()
{
  _name = "Cylinder";
  GLfloat p = 0;

  // Adding vertices

  // Top disk vertices
  this->addVertex(0,0,1);
  for( GLfloat n = 1; n <= nvertices; n++ ) {
      p+= 2 * M_PI / (GLfloat)nvertices;
      this->addVertex(sin(p), cos(p), 1);
  }

  // Bottom Disk vertices
  this->addVertex(0,0,-1);
  for(GLfloat n = nvertices + 2; n <= nvertices * 2 + 1; n++) {
      p+= 2 * M_PI / (GLfloat)nvertices;
      this->addVertex(sin(p), cos(p), -1);
  }

  // Creating triangles
  // Between the disks
  for(int i = 1; i <= nvertices; i++) {
      if(i == nvertices){
        this->addTriangle(i, 1, i *2 +1);
        this->addTriangle(i+2, i*2+1, 1);
      }
      else {
        this->addTriangle(i, i+1, i+nvertices+1);
        this->addTriangle(i+nvertices+2, i+nvertices+1, i+1);
      }
  }

  // Top disk
  for (int i=0; i<nvertices; ++i) {
      if(i == nvertices - 1)
          this->addTriangle(0, 1, i+1);
      else
          this->addTriangle(0, i+2, i+1);
  }

  // Bottom Disk
  for(int i = nvertices + 1; i < nvertices * 2 + 1; ++i) {
      if( i == nvertices * 2 )
          this->addTriangle(nvertices+1, i+1, nvertices+2);
      else
          this->addTriangle(nvertices+1, i+1, i+2);
  }
  computeNormalsT();
  computeNormalsV();
}

