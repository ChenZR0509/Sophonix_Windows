/**
 * @file Interface
 * @brief 接口
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "interface.h"
/* Includes< >------------------------------------------------------------------*/
/* Namespace------------------------------------------------------------------*/
namespace Sophonix
{

Interface::Interface(QQmlApplicationEngine* engine, QObject* parent)
    : qmlEngine{engine}, QObject(parent),
      windowInterface{new Ui::UiWindowInterface(qmlEngine,this)}
{
    ;
}

Interface::~Interface()
{
    ;
}


}
