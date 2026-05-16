/**
 * @file UiShellInterface
 * @brief UiShell接口
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "uiShellInterface.h"
/* Includes< >------------------------------------------------------------------*/
/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui
{

UiShellInterface::UiShellInterface(QQmlApplicationEngine* engine, QObject* parent)
    : qmlEngine{engine}, QObject(parent),
    shellInterface{new Component::ShellInterface(qmlEngine,engine)}
{
    qmlEngine->rootContext()->setContextProperty("sophonixShell", shellInterface);
}

UiShellInterface::~UiShellInterface()
{
    ;
}

}
