#ifndef GRAPHICS_SCENE_BUILDER_H
#define GRAPHICS_SCENE_BUILDER_H


// QT
#include <qdebug.h>
#include <qgraphicsscene.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>

// C++
#include <iostream>

// Achab
#include <model/modelFile.h>
#include <model/project.h>
#include <view/graphicsScene.h>



/// @class
class GraphicsSceneBuilder
{

//---------------------------------------------------------------------------------------
// PROTECTED MEMBER DATA
protected:

    ///
    GraphicsScene* graphics_scene = NULL;



//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
    GraphicsSceneBuilder() = default;



    /// @brief Copy constructor.
    GraphicsSceneBuilder(const GraphicsSceneBuilder& graphics_scene_builder) = default;



    /// @brief Destructor.
    virtual ~GraphicsSceneBuilder() = default;



    /// @brief
    ///
    /// @param project
    /// @param model_file
    /// @param parent
    virtual void createGraphicsScene(Project* project
    								,ModelFile* model_file
									,QObject *parent = 0) noexcept;



    /// @brief
    ///
    /// @return
    virtual GraphicsScene* getGraphicsScene() noexcept;



    /// @brief
    ///
    /// @param model
    virtual void createInformationLayer(ModelFile* model_file) = 0;

};

#endif /* GRAPHICS_SCENE_BUILDER_H */
