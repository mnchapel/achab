/// @file projectProperties.cpp
/// @brief Main file
/// @author Marie-Neige Chapel
/// @version 0.1



#include <model/projectProperties.h>



//---------------------------------------------------------------------------------------
void ProjectProperties::clearAll() noexcept
{
	end_time = 0;
	initialization_phases.clear();
	initialization_time = 0;
	name = "";
	nb_max_point = 0;
	process_phases.clear();
	start_time = 0;
	template_gt_image_path = "";
	template_image_path = "";
}



//---------------------------------------------------------------------------------------
void ProjectProperties::findFeaturePointFile() noexcept
{
	uint nb_process_phase = process_phases.size();
	for(int i=0; i<nb_process_phase; i++)
	{
		uint nb_file = template_result_file[i].size();
		for(int j=0; j<nb_file; j++)
		{
			if(template_result_file[i][j] == "feature_point_%1.txt")
				template_feature_point_file = mobdec_data_folder_path + name + "/" + process_phases[i] + "/feature_point_%1.txt";
		}
	}
}



//---------------------------------------------------------------------------------------
void ProjectProperties::findProcessResultFiles() noexcept
{
	template_result_file.clear();
	QString file_template[6] = result_file_mobdec_template.file_template;
	uint nb_file_template   = result_file_mobdec_template.nb_file_template;

	uint nb_process_phase = process_phases.size();
	for(int i=0; i<nb_process_phase; i++)
	{
		QString file_template_path = mobdec_data_folder_path + name + "/" + process_phases[i] + "/";
		QDir dir(file_template_path.toStdString().c_str());
		QStringList filter;
		QVector<QString> file_template_process;

		for(int j=0; j<nb_file_template; j++)
		{
			filter << file_template[j];
			QStringList dirs = dir.entryList(filter);
			if(dirs.size()>0)
			{
				QString template_file = file_template[j];
				template_file.replace("*","%1");
				file_template_process.push_back(template_file);
			}

			filter.clear();
		}

		template_result_file.push_back(file_template_process);
	}
}



//---------------------------------------------------------------------------------------
void ProjectProperties::processConfigurationFileLine(const QString identifier,
													 QTextStream& data_stream) noexcept
{
    if(identifier == "END")
    	data_stream >> end_time;
    else if(identifier == "INITIALIZATION_PHASES")
    {
        QString phase;
        data_stream >> phase;
        while(phase != "end" && !data_stream.atEnd())
        {
        	initialization_phases.push_back(phase);
        	data_stream >> phase;
        }
    }
    else if(identifier == "INITIALIZATION_TIME")
    	data_stream >> initialization_time;
    else if(identifier == "PROCESS_PHASES")
    {
        QString phase;
        data_stream >> phase;
        while(phase != "end" && !data_stream.atEnd())
        {
        	process_phases.push_back(phase);
        	data_stream >> phase;
        }
    }
    else if(identifier == "START")
    	data_stream >> start_time;
    else if(identifier == "TEMPLATE_GT_IMAGE_PATH")
    	data_stream >> template_gt_image_path;
    else if(identifier == "TEMPLATE_IMAGE_PATH")
    	data_stream >> template_image_path;
}



//---------------------------------------------------------------------------------------
void ProjectProperties::readConfigurationFile() noexcept
{
    QString identifier;
    QString garbage;
	QString path = mobdec_data_folder_path + name + "/launch_" + name + ".txt";

	QFile file(path);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Error, the file " << path << " doesn't exist.";
		// TODO: manage it
	}

	QTextStream text_stream(&file);

    if(!text_stream.atEnd())
    	text_stream >> identifier;

	while(!text_stream.atEnd())
	{
        if(identifier[0] != '#')
        	processConfigurationFileLine(identifier, text_stream);
        else
            text_stream.readLine();

        text_stream >> identifier;
	}

	file.close();
}



//---------------------------------------------------------------------------------------
void ProjectProperties::setSelectedProject(QString selected_project) noexcept
{
	clearAll();

	name = selected_project;
	readConfigurationFile();
	findProcessResultFiles();
	findFeaturePointFile();
}









