#include <view/graphicsScene.h>


double GraphicsScene::image_scale = 1;


//---------------------------------------------------------------------------------------
GraphicsScene::GraphicsScene(QObject* parent) noexcept
    : image_layer{}
	, information_layer{}
	, QGraphicsScene{parent}
{}


//---------------------------------------------------------------------------------------
GraphicsScene::GraphicsScene(Project* project
							,ModelFile* model
							,QObject* parent) noexcept
    :project(project)
	,model(model)
	,information_layer{new GraphicsItem{model}}
	,QGraphicsScene{parent}
{
	QString path_to_image = model->getPathToCurrentImageFile();
	image_layer = new QGraphicsPixmapItem{QPixmap(path_to_image)};

    this->addItem(image_layer);
    this->addItem(information_layer);

	connect(model, &ModelFile::signalUpdateData,   this, &GraphicsScene::slotUpdateView);
	connect(model, &ModelFile::signalSetSelection, this, &GraphicsScene::slotSetSelection);

	slotSetImageScale();
}



//---------------------------------------------------------------------------------------
GraphicsScene::~GraphicsScene() noexcept
{}



//---------------------------------------------------------------------------------------
QGraphicsPixmapItem* GraphicsScene::getImageLayer() const noexcept
{
	return image_layer;
}



//---------------------------------------------------------------------------------------
void GraphicsScene::keyPressEvent(QKeyEvent* key_event) noexcept
{
	if(key_event->key() == Qt::Key_Left)
		emit signalPreviousFrame();
	else if(key_event->key() == Qt::Key_Right)
		emit signalNextFrame();
	else if(key_event->key() == Qt::Key_Control)
	{
		isDragging = true;
		emit signalStartSceneDrag();
	}
}



//---------------------------------------------------------------------------------------
void GraphicsScene::keyReleaseEvent(QKeyEvent* key_event) noexcept
{
	if(key_event->key() == Qt::Key_Control)
	{
		isDragging = false;
		emit signalStopSceneDrag();
	}
}



//---------------------------------------------------------------------------------------
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event) noexcept
{
	if(event->button() == Qt::LeftButton
	&& !isDragging)
	{
		drag_start_position = event->scenePos();
		emit signalMousePressOnScene(event->scenePos()/image_scale);
	}
}



//---------------------------------------------------------------------------------------
void GraphicsScene::setInformationLayer(GraphicsItem* information_layer) noexcept
{
	this->removeItem(this->information_layer);
	this->information_layer = information_layer;
    this->information_layer->setScale(image_scale);
	information_layer->setBoundingRect(0,0,image_layer->pixmap().width()*image_scale,image_layer->pixmap().height()*image_scale);
	this->addItem(this->information_layer);
}



//---------------------------------------------------------------------------------------
void GraphicsScene::slotSetImageScale() noexcept
{
	image_layer->setScale(image_scale);
    information_layer->setScale(image_scale);

	this->setSceneRect(0,0,image_layer->pixmap().width()*image_scale,image_layer->pixmap().height()*image_scale);
}



//---------------------------------------------------------------------------------------
void GraphicsScene::slotSetSelection(QVector<double> selection) noexcept
{
	information_layer->setSelection(selection);
	this->update();
}



//---------------------------------------------------------------------------------------
void GraphicsScene::slotUpdateView() noexcept
{
	QString path_to_image = project->getCurrentFramePath();
    image_layer->setPixmap(QPixmap(path_to_image));
//	information_layer->setData(data);
    information_layer->update();
}



//---------------------------------------------------------------------------------------
void GraphicsScene::updateView() noexcept
{
	slotUpdateView();
}



//---------------------------------------------------------------------------------------
void GraphicsScene::wheelEvent(QGraphicsSceneWheelEvent* event) noexcept
{
	if(event->delta()>0)
		image_scale += 0.1;
	else
		image_scale -= 0.1;

	image_scale = (image_scale<0)?0:image_scale;

	event->accept();
	emit signalSetImageScale();
}
















