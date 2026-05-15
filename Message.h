#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
using namespace std;

// ═══════════════════════════════════════════════════════════════
//  CLASS 3: Message
//  • AGGREGATION with User: 
//  • static msgCounter:
// ═══════════════════════════════════════════════════════════════
class Message {
private:
    int    messageID;
    int    senderID;
    int    receiverID;
    string content;
    string timestamp;
    bool   isRead;

    static int msgCounter;  

public:
   
    Message();

   
    Message(int sid, int rid, const string& msg, const string& ts);

   
    Message(const Message& m);

    
    int    getMessageID()  const;
    int    getSenderID()   const;
    int    getReceiverID() const;
    string getContent()    const;
    string getTimestamp()  const;
    bool   getIsRead()     const;

    
    void setContent(const string& c);
    void markAsRead();

  
    void display()                                              const;
    bool isFromSender(int sid)                                  const;
    void reply(int newSenderID, const string& replyContent,
               const string& ts);

    static int getMsgCounter();
};

#endif
