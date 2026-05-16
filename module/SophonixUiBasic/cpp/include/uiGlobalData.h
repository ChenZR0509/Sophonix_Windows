#pragma once
/**
 * @file uiGlobalData.h
 * @brief ui全局数据
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "uiDataType.h"
/* Includes< >------------------------------------------------------------------*/
#include <QObject>
#include <QtQuick/QQuickPaintedItem>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix::Ui::Basic
{
class UiGlobalData : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_DISABLE_COPY(UiGlobalData)
public:
    /* DataType Definition------------------------------------------------------------------*/
    /* Variable Declare------------------------------------------------------------------*/
    /* Functions Declare------------------------------------------------------------------*/
    explicit UiGlobalData(QObject* parent = nullptr);
    ~UiGlobalData(void);
private:
    UiDataType::FocusState focusState = UiDataType::MenuSelect;
private:
    Q_PROPERTY(UiDataType::FocusState focusState READ getFocusState WRITE setFocusState NOTIFY focusStateChanged FINAL)
public:
    UiDataType::FocusState getFocusState() const;
    void setFocusState(const UiDataType::FocusState &newFocusState);
signals:
    void focusStateChanged();
protected:
};
}
