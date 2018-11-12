#include "cylinder.h"
#include "QDebug"

Cylinder::Cylinder(): TriMesh()
{
  _name = "Cylinder";
  int nbStep = 30;
  GLfloat p = 0;

  // Adding vertices

  // Top disk vertices
  this->addVertex(0,0,1);
  for( GLfloat n = 1; n <= nbStep; n++ ) {
      p+= 2 * M_PI / (GLfloat)nbStep;
      this->addVertex(sin(p), cos(p), 1);
  }

  // Bottom Disk vertices
  this->addVertex(0,0,-1);
  for(GLfloat n = nbStep + 2; n <= nbStep * 2 + 1; n++) {
      p+= 2 * M_PI / (GLfloat)nbStep;
      this->addVertex(sin(p), cos(p), -1);
  }

  // Creating triangles
  // Between the disks
  for(int i = 1; i <= nbStep; i++) {
      if(i == nbStep){
        this->addTriangle(i, 1, i *2 +1);
        this->addTriangle(i+2, i*2+1, 1);
      }
      else {
        this->addTriangle(i, i+1, i+nbStep+1);
        this->addTriangle(i+nbStep+2, i+nbStep+1, i+1);
      }
  }

  // Top disk
  for (int i=0; i<nbStep; ++i) {
      if(i == nbStep - 1)
          this->addTriangle(0, 1, i+1);
      else
          this->addTriangle(0, i+2, i+1);
  }

  // Bottom Disk
  for(int i = nbStep + 1; i < nbStep * 2 + 1; ++i) {
      if( i == nbStep * 2 )
          this->addTriangle(nbStep+1, i+1, nbStep+2);
      else
          this->addTriangle(nbStep+1, i+1, i+2);
  }

  qDebug() << "cylinder";
  computeNormalsT();
  computeNormalsV();
}

