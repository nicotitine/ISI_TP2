#ifndef SPHERE_H
#define SPHERE_H

#include "triMesh.h"

/**
 * Sphere Object
 *
 */
class Sphere : public TriMesh {
public:
    Sphere(int nvertices);
    virtual ~Sphere(){}
};

#endif // SPHERE_H
