#ifndef OFF_LOADER_H
#define OFF_LOADER_H

#include <QString>
#include "triMesh.h"
#include <QFile>
#include <QTextStream>



class OffLoader : public TriMesh {
public:
    OffLoader(QString path);
    bool getLoadedState();
private:
    bool loadedState;
};

#endif // OFF_LOADER_H
