#include "disk.h"
#include "QDebug"

Disk::Disk() : TriMesh() {
    _name = "Disque";
    int nbStep = 30;
    GLfloat p = 0;

    for( GLfloat n = 0; n < nbStep; n++ ) {
        p+= 2 * M_PI / (GLfloat)nbStep;
        this->addVertex(sin(p), cos(p), 0);
    }

    for (int i=0; i<nbStep-2; i++) {
        if(i == nbStep - 1)
            this->addTriangle(0, 1, i+1);
        else
            this->addTriangle(0, i+2, i+1);
    }

    qDebug() << "disk";
    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}
