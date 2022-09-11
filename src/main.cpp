#include <Arduino.h>
#include <sent_recv.h>
#include <global.h>

void setup()
{
  Serial.begin(115200);
  // put your setup code here, to run once:
  sent_recv_init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  recv_serial();
}