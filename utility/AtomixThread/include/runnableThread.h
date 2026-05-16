#pragma once
/**
 * @file RunnableThread
 * @brief
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "AtomixThread_global.h"
/* Includes< >------------------------------------------------------------------*/
#include <QMutex>
#include <QObject>
#include <QRunnable>
#include <QWaitCondition>
/* NameSpace------------------------------------------------------------------*/
namespace Atomic::Thread
{
class ATOMIXTHREAD_EXPORT RunnableThread: public QObject, public QRunnable
{
    Q_OBJECT
public:
    /**
     * @name RunnableThread
     * @brief 构造函数
     *
     * @param[in] parent 对象树父节点
     */
    explicit RunnableThread(QObject* parent);
    /**
     * @name ~RunnableThread
     * @brief 析构函数
     */
    ~RunnableThread();
public:
    enum class threadState  ///< threadState 线程状态
    {
        Running,            ///< Running 运行态
        Suspension,         ///< Suspension 挂起态
        Quit                ///< Quit 退出态
    };
protected:
    /// state 线程状态
    std::atomic<threadState> state {threadState::Quit};
private:
    /// pauseMutex 线程锁
    QMutex pauseMutex;
    /// pauseCond 线程等待条件
    QWaitCondition pauseCond;
public:
    /**
     * @name pauseThread
     * @brief 线程暂停
     * @author ChenZR
     */
    void pauseThread();
    /**
     * @name resumeThread
     * @brief 线程恢复
     * @author ChenZR
     */
    void resumeThread();
    /**
     * @name stopThread
     * @brief 线程停止
     * @author ChenZR
     */
    void stopThread();
    /**
     * @name startThread
     * @brief 线程启动
     * @author ChenZR
     */
    void startThread();
    /**
     * @name run
     * @brief 线程函数
     * @author ChenZR
     */
    void run() override;
    /**
     * @name initFunction
     * @brief 初始化逻辑函数
     *
     * @note 需在初始化逻辑函数最后将state置为Running
     * @note 若业务仅需执行一次，则可直接将业务写入初始化逻辑中，并保持state为Quit
     */
    virtual void initFunction() = 0;
    /**
     * @name pauseFunction
     * @brief 暂停逻辑函数
     */
    virtual void pauseFunction() = 0;
    /**
     * @name resumeFunction
     * @brief 恢复逻辑函数
     */
    virtual void resumeFunction() = 0;
    /**
     * @name workFunction
     * @brief 业务逻辑函数
     */
    virtual void workFunction() = 0;
    /**
     * @name unInitFunction
     * @brief 结束逻辑函数
     */
    virtual void unInitFunction() = 0;
};
}
