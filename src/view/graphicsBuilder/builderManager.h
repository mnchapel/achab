#ifndef BUILDER_MANAGER_H
#define BUILDER_MANAGER_H


// QT
#include <qdebug.h>
#include <qgraphicsitem.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>

// C++
#include <iostream>

// Achab
#include <view/graphicsBuilder/graphicsSceneBuilder.h>



/// @class
class BuilderManager
{
//-----------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief
    ///
    /// @param graphics_scene_builder
	/// @param model_data
    /// @param path_to_image
    /// @param parent
    ///
    /// @return
    static GraphicsScene* createGraphicsScene(GraphicsSceneBuilder* graphics_scene_builder
											 ,Project* project
											 ,ModelFile* model_file
											 ,QObject *parent = 0) noexcept;



//-----------------------------------------------------------------------------
// PRIVATE MEMBER FUNCTION
private:

    /// @brief Default constructor.
	BuilderManager() noexcept = default;



    ///@brief Destructor.
    ~BuilderManager() noexcept = default;

};

#endif /* BUILDER_MANAGER_H */
