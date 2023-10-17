#include<bits/stdc++.h>
using namespace std;

class Stock{
    int Time;
    int counter = 0;
    float sum = 0;
    queue<int> q1;//For  sma
    float prevEMA = 0 ;// for ema

    public:

    Stock(int n){
        Time = n;
    }

    float sma(int value){
        q1.push(value);
        sum += value;
        if(counter < Time){
            counter ++; //this opearation need to be done only once either sma or ema
            return -1;
        }
        else{
            sum -= q1.front();
            q1.pop();
            return sum/Time;
        }
    }

    float ema(int value)
    {
        prevEMA += ( 2*(value-prevEMA)/(Time+1) );
        if(counter < Time){
            //counter ++; //this opearation need to be done only once either sma or ema
            return -1;
        }
        else{
            return prevEMA;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif

    int T;// Time Frame of SMA
    cin >> T;
    Stock s1(T);
    cout << "Price\tSMA\tEMA\n";
    int temp = 0;
    while(temp != -1)
    {
        cin >> temp;
        printf("%d\t%f\t%f\n",temp, s1.sma(temp), s1.ema(temp));
        //cout << temp << "\t" << s1.sma(temp) << "\t" << s1.ema(temp) << endl;
    }

    getchar();
    return 0;
}