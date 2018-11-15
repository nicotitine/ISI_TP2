/**
 * @file   main.cpp
 * @author Bruno Jobard
 * @author Author1
 * @author Author2
 * @date   Sep 2012
 *
 * @brief  Declares an application, a main window and a 3D scene
 *
 *
 */
#include <QApplication>
#include <QTextStream>
#include <QDebug>
#include "my_main_window.h"
#include "my_object3d.h"
#include "objects/corner_cube.h"
#include "objects/pyramid.h"
#include "objects/cube.h"
#include "objects/disk.h"
#include "objects/cylinder.h"
#include "objects/cone.h"
#include "objects/disk_hole.h"
#include "objects/sphere.h"
#include "objects/torus.h"

/**
* Program usage
* Should be handled with the tclap library
*/
void usage(char* name){
  cout<< "usage: " << name << " [options]" <<endl;
  cout<< "options:" <<endl;
  cout<< "  -h, --help                 shows this message" <<endl;
  cout<< "  --off file                 loads OFF file" <<endl;
}

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    TriMesh * dataObject = new TriMesh();
    QFile data("../isi_tp1_project/data/venus.off");
    if(data.open(QIODevice::ReadOnly)) {
        QTextStream in(&data);
        QString line = in.readLine();
        if(line == "OFF") {
            int i = 0;
            int nb_vertices, nb_triangles, old_pos;
            QString nb_vertices_buf, nb_triangles_buf, x, y, z;
            QStringList vertices_list, triangles_list, parameters_list = in.readLine().split(" ", QString::SkipEmptyParts);

            nb_vertices_buf = parameters_list.at(0);
            nb_triangles_buf = parameters_list.at(1);

            nb_vertices = nb_vertices_buf.toInt();
            nb_triangles = nb_triangles_buf.toInt();

            old_pos = in.pos();

            // for aircraft.off which has a blank line bellow the counting numbers line
            if(in.readLine() != "")
                in.seek(old_pos);

            // READ VERTICES
            for(i = 0; i < nb_vertices; i++) {
                vertices_list = in.readLine().split(" ", QString::SkipEmptyParts);
                x = vertices_list.at(0);
                y = vertices_list.at(1);
                z = vertices_list.at(2);
                dataObject->addVertex(x.toDouble(), y.toDouble(), z.toDouble());
            }

            // READ TRIANGLES
            for(i = 0; i < nb_triangles; i++) {
                triangles_list = in.readLine().split(" ", QString::SkipEmptyParts);
                if(triangles_list.at(0) == "3") {
                    x = triangles_list.at(1);
                    y = triangles_list.at(2);
                    z = triangles_list.at(3);
                    dataObject->addTriangle(x.toInt(), y.toInt(), z.toInt());
                }
            }
            dataObject->computeNormalsT();
            dataObject->computeNormalsV();
        } else {
            std::cout << "Le fichier donné n'est pas au format off." << std::endl;
        }
    }
    data.close();

  // Parse program arguments here
  // with the tclap library
  // http://tclap.sourceforge.net/manual.html
  //

  // initialize my custom 3D scene
  float objectRadius = 1.;
  QPointer<MyScene> myScene = new MyScene(objectRadius);

  //add simple objects
  myScene->addObject(dataObject);
  myScene->addObject(new Sphere());
  myScene->addObject(new Torus());

  myScene->addObject(new DiskHole());
  myScene->addObject(new Cone());
  myScene->addObject(new Cylinder());
  myScene->addObject(new Disk());
  myScene->addObject(new Cube());
  myScene->addObject(new Pyramid());
  myScene->addObject(new CornerCube());

  // add surface functions
  // ...

  // add user defined OFF files
  // ...

  // initialize my custom main window
  QPointer<MyMainWindow> myMainWindow = new MyMainWindow(myScene);
  // display the window
  myMainWindow->show();
  // enter in the main loop
  return app.exec();
}

