/**
 * @file UiShell.qml
 * @brief 终端
 * @author ChenZR
 * @details
 */
/* Import" "------------------------------------------------------------------*/
import SophonixUiBasic 1.0
import SophonixUiComponent 1.0
/* Import< >------------------------------------------------------------------*/
import QtQuick
import QtQuick.Shapes
import QtQuick.Controls
import QtQuick.Controls.Basic
/* Root ----------------------------------------------------------------------*/
Control {
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property int viewState: UiDataType.ViewExit   //组件状态
  /* Property Setting------------------------------------------------------------------*/
  padding: 3*SizeScheme.mediumConner
  background: UiShellBackground{
    id: cliBackground
    viewState: root.viewState
    onEnterFinished: {
      cliContent.enter()
    }
  }
  contentItem: UiShellSurface{
    id: cliContent
    width: availableWidth
    height: availableHeight
  }
  /* Object Definition------------------------------------------------------------------*/
  /* Function Definition------------------------------------------------------------------*/
  // onEnter 入场
  function onEnter() {
    root.viewState = UiDataType.ViewEnter
    root.forceActiveFocus()
  }
  function onExit() {
    root.viewState = UiDataType.ViewExit
  }
  function onDuplicate() {
    root.viewState = UiDataType.ViewDuplicate
  }
  /* Signal Definition------------------------------------------------------------------*/
  /* Slots Definition------------------------------------------------------------------*/
  /* Connection Definition------------------------------------------------------------------*/
}
