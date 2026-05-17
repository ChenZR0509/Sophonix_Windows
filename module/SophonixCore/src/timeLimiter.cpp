/**
 * @file timeLimiter.cpp
 * @brief 时间限制器
 * @author ChenZR
 * @details 控制某段逻辑在给定时间间隔内最多只允许执行一次
 */
/* Includes" "------------------------------------------------------------------*/
#include "timeLimiter.h"
/* Includes< >------------------------------------------------------------------*/
#include <QDebug>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix
{

timeLimiter::timeLimiter(uint16_t interval, QObject *parent)
    :timeInterval(interval), QObject(parent)
{
    ;
}

timeLimiter::~timeLimiter()
{

}

void timeLimiter::timerStart()
{
    timer.start();
    pauseInterval = 0;
    isPaused = false;
}

void timeLimiter::timerPause()
{
    if (!isPaused)
    {
        pauseTimer.start();
        isPaused = true;
    }
}

void timeLimiter::timerResume()
{
    if (isPaused) {
        pauseInterval += pauseTimer.elapsed();
        isPaused = false;
    }
}

bool timeLimiter::tryRun()
{
    if (isPaused) return false;

    qint64 adjustedElapsed = timer.elapsed() - pauseInterval;
    if (adjustedElapsed >= timeInterval)
    {
        timer.restart();
        pauseInterval = 0;
        return true;
    }
    return false;
}

uint16_t timeLimiter::getTimeInterval() const
{
    return timeInterval;
}

void timeLimiter::setTimeInterval(uint16_t newTimeInterval)
{
    timeInterval = newTimeInterval;
}

}
