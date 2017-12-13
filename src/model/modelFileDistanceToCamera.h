#ifndef MODEL_FILE_DISTANCE_TO_CAMERA_H
#define MODEL_FILE_DISTANCE_TO_CAMERA_H



// Achab
#include <model/modelFile.h>
#include <model/featurepoint.h>



class ModelFileDistanceToCamera : public ModelFile
{
	Q_OBJECT;

//-----------------------------------------------------------------------------
// PROTECTED MEMBER DATA
protected:

	QVector<double> distance_to_camera;

	QPointF selected_feature_point;


//-----------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Constructor.
    ///
    /// @param project
    /// @param project_properties
    /// @param phase_name
    /// @param path_template_data_file
    /// @param parent
	ModelFileDistanceToCamera(Project* project
							 ,ProjectProperties* project_properties
							 ,QString phase_name
							 ,QString path_template_data_file
							 ,QObject* parent=0) noexcept;



    /// @brief Destructor.
    virtual ~ModelFileDistanceToCamera() noexcept = default;



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

#endif /* MODEL_FILE_DISTANCE_TO_CAMERA_H */
