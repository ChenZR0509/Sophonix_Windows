#pragma once
/**
 * @file shellModelManager
 * @brief shell模型管理
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "shellOutputModel.h"
/* Includes< >------------------------------------------------------------------*/
#include <qqml.h>
#include <QAbstractListModel>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix::Ui::Component
{
class ShellModelManager: public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    /**
     * @name ShellModelManager
     * @brief 构造函数
     *
     * @param[in] parent 对象树父节点
     */
    explicit ShellModelManager(QObject *parent = nullptr);
    /**
     * @name ~ShellModelManager
     * @brief 析构函数
     */
    ~ShellModelManager();
private:
    /// models shell模型
    QVector<ShellOutputModel*> models {};
public:
    /**
     * @name addModel
     * @brief 添加模型
     *
     * @return int 模型ID
     */
    Q_INVOKABLE int addModel();
    /**
     * @name removeModel
     * @brief 删除模型
     *
     * @param[in] id 待删除模型id
     */
    Q_INVOKABLE void removeModel(int id);
    /**
     * @name getModel
     * @brief 读取模型
     *
     * @param[in] id 待读取模型id
     */
    Q_INVOKABLE ShellOutputModel* getModel(int id);
};
}
