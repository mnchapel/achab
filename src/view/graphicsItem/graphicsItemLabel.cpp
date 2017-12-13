#include <view/graphicsItem/graphicsItemLabel.h>



//---------------------------------------------------------------------------------------
GraphicsItemLabel::GraphicsItemLabel(ModelFile* model_data
									,QGraphicsItem* parent) noexcept
    : GraphicsItem(model_data,parent)
{
}



//---------------------------------------------------------------------------------------
void GraphicsItemLabel::paintACross(uint x
								   ,uint y
								   ,QPainter* painter) noexcept
{
    painter->drawLine(x-CROSS_SIZE, y, x+CROSS_SIZE, y);
    painter->drawLine(x, y-CROSS_SIZE, x, y+CROSS_SIZE);
}



//---------------------------------------------------------------------------------------
void GraphicsItemLabel::paint(QPainter* painter
							 ,const QStyleOptionGraphicsItem* option
							 ,QWidget* widget) noexcept
{
	QVector<QVector<double>> model_data = model->getData();
	QVector<double> model_selected_data = model->getSelectedData();

    for(int i=0; i<model_data.size(); i++)
    {
        uint x = model_data[i][0];
        uint y = model_data[i][1];
        char label = model_data[i][2];

        if(label == 'S')
        	painter->setPen(Qt::green);
        else if(label == 'M')
        	painter->setPen(Qt::red);
        else if(label == 'C')
        	painter->setPen(Qt::blue);
        else
        	painter->setPen(Qt::white);

		painter->drawEllipse(x,y,2,2);
    }

    painter->setPen(QColor(255,255,0));
    if(model_selected_data.size() == 1)
    {
    	uint i = model_selected_data[0];
		uint x = model_data[i][0];
		uint y = model_data[i][1];

		painter->drawEllipse(x,y,2,2);
    }
}











