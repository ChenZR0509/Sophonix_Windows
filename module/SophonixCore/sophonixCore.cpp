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
    qmlRefresh{new UiRefresh(this)},
    qmlInterface{new Interface(qmlEngine, this)}
{
    auto threadPool = QThreadPool::globalInstance();
    threadPool->start(qmlRefresh);
    qmlRefresh->startThread();
}

SophonixCore::~SophonixCore()
{

}


}
