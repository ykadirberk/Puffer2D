#include "MessageHandler.h"

MessageHandler::MessageHandler() {
    lastMessage = 0;
}

MessageHandler::~MessageHandler() {

}

int MessageHandler::getMessage() {
    return lastMessage;
}

void MessageHandler::sendMessage(int msg) {
    lastMessage = msg;
}