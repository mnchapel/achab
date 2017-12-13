#include <model/modelFileFeaturePoint.h>
#include <model/project.h>



//---------------------------------------------------------------------------------------
ModelFileFeaturePoint::ModelFileFeaturePoint(Project* project
					,ProjectProperties* project_properties
					,QString phase_name
		  	  	    ,QString path_template_data_file
		   	   	    ,QObject* parent) noexcept
					:ModelFile(project, project_properties, phase_name, path_template_data_file, parent)
{
	name = "feature_point_%1.txt";
}



//---------------------------------------------------------------------------------------
void ModelFileFeaturePoint::convertData() noexcept
{
	model_phase.clear();

	for(int i=0; i<feature_point.size(); i++)
	{
		QVector<double> position;
		position.push_back(feature_point[i].getX());
		position.push_back(feature_point[i].getY());

		model_phase.push_back(position);
	}
}



//---------------------------------------------------------------------------------------
void ModelFileFeaturePoint::convertSelectedData(int index_selected_data) noexcept
{
	model_selected_data.clear();
	if(index_selected_data >= 0)
		model_selected_data.push_back(index_selected_data);

	fillInformation();
}



//---------------------------------------------------------------------------------------
void ModelFileFeaturePoint::fillInformation() noexcept
{
	model_information_selected_data.clear();
	model_information_selected_data.push_back(phase_name);
	model_information_selected_data.push_back(name);

	uint index_selected_data = model_project->getIndexSelectedData();

	QString position 		 = QString("position %1 %2").arg(QString::number(feature_point[index_selected_data].getX())
															,QString::number(feature_point[index_selected_data].getY()));

	model_information_selected_data.push_back(position);
}



//---------------------------------------------------------------------------------------
void ModelFileFeaturePoint::init(uint current_frame) noexcept
{
	readDataFile(current_frame);
//	sendSignalUpdateData();
}



//---------------------------------------------------------------------------------------
void ModelFileFeaturePoint::processDataFile(QFile& file) noexcept
{
	double x;
	double y;

	QTextStream text_stream(&file);
	while(!text_stream.atEnd())
	{
		text_stream >> x;
		text_stream >> y;
		text_stream.readLine();
		FeaturePoint fp{x,y};
		feature_point.push_back(fp);
	}
}



//---------------------------------------------------------------------------------------
void ModelFileFeaturePoint::readDataFile(uint current_frame) noexcept
{
	feature_point.clear();

	QString data_file_path = path_template_data_file.arg(current_frame, 3, 10, QChar('0'));
	QFile file(data_file_path);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Error, the file " << data_file_path << " doesn't exist.";
		return;
		// TODO: manage it
	}

	processDataFile(file);
	convertData();

	file.close();
}
