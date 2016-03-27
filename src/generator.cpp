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
        int num_samples;
        


	//constructor	
    generator(float _Fs,float _start,float _end,float _duration)
       {
        setting(_Fs,_start,_end,_duration);
        chirp();
        }

    ~generator()
        {
        std::cout << "Call destructor : class generator" << endl;
        delete [] data;
        }

	
	//destructor
		
   	//functions

    //Chirp - sinusoidal chirp signal given start and end freq. ranges of types linear, exp.

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


    void setting(float _Fs,float _strt,float _end,float _duration)
        {
        Fs      = _Fs;
        start   = _strt;
        end     = _end;
        duration= _duration;
        }
	};
