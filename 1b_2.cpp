#include <iostream>
#include <cstdio>
using namespace std;

void colorer(int N, int h2, char c2, int h1, char c1, int h0, char c0)
{
    char stables[1000];
    for(int dirt=0; dirt<1001; ++dirt)
    {
        stables[dirt] = 'z';
    }
    for(int j=0; j<h0; ++j)
    {
        if(j*2>=N-1)
        {
            cout<< "IMPOSSIBLE";
            return ;
        }
        stables[j*2] = c0;
    }

    for(int j=0; j<h1; ++j)
    {
        if(N - j*2 - 1 <0)
        {
            cout<< "IMPOSSIBLE";
            return ;
        }
        if(stables[N- j*2 -1] == 'z')
        {
            stables[N - j*2 - 1] = c1;
        }
        else
        {
            if(N - j*2 - 2 <0)
            {
                cout<< "IMPOSSIBLE";
                return ;
            }
            stables[N - j*2 - 2] = c1;
        }
    }
    int empty_count = 0;
    int prev = -2;
    for(int j=0 ;j <N; ++j)
    {
        if(stables[j] == 'z')
        {
            if(prev == j-1)
            {
                cout <<"IMPOSSIBLE";
                return;
            }
            prev = j;
            stables[j] = c2;
            empty_count ++;
        }
    }
    if(empty_count != h2)
    {
        cout << "IMPOSSIBLE";
        return ;
    }
    else
    {
        for(int op=0; op<N; ++op)
        {
            cout<<stables[op];
        }
    }
    return;
}

int main()
{
    int T;
    cin>>T;

    for(int caser= 1; caser <= T; ++caser)
    {
        int N;
        int R, O, Y, G, B, V;
        cout<<"\nCase #"<< caser <<": ";
        cin >> N;

        cin >> R >> O >> Y >> G >> B >> V;
        if(R>= B && Y>= B)
        {
            if(Y >= R)
            {
                colorer(N, B, 'B', R, 'R', Y, 'Y');
            }
            else
            {
                colorer(N, B, 'B', Y, 'Y', R, 'R');
            }
        }
        else if(R>= Y && B>= Y)
        {
            if(B >= R)
            {
                colorer(N, Y, 'Y', R, 'R', B, 'B');
            }
            else
            {
                colorer(N, Y, 'Y', B, 'B', R, 'R');
            }
        }
        else if(B>= R && Y>= R)
        {
            if(B >= Y)
            {
                colorer(N, R, 'R', Y, 'Y', B, 'B');
            }
            else
            {
                colorer(N, R, 'R', B, 'B', Y, 'Y');
            }
        }

//        cout<<"\nCase #"<< caser <<": "<< double (D)/ double (timer);
    }
}
