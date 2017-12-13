#ifndef GRAPHICS_ITEM_LABEL_BUILDER_H
#define GRAPHICS_ITEM_LABEL_BUILDER_H


// QT

// C++
#include <iostream>

// Achab
#include <view/graphicsBuilder/graphicsSceneBuilder.h>
#include <view/graphicsItem/graphicsItemLabel.h>



/// @class
class GraphicsItemLabelBuilder : public GraphicsSceneBuilder
{

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
	GraphicsItemLabelBuilder() = default;



    /// @brief Copy constructor.
	GraphicsItemLabelBuilder(const GraphicsItemLabelBuilder& graphics_item_label_builder) = default;



    /// @brief Destructor.
    ~GraphicsItemLabelBuilder() = default;



    /// @brief
    void createInformationLayer(ModelFile* model_file) noexcept
	{
		graphics_scene->setInformationLayer(new GraphicsItemLabel{model_file});
	}

};

#endif /* GRAPHICS_ITEM_LABEL_BUILDER_H */
