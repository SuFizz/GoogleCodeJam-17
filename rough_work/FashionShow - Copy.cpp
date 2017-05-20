#include <iostream>
#include <cstdio>
using namespace std;

char chr[10000];
int rows[10000];
int cols[10000];
int subs ;

void clear_ramp(char ramp[100][100])
{
    for(int i=0; i<100; ++i)
        for(int j=0; j<100; ++j)
        {
            ramp[i][j] = '.';
        }
}

void do_placement(char ramp[100][100], int N)
{
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            int flagu = 0;
            for(int d=1; d<N; ++d)
            {
                if(
                    (((i+d) <N) && (ramp[i+d][j] == 'x' || ramp[i+d][j] == 'o'))
                   || (((j-d) >=0) && (ramp[i][j-d] == 'x' || ramp[i][j-d] == 'o'))
                   || (((i-d) >=0) && (ramp[i-d][j] == 'x' || ramp[i-d][j] == 'o'))
                   || (((j+d) <N)  && (ramp[i][j+d] == 'x' || ramp[i][j+d] == 'o'))
                  )
                {
                    flagu = 1;
                    break;
                }
            }
            if(flagu) continue;

            int flag = 0;
            for(int d=1; d<N; ++d)
            {
                if(
                    (((i+d) <N) && ((j+d) <N) && (ramp[i+d][j+d] == '+' || ramp[i+d][j+d] == 'o'))
                   || (((i+d) <N) && ((j-d) >=0) && (ramp[i+d][j-d] == '+' || ramp[i+d][j-d] == 'o'))
                   || (((i-d) >=0) && ((j-d) >=0) && (ramp[i-d][j-d] == '+' || ramp[i-d][j-d] == 'o'))
                   || (((i-d) >=0) && ((j+d) <N) && (ramp[i-d][j+d] == '+' || ramp[i-d][j+d] == 'o'))
                  )
                {
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            else
            {
                ramp[i][j] = 'o';
                chr[subs] = 'o';
                rows[subs] = i+1;
                cols[subs] = j+1;
                subs++;
//                cout << "o " << i+1<<' '<<j+1<<'\n';
            }
        }

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            if(ramp[i][j] == 'o' || ramp[i][j] == 'x' || ramp[i][j] == '+')
            {
                continue;
            }
            int flag = 0;
            for(int d=1; d<N; ++d)
            {
                if(
                    (((i+d) <N) && ((j+d) <N) && (ramp[i+d][j+d] == '+' || ramp[i+d][j+d] == 'o'))
                   || (((i+d) <N) && ((j-d) >=0) && (ramp[i+d][j-d] == '+' || ramp[i+d][j-d] == 'o'))
                   || (((i-d) >=0) && ((j-d) >=0) && (ramp[i-d][j-d] == '+' || ramp[i-d][j-d] == 'o'))
                   || (((i-d) >=0) && ((j+d) <N) && (ramp[i-d][j+d] == '+' || ramp[i-d][j+d] == 'o'))
                  )
                {
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            else
            {
                ramp[i][j] = '+';
                chr[subs] = '+';
                rows[subs] = i+1;
                cols[subs] = j+1;
                subs++;
//                cout<<"+ "<< i+1 <<' '<< j+1<<'\n';
            }
        }

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            int flagu = 0;
            for(int d=1; d<N; ++d)
            {
                if(
                    (((i+d) <N) && (ramp[i+d][j] == 'x' || ramp[i+d][j] == 'o'))
                   || (((j-d) >=0) && (ramp[i][j-d] == 'x' || ramp[i][j-d] == 'o'))
                   || (((i-d) >=0) && (ramp[i-d][j] == 'x' || ramp[i-d][j] == 'o'))
                   || (((j+d) <N)  && (ramp[i][j+d] == 'x' || ramp[i][j+d] == 'o'))
                  )
                {
                    flagu = 1;
                    break;
                }
            }
            if(flagu) continue;

            if(ramp[i][j] == 'o' || ramp[i][j] == 'x' || ramp[i][j] == '+')
            {
                continue;
            }
            ramp[i][j] = 'x';
            chr[subs] = 'x';
            rows[subs] = i+1;
            cols[subs] = j+1;
            subs++;
//            cout<<"x "<< i+1<<' ' <<j+1<<'\n';
        }
}
void calculate_score(char ramp[][100], int N)
{
    int score = 0;
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
        {
            if(ramp[i][j] == 'o')
            {
                score += 2;
            }
            else if(ramp[i][j] == '+' || ramp[i][j] == 'x')
            {
                score += 1;
            }
        }
    cout << score<<" "<< subs << endl;
}
void spit_subs()
{
    for(int y=0; y<subs; ++y)
    {
        cout << chr[y] <<" "<< rows[y] <<" "<< cols[y] << endl;
    }
}

int main()
{
    int T;
    cin>>T;

    char ramp[100][100];
    int M, N;

    for(int caser= 1; caser <= T; ++caser)
    {
        clear_ramp(ramp);
        cin>> N>> M;
        char model_type;
        int R, C;
        for(int model=0; model<M; ++model)
        {
            cin >> model_type >> R >> C;
            ramp[R-1][C-1] = model_type;
        }

        cout<<"\nCase #"<< caser <<": ";
        subs = 0;
        do_placement(ramp, N);
        calculate_score(ramp, N);
        spit_subs();
    }
}
