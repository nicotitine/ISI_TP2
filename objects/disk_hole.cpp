#include "disk_hole.h".h"
#include "QDebug"

DiskHole::DiskHole() : TriMesh() {
    _name = "Disk Hole";
    int nbStep = 30;
    GLfloat p = 0;

    for( GLfloat n = 0; n < nbStep; n++ ) {
        p+= 2 * M_PI / (GLfloat)nbStep;
        this->addVertex(sin(p), cos(p), 0);
    }
    for( GLfloat n = 0; n < nbStep; n++ ) {
        p+= 2 * M_PI / (GLfloat)nbStep;
        this->addVertex(sin(p) * 0.25, cos(p) * 0.25, 0);
    }

    for (int i=0; i<nbStep; ++i) {
        if(i == nbStep-1) {
            this->addTriangle(i, nbStep + i, 0);
            this->addTriangle(0, nbStep + i, nbStep);
        }

        else {
            this->addTriangle(i, nbStep + i, nbStep + i + 1);
            this->addTriangle(i, nbStep + 1 + i, i+1);
        }
    }

    qDebug() << "disk hole";
    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}
