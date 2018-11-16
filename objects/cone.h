#ifndef CONE_H
#define CONE_H

#include "triMesh.h"

/**
 * Cone Object
 *
 */
class Cone : public TriMesh {
public:
    Cone(int nvertices);
    virtual ~Cone(){}
};

#endif // CONE_H
