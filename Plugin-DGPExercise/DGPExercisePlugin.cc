#include "DGPExercisePlugin.hh"

#include "EigenTutorial.hh"

void DGPExercisePlugin::initializePlugin()
{

    tool_ = new DGPExerciseToolbar();
    QSize size(300,300);
    tool_->resize(size);

    connect(tool_->solve_sls_pb, SIGNAL(clicked()), this, SLOT(slot_solve_sparse_linear_system()));

    emit addToolbox( tr("DGPExercise") , tool_ );
}


void DGPExercisePlugin::pluginsInitialized()
{
}

void DGPExercisePlugin::slot_solve_sparse_linear_system()
{
    EigenTutorial et;
    et.solve_sparse_linear_system();
}

//======================================================================================================================
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(tetctplugin, TetCTPlugin);
#endif