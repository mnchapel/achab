#ifndef GRAPHICS_ITEM_FEATURE_POINT_BUILDER_H
#define GRAPHICS_ITEM_FEATURE_POINT_BUILDER_H


// QT

// C++
#include <iostream>

// Achab
#include <view/graphicsBuilder/graphicsSceneBuilder.h>



/// @class
class GraphicsItemFeaturePointBuilder : public GraphicsSceneBuilder
{

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
	GraphicsItemFeaturePointBuilder() = default;



    /// @brief Copy constructor.
	GraphicsItemFeaturePointBuilder(const GraphicsItemFeaturePointBuilder& graphics_item_region_builder) = default;



    /// @brief Destructor.
    ~GraphicsItemFeaturePointBuilder() = default;



    /// @brief
    void createInformationLayer(ModelFile* model_file) noexcept
	{
		graphics_scene->setInformationLayer(new GraphicsItemFeaturePoint{model_file});
	}

};

#endif /* GRAPHICS_ITEM_FEATURE_POINT_BUILDER_H */
