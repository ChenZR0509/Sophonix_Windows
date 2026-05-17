/**
 * @file shellModelManager
 * @brief shell模型管理
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "shellModelManager.h"
/* Includes< >------------------------------------------------------------------*/

/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui::Component
{

ShellModelManager::ShellModelManager(QObject *parent)
    : QObject(parent)
{
    addModel();
}

ShellModelManager::~ShellModelManager()
{
    ;
}

int ShellModelManager::addModel()
{
    ShellModel* model = new ShellModel(this);
    models.append(model);
    return models.count()-1;
}

void ShellModelManager::removeModel(int id)
{
    if (id >= models.count() || id < 0)
    {
        return;
    }

    ShellModel* model = models.at(id);
    models.remove(id);
    model->deleteLater();
}

ShellModel* ShellModelManager::getModel(int id)
{
    if (id >= models.count()|| id < 0)
    {
        return nullptr;
    }
    return models[id];
}

void ShellModelManager::appendData(const ShellModel::LogInfo &data, int id)
{
    if (id >= models.count()|| id < 0)
    {
        return;
    }
    models[id]->appendData(data);
}


}
