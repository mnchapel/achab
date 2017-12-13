#ifndef GRAPHICS_ITEM_CONFIDENCE_VALUE_BUILDER_H
#define GRAPHICS_ITEM_CONFIDENCE_VALUE_BUILDER_H


// QT

// C++
#include <iostream>

// Achab
#include <view/graphicsBuilder/graphicsSceneBuilder.h>
#include <view/graphicsItem/graphicsItemConfidenceValue.h>



/// @class
class GraphicsItemConfidenceValueBuilder : public GraphicsSceneBuilder
{

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
	GraphicsItemConfidenceValueBuilder() = default;



    /// @brief Copy constructor.
	GraphicsItemConfidenceValueBuilder(const GraphicsItemConfidenceValueBuilder& graphics_item_confidence_value_builder) = default;



    /// @brief Destructor.
    ~GraphicsItemConfidenceValueBuilder() = default;



    /// @brief
    void createInformationLayer(ModelFile* model_file) noexcept
	{
		graphics_scene->setInformationLayer(new GraphicsItemConfidenceValue{model_file});
	}

};

#endif /* GRAPHICS_ITEM_CONFIDENCE_VALUE_BUILDER_H */
