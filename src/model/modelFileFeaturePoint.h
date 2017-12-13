#ifndef DATA_POINT_H
#define DATA_POINT_H



// Achab
#include <model/modelFile.h>
#include <model/featurepoint.h>



class ModelFileFeaturePoint : public ModelFile
{
	Q_OBJECT;

//-----------------------------------------------------------------------------
// PROTECTED MEMBER DATA
protected:

	QVector<FeaturePoint> feature_point;

	QPointF selected_feature_point;


//-----------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Constructor.
	ModelFileFeaturePoint(Project* project
			 ,ProjectProperties* project_properties
			 ,QString phase_name
			 ,QString path_template_data_file
			 ,QObject* parent=0) noexcept;



    /// @brief Destructor.
    virtual ~ModelFileFeaturePoint() noexcept = default;



    /// @brief
    void convertSelectedData(int index_selected_data) noexcept override;



    /// @brief
    ///
    /// @param current_frame
    void init(uint current_frame) noexcept;



    /// @brief
    ///
    /// @param current_frame
    void readDataFile(uint current_frame) noexcept override;



//-----------------------------------------------------------------------------
// PRIVATE MEMBER FUNCTION
private:

    /// @brief
    void convertData() noexcept;



    /// @brief
    void fillInformation() noexcept override;



    /// @brief
    ///
    /// @param file
    void processDataFile(QFile& file) noexcept;

};

#endif
