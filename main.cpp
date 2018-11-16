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
#include "objects/off_loader.h"
#include <tclap/CmdLine.h>

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
    QString path = "";


  // Parse program arguments here
  // with the tclap library
  // http://tclap.sourceforge.net/manual.html
  //

    try {
        TCLAP::CmdLine cmd("Command description message", ' ', "0.9");
        TCLAP::ValueArg<std::string> pathArg("o","off","Path to .off",false,"","string");
        cmd.add( pathArg );
        cmd.parse( argc, argv );
        path = QString::fromStdString(pathArg.getValue());
    } catch (TCLAP::ArgException &e) {
        usage("isiviewer-1.4");
    }

  // initialize my custom 3D scene
  float objectRadius = 1.;
  QPointer<MyScene> myScene = new MyScene(objectRadius);

  //add simple objects
  if(path != "") {
      OffLoader * offObject = new OffLoader(path);
      if(offObject->getLoadedState()) {
          myScene->addObject(offObject);
      } else {
          std::cout << "Le fichier spécifié n'a pas pu être chargé. Vérifiéz bien son chemin (" << path.toLocal8Bit().constData() << ").";
      }
  }

  myScene->addObject(new Sphere(20));
  myScene->addObject(new Torus());
  myScene->addObject(new DiskHole(20));
  myScene->addObject(new Cone(20));
  myScene->addObject(new Cylinder(20));
  myScene->addObject(new Disk(20));
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

