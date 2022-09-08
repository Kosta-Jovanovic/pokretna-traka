# pokretna-traka

# srpski

## opis projekta

Pokretna traka je projekat u kom se kutije razvrstavaju po boji i materijalu. Kada se projekat pokrene korisnik ce imati izbor da li ce da razvrstava kutije po boji ili po materijalu, izbor ce se korisniku dati klikom na dugme. Traka ce raditi tako sto ce odgurati kutiju do kraja trake gde ce se nasloniti na "Soil Moisture Sensor" koji ce izmeriti provodljivost materijala i po tome ce odrediti od kog matrijala je napravljena kutija a iznad trenutnog polozaja kutije stoji "TCS3200 Color Sensor" koji ce odrediti da li je kutija obojena u crnu ili belu. Nakon sto senzori odrede ptrebne informacije o kutiji kutija se vraca nekoliko santimetara unazad i zatim ga "sg90 servo motor" sklanja u levu ili desnu stranu u zavisnosti od osobina kutije koje su senzori odredili. Traka se krece tako sto stepper motor okrece valjke oko kojih je obmotana gumena traka.

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

## Autori projekta:

        Kosta Jovanović:
            Email: kostajovanovic06@gmail.com
            Github: https://github.com/Kosta-Jovanovic

        Dimitrije Marić:
            Email: dimitrijemmaric@gmail.com
            Github: /

# english

## project description

Conveyor belt is a project where boxes are sorted by color and material. When the project starts, the user will have the choice whether to sort the boxes by color or by material, the choice will be given to the user by clicking on the button. The tape will work by pushing the box to the end of the tape where it will rest on the "Soil Moisture Sensor" which will measure the conductivity of the material and by that will determine what material the box is made of and above the current position of the box is the "TCS3200 Color Sensor" which will determine whether the box is colored black or white. After the sensors have determined the necessary information about the box, the box moves back a few centimeters and then the "sg90 servo motor" moves it to the left or right depending on the properties of the box determined by the sensors. The tape moves as the stepper motor turns the rollers around which the rubber tape is wrapped.

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

## Authors of the project:

        Kosta Jovanovic:
            Email: kostajovanovic06@gmail.com
            Github: https://github.com/Kosta-Jovanovic

        Dimitrije Maric:
            Email: dimitrijemmaric@gmail.com
            Github: /


