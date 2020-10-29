#define LOADING_COMPLETE 150120016
#include<iostream>

//Bu sınıf olası arkaplan işlemlerinde (diskten sahne yüklemek gibi) bilgi iletmek için
class MessageHandler {
    public:
        MessageHandler();  
        ~MessageHandler();
        int getMessage();
        void sendMessage(int msg);
    private:
        int lastMessage;
};