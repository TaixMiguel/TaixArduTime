#include "taixArduTime.hpp"

TaixArduTime::TaixArduTime() {
  daylightOffset_sec = 3600;
  gmtOffset_sec = 3600;
}

void TaixArduTime::updateTime() {
  if (WiFi.isConnected()) {
    struct tm timeinfo;
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    getLocalTime(&timeinfo);
  }
}