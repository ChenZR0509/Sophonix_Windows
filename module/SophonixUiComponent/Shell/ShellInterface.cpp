/**
 * @file ShellInterface
 * @brief Shell接口
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "shellInterface.h"
/* Includes< >------------------------------------------------------------------*/
#include <QDebug>
/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui::Component
{

ShellInterface::ShellInterface(QQmlApplicationEngine *engine, QObject *parent)
    : qmlEngine{engine}, QObject(parent),
    shellModelManager{new ShellModelManager(this)}
{
    ;
}

ShellInterface::~ShellInterface()
{
    ;
}

}
