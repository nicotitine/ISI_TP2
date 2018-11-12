#include "cone.h"
#include "QDebug"

Cone::Cone() : TriMesh() {
    _name = "Cone";
    int nbStep = 20;
    GLfloat p = 0;

    this->addVertex(0,0,-1);
    for( GLfloat n = 1; n <= nbStep; n++ ) {
        p+= 2 * M_PI / (GLfloat)nbStep;
        this->addVertex(cos(p), sin(p), -1);
    }
    this->addVertex(0, 0, 1);

    for (int i=0; i<nbStep; ++i) {
        if(i == nbStep - 1) {
            this->addTriangle(0, 1, i+1);
            this->addTriangle(1, nbStep+1, i+1);
        } else {
            this->addTriangle(0, i+2, i+1);
            this->addTriangle(i+2, nbStep+1, i+1);
        }
    }

    qDebug() << "cone";
    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}
