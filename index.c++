//Primeiro passo: Variáveis

const int PinBuzzer = 6;
const int PinLed = 10;
const int PinLdr = 0;

int ValorLDR = 0; //Valor que será lido
const int freq = 5;

void setup()
{
  pinMode(PinLed, OUTPUT);
  pinMode(PinBuzzer, OUTPUT);
}


void loop()
{
  //Vai ler o valor do LDR
  ValorLDR = analogRead(PinLdr);
   // criei este sistema
  //Que com determinada luminosidade(600 pode não ser o valor correto)
  //(Pânico) ele ative o alarme
  //Se for muito alta ele para pois é aceitável 
  if(ValorLDR <= 600){
   ligarAlarme();
  }
  else{
   desligarAlarme();
  }
}

void ligarAlarme() {
  tone(PinBuzzer, 700);
  digitalWrite(PinLed, HIGH);
  delay(500);
  digitalWrite(PinLed, LOW);
  delay(500);
  desligarAlarme();
  
}

void desligarAlarme(){
  noTone(PinBuzzer);
  digitalWrite(PinLed, LOW);  
}