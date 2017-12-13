#include <model/modelFile.h>



//---------------------------------------------------------------------------------------
ModelFile::ModelFile() noexcept
		  	:model_project{NULL}
		  	,phase_name{}
		  	,path_template_data_file{}
		  	,project_properties{}
{}



//---------------------------------------------------------------------------------------
ModelFile::ModelFile(Project* project
		  	,ProjectProperties* project_properties
			,QString phase_name
			,QString path_template_data_file
			,QObject* parent) noexcept
	:model_project(project)
	,phase_name(phase_name)
	,path_template_data_file(path_template_data_file)
	,project_properties(project_properties)
{}



//---------------------------------------------------------------------------------------
ModelFile::~ModelFile() noexcept
{

}



//---------------------------------------------------------------------------------------
int ModelFile::columnCount(const QModelIndex& parent) const noexcept
{
    return 1;
}



//---------------------------------------------------------------------------------------
void ModelFile::convertIndexToPoint(QVector< QVector<double> >& delaunay_region_point) const noexcept
{
//	for(int i=0; i<data_file->getNbDelaunayRegion(); i++)
//	{
//		QVector<double> region_point;
//
//		for(int j=0; j<data_file->getNbPointInDelaunayRegion(i); j++)
//		{
//			uint index = data_file->getDelaunayRegionPointIndex(i,j);
//
//			double x,y;
//
//			if(index >= NB_MAX_POINT)
//				x = y = -1;
//			else
//			{
//				FeaturePoint feature_point = data_file->getFeaturePointAt(index);
//				x = feature_point.getX();
//				y = feature_point.getY();
//			}
//
//			region_point.push_back(x);
//			region_point.push_back(y);
//		}
//
//		delaunay_region_point.push_back(region_point);
//	}
}



//---------------------------------------------------------------------------------------
QVariant ModelFile::data(const QModelIndex& index, int role) const noexcept
{
	return QVariant();
}



//---------------------------------------------------------------------------------------
uint ModelFile::findNearestFeaturePoint(QPointF point) const noexcept
{
	uint index = 0;
//	FeaturePoint feature_point = data_file->getFeaturePointAt(index);
//	double distance = feature_point.distance2DToQPointF(point);
//
//	for(int i=0; i<NB_MAX_POINT; i++)
//	{
//		feature_point = data_file->getFeaturePointAt(i);
//		double distance_tmp = feature_point.distance2DToQPointF(point);
//		if(distance > distance_tmp)
//		{
//			distance = distance_tmp;
//			index = i;
//		}
//	}

	return index;
}



//---------------------------------------------------------------------------------------
QVector<QVector<double>> ModelFile::getData() const noexcept
{
	return model_phase;
}



//---------------------------------------------------------------------------------------
QString ModelFile::getPathToCurrentImageFile() const noexcept
{
//	QString image_file = project_properties->template_image_path;
//	char buffer[500];
//	sprintf(buffer, image_file.toStdString().c_str(), current_frame);
//	return buffer;

	return QString{};
}



//---------------------------------------------------------------------------------------
QVector<QString> ModelFile::getInformation() const noexcept
{
	return model_information_selected_data;
}



//---------------------------------------------------------------------------------------
QVector<double> ModelFile::getSelectedData() const noexcept
{
	return model_selected_data;
}



//---------------------------------------------------------------------------------------
QModelIndex ModelFile::index(int row, int column, const QModelIndex &parent) const noexcept
{
	return QModelIndex();
}



//---------------------------------------------------------------------------------------
void ModelFile::init(uint current_frame) noexcept
{
	readDataFile(current_frame);
}



//---------------------------------------------------------------------------------------
QModelIndex	ModelFile::parent(const QModelIndex &index) const noexcept
{
	return QModelIndex();
}



//---------------------------------------------------------------------------------------
int ModelFile::rowCount(const QModelIndex& parent) const noexcept
{
    return NB_MAX_POINT;
}



//---------------------------------------------------------------------------------------
void ModelFile::setSelectedPoint(uint selected_point) noexcept
{
	fillInformation();
	this->selected_point = selected_point;
}



//---------------------------------------------------------------------------------------
void ModelFile::slotMousePressOnScene(QPointF point) noexcept
{
	selected_point = findNearestFeaturePoint(point);
}



////---------------------------------------------------------------------------------------
//void Data::slotSetSelectedProject(QString selected_project) noexcept
//{
//	result_list.clear();
//    result_folder.setSelectedProject(selected_project);
//
//    readMobdecProjectVariable();
//    current_frame = data_file->getStartFrame();
//
//    readFeaturePointFile();
//
//    QVector<QString> existing_result_folder = data_file->getExistingResultFolder();
//    emit(displayExistingResultFolder(existing_result_folder));
//    emit(signalSetStartEnd(data_file->getStartFrame(), data_file->getEndFrame()));
//}



//---------------------------------------------------------------------------------------
void ModelFile::updateData(uint current_frame
					 ,int index_selected_data) noexcept
{
	readDataFile(current_frame);
	convertSelectedData(index_selected_data);
//	sendSignalUpdateData();
//	sendSignalUpdateSelectionInformation();
	emit signalSetCurrentFrame(current_frame);
}




























