/**
* @file tablemodel.h
* @author Kharkunov Eugene
* @date 27.06.2011
* @brief �������� �������� ������ ��� ������������� ������ � ���� �������
*/

#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QContextMenuEvent>

/**
* @class TableModel
* @brief �����, ����������� ������ ������������� ������ � ���� �������
*/
class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    /**
    * @brief ����������� ����������
    * @param parent ��������� �� ������������ ������
    */
    explicit TableModel(QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    virtual ~TableModel();

    /**
    * @brief ���������� ����� �������� ��� ���������� ������� @p parent
    * @param parent ������ ������������� �������
    * @return ����� ��������
    */
    virtual int columnCount(const QModelIndex &parent) const;

    /**
    * @brief ���������� ����� ����� ��� ���������� ������� @p parent
    * @param parent ������ ������������� �������
    * @return ����� �����
    */
    virtual int rowCount(const QModelIndex &parent) const;

    /**
    * @brief ���������� ������ ������������ �� ���������� �������
    * @param index ������ ������, ������� ���������� ��������
    * @param role  ����, ������� ����������� ��� ���������� ������
    * @return ������, ������� ��������� �� ���������� �������
    */
    virtual QVariant data(const QModelIndex &index, int role) const;

    /**
    * @brief ��������� ������
    * @param index ������ �������, ������� ����� ��������� � ctmt ��������������� ������
    * @param value ��������������� ������
    * @param role  ���� ��� ��������������� ������
    * @return ���������� ���������� ��������
    */
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);

    /**
    * @brief ��������� ������, ���������� � ��������� �������
    * @param section        ����� ������, � ������� �������� ����������� ���������
    * @param orientation    ���������� ������(�������������� ��� ������������)
    * @param role           ����, ������� ����������� ��� ���������� ������
    * @return ������ �� ���������� ���������
    */
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    /**
    * @brief ���������� ������������� ����� ��� ������� � ��������� ��������
    * @param index ������ �������
    * @return ������������ �����
    */
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    //! ����� ��������
    int mColCount;

    //! ����� �����
    int mRowCount;

    //! ������, ������� ���������� �����������
    QVariant** table;

    //! ������ ����������
    QVector<QString> headerNames;
};

#endif // TABLEMODEL_H
