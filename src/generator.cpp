/*
Desc - 
      class generator creates signals of type tone, noise, chirp, silence
Input - 
      depends on type of signal to be created

Output - 
      

Usage - 
*/

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

#define pi 3.14159265

class generator 
	{
    	//Private vars	

	
	public:
        double * data;
        float duration;
        float start;
        float end;
        float Fs;
        float f;
        int num_samples;
        


	//constructor	
    //generator(char* _type,float _Fs,float _start,float _end,float _duration)
    generator(char* _type)
       {
        //setting(_Fs,_start,_end,_duration);
        char * A = "chirp";
        char * B = "tone";
        char * C = "noise";
        char * D = "silence";

        if (strcmp(_type,A) == 0)
        {
            chirp_setting();
            chirp();
        }
       
        if (strcmp(_type,B) == 0)
        {
            tone_setting();
            tone();
        }
       
        if (strcmp(_type,C) == 0)
        {
            //noise_setting();
            //noise();
        }
       
        if (strcmp(_type,D) == 0)
        {
            silence_setting();
            silence();
        }
        
       }

    ~generator()
        {
        std::cout << "Call destructor : class generator" << endl;
        delete [] data;
        }

	
	//destructor
		
   	//functions

    //Chirp - sinusoidal chirp signal given start and end freq. ranges of types linear, exp.

    //void chirp_setting(float _Fs,float _strt,float _end,float _duration)
    void chirp_setting()
        {
        cout << "Sampling Freq. (Fs) : ";
        cin  >> Fs;
        cout << "Starting Freq. (f0) : ";
        cin >> start;
        cout << "End Freq.      (f1) : ";
        cin >> end;
        cout << "Duration(in secs)(T): "; 
        cin >> duration;
        }


    void chirp()
        {
        int N           = (int)  Fs * duration;
        num_samples     = N;
        data            = new double[N];
        
        float k         = (end - start) / (2*Fs*duration); //rate .. not sure why it is divided by 2.0
        float fNew      = 0.0;

        for (int n = 0 ; n < N ; n++)
            {
            fNew          = (start + n*k);
            data[n]       = sin(2*pi*fNew/Fs*n);
            }

        }

    void silence_setting()
        {
        cout << "Sampling Freq.(Fs)";
        cin >> Fs;
        cout << "Duration";
        cin >> duration;
        }

    void silence()
        {
        int N           = (int) Fs * duration;
        num_samples     = N;
        data            = new double[N];
       
        for (int n = 0; n < N; n++)
            data[N] = 0;
        }

    void tone_setting()
        {
        cout << "Sampling Freq. (Fs)";
        cin >> Fs;
        cout << "Freq.";
        cin >> f;
        cout << "Duration";
        cin >> duration;
        }

    void tone()
        {
        int N           = (int) Fs * duration;
        num_samples     = N;
        data            = new double[N];

        for (int n = 0; n < N; n++)
            {
            data[n] = sin(2*pi*f/Fs*n);    
            }
        }
	};
