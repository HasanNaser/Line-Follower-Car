#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

decode_results results;
int RECV_PIN =11;//pin 11 of arduino to data pin of ir receiver
IRrecv irrecv(RECV_PIN);


int sagteker=9;
int solteker=10;

int sagteker2=5;
int solteker2=6;

void setup()
{ 
         Serial.begin(9600);
  irrecv.enableIRIn();     
 
 
} 
 
  
void sagadon(int sag){
  int y=analogRead(A1);
             if(sag<150&&y>150){
                analogWrite(sagteker,80);
                analogWrite(solteker,0);
                delay(300);    
             
              }
                
              int x=analogRead(A0);
               
               if(x>150 ){
                 analogWrite(sagteker,0); 
                  yuru();
                 }
}


void soladon(int sol){
         int y=analogRead(A1);
            if(sol<150&&y>150){
                analogWrite(solteker,75);
                analogWrite(sagteker,0);
                delay(300);
                
              
                }
                 
                  int x=analogRead(A2);
                  if(x>150 ){
                   analogWrite(solteker,0); 
                   yuru();
                     
                   }  
} 

int tim;
void yuru(){
                 int orta=analogRead(A1);
                  
                if(orta<150   ){
                   int sagX=analogRead(A0);
                  int solX=analogRead(A2);
                  if(sagX<150){
                    sagadon(sagX); 
                  }
                  if(solX<150){
                    soladon(solX); 
                  }
                  analogWrite(solteker,80);
                  analogWrite(sagteker,85);
                 
                                    
                  
                }
                else
                {
                analogWrite(solteker,50);
                }
               
               
                 
              
                 
}

int mode=0;
void loop()
{   
  if (irrecv.decode(&results))
    {
     Serial.println(results.value);
     irrecv.resume(); // Receive the next value
    }
  
  if(results.value== 16726215  )
    {
      Serial.println("okudu");
      mode=1;
    }
  else if(results.value==16756815 )
    {
      mode=2;
    }
   else if(results.value==16738455 )
    {
      mode=0;
    }
if(mode==0){
  analogWrite(sagteker,0);
           analogWrite(solteker,0);
           analogWrite(sagteker2,0);
           analogWrite(solteker2,0);
}
if(mode==1){
      if(results.value==16734885)
        {
           analogWrite(solteker,150);
              analogWrite(sagteker,0);
               analogWrite(sagteker2,0);
           analogWrite(solteker2,0);
           delay(750);
        }
        
       if(results.value==16716015)
        {
           analogWrite(sagteker,150);
           analogWrite(solteker,0);
            analogWrite(sagteker2,0);
           analogWrite(solteker2,0);
           delay(750);
        }
        if(results.value==16718055     )
        {
           analogWrite(sagteker,160);
           analogWrite(solteker,160);
            analogWrite(sagteker2,0);
           analogWrite(solteker2,0);
           delay(750);
        }
        
        if(results.value==16730805)
        {
          analogWrite(sagteker ,0);
           analogWrite(solteker ,0);
           analogWrite(sagteker2,135);
           analogWrite(solteker2,135);
           delay(750);
        }
        else 
       { analogWrite(sagteker,0);
           analogWrite(solteker,0);
            analogWrite(sagteker2,0);
           analogWrite(solteker2,0);
       }
  }

  if(mode==2){
    
              int sag=analogRead(A0);
              int sol=analogRead(A2); 
                    sagadon(sol);
                    soladon(sag);  
              int orta=analogRead(A1);   
                     Serial.print (sag);
                     Serial.print (" ");
                     Serial.print (orta);
                     Serial.print (" ");
                     Serial.println(sol);
                    
             
  }

              
             
               
                
              
    }
              
              
              
              
               
           

