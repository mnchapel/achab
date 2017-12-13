#ifndef APPLICATION_H
#define APPLICATION_H

// QT
#include <QtWidgets/qapplication.h>

#include "../view/mainWindow.h"



/**
 * @class Application
 * This class defines an application for a (future) QT interface.
 */
class Application : QApplication
{
  Q_OBJECT

//-----------------------------------------------------------------------------
// PRIVATE MEMBER DATA
private:

    //!
    static MainWindow* mainWindow;

//-----------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /**
      * @brief
      *
      * @param argc: .
      * @param argv: .
      * @param distance_graph: .
      */
    Application(int& argc,
                char* argv[]);

    /**
      * @brief Destructor.
      */
    ~Application();

    /**
      * @brief
      */
    static int exec();

    /**
      * @brief
      *
      * @return
      */
    int getRun();
};

#endif // APPLICATION_H
