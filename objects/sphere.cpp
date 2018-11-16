#include "sphere.h"
#include "QDebug"

Sphere::Sphere(int nvertices) : TriMesh() {
    _name = "Sphere";
    float r = 1.0f;
    for (double phi = 0.; phi < 2*PI; phi += PI/(float)nvertices) // Azimuth [0, 2PI]
        {
            for (double theta = 0.; theta < PI; theta += PI/(float)nvertices) // Elevation [0, PI]
            {
                float x = r * cos(phi) * sin(theta);
                float y = r * sin(phi) * sin(theta);
                float z = r            * cos(theta);
                addVertex(x, y, z);
            }
        }

    //qDebug() << "vertices size" << _vertices.size();



    //const float PI = 3.141592f;
//    float nbStep = 30;
//    GLfloat p = 0;
//    GLfloat s = 0;
//    GLfloat z = -1;
//    float step = 2 / (nbStep - 1);
//    qDebug() << "step" << step;

//    // Adding vertices

//    // Top disk vertices

//    for(int i = 0; i < nbStep; i++) {
//        qDebug() << s;
//        for( GLfloat n = 0; n < nbStep; n++ ) {
//            p+= 2 * M_PI / (GLfloat)nbStep;
//            this->addVertex(sin(p) * s, cos(p) * s, z);
//        }
//        if(i < (nbStep / 2 - 1)) {
//            s+=step;
//        } else {
//            s-=step;
//        }
//        z+=step;
//    }

//    for(int i = 0; i < nbStep; i++) {
//        qDebug() << s;
//        for( GLfloat n = 0; n < nbStep; n++ ) {
//            p+= 2 * M_PI / (GLfloat)nbStep;
//            this->addVertex(sin(p) * s,z ,  cos(p) * s);
//        }
//        if(i < (nbStep / 2 - 1)) {
//            s+=step;
//        } else {
//            s-=step;
//        }

//        z+=step;
//    }


//    qDebug() << _vertices.size();

//    for(int i = 0; i < nbStep-1; i++) {
//        for(int j = 0; j < nbStep -1; j    glutSolidSphere(1, 20, 20);++) {
//            addTriangle(i*nbStep, i * nbStep + j, i * nbStep + j + 1);
//        }
//    }


    // Top disk
//    addTriangle(0,5,6);
//    addTriangle(0,6,7);
//    addTriangle(0,7,8);
//    addTriangle(0,8,9);
//    addTriangle(0,9,5);
//    addTriangle(1,2,3);
//    addTriangle(2,3,4);
//    addTriangle(3,4,0);
//    addTriangle(4, 0, 1);

//    addTriangle(5,6,7);
//    addTriangle(6,7,8);
//    addTriangle(7,8,9);
//    addTriangle(8,9,5);
//    addTriangle(9, 5, 6);

//    addTriangle(10,11,12);
//    addTriangle(11,12,13);
//    addTriangle(12,13,14);
//    addTriangle(13,14,10);
//    addTriangle(14,10,11);

//    addTriangle(15,16,17);
//    addTriangle(16,17,18);
//    addTriangle(17,18,19);
//    addTriangle(18,19,15);
//    addTriangle(19,15,16);

//    addTriangle(20,20,22);
//    addTriangle(21,22,23);
//    addTriangle(22,23,24);
//    addTriangle(23,24,20);
//    addTriangle(24,20,21);

//    addTriangle(5,10,11);
//    addTriangle(5,11,6);

//    addTriangle(25,26,27);
//    addTriangle(26,27,28);
//    addTriangle(27,28,29);
//    addTriangle(28,29,25);
//    addTriangle(29,25,26);


    //qDebug() << "disk";
    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed

}
