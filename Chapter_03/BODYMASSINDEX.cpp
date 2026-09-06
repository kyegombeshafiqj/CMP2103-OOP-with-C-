#include <iostream>
#include <math.h>
#include <iomanip>
#define KILOGRAMS 0.45359237
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

    if(BMI < 18.5){
        cout<<"Underweight"<<endl;
    } else if(BMI <= 24.9){
        cout<<"Normal"<<endl;
    } else if(BMI <= 29.9){
        cout<<"Overweight"<<endl;
    } else {
        cout<<"Obese"<<endl;
    }
     
    
    
    return 0;
}