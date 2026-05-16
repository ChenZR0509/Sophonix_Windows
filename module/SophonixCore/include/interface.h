#pragma once
/**
 * @file interface
 * @brief 接口
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "uiWindowInterface.h"
/* Includes< >------------------------------------------------------------------*/
#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix
{
class Interface: public QObject
{
    Q_OBJECT
private:
    using UiWindowInterface = Ui::UiWindowInterface;
public:
    /**
     * @name Interface
     * @brief 构造函数
     *
     * @param[in] parent 对象树父节点
     */
    explicit Interface(QQmlApplicationEngine* engine = nullptr, QObject* parent = nullptr);
    /**
     * @name ~Interface
     * @brief 析构函数
     */
    ~Interface();
private:
    /// qmlEngine 前端引擎
    QQmlApplicationEngine* qmlEngine = nullptr;
    /// windowInterface 窗口UI的接口
    UiWindowInterface* windowInterface = nullptr;
private:
};
}
