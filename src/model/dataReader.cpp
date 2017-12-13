#include <model/dataReader.h>



//---------------------------------------------------------------------------------------
void DataReader::readFeaturePointFile(uint time,
									  QString component_name,
									  const ProjectProperties& project_properties) noexcept
{
	char buffer[500];
	QString path = "feature_point_%03d.txt";
	sprintf(buffer, path.toStdString().c_str(), time);

	std::ifstream file;
	file.open(buffer);

	for(int i=0; i<project_properties.nb_max_point; i++)
	{

	}

	file.close();
}
