#include <controller/application.h>



MainWindow* Application::mainWindow = NULL;



/**
  *
  */
Application::Application(int& argc,
                         char* argv[])
                        :QApplication(argc, argv)
{
    mainWindow = new MainWindow();
}



/**
  *
  */
Application::~Application()
{
    delete mainWindow;
}



/**
  *
  */
int Application::exec()
{
    return QApplication::exec();
}



/**
  *
  */
int Application::getRun()
{
//    return mainWindow->getRun();
}
