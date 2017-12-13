#include <model/featurepoint.h>



//---------------------------------------------------------------------------------------
FeaturePoint::FeaturePoint() noexcept
    :age{0}
	,confidence_value{0}
	,distance_to_camera{0}
	,label{Labeling::UNLABELED}
	,x{0}
	,y{0}
{}



//---------------------------------------------------------------------------------------
FeaturePoint::FeaturePoint(double x
						  ,double y) noexcept
    :age{0}
    ,confidence_value{0}
    ,distance_to_camera{0}
    ,label{Labeling::UNLABELED}
    ,x{x}
	,y{y}
{}



//---------------------------------------------------------------------------------------
double FeaturePoint::distance2DToFeaturePoint(FeaturePoint& feature_point) const noexcept
{
	return sqrt((x-feature_point.x)*(x-feature_point.x)
			   +(y-feature_point.y)*(y-feature_point.y));
}



//---------------------------------------------------------------------------------------
double FeaturePoint::distance2DToQPointF(QPointF& point) const noexcept
{
	return sqrt((x-point.x())*(x-point.x())
			   +(y-point.y())*(y-point.y()));
}



//---------------------------------------------------------------------------------------
double FeaturePoint::getConfidenceValue() const noexcept
{
	return confidence_value;
}



//---------------------------------------------------------------------------------------
double FeaturePoint::getLabel() const noexcept
{
	return label;
}



//---------------------------------------------------------------------------------------
double FeaturePoint::getX() const noexcept
{
	return x;
}



//---------------------------------------------------------------------------------------
double FeaturePoint::getY() const noexcept
{
	return y;
}



//---------------------------------------------------------------------------------------
void FeaturePoint::setConfidenceValue(double confidence_value) noexcept
{
	this->confidence_value = confidence_value;
}



//---------------------------------------------------------------------------------------
void FeaturePoint::setLabel(double label) noexcept
{
	this->label = label;
}



//---------------------------------------------------------------------------------------
void FeaturePoint::setX(double x) noexcept
{
	this->x = x;
}



//---------------------------------------------------------------------------------------
void FeaturePoint::setY(double y) noexcept
{
	this->y = y;
}
