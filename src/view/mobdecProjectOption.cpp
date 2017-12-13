#include <view/mobdecProjectOption.h>



//---------------------------------------------------------------------------------------
MobdecProjectOption::MobdecProjectOption(QWidget* parent) noexcept
    :QWidget{parent}
	,model_project(NULL)
    ,ui(new Ui::ui_mobdecProjectOption)
{
    ui->setupUi(this);
}



//---------------------------------------------------------------------------------------
void MobdecProjectOption::displayExistingResultFolder(QVector<QString>& existing_result_folder
													 ,QVector<QVector<QString>>& existing_file) noexcept
{
    // Delete previous QCheckBox
//    while(QLayoutItem* item = ui->vertical_layout->takeAt(0))
//    {
//        QWidget* widget = item->widget();
//        delete widget;
//    }

    QStandardItemModel* standard_model = new QStandardItemModel;
    QStandardItem* root_node = standard_model->invisibleRootItem();

    for(int i=0; i<existing_result_folder.size(); i++)
    {
        QStandardItem* standard_item = new QStandardItem(existing_result_folder[i]);
        root_node->appendRow(standard_item);

        for(int j=0; j<existing_file[i].size(); j++)
        {
            QStandardItem* standard_subitem = new QStandardItem(existing_file[i][j]);
            standard_subitem->setCheckable(true);
            standard_item->appendRow(standard_subitem);
        }
    }

    connect(standard_model, &QStandardItemModel::itemChanged, this, &MobdecProjectOption::slotResultCheckedBis);
    ui->treeView->setModel(standard_model);
    ui->treeView->setStyleSheet("QTreeView{show-decoration-selected: 1;} \\"
    							"QTreeView::item{border: 1px solid #d9d9d9; border-top-color: transparent; border-bottom-color: transparent;} \\"
    							"QTreeView::item:hover{background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e7effd, stop: 1 #cbdaf1); border: 1px solid #bfcde4;}"
    							);
}



//---------------------------------------------------------------------------------------
QStandardItem* MobdecProjectOption::findFileNameItem(QString phase_name
										  	  	  	,QString file_name) noexcept
{
	QStandardItem* result_phase_item;
	QStandardItem* result_file_item;
	QStandardItemModel* standard_model = (QStandardItemModel*)ui->treeView->model();

	for(int i=0; i<standard_model->rowCount(); i++)
	{
		result_phase_item = standard_model->item(i,0);
		QString item_name = result_phase_item->text();

		if(item_name == phase_name)
			break;
	}

	for(int i=0; i<result_phase_item->rowCount(); i++)
	{
		result_file_item = result_phase_item->child(i,0);
		QString item_name = result_file_item->text();

		if(item_name == phase_name)
			break;
	}

	return result_file_item;
}



//---------------------------------------------------------------------------------------
void MobdecProjectOption::setInformation(QVector<QString>& information) noexcept
{
	assert(information.size() >= 2);

	QString phase_name = information[0];
	QString file_name  = information[1];

	QStandardItem* result_file_item = findFileNameItem(phase_name, file_name);

	// Delete previous display
	while(result_file_item->rowCount() > 0)
		result_file_item->removeRow(0);

	for(int i=2; i<information.size(); i++)
	{
        QStandardItem* standard_item = new QStandardItem(information[i]);
        result_file_item->appendRow(standard_item);
	}

	ui->treeView->expandAll();
}



//---------------------------------------------------------------------------------------
void MobdecProjectOption::setModelProject(Project* project) noexcept
{
	this->model_project = project;
}



//---------------------------------------------------------------------------------------
void MobdecProjectOption::slotResultChecked(int state) noexcept
{}



//---------------------------------------------------------------------------------------
void MobdecProjectOption::slotResultCheckedBis(QStandardItem* item) noexcept
{
	QString file_name = item->text();
	QString phase_name = item->parent()->text();

	file_name.replace("*","%03d");

	if(item->checkState() == Qt::Checked)
		emit signalAddResult(phase_name,file_name);
	else
		emit signalRemoveResult(phase_name,file_name);
}



//---------------------------------------------------------------------------------------
void MobdecProjectOption::slotSetInformation(QString name
											,QVector<QString>& information) noexcept
{
	QStandardItem* result_item;
	QStandardItemModel* standard_model = (QStandardItemModel*)ui->treeView->model();

	for(int i=0; i<standard_model->rowCount(); i++)
	{
		result_item = standard_model->item(i,0);
		QString item_name = result_item->text();

		if(item_name == name)
			break;
	}

	// Delete previous display
	while(result_item->rowCount() > 0)
		result_item->removeRow(0);

	for(int i=0; i<information.size(); i++)
	{
        QStandardItem* standard_item = new QStandardItem(information[i]);
        result_item->appendRow(standard_item);
	}

	ui->treeView->expandAll();
}



//---------------------------------------------------------------------------------------
void MobdecProjectOption::updateInformation() noexcept
{
	QVector<QVector<QString>> information = model_project->getModelPhaseInformation();

	for(int i=0; i<information.size(); i++)
		setInformation(information[i]);
}



















