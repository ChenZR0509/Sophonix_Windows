#pragma once
/**
 * @file UiWindowInterface
 * @brief UiWindow接口
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "shellInterface.h"
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
    using ShellInterface = Sophonix::Ui::Component::ShellInterface;
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
    /// ShellInterface uiShell接口
    ShellInterface* shellInterface = nullptr;
};
}
