#pragma once
/**
 * @file uiRefresh
 * @brief ui刷新
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "timeLimiter.h"
#include "runnableThread.h"
/* Includes< >------------------------------------------------------------------*/
#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix
{
class UiRefresh : public Atomic::Thread::RunnableThread
{
    Q_OBJECT
public:
 using RunnableThread = Atomic::Thread::RunnableThread;
public:
    /**
     * @name UiRefresh
     * @brief 构造函数
     *
     * @param[in] parent 对象树父节点
     */
    explicit UiRefresh(QObject* parent = nullptr);
    /**
     * @name ~UiRefresh
     * @brief 析构函数
     */
    ~UiRefresh();
private:
    /// uiLimit Ui刷新时间限制器
    timeLimiter uiLimit{(uint16_t)20, this};
public:
    /**
     * @name initFunction
     * @brief 初始化逻辑函数
     *
     * @note 需在初始化逻辑函数最后将state置为Running
     * @note 若业务仅需执行一次，则可直接将业务写入初始化逻辑中，并保持state为Quit
     */
    void initFunction() override;
    /**
     * @name pauseFunction
     * @brief 暂停逻辑函数
     */
    void pauseFunction() override;
    /**
     * @name resumeFunction
     * @brief 恢复逻辑函数
     */
    void resumeFunction() override;
    /**
     * @name workFunction
     * @brief 业务逻辑函数
     */
    void workFunction() override;
    /**
     * @name unInitFunction
     * @brief 结束逻辑函数
     */
    void unInitFunction() override;
signals:
    void refresh();
};
}
