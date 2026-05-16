#pragma once
/**
 * @file colorScheme.h
 * @brief Ui颜色配置文件
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
/* Includes< >------------------------------------------------------------------*/
#include <QObject>
#include <QColor>
#include <QtQuick/QQuickPaintedItem>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix::Ui::Basic
{
class ColorScheme : public QObject{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_DISABLE_COPY(ColorScheme)
public:
    /* DataType Definition------------------------------------------------------------------*/
    /* Variable Declare------------------------------------------------------------------*/
    /* Functions Declare------------------------------------------------------------------*/
    explicit ColorScheme(QObject* parent = nullptr);
    ~ColorScheme(void);
private:
    const QColor primary{QColor::fromRgb(0x00E5FF)};
    const QColor onPrimary{QColor::fromRgb(0x001014)};
    const QColor primaryContainer{QColor::fromRgb(0x00363D)};
    const QColor onPrimaryContainer{QColor::fromRgb(0x7FEFFF)};
    const QColor inversePrimary{QColor::fromRgb(0x00B8D4)};

    const QColor secondary{QColor::fromRgb(0x4D7CFE)};
    const QColor onSecondary{QColor::fromRgb(0x0B1020)};
    const QColor secondaryContainer{QColor::fromRgb(0x1A237E)};
    const QColor onSecondaryContainer{QColor::fromRgb(0xC7D2FF)};

    const QColor tertiary{QColor::fromRgb(0x00FFA3)};
    const QColor onTertiary{QColor::fromRgb(0x002117)};
    const QColor tertiaryContainer{QColor::fromRgb(0x00382A)};
    const QColor onTertiaryContainer{QColor::fromRgb(0x7DFFD1)};

    const QColor background{QColor::fromRgb(0x141518)};
    const QColor onBackground{QColor::fromRgb(0xE5E6ED)};
    const QColor surface{QColor::fromRgb(0x1E1F25)};
    const QColor onSurface{QColor::fromRgb(0xE5E6ED)};
    const QColor surfaceVariant{QColor::fromRgb(0x282C38)};
    const QColor onSurfaceVariant{QColor::fromRgb(0x757B8C)};
    const QColor inverseSurface{QColor::fromRgb(0xE5E6ED)};
    const QColor inverseOnSurface{QColor::fromRgb(0x141518)};

    const QColor surfaceDim{QColor::fromRgb(0x121316)};
    const QColor surfaceBright{QColor::fromRgb(0x2A2C33)};
    const QColor surfaceContainerLowest{QColor::fromRgb(0x0F1013)};
    const QColor surfaceContainerLow{QColor::fromRgb(0x1A1B20)};
    const QColor surfaceContainer{QColor::fromRgb(0x1E1F25)};
    const QColor surfaceContainerHigh{QColor::fromRgb(0x262830)};
    const QColor surfaceContainerHighest{QColor::fromRgb(0x2F3240)};

    const QColor error{QColor::fromRgb(0xFF5A5F)};
    const QColor onError{QColor::fromRgb(0x2A0001)};
    const QColor errorContainer{QColor::fromRgb(0x410002)};
    const QColor onErrorContainer{QColor::fromRgb(0xFFDAD6)};

    const QColor outline{QColor::fromRgb(0x3C4254)};
    const QColor outlineVariant{QColor::fromRgb(0x282C38)};

    const float stateHover{0.08f};
    const float stateFocus{0.12f};
    const float statePressed{ 0.16f};
    const float stateDragged{0.24f};
    const float stateDisabled{0.38f};

    const QColor transparent{Qt::transparent};
    const QColor white{QColor::fromRgb(0xFFFFFF)};
    const QColor black{QColor::fromRgb(0x000000)};
private:
    Q_PROPERTY(QColor primary READ getPrimary CONSTANT FINAL)
    Q_PROPERTY(QColor onPrimary READ getOnPrimary CONSTANT FINAL)
    Q_PROPERTY(QColor primaryContainer READ getPrimaryContainer CONSTANT FINAL)
    Q_PROPERTY(QColor onPrimaryContainer READ getOnPrimaryContainer CONSTANT FINAL)
    Q_PROPERTY(QColor inversePrimary READ getInversePrimary CONSTANT FINAL)

    Q_PROPERTY(QColor secondary READ getSecondary CONSTANT FINAL)
    Q_PROPERTY(QColor onSecondary READ getOnSecondary CONSTANT FINAL)
    Q_PROPERTY(QColor secondaryContainer READ getSecondaryContainer CONSTANT FINAL)
    Q_PROPERTY(QColor onSecondaryContainer READ getOnSecondaryContainer CONSTANT FINAL)

    Q_PROPERTY(QColor tertiary READ getTertiary CONSTANT FINAL)
    Q_PROPERTY(QColor onTertiary READ getOnTertiary CONSTANT FINAL)
    Q_PROPERTY(QColor tertiaryContainer READ getTertiaryContainer CONSTANT FINAL)
    Q_PROPERTY(QColor onTertiaryContainer READ getOnTertiaryContainer CONSTANT FINAL)

    Q_PROPERTY(QColor background READ getBackground CONSTANT FINAL)
    Q_PROPERTY(QColor onBackground READ getOnBackground CONSTANT FINAL)
    Q_PROPERTY(QColor surface READ getSurface CONSTANT FINAL)
    Q_PROPERTY(QColor onSurface READ getOnSurface CONSTANT FINAL)
    Q_PROPERTY(QColor surfaceVariant READ getSurfaceVariant CONSTANT FINAL)
    Q_PROPERTY(QColor onSurfaceVariant READ getOnSurfaceVariant CONSTANT FINAL)
    Q_PROPERTY(QColor inverseSurface READ getInverseSurface CONSTANT FINAL)
    Q_PROPERTY(QColor inverseOnSurface READ getInverseOnSurface CONSTANT FINAL)

    Q_PROPERTY(QColor surfaceDim READ getSurfaceDim CONSTANT FINAL)
    Q_PROPERTY(QColor surfaceBright READ getSurfaceBright CONSTANT FINAL)
    Q_PROPERTY(QColor surfaceContainerLowest READ getSurfaceContainerLowest CONSTANT FINAL)
    Q_PROPERTY(QColor surfaceContainerLow READ getSurfaceContainerLow CONSTANT FINAL)
    Q_PROPERTY(QColor surfaceContainer READ getSurfaceContainer CONSTANT FINAL)
    Q_PROPERTY(QColor surfaceContainerHigh READ getSurfaceContainerHigh CONSTANT FINAL)
    Q_PROPERTY(QColor surfaceContainerHighest READ getSurfaceContainerHighest CONSTANT FINAL)

    Q_PROPERTY(QColor error READ getError CONSTANT FINAL)
    Q_PROPERTY(QColor onError READ getOnError CONSTANT FINAL)
    Q_PROPERTY(QColor errorContainer READ getErrorContainer CONSTANT FINAL)
    Q_PROPERTY(QColor onErrorContainer READ getOnErrorContainer CONSTANT FINAL)

    Q_PROPERTY(QColor outline READ getOutline CONSTANT FINAL)
    Q_PROPERTY(QColor outlineVariant READ getOutlineVariant CONSTANT FINAL)

    Q_PROPERTY(float stateHover READ getStateHover CONSTANT FINAL)
    Q_PROPERTY(float stateFocus READ getStateFocus CONSTANT FINAL)
    Q_PROPERTY(float statePressed READ getStatePressed CONSTANT FINAL)
    Q_PROPERTY(float stateDragged READ getStateDragged CONSTANT FINAL)
    Q_PROPERTY(float stateDisabled READ getStateDisabled CONSTANT FINAL)

    Q_PROPERTY(QColor transparent READ getTransparent CONSTANT FINAL)
    Q_PROPERTY(QColor white READ getWhite CONSTANT FINAL)
    Q_PROPERTY(QColor black READ getBlack CONSTANT FINAL)
public:
    QColor getPrimary() const;

    QColor getOnPrimary() const;

    QColor getPrimaryContainer() const;

    QColor getOnPrimaryContainer() const;

    QColor getInversePrimary() const;

    QColor getSecondary() const;

    QColor getOnSecondary() const;

    QColor getSecondaryContainer() const;

    QColor getOnSecondaryContainer() const;

    QColor getTertiary() const;

    QColor getOnTertiary() const;

    QColor getTertiaryContainer() const;

    QColor getOnTertiaryContainer() const;

    QColor getBackground() const;

    QColor getOnBackground() const;

    QColor getSurface() const;

    QColor getOnSurface() const;

    QColor getSurfaceVariant() const;

    QColor getOnSurfaceVariant() const;

    QColor getInverseSurface() const;

    QColor getInverseOnSurface() const;

    QColor getSurfaceDim() const;

    QColor getSurfaceBright() const;

    QColor getSurfaceContainerLowest() const;

    QColor getSurfaceContainerLow() const;

    QColor getSurfaceContainer() const;

    QColor getSurfaceContainerHigh() const;

    QColor getSurfaceContainerHighest() const;

    QColor getError() const;

    QColor getOnError() const;

    QColor getErrorContainer() const;

    QColor getOnErrorContainer() const;

    QColor getOutline() const;

    QColor getOutlineVariant() const;

    float getStateHover() const;

    float getStateFocus() const;

    float getStatePressed() const;

    float getStateDragged() const;

    float getStateDisabled() const;

    QColor getTransparent() const;

    QColor getWhite() const;

    QColor getBlack() const;
};
}
