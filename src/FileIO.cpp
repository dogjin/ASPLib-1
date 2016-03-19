/*
Desc - 
	Uses SNDFILE to read audio

	Call WAVDATA.readWav() upon instantiation
        Class variables :
	*fName(required) : File Name
	nChannels	 : Num channels
	Fs		 : Sampling frequency
	audio		 : double * sample data
	L		 : int number of samples
Input - 
	
Output - 

Usage - 
*/

#include <iostream>
#include <stdlib.h>
#include <sndfile.h>
using namespace std;


class WAVDATA 
	{
	//vars	
	SNDFILE *sf;
	SNDFILE	*writeSf;
	SF_INFO info;
	SF_INFO write_info;
	
	public:
	  char * fName;
          int nChannels;
          int Fs;
          double * audio;
	  int L;
	WAVDATA(char * s)
		{
		readWav(s);	
		}
	~WAVDATA()
		{
		std::cout << "Destructor" << endl;
		delete [] audio;
		}
 	
		
	//functions
	
	/*
	readWav(double * audio)
	*/
              void readWav(char * fName)
		{
		//get file info - num_channels, sampling rate
                  SNDFILE *sf;
		  SF_INFO info;
		  sf = sf_open(fName,SFM_READ,&info);
		  if (sf == NULL)
		  {
		   printf("Could not open WAVE audio\n");
		   //Exit(-1);
		   exit (EXIT_FAILURE);
               	 }
		  Fs=info.samplerate;
		  nChannels=info.channels;
		
		//allocate memory for reading data
	 	int num_items=info.frames * nChannels;
		L = num_items;
                int size = num_items + 2;
		audio = new double[size];
	        audio[num_items] = '\0';
                audio[num_items+1] = num_items;
		int num=sf_read_double(sf,audio,num_items);
		sf_close(sf);
		}
             void writeWav(double * audio,char * fName)
	        {}
	};
