#include <iostream>
#include <cstdio>
using namespace std;

bool flip(char str[1005], int i, int K)
{
    for(int j=i; j<i+K; ++j)
    {
        if(!str[j])
        {
            return false;
        }
        if(str[j] == '-')
        {
            str[j] = '+';
        }
        else
        {
            str[j] = '-';
        }
    }
    return true;
}

int main()
{
    int T;
    cin>>T;

    char str[1005];
    int K;

    for(int caser= 1; caser <= T; ++caser)
    {
        cin>>str;
        cin>>K;
        int i=0;
        int flips = 0;
        bool flagger = false;

        while(str[i])
        {
            if(str[i] == '-')
            {
                if(flip(str,i,K))
                {
                    ++flips;
                }
                else
                {
                    cout<<"\nCase #"<< caser <<": IMPOSSIBLE";
                    flagger = true;
                    break;
                }
            }
            ++i;
        }
        if(!flagger)
        {
            cout<<"\nCase #"<< caser <<": "<<flips;
        }
    }
}
