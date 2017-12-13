#ifndef GRAPHICS_ITEM_TREND_UPDATE_VALUE_BUILDER_H
#define GRAPHICS_ITEM_TREND_UPDATE_VALUE_BUILDER_H


// QT

// C++
#include <iostream>

// Achab
#include <view/graphicsBuilder/graphicsSceneBuilder.h>
#include <view/graphicsItem/graphicsItemTrendUpdateValue.h>



/// @class
class GraphicsItemTrendUpdateValueBuilder : public GraphicsSceneBuilder
{

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
	GraphicsItemTrendUpdateValueBuilder() = default;



    /// @brief Copy constructor.
	GraphicsItemTrendUpdateValueBuilder(const GraphicsItemTrendUpdateValueBuilder& copy) = default;



    /// @brief Destructor.
    ~GraphicsItemTrendUpdateValueBuilder() = default;



    /// @brief
    void createInformationLayer(ModelFile* model_file) noexcept
	{
		graphics_scene->setInformationLayer(new GraphicsItemTrendUpdateValue{model_file});
	}

};

#endif /* GRAPHICS_ITEM_TREND_UPDATE_VALUE_BUILDER_H */
