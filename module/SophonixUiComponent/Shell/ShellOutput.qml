/**
 * @file CliOutput
 * @brief CLI输出显示组件
 * @author ChenZR
 * @details
 */
/* Import" "------------------------------------------------------------------*/
import SophonixUiBasic 1.0
/* Import< >------------------------------------------------------------------*/
import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Basic
/* Root ----------------------------------------------------------------------*/
ListView{
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property real fontSize: 18
  /* Property Setting------------------------------------------------------------------*/
  height: contentHeight
  clip: false
  interactive: false
  spacing: 4
  delegate: cliOutput
  /* Object Definition------------------------------------------------------------------*/
  Component{
    id: cliOutput
    Rectangle{
      id: outputSurface
      implicitHeight: Math.max(name.height,content.height)
      width: root.width
      color: ColorScheme.background
      UiText{
        id: name
        padding: 0
        anchors.left: outputSurface.left
        anchors.top: outputSurface.top
        textContent: model.name + ": "
        textFamily: "Consolas"
        textSize: fontSize
        textColor: "#FFFFFF"
        textObject.horizontalAlignment: Text.AlignHCenter
        textObject.verticalAlignment: Text.AlignTop
      }
      UiText{
        id: content
        anchors.left: name.right
        anchors.right: outputSurface.right
        anchors.top: outputSurface.top
        textContent: model.content
        textFamily: "Consolas"
        textSize: fontSize
        textColor: "#00FFFF"
        textObject.textFormat: Text.RichText
        textObject.horizontalAlignment: Text.AlignJustify
        textObject.verticalAlignment: Text.AlignTop
        textObject.wrapMode: Text.Wrap
        textObject.lineHeight: (root.spacing+fontSize)/fontSize
      }
    }
  }
  /* Function Definition------------------------------------------------------------------*/
  /* Signal Definition------------------------------------------------------------------*/
  /* Slots Definition------------------------------------------------------------------*/
  /* Connection Definition------------------------------------------------------------------*/
}
