/**
 * @file UiWindowInterface
 * @brief UiWindow接口
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "uiWindowInterface.h"
/* Includes< >------------------------------------------------------------------*/
/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui
{

UiWindowInterface::UiWindowInterface(QQmlApplicationEngine *engine, QObject *parent)
    : qmlEngine{engine}, QObject(parent),
    shellInterface{new ShellInterface(qmlEngine, qmlEngine)}
{
    qmlEngine->rootContext()->setContextProperty("sophonixShell", shellInterface->shellModelManager);
}

UiWindowInterface::~UiWindowInterface()
{

}


}
