#include <view/graphicsItem/graphicsItem.h>



//---------------------------------------------------------------------------------------
GraphicsItem::GraphicsItem(ModelFile* model_file
						  ,QGraphicsItem* parent) noexcept
	:QGraphicsItem()
	,model(model_file)
	,left(0)
	,height(0)
	,top(0)
	,width(0)
{}



//---------------------------------------------------------------------------------------
QRectF GraphicsItem::boundingRect() const noexcept
{
	return QRectF(left, top, width, height);
}



//---------------------------------------------------------------------------------------
void GraphicsItem::paint(QPainter* painter,
					     const QStyleOptionGraphicsItem* option,
					     QWidget* widget) noexcept
{

}



//---------------------------------------------------------------------------------------
void GraphicsItem::setBoundingRect(qreal left,
								   qreal top,
								   qreal width,
								   qreal height) noexcept
{
    this->left = left;
    this->top = top;
    this->width = width;
    this->height = height;
}



//---------------------------------------------------------------------------------------
void GraphicsItem::setData() noexcept
{
    this->update();
}



//---------------------------------------------------------------------------------------
void GraphicsItem::setSelection(QVector<double>& selection) noexcept
{
//    this->selection = selection;
    this->update();
}
