/**
 * @file main
 * @brief 程序入口
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "sophonixCore.h"
/* Includes< >------------------------------------------------------------------*/
#include <QGuiApplication>
#include <QQmlApplicationEngine>
/* Macro Definition------------------------------------------------------------------*/
/* DataType Definition------------------------------------------------------------------*/
/* Variable Definition-----------------------------------------------------*/
/* Functions Declare------------------------------------------------------------------*/
/* Function Definition------------------------------------------------------------------*/
/**
 * @name main
 * @brief 程序入口函数
 *
 * @param[in] argc 参数数量
 * @param[out] argv 参数数组
 * @return int 进场返回值
 */
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Sophonix::SophonixCore core(&engine, &engine);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Sophonix", "Main");
    return app.exec();
}
