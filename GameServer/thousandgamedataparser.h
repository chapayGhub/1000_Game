/**
* @file thousandgamedataparser.h
* @author Kharkunov Eugene
* @date 6.06.2011
* @brief �������� �������� ������, ������� ������������ ������ ��� ��������
*/

#ifndef THOUSANDGAMEDATAPARSER_H
#define THOUSANDGAMEDATAPARSER_H

#include "abstractdataparser.h"

/**
* @class DataParser
* @brief �����, �������������� ���������� ��������� ����������� ������ � ���������� ������ ��� ��������
* ��������
*/
class ThousandGameDataParser : public AbstractDataParser
{
    Q_OBJECT
public:
    explicit ThousandGameDataParser(QObject *parent = 0);

signals:

public slots:

};

#endif // THOUSANDGAMEDATAPARSER_H
