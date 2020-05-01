#include "Arduino.h"
#include "valve_manager.h"

ValveManager::ValveManager() : valveToPin({D1,D2,D3,D4,D5,D6,D7,D8}) {
  for (int i = 0; i < MAX_VALVES; i++) {
    valves[i] = '0';
  }
}

void ValveManager::InitializePins() {
  for (int i = 0; i < MAX_VALVES; i++) {
    pinMode(valveToPin[i], OUTPUT);
    digitalWrite(valveToPin[i], LOW);
  }
}

String ValveManager::ShowCurrentState() {
  return String(this->valves);
}

bool ValveManager::TurnOnValve(int index) {
  if (index > 0 && index < MAX_VALVES) {
    valves[index] = '1';
    digitalWrite(valveToPin[index], HIGH);

    return true;
  }
  else {
    return false;
  }
}

bool ValveManager::TurnOffValve(int index) {
  if (index > 0 && index < MAX_VALVES) {
    valves[index] = '0';   
    digitalWrite(valveToPin[index], LOW);

    return true;
  }
  else {
    return false;
  }
}
