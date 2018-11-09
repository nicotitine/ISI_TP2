#include "disk.h"

#include "QDebug"

Disk::Disk() : TriMesh() {
    _name = "Disque";
    int nbStep = 20;
    // Vector of vector initialization
    static vector<vector<GLfloat>> v(nbStep+1, vector<GLfloat>(3));
    static vector<vector<GLfloat>> t(nbStep, vector<GLfloat>(3));
    static vector<vector<GLfloat>> nt(nbStep, vector<GLfloat>(3));
    v[0] = {0,0,0};
    GLfloat p = 0;


            for( GLfloat n = 1; n <= nbStep; n++ ) {
                p+= 2 * M_PI / (GLfloat)nbStep;
                v[n] = {(GLfloat) sin(p) * 1,(GLfloat)cos(p) * 1,(GLfloat) 0};
            }

            for(GLfloat j = 0; j < nbStep; ++j) {
                if(j == nbStep -1)
                    t[j] = {(GLfloat)0, (GLfloat)1, (GLfloat)j+1};
                else
                    t[j] = {(GLfloat)0, (GLfloat)j+2, (GLfloat)j+1};
            }

            for (int i=0; i<nbStep+1 ; ++i) {
              this->addVertex(v[i][0], v[i][1], v[i][2]);
            }

            for (int i=0; i<nbStep; ++i) {
                this->addTriangle(t[i][0], t[i][1], t[i][2]);
                nt[i] = {0, 0, 0.5};
            }


//            static const GLint nv[36][3] = {
//              {0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1}, // bottom triangle vertex normals

//              {0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},       // side triangle vertex normals
//              {1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},
//              {0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},
//              {-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},

//              {0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1}        // top triangle vertex normals
//            };


            bool use_computed_normals = true;

            if (use_computed_normals) {
                qDebug() << "disk";
                computeNormalsT();  // to be fixed
                computeNormalsV();  // to be fixed

              } else { // use manually defined normals

                // set triangle normals
                for (int i=0; i<nbStep; ++i) {
                    Normal nT(nt[i][0], nt[i][1], nt[i][2]);
                    this->addNormalT(nT);
                  }
              }



}
