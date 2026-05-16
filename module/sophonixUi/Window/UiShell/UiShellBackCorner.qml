/**
 * @file BackCorner.qml
 * @brief 背景装饰组件
 * @author ChenZR
 * @details
 */
/* Import" "------------------------------------------------------------------*/
import SophonixUiBasic 1.0
/* Import< >------------------------------------------------------------------*/
import QtQuick
import QtQuick.Shapes
/* Root ----------------------------------------------------------------------*/
Shape {
  id: root
  /* Property Definition------------------------------------------------------------------*/
  /* Property Setting------------------------------------------------------------------*/
  ShapePath {
    id: line1
    strokeWidth: 1
    strokeColor: ColorScheme.white
    fillColor: ColorScheme.background
    startX: 0; startY: 0
    PathLine { x: root.width/2; y: root.height/2}
  }
  ShapePath {
    id: line6
    strokeWidth: 2
    strokeColor: ColorScheme.white
    fillColor: ColorScheme.background
    startX: 0; startY: 0
    PathLine { x: root.width/16; y: root.height/16}
  }
  ShapePath {
    id: line7
    strokeWidth: 2
    strokeColor: ColorScheme.white
    fillColor: ColorScheme.background
    startX: root.width/2; startY: root.height/2
    PathLine { x: root.width/2-root.width/16; y: root.height/2-root.height/16}
  }
  ShapePath {
    id: line2
    strokeWidth: 1
    strokeColor: ColorScheme.white
    fillColor: ColorScheme.background
    startX: root.width/6; startY: root.height/6
    PathLine { x: root.width; y: root.height/6}
    PathLine { x: root.width; y: root.height/3}
  }
  ShapePath {
    id: line3
    strokeWidth: 1
    strokeColor: ColorScheme.white
    fillColor: ColorScheme.background
    startX: root.width/6; startY: root.height/6
    PathLine { x: root.width/6; y: root.height}
    PathLine { x: root.width/3; y: root.height}
  }
  ShapePath {
    id: line4
    strokeWidth: 1
    strokeColor: ColorScheme.white
    fillColor: ColorScheme.background
    startX: root.width; startY: root.height/6
    PathLine { x: root.width; y: root.height/3}
  }
  ShapePath {
    id: line5
    strokeWidth: 1
    strokeColor: ColorScheme.white
    fillColor: ColorScheme.background
    startX: root.width/6; startY: root.height
    PathLine { x: root.width/3; y: root.height}
  }
  /* Object Definition------------------------------------------------------------------*/
  /* Function Definition------------------------------------------------------------------*/
  /* Signal Definition------------------------------------------------------------------*/
  /* Slots Definition------------------------------------------------------------------*/
  /* Connection Definition------------------------------------------------------------------*/
}
