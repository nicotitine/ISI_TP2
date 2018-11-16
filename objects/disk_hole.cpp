#include "disk_hole.h"
DiskHole::DiskHole(int nvertices) : TriMesh() {
    _name = "Disk Hole";
    GLfloat p = 0;

    for( GLfloat n = 0; n < nvertices; n++ ) {
        p+= 2 * M_PI / (GLfloat)nvertices;
        this->addVertex(sin(p), cos(p), 0);
    }
    for( GLfloat n = 0; n < nvertices; n++ ) {
        p+= 2 * M_PI / (GLfloat)nvertices;
        this->addVertex(sin(p) * 0.25, cos(p) * 0.25, 0);
    }

    for (int i=0; i<nvertices; ++i) {
        if(i == nvertices-1) {
            this->addTriangle(i, nvertices + i, 0);
            this->addTriangle(0, nvertices + i, nvertices);
        }

        else {
            this->addTriangle(i, nvertices + i, nvertices + i + 1);
            this->addTriangle(i, nvertices + 1 + i, i+1);
        }
    }
    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}
