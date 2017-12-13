/// @file projectProperties.h
/// @brief Main file
/// @author Marie-Neige Chapel
/// @version 0.1



#ifndef PROJECT_PROPERTIES_H
#define PROJECT_PROPERTIES_H



// Achab
#include <model/resultFileMobdecTemplate.h>

// C++
#include <fstream>
#include <iostream>

// Qt
#include <qdir.h>
#include <qtextstream.h>
#include <qdebug.h>
#include <qfile.h>
#include <QtCore/qstring.h>



class ProjectProperties
{

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER DATA
public:

	//!
	uint end_time = 0;

	//!
	QVector<QString> initialization_phases;

	//!
	uint initialization_time = 0;

	//!
	QString mobdec_data_folder_path = "/home/mnchapel/mnchapel/developpement/trunk/mobdec/datas/";

	//!
	QString name;

	//!
	uint nb_max_point = 0;

	//!
	QVector<QString> process_phases;

	//!
	uint start_time = 0;

	//!
	ResultFileMobdecTemplate result_file_mobdec_template;

	//!
	QString template_feature_point_file;

	//!
	QString template_gt_image_path;

	//!
	QString template_image_path;

	//!
	QVector<QVector<QString>> template_result_file;



//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
	ProjectProperties() = default;



    /// @brief Destructor.
    ~ProjectProperties() = default;



    /// @brief
    void clearAll() noexcept;



    /// @brief
    void setSelectedProject(QString selected_project) noexcept;



//---------------------------------------------------------------------------------------
// PRIVATE MEMBER FUNCTION
private:

    /// @brief
    void findFeaturePointFile() noexcept;



    /// @brief
    void findProcessResultFiles() noexcept;



    /// @brief
    ///
    /// @param identifier
    /// @param data_stream
    void processConfigurationFileLine(const QString identifier,
    								  QTextStream& data_stream) noexcept;



    /// @brief
    void readConfigurationFile() noexcept;

};

#endif /* PROJECT_PROPERTIES_H */
