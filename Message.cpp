#include "Message.h"

int Message::msgCounter = 0;


Message::Message()
    : messageID(++msgCounter), senderID(0), receiverID(0),
      content(""), timestamp(""), isRead(false) {}


Message::Message(int sid, int rid, const string& msg, const string& ts)
    : messageID(++msgCounter), senderID(sid), receiverID(rid),
      content(msg), timestamp(ts), isRead(false) {}
Message::Message(const Message& m)
    : messageID(m.messageID), senderID(m.senderID), receiverID(m.receiverID),
      content(m.content), timestamp(m.timestamp), isRead(m.isRead) {}


int    Message::getMessageID()  const { return messageID; }
int    Message::getSenderID()   const { return senderID; }
int    Message::getReceiverID() const { return receiverID; }
string Message::getContent()    const { return content; }
string Message::getTimestamp()  const { return timestamp; }
bool   Message::getIsRead()     const { return isRead; }


void Message::setContent(const string& c) { content = c; }
void Message::markAsRead()                { isRead = true; }


void Message::display() const {
    cout << "[MSG #" << messageID << "] From:" << senderID
         << " To:" << receiverID << " | " << timestamp << "\n"
         << "  \"" << content << "\" [" << (isRead ? "Read" : "Unread") << "]\n";
}

bool Message::isFromSender(int sid) const {
    return senderID == sid;
}

void Message::reply(int newSenderID, const string& replyContent, const string& ts) {
    cout << "[Message] Reply sent from User #" << newSenderID
         << ": " << replyContent << "\n";
}

int Message::getMsgCounter() { return msgCounter; }
