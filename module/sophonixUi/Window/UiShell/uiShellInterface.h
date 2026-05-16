#pragma once
/**
 * @file UiShellInterface
 * @brief UiShell接口
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
class UiShellInterface: public QObject
{
    Q_OBJECT
private:
    using ShellInterface = Component::ShellInterface;
public:
    /**
     * @name UiShellInterface
     * @brief 构造函数
     *
     * @param[in] engine qml引擎
     * @param[in] parent 对象树父节点
     */
    explicit UiShellInterface(QQmlApplicationEngine* engine = nullptr, QObject* parent = nullptr);
    /**
     * @name ~UiShellInterface
     * @brief 析构函数
     */
    ~UiShellInterface();
private:
    /// qmlEngine 前端引擎
    QQmlApplicationEngine* qmlEngine = nullptr;
    /// shellInterface shell接口
    ShellInterface* shellInterface = nullptr;

};
}
