/**
 * @file colorScheme.h
 * @brief Ui颜色配置文件
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "colorScheme.h"
/* Includes< >------------------------------------------------------------------*/
#include <QScreen>
/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui::Basic
{

ColorScheme::ColorScheme(QObject *parent)
{
    ;
}

ColorScheme::~ColorScheme()
{
    ;
}

QColor ColorScheme::getBlack() const
{
    return black;
}

QColor ColorScheme::getWhite() const
{
    return white;
}

QColor ColorScheme::getTransparent() const
{
    return transparent;
}

float ColorScheme::getStateDisabled() const
{
    return stateDisabled;
}

float ColorScheme::getStateDragged() const
{
    return stateDragged;
}

float ColorScheme::getStatePressed() const
{
    return statePressed;
}

float ColorScheme::getStateFocus() const
{
    return stateFocus;
}

float ColorScheme::getStateHover() const
{
    return stateHover;
}

QColor ColorScheme::getOutlineVariant() const
{
    return outlineVariant;
}

QColor ColorScheme::getOutline() const
{
    return outline;
}

QColor ColorScheme::getOnErrorContainer() const
{
    return onErrorContainer;
}

QColor ColorScheme::getErrorContainer() const
{
    return errorContainer;
}

QColor ColorScheme::getOnError() const
{
    return onError;
}

QColor ColorScheme::getError() const
{
    return error;
}

QColor ColorScheme::getSurfaceContainerHighest() const
{
    return surfaceContainerHighest;
}

QColor ColorScheme::getSurfaceContainerHigh() const
{
    return surfaceContainerHigh;
}

QColor ColorScheme::getSurfaceContainer() const
{
    return surfaceContainer;
}

QColor ColorScheme::getSurfaceContainerLow() const
{
    return surfaceContainerLow;
}

QColor ColorScheme::getSurfaceContainerLowest() const
{
    return surfaceContainerLowest;
}

QColor ColorScheme::getSurfaceBright() const
{
    return surfaceBright;
}

QColor ColorScheme::getSurfaceDim() const
{
    return surfaceDim;
}

QColor ColorScheme::getInverseOnSurface() const
{
    return inverseOnSurface;
}

QColor ColorScheme::getInverseSurface() const
{
    return inverseSurface;
}

QColor ColorScheme::getOnSurfaceVariant() const
{
    return onSurfaceVariant;
}

QColor ColorScheme::getSurfaceVariant() const
{
    return surfaceVariant;
}

QColor ColorScheme::getOnSurface() const
{
    return onSurface;
}

QColor ColorScheme::getSurface() const
{
    return surface;
}

QColor ColorScheme::getOnBackground() const
{
    return onBackground;
}

QColor ColorScheme::getBackground() const
{
    return background;
}

QColor ColorScheme::getOnTertiaryContainer() const
{
    return onTertiaryContainer;
}

QColor ColorScheme::getTertiaryContainer() const
{
    return tertiaryContainer;
}

QColor ColorScheme::getOnTertiary() const
{
    return onTertiary;
}

QColor ColorScheme::getTertiary() const
{
    return tertiary;
}

QColor ColorScheme::getOnSecondaryContainer() const
{
    return onSecondaryContainer;
}

QColor ColorScheme::getSecondaryContainer() const
{
    return secondaryContainer;
}

QColor ColorScheme::getOnSecondary() const
{
    return onSecondary;
}

QColor ColorScheme::getSecondary() const
{
    return secondary;
}

QColor ColorScheme::getInversePrimary() const
{
    return inversePrimary;
}

QColor ColorScheme::getOnPrimaryContainer() const
{
    return onPrimaryContainer;
}

QColor ColorScheme::getOnPrimary() const
{
    return onPrimary;
}

QColor ColorScheme::getPrimaryContainer() const
{
    return primaryContainer;
}

QColor ColorScheme::getPrimary() const
{
    return primary;
}
}
