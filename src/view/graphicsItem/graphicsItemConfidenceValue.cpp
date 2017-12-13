#include <view/graphicsItem/graphicsItemConfidenceValue.h>



//---------------------------------------------------------------------------------------
GraphicsItemConfidenceValue::GraphicsItemConfidenceValue(ModelFile* model_data
												  	  	  ,QGraphicsItem* parent) noexcept
    : GraphicsItem(model_data,parent)
{
}



//---------------------------------------------------------------------------------------
void GraphicsItemConfidenceValue::paintACross(uint x
										  	  ,uint y
											  ,QPainter* painter) noexcept
{
    painter->drawLine(x-CROSS_SIZE, y, x+CROSS_SIZE, y);
    painter->drawLine(x, y-CROSS_SIZE, x, y+CROSS_SIZE);
}



//---------------------------------------------------------------------------------------
void GraphicsItemConfidenceValue::paint(QPainter* painter
										,const QStyleOptionGraphicsItem* option
										,QWidget* widget) noexcept
{
	double LABEL_ON_CV_THRESHOLD = 0.2;
	QVector<QVector<double>> model_data = model->getData();
	QVector<double> model_selected_data = model->getSelectedData();

	painter->setPen(Qt::white);
    for(int i=0; i<model_data.size(); i++)
    {
        uint x = model_data[i][0];
        uint y = model_data[i][1];
        double confidence_value = model_data[i][2];

        if(confidence_value > LABEL_ON_CV_THRESHOLD)
        	painter->setPen(Qt::green);
        else if(confidence_value < (-1*LABEL_ON_CV_THRESHOLD))
        	painter->setPen(Qt::red);
        else
        	painter->setPen(Qt::blue);

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











