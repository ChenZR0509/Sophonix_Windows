/**
 * @file UiButton
 * @brief 按键原型
 * @author ChenZR
 * @details
 */
/* Import" "------------------------------------------------------------------*/
/* Import< >------------------------------------------------------------------*/
import QtQuick
import QtQuick.Controls
/* Root ----------------------------------------------------------------------*/
Item{
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property alias buttonArea: buttonArea          //对象别名：mouseArea
  property real leftInset: 0                   //左边距
  property real rightInset: 0                  //右边距
  property real topInset: 0                    //上边距
  property real bottomInset: 0                 //下边距
  property int doubleClickInterval: 300        //双击间隔
  property int clickCount: 0                   //点击计数
  property bool enableDoubelClick: false       //是否使能双击功能
  property Component hintAnimation: null       //提示动画函数
  property Component hoverAnimation: null      //悬停动画函数
  property Component leaveAnimation: null      //离开动画函数
  property Component pressAnimation: null      //按下动画函数
  property Component releaseAnimation: null    //释放动画函数
  /* Property Setting------------------------------------------------------------------*/
  MouseArea {
    id: buttonArea
    anchors.fill: parent
    anchors.leftMargin: leftInset
    anchors.rightMargin: rightInset
    anchors.topMargin: topInset
    anchors.bottomMargin: bottomInset
    hoverEnabled: true
    onEntered: {
      stopHintAnimation()
      root.entered()
      playHoverAnimation()
    }
    onExited: {
      stopHintAnimation()
      root.exited()
      playLeaveAnimation()
    }
    onPressed: {
      stopHintAnimation()
      playPressAnimation()
    }
    onReleased: {
      stopHintAnimation()
      playReleaseAnimation()
    }
    onClicked: {
      if(enableDoubelClick) {
        clickCount++
        doubleClickTimer.restart()
      }
      else
      {
        root.clicked()
      }
    }
    Timer {
      id: doubleClickTimer
      interval: root.doubleClickInterval
      running: false
      repeat: false
      onTriggered: {
        if (clickCount === 1)
          root.clicked()
        else if (clickCount === 2)
          root.doubleClicked()
        clickCount = 0
      }
    }
  }
  /* Object Definition------------------------------------------------------------------*/
  /* Function Definition------------------------------------------------------------------*/
  function playHintAnimation() {
    if (hintAnimation) {
      var anim = hintAnimation.createObject(root)
      anim.start()
    }
  }
  function stopHintAnimation() {
    if (hintAnimation) {
      hintAnimation.destroy()
    }
  }
  function playHoverAnimation() {
    if (hoverAnimation) {
      var anim = hoverAnimation.createObject(root)
      anim.start()
    }
  }
  function playLeaveAnimation() {
    if (leaveAnimation) {
      var anim = leaveAnimation.createObject(root)
      anim.start()
    }
  }
  function playPressAnimation() {
    if (pressAnimation) {
      var anim = pressAnimation.createObject(root)
      anim.start()
    }
  }
  function playReleaseAnimation() {
    if (releaseAnimation) {
      var anim = releaseAnimation.createObject(root)
      anim.start()
    }
  }
  /* Signal Definition------------------------------------------------------------------*/
  signal entered()
  signal exited()
  signal clicked()
  signal doubleClicked()
  /* Slots Definition------------------------------------------------------------------*/
  Component.onCompleted: {
    playHintAnimation()
  }
  /* Connection Definition------------------------------------------------------------------*/
}
