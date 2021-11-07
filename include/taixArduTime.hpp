#ifndef taixArduTime_hpp
#define taixArduTime_hpp

#include "Arduino.h"
#include "time.h"
#include <WiFi.h>

/**
 * @author TaixMiguel
 */
class TaixArduTime {

  const char* ntpServer = "pool.ntp.org";

  public:
    TaixArduTime(int utc, bool horarioVerano);
    TaixArduTime();

    void updateTime();

  private:
    long  gmtOffset_sec;
    int   daylightOffset_sec;

    void init(int utc, bool horarioVerano);
};

#endif