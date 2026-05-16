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
    uiShellInterface{new UiShellInterface(qmlEngine, this)}
{

}

UiWindowInterface::~UiWindowInterface()
{

}


}
