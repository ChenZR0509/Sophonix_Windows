/**
 * @file CliIutput
 * @brief CLI输入显示组件
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
Rectangle{
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property real fontSize: 18
  property real spacing: 4
  property string userName: "ChenZR"
  /* Property Setting------------------------------------------------------------------*/
  height: Math.max(name.height,content.height)
  color: ColorScheme.background
  /* Object Definition------------------------------------------------------------------*/
  UiText{
    id: name
    anchors.left: root.left
    anchors.top: root.top
    textContent: userName + ": "
    textFamily: "Consolas"
    textSize: fontSize
    textColor: "#FFFFFF"
    textObject.horizontalAlignment: Text.AlignHCenter
    textObject.verticalAlignment: Text.AlignTop
  }
  TextInput {
    id: content
    anchors.left: name.right
    anchors.right: root.right
    anchors.verticalCenter: root.verticalCenter
    focus: true
    focusPolicy: Qt.StrongFocus
    activeFocusOnPress: true
    font.family: "Consolas"
    font.pixelSize: fontSize
    color: "#00FFFF"
    verticalAlignment: TextInput.AlignVCenter
    selectByMouse: true
    wrapMode: Text.Wrap
    Keys.onPressed: function(event) {
      if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter){
        if(UiGlobalData.focusState !== UiDataType.ChildrenInput){
          return
        }
        root.inputCommand(text)
        text = ""
        event.accepted = true
      }
      else if (event.key === Qt.Key_Escape){
        UiGlobalData.focusState = UiDataType.MenuSelect
      }
    }
    Component.onCompleted: {
      Qt.callLater(() => content.forceActiveFocus())
      UiGlobalData.focusState = UiDataType.ChildrenInput
    }
  }
  /* Function Definition------------------------------------------------------------------*/  
  /* Signal Definition------------------------------------------------------------------*/
  /* Slots Definition------------------------------------------------------------------*/
  /* Connection Definition------------------------------------------------------------------*/
}
