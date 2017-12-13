#include <view/mainWindow.h>



//---------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget* parent)
    :QMainWindow(parent)
	,project{}
	,ui(new Ui::ui_MainWindow)
{
    this->showMaximized();
    ui->setupUi(this);

    connect(ui->combo_box_mobdec_project_list, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &MainWindow::slotSetSelectedProject);
    connect(ui->tool_button_next_frame, &QToolButton::clicked, this, &MainWindow::slotNextFrame);
    connect(ui->tool_button_previous_frame, &QToolButton::clicked, this, &MainWindow::slotPreviousFrame);

    connect(ui->widget_mobdec_project_option, &MobdecProjectOption::signalAddResult, this, &MainWindow::slotAddResult);
    connect(ui->widget_mobdec_project_option, &MobdecProjectOption::signalRemoveResult, this, &MainWindow::slotRemoveResult);

    initComboBoxMobdecProject();
	ui->widget_mobdec_project_option->setModelProject(&project);
}



//---------------------------------------------------------------------------------------
int MainWindow::getViewItemIndexByName(QString phase_name
									  ,QString file_name) const
{
	for(int i=0; i<view.size(); i++)
	{
		if(view[i]->objectName() == (phase_name+file_name))
		   return i;
	}

	return -1;
}



//---------------------------------------------------------------------------------------
void MainWindow::initComboBoxMobdecProject()
{
    QString path_to_mobdec_data = "/home/mnchapel/mnchapel/developpement/trunk/mobdec/datas/";
    QDirIterator it(path_to_mobdec_data);

    while(it.hasNext())
    {
        it.next();

        if(it.fileName() == "."
        || it.fileName() == "..")
            continue;

        ui->combo_box_mobdec_project_list->addItem(it.fileName());
    }

    slotSetSelectedProject(ui->combo_box_mobdec_project_list->currentText());
}



//---------------------------------------------------------------------------------------
void MainWindow::slotAddResult(QString phase_name
							  ,QString file_name) noexcept
{
	GraphicsScene* scene;
	QGraphicsView* graphics_view = new QGraphicsView;
	graphics_view->setObjectName(phase_name+file_name);

	ModelFile* model_file = project.createModel(phase_name, file_name);

	if(file_name == "feature_point_%1.txt")
		scene = BuilderManager::createGraphicsScene(new GraphicsItemFeaturePointBuilder{}, &project, model_file, this);
	else if(file_name == "distance_to_camera_%1.txt")
		scene = BuilderManager::createGraphicsScene(new GraphicsItemDistanceToCameraBuilder{}, &project, model_file, this);
	else if(file_name == "confidence_value_%1.txt")
		scene = BuilderManager::createGraphicsScene(new GraphicsItemConfidenceValueBuilder{}, &project, model_file, this);
	else if(file_name == "label_%1.txt")
		scene = BuilderManager::createGraphicsScene(new GraphicsItemLabelBuilder{}, &project, model_file, this);
	else if(file_name == "trend_bonus_malus_value_%1.txt")
		scene = BuilderManager::createGraphicsScene(new GraphicsItemTrendUpdateValueBuilder{}, &project, model_file, this);
	else if(file_name == "trend_cluster_bonus_malus_value_%1.txt")
		scene = BuilderManager::createGraphicsScene(new GraphicsItemTrendUpdateClusterValueBuilder{}, &project, model_file, this);
	else
	{
		qDebug() << file_name << " not known";
		return;
	}

    graphics_view->setScene(scene);
    graphics_view->centerOn(0,0);
    view.push_back(graphics_view);
	ui->grid_layout_view->addWidget(graphics_view, new_view_row, new_view_col);

	new_view_col++;
	if(new_view_col>=nb_max_col_view)
	{
		new_view_col = 0;
		new_view_row++;
	}

	connect(model_file, &ModelFile::signalSetInformation,  ui->widget_mobdec_project_option, &MobdecProjectOption::slotSetInformation);

	connect(scene, &GraphicsScene::signalNextFrame,         this, &MainWindow::slotNextFrame);
	connect(scene, &GraphicsScene::signalPreviousFrame,     this, &MainWindow::slotPreviousFrame);
	connect(scene, &GraphicsScene::signalSetImageScale,		this, &MainWindow::slotSetImageScale);
	connect(scene, &GraphicsScene::signalMousePressOnScene, this, &MainWindow::slotMousePressOnScene);
	connect(scene, &GraphicsScene::signalStartSceneDrag,	this, &MainWindow::slotStartSceneDrag);
	connect(scene, &GraphicsScene::signalStopSceneDrag,		this, &MainWindow::slotStopSceneDrag);

	connect(graphics_view->horizontalScrollBar(), &QScrollBar::valueChanged, this, &MainWindow::slotScrollingHorizontal);
	connect(graphics_view->verticalScrollBar(),   &QScrollBar::valueChanged, this, &MainWindow::slotScrollingVertical);

	connect(this, &MainWindow::signalSetImageScale, scene, &GraphicsScene::slotSetImageScale);

	updateAllScene();

	QVector<QString> vec;
}



//---------------------------------------------------------------------------------------
void MainWindow::slotMousePressOnScene(QPointF point) noexcept
{
	project.setSelectedPoint(point);
	updateAllScene();
	ui->widget_mobdec_project_option->updateInformation();
}



//---------------------------------------------------------------------------------------
void MainWindow::slotNextFrame() noexcept
{
	project.nextFrame();
	ui->label_current_frame->setText(QString::number(project.getCurrentFrame()));
	updateAllScene();
	ui->widget_mobdec_project_option->updateInformation();
}



//---------------------------------------------------------------------------------------
void MainWindow::slotPreviousFrame() noexcept
{
	project.previousFrame();
	ui->label_current_frame->setText(QString::number(project.getCurrentFrame()));
	updateAllScene();
	ui->widget_mobdec_project_option->updateInformation();
}



//---------------------------------------------------------------------------------------
void MainWindow::slotRemoveResult(QString phase_name,
								  QString file_name) noexcept
{
	int item_index = getViewItemIndexByName(phase_name, file_name);
	assert(item_index >= 0 && item_index<view.size());

	int a;
	int b;
	ui->grid_layout_view->getItemPosition(item_index, &new_view_row, &new_view_col, &a, &b);

	view[item_index]->setParent(NULL);
	view.remove(item_index);

	for(int j=item_index; j<view.size(); j++)
	{
		view[j]->setParent(NULL);
		ui->grid_layout_view->addWidget(view[j], new_view_row, new_view_col);

		new_view_col++;
		if(new_view_col>=nb_max_col_view)
		{
			new_view_col = 0;
			new_view_row++;
		}
	}

	project.removeModel(item_index);
}



//---------------------------------------------------------------------------------------
void MainWindow::slotScrollingHorizontal(int value) noexcept
{
	for(int i=0; i<view.size(); i++)
		view[i]->horizontalScrollBar()->setValue(value);
}



//---------------------------------------------------------------------------------------
void MainWindow::slotScrollingVertical(int value) noexcept
{
	for(int i=0; i<view.size(); i++)
		view[i]->verticalScrollBar()->setValue(value);
}



//---------------------------------------------------------------------------------------
void MainWindow::slotSetImageScale() noexcept
{
	emit signalSetImageScale();
}



//---------------------------------------------------------------------------------------
void MainWindow::slotSetSelectedProject(QString selected_project) noexcept
{
	for(int i=0; i<view.size(); i++)
	{
		view[i]->setParent(NULL);
		view.remove(i);
	}

	project.setSelectedProject(selected_project);
	ui->label_current_frame->setText(QString::number(project.getCurrentFrame()));
	ui->label_total_frame->setText(QString::number(project.getEndTime()));

	ui->widget_mobdec_project_option->displayExistingResultFolder(project.getProcessPhase()
																 ,project.getTemplateResultFile());
}



//---------------------------------------------------------------------------------------
void MainWindow::slotStartSceneDrag() noexcept
{
	for(int i=0; i<view.size(); i++)
	{
		view[i]->setDragMode(QGraphicsView::ScrollHandDrag);
	}
}



//---------------------------------------------------------------------------------------
void MainWindow::slotStopSceneDrag() noexcept
{
	for(int i=0; i<view.size(); i++)
	{
		view[i]->setDragMode(QGraphicsView::NoDrag);
		view[i]->setInteractive(true);
	}
}



//---------------------------------------------------------------------------------------
void MainWindow::updateAllScene() noexcept
{
	for(int i=0; i<view.size(); i++)
	{
		GraphicsScene* scene = static_cast<GraphicsScene*>(view[i]->scene());
		scene->updateView();
	}
}









