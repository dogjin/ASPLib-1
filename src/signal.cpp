/*
Desc - 
    Class signal provides various methods for analyzing audio signals	

Input - 
    double * //(audio data)
	
Output - 
    Depending on called method. List of available methods : 
    fft()

    ifft()


    spect()

    psd()

    power()

    abs()

Usage - 
*/

#include <iostream>
#include <complex>
#include "utils.cpp"
using namespace std;


class signal 
	{
	//Private vars	
    const double pi = std::acos(-1);
    const std::complex<double> i(0, 1);

	public:
         

	//constructor	
	
	//destructor
		
	//functions
    /*
    fft()
    input   : double * audio, int N [num of points of FFT]
    output  : double * array of length N 
    */

    double * fft(double * audio, int L, int N)
        {
        double * x=audio;
        //1. DS1,DS2
        double * x0,x1;
        //alloc mem
        x0 = downsample(x, 0, 2, L)
        x1 = downsample(x, 1, 2, L)

        //2. FFT1,FFT2
        double * X0, X1;
        X0 = fft(X0,L/2,N);
        X1 = fft(X1,L/2,N);
        //3. 
        
        }
	};
