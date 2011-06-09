#include "thousandgamequeryhandler.h"
#include "thousandgameserver.h"
#include "thousandgamedataparser.h"
#include "protocol.h"

ThousandGameQueryHandler::ThousandGameQueryHandler(ThousandGameServer *parentServer, QObject *parent) :
    AbstractQueryHandler(parent),
    server(parentServer)
{
//    parser = new ThousandGameDataParser(parent);
}

ThousandGameQueryHandler::~ThousandGameQueryHandler() {
    delete parser;
    parser = 0;
}

void ThousandGameQueryHandler::run() {
    QueryStruct request;
    bool empty;
    do {
        //��������� ������, ������� ��������� ������ � �������
        server->locker.lockForRead();
        request = server->_mRequestQueries.first();
        server->locker.unlock();
        QueryType type = request.type;
        switch(type) {
        case REGISTER : {
            break;
        }
        case AUTHORIZATION : {
            break;
        }
        case MESSANGE : {
            break;
        }
        case NEWGAME : {
            break;
        }
        case CONNECTGAME : {
            break;
        }
        case DISCONNECTGAME : {
            break;
        }
        case STARTGAME : {
            break;
        }
        case CANCELGAME : {
            break;
        }
        case FINISHGAME : {
            break;
        }
        case LISTALLGAME : {
            break;
        }
        case LISTALLNEWGAME : {
            break;
        }
        case TOTALSTATISTICS : {
            break;
        }
        case PLAYERSTATISTICS : {
            break;
        }
        case MOVE : {
            break;
        }
        default : {
        }

        }

        //������� ������ �� �������
        server->locker.lockForWrite();
        server->_mRequestQueries.removeFirst();
        server->locker.unlock();
        //��������� ������� �� �������
        server->locker.lockForRead();
        empty = server->_mRequestQueries.isEmpty();
        server->locker.unlock();
    } while (!empty);
}
