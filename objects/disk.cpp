#include "disk.h"

Disk::Disk(int nvertices) : TriMesh() {
    _name = "Disque";
    GLfloat p = 0;

    for( GLfloat n = 0; n < nvertices; n++ ) {
        p+= 2 * M_PI / (GLfloat)nvertices;
        this->addVertex(sin(p), cos(p), 0);
    }

    for (int i=0; i<nvertices-2; i++) {
        if(i == nvertices - 1)
            this->addTriangle(0, 1, i+1);
        else
            this->addTriangle(0, i+2, i+1);
    }
    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}
