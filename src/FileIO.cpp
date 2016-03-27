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
	WAVDATA()
		{
		//readWav(s);	
		}
	~WAVDATA()
		{
		std::cout << "Call destructor : class WAVDATA" << endl;
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


    void writeWav(char * fName, float _Fs, double * _data, int _L)
        {
        SNDFILE *write_sf;
        SF_INFO write_info;

        write_info.format       = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
        write_info.channels     = 1;
        write_info.samplerate   = _Fs;

        audio = new double[_L];
        for (int n = 0; n < _L; n++)
        {
        audio[n] = _data[n];
        //cout << audio[n]<<endl;
        }

        write_sf= sf_open(fName,SFM_WRITE,&write_info);
        long writtenFrames = sf_writef_double(write_sf,audio,_L);
        sf_write_sync(write_sf);
        sf_close(write_sf);
        cout << "WrittenFrames : \n" << writtenFrames << endl;
        }
	};
