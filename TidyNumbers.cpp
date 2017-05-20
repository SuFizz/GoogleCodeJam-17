#include <iostream>
#include <math.h>
using namespace std;

void make_new_start (unsigned long long int N )
{
    int str[20];
    for(int h=0; h<20; ++h)
    {
        str[h] = 0;
    }
    int i = 0;
    while(N)
    {
        str[i++] = N%10;
        N/=10;
    }
//    for(int h=0; h<i; ++h)
//    {
//        cout<<str[h];
//    }
//    cout << endl;

    for(int uk = 0; uk<i ; ++uk)
    {
        int flag = 0;
        for(int j=i-1; j>0; --j)
        {
            if(str[j] > str[j-1])
            {
                str[j]--;
                for(int k=j-1; k>=0; --k)
                {
                    str[k] = 9;
                    flag = 1;
                }
                break;
            }
        }
        if(!flag)
        {
            break;
        }
    }

    int flagg = 0;
    for(int h=i-1; h>=0; --h)
    {
        if(str[h])
        {
            flagg = 1;
        }
        if(flagg)
        {
            cout<<str[h];
        }
    }

}

int main()
{
    int T;
    cin>>T;

    unsigned long long int N;

    for(int caser= 1; caser <= T; ++caser)
    {
        cin>>N;

        cout<<"\nCase #"<< caser <<": ";
        make_new_start(N);
    }
}

unsigned long long int is_tidy(unsigned long long int N)
{
    unsigned long long int M = N;
    int prev = N%10;
    N/=10;
    while(N)
    {
        int newer = N%10;
        if(newer > prev)
        {
            return 0;
        }
        else
        {
            prev = newer;
            N/=10;
        }
    }
    return M;
}
