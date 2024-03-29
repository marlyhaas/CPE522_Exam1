/* A TMP36 temperature sensor application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

// Edited by Marly Haas for use during CPE522 Take-Home Exam1.

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

#define LDR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

int readAnalog(int number)
{
// returns the input as an int
   stringstream ss;
   ss << LDR_PATH << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}

float getTemperature(int adc_value)
{
   float cur_voltage = adc_value * (1.80f/4096.0f);
   float diff_degreesC = (cur_voltage-0.75f)/0.01f;
   return (25.0f + diff_degreesC);
}

int main(int argc, char* argv[])
{
   FILE* tempsfile;
   tempsfile = fopen("temperatures.txt", "a");

   int ain = 0;
   cout << "Starting the TMP36 temperature sensor program" << endl;
   for(int i = 0; i < 10; i++)
   {
   	if (argc>1) ain = atoi(argv[1]);
   	int value = readAnalog(ain);

	cout << "Reading temperature " << i << "." << endl;

   	float temperature = getTemperature(value);
   	fprintf(tempsfile, "%f\n", temperature);

	sleep(1);
   }

   cout << "Ending the TMP36 temperature sensor program" << endl;

   fclose(tempsfile);

   return 0;
}
