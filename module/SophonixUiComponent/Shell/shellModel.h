#pragma once
/**
 * @file shellOutputModel
 * @brief shell输出模型
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
/* Includes< >------------------------------------------------------------------*/
#include <qqml.h>
#include <QAbstractListModel>
/* NameSpace------------------------------------------------------------------*/
namespace Sophonix::Ui::Component
{
class ShellModel: public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    /**
     * @name ShellModel
     * @brief 构造函数
     *
     * @param[in] parent 对象树父节点
     */
    explicit ShellModel(QObject *parent = nullptr);
    /**
     * @name ~ShellModel
     * @brief 析构函数
     */
    ~ShellModel();
public:
    enum Roles
    {
        NameRole = Qt::UserRole + 1,
        TimeRole,
        LevelRole,
        ContentRole
    };
    enum Columns
    {
        NameColumn = 0,
        TimeColumn,
        LevelColumn,
        ContentColumn
    };
    typedef struct LogInfo
    {
        QString name;
        QString time;
        QString level;
        QString content;
    }LogInfo;
private:
    /// maxDataCount 最大历史数据容量
    uint16_t maxDataCount {500};
    /// dataItems 数据内容
    QVector<LogInfo> dataItems {};
    /// startIndex 最旧数据位置
    int startIndex = 0;
    /// currentSize 当前有效数据数量
    int currentSize = 0;
public:
    /**
     * @name rowCount
     * @brief 数据模型行数
     *
     * @param[in] parent 模型索引对象
     * @return int 数据模型行数
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    /**
     * @name data
     * @brief 读取数据项
     *
     * @param[in] index 数据索引
     * @param[in] role 索引规则
     * @return QVariant 数据
     */
    QVariant data(const QModelIndex &index, int role) const override;
    /**
     * @name roleNames
     * @brief 映射名称
     *
     * @return QHash<int, QByteArray> 数据
     */
    QHash<int, QByteArray> roleNames() const override;
public:
    /**
     * @name getMaxDataCount
     * @brief 读取最大历史数据容量
     *
     * @return uint16_t 最大历史数据容量
     */
    uint16_t getMaxDataCount() const;
    /**
     * @name setMaxDataCount
     * @brief 设置最大历史数据容量
     *
     * @param[in] newMaxDataCount 最大历史数据容量
     */
    void setMaxDataCount(uint16_t newMaxDataCount);
    /**
     * @name appendData
     * @brief 添加数据
     *
     * @param[in] data 待添加数据
     */
    void appendData(const LogInfo& data);
    /**
     * @name clearData
     * @brief 清除数据
     */
    void clearData();
};
}
