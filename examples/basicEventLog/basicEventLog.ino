#include "flprogEventLog.h"

FlprogEventLog logData(5, 10, 6);

void setup() {
  logData.setTimeField(0);
  logData.setByteField(1);
  logData.setIntegerField(2);
  logData.setBooleanField(3);
  logData.setLongField(4);
  logData.setUnLongField(5);
  logData.setEventDescription(0, "Test");

}

void loop() {
  logData.addNewEvent(2);
  logData.setLastBooleanValue(3, false);
  logData.setLastByteValue(1, 25);
  logData.setLastIntValue(2, 25);
  logData.setLastLongValue(4, 25);
  logData.setLastUnLongValue(5, 25);
  logData.setLastTimeValue(0, 25);

}