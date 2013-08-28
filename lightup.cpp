#include "mbed.h"              
 
Serial pc(USBTX, USBRX); // tx, rx
PwmOut led(LED1);
 
float brightness = 0.0;
 
int main() {
    pc.printf("Use u and d to control led brightness \n");
    while(1) {
       char c = pc.getc();
       if ((c == 'u') && (brightness < 0.5)) {
            brightness += 0.1;
            led = brightness;
       }
       if ((c == 'd') && (brightness > 0.0)) {
            brightness -= 0.1;
            led = brightness;
       }
       if ((c != 'd') && (c != 'u')){
            pc.printf("Type 'u' or 'd' \n");
       }     
    }
}