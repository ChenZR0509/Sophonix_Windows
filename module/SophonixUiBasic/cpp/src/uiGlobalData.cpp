/**
 * @file uiGlobalData
 * @brief ui全局数据存储
 * @author ChenZR
 * @details
 */
/* Includes" "------------------------------------------------------------------*/
#include "uiGlobalData.h"
/* Includes< >------------------------------------------------------------------*/
/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui::Basic
{

UiGlobalData::UiGlobalData(QObject *parent)
{
    ;
}

UiGlobalData::~UiGlobalData()
{
    ;
}

UiDataType::FocusState UiGlobalData::getFocusState() const
{
    return focusState;
}

void UiGlobalData::setFocusState(const UiDataType::FocusState &newFocusState)
{
    if (focusState == newFocusState)
        return;
    focusState = newFocusState;
    emit focusStateChanged();
}

}
