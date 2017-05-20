#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    cin>>T;

    for(int caser= 1; caser <= T; ++caser)
    {
        int N;
        unsigned long long int D;
        cin >> D >> N;
        double timer = 0.0;
        for (int horse = 0; horse < N; ++horse)
        {
            unsigned long long int K, S;
            cin>>K >> S;
            double time_horse = double (D - K) / double (S);
            if(time_horse > timer)
                timer = time_horse;
        }
        cout.precision(6);
        printf("\nCase #%d: %.6f", caser,  double (D)/ double (timer));
//        cout<<"\nCase #"<< caser <<": "<< double (D)/ double (timer);
    }
}
