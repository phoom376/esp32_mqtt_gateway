#include <sent_recv.h>

// HardwareSerial RECV(2);
// HardwareSerial SENT(1);
HardwareSerial SENT_RECV(1);

typedef struct recv_struct
{
    char payload[4096];
} recv_struct;

recv_struct recv_message;

void sent_recv_init()
{
    // SENT.begin(9600, SERIAL_8N1, SENT_TX_PIN, SENT_RX_PIN);

    // RECV.begin(115200, SERIAL_8N1, RECV_RX_PIN, RECV_TX_PIN);

    SENT_RECV.begin(115200, SERIAL_8N1, SENT_RECV_RX_PIN, SENT_RECV_TX_PIN);
}

void sent_serial(char *_payload)
{

    SENT_RECV.print(_payload);
    Serial.print("SENT SERIAL :");
    Serial.println(_payload);
    SENT_RECV.flush();
    Serial.flush();
}

void recv_serial()
{

    while (SENT_RECV.available())
    {
        // strcpy(RECV_MESSAGE, RECV.readString().c_str());

        Serial.print("serial Recv -> :");
        Serial.println(SENT_RECV.readStringUntil('\n'));
    }
}