/**
 * @file sophonixCore
 * @brief 智子内核
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "sophonixCore.h"
/* Includes< >------------------------------------------------------------------*/
#include <QDebug>
/* Namespace------------------------------------------------------------------*/
namespace Sophonix
{

SophonixCore::SophonixCore(QQmlApplicationEngine* engine, QObject* parent)
    : qmlEngine{engine}, QObject(parent),
    qmlInterface{new Interface(qmlEngine, this)}
{
    ;
}

SophonixCore::~SophonixCore()
{

}


}
