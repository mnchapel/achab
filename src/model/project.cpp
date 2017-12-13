#include <model/project.h>



//---------------------------------------------------------------------------------------
Project::Project() noexcept
	:current_frame{0}
	,project_properties{}
	,selected_point{-1}
{}



//---------------------------------------------------------------------------------------
ModelFile* Project::createModel(QString phase_name
						  	   ,QString file_name) noexcept
{
	ModelFile* model_file;
	QString path_data_file = createPathToFile(phase_name, file_name);

	if(file_name == "feature_point_%1.txt")
		model_file = new ModelFileFeaturePoint{this, &project_properties, phase_name, path_data_file};
	else if(file_name == "distance_to_camera_%1.txt")
		model_file = new ModelFileDistanceToCamera{this, &project_properties, phase_name, path_data_file};
	else if(file_name == "confidence_value_%1.txt")
		model_file = new ModelFileConfidenceValue{this, &project_properties, phase_name, path_data_file};
	else if(file_name == "label_%1.txt")
		model_file = new ModelFileLabel{this, &project_properties, phase_name, path_data_file};
	else if(file_name == "trend_cluster_bonus_malus_value_%1.txt")
		model_file = new ModelFileTrendUpdateClusterValue{this, &project_properties, phase_name, path_data_file};
	else if(file_name == "trend_bonus_malus_value_%1.txt")
		model_file = new ModelFileTrendUpdateValue{this, &project_properties, phase_name, path_data_file};
	else
	{
		qDebug() << file_name << " not known";
		return NULL;
	}

	model_file->init(current_frame);
	model.push_back(model_file);

	return model_file;
}



//---------------------------------------------------------------------------------------
QString Project::createPathToFile(QString phase_name
						  	     ,QString file_name) noexcept
{
	QString path = project_properties.mobdec_data_folder_path + project_properties.name + "/" + phase_name + "/" + file_name;
	return path;
}



//---------------------------------------------------------------------------------------
void Project::findNearestFeaturePoint(QPointF point) noexcept
{
	double distance = 1000;
	for(int i=0; i<feature_point.size(); i++)
	{
		FeaturePoint fp = feature_point[i];
		double distance_tmp = (point.x()-fp.getX())*(point.x()-fp.getX())
							+ (point.y()-fp.getY())*(point.y()-fp.getY());

		if(distance_tmp<distance)
		{
			distance = distance_tmp;
			selected_point = i;
		}
	}
}



//---------------------------------------------------------------------------------------
uint Project::getCurrentFrame() noexcept
{
	return current_frame;
}



//---------------------------------------------------------------------------------------
QString Project::getCurrentFramePath() const noexcept
{
	QString template_image_path = project_properties.template_image_path;
	QString image_path;

	//TODO: remplacer par un code automatique plutot que de faire des if
	if(template_image_path.indexOf("%02d") >= 0)
	{
		template_image_path.replace("%02d","%1");
		image_path = template_image_path.arg(current_frame, 2, 10, QChar('0'));
	}
	else if(template_image_path.indexOf("%03d") >= 0)
	{
		template_image_path.replace("%03d","%1");
		image_path = template_image_path.arg(current_frame, 3, 10, QChar('0'));
	}
	return image_path;
}



//---------------------------------------------------------------------------------------
uint Project::getEndTime() noexcept
{
	return project_properties.end_time;
}



//---------------------------------------------------------------------------------------
QVector<FeaturePoint>& Project::getFeaturePoint() noexcept
{
	return feature_point;
}



//---------------------------------------------------------------------------------------
int Project::getIndexSelectedData() noexcept
{
	return selected_point;
}



//---------------------------------------------------------------------------------------
uint Project::getInitializationTime() noexcept
{
	return project_properties.initialization_time;
}



//---------------------------------------------------------------------------------------
QVector<QVector<QString>> Project::getModelPhaseInformation() const noexcept
{
	QVector<QVector<QString>> information;

	for(int i=0; i<model.size(); i++)
	{
		QVector<QString> model_phase_information = model[i]->getInformation();
		information.push_back(model_phase_information);
	}

	return information;
}



//---------------------------------------------------------------------------------------
QVector<QString>& Project::getProcessPhase() noexcept
{
	return project_properties.process_phases;
}



//---------------------------------------------------------------------------------------
QVector<QVector<QString>>& Project::getTemplateResultFile() noexcept
{
	return project_properties.template_result_file;
}



//---------------------------------------------------------------------------------------
void Project::nextFrame() noexcept
{
	if(current_frame<project_properties.end_time)
		current_frame++;

	updateData();
}



//---------------------------------------------------------------------------------------
void Project::previousFrame() noexcept
{
	if(current_frame>project_properties.initialization_time)
		current_frame--;

	updateData();
}



//---------------------------------------------------------------------------------------
void Project::processFeaturePointFile(QFile& file) noexcept
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
void Project::readFeaturePointFile() noexcept
{
	feature_point.clear();

	QString feature_point_template = project_properties.template_feature_point_file;
	QString path = feature_point_template.arg(current_frame, 3, 10, QChar('0'));
	QFile file(path);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Error, the file " << path << " doesn't exist.";
		// TODO: manage it
	}

	processFeaturePointFile(file);

	file.close();
}



//---------------------------------------------------------------------------------------
void Project::removeModel(uint model_index) noexcept
{
	model.removeAt(model_index);
}



//---------------------------------------------------------------------------------------
void Project::setSelectedPoint(QPointF point) noexcept
{
	findNearestFeaturePoint(point);
	updateSelectedData();
}



//---------------------------------------------------------------------------------------
void Project::setSelectedProject(QString selected_project) noexcept
{
	project_properties.setSelectedProject(selected_project);
	current_frame = project_properties.initialization_time;
	updateData();
}



//---------------------------------------------------------------------------------------
void Project::updateCurrentImage() noexcept
{
	QString template_image_path = project_properties.template_image_path;
	path_to_current_image = template_image_path.arg(QString::number(current_frame));
}



//---------------------------------------------------------------------------------------
void Project::updateData() noexcept
{
	updateCurrentImage();
	readFeaturePointFile();
	updateModel();
	updateSelectedData();
}



//---------------------------------------------------------------------------------------
void Project::updateModel() noexcept
{
	for(int i=0; i<model.size(); i++)
		model[i]->readDataFile(current_frame);
}



//---------------------------------------------------------------------------------------
void Project::updateSelectedData() noexcept
{
	for(int i=0; i<model.size(); i++)
		model[i]->convertSelectedData(selected_point);
}














