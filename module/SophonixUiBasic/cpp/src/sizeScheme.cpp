/**
 * @file sizeScheme.cpp
 * @brief Ui颜色配置文件
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "sizeScheme.h"
/* Includes< >------------------------------------------------------------------*/
#include <QScreen>
#include <QtGlobal>
/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui::Basic
{

SizeScheme::SizeScheme(QObject *parent)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
    {
        QRect geometry = screen->geometry();
        setScreenWidth(geometry.width());
        setScreenHeight(geometry.height());
    }
}

SizeScheme::~SizeScheme()
{
    ;
}

double SizeScheme::getSmallConner() const
{
    return smallConner;
}

double SizeScheme::getMediumConner() const
{
    return mediumConner;
}

double SizeScheme::getLargeConner() const
{
    return largeConner;
}

double SizeScheme::getSpacerScale() const
{
    return spacerScale;
}

void SizeScheme::setSpacerScale(double newSpacerScale)
{
    if (qFuzzyCompare(spacerScale, newSpacerScale))
        return;
    if (newSpacerScale < 0 || newSpacerScale > 1.0)
        return;
    spacerScale = newSpacerScale;
    setLayoutSpacer(qRound(windowSize*spacerScale));
    emit spacerScaleChanged();
}

double SizeScheme::getLayoutSpacer() const
{
    return layoutSpacer;
}

void SizeScheme::setLayoutSpacer(double newLayoutSpacer)
{
    if (qFuzzyCompare(layoutSpacer, newLayoutSpacer))
        return;
    layoutSpacer = newLayoutSpacer;
    emit layoutSpacerChanged();
}

double SizeScheme::getWindowSize() const
{
    return windowSize;
}

void SizeScheme::setWindowSize(double newWindowSize)
{
    if (qFuzzyCompare(windowSize, newWindowSize))
        return;
    windowSize = newWindowSize;
    setLayoutSpacer(qRound(windowSize*spacerScale));
    emit windowSizeChanged();
}

double SizeScheme::getWindowHeight() const
{
    return windowHeight;
}

void SizeScheme::setWindowHeight(double newWindowHeight)
{
    if (qFuzzyCompare(windowHeight, newWindowHeight))
        return;
    windowHeight = newWindowHeight;
    setWindowSize(sqrt(windowWidth*windowWidth+windowHeight*windowHeight));
    emit windowHeightChanged();
}

double SizeScheme::getWindowWidth() const
{
    return windowWidth;
}

void SizeScheme::setWindowWidth(double newWindowWidth)
{
    if (qFuzzyCompare(windowWidth, newWindowWidth))
        return;
    windowWidth = newWindowWidth;
    setWindowSize(sqrt(windowWidth*windowWidth+windowHeight*windowHeight));
    emit windowWidthChanged();
}

double SizeScheme::getWindowScale() const
{
    return windowScale;
}

void SizeScheme::setWindowScale(double newWindowScale)
{
    if (qFuzzyCompare(windowScale, newWindowScale))
        return;
    windowScale = newWindowScale;
    emit windowScaleChanged();
}

double SizeScheme::getScreenWidth() const
{
    return screenWidth;
}

void SizeScheme::setScreenWidth(double newScreenWidth)
{
    if (qFuzzyCompare(screenWidth, newScreenWidth))
        return;
    screenWidth = newScreenWidth;
    setScreenSize(sqrt(screenWidth*screenWidth+screenHeight*screenHeight));
    setWindowWidth(screenWidth*windowScale);
    emit screenWidthChanged();
}

double SizeScheme::getScreenHeight() const
{
    return screenHeight;
}

void SizeScheme::setScreenHeight(double newScreenHeight)
{
    if (qFuzzyCompare(screenHeight, newScreenHeight))
        return;
    screenHeight = newScreenHeight;
    setScreenSize(sqrt(screenWidth*screenWidth+screenHeight*screenHeight));
    setWindowHeight(screenHeight*windowScale);
    emit screenHeightChanged();
}

double SizeScheme::getScreenSize() const
{
    return screenSize;
}

void SizeScheme::setScreenSize(double newScreenSize)
{
    if (qFuzzyCompare(screenSize, newScreenSize))
        return;
    screenSize = newScreenSize;
    emit screenSizeChanged();
}
}
