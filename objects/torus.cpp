#include "torus.h"
Torus::Torus() : TriMesh()
{
    _name = "Torus";
    float centreX = 0;
    float centreY = 0;
    float centreZ = 0;
    float r = 0.38;
    float r2 = 0.25;
    int num_segments = 30;
    int nb_cercles = num_segments;

    for (int i=0;i<num_segments;i++) {
        float theta2 = 2.0f * 3.1415926f * float(i) / float(num_segments);
        centreX = r * cosf(theta2);
        centreY = r * sinf(theta2);
        this->addVertex(centreX, centreY, centreZ);
        for(int j = 0; j < num_segments; j++) {
            float theta = 2.0f * 3.1415926f * float(j) / float(num_segments);
            float x = (r+r2*cosf(theta)) * cosf(theta2);
            float y = (r+r2*cosf(theta)) * sinf(theta2);
            float z = r2*sin(theta);

            this->addVertex(x+centreX, y+centreY, z+centreZ);
        }
    }

  /*Creation des triangles pour le côté du torus*/

  for (int i=0;i<num_segments;i++) {
    int k = 1;
    if (i < nb_cercles-1) {
      for (int j = (i*num_segments)+(i+1); j<(i+1)*num_segments+i; j++) {
          k++;
          this->addTriangle(j, (i+1)*num_segments +k+(i+1),j+1);
          this->addTriangle(j,(i+1)*num_segments +k +i, (i+1)*num_segments +k+(i+1));
      }
      this->addTriangle((i*num_segments)+(i+1),(i+1)*num_segments+i,(i+2)*num_segments+(i+1));
      this->addTriangle((i*num_segments)+(i+1) ,(i+2)*num_segments+(i+1),(i+1)*num_segments+i+2);
    }

    else {
        k=0;
        for (int j = (i*num_segments)+(i+1); j<(i+1)*num_segments+i; j++) {
            k++;
            this->addTriangle(j, k+1,j+1);
            this->addTriangle(j,k, k+1);
        }
        this->addTriangle(1,(i+1)*num_segments+i,num_segments);
        this->addTriangle(1,(i)*num_segments+i+1,(i+1)*num_segments+i);
    }
  }
  computeNormalsT();
  computeNormalsV();
}
