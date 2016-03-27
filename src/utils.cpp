/*
Desc - 
        Common utilities
Input - 
	
Output - 

Usage - 
*/

#include <iostream>
#include <math>
using namespace std;


class <className> 
	{
	//Private vars	
	
	public:

	//constructor	
	
	//destructor
		
	//functions
    /*
    downsample - returns the signal of length L downsampled by a factor of 'k'
    double * downsample(double * x,int strt_idx, int k,int L)
        {
            double * out;
            out = new double[(int) ceil(L/2)];
            int j = 0;
            for (int i = strt_idx; i < L ; i+=2)
                {
                   out[j] = x[i]; 
                   j++;
                }
                
        return out;
        }
	};
