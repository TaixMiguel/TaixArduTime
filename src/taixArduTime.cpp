#include "taixArduTime.hpp"

/**
 * Constructor genérico
 */
TaixArduTime::TaixArduTime(int utc, bool horarioVerano) {
  init(utc, horarioVerano);
}

/**
 * Constructor para UTC+1 con cambio de hora en verano
 */
TaixArduTime::TaixArduTime() {
  init(1, true);
}

void TaixArduTime::init(int utc, bool horarioVerano) {
  gmtOffset_sec = horarioVerano ? 3600 : 0;
  daylightOffset_sec = utc * 60 * 60;
}

void TaixArduTime::updateTime() {
  if (WiFi.isConnected()) {
    struct tm timeinfo;
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    getLocalTime(&timeinfo);
  }
}