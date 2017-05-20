#include <iostream>
#include <cstdio>
#include <math.h>
#define _USE_MATH_DEFINES

using namespace std;
struct pancake{
double  r, h;
bool chosen;
};

double calculate_area(pancake S[1000], int K)
{
    double areas=0.0;
    for(int i=0;i <K-1; ++i)
    {
        double diff = pow(S[i].r,2) - pow(S[i+1].r,2);
        areas += (M_PI * diff + (2 * M_PI * S[i].r * S[i].h));
    }
    areas += (M_PI * pow(S[K-1].r,2) + (2* M_PI * S[K-1].r * S[K-1].h));
    return areas;
}

int main()
{
    int T;
    cin>>T;

    for(int caser= 1; caser <= T; ++caser)
    {
        int N, K;
        cin >>  N >> K;
        pancake P[1000];
        pancake S[1000];
        for (int pc = 0; pc < N; ++pc)
        {
            cin>>P[pc].r >> P[pc].h;
            P[pc].chosen = false;
        }
        for(int trials=0; trials < N; ++trials)
        {
            double maxP_r = 0;
            double maxP_h = 0;
            int index = -1;
            for(int pc = 0; pc < N; ++pc)
            {
                if(!P[pc].chosen)
                {
                    if(maxP_r < P[pc].r)
                    {
                        index = pc;
                        maxP_r = P[pc].r;
                        maxP_h = P[pc].h;
                    }
                    else if (maxP_r == P[pc].r && maxP_h < P[pc].h)
                    {
                        index = pc;
                        maxP_r = P[pc].r;
                        maxP_h = P[pc].h;
                    }
                }
            }
            P[index].chosen = true;
            S[trials].r = maxP_r;
            S[trials].h = maxP_h;
        }
        for(int trials=0; trials < K; ++trials)
        {
            double maxP_r = 0;
            double maxP_h = 0;
            int index = -1;
            for(int pc = 0; pc < N; ++pc)
            {
                if(!P[pc].chosen)
                {
                    if(maxP_r < P[pc].r)
                    {
                        index = pc;
                        maxP_r = P[pc].r;
                        maxP_h = P[pc].h;
                    }
                    else if (maxP_r == P[pc].r && maxP_h < P[pc].h)
                    {
                        index = pc;
                        maxP_r = P[pc].r;
                        maxP_h = P[pc].h;
                    }
                }
            }
            P[index].chosen = true;
            S[trials].r = maxP_r;
            S[trials].h = maxP_h;
        }

        printf("\nCase #%d: %.6f", caser, calculate_area(S, K));
//        cout<<"\nCase #"<< caser <<": "<< double (D)/ double (timer);
    }
}
