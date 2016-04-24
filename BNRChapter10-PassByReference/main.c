//
//  main.c
//  BNRChapter10-PassByReference

#include <stdio.h>
#include <math.h>


//void metersToFeetAndInches(double meters, unsigned int *ftPtr, double *inPtr) {
//    // This function assumes meters in non-negative.
//    
//    // Convert the number of meters into a floating-point number of feet.
//    double rawFeet = meters * 3.281; // basic conversion
//    
//    // How many complete feet as unsigned int?
//    unsigned int feet = (unsigned int)floor(rawFeet);
//    
//    // Store the number of feet at the supplied address.
//    if (feet) {
//    printf("Storing %u to the address %p\n", feet, ftPtr);
//    *ftPtr = feet;
//    }
//    // Calculate inches.
//    double fractionalFoot = rawFeet - feet;
//    double inches = fractionalFoot * 12;
//    
//    if (inches) {
//    // Store the number of inches at the supplied address.
//    printf("Storing %.2f to the address %p\n", inches, inPtr);
//    *inPtr = inches;
//    }
//}

void metersToFeetAndInches(double meters, unsigned int *ftPtr, double *inPtr) {
    // This function assumes meters in non-negative.
    
    // Declare feet.
    double feet;
    
    // Convert the number of meters into a floating-point number of feet.
    double rawFeet = meters * 3.281; // basic conversion
    
    // This time using modf()
    double fractionalFoot = modf(rawFeet, &feet);
    
    
    // Store the number of feet at the supplied address.
    if (feet) {
        printf("Storing %f to the address %p\n", feet, ftPtr);
        *ftPtr = feet;
    }
    // Calculate inches.
    double inches = fractionalFoot * 12;
    
    if (inches) {
        // Store the number of inches at the supplied address.
        printf("Storing %.2f to the address %p\n", inches, inPtr);
        *inPtr = inches;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    double pi = 3.14;
    double integerPart;
    double fractionPart;
    
    // pass the address of the integerPart as an argument
    fractionPart = modf(pi, &integerPart);
    
    // Find the value stored in the integerPart
    printf("integerPart = %.0f, fractionPart = %.2f\n\n\n", integerPart, fractionPart);
    
    
    // Meters to Feet and Inches function fun.
    double meters = 3.0;
    unsigned int feet;
    double inches;
    
    metersToFeetAndInches(meters, &feet, &inches);
    printf("%.1f meters is equal to %d feet and %.1f inches.\n", meters, feet, inches);
    
    
    return 0;
}
