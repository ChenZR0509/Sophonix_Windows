#pragma once
/**
 * @file uiDataType.h
 * @brief UI数据结构
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
/* Includes< >------------------------------------------------------------------*/
#include <QObject>
#include <QtQuick/QQuickPaintedItem>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix::Ui::Basic
{
class UiDataType : public QObject{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_DISABLE_COPY(UiDataType)
public:
    explicit UiDataType(QObject* parent = nullptr){};
    ~UiDataType(void) = default;
    /* DataType Definition------------------------------------------------------------------*/
    /// ViewState 视图状态
    enum ViewState
    {
        ViewNormal,     ///< Normal 视图正常
        ViewEnter,      ///< Enter 视图进场
        ViewExit,       ///< Exit 视图退出
        ViewDuplicate   ///< Duplicate 视图重复进场
    };
    Q_ENUM(ViewState)
    /// FocusState 焦点状态
    enum FocusState
    {
        MenuSelect,        ///< MenuSelect 菜单选择模式
        ChildrenInput,     ///< ChildrenInput 子项输入模式
    };
    Q_ENUM(FocusState)
};
}
Q_DECLARE_METATYPE(Sophonix::Ui::Basic::UiDataType::FocusState)

