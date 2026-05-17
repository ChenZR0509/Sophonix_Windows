#pragma once
/**
 * @file timeLimiter.h
 * @brief 时间限制器
 * @author ChenZR
 * @details 控制某段逻辑在给定时间间隔内最多只允许执行一次
 */
/* Includes" "------------------------------------------------------------------*/
/* Includes< >------------------------------------------------------------------*/
#include <stdint.h>
#include <QObject>
#include <QElapsedTimer>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix
{
/**
 * @name timeLimiter
 * @brief 时间限制器类
 * @author ChenZR
 */
class timeLimiter: public QObject
{
    Q_OBJECT
public:
    /**
     * @name timeLimiter
     * @brief 构造函数
     *
     * @param[in] interval 时间间隔
     * @param[in] parent 父对象
     */
    explicit timeLimiter(uint16_t interval, QObject* parent = nullptr);
    /**
     * @name ~timeLimiter
     * @brief 析构函数
     *
     * @param[in] void
     * @return void
     */
    ~timeLimiter();
    /**
     * @name timerStart
     * @brief 定时器启动函数
     *
     * @param[in] void
     * @return void
     */
    void timerStart();
    /**
     * @name timerPause
     * @brief 时间限制器暂停函数
     *
     * @param[in] void
     * @return none
     */
    void timerPause();
    /**
     * @name timerResume
     * @brief 时间限制器恢复
     *
     * @param[in] void
     * @return none
     */
    void timerResume();
    /**
     * @name tryRun
     * @brief 时间限制器功能函数
     *
     * @param[in] void
     * @return none
     */
    bool tryRun();
    /**
     * @name getTimeInterval
     * @brief 读取定时器时间间隔，单位：ms
     *
     * @return uint16_t
     */
    uint16_t getTimeInterval() const;
    /**
     * @name tryRun
     * @brief 时间限制器功能函数
     *
     * @param[in] newTimeInterval 时间间隔，单位：ms
     */
    void setTimeInterval(uint16_t newTimeInterval);
private:
    ///< isPaused 是否暂停
    bool isPaused{true};
    ///< timeInterval 时间间隔，单位：ms
    uint16_t timeInterval{0};
    ///< pauseInterval 暂停时间
    qint64 pauseInterval{0};
    ///< timer 定时器
    QElapsedTimer timer;
    ///< pauseTimer 暂停计时器
    QElapsedTimer pauseTimer;
};
}
