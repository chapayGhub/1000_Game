/**
* @file httpresponse.h
* @brief ���� �������� �������� ������, ��������������� ����� HTTP �������
* @author Kharkunov Eugene
* @date 16.09.2011
*/
#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <QObject>
#include <QHash>

//! �������, �������� � ���� ���������� ������� ����� ��������� � �� ��������� ���������
extern QHash<int, QString> STATUS_CODE;

/**
* @macro ADD_CODE
* @brief ������ ��� ���������� ���� ��������� ������ ������� � ��� ���������� ��������
* @param num ��� ���������
* @param status ��������� ��������
*/
#define ADD_CODE(num, status) STATUS_CODE.insert(num, status)

class HttpRequest;

/**
* @class HttpResponse
* @brief ����� ������ ������� �� ��������� HTTP
*/
class HttpResponse : public QObject
{
    Q_OBJECT
public:
    /**
    * @brief ����������� ������
    * @param name ��� �������, ������� ��������� �����
    * @param parent ��������� �� ������������ ������
    */
    explicit HttpResponse(QString name, QObject *parent = 0);

    //! ����������� ����������
    virtual ~HttpResponse();

    /**
    * @brief ������� ���������� ��������� � ���� ������
    * @param request ���������� ������, ��� �������� ����������� �����
    * @param arr     ���� ������
    */
    void prepareResponse(const HttpRequest &request, QByteArray &arr);

    /**
    * @brief ������� ���������� ��������� ������������� ������ �������
    * @return ��������� ������������� ������ �������
    */
    QString responseStr() const;

private:
    //! ��� �������, ������������ �����
    QString serverName;

    //! ��������� ������������� ������ �������
    QString _mResponseStr;

    /**
    * @brief �������, ����������� ���������� ���� ������
    * @param filePath ���� � �������������� �����
    * @param found    ����, ��������������� � ������� �������������� �����
    * @return ������������� ������
    * @note � ������ ����������� ����������� ������, ������������ �������� � ���������� �� ������
    */
    QByteArray prepareData(const QString filePath, bool &found);
};

#endif // HTTPRESPONSE_H
