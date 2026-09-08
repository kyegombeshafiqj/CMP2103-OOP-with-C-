// Write a program that prompts the user to enter a weight in pounds and height in inches and
// then displays the BMI. Note that one pound is 0.45359237 kilograms and one inch is
// 0.0254 meters. Listing 4.6 gives the program.

// Conditions
// Below 18.5 Underweight
// 18.5–24.9 Normal
// 25.0–29.9 Overweight
// Above 30.0 Obese

// Enter weight in pounds:
// Enter Weight in pounds: 146
// Enter height in inches: 70
// BMI is 20.95
// Normal
#include <iostream>
#include <math.h>
#include <iomanip>
#define KILOGRAMS 0.4539237
#define METERS 0.0254
double convert_to_kilograms(double weight){
    return(weight*KILOGRAMS);
}
double convert_to_meters(double height){
    return(height*METERS);
}
using namespace std;
int main(){
    double weight;
    double height;
    cout<<"Enter weight in pounds: "<<endl;
    cin>>weight;
    cout<<"Enter height in inches: " <<endl;
    cin>>height;
    double height_in_meters= convert_to_meters(height);
    double weight_in_kilograms= convert_to_kilograms(weight);
    double BMI;
    BMI = (weight_in_kilograms/(height_in_meters*height_in_meters) );
    cout<<"The BMI is: "<<fixed<<setprecision(2)<<BMI<<endl;

    if(BMI< 18.5){
        cout<<"Underweight"<<endl;
    }
    if(18.5<=BMI<=24.9){
        cout<<"Normal"<<endl;
    }
    if(BMI>30.0){
        cout<<"Obese"<<endl;
    }
     
    
    
    return 0;
}