/**
 * @file Background.qml
 * @brief 背景组件
 * @author ChenZR
 * @details
 */
/* Import" "------------------------------------------------------------------*/
import SophonixUiBasic 1.0
/* Import< >------------------------------------------------------------------*/
import QtQuick
import QtQuick.Shapes
import QtQuick.Controls
/* Root ----------------------------------------------------------------------*/
Control{
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property int viewState: UiDataType.ViewExit   //组件状态
  /* Property Setting------------------------------------------------------------------*/
  /* Object Definition------------------------------------------------------------------*/
  UiShellBackCorner{
    id: leftTopCorner
    anchors.left: root.left
    anchors.top: root.top
    width: SizeScheme.mediumConner*2
    height: SizeScheme.mediumConner*2
  }
  UiShellBackCorner{
    id: rightTopCorner
    anchors.right: root.right
    anchors.top: root.top
    width: SizeScheme.mediumConner*2
    height: SizeScheme.mediumConner*2
    rotation: 90
  }
  UiShellBackCorner{
    id: leftBottomCorner
    anchors.left: root.left
    anchors.bottom: root.bottom
    width: SizeScheme.mediumConner*2
    height: SizeScheme.mediumConner*2
    rotation: 270
  }
  UiShellBackCorner{
    id: rightBottomCorner
    anchors.right: root.right
    anchors.bottom: root.bottom
    width: SizeScheme.mediumConner*2
    height: SizeScheme.mediumConner*2
    rotation: 180
  }
  Rectangle{
    id: mainArea
    readonly property real widthUnit: mainArea.width/100
    readonly property real heightUnit: mainArea.height/36
    anchors.fill: root
    anchors.margins: SizeScheme.mediumConner
    color: ColorScheme.background
    Rectangle{
      id: mainBorder
      anchors.fill: mainArea
      anchors.margins: SizeScheme.mediumConner
      color: ColorScheme.background
      border.width: 1
      border.color: ColorScheme.outline
    }
    Rectangle{
      id: leftRec1
      anchors.top: mainBorder.top
      anchors.topMargin: -SizeScheme.mediumConner/4
      anchors.horizontalCenter: mainBorder.left
      color: ColorScheme.white
      width: SizeScheme.mediumConner/2
      height: 0
    }
    Rectangle{
      id: topRec1
      anchors.top: mainBorder.top
      anchors.topMargin: -SizeScheme.mediumConner/4
      anchors.left: leftRec1.left
      color: ColorScheme.white
      height: SizeScheme.mediumConner/2
      width: 0
    }

    Rectangle{
      id: rightRec1
      anchors.top: mainBorder.top
      anchors.topMargin: -SizeScheme.mediumConner/4
      anchors.horizontalCenter: mainBorder.right
      color: ColorScheme.white
      width: SizeScheme.mediumConner/2
      height: 0
    }
    Rectangle{
      id: topRec7
      anchors.top: mainBorder.top
      anchors.topMargin: -SizeScheme.mediumConner/4
      anchors.right: rightRec1.right
      color: ColorScheme.white
      height: SizeScheme.mediumConner/2
      width: 0
    }

    Rectangle{
      id: leftRec3
      anchors.bottom: mainBorder.bottom
      anchors.bottomMargin: -SizeScheme.mediumConner/4
      anchors.horizontalCenter: mainBorder.left
      color: ColorScheme.white
      width: SizeScheme.mediumConner/2
      height: 0
    }
    Rectangle{
      id: bottomRec1
      anchors.bottom: mainBorder.bottom
      anchors.bottomMargin: -SizeScheme.mediumConner/4
      anchors.left: leftRec3.left
      color: ColorScheme.white
      height: SizeScheme.mediumConner/2
      width: 0
    }

    Rectangle{
      id: rightRec3
      anchors.bottom: mainBorder.bottom
      anchors.bottomMargin: -SizeScheme.mediumConner/4
      anchors.horizontalCenter: mainBorder.right
      color: ColorScheme.white
      width: SizeScheme.mediumConner/2
      height: 0
    }
    Rectangle{
      id: bottomRec7
      anchors.bottom: mainBorder.bottom
      anchors.bottomMargin: -SizeScheme.mediumConner/4
      anchors.right: rightRec1.right
      color: ColorScheme.white
      height: SizeScheme.mediumConner/2
      width: 0
    }

    Rectangle{
      id: leftRec2
      anchors.verticalCenter: mainBorder.verticalCenter
      anchors.horizontalCenter: mainBorder.left
      color: ColorScheme.background
      width: SizeScheme.mediumConner/2
      height: 24*mainArea.heightUnit
      border.width: 1
      border.color: ColorScheme.white
      opacity: 0
    }
    Rectangle{
      id: rightRec2
      anchors.verticalCenter: mainBorder.verticalCenter
      anchors.horizontalCenter: mainBorder.right
      color: ColorScheme.background
      width: SizeScheme.mediumConner/2
      height: 24*mainArea.heightUnit
      border.width: 1
      border.color: ColorScheme.white
      opacity: 0
    }

    Rectangle{
      id: topRec2
      anchors.top: mainBorder.top
      anchors.topMargin: -SizeScheme.mediumConner/4
      anchors.left: topRec1.right
      anchors.leftMargin: mainArea.widthUnit
      color: ColorScheme.background
      height: SizeScheme.mediumConner/2
      width: 4*mainArea.widthUnit
      border.width: 1
      border.color: ColorScheme.white
      opacity: 0
    }
    Rectangle{
      id: topRec6
      anchors.top: mainBorder.top
      anchors.topMargin: -SizeScheme.mediumConner/4
      anchors.right: topRec7.left
      anchors.rightMargin: mainArea.widthUnit
      color: ColorScheme.background
      height: SizeScheme.mediumConner/2
      width: 4*mainArea.widthUnit
      border.width: 1
      border.color: ColorScheme.white
      opacity: 0
    }
    Rectangle{
      id: bottomRec2
      anchors.bottom: mainBorder.bottom
      anchors.bottomMargin: -SizeScheme.mediumConner/4
      anchors.left: bottomRec1.right
      anchors.leftMargin: mainArea.widthUnit
      color: ColorScheme.background
      height: SizeScheme.mediumConner/2
      width: 4*mainArea.widthUnit
      border.width: 1
      border.color: ColorScheme.white
      opacity: 0
    }
    Rectangle{
      id: bottomRec6
      anchors.bottom: mainBorder.bottom
      anchors.bottomMargin: -SizeScheme.mediumConner/4
      anchors.right: bottomRec7.left
      anchors.rightMargin: mainArea.widthUnit
      color: ColorScheme.background
      height: SizeScheme.mediumConner/2
      width: 4*mainArea.widthUnit
      border.width: 1
      border.color: ColorScheme.white
      opacity: 0
    }

    Rectangle{
      id: topRec3
      anchors.top: mainBorder.top
      anchors.topMargin: -SizeScheme.mediumConner/8
      anchors.left: topRec2.right
      anchors.leftMargin: mainArea.widthUnit
      color: ColorScheme.white
      height: SizeScheme.mediumConner/4
      width: 0
      opacity: 0
    }
    Rectangle{
      id: topRec5
      anchors.top: mainBorder.top
      anchors.topMargin: -SizeScheme.mediumConner/8
      anchors.right: topRec6.left
      anchors.rightMargin: mainArea.widthUnit
      color: ColorScheme.white
      height: SizeScheme.mediumConner/4
      width: 0
      opacity: 0.8
    }
    Rectangle{
      id: bottomRec3
      anchors.bottom: mainBorder.bottom
      anchors.bottomMargin: -SizeScheme.mediumConner/8
      anchors.left: bottomRec2.right
      anchors.leftMargin: mainArea.widthUnit
      color: ColorScheme.white
      height: SizeScheme.mediumConner/4
      width: 0
      opacity: 0
    }
    Rectangle{
      id: bottomRec5
      anchors.bottom: mainBorder.bottom
      anchors.bottomMargin: -SizeScheme.mediumConner/8
      anchors.right: bottomRec6.left
      anchors.rightMargin: mainArea.widthUnit
      color: ColorScheme.white
      height: SizeScheme.mediumConner/4
      width: 0
      opacity: 0.8
    }

    Rectangle{
      id: topRec4
      anchors.top: mainBorder.top
      anchors.topMargin: -SizeScheme.mediumConner/4
      anchors.horizontalCenter: mainBorder.horizontalCenter
      color: ColorScheme.white
      height: SizeScheme.mediumConner/2
      width: 0
    }
    Rectangle{
      id: bottomRec4
      anchors.bottom: mainBorder.bottom
      anchors.bottomMargin: -SizeScheme.mediumConner/4
      anchors.horizontalCenter: mainBorder.horizontalCenter
      color: ColorScheme.white
      height: SizeScheme.mediumConner/2
      width: 0
    }

  }
  /* Animation Definition------------------------------------------------------------------*/
  SequentialAnimation{
    id: enterAnimation
    NumberAnimation{
      target: mainBorder
      property: "scale"
      from: 0.6
      to: 1.0
      duration: 250
      easing.type: Easing.InCubic
    }
    ParallelAnimation{
      NumberAnimation{
        targets: [leftRec1,leftRec3,rightRec1,rightRec3]
        property: "height"
        from: 0
        to: 4*mainArea.heightUnit
        duration: 200
        easing.type: Easing.InCubic
      }
      NumberAnimation{
        targets: [topRec1,topRec7,bottomRec1,bottomRec7]
        property: "width"
        from: 0
        to: 2*mainArea.widthUnit
        duration: 200
        easing.type: Easing.InCubic
      }
    }
    NumberAnimation{
      targets: [leftRec2,rightRec2]
      property: "opacity"
      from: 0
      to: 1.0
      duration: 150
      easing.type: Easing.InCubic
    }
    NumberAnimation{
      targets: [topRec2,topRec6,bottomRec2,bottomRec6]
      property: "opacity"
      from: 0
      to: 1.0
      duration: 150
      easing.type: Easing.InCubic
    }
    ParallelAnimation{
      NumberAnimation{
        targets: [topRec3,topRec5,bottomRec3,bottomRec5]
        property: "width"
        from: 0
        to: 12*mainArea.widthUnit
        duration: 150
        easing.type: Easing.InCubic
      }
      NumberAnimation{
        targets: [topRec4,bottomRec4]
        property: "width"
        from: 0
        to: 54*mainArea.widthUnit
        duration: 150
        easing.type: Easing.InCubic
      }
    }
    onFinished: {
      root.enterFinished()
    }
  }
  ParallelAnimation{
    id: normalAnimation
    running: true
    loops: Animation.Infinite
    SequentialAnimation{
      NumberAnimation{
        targets: [topRec3,bottomRec5]
        property: "opacity"
        from: 0
        to: 0.8
        duration: 500
        easing.type: Easing.InOutCubic
      }
      NumberAnimation{
        targets: [topRec3,bottomRec5]
        property: "opacity"
        from: 0.8
        to: 0
        duration: 500
        easing.type: Easing.InOutCubic
      }
    }
    SequentialAnimation{
      NumberAnimation{
        targets: [topRec5,bottomRec3]
        property: "opacity"
        from: 0.8
        to: 0
        duration: 500
        easing.type: Easing.InOutCubic
      }
      NumberAnimation{
        targets: [topRec5,bottomRec3]
        property: "opacity"
        from: 0
        to: 0.8
        duration: 500
        easing.type: Easing.InOutCubic
      }
    }
  }
  /* Function Definition------------------------------------------------------------------*/
  /* Signal Definition------------------------------------------------------------------*/
  signal enterFinished()
  /* Slots Definition------------------------------------------------------------------*/
  onViewStateChanged: {
    switch(viewState) {
      case UiDataType.ViewEnter:
        enterAnimation.start();
        break
      case UiDataType.ViewExit:
        break
      default:
        break;
    }
  }
  /* Connection Definition------------------------------------------------------------------*/
}
