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
    ShellOutputModel* model = new ShellOutputModel(this);
    models.append(model);
    return models.count()-1;
}

void ShellModelManager::removeModel(int id)
{
    if (id >= models.count() || id < 0)
    {
        return;
    }

    ShellOutputModel* model = models.at(id);
    models.remove(id);
    model->deleteLater();
}

ShellOutputModel* ShellModelManager::getModel(int id)
{
    if (id >= models.count()|| id < 0)
    {
        return nullptr;
    }
    return models[id];
}
}
