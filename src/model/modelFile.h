#ifndef DATA_H
#define DATA_H



// Achab
#include <model/constant.h>
#include <model/featurepoint.h>
#include <model/projectProperties.h>

// Qt
#include <qabstractitemmodel.h>


//#include <model/project.h>
class Project;




class ModelFile : public QAbstractItemModel
{
    Q_OBJECT

//---------------------------------------------------------------------------------------
// PROTECTED MEMBER DATA
protected:

	//!
	QVector<QVector<double>> model_phase;

	//!
	QVector<QString> model_information_selected_data;

	//!
	Project* model_project;

	//!
	QVector<double> model_selected_data;

	//!
	QString phase_name;

	//!
	QString name;

	//!
	QString path_template_data_file;

	//!
    ProjectProperties* project_properties;

    //!
    uint selected_point = 0;


//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
    ModelFile() noexcept;



    /// @brief Constructor.
    ///
    /// @param project_properties
    /// @param path_template_data_file
    /// @param path_template_feature_point_file
    /// @param parent
    ModelFile(Project* project
    	 ,ProjectProperties* project_properties
		 ,QString phase_name
		 ,QString path_template_data_file
		 ,QObject* parent = 0) noexcept;



    ///@brief Destructor.
    virtual ~ModelFile() noexcept;// = default;



    /// @brief
    ///
    /// @param parent
    ///
    /// @return Returns the number of columns for the children of the given parent
    int columnCount(const QModelIndex& parent = QModelIndex()) const noexcept;



    /// @brief
    ///
    /// @param index_selected_data
    virtual void convertSelectedData(int index_selected_data) noexcept = 0;



    /// @brief
    ///
    /// @param index
    /// @param role
    ///
    /// @return Returns the data stored under the given role for the item referred to by the index
    QVariant data(const QModelIndex& index, int role) const noexcept;



    /// @brief
    ///
    /// @return
    QVector<QVector<double>> getData() const noexcept;



    /// @brief
    ///
    /// @return Returns
    QString getPathToCurrentImageFile() const noexcept;



    /// @brief
    ///
    /// @return
    QVector<QString> getInformation() const noexcept;



    /// @brief
    ///
    /// @return
    QVector<double> getSelectedData() const noexcept;



    /// @brief
    ///
    /// @param row
    /// @param column
    /// @param parent
    ///
    /// @return Returns the index of the item in the model specified by the given row, column and parent index.
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const noexcept;



    /// @brief
    ///
    /// @param current_frame
	void init(uint current_frame) noexcept;



	/// @brief
	///
	/// @param index
	///
	/// @return Returns the parent of the model item with the given index.
	/// 		If the item has no parent, an invalid QModelIndex is returned.
	QModelIndex	parent(const QModelIndex &index) const noexcept;



    /// @brief
    ///
    /// @param current_frame
    virtual void readDataFile(uint current_frame) noexcept = 0;



    /// @brief
    ///
    /// @param parent
    ///
    /// @return Returns the number of rows for the children of the given parent
    int rowCount(const QModelIndex& parent = QModelIndex()) const noexcept override;



    /// @brief
    ///
    /// @param selected_point
    void setSelectedPoint(uint selected_point) noexcept;



    /// @brief
    ///
    /// @param current_frame
    /// @param index_selected_data
    void updateData(uint current_frame
    			   ,int index_selected_data) noexcept;



//---------------------------------------------------------------------------------------
// PRIVATE MEMBER FUNCTION
private:

    /// @brief
    ///
    /// @param delaunay_region_point
    void convertIndexToPoint(QVector< QVector<double> >& delaunay_region_point) const noexcept;



    /// @brief
    ///
    /// @return
    virtual void fillInformation() noexcept = 0;



    /// @brief
    ///
    /// @param point
    ///
    /// @return
    uint findNearestFeaturePoint(QPointF point) const noexcept;



    /// @brief
//    virtual void sendSignalUpdateData() noexcept = 0;



    /// @brief
//    virtual void sendSignalUpdateSelectionInformation() noexcept = 0;



//-----------------------------------------------------------------------------
// SIGNAL
signals:

    /// @brief
    ///
    /// @param existing_result_folder
    void displayExistingResultFolder(QVector<QString> existing_result_folder);



    /// @brief
    ///
    /// @param type:
    /// @param name:
    /// @param path_to_image:
    void signalAddGraphicView(QString type
    						 ,QString name
							 ,QString path_to_image);



    /// @brief
    ///
    /// @param name
    void signalRemoveGraphicView(QString name);



    /// @brief
    ///
    /// @param current_frame
    void signalSetCurrentFrame(int current_frame);



    /// @brief
    ///
    /// @param data
    void signalSetBsrLabelSegmentation(QString path_to_image
    				     			  ,QVector< QVector<double> >& data);



    /// @brief
    ///
    /// @param data
    void signalSetConvexLabelClustering(QString path_to_image
    				     				,QVector< QVector<double> >& data);



    /// @brief
    ///
    /// @param data
    void signalSetDelaunayLabelClustering(QString path_to_image
    									 ,QVector< QVector<double> >& data);



    /// @brief
    void signalUpdateData();



    /// @brief
    ///
    /// @param name
    /// @param information
    void signalSetInformation(QString name
    						 ,QVector<QString>& information);



    /// @brief
    ///
    /// @param data
    void signalSetVoronoiSegmentation(QString path_to_image
    								 ,QVector< QVector<double> >& data);



    /// @brief
    ///
    /// @param selection
    void signalSetSelection(QVector<double> selection);



    /// @brief
    ///
    /// @param path_to_image:
    /// @param data:
    void signalUpdateGraphicsSceneData(QString path_to_image
			  	  	  	  	  	      ,QVector< QVector<double> >& data);



    /// @brief
    ///
    /// @param data
    void signalSetGraphCut(QString path_to_image
    					  ,QVector< QVector<double> >& data);



//-----------------------------------------------------------------------------
// PRIVATE MEMBER SLOT
public slots:

	/// @brief
	///
	/// @param point
	void slotMousePressOnScene(QPointF point) noexcept;



    /// @brief
    ///
    /// @param selected_project
//    void slotSetSelectedProject(QString selected_project) noexcept;

};

#endif // DATA_H












