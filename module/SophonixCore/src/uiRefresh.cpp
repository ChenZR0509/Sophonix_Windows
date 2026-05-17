/**
 * @file uiRefresh
 * @brief ui刷新
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "uiRefresh.h"
/* Includes< >------------------------------------------------------------------*/
/* Namespace------------------------------------------------------------------*/
namespace Sophonix
{

UiRefresh::UiRefresh(QObject* parent)
    : RunnableThread(parent)
{
    ;
}

UiRefresh::~UiRefresh()
{
    ;
}

void UiRefresh::initFunction()
{
    uiLimit.timerStart();
}

void UiRefresh::pauseFunction()
{
    uiLimit.timerPause();
}

void UiRefresh::resumeFunction()
{
    uiLimit.timerResume();
}

void UiRefresh::workFunction()
{
    if(uiLimit.tryRun())
    {
        emit refresh();
    }
}

void UiRefresh::unInitFunction()
{
    uiLimit.timerPause();
}


}
