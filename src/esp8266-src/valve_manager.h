#ifndef _VALVE_MANAGER_H_
#define _VALVE_MANAGER_H_

#define MAX_VALVES 8

// let's define pins, which are used in ESP8266
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15

class ValveManager {
  private:
    char valves[MAX_VALVES];
    int valveToPin[MAX_VALVES];

  public:
    ValveManager();
    void InitializePins();
    String ShowCurrentState();
    bool TurnOnValve(int index);
    bool TurnOffValve(int index);
};

#endif // _VALVE_MANAGER_H_
