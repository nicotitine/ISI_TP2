#include "cone.h"

Cone::Cone(int nvertices) : TriMesh() {
    _name = "Cone";
    GLfloat p = 0;

    this->addVertex(0,0,-1);
    for( GLfloat n = 1; n <= nvertices; n++ ) {
        p+= 2 * M_PI / (GLfloat)nvertices;
        this->addVertex(cos(p), sin(p), -1);
    }
    this->addVertex(0, 0, 1);

    for (int i=0; i<nvertices; ++i) {
        if(i == nvertices - 1) {
            this->addTriangle(0, 1, i+1);
            this->addTriangle(1, nvertices+1, i+1);
        } else {
            this->addTriangle(0, i+2, i+1);
            this->addTriangle(i+2, nvertices+1, i+1);
        }
    }
    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}
