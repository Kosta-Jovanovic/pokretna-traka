# pokretna-traka

# srpski

## opis projekta

Pokretna traka je projekat u kom se kutije razvrstavaju po boji i materijalu. Kada se projekat pokrene korisnik će imati izbor da li će da razvrstava kutije po boji ili po materijalu, izbor će se korisniku daje klikom na dugme. Traka će raditi tako sto će odgurati kutiju do kraja trake gde će se nasloniti na "Soil Moisture Sensor". "Soil Moisture Sensor" će izmeriti provodljivost materijala i po tome će odrediti od kog matrijala je napravljena kutija. iznad polozaja kutije u tom trenutku stoji "TCS3200 Color Sensor" koji će odrediti da li je kutija obojena u crnu ili belu boju. Nakon sto senzori odrede potrebne informacije o kutiji, kutija se vraća nekoliko cantimetara unazad i zatim ga "sg90 servo motor" sklanja u levu ili desnu stranu u zavisnosti od osobina kutije koje su senzori odredili. Traka se kreće tako što stepper motor okrece valjke oko kojih je obmotana gumena traka.

## hardver 

Od hardvera su korišćeni sledeći elektronski delovi: - Sg90 servo motor
                                                     - TCS3200 Color Sensor
                                                     - Soil Moisture Sensor
                                                     
Od hardvera su korišćeni sledeći delovi: - 3d printovani delovi (stl fajlovi u projektu)
                                         - Za sva spajanja su korišćeni m4 šrafovi
                                         
## softver 

Od softvera smo koristili Fusion 360 za modelovanje delova za štampu, Arduino ide za programirnje arduina, Prusa slicer 242 za slajsovanje 3d modela.

## zaključci 

Nakon dosta sati rada sa treakom zakljucili smo da bi trebala da se napravi bolja veza izmedju motora, šrafa i valjka zato što nakon zatezanja trake veza se pokida i motor vrti u mestu a valjak samo stoji

## planovi projekta

Plan projekta je bio da se napravi sistem koji je sposoban da razvrstava kocke po razicitim osobinama kocke (boja, materijal)

## ideje za unapredjivane projekta

Unapredjivanje projekta bi moglo da se izvede uklanjanjem sg90 servo motora koji sklanja kutije u stranu i dodavanja robotske ruke koja bi imala opciju da razvrstava kutije na vise od dve vrste u isto vreme. Druga ideja je unapredjivane softvera i senzora kako bi mogao da razvrtva vise kutija.

## Kod porjekta

        #include <Servo.h>

        #define S0 2
        #define S1 3
        #define S2 4
        #define S3 5
        #define sensorOut 6
        #define servoPin 9

        Servo myservo;

        int redFrequency = 0;
        int greenFrequency = 0;
        int blueFrequency = 0;

        int sensorPin = A0; 
        int sensorValue;  

        int angle = 0;

        //1 color, 0 material
        int SortType = 1;

        void Spin()
        {
          //Vrati traku u nazad
           Serial.println("T");



  
          if(SortType == 1)
         {
    if(redFrequency < 30 and greenFrequency < 30 and blueFrequency < 30) //White cube
    {
      myservo.write(180);
      Serial.println("Here");
      delay(1000);
      myservo.write(-180);
    }
    else //Black
    {
      myservo.write(-180);
      Serial.println("noup    ");
      delay(1000);
      myservo.write(180);
    }
          }
         else
          {
    if(sensorValue <= 100) //Metal
    {
      myservo.write(180);
      delay(1000);
      myservo.write(-180);
    }
    else //Plastic
    {
      myservo.write(-180);
      delay(1000);
      myservo.write(180);
    }
         }
         delay(5000);
        }


        void setup() {
         pinMode(S0, OUTPUT);
         pinMode(S1, OUTPUT);
         pinMode(S2, OUTPUT);
         pinMode(S3, OUTPUT);
  
          pinMode(sensorOut, INPUT);
  
          digitalWrite(S0,HIGH);
          digitalWrite(S1,LOW);

          myservo.attach(servoPin);
         myservo.write(0);
  
          Serial.begin(9600);
        }
        void loop() {
         // RED
         digitalWrite(S2,LOW);
         digitalWrite(S3,LOW);
         redFrequency = pulseIn(sensorOut, LOW);
  
         // GREEN
         digitalWrite(S2,HIGH);
          digitalWrite(S3,HIGH);
         greenFrequency = pulseIn(sensorOut, LOW);
 
         // BLUE
         digitalWrite(S2,LOW);
       digitalWrite(S3,HIGH);
        blueFrequency = pulseIn(sensorOut, LOW);

         // SOIL
         sensorValue = analogRead(sensorPin); 



         Serial.println(sensorValue);
         Serial.println(redFrequency);
         Serial.println(greenFrequency);
         Serial.println(blueFrequency);

         delay(1000);
          if(redFrequency < 30 and redFrequency < 30 and blueFrequency < 30)
        {
    Spin();
         }
      if(redFrequency > 30 and redFrequency > 30 and blueFrequency > 30 and redFrequency < 60 and redFrequency < 60 and blueFrequency < 60)
      {
    Spin();
       }
        //140   210
        //200   240
        //200   200 
        }

## Autori projekta:

        Kosta Jovanović:
            Email: kostajovanovic06@gmail.com
            Github: https://github.com/Kosta-Jovanovic

        Dimitrije Marić:
            Email: dimitrijemmaric@gmail.com
            Github: https://github.com/DimitrijeMMaric

# english

## project description

Conveyor belt is a project where boxes are sorted by color and material. When the project is started, the user will have the choice whether to sort the boxes by color or by material, the choice will be given to the user by clicking on the button. The strip will work by pushing the box to the end of the strip where it will rest against the "Soil Moisture Sensor". "Soil Moisture Sensor" will measure the conductivity of the material and will determine what material the box is made of. above the position of the box at that moment is "TCS3200 Color Sensor" which will determine whether the box is colored black or white. After the sensors determine the necessary information about the box, the box moves back a few centimeters and then the "sg90 servo motor" moves it to the left or right depending on the properties of the box determined by the sensors. The tape moves by the stepper motor turning the rollers around which the rubber tape is wrapped.

## hardware

From the hardware, the following electronic parts were used: - Sg90 servo motor
                                                             - TCS3200 Color Sensor
                                                             - Soil Moisture Sensor
                                                     
The following hardware parts were used: - 3d printed parts (stl files in the project)
                                        - M4 screws were used for all connections
                                         
## software

From the software, we used Fusion 360 for modeling parts for printing, Arduino ide for programming arduino, Prusa slicer 242 for slicing 3d models.

## conclusions

After many hours of working with the track, we concluded that a better connection between the motor, the screw and the roller should be made, because after tightening the tape, the connection breaks and the motor spins in place and the roller just stands still.

## project plans

The project plan was to create a system capable of sorting cubes according to different properties of the cube (color, material)

## ideas for improved projects

Improvements to the project could be made by removing the sg90 servo motor that moves the boxes to the side and adding a robotic arm that would have the option to sort the boxes into more than two types at the same time. Another idea is to improve the software and sensors so that it can sort more than boxes.

## Project code

        #include <Servo.h>

        #define S0 2
        #define S1 3
        #define S2 4
        #define S3 5
        #define sensorOut 6
        #define servoPin 9

        Servo myservo;

        int redFrequency = 0;
        int greenFrequency = 0;
        int blueFrequency = 0;

        int sensorPin = A0; 
        int sensorValue;  

        int angle = 0;

        //1 color, 0 material
        int SortType = 1;

        void Spin()
        {
          //Vrati traku u nazad
           Serial.println("T");



  
          if(SortType == 1)
         {
    if(redFrequency < 30 and greenFrequency < 30 and blueFrequency < 30) //White cube
    {
      myservo.write(180);
      Serial.println("Here");
      delay(1000);
      myservo.write(-180);
    }
    else //Black
    {
      myservo.write(-180);
      Serial.println("noup    ");
      delay(1000);
      myservo.write(180);
    }
          }
         else
          {
    if(sensorValue <= 100) //Metal
    {
      myservo.write(180);
      delay(1000);
      myservo.write(-180);
    }
    else //Plastic
    {
      myservo.write(-180);
      delay(1000);
      myservo.write(180);
    }
         }
         delay(5000);
        }


        void setup() {
         pinMode(S0, OUTPUT);
         pinMode(S1, OUTPUT);
         pinMode(S2, OUTPUT);
         pinMode(S3, OUTPUT);
  
          pinMode(sensorOut, INPUT);
  
          digitalWrite(S0,HIGH);
          digitalWrite(S1,LOW);

          myservo.attach(servoPin);
         myservo.write(0);
  
          Serial.begin(9600);
        }
        void loop() {
         // RED
         digitalWrite(S2,LOW);
         digitalWrite(S3,LOW);
         redFrequency = pulseIn(sensorOut, LOW);
  
         // GREEN
         digitalWrite(S2,HIGH);
          digitalWrite(S3,HIGH);
         greenFrequency = pulseIn(sensorOut, LOW);
 
         // BLUE
         digitalWrite(S2,LOW);
       digitalWrite(S3,HIGH);
        blueFrequency = pulseIn(sensorOut, LOW);

         // SOIL
         sensorValue = analogRead(sensorPin); 



         Serial.println(sensorValue);
         Serial.println(redFrequency);
         Serial.println(greenFrequency);
         Serial.println(blueFrequency);

         delay(1000);
          if(redFrequency < 30 and redFrequency < 30 and blueFrequency < 30)
        {
    Spin();
         }
      if(redFrequency > 30 and redFrequency > 30 and blueFrequency > 30 and redFrequency < 60 and redFrequency < 60 and blueFrequency < 60)
      {
    Spin();
       }
        //140   210
        //200   240
        //200   200 
        }

## Authors of the project:

        Kosta Jovanovic:
            Email: kostajovanovic06@gmail.com
            Github: https://github.com/Kosta-Jovanovic

        Dimitrije Maric:
            Email: dimitrijemmaric@gmail.com
            Github: https://github.com/DimitrijeMMaric


