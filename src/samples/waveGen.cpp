#include <iostream>
#include <string>
#include "/home/vvekkumar/code/ASPLib/src/FileIO.cpp"
#include "/home/vvekkumar/code/ASPLib/src/generator.cpp"


/*
TODO
add documentation for FileIO.cpp and commit
*/

using namespace std;

int main()
	{
    char * outFile = "/home/vvekkumar/code/data/test/gen_chirp.wav";
    //generate signal
    generator chirp(16000,800,4000,30);

    //write to file
    WAVDATA f;
    f.writeWav(outFile,chirp.Fs,chirp.data,chirp.num_samples);
	return 0;
	}
