#ifndef GRAPHICS_ITEM_DISTANCE_TO_CAMERA_H
#define GRAPHICS_ITEM_DISTANCE_TO_CAMERA_H



// Achab
#include <model/modelFile.h>
#include <view/graphicsItem/graphicsItem.h>

// C++
#include <iostream>

// QT
#include <qdebug.h>
#include <qgraphicsitem.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>

#define CROSS_SIZE 2



class GraphicsItemDistanceToCamera : public GraphicsItem
{

//-----------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
	GraphicsItemDistanceToCamera(ModelFile* model_data
    						,QGraphicsItem* parent = 0) noexcept;



    ///@brief Destructor.
    ~GraphicsItemDistanceToCamera() noexcept = default;



    /// @brief
    ///
    /// @param x
    /// @param y
    /// @param painter
    void paintACross(uint x
    			    ,uint y
					,QPainter* painter) noexcept;



    /// @brief paint
    ///
    /// @param painter
    /// @param option
    /// @param widget
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget) noexcept;

};

#endif /* GRAPHICS_ITEM_DISTANCE_TO_CAMERA_H */
