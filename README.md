# Sophonix(智子系统)

---

>- 作者：ChenZR
>- 简介：个人应用软件
>- 日期：2026年4月7日

---

## 第一部分	需求分析

- 软件页面：
  - 终端：
  - 设备：
  - 主页：
  - 助手：
  - 设置：

## 第二部分	项目架构

- 目录结构：
  - moudle
  - resource
  - thirdParty
  - utility
  - CMakeLists.txt
  - main.cpp
  - Main.qml

## 第三部分	类结构

```mermaid
classDiagram
  class SophonixCore {
    -Interface*  qmlInterface
  }
  class Interface {
    -UiWindowInterface*  windowInterface
  }
  class UiWindowInterface {
    -UiShellInterface* uiShellInterface
  }
  class UiShellInterface {
    -ShellInterface* shellInterface
  }
  class ShellInterface {
    -ShellModelManager* shellModelManager
    +setContextProperty() sophonixShell(QML OBJECT)
  }
  class ShellModelManager {
    QVector<ShellOutputModel*> models
  }
  class ShellModel {
    uint16_t maxDataCount
    QVector<LogInfo> dataItems
  }  
  SophonixCore *-- Interface
  Interface *-- UiWindowInterface
  UiWindowInterface *-- UiShellInterface
  UiShellInterface *-- ShellInterface
  ShellInterface *-- ShellModelManager
  ShellModelManager *-- ShellModel
```

