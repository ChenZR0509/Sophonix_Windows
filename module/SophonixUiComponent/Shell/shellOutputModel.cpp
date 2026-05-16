/**
 * @file shellOutputModel
 * @brief shell输出模型
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "shellOutputModel.h"
/* Includes< >------------------------------------------------------------------*/

/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui::Component
{

ShellOutputModel::ShellOutputModel(QObject *parent)
    : QAbstractListModel(parent)
{
    LogInfo log{
        .name = "ChenZR",
        .content = "Hello",
    };
    appendData(log);
}

ShellOutputModel::~ShellOutputModel()
{
    ;
}

void ShellOutputModel::setMaxDataCount(uint16_t newMaxDataCount)
{
    maxDataCount = newMaxDataCount;
}

uint16_t ShellOutputModel::getMaxDataCount() const
{
    return maxDataCount;
}

int ShellOutputModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }
    else
    {
        return dataItems.size();
    }
}

QVariant ShellOutputModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= dataItems.size() || index.row() < 0)
    {
        return QVariant();
    }
    const LogInfo& log = dataItems.at(index.row());
    switch (role)
    {
        case NameRole:
            return log.name;
        case TimeRole:
            return log.time;
        case LevelRole:
            return log.level;
        case ContentRole:
            return log.content;
        default:
            return QVariant{};
    }
}

void ShellOutputModel::appendData(const LogInfo& data)
{
    int row = dataItems.count();
    beginInsertRows(QModelIndex(), row, row);
    dataItems.append(data);
    endInsertRows();
}

void ShellOutputModel::clearData()
{
    beginResetModel();
    dataItems.clear();
    endResetModel();
}

void ShellOutputModel::insertData(int row, const LogInfo &data)
{
    if (row < 0 || row > dataItems.size())
    {
        return;
    }
    beginInsertRows(QModelIndex(), row, row);
    dataItems.insert(row, data);
    endInsertRows();
}

void ShellOutputModel::removeLine(int row)
{
    if (row < 0 || row >= dataItems.size())
    {
        return;
    }
    beginRemoveRows(QModelIndex(), row, row);
    dataItems.removeAt(row);
    endRemoveRows();
}

QHash<int, QByteArray> ShellOutputModel::roleNames() const
{
    return {
        { NameRole, "name" },
        { ContentRole, "content" },
        { TimeRole, "time"},
        { LevelRole, "level"},
        { ContentRole, "content"}
    };
}
}
