#ifndef RESULT_FILE_MOBDEC_TEMPLATE_H
#define RESULT_FILE_MOBDEC_TEMPLATE_H



// Qt
#include <qdebug.h>
#include <QtCore/qstring.h>



class ResultFileMobdecTemplate
{

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER DATA
public:

	QString file_template[6] = {"feature_point_*.txt"
							   ,"confidence_value_*.txt"
							   ,"distance_to_camera_*.txt"
							   ,"label_*.txt"
							   ,"trend_bonus_malus_value_*.txt"
							   ,"trend_cluster_bonus_malus_value_*.txt"};

	uint nb_file_template = 6;



//---------------------------------------------------------------------------------------
// PUBLIC MEMBER DATA
public:

	/// @brief Default constructor.
	ResultFileMobdecTemplate() noexcept = default;

};



#endif /* RESULT_FILE_MOBDEC_TEMPLATE_H */
