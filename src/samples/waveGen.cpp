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
    char * outFile1 = "/home/vvekkumar/code/data/test/gen_chirp.wav";
    //generate signal
    char * type = "chirp";
    generator signal1(type);
    //write to file
    WAVDATA f;
    f.writeWav(outFile1,signal1.Fs,signal1.data,signal1.num_samples);


	char * outFile2 = "/home/vvekkumar/code/data/test/silence.wav";
    //generate signal
    char * type1 = "silence";
    generator signal2(type1);
    //write to file
    WAVDATA f1;
    f1.writeWav(outFile2,signal2.Fs,signal2.data,signal2.num_samples);



  char * outFile3 = "/home/vvekkumar/code/data/test/sine.wav";
  //generate signal
  char * type2 = "tone";
  generator signal3(type2);
  //write to file
  WAVDATA f2;
  f2.writeWav(outFile3,signal3.Fs,signal3.data,signal3.num_samples);
  return 0;
	}
