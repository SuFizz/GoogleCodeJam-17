#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    cin>>T;

    for(int caser= 1; caser <= T; ++caser)
    {
        int N;
        int Q;
        cin >> N >> Q;
        int horse_speed[100];
        int horse_distance[100];
        for(int k=0;k <N; ++k)
        {
            cin >> horse_speed[k] >> horse_distance[k];
        }
        int distance_city[100][100];
        for(int i=0; i<N; ++i)
            for(int j=0; j< N; ++j)
            {
                cin >> distance_city[i][j];
            }
        int U, V;
        cin >> U >> V;


        //        cout<<"\nCase #"<< caser <<": "<< double (D)/ double (timer);
    }
}
