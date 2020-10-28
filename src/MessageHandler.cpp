#include "MessageHandler.h"

MessageHandler::MessageHandler() {

}

MessageHandler::~MessageHandler() {

}

int MessageHandler::getMessage() {
    return lastMessage;
}

void MessageHandler::sendMessage(int msg) {
    lastMessage = msg;
}