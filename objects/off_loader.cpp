#include "off_loader.h"
#include <QDebug>

OffLoader::OffLoader(QString path) : TriMesh() {
    QFile data(path);
    if(data.open(QIODevice::ReadOnly)) {
        QTextStream in(&data);
        QString line = in.readLine();
        if(line == "OFF") {
            int i = 0;
            int nb_vertices, nb_triangles, old_pos;
            QString nb_vertices_buf, nb_triangles_buf, x, y, z, fourthPoint;
            QStringList vertices_list, triangles_list, parameters_list;

            line = in.readLine();
            while(line == "" || line.at(0) == "#") {
                line = in.readLine();
            }
            parameters_list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
            nb_vertices_buf = parameters_list.at(0);
            nb_triangles_buf = parameters_list.at(1);

            nb_vertices = nb_vertices_buf.toInt();
            nb_triangles = nb_triangles_buf.toInt();

            old_pos = in.pos();
            if(in.readLine() != "")
                in.seek(old_pos);

            // READ VERTICES
            for(i = 0; i < nb_vertices; i++) {
                vertices_list = in.readLine().split(QRegExp("\\s+"), QString::SkipEmptyParts);
                x = vertices_list.at(0);
                y = vertices_list.at(1);
                z = vertices_list.at(2);
                addVertex(x.toDouble(), y.toDouble(), z.toDouble());
            }

            old_pos = in.pos();
            if(in.readLine() != "")
                in.seek(old_pos);

            // READ TRIANGLES
            for(i = 0; i < nb_triangles; i++) {
                triangles_list = in.readLine().split(QRegExp("\\s+"), QString::SkipEmptyParts);
                if(triangles_list.at(0) == "3") {
                    x = triangles_list.at(1);
                    y = triangles_list.at(2);
                    z = triangles_list.at(3);
                    addTriangle(x.toInt(), y.toInt(), z.toInt());
                } else {
                    x = triangles_list.at(1);
                    y = triangles_list.at(2);
                    z = triangles_list.at(3);
                    fourthPoint = triangles_list.at(4);
                    addTriangle(x.toInt(), z.toInt(), y.toInt());
                    addTriangle(z.toInt(), x.toInt(), fourthPoint.toInt());
                }
            }
            computeNormalsT();
            computeNormalsV();
            loadedState = true;
        } else {
            std::cout << "Le fichier donné n'est pas au format off." << std::endl;
            loadedState = false;
        }
    } else {
        std::cout <<"Le fichier spécifié n'a pas pu être trouvé." << std::endl;
        loadedState = false;
    }
    data.close();
}

bool OffLoader::getLoadedState() {
    return this->loadedState;
}
