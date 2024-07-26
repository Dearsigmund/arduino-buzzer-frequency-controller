int buzz = 5; // buzzer input pin
int pb = 3; // main push button's pin
int pbread;
int pbleft = 8; // Reduce frequency
int pbright = 10; // Increase frequency
int pbleftR, pbrightR; 
int freq = 1000; // initial frequency 1000Hz = 1KHz
int lastpbleft = 0; // last state of left push button
int lastpbright = 0; // last state of right push button

void setup() {
    // Set the pin modes
    pinMode(buzz, OUTPUT);
    pinMode(pb, INPUT);
    pinMode(pbleft, INPUT_PULLUP);
    pinMode(pbright, INPUT_PULLUP);
}

void loop() {
    pbread = digitalRead(pb);
    if (pbread == HIGH) {
        tone(buzz, freq);
    } else {
        noTone(buzz); // Turn off the buzzer
    }

    pbleftR = digitalRead(pbleft);
    pbrightR = digitalRead(pbright);

    // Check the right button for increasing the frequency
    if (pbrightR == LOW && lastpbright == HIGH && freq < 19950) {
        freq += 50;
        delay(50); // Debounce delay
    }
    lastpbright = pbrightR;

    // Check the left button for decreasing the frequency
    if (pbleftR == LOW && lastpbleft == HIGH && freq > 70) {
        freq -= 50;
        delay(50); // Debounce delay
    }
    lastpbleft = pbleftR;
}
