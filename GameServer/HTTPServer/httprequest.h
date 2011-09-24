/**
* @file httprequest.h
* @brief ���� �������� �������� ������, ��������������� ���������� HTTP ������
* @author Kharkunov Eugene
* @date 16.09.2011
*/
#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QObject>
#include <QMap>
#include "httpdefs.h"

/**
* @class HttpRequest
* @brief �����, ����������� ��������� � ������������� ����������� ������� �� ��������� HTTP
* @note Read-only class
*/
class HttpRequest : public QObject
{
    Q_OBJECT
public:
    /**
    * @brief ����������� ������. � ��� ���������� ������ ���������� ������� � ������� ���������� ���������
    * @param str ������, ���������� ���������� ������
    * @param parent ��������� �� ������������ ������
    */
    explicit HttpRequest(QString str, QObject *parent = 0);

    //! ����������� ���������� ������
    virtual ~HttpRequest();

    /**
    * @brief �������� ������������� URL
    * @return ������, ���������� URL �������������� �������
    */
    QString url() const;

    /**
    * @brief �������� ���� � �������������� �������
    * @return ������, ���������� ���� � ������� ������������ �������� ����������
    * @sa Config::rootDirectory
    */
    QString path() const;

    /**
    * @brief �������� ����� ���������
    * @return ����� �������. � ������ ��������� ���� �� ��������������� ������� ���������� Method::UNDEFINED
    */
    Method method() const;

    /**
    * @brief �������� ��������, �� �������� ��������� ���������� ������
    * @return �������� ���������
    * @note �������������� ������ HTTP 1.0, HTTP 1.1
    */
    QString protocol() const;

    /**
    * @brief �������� ����� ������ ���������
    * @return ������ ���������
    */
    double version() const;

    /**
    * @brief ��������� ����������� �������� � �������� ���� ��������� �������
    * @param field �������� ���� ���������
    * @param value �������� ���� ���������
    */
    void addHeaderValue(QString field, QString value);

    /**
    * @brief �������� �������� �������������� ���� ���������
    * @param field ������������� ����
    * @return �������� ������� ����
    */
    QString getHeaderValue(const QString field) const;

    /**
    * @brief �������� ��������� ������������� �������
    * @return ��������� ������������� �������
    */
    QString requestStr() const;

private:
    //! ��������� ������������� ����������� �������
    QString _mRequestStr;

    //! ����������� ����� ����� ��������� � ��� ���������
    QMap<QString, QString> headersField2Value;

    //! ������������� URL �������
    QString _mUrl;

    //! ���� � �������������� ������� ������������ �������� ����������
    QString _mPath;

    //! ����� �������
    Method _mMethod;

    //! ��������, �� �������� �������������� ������ ������
    QString _mProtocol;

    //! ������ ���������
    double _mVersion;
};

#endif // HTTPREQUEST_H
