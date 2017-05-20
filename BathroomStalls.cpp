#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    cin>>T;

    unsigned long long int N,K;

    for(int caser= 1; caser <= T; ++caser)
    {
        cin >> N >> K;

        unsigned int* lbaths = new unsigned int[1000000];
        unsigned int* rbaths = new unsigned int[1000000];
        for(j=0; j<N; ++j)
        {
            lbaths[j] = j;
            rbaths[N-j] = j;
        }

        unsigned long long int stall = (start + end)/2;
        lbaths[0] = 1;
        rbaths[N-1] = 1;
//        baths[stall] = true;
        unsigned long long int max = start;

        unsigned long long int accum = 0;
        unsigned long long int start_check = start;
        unsigned long long int end_check = end;

        unsigned long long int start_prev = start;
        unsigned long long int end_prev = end;

        for(int j=1; j<N+1; ++j)
        {
            if( !baths[j] )
            {
                accum++;
            }
            else
            {
                if(accum > max)
                {
                    end_check = j;
                    start_check =
                }
            }
            if(max == start)
            stall = (start + end)/2;
            if(j != K-1)
            {
                if (stall - start >= end - stall )
                {
                    end = stall;
                }
                else
                {
                    start = stall;
                }
            }
        }
        cout<<"\nCase #"<< caser <<": ";

        int max = ((stall - start) >= (end - stall)) ? (stall - start - 1) : (end - stall - 1);
        int min = ((stall - start) > (end - stall)) ? (end - stall - 1) : (stall - start - 1);
        cout << max << " " << min;
        delete baths;

//        if(!flagger)
//        {
//            cout<<"\nCase #"<< caser <<": "<<flips;
//        }
    }
}
