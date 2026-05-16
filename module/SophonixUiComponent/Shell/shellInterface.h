#pragma once
/**
 * @file ShellInterface
 * @brief Shell接口
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "shellModelManager.h"
/* Includes< >------------------------------------------------------------------*/
#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui::Component
{
class ShellInterface: public QObject
{
    Q_OBJECT
public:
    /**
     * @name ShellInterface
     * @brief 构造函数
     *
     * @param[in] engine qml引擎
     * @param[in] parent 对象树父节点
     */
    explicit ShellInterface(QQmlApplicationEngine* engine = nullptr, QObject* parent = nullptr);
    /**
     * @name ~ShellInterface
     * @brief 析构函数
     */
    ~ShellInterface();
private:
    /// qmlEngine 前端引擎
    QQmlApplicationEngine* qmlEngine = nullptr;
    /// shellModelManager shell 输出模型
    ShellModelManager* shellModelManager = nullptr;
private:
    Q_PROPERTY(ShellModelManager* shellModelManager READ getShellModelManager CONSTANT FINAL)
public:
    ShellModelManager *getShellModelManager() const;
};
}
