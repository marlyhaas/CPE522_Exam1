#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

std::vector<float> readLines(string filename){
   ifstream fs;
   fs.open((filename).c_str());
   string line;
   int newline;
   std::vector<float> temp_array;

   while(getline(fs, line)){
	temp_array.push_back(atoi(line.c_str()));
   }

   fs.close();
   return temp_array;
}

int main(int argc, char* argv[]){
   if(argc != 2){
      cout << endl;
      cout << "Usage is process-temp and filename" << endl;
      cout << "  e.g. readLines(filename)" << endl;
   }

   cout << endl;
   cout << "Starting the reading_file program." << endl;
   string filename(argv[1]);
   cout << "The filepath entered is: " << filename << endl;
   cout << "Taking the average of the temperatures." << endl;

   std::vector<float> temp_array;
   temp_array = readLines(filename);
   float sum = 0;
   for(auto& i : temp_array){
	sum += i;
   }

   int div;
   float avg;
   div = temp_array.size();
   avg = sum / div;

   cout << "The average of the 10 temperatures is: " << avg << endl;

   cout << "Finished the process-temp program." << endl;
   cout << endl;
   return 0;
}
