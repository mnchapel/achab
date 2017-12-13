#ifndef GRAPHICS_ITEM_H
#define GRAPHICS_ITEM_H


// Achab
#include <model/modelFile.h>

// QT
#include <qdebug.h>
#include <qgraphicsitem.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>

// C++
#include <iostream>



class GraphicsItem : public QGraphicsItem
{

//-----------------------------------------------------------------------------
// PROTECTED MEMBER DATA
protected:

	//!
	ModelFile* model;

    ///
    qreal height;

    ///
    qreal left;

    ///
    qreal top;

    ///
    qreal width;



//-----------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Constructor.
    GraphicsItem(ModelFile* model
    			,QGraphicsItem* parent=0) noexcept;



    /// @brief Copy constructor.
    GraphicsItem(const GraphicsItem& graphics_item) = default;



    /// @brief Destructor.
    ~GraphicsItem() noexcept = default;



    /// @brief boundingRect
    ///
    /// @return
    QRectF boundingRect() const noexcept;



    /// @brief paint
    ///
    /// @param painter
    /// @param option
    /// @param widget
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget) noexcept;



    /// @brief setBoundingRect
    ///
    /// @param left
    /// @param top
    /// @param width
    /// @param height
    virtual void setBoundingRect(qreal left,
								 qreal top,
								 qreal width,
								 qreal height) noexcept;



    /// @brief
    ///
    /// @param data
    virtual void setData() noexcept;



    /// @brief
    ///
    /// @param selection
    virtual void setSelection(QVector<double>& selection) noexcept;

};

#endif /* GRAPHICS_ITEM_H */
