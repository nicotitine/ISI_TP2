#ifndef CYLINDER_H
#define CYLINDER_H

#include "triMesh.h"

/**
 * Cylinder Object
 *
 */
class Cylinder : public TriMesh {
public:
  Cylinder(int nvertices);
  virtual ~Cylinder(){};

};

#endif // CYLINDER_H
