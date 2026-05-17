/**
 * @file RunnableThread
 * @brief 线程池可支配线程
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "runnableThread.h"
/* Includes< >------------------------------------------------------------------*/
#include <atomic>
#include <QDebug>
/* Namespace------------------------------------------------------------------*/
namespace Atomic::Thread
{

RunnableThread::RunnableThread(QObject *parent)
{

}

RunnableThread::~RunnableThread()
{

}

void RunnableThread::pauseThread()
{
    threadState expected = threadState::Running;
    state.compare_exchange_strong(expected, threadState::Suspension);
}

void RunnableThread::resumeThread()
{
    threadState expected = threadState::Suspension;
    state.compare_exchange_strong(expected, threadState::Running);
    pauseCond.wakeAll();
}

void RunnableThread::stopThread()
{
    state.store(threadState::Quit);
    pauseCond.wakeAll();
}

void RunnableThread::startThread()
{
    state.store(threadState::Running);
    pauseCond.wakeAll();
}

void RunnableThread::run()
{
    initFunction();
    while (state.load() != threadState::Quit)
    {
        //1、线程暂停逻辑
        pauseMutex.lock();
        while (state.load() == threadState::Suspension)
        {
            pauseFunction();
            pauseCond.wait(&pauseMutex);
            resumeFunction();
        }
        pauseMutex.unlock();
        //2、线程退出逻辑
        if (state.load() == threadState::Quit)
        {
            unInitFunction();
            break;
        }
        //3、线程工作内容
        workFunction();
    }
}
}
