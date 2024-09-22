//переменные в виде массивоыв для создания одной буквы
int text_ok=0;
int a[] = {126, 144, 144, 144, 126};
int b[] = {254, 146, 146, 146, 108};
int c[] = {254, 130, 130, 130, 130};
int d[] = {254, 130, 130, 130, 124};
int e[] = {254, 146, 146, 146, 146};
int f[] = {254, 144, 144, 144, 128};
int g[] = {124, 130, 138, 138, 76};
int h[] = {254, 16, 16, 16, 254};
int i[] = {130, 250, 130};
int j[] = {12, 2, 2, 2, 252};
int k[] = {254, 16, 40, 68, 130};
int l[] = {254, 2, 2, 2, 2};
int m[] = {254, 64, 32, 64, 254};
int n[] = {254, 32, 16, 8, 254};
int o[] = {124, 130, 130, 130, 124};
int p[] = {254, 136, 136, 136, 112};
int q[] = {124, 130, 138, 134, 126};
int r[] = {254, 144, 152, 148, 98};
int s[] = {100, 146, 146, 146, 76};
int t[] = {128, 128, 254, 128, 128};
int u[] = {252, 2, 2, 2, 252};
int v[] = {248, 4, 2, 4, 248};
int w[] = {254, 4, 8, 4, 254};
int x[] = {198, 40, 16, 40, 198};
int y[] = {224, 16, 14, 16, 224};
int z[] = {134, 138, 146, 162, 194};
//доп симвлы
int eos[] = {0, 3, 2,0};
int excl[] = {0, 250, 0};
int ques[] = {64, 128, 138, 144, 96};
//задержка по времени
float delayTime=1;
//Переменные для POV-дисплея
unsigned long currentMMs, elapsed_loop_counter, previousMMs;
unsigned long counter_1, current_count;
//Переменные прерывания для подсчета скорости вращения
//Переменные для хранения предыдущего значения входного сигнала (if LOW or HIGH)
byte last_IN_state;               //Хранение предедущего состояния на цифровом порту 13
float one_rot_time=0;             //Хранение времени для прохождения полного оборотов
float time_per_deg=0;             //Хранение времени, на который тратиться для повората на один градус

void setup() {
  PCICR |= (1 << PCIE0);    //Включение сканирования PCMSK0
  PCMSK0 |= (1 << PCINT5);  //Включение состояния прерывания для порта 13
  //Подлючение и онфигурирование портов микроконтроллера
  DDRD |= B11111100;      //Порты от 2 до 7 включительно как выходы  
  DDRB |= B00011111;      //Порты от 8 до 12 включительно как выходы
  DDRB &= B11011111;      //Порт 13 как входной
  PORTD &= B00000011;     //Порты от 2 до 7 LOW
  PORTB &= B00000000;     //Порты от 8 до 13 LOW
}
void draw_a_line(int this_line){
int now_line;
now_line = this_line;
if (now_line>=128){PORTB |= B00100000;  now_line-=128;} else {PORTB &= B11011111;}
if (now_line>=64) {PORTD |= B01000000;  now_line-=64;}  else {PORTD &= B10111111;}
if (now_line>=32) {PORTD |= B10000000;  now_line-=32;}  else {PORTD &= B01111111;}
if (now_line>=16) {PORTB |= B00000001;  now_line-=16;}  else {PORTB &= B11111110;}
if (now_line>=8)  {PORTB |= B00000010;  now_line-=8;}   else {PORTB &= B11111101;}
if (now_line>=4)  {PORTB |= B00000100;  now_line-=4;}   else {PORTB &= B11111011;}
if (now_line>=2)  {PORTB |= B00001000;  now_line-=2;}   else {PORTB &= B11110111;}
if (now_line>=1)  {PORTB |= B00010000;  now_line-=1;}   else {PORTB &= B11101111;}
}
void displayChar(char cr, float line_delay){
if (cr == 'a'){for (int i = 0; i <5; i++){draw_a_line(a[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'b'){for (int i = 0; i <5; i++){draw_a_line(b[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'c'){for (int i = 0; i <5; i++){draw_a_line(c[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'd'){for (int i = 0; i <5; i++){draw_a_line(d[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'e'){for (int i = 0; i <5; i++){draw_a_line(e[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'f'){for (int i = 0; i <5; i++){draw_a_line(f[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'g'){for (int i = 0; i <5; i++){draw_a_line(g[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'h'){for (int i = 0; i <5; i++){draw_a_line(h[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'i'){for (int itr = 0; itr <3; itr++){draw_a_line(i[itr]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'j'){for (int i = 0; i <5; i++){draw_a_line(j[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'k'){for (int i = 0; i <5; i++){draw_a_line(k[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'l'){for (int i = 0; i <5; i++){draw_a_line(l[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'm'){for (int i = 0; i <5; i++){draw_a_line(m[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'n'){for (int i = 0; i <5; i++){draw_a_line(n[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'o'){for (int i = 0; i <5; i++){draw_a_line(o[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'p'){for (int i = 0; i <5; i++){draw_a_line(p[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'q'){for (int i = 0; i <5; i++){draw_a_line(q[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'r'){for (int i = 0; i <5; i++){draw_a_line(r[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 's'){for (int i = 0; i <5; i++){draw_a_line(s[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 't'){for (int i = 0; i <5; i++){draw_a_line(t[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'u'){for (int i = 0; i <5; i++){draw_a_line(u[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'v'){for (int i = 0; i <5; i++){draw_a_line(v[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'w'){for (int i = 0; i <5; i++){draw_a_line(w[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'x'){for (int i = 0; i <5; i++){draw_a_line(x[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'y'){for (int i = 0; i <5; i++){draw_a_line(y[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == 'z'){for (int i = 0; i <5; i++){draw_a_line(z[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == '!'){for (int i = 0; i <3; i++){draw_a_line(excl[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == '?'){for (int i = 0; i <5; i++){draw_a_line(ques[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
if (cr == '.'){for (int i = 0; i <4; i++){draw_a_line(eos[i]);delayMicroseconds(line_delay);}draw_a_line(0);}
delayMicroseconds(line_delay*2);
}
void displayString(char* s, float line_delay){
for (int i = 0; i<=strlen(s); i++){
displayChar(s[i],line_delay);
}
}
void loop() {
  currentMMs = micros();
  elapsed_loop_counter = currentMMs - previousMMs;
  delayTime = time_per_deg*3.5; // для выделения для каждой строки букв градусы, то есть расстоение между ними

  //Убедиться, что текст, который будет визуализироваться будет по середине
  if((elapsed_loop_counter >=  time_per_deg*(216)) && (elapsed_loop_counter <  time_per_deg*(217)) &&  text_ok)
  { 
  displayString("d",delayTime);
  delayMicroseconds(delayTime*10);
  text_ok=0;
  }
}
ISR(PCINT0_vect){
//Берётся текущее значение счета в микросекундах, используя функцию micros()
  
  current_count = micros();
  //Канал 1
  if(PINB & B00100000){                              //Создание логического И для регистра состояния, проверка, что порт 8 HIGH?
    if(last_IN_state == 0){                         //Если последнее состояние было 0, то  есть изменение состояния
      last_IN_state = 1;                            //Хрение текущего состояния в последнем состоянии для следующего цикла
      counter_1 = current_count;                     //Установка counter_1 на текущее значение.
    }
  }
  else if(last_IN_state == 1){                      //Если вывод 8 низкий, а последнее состояние было ВЫСОКИМ, то происходит изменение состояния   
    last_IN_state = 0;                               //Хрение текущего состояния в последнем состоянии для следующего цикла
    one_rot_time = current_count - counter_1;   //Мы учитываем разницу во времени. Канал 1 это current_time - timer_1.
    time_per_deg = one_rot_time/360.0;
    previousMMs = micros();
    text_ok=1;
   }
}
