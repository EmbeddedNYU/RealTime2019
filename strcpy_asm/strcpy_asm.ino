
  #include <stdlib.h>
extern "C" char* copy( char str[] ) ; 

void setup() {
Serial.begin(9600);
    char str[] = "Professor Campisi has a Drone" ;
   char* result;
   result = copy( str ) ; 

  while(1){
  Serial.println(result);

  }
    

}

void loop() {
   


  }

