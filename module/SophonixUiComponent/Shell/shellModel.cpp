/**
 * @file shellOutputModel
 * @brief shell输出模型
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
#include "shellModel.h"
/* Includes< >------------------------------------------------------------------*/

/* Namespace------------------------------------------------------------------*/
namespace Sophonix::Ui::Component
{

ShellModel::ShellModel(QObject *parent)
    : QAbstractListModel(parent)
{
    dataItems.reserve(maxDataCount);
    LogInfo log{
        .name = "ChenZR",
        .content = "Hello",
    };
    appendData(log);
}

ShellModel::~ShellModel()
{
    ;
}

void ShellModel::setMaxDataCount(uint16_t newMaxDataCount)
{
    if (newMaxDataCount == 0 || newMaxDataCount == maxDataCount)
    {
        return;
    }
    beginResetModel();
    maxDataCount = newMaxDataCount;
    dataItems.clear();
    dataItems.reserve(maxDataCount);
    startIndex = 0;
    currentSize = 0;
    endResetModel();
}

QHash<int, QByteArray> Sophonix::Ui::Component::ShellModel::roleNames() const
{
    return {
        {NameRole, "name"},
        {TimeRole, "time"},
        {LevelRole, "level"},
        {ContentRole, "content"}
    };
}

uint16_t ShellModel::getMaxDataCount() const
{
    return maxDataCount;
}

int ShellModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return currentSize;
}

QVariant ShellModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }
    int row = index.row();
    if (row < 0 || row >= currentSize)
    {
        return QVariant();
    }
    int realIndex = (startIndex + row) % maxDataCount;
    const LogInfo& log = dataItems.at(realIndex);
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

void ShellModel::appendData(const LogInfo& data)
{
    if (currentSize < maxDataCount)
    {
        int row = currentSize;
        beginInsertRows(QModelIndex(), row, row);
        dataItems.append(data);
        currentSize++;
        endInsertRows();
    }
    else
    {
        dataItems[startIndex] = data;
        startIndex = (startIndex + 1) % maxDataCount;
        emit dataChanged(index(0, 0),index(currentSize - 1, 0));
    }
}

void ShellModel::clearData()
{
    beginResetModel();
    dataItems.clear();
    startIndex = 0;
    currentSize = 0;
    endResetModel();
}

}
