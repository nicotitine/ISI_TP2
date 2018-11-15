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

  QFile data("../ISI_TP2/data/aircraft.off");
  if(data.open(QIODevice::ReadOnly)) {
      QTextStream in(&data);
      QString line = in.readLine();
      if(line == "OFF") {
          line = in.readLine();
          int i = 0;
          QString nb_read = "";
          int nb_vertices;
          int nb_triangles;
          int nb_colors;
          while(line.at(i) != " ") {
              nb_read += line.at(i);
              i++;
          }
          nb_vertices = nb_read.toInt();
          nb_read = "";
          i++;
          while(line.at(i) != " ") {
              nb_read += line.at(i);
              i++;
          }
          nb_triangles = nb_read.toInt();
          nb_read = "";
          i++;
          do {
              nb_read += line.at(i);
              i++;
          } while (i < line.length());
          nb_colors = nb_read.toInt();
          in.readLine();

          // Create the trimesh object
          TriMesh * dataObject = new TriMesh();

          // READ VERTICES
          for(i = 0; i < nb_vertices; i++) {
              QString x, y, z;
              x = "";
              y = "";
              z = "";
              int j = 0;
              line = in.readLine();
              while(line.at(j) != " ") {
                  x += line.at(j);
                  j++;
              }
              j++;
              while(line.at(j) != " ") {
                  y += line.at(j);
                  j++;
              }
              j++;
              do {
                  z += line.at(j);
                  j++;
              } while (j < line.length());

              // Add the {x, y, z} vertice
              dataObject->addVertex(x.toDouble(), y.toDouble(), z.toDouble());
          }
          // READ TRIANGLES
          for(i = 0; i < nb_triangles; i++) {
              line = in.readLine();
              int size = QString(line.at(0)).toInt();
              int cursor = 3;
              QString test = "";
              for(int j = 0; j < size; j++) {
                  do {
                      //QString test("");
                      test += line.at(cursor);
                      cursor++;
                  } while (cursor < line.length() -1);
                  qDebug() << test;
              }
          }


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

