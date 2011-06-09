/**
* @file config.h
* @brief ������ ��������� ��������� �������� �������
* @author Kharkunov Eugene
* @date 2.06.2011
*/

#ifndef CONFIG_H
#define CONFIG_H

#include <QDir>
#include <QString>
#include <QMap>

/**
* @class Config
* @brief ������� �����, �������� ��������� �������:
*
*
*/
class  Config {
public:
    //! ���� � ����������, � ������� ��������� ��� ������������ ������ � ���������� �������
    static QDir pathIcons;

    //! ���� � ����������, ���������� ����� �������� ������ ���������� (*.qss)
    static QDir pathStyles;

    //! ���� � �������� ����������, � ������� �������� html-��������
    static QDir rootDirectory;

    //! ���� � ����������, � ������� ��������� ���� ������ ���� ��������� ��������
    static QDir pathDatabases;

    //! ����, �� ������� ������� http ������
    static int  portForHttpServer;

    //! ������, � ������� �������� �����, �� ������� �������� ������� �������, ��������������� � �� ����������
    static QMap<QString, int> portsForGameServers;
};

#endif // CONFIG_H
