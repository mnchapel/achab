/// @file mainWindow.cpp
/// @brief Main file
/// @author Marie-Neige Chapel
/// @version 0.1



#ifndef MAINWINDOW_H
#define MAINWINDOW_H



// Achab
#include <../build/ui_MainWindow.h>
#include <../build/ui_mobdecProjectOption.h>
#include <model/project.h>
#include <view/graphicsBuilder/builderManager.h>
#include <view/graphicsBuilder/graphicsItemFeaturePointBuilder.h>
#include <view/graphicsBuilder/graphicsItemDistanceToCameraBuilder.h>
#include <view/graphicsBuilder/graphicsItemConfidenceValueBuilder.h>
#include <view/graphicsBuilder/graphicsItemLabelBuilder.h>
#include <view/graphicsBuilder/graphicsItemTrendUpdateClusterValueBuilder.h>
#include <view/graphicsBuilder/graphicsItemTrendUpdateValueBuilder.h>
#include <view/graphicsScene.h>

// QT
#include <qcombobox.h>
#include <QtCore/qdiriterator.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qdatawidgetmapper.h>
#include <QtWidgets/qgraphicsview.h>
#include <qscrollbar.h>

// C++
#include <iostream>



namespace Ui {
    class ui_MainWindow;
}



/// @class MainWindow
/// This class defines the main window of the graphic interface.
class MainWindow : public QMainWindow
{
    Q_OBJECT

//---------------------------------------------------------------------------------------
// PRIVATE MEMBER DATA
private:

	///
	Project project;

    ///
    const int nb_max_col_view = 2;

    ///
    int new_view_col = 0;

    ///
    int new_view_row = 0;

    ///
    QVector<QGraphicsView*> view;

    ///
    Ui::ui_MainWindow* ui;

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
    MainWindow(QWidget* parent=0);



//---------------------------------------------------------------------------------------
// PROTECTED MEMBER FUNCTION
protected:

    /// @brief
    ///
    /// @param phase_name
    /// @param file_name
    ///
    /// @return
    int getViewItemIndexByName(QString phase_name
    						  ,QString file_name) const;



    /// @brief
    void initComboBoxMobdecProject();



    /// @brief
    void updateAllScene() noexcept;



//-----------------------------------------------------------------------------
// SIGNAL
Q_SIGNALS:

	/// @brief
	void signalMousePressOnScene(QPointF point);



	/// @brief
	void signalNextFrame();



	/// @brief
	void signalPreviousFrame();



	/// @brief
	void signalSetImageScale();



    /// @brief
    ///
    /// @param selected_project
    void updateSelectedProject(QString selected_project);



//-----------------------------------------------------------------------------
// PRIVATE MEMBER SLOT
public Q_SLOTS:

	/// @brief
	///
	/// @param phase_name
	/// @param file_name
	void slotAddResult(QString phase_name
					  ,QString file_name) noexcept;



	/// @brief
	///
	/// @param point
	void slotMousePressOnScene(QPointF point) noexcept;



	/// @brief
	void slotNextFrame() noexcept;



	/// @brief
	void slotPreviousFrame() noexcept;



	/// @brief
	///
	/// @param phase_name
	/// @param file_name
	void slotRemoveResult(QString phase_name
						 ,QString file_name) noexcept;



	/// @brief
	///
	/// @param
	void slotScrollingHorizontal(int value) noexcept;



	/// @brief
	///
	/// @param
	void slotScrollingVertical(int value) noexcept;



    /// @brief
    void slotSetImageScale() noexcept;



    /// @brief
    ///
    /// @param selected_project:
    void slotSetSelectedProject(QString selected_project) noexcept;



    /// @brief
    void slotStartSceneDrag() noexcept;



    /// @brief
    void slotStopSceneDrag() noexcept;

};

#endif // MAINWINDOW_H













