/**
 * @file UiWindow.h
 * @brief 窗口样式
 * @author ChenZR
  */
/* Import" "------------------------------------------------------------------*/
import "UiShell"
import SophonixUiBasic 1.0
import SophonixUiComponent 1.0
/* Import< >------------------------------------------------------------------*/
import QtQuick
import QtQuick.Controls
import QtQuick.Shapes
import QtMultimedia
/* Root ----------------------------------------------------------------------*/
Control{
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property var menuState: homeButton                  //顶部菜单栏按键状态
  readonly property var windowMenu: new Map([ // windowMenu 窗口菜单索引
    ["home", homeView],                       // homeView 主窗口
    ["shell", shellView],                     // shellView 终端窗口
    ["device", deviceView],                   // deviceView 设备窗口
    ["setting", settingView],                 // settingView 设置窗口
    ["assistant", assistantView],             // assistantView 助手窗口
  ])
  /* Property Setting------------------------------------------------------------------*/
  visible: true
  focus: true
  background: Rectangle{
    color: ColorScheme.transparent
  }
  /* Object Definition------------------------------------------------------------------*/
  //1、顶部按键
  Shape{
    id: topSurface
    anchors.top: root.top
    anchors.left: root.left
    anchors.right: root.right
    height: 1.8*SizeScheme.mediumConner
    ShapePath {
      startX: 0
      startY: 0
      strokeWidth: 1
      strokeColor: ColorScheme.white
      fillColor: ColorScheme.background
      PathLine { x: topSurface.width-SizeScheme.mediumConner; y: 0}
      PathLine { x: topSurface.width;  y: SizeScheme.mediumConner}
      PathLine { x: topSurface.width;  y: topSurface.height}
      PathLine { x: 0; y: topSurface.height}
      PathLine { x: 0; y: 0}
    }
    UiButton{
      id: shellButton
      anchors.left: topSurface.left
      anchors.top: topSurface.top
      anchors.bottom: topSurface.bottom
      width: topSurface.width/5+SizeScheme.mediumConner
      Shape{
        id: shellButtonSurface
        anchors.fill: shellButton.buttonArea
        ShapePath {
          id: shellButtonBorder
          strokeWidth: 1
          strokeColor: ColorScheme.white
          fillColor: ColorScheme.background
          startX: 0; startY: 0
          PathLine { x: shellButton.width-SizeScheme.mediumConner; y: 0}
          PathLine { x: shellButton.width;  y: shellButton.height}
          PathLine { x: 0; y: shellButton.height}
          PathLine { x: 0; y: 0}
        }
        UiText{
          id: shellButtonText
          anchors.fill: shellButtonSurface
          padding: 4
          textContent: "终端"
          textFamily: "KaiTi"
          textSize: parent.height-8
          textColor: ColorScheme.white
          textObject.horizontalAlignment: Text.AlignHCenter
          textObject.verticalAlignment: Text.AlignVCenter
        }
      }
      ParallelAnimation{
        id: shellButtonPressedAnimation
        ColorAnimation{
          target: shellButtonBorder
          properties: "fillColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: shellButtonText
          properties: "textColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      ParallelAnimation{
        id: shellButtonReleasedAnimation
        ColorAnimation{
          target: shellButtonBorder
          properties: "fillColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: shellButtonText
          properties: "textColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      onClicked: {
        selectMenu(shellButton)
      }
    }
    UiButton{
      id: deviceButton
      anchors.left: shellButton.right
      anchors.leftMargin: -SizeScheme.mediumConner
      anchors.top: topSurface.top
      anchors.bottom: topSurface.bottom
      width: topSurface.width/5+SizeScheme.mediumConner
      Shape{
        id: deviceButtonSurface
        anchors.fill: deviceButton.buttonArea
        ShapePath {
          id: deviceButtonBorder
          strokeWidth: 1
          strokeColor: ColorScheme.white
          fillColor: ColorScheme.background
          startX: 0; startY: 0
          PathLine { x: deviceButton.width-SizeScheme.mediumConner; y: 0}
          PathLine { x: deviceButton.width;  y: deviceButton.height}
          PathLine { x: SizeScheme.mediumConner; y: deviceButton.height}
          PathLine { x: 0; y: 0}
        }
        UiText{
          id: deviceButtonText
          anchors.fill: deviceButtonSurface
          padding: 4
          textContent: "设备"
          textFamily: "KaiTi"
          textSize: parent.height-8
          textColor: ColorScheme.white
          textObject.horizontalAlignment: Text.AlignHCenter
          textObject.verticalAlignment: Text.AlignVCenter
        }
      }
      ParallelAnimation{
        id: deviceButtonPressedAnimation
        ColorAnimation{
          target: deviceButtonBorder
          properties: "fillColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: deviceButtonText
          properties: "textColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      ParallelAnimation{
        id: deviceButtonReleasedAnimation
        ColorAnimation{
          target: deviceButtonBorder
          properties: "fillColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: deviceButtonText
          properties: "textColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      onClicked: {
        selectMenu(deviceButton)
      }
    }
    UiButton{
      id: homeButton
      anchors.left: deviceButton.right
      anchors.leftMargin: -SizeScheme.mediumConner
      anchors.top: topSurface.top
      anchors.bottom: topSurface.bottom
      width: topSurface.width/5+SizeScheme.mediumConner
      Shape{
        id: homeButtonSurface
        anchors.fill: homeButton.buttonArea
        ShapePath {
          id: homeButtonBorder
          strokeWidth: 1
          strokeColor: ColorScheme.white
          fillColor: ColorScheme.white
          startX: 0; startY: 0
          PathLine { x: homeButton.width-SizeScheme.mediumConner; y: 0}
          PathLine { x: homeButton.width;  y: homeButton.height}
          PathLine { x: SizeScheme.mediumConner; y: homeButton.height}
          PathLine { x: 0; y: 0}
        }
        UiText{
          id: homeButtonText
          anchors.fill: homeButtonSurface
          padding: 4
          textContent: "主页"
          textFamily: "KaiTi"
          textSize: parent.height-8
          textColor: ColorScheme.background
          textObject.horizontalAlignment: Text.AlignHCenter
          textObject.verticalAlignment: Text.AlignVCenter
        }
      }
      ParallelAnimation{
        id: homeButtonPressedAnimation
        ColorAnimation{
          target: homeButtonBorder
          properties: "fillColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: homeButtonText
          properties: "textColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      ParallelAnimation{
        id: homeButtonReleasedAnimation
        ColorAnimation{
          target: homeButtonBorder
          properties: "fillColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: homeButtonText
          properties: "textColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      onClicked: {
        selectMenu(homeButton)
      }
    }
    UiButton{
      id: assistantButton
      anchors.left: homeButton.right
      anchors.leftMargin: -SizeScheme.mediumConner
      anchors.top: topSurface.top
      anchors.bottom: topSurface.bottom
      width: topSurface.width/5+SizeScheme.mediumConner
      Shape{
        id: assistantButtonSurface
        anchors.fill: assistantButton.buttonArea
        ShapePath {
          id: assistantButtonBorder
          strokeWidth: 1
          strokeColor: ColorScheme.white
          fillColor: ColorScheme.background
          startX: 0; startY: 0
          PathLine { x: assistantButton.width-SizeScheme.mediumConner; y: 0}
          PathLine { x: assistantButton.width;  y: assistantButton.height}
          PathLine { x: SizeScheme.mediumConner; y: assistantButton.height}
          PathLine { x: 0; y: 0}
        }
        UiText{
          id: assistantButtonText
          anchors.fill: assistantButtonSurface
          padding: 4
          textContent: "助手"
          textFamily: "KaiTi"
          textSize: parent.height-8
          textColor: ColorScheme.white
          textObject.horizontalAlignment: Text.AlignHCenter
          textObject.verticalAlignment: Text.AlignVCenter
        }
      }
      ParallelAnimation{
        id: assistantButtonPressedAnimation
        ColorAnimation{
          target: assistantButtonBorder
          properties: "fillColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: assistantButtonText
          properties: "textColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      ParallelAnimation{
        id: assistantButtonReleasedAnimation
        ColorAnimation{
          target: assistantButtonBorder
          properties: "fillColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: assistantButtonText
          properties: "textColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      onClicked: {
        selectMenu(assistantButton)
      }
    }
    UiButton{
      id: settingButton
      anchors.right: topSurface.right
      anchors.top: topSurface.top
      anchors.bottom: topSurface.bottom
      width: topSurface.width/5+SizeScheme.mediumConner
      Shape{
        id: settingButtonSurface
        anchors.fill: settingButton.buttonArea
        ShapePath {
          id: settingButtonBorder
          strokeWidth: 1
          strokeColor: ColorScheme.white
          fillColor: ColorScheme.background
          startX: 0; startY: 0
          PathLine { x: settingButton.width-SizeScheme.mediumConner; y: 0}
          PathLine { x: settingButton.width;  y: SizeScheme.mediumConner}
          PathLine { x: settingButton.width;  y: settingButton.height}
          PathLine { x: SizeScheme.mediumConner; y: settingButton.height}
          PathLine { x: 0; y: 0}
        }
        UiText{
          id: settingButtonText
          anchors.fill: settingButtonSurface
          padding: 4
          textContent: "设置"
          textFamily: "KaiTi"
          textSize: parent.height-8
          textColor: ColorScheme.white
          textObject.horizontalAlignment: Text.AlignHCenter
          textObject.verticalAlignment: Text.AlignVCenter
        }
      }
      ParallelAnimation{
        id: settingButtonPressedAnimation
        ColorAnimation{
          target: settingButtonBorder
          properties: "fillColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: settingButtonText
          properties: "textColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      ParallelAnimation{
        id: settingButtonReleasedAnimation
        ColorAnimation{
          target: settingButtonBorder
          properties: "fillColor"
          from: ColorScheme.white
          to: ColorScheme.background
          duration: 300
          easing.type: Easing.InOutCubic
        }
        ColorAnimation{
          target: settingButtonText
          properties: "textColor"
          from: ColorScheme.background
          to: ColorScheme.white
          duration: 300
          easing.type: Easing.InOutCubic
        }
      }
      onClicked: {
        selectMenu(settingButton)
      }
    }
  }
  //2、底部窗口
  Shape{
    id: shapeWindow
    anchors.top: topSurface.bottom
    anchors.left: root.left
    anchors.right: root.right
    anchors.bottom: root.bottom
    //1、边框绘制
    ShapePath {
      strokeWidth: 1
      strokeColor: ColorScheme.white
      fillColor: ColorScheme.background
      startX: 0; startY: 0
      PathLine { x: shapeWindow.width; y: 0}
      PathLine { x: shapeWindow.width;  y: shapeWindow.height}
      PathLine { x: SizeScheme.mediumConner; y: shapeWindow.height}
      PathLine { x: 0; y: shapeWindow.height-SizeScheme.mediumConner}
      PathLine { x: 0; y: 0}
    }
    UiView{
      id: windowView
      anchors.fill: shapeWindow
      padding: SizeScheme.mediumConner
      viewContent: homeView
      background: Rectangle{
        color: ColorScheme.transparent
      }
      Component {
        id: homeView
        Rectangle{
          color: ColorScheme.background
        }
      }
      Component {
        id: shellView
        UiShell{
        }
      }
      Component {
        id: deviceView
        Rectangle{
          color: ColorScheme.background
        }
      }
      Component {
        id: settingView
        Rectangle{
          color: ColorScheme.background
        }
      }
      Component {
        id: assistantView
        Rectangle{
          color: ColorScheme.background
        }
      }
    }
  }
  //3、按键音效
  SoundEffect {
    id: menuSelect
    //source: "qrc:/wav/music/buttonMusic1.wav"
    source: "qrc:/wav/music/menuSelect.wav"
    volume: 0.8
  }
  /* Function Definition------------------------------------------------------------------*/
  //1、选择菜单
  function selectMenu(targetMenu) {
    if (menuState === targetMenu)
      return
    menuSelect.play()
    switch(menuState)
    {
      case shellButton:
        shellButtonReleasedAnimation.start()
        break
      case deviceButton:
        deviceButtonReleasedAnimation.start()
        break
      case homeButton:
        homeButtonReleasedAnimation.start()
        break
      case assistantButton:
        assistantButtonReleasedAnimation.start()
        break
      case settingButton:
        settingButtonReleasedAnimation.start()
        break
    }
    switch(targetMenu)
    {
      case shellButton:
        shellButtonPressedAnimation.start()
        break
      case deviceButton:
        deviceButtonPressedAnimation.start()
        break
      case homeButton:
        homeButtonPressedAnimation.start()
        break
      case assistantButton:
        assistantButtonPressedAnimation.start()
        break
      case settingButton:
        settingButtonPressedAnimation.start()
        break
    }
    menuState = targetMenu
    root.forceActiveFocus()
  }
  //2、选择下一个菜单
  function selectNextMenu() {
    switch(menuState)
    {
      case shellButton:
        selectMenu(deviceButton)
        break
      case deviceButton:
        selectMenu(homeButton)
        break
      case homeButton:
        selectMenu(assistantButton)
        break
      case assistantButton:
        selectMenu(settingButton)
        break
      case settingButton:
        selectMenu(shellButton)
        break
    }
  }
  //3、选择上一个菜单
  function selectPrevMenu() {
    switch(menuState)
    {
      case shellButton:
        selectMenu(settingButton)
        break
      case deviceButton:
        selectMenu(shellButton)
        break
      case homeButton:
        selectMenu(deviceButton)
        break
      case assistantButton:
        selectMenu(homeButton)
        break
      case settingButton:
        selectMenu(assistantButton)
        break
    }
  }
  /* Signal Definition------------------------------------------------------------------*/
  /* Slots Definition------------------------------------------------------------------*/
  //1、菜单项更改槽函数
  onMenuStateChanged: {
    switch(menuState)
    {
      case shellButton:
        windowView.changeView(windowMenu.get("shell"))
        break;
      case deviceButton:
        windowView.changeView(windowMenu.get("device"))
        break;
      case homeButton:
        windowView.changeView(windowMenu.get("home"))
        break;
      case assistantButton:
        windowView.changeView(windowMenu.get("assistant"))
        break;
      case settingButton:
        windowView.changeView(windowMenu.get("setting"))
        break;
    }
  }
  //2、组件加载完成槽函数
  Component.onCompleted: {
    forceActiveFocus()
  }
  //3、键盘监听槽函数
  Keys.onPressed: function(event) {
    if (event.key === Qt.Key_Left && UiGlobalData.focusState === UiDataType.MenuSelect)
    {
      selectPrevMenu()
      event.accepted = true
    }
    else if (event.key === Qt.Key_Right && UiGlobalData.focusState === UiDataType.MenuSelect)
    {
      selectNextMenu()
      event.accepted = true
    }
  }
  /* Connection Definition------------------------------------------------------------------*/
}
