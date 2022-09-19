public class Conversion
{
  public static void main(String[] args)
  {
     double miles = .5;                         // miles to convert

     double convertToMeters = 1609.34;         // 1 mile = 1609.34 meters
     double meters;

     double convertToInches = 63360.0;       // 1 mile = 63360 inches
     double inches;
  
     double convertToFeet = 5280;            // 1 mile = 5280 feet
     double feet;

     double convertToYards = 1760.0;        // 1 mile = 1760 yards
     double yards;
 
     double convertToCenti = 160934;         // 1 mile = 160934 centimeters
     double centimeters;

     double convertToMilli = 1609344.0;      // 1 mile = 1609344 millimeters
     double millimeters;
  
     double convertToKilo = 1.60934;         // 1 mile = 1.60934 kilometers
     double kilometers;

     meters = miles * convertToMeters;
     inches = miles * convertToInches;
     feet = miles * convertToFeet;
     yards = miles * convertToYards;
     centimeters = miles * convertToCenti;
     millimeters = miles * convertToMilli;
     kilometers = miles * convertToKilo;

     System.out.println("1/2 miles is equal to:");
     System.out.println(miles + " miles");
     System.out.println(meters + " meters");
     System.out.println(inches + " inches");
     System.out.println(feet + " feet");
     System.out.println(yards + " yards");
     System.out.println(centimeters + " centimeters");
     System.out.println(millimeters + " millimeters");
     System.out.println(kilometers + " kilometers");


     double gallons = .5;                  // fluid ounces to convert

     double convertToLiters = 3.78541;       // 1 gallon = 3.78541 liters
     double liters;

     double convertToPints = 8;          // 1 gallon = 8 pints
     double pints;
  
     double convertToQuarts = 4;        // 1 gallon = 4 quarts
     double quarts;
 
     double convertToFluidOunces = 128;    // 1 gallon = 128 fluid ounces
     double fluidOunces;

     double convertToMilliliters = 3785.41;  // 1 gallon = 3785.41 milliliters
     double milliliters;


     liters = gallons * convertToLiters;
     pints = gallons * convertToPints;
     quarts = gallons * convertToQuarts;
     fluidOunces = gallons * convertToFluidOunces;
     milliliters = gallons * convertToMilliliters;

     System.out.println();
     System.out.println("1/2 gallons is equal to: ");
     System.out.println(gallons + " gallons");
     System.out.println(liters + " liters");
     System.out.println(pints + " pints");
     System.out.println(fluidOunces + " fluid ounces");
     System.out.println(quarts + " quarts");
     System.out.println(milliliters + " milliliters");
  }
}