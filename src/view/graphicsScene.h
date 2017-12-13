#ifndef MODEL_FRAME_H
#define MODEL_FRAME_H


// QT
#include <qapplication.h>
#include <qdebug.h>
#include <qdrag.h>
#include <qgraphicsscene.h>
#include <QGraphicsPixmapItem>
#include <qmimedata.h>
#include <QMouseEvent>

// C++
#include <iostream>

// Program
#include <model/modelFile.h>
#include <model/project.h>
#include <view/graphicsItem/graphicsItem.h>
#include <view/graphicsItem/graphicsItemFeaturePoint.h>



/// @class
class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

//-----------------------------------------------------------------------------
// PROTECTED MEMBER DATA
protected:

	//!
	Project* project = NULL;

	///
	ModelFile* model = NULL;

    ///
    QGraphicsPixmapItem* image_layer;

    ///
    static double image_scale;

    ///
    bool isDragging = false;

    ///
    GraphicsItem* information_layer;

    ///
    QPointF drag_start_position;



//-----------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Constructor.
    ///
    /// @param parent
    /// @param item_name
    /// @param path_to_image
    GraphicsScene(QObject *parent = 0) noexcept;



    /// @brief Constructor.
    ///
    /// @param project
    /// @param model_file
    /// @param parent
    GraphicsScene(Project* project
    			 ,ModelFile* model_file
				 ,QObject *parent = 0) noexcept;



    /// @brief Destructor.
    ~GraphicsScene() noexcept;



    /// @brief
    ///
    /// @return
    QGraphicsPixmapItem* getImageLayer() const noexcept;



    /// @brief Set the information layer.
    ///
    /// @param information_layer: the new information layer.
    void setInformationLayer(GraphicsItem* information_layer) noexcept;



    /// @brief
    void updateView() noexcept;



//-----------------------------------------------------------------------------
// PROTECTED MEMBER FUNCTION
protected:

	/// @brief
	///
	/// @param key_event
	void keyPressEvent(QKeyEvent* key_event) noexcept;



	/// @brief
	///
	/// @param key_event
	void keyReleaseEvent(QKeyEvent* key_event) noexcept override;



    /// @brief
    ///
    /// @param event
    void mousePressEvent(QGraphicsSceneMouseEvent* event) noexcept;



    /// @brief
    ///
    /// @param event
    void wheelEvent(QGraphicsSceneWheelEvent* event) noexcept;



//-----------------------------------------------------------------------------
// SIGNAL
signals:

	/// @brief
	void signalMousePressOnScene(QPointF point);



	/// @brief
	void signalNextFrame();



	/// @brief
	void signalPreviousFrame();



	/// @brief
	void signalSetImageScale();



	/// @brief
	void signalStartSceneDrag();



	/// @brief
	void signalStopSceneDrag();



//-----------------------------------------------------------------------------
// PUBLIC MEMBER SLOT
public Q_SLOTS:



	// @brief
	void slotSetImageScale() noexcept;



	// @brief
	void slotSetSelection(QVector<double> selection) noexcept;



    /// @brief
    void slotUpdateView() noexcept;

};

#endif // MODEL_FRAME_H
