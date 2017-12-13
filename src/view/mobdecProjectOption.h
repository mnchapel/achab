#ifndef MOBDEC_PROJECT_OPTION_H
#define MOBDEC_PROJECT_OPTION_H



// Achab
#include <../build/ui_mobdecProjectOption.h>
#include <model/project.h>

// C++
#include <iostream>

// Qt
#include <QDebug>
#include <QtCore/qdiriterator.h>
#include <QtWidgets/QCheckBox>
#include <qstandarditemmodel.h>
#include <qtreeview.h>



namespace Ui {
	class ui_mobdecProjectOption;
}



class MobdecProjectOption : public QWidget
{
    Q_OBJECT

//---------------------------------------------------------------------------------------
// PRIVATE MEMBER DATA
private:

	//!
	Project* model_project;

	//!
    Ui::ui_mobdecProjectOption* ui;

    //!
    QTreeView* tree_view = NULL;



//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor
    MobdecProjectOption(QWidget* parent = 0) noexcept;



    /// @brief Destructor.
    ~MobdecProjectOption() = default;



	/// @brief
	///
	/// @param existing_result_folder
	/// @param existing_file
    void displayExistingResultFolder(QVector<QString>& existing_result_folder
			 	 	 	 	 	 	,QVector<QVector<QString>>& existing_file) noexcept;



    /// @brief
    ///
    /// @param information:
    void setInformation(QVector<QString>& information) noexcept;



    /// @brief
    ///
    /// @param project: the model
    void setModelProject(Project* project) noexcept;



    /// @brief
    void updateInformation() noexcept;



//---------------------------------------------------------------------------------------
// PRIVATE MEMBER FUNCTION
private:

    /// @brief
    ///
    /// @param phase_name: the name of the mobdec phase.
    /// @param file_name: the name of the file.
    ///
    /// @return
    QStandardItem* findFileNameItem(QString phase_name
    					 	 	   ,QString file_name) noexcept;



//-----------------------------------------------------------------------------
// SIGNAL
signals:

	/// @brief
	///
	/// @param phase_name
	/// @param file_name
	void signalAddResult(QString phase_name
						,QString file_name);



	/// @brief
	///
	/// @param phase_name
	/// @param file_name
	void signalRemoveResult(QString phase_name
						   ,QString file_name);




//-----------------------------------------------------------------------------
// PRIVATE MEMBER SLOT
public slots:


    /// @brief
    ///
    /// @param state
    void slotResultChecked(int state) noexcept;


    /// @brief
    ///
    /// @param item
    void slotResultCheckedBis(QStandardItem* item) noexcept;


    /// @brief
    ///
    /// @param name:
    /// @param information:
    void slotSetInformation(QString name
						   ,QVector<QString>& information) noexcept;
};

#endif // MOBDEC_PROJECT_OPTION_H
