#include <view/graphicsBuilder/graphicsSceneBuilder.h>



//-----------------------------------------------------------------------------
void GraphicsSceneBuilder::createGraphicsScene(Project* project
											  ,ModelFile* model_file
											  ,QObject* parent) noexcept
{
	graphics_scene = new GraphicsScene{project, model_file, parent};
}



//-----------------------------------------------------------------------------
GraphicsScene* GraphicsSceneBuilder::getGraphicsScene() noexcept
{
	return graphics_scene;
}
