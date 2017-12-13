#ifndef GRAPHICS_ITEM_DISTANCE_TO_CAMERA_BUILDER_H
#define GRAPHICS_ITEM_DISTANCE_TO_CAMERA_BUILDER_H


// QT

// C++
#include <iostream>

// Achab
#include <view/graphicsBuilder/graphicsSceneBuilder.h>
#include <view/graphicsItem/graphicsItemDistanceToCamera.h>



/// @class
class GraphicsItemDistanceToCameraBuilder : public GraphicsSceneBuilder
{

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
	GraphicsItemDistanceToCameraBuilder() = default;



    /// @brief Copy constructor.
	GraphicsItemDistanceToCameraBuilder(const GraphicsItemDistanceToCameraBuilder& graphics_item_region_builder) = default;



    /// @brief Destructor.
    ~GraphicsItemDistanceToCameraBuilder() = default;



    /// @brief
    void createInformationLayer(ModelFile* model_file) noexcept
	{
		graphics_scene->setInformationLayer(new GraphicsItemDistanceToCamera{model_file});
	}

};

#endif /* GRAPHICS_ITEM_DISTANCE_TO_CAMERA_BUILDER_H */
