#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;
    void welcomeMessage();
    void endGameMessage();
    int getLotteryNumbers(int lotteryNumbers[]);
    int getPlayersNumbers(int playersNumbers[]);
    int sortNumbers(int sortNumbers[]);
    void checkNumbers(int lotteryNumbers[],int playersNumbers[]);
    void resultsMessage(int counter);
    void replayGame(char*replay);

int main()
{
    int lotteryNumbers[6];
    int playersNumbers[6];
    char replay;

    welcomeMessage();

    do
    {
    getLotteryNumbers(lotteryNumbers);
    getPlayersNumbers(playersNumbers);
    sortNumbers(lotteryNumbers);
    sortNumbers(playersNumbers);
    checkNumbers(lotteryNumbers,playersNumbers);
    replayGame(&replay);
    system("PAUSE");
    system("CLS");
    }
    while(replay !='y' || replay !='Y');

    endGameMessage();
    return 0;
}

    void welcomeMessage()
    {
    cout<<setw(45)<<"Midway Lottery"<<endl<<endl;
    }

    void endGameMessage()
    {
     cout<<setw(49)<<"Thanks for Playing!!!"<<endl<<endl;
    }

    void replayGame(char*replay)
    {
    cout<<setw(51)<<"Press 'y' to try again"<<endl;

    do
    {
    cin>>*replay;
    }
    while(
    *replay !='y'&&
    *replay !='Y'&&
    *replay !='n'&&
    *replay !='N');
    }

    int getLotteryNumbers(int lotteryNumbers[])
    {
    srand(time(0));

    for (int x=0;x<6;x++)
    {
        lotteryNumbers [x] = 1+(rand()%30);

        while(lotteryNumbers[x]==lotteryNumbers[x-1])
        {
            lotteryNumbers [x] = 1+(rand()%30);
        }
    }
    return 0;
    }
    int getPlayersNumbers(int playersNumbers[])
    {
        cout<<setw(55)<<"enter 6 Lottery numbers (1-30) inclusive"<<endl;
        for(int x=0;x<6;x++)
        {
            cin>>playersNumbers[x];
            while (playersNumbers[x]<1 || playersNumbers[x]>30)
            {
                cout<<"Invalid number!"<<endl;
                cout<<"Please choose (1-30) inclusive: ";
                cin>>playersNumbers[x];
            }
        }
    return 0;
    }
    int sortNumbers(int sortNumbers[])
    {
        int temp;
        for(int counter = 7; counter > 0; counter--)
        {
            for(int x=0; x<5; x++)
            {
                if(sortNumbers[x]>sortNumbers[x+1])
                {
                    temp = sortNumbers[x+1];
                    sortNumbers[x+1] = sortNumbers[x];
                    sortNumbers[x] = temp;
                }
            }
        }
        return 0;
    }

    void checkNumbers(int lotteryNumbers[], int playersNumbers[])
    {
        string yes="YES";
        string no="NO";
        int counter=0;
        cout<<endl;
        cout<<"Lottery numbers ____________  Your numbers     ______________     Results"<<endl;
        for(int x=0;x<6;x++)
        {
            if(lotteryNumbers[x]==playersNumbers[x])
            {
                cout<<setw(11)<<lotteryNumbers[x]<<setw(18)<<"        _       "<<setw(6)
                <<playersNumbers[x]<<setw(19)<<"          _"<<setw(7)<<yes<<endl;
                counter++;
            }
            else
            {
                cout<<setw(11)<<lotteryNumbers[x]<<setw(18)<<"        _       "<<setw(6)
                <<playersNumbers[x]<<setw(19)<<"          _"<<setw(17)<<no<<endl;
            }
        }
        resultsMessage(counter);
        }
        void resultsMessage(int counter)
        {
            cout<<endl;
            if(counter==6)
            {
                cout<<setw(28)<<"You got "<<counter<<" Numbers out of 6"<<endl;
                cout<<setw(41)<<"YOU WON R100 JACKPOT!"<<endl<<endl;
            }
            else if(counter==5)
            {
                cout<<setw(28)<<"You got "<<counter<<" Numbers out of 6"<<endl;
                cout<<setw(41)<<"YOU WON R80 JACKPOT!"<<endl<<endl;
            }
            else if(counter==4)
            {
                cout<<setw(28)<<"You got "<<counter<<" Numbers out of 6"<<endl;
                cout<<setw(41)<<"YOU WON R60 JACKPOT!"<<endl<<endl;
            }
            else if(counter==3)
            {
                cout<<setw(28)<<"You got "<<counter<<" Numbers out of 6"<<endl;
                cout<<setw(41)<<"Try again"<<endl<<endl;
            }
            else if(counter==2)
            {
                cout<<setw(28)<<"You got "<<counter<<" Numbers out of 6"<<endl;
                cout<<setw(41)<<"Try again"<<endl<<endl;
            }
            else if(counter==1)
            {
                cout<<setw(28)<<"You got "<<counter<<" Numbers out of 6"<<endl;
                cout<<setw(41)<<"Try again"<<endl<<endl;
            }
        }
