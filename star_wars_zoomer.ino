constexpr int ZOOOMER_PIN = 3;
constexpr int BTN_PIN = 4;
constexpr int COUNT_NOTES = 39;

int frequences[COUNT_NOTES] = {
  392, 392, 392, 311, 466, 392, 311, 466, 392,
  587, 587, 587, 622, 466, 369, 311, 466, 392,
  784, 392, 392, 784, 739, 698, 659, 622, 659,
  415, 554, 523, 493, 466, 440, 466,
  311, 369, 311, 466, 392
};
//длительность нот
int durations[COUNT_NOTES] = {
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 250, 100, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 750
};

void setup() {
  pinMode(ZOOOMER_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  bool btnState = !digitalRead(BTN_PIN);

  if(btnState) {
    for (int i = 0; i <= COUNT_NOTES; i++  ) { // Цикл от 0 до количества нот
      tone(ZOOOMER_PIN, frequences[i], durations[i] * 2);
      delay(durations[i] * 2);  // Дауза для заданой ноты
    }
  }
}

