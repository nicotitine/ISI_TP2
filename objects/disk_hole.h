#ifndef DISK_HOLE_H
#define DISK_HOLE_H

#include "triMesh.h"

class DiskHole : public TriMesh {
public:
    DiskHole(int nvertices);
    virtual ~DiskHole(){};
};

#endif // DISK_HOLE_H
