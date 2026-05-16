#pragma once
/**
 * @file sizeScheme.h
 * @brief Ui尺寸配置文件
 * @author ChenZR
 * @note: 多屏环境下软件切换屏幕尺寸更新功能没实现
 */
/* Includes" "------------------------------------------------------------------*/
/* Includes< >------------------------------------------------------------------*/
#include <QObject>
#include <QtQuick/QQuickPaintedItem>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix::Ui::Basic
{
class SizeScheme : public QObject{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_DISABLE_COPY(SizeScheme)
public:
    /* DataType Definition------------------------------------------------------------------*/
    /* Variable Declare------------------------------------------------------------------*/
    /* Functions Declare------------------------------------------------------------------*/
    explicit SizeScheme(QObject* parent = nullptr);
    ~SizeScheme(void);
private:
    double screenWidth{0};
    double screenHeight{0};
    double screenSize{0};
    double windowScale{0.8};
    double windowWidth{0};
    double windowHeight{0};
    double windowSize{0};
    double layoutSpacer{0};
    double spacerScale{0.01};
    const double largeConner{18};
    const double mediumConner{14};
    const double smallConner{10};
private:
    Q_PROPERTY(double screenWidth READ getScreenWidth WRITE setScreenWidth NOTIFY screenWidthChanged FINAL)
    Q_PROPERTY(double screenHeight READ getScreenHeight WRITE setScreenHeight NOTIFY screenHeightChanged FINAL)
    Q_PROPERTY(double screenSize READ getScreenSize WRITE setScreenSize NOTIFY screenSizeChanged FINAL)
    Q_PROPERTY(double windowWidth READ getWindowWidth WRITE setWindowWidth NOTIFY windowWidthChanged FINAL)
    Q_PROPERTY(double windowHeight READ getWindowHeight WRITE setWindowHeight NOTIFY windowHeightChanged FINAL)
    Q_PROPERTY(double windowSize READ getWindowSize WRITE setWindowSize NOTIFY windowSizeChanged FINAL)
    Q_PROPERTY(double windowScale READ getWindowScale WRITE setWindowScale NOTIFY windowScaleChanged FINAL)
    Q_PROPERTY(double layoutSpacer READ getLayoutSpacer WRITE setLayoutSpacer NOTIFY layoutSpacerChanged FINAL)
    Q_PROPERTY(double spacerScale READ getSpacerScale WRITE setSpacerScale NOTIFY spacerScaleChanged FINAL)
    Q_PROPERTY(double largeConner READ getLargeConner CONSTANT FINAL)
    Q_PROPERTY(double mediumConner READ getMediumConner CONSTANT FINAL)
    Q_PROPERTY(double smallConner READ getSmallConner CONSTANT FINAL)

public:

    double getScreenWidth() const;
    void setScreenWidth(double newScreenWidth);

    double getScreenHeight() const;
    void setScreenHeight(double newScreenHeight);

    double getScreenSize() const;
    void setScreenSize(double newScreenSize);

    double getWindowWidth() const;
    void setWindowWidth(double newWindowWidth);

    double getWindowHeight() const;
    void setWindowHeight(double newWindowHeight);

    double getWindowSize() const;
    void setWindowSize(double newWindowSize);

    double getLayoutSpacer() const;
    void setLayoutSpacer(double newLayoutSpacer);

    double getSpacerScale() const;
    void setSpacerScale(double newSpacerScale);

    double getLargeConner() const;

    double getMediumConner() const;

    double getSmallConner() const;

    double getWindowScale() const;
    void setWindowScale(double newWindowScale);

signals:
    void screenWidthChanged();
    void screenHeightChanged();
    void screenSizeChanged();
    void windowWidthChanged();
    void windowHeightChanged();
    void windowSizeChanged();
    void layoutSpacerChanged();
    void spacerScaleChanged();
    void windowScaleChanged();
};
}
