#ifndef PROJECT_H
#define PROJECT_H



// Achab
#include <model/modelFileConfidenceValue.h>
#include <model/modelFileDistanceToCamera.h>
#include <model/modelFileFeaturePoint.h>
#include <model/modelFileLabel.h>
#include <model/modelFileTrendUpdateClusterValue.h>
#include <model/modelFileTrendUpdateValue.h>
#include <model/featurepoint.h>
#include <model/projectProperties.h>

// Qt
#include <qdebug.h>
#include <qfile.h>

//class Data;

class Project
{
//---------------------------------------------------------------------------------------
// PROTECTED MEMBER DATA
protected:

	//! The current frame number.
	uint current_frame;

	//!
	QVector<FeaturePoint> feature_point;

    /// List of model.
    QVector<ModelFile*> model;

    //!
    QString path_to_current_image;

	//! The project properties.
    ProjectProperties project_properties;

    //! The index of the selected point.
    int selected_point;



//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
    explicit Project() noexcept;



    ///@brief Destructor.
    virtual ~Project() noexcept = default;



	/// @brief
    ///
    /// @param phase_name
    /// @param file_name
    ///
    /// @return
    ModelFile* createModel(QString phase_name
					 	  ,QString file_name) noexcept;



	/// @brief
	///
	/// @return
	uint getCurrentFrame() noexcept;



	/// @brief
	///
	/// @return
	QString getCurrentFramePath() const noexcept;



	/// @brief
	///
	/// @return
	uint getEndTime() noexcept;



	/// @brief
	///
	/// @return
	QVector<FeaturePoint>& getFeaturePoint() noexcept;



	/// @brief
	///
	/// @return
	int getIndexSelectedData() noexcept;



	/// @brief
	///
	/// @return
	uint getInitializationTime() noexcept;



	/// @brief
	///
	/// @return
	QVector<QVector<QString>> getModelPhaseInformation() const noexcept;



	/// @brief
	///
	/// @return
	QVector<QString>& getProcessPhase() noexcept;



	/// @brief
	///
	/// @return
	QVector<QVector<QString>>& getTemplateResultFile() noexcept;



	/// @brief Increment the current frame number.
	void nextFrame() noexcept;



	/// @brief
	void previousFrame() noexcept;



	/// @brief
	///
	/// @param model_index
	void removeModel(uint model_index) noexcept;



	/// @brief
	///
	/// @param point
	void setSelectedPoint(QPointF point) noexcept;



	/// @brief
	///
	/// @param selected_project
	void setSelectedProject(QString selected_project) noexcept;



	/// @brief
	void updateData() noexcept;


//---------------------------------------------------------------------------------------
// PRIVATE MEMBER FUNCTION
private:



	/// @brief
	///
	/// @param phase_name
	/// @param file_name
	///
	/// @return
	QString createPathToFile(QString phase_name
				  	        ,QString file_name) noexcept;



	/// @brief
	///
	/// @param point
	void findNearestFeaturePoint(QPointF point) noexcept;



	/// @brief
	///
	/// @param file
	void processFeaturePointFile(QFile& file) noexcept;



	/// @brief
	void readFeaturePointFile() noexcept;



	/// @brief
	void updateCurrentImage() noexcept;



	/// @brief
	void updateModel() noexcept;



	/// @brief
	void updateSelectedData() noexcept;

};

#endif /* PROJECT_H */












