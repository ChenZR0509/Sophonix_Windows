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
Column {
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property var modelManager: null
  /* Property Setting------------------------------------------------------------------*/
  spacing: 4
  /* Object Definition------------------------------------------------------------------*/
  ShellOutput {
    id: cliOutput
    width: root.width
    model: modelManager.getModel(0)
  }
  ShellInput {
    id: cliInput
    width: root.width
  }
  /* Function Definition------------------------------------------------------------------*/
  /* Signal Definition------------------------------------------------------------------*/
  /* Slots Definition------------------------------------------------------------------*/
  /* Connection Definition------------------------------------------------------------------*/
}
