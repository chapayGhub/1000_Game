/**
* @file thousandgamequeryhandler.h
* @author Kharkunov Eugene
* @date 9.06.2011
* @brief ���� �������� �������� ������ ��������� ������� �������� ��� �������� ������� "������"
*/

#ifndef THOUSANDGAMEQUERYHANDLER_H
#define THOUSANDGAMEQUERYHANDLER_H

#include "abstractqueryhandler.h"

class ThousandGameServer;

/**
* @class ThousandGameQueryHandler
* @brief ����� ��������� ������� ��������, ����������� �� ������� ������. ����������� � ��������� ������.
* @sa AbstractQueryHandler
*/
class ThousandGameQueryHandler : public AbstractQueryHandler
{
    Q_OBJECT
public:
    explicit ThousandGameQueryHandler(ThousandGameServer *parentServer, QObject *parent = 0);
    void run();
private:
    ThousandGameServer *server;
};

#endif // THOUSANDGAMEQUERYHANDLER_H
