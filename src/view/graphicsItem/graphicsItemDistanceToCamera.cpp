#include <view/graphicsItem/graphicsItemDistanceToCamera.h>



//---------------------------------------------------------------------------------------
GraphicsItemDistanceToCamera::GraphicsItemDistanceToCamera(ModelFile* model_data
												  	  	  ,QGraphicsItem* parent) noexcept
    : GraphicsItem(model_data,parent)
{
}



//---------------------------------------------------------------------------------------
void GraphicsItemDistanceToCamera::paintACross(uint x
										  	  ,uint y
											  ,QPainter* painter) noexcept
{
    painter->drawLine(x-CROSS_SIZE, y, x+CROSS_SIZE, y);
    painter->drawLine(x, y-CROSS_SIZE, x, y+CROSS_SIZE);
}



//---------------------------------------------------------------------------------------
void GraphicsItemDistanceToCamera::paint(QPainter* painter
										,const QStyleOptionGraphicsItem* option
										,QWidget* widget) noexcept
{
	QVector<QVector<double>> model_data = model->getData();
	QVector<double> model_selected_data = model->getSelectedData();

    painter->setPen(QColor(255,255,255));
    for(int i=0; i<model_data.size(); i++)
    {
        uint x = model_data[i][0];
        uint y = model_data[i][1];

    	paintACross(x, y, painter);
    }

    painter->setPen(QColor(255,255,0));
    if(model_selected_data.size() == 1)
    {
    	uint i = model_selected_data[0];
		uint x = model_data[i][0];
		uint y = model_data[i][1];

		paintACross(x, y, painter);
    }
}











