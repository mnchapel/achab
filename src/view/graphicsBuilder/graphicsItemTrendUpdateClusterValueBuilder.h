#ifndef GRAPHICS_ITEM_TREND_UPDATE_CLUSTER_VALUE_BUILDER_H
#define GRAPHICS_ITEM_TREND_UPDATE_CLUSTER_VALUE_BUILDER_H


// QT

// C++
#include <iostream>

// Achab
#include <view/graphicsBuilder/graphicsSceneBuilder.h>
#include <view/graphicsItem/graphicsItemTrendUpdateClusterValue.h>



/// @class
class GraphicsItemTrendUpdateClusterValueBuilder : public GraphicsSceneBuilder
{

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
	GraphicsItemTrendUpdateClusterValueBuilder() = default;



    /// @brief Copy constructor.
	GraphicsItemTrendUpdateClusterValueBuilder(const GraphicsItemTrendUpdateClusterValueBuilder& copy) = default;



    /// @brief Destructor.
    ~GraphicsItemTrendUpdateClusterValueBuilder() = default;



    /// @brief
    void createInformationLayer(ModelFile* model_file) noexcept
	{
		graphics_scene->setInformationLayer(new GraphicsItemTrendUpdateClusterValue{model_file});
	}

};

#endif /* GRAPHICS_ITEM_TREND_UPDATE_CLUSTER_VALUE_BUILDER_H */
