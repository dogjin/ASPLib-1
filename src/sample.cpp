#include <iostream>
#include <string>
#include "FileIO.cpp"


/*
TODO
add documentation for FileIO.cpp and commit
*/

using namespace std;

int main()
	{
	//WAVDATA f;
	//double * audio;
	int Fs;
	//f.fName = "/home/vvekkumar/code/data/test/a440.wav";
        char * inFile = "/home/vvekkumar/code/data/test/a440.wav";
	WAVDATA f(inFile);
	/*
	Need to have member function that returns an audio variable, and perhaps an "Fs" variable 
	Q's
	Where should memory allocation occur?
	If memory is allocated inside the member function, what is the state of the variable when it is returned?	
	*/

        f.readWav(inFile);
        cout << "Channels : " <<  f.nChannels << endl;
        cout << "Sample Rate :" << f.Fs << endl;			
	cout << "Length of array :" << f.L << endl;
        int i = 0;
        cout << "Num samples : " << f.L << endl; 
	return 0;
	}
