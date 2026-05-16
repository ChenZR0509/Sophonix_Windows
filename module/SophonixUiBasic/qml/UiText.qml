/**
 * @file UiText
 * @brief 文本原型
 * @author ChenZR
 * @details
 */
/* Import" "------------------------------------------------------------------*/
/* Import< >------------------------------------------------------------------*/
import QtQuick
import QtQuick.Controls
/* Root ----------------------------------------------------------------------*/
Control{
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property alias textObject: textObject
  property string textContent: ""
  property string textFamily: ""
  property int textSize: 18
  property color textColor: uiColor.white
  /* Property Setting------------------------------------------------------------------*/
  implicitWidth: textObject.implicitWidth
  contentItem: textObject
  /* Object Definition------------------------------------------------------------------*/
  Text{
    id: textObject
    padding: 0
    text: textContent
    font.family: textFamily
    font.pixelSize: textSize
    color: textColor
    // note 常用配置
    // font.bold: true
    // font.italic: false
    // font.letterSpacing: 0
    // horizontalAlignment: Text.AlignHCenter
    // verticalAlignment: Text.AlignVCenter
    //
  }
  /* Function Definition------------------------------------------------------------------*/
  /* Signal Definition------------------------------------------------------------------*/
  /* Slots Definition------------------------------------------------------------------*/
  /* Connection Definition------------------------------------------------------------------*/
}
