/**
 * @file UiView.h
 * @brief 视图加载器
 * @author ChenZR
 * @note:
 *  1、view内容按需提供onDuplicate函数、onExit函数、onEnter函数
 */
/* Import" "------------------------------------------------------------------*/
/* Import< >------------------------------------------------------------------*/
import QtQuick
import QtQuick.Controls
/* Root ----------------------------------------------------------------------*/
Control{
  id: root
  /* Property Definition------------------------------------------------------------------*/
  property alias viewloader: loader
  property Component viewContent: null
  /* Property Setting------------------------------------------------------------------*/
  /* Object Definition------------------------------------------------------------------*/
  contentItem: Loader {
    id: loader
    sourceComponent: viewContent
  }
  /* Function Definition------------------------------------------------------------------*/
  /* Signal Definition------------------------------------------------------------------*/
  signal changeView(Component view)
  /* Slots Definition------------------------------------------------------------------*/
  onChangeView: view => {
    if(!view) return;
    if(view === viewContent)
    {
      if(loader.item && loader.item.onDuplicate)
        loader.item.onDuplicate()
      return
    }
    if(loader.item && loader.item.onExit)
    {
      loader.item.onExit()
    }
    viewContent = view
    if(loader.item && loader.item.onEnter)
    {
      loader.item.onEnter()
    }
  }
  /* Connection Definition------------------------------------------------------------------*/
}
