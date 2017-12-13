#include <model/modelFileTrendUpdateClusterValue.h>
#include <model/project.h>



//---------------------------------------------------------------------------------------
ModelFileTrendUpdateClusterValue::ModelFileTrendUpdateClusterValue(Project* project
																  ,ProjectProperties* project_properties
																  ,QString phase_name
																  ,QString path_template_data_file
																  ,QObject* parent) noexcept
																  :ModelFile(project, project_properties, phase_name, path_template_data_file, parent)
{
	name = "trend_cluster_bonus_malus_%1.txt";
}



//---------------------------------------------------------------------------------------
void ModelFileTrendUpdateClusterValue::convertData() noexcept
{
	model_phase.clear();
	QVector<FeaturePoint> feature_point = model_project->getFeaturePoint();

	for(int i=0; i<trend_update_cluster_value.size(); i++)
	{
		QVector<double> data;
		data.push_back(feature_point[i].getX());
		data.push_back(feature_point[i].getY());
		data.push_back(trend_update_cluster_value[i]);

		model_phase.push_back(data);
	}
}



//---------------------------------------------------------------------------------------
void ModelFileTrendUpdateClusterValue::convertSelectedData(int index_selected_data) noexcept
{
	model_selected_data.clear();
	if(index_selected_data >= 0)
		model_selected_data.push_back(index_selected_data);

	fillInformation();
}



//---------------------------------------------------------------------------------------
void ModelFileTrendUpdateClusterValue::fillInformation() noexcept
{
	model_information_selected_data.clear();
	model_information_selected_data.push_back(phase_name);
	model_information_selected_data.push_back(name);

	uint index_selected_data = model_project->getIndexSelectedData();

	QString distance = QString("Update cluster value %1").arg(QString::number(trend_update_cluster_value[index_selected_data]));

	model_information_selected_data.push_back(distance);
}



//---------------------------------------------------------------------------------------
void ModelFileTrendUpdateClusterValue::init(uint current_frame) noexcept
{
	readDataFile(current_frame);
}



//---------------------------------------------------------------------------------------
void ModelFileTrendUpdateClusterValue::processDataFile(QFile& file) noexcept
{
	uint cluster_index;
	double ucv;

	QTextStream text_stream(&file);
	while(!text_stream.atEnd())
	{
		text_stream >> cluster_index;
		text_stream >> ucv;
		text_stream.readLine();
		trend_update_cluster_value.push_back(ucv);
	}
}



//---------------------------------------------------------------------------------------
void ModelFileTrendUpdateClusterValue::readDataFile(uint current_frame) noexcept
{
	trend_update_cluster_value.clear();

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
