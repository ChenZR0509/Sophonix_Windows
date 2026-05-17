#pragma once
/**
 * @file sophonixCore
 * @brief 智子内核
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "uiRefresh.h"
#include "interface.h"
/* Includes< >------------------------------------------------------------------*/
#include <QObject>
#include <QQmlContext>
#include <QThreadPool>
#include <QQmlApplicationEngine>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix
{
class SophonixCore: public QObject
{
    Q_OBJECT
public:
    /**
     * @name SophonixCore
     * @brief 构造函数
     *
     * @param[in] parent 对象树父节点
     */
    explicit SophonixCore(QQmlApplicationEngine* engine = nullptr, QObject* parent = nullptr);
    /**
     * @name ~SophonixCore
     * @brief 析构函数
     */
    ~SophonixCore();
private:
    /// qmlEngine 前端引擎
    QQmlApplicationEngine* qmlEngine = nullptr;
    /// uiRefresh qml刷新器
    UiRefresh* qmlRefresh = nullptr;
    /// qmlInterface 前后端接口
    Interface* qmlInterface = nullptr;
private:
};
}
