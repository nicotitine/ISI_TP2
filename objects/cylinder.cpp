#include "cylinder.h".h"
#include "QDebug"

Cylinder::Cylinder()
  : TriMesh()
{
  _name = "Cylinder";

  int nbStep = 20;
  // Vector of vector initialization
  static vector<vector<GLfloat>> v(nbStep*2 + 2, vector<GLfloat>(3));
  static vector<vector<GLfloat>> t(nbStep, vector<GLfloat>(3));
  static vector<vector<GLfloat>> nt(nbStep, vector<GLfloat>(3));
  v[0] = {0,0,1};
  v[nbStep + 1] = {0, 0, -1};
  GLfloat p = 0;


          for( GLfloat n = 1; n <= nbStep; n++ ) {
              p+= 2 * M_PI / (GLfloat)nbStep;
              v[n] = {(GLfloat) sin(p) * 1,(GLfloat)cos(p) * 1,(GLfloat) 1};
              qDebug() << "v[n] : " << v[n];
          }

          for (GLfloat n = nbStep + 2; n < nbStep * 2 + 2; n++) {
              p += 2 * M_PI / (GLfloat)nbStep;
              v[n] = {(GLfloat) sin(p) * 1,(GLfloat)cos(p) * 1,(GLfloat) -1};
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
              nt[i] = {0, 0, 0};
          }
          bool use_computed_normals = false;

          if (use_computed_normals) {
              qDebug() << "cylinder";
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
