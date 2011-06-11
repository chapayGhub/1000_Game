/**
* @file thousandgamedataparser.h
* @author Kharkunov Eugene
* @date 6.06.2011
* @brief �������� �������� ������, ������� ������������ ������ ��� ��������
*/

#ifndef THOUSANDGAMEDATAPARSER_H
#define THOUSANDGAMEDATAPARSER_H

#include "abstractdataparser.h"

class ThousandGameQueryHandler;

/**
* @class DataParser
* @brief �����, �������������� ���������� ��������� ����������� ������ � ���������� ������ ��� ��������
* ��������
*/
class ThousandGameDataParser : public AbstractDataParser
{
    Q_OBJECT
public:
    /**
    * @brief ����������� �����������
    * @param parentHandler  ��������� �� ������������ ���������� ��������
    * @param parent         ��������� �� ������������ ������
    */
    explicit ThousandGameDataParser(ThousandGameQueryHandler *parentHandler, QObject *parent = 0);

    /**
    * @brief ����������� ����������
    */
    ~ThousandGameDataParser();

    /**
    * @brief �������������� �� AbstractDataParser::inRegistration
    */
    RegistrationData inRegistration(const QByteArray &data);

    /**
    * @brief �������������� �� AbstractDataParser::outRegistration
    */
    QByteArray outRegistration(QVector<QString> &information);
private:
    //! ��������� �� ���������� ������� ��������
    ThousandGameQueryHandler *handler;

signals:

public slots:

};

#endif // THOUSANDGAMEDATAPARSER_H
