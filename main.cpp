//Afham Bashir. Assignment 6 wind chill factor. 
#include <iostream>
#include <cmath>            //allows use of pow function for exponents in calculator of wind chill. 
#include <iomanip>
using namespace std; 
 
double ctof( double celsius);                        //prototype for functino for converting from celsius to fahrenheit. 
double ftoc( double fahrenheit);                     //prototype for function for converting from fahrenheit to celsius.  
double windchill(double temperature, double speed);  //prototyp for function that calculates windchill from fahrenheit and wind speed. 

int main() {              // main function 
  double speed;           //declaring variable to store value of wind speed. 
  double temperature;     //declaring varaiable to store the temperature the user gives.   
  double chillfactor;     //declaring a varaible to store that calcualted chill factor. 
  char scale;             //declaring varaible to store the charater the user input to determine which temperature scale is being used. 

  cout << "Calculating Wind Chill Factor" <<endl;             //title 
  cout << endl;                                                 
  cout << "Enter wind speed in miles per hour: " ;            //prompt for wind speed
  cin >> speed;                                               //assing value to wind speed. 
  cout << endl; 
  cout << "Enter the current temperature followed by either \n c for celsius or f for fahrenheit without a space: ";  //prompts user to input temperature and scale that value is on. 
  cin >> temperature >> scale;      // assings values to both the temperature and a character to scale
  cout << endl; 

  if (scale == 'c'){                        //if the temperature scale was in celsius, then the program will execute these statements. 
    temperature= ctof(temperature);         //the given celsius temperature is converted to fahrenheit using the ctof function.
     chillfactor= windchill(temperature, speed);      //the chill factor is assinged a value from the function that calculated the wind chill from the temperature and speed. 
    cout << "The Wind Chill Factor is "<<fixed << setprecision (1)<< chillfactor<<"F or "<<ftoc(chillfactor)<<"C."<<endl;   // the windchill is output with one decimal point while also being converted back into celsius using the ftoc function. 
  }
  else {        //if the temperature scale wasnt in celsius, then the program doesnt need to convert the temperature and thus these statements are execued. 
     chillfactor= windchill(temperature, speed);  // the chill factor is assinged a value from the function that calculated the wind chill from the temperature and speed. 
      cout << "The Wind Chill Factor is "<<fixed << setprecision (1)<<chillfactor<<"F."<<endl; //the windchill is output with one decimal point.
  }
return 0;  // the main function terminates. 
}

double ctof (double celsius){             //function for going from celsius to fahrenheit
  double fahrenheit;                     // fahrenheit must be declared to store calcualted value from input celsius
  fahrenheit= (1.8*celsius)+32;         // fahrenheit is 1.8 times celsius, then plus 32. 
return fahrenheit;                      //the program returns a copy of the fahrenheit varaiable's value. 
}
 
double ftoc (double fahrenheit){           //function for going from fahrenheit to celsius. 
  double celsius;                           // celsius must be declared to store calcualted value from input fahrenheit temperature. 
  celsius= (0.55555556)*(fahrenheit-32);    // celsius is (5/9) times 32 less than fahrenheit. 
return celsius;                             //the program returns a copy of the celsius varaiable's value.
}

double windchill( double temperature, double speed){  //function for finding wind chill from wind speed and temperature 
double chillfactor;           // declaring a variable to hold the value of the calcualted chillfactor
chillfactor= 35.74+ (0.6215*temperature)-(35.75*(pow(speed, 0.16)))+(0.4275*temperature*(pow(speed, 0.16)));  //
   // the chill factor is 35.74 plus the temperature times 0.6215 minus 35.75 times the speed to the 0.16 power, plus 0.4275 times the temperature times the wind speed to the 0.16 power. 
  return chillfactor;     //the program returns a copy of the chill facotor varaiable's value.
}