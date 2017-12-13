#include <model/modelFileDistanceToCamera.h>
#include <model/project.h>



//---------------------------------------------------------------------------------------
ModelFileDistanceToCamera::ModelFileDistanceToCamera(Project* project
					,ProjectProperties* project_properties
					,QString phase_name
		  	  	    ,QString path_template_data_file
		   	   	    ,QObject* parent) noexcept
					:ModelFile(project, project_properties, phase_name, path_template_data_file, parent)
{
	name = "distance_to_camera_%1.txt";
}



//---------------------------------------------------------------------------------------
void ModelFileDistanceToCamera::convertData() noexcept
{
	model_phase.clear();
	QVector<FeaturePoint> feature_point = model_project->getFeaturePoint();

	for(int i=0; i<distance_to_camera.size(); i++)
	{
		QVector<double> data;
		data.push_back(feature_point[i].getX());
		data.push_back(feature_point[i].getY());
		data.push_back(distance_to_camera[i]);

		model_phase.push_back(data);
	}
}



//---------------------------------------------------------------------------------------
void ModelFileDistanceToCamera::convertSelectedData(int index_selected_data) noexcept
{
	model_selected_data.clear();
	if(index_selected_data >= 0)
		model_selected_data.push_back(index_selected_data);

	fillInformation();
}



//---------------------------------------------------------------------------------------
void ModelFileDistanceToCamera::fillInformation() noexcept
{
	model_information_selected_data.clear();
	model_information_selected_data.push_back(phase_name);
	model_information_selected_data.push_back(name);

	uint index_selected_data = model_project->getIndexSelectedData();

	QString distance = QString("Distance to camera %1").arg(QString::number(distance_to_camera[index_selected_data]));

	model_information_selected_data.push_back(distance);
}



//---------------------------------------------------------------------------------------
void ModelFileDistanceToCamera::init(uint current_frame) noexcept
{
	readDataFile(current_frame);
}



//---------------------------------------------------------------------------------------
void ModelFileDistanceToCamera::processDataFile(QFile& file) noexcept
{
	double d;

	QTextStream text_stream(&file);
	while(!text_stream.atEnd())
	{
		text_stream >> d;
		text_stream.readLine();
		distance_to_camera.push_back(d);
	}
}



//---------------------------------------------------------------------------------------
void ModelFileDistanceToCamera::readDataFile(uint current_frame) noexcept
{
	distance_to_camera.clear();

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
