#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


int m11=1;
int m12=6;
int m21=8;
int m22=14;

int i1=m11;
int i2=m22;

int h1=-1;
int h2=-1;
int uph1,uph2;
int m = -1;

int nrhearts1=0;
int nrhearts2=0;

bool up1=false;
bool up2=false;
int valIntermediar;
int valIntermediar1;

bool ok1=false;
bool ok2=false;
bool okb1=false;
bool okb2=false;
int b1;
int b2;
int upb1;
int upb2;
bool isdead1=false;
bool isdead2=false;

bool ok=true;

// Masca pentru primul caracter
byte man1[8] = {
B01110,
B00100,
B01110,
B10101,
B00100,
B01010,
B10001,
};

// Masca pentru al doilea caracter
byte man2[8] = {
B01110,
B00100,
B01110,
B10101,
B00100,
B01010,
B10001,
};
// Masca pentru line
byte line[8] = {
B01110,
B01110,
B01110,
B01110,
B01110,
B01110,
B01110,
};

//  Masca pentru heart

byte heart[8] = {
B00000,
B01010,
B11111,
B11111,
B01110,
B00100,
B00000,
};

byte bomb[8] = {
B00000,
B00100,
B01110,
B11111,
B01110,
B00100,
B00000,
};


void setup() { 

 analogReference(DEFAULT); 
 pinMode(A1, INPUT); 
 digitalWrite(A1, HIGH);
 pinMode(A2, INPUT); 
 digitalWrite(A2, HIGH);

 lcd.begin(16, 2);
 // cele două caractere sunt stocate în CGROM, zona utilizator, pozitiile 0 şi 1
lcd.createChar(0, man1);
lcd.createChar(1, man2);
lcd.createChar(2,line);
lcd.createChar(3,heart);
lcd.createChar(4,bomb);
// Afişare prima linie

lcd.setCursor(i1, 1);
lcd.write(1); 
lcd.setCursor(i2,1);
lcd.write(byte(0));
lcd.setCursor(7, 0);
lcd.write(2);
lcd.setCursor(7, 1);
lcd.write(2); 

lcd.setCursor(0,1);
lcd.print("A");
lcd.setCursor(15,1);
lcd.print("B");

lcd.setCursor(0,0);
lcd.print(0);
lcd.setCursor(15,0);
lcd.print(0);





valIntermediar=1000;
valIntermediar1=1000;
}

void loop()
{
  if(ok)
  {
lcd.setCursor(0,1);
lcd.print("A");
lcd.setCursor(15,1);
lcd.print("B");

 int val = analogRead(A1); 
 val = getTasta(val);
int val1 = analogRead(A2); 
 val1 = getTasta(val1);

 unsigned long milis = millis();
 //bool ok=false;

  if(m!=milis/1000 && milis<25000)
  {
  //ok=true;
  m = milis/1000;
  if(m%3==0)
  {
    ok1=true;
    ok2=true;
    if(h1>=0 && h1!=i1)
    {
       lcd.setCursor(h1,uph1);
       lcd.print(" ");
    }
    h1 = random(1,7);
    uph1=random(2);
    while(h1==i1)
      h1 = random(1,7);
    lcd.setCursor(h1,uph1);
    lcd.write(3);
 
    if(h2>=0 && h2!=i2)
    {
       lcd.setCursor(h2,uph2);
       lcd.print(" ");
    }
    h2 = random(8,15);
    uph2=random(2);
    while(h2==i2)
      h2 = random(8,15);
    lcd.setCursor(h2,uph2);
    lcd.write(3);
  }
}

else if(milis>28000 && milis<33000){

  //lcd.setCursor(5,0);
 // lcd.print("Start");
  lcd.setCursor(0,1);
lcd.print("A");
lcd.setCursor(15,1);
lcd.print("B");
  if(h1!=i1){
    lcd.setCursor(h1,uph1);
    lcd.print(" ");
  }
  if(h2!=i2){
    lcd.setCursor(h2,uph2);
    lcd.print(" ");
  }

  if(up1)
     lcd.setCursor(i1,0);
   else
      lcd.setCursor(i1,1);
   lcd.print(" ");
   if(up2)
      lcd.setCursor(i2,0);
   else
       lcd.setCursor(i2,1);
    lcd.print(" ");

    lcd.setCursor(1,1);
    lcd.write(1);
    lcd.setCursor(14,1);
    lcd.write(1);

    lcd.setCursor(0,0);
    lcd.print(nrhearts1);
    lcd.setCursor(15,0);
    lcd.print(nrhearts2);

    i1=1;
    up1=false;
    i2=14;
    up2=false;
}
else if(milis>=33000 && milis<38000)
{
  lcd.setCursor(5,0);
  lcd.print("Start");
  lcd.setCursor(0,1);
lcd.print("A");
lcd.setCursor(15,1);
lcd.print("B");
}
else if(milis>=38000 && milis<39000)
{
  lcd.setCursor(5,0);
  lcd.print(" ");
  lcd.setCursor(6,0);
  lcd.print(" ");
  lcd.setCursor(8,0);
  lcd.print(" ");
  lcd.setCursor(9,0);
  lcd.print(" ");
  lcd.setCursor(7,0);
  lcd.write(2);
}
else if(milis>=39000)
{
  lcd.setCursor(7, 0);
lcd.write(2);
lcd.setCursor(7, 1);
lcd.write(2); 

  m = milis/100;
  if(m%5==0)
  {
  if(okb1)
    {
      lcd.setCursor(b1,upb1);
      lcd.print(" ");
      if(i2==b1)
      {
        if((up2==true && upb1==0) ||(up2==false && upb1==1))
        isdead2=true;
      }
        
      b1++;
      if(b1>14)
        okb1=false;
        else 
        {
          lcd.setCursor(b1,upb1);
          lcd.write(4);
          if(b1==7)
        {
          lcd.setCursor(b1,upb1);
          lcd.write(2);
        }
        }
    }
  if(okb2)
  {
    lcd.setCursor(b2,upb2);
     lcd.print(" ");
     if(i1==b2 )
     {
      if((up1==true && upb2==0) ||(up1==false && upb2==1))
        isdead1=true;
     }
        
      b2--;
      if(b2<1)
        okb2=false;
        else 
        {lcd.setCursor(b2,upb2);
          lcd.write(4);
          if(b2==7)
        {
          lcd.setCursor(b2,upb2);
          lcd.write(2);
        }
        }
  }

    lcd.setCursor(0,0);
    lcd.print(nrhearts1);
    lcd.setCursor(15,0);
    lcd.print(nrhearts2);
  }
  if(nrhearts1==0 && nrhearts2==0 && !okb1 && !okb2)
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Nobody wins :(");
  ok=false;
}



 
}

if(i1==h1 && ((up1==true && uph1==0) || (up1==false && uph1==1)) && milis<35000 && ok1)
    
    {
      nrhearts1++;
      lcd.setCursor(0,0);
    lcd.print(nrhearts1);
      ok1=false;
    }

if(i2==h2 && ((up2==true && uph2==0) || (up2==false && uph2==1)) && milis<35000 && ok2)
  {
    nrhearts2++;
    lcd.setCursor(15,0);
    lcd.print(nrhearts2);
    ok2=false;
  }

if(isdead1)
{
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("B wins!");
  ok=false;
}


if(isdead2)
{
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("A wins!");
  ok=false;
}


  
    
 if(valIntermediar != val)
{
  switch(val)
  {
    case 5:
            if(okb1==false && nrhearts1>0)
            {
              nrhearts1--;
              okb1=true;
              b1=i1+1;
              if(up1)
                upb1=0;
                else
                upb1=1;
            }
             break;
    case 6:
          if(!isdead1)
          {
            if(i1<6)
            {
              if(up1)
                lcd.setCursor(i1,0);
              else
                lcd.setCursor(i1,1);
                
              lcd.print(" ");
              i1++;
              if(up1)
                lcd.setCursor(i1,0);
              else
                lcd.setCursor(i1,1);
              lcd.write(1);
             }
          }
             break;
     case 4:
     if(!isdead1)
     {
            if(i1>1)
            {
                if(up1)
                  lcd.setCursor(i1,0);
                else
                  lcd.setCursor(i1,1);
                
                lcd.print(" ");
                i1--;
                if(up1)
                lcd.setCursor(i1,0);
              else
                lcd.setCursor(i1,1);
                lcd.write(1);
             }
     }
             break;
     case 2:
     if(!isdead1)
     {
            if(!up1)
            {
                lcd.setCursor(i1,1);
                lcd.print(" ");
               
                lcd.setCursor(i1,0);
                lcd.write(1);
                up1=true;
             }
     }
             break;
     case 8:
     if(!isdead1)
     {
            if(up1)
            {
                lcd.setCursor(i1,0);
                lcd.print(" ");
               
                lcd.setCursor(i1,1);
                lcd.write(1);
                up1=false;
             }
     }
             break;
  }

    valIntermediar = val;
}

if(valIntermediar1 != val1)
{
  switch(val1)
  {
    case 5:
            if(okb2==false && nrhearts2>0)
            {
              nrhearts2--;
              okb2=true;
              b2=i2-1;
              if(up2)
                upb2=0;
                else
                upb2=1;
            }
             break;
    case 6:
    if(!isdead2)
    {
            if(i2<14)
            {
              if(up2)
                lcd.setCursor(i2,0);
              else
                lcd.setCursor(i2,1);
                
              lcd.print(" ");
              i2++;
              if(up2)
                lcd.setCursor(i2,0);
              else
                lcd.setCursor(i2,1);
              lcd.write(1);
             }
    }
             break;
     case 4:
     if(!isdead2)
     {
            if(i2>8)
            {
                if(up2)
                  lcd.setCursor(i2,0);
                else
                  lcd.setCursor(i2,1);
                
                lcd.print(" ");
                i2--;
                if(up2)
                lcd.setCursor(i2,0);
              else
                lcd.setCursor(i2,1);
                lcd.write(1);
             }
     }
             break;
     case 2:
     if(!isdead2)
     {
            if(!up2)
            {
                lcd.setCursor(i2,1);
                lcd.print(" ");
               
                lcd.setCursor(i2,0);
                lcd.write(1);
                up2=true;
             }
     }
             break;
     case 8:
     if(!isdead2)
     {
            if(up2)
            {
                lcd.setCursor(i2,0);
                lcd.print(" ");
               
                lcd.setCursor(i2,1);
                lcd.write(1);
                up2=false;
             }
     }
             break;
  }

    valIntermediar1 = val1;
}
delay(100);

  }
} 

int getTasta(int val)
{
  if(val > 50 && val < 80)return 12;
  else if(val > 90 && val < 120) return 11; // key 11 is pressed
  else if(val > 120 && val < 160) return 10; // and so on
  else if(val > 160 && val < 200) return 9;
  else if(val > 200 && val < 240)return 8;
  else if(val > 240 && val < 290) return 7;
  else if(val > 290 && val < 320) return 6;
  else if(val > 320 && val < 370) return 5;
  else if(val > 370 && val < 410) return 4;
  else if(val > 410 && val < 450) return 3;
  else if(val > 450 && val < 490) return 2;
  else if(val > 490 && val < 530) return 1;
  else return 0; 
}
