#include <view/graphicsBuilder/builderManager.h>



//---------------------------------------------------------------------------------------
GraphicsScene* BuilderManager::createGraphicsScene(GraphicsSceneBuilder* graphics_scene_builder
		  	  	  	  	  	  	  	  	  	  	  ,Project* project
												  ,ModelFile* model_file
												  ,QObject* parent) noexcept
{
	GraphicsScene* graphics_scene;

	graphics_scene_builder->createGraphicsScene(project, model_file, parent);
	graphics_scene_builder->createInformationLayer(model_file);

	graphics_scene = graphics_scene_builder->getGraphicsScene();

	return graphics_scene;
}
