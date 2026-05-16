#pragma once
/**
 * @file UiWindowInterface
 * @brief UiWindow接口
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "UiShell/uiShellInterface.h"
/* Includes< >------------------------------------------------------------------*/
#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui
{
class UiWindowInterface: public QObject
{
    Q_OBJECT
public:
    /**
     * @name UiWindowInterface
     * @brief 构造函数
     *
     * @param[in] engine qml引擎
     * @param[in] parent 对象树父节点
     */
    explicit UiWindowInterface(QQmlApplicationEngine* engine = nullptr, QObject* parent = nullptr);
    /**
     * @name ~UiWindowInterface
     * @brief 析构函数
     */
    ~UiWindowInterface();
private:
    /// qmlEngine 前端引擎
    QQmlApplicationEngine* qmlEngine = nullptr;
    /// uiShellInterface uiShell接口
    UiShellInterface* uiShellInterface = nullptr;
};
}
