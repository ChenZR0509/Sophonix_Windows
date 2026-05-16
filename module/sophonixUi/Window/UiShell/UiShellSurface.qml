/**
 * @file Surface
 * @brief 终端内容显示
 * @author ChenZR
 * @details
 */
/* Import" "------------------------------------------------------------------*/
import SophonixUiBasic 1.0
import SophonixUiComponent 1.0
/* Import< >------------------------------------------------------------------*/
import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Basic
/* Root ----------------------------------------------------------------------*/
FocusScope {
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property bool inputMode: true
  /* Property Setting------------------------------------------------------------------*/
  visible: false
  focus: true
  /* Object Definition------------------------------------------------------------------*/
  Shell{
    id: shell
    anchors.fill: parent
    modelManager: sophonixShell.shellModelManager
  }
  /* Function Definition------------------------------------------------------------------*/
  function enter(){
    root.visible = true
  }
  /* Signal Definition------------------------------------------------------------------*/
  /* Slots Definition------------------------------------------------------------------*/
  /* Connection Definition------------------------------------------------------------------*/
}
