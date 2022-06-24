#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int player=1;
string p1;
string p2;
void viewScores();
void writeScores(string);
class TTT{
    private:
        int square[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}; //Board Position
    public:
        char change(int,int);
        void getNames();
        int checkWin();
        void drawboard();
};
void TTT::getNames(){
    cout<<endl<<"Enter Name of Player 1 :";
    cin>>p1;
    cout<<endl<<"Enter Name of Player 2 :";
    cin>>p2;
}
void writeScores(string winner){
    ofstream out;
    out.open("winners.dat",ios::app);
    out<<winner<<endl;
    out.close();
}
void viewScores(){
    ifstream in;
    in.open("winners.dat",ios::in);
    if(in.is_open()){
        cout<<endl<<"=========================="<<endl;
        cout<<"Tic Tac Toe - Winners"<<endl;
        cout<<"=========================="<<endl;
        string winner;
        while(getline(in, winner)){
            cout<<winner<<"\n";
        }
        in.close();
        cout<<"=========================="<<endl;
    }else{
        cout<<endl<<"=========================="<<endl;
        cout<<"File not Found!"<<endl;
        cout<<"=========================="<<endl;
    }
    cout<<endl<<"Press any key to continue!";
    getch();
}
int TTT::checkWin(){
//Game's Logic : For 3x3 Tic Tac Toe, 3 in a row means Win... In our case(5x5), we choose 4 in a row means Win
    //Checking Horizontal Rows for Win
        //row 1
    if(square[1]==square[2] && square[2]==square[3] && square[3]==square[4])
        return 1;
    else if(square[2]==square[3] && square[3]==square[4] && square[4]==square[5])
        return 1;
        //row 2
    else if(square[6]==square[7] && square[7]==square[8] && square[8]==square[9])
        return 1;
    else if(square[7]==square[8] && square[8]==square[9] && square[9]==square[10])
        return 1;
        //row 3
    else if(square[11]==square[12] && square[12]==square[13] && square[13]==square[14])
        return 1;
    else if(square[12]==square[13] && square[13]==square[14] && square[14]==square[15])
        return 1;
        //row 4
    else if(square[16]==square[17] && square[17]==square[18] && square[18]==square[19])
        return 1;
    else if(square[17]==square[18] && square[18]==square[19] && square[19]==square[20])
        return 1;
        //row 5
    else if(square[21]==square[22] && square[22]==square[23] && square[23]==square[24])
        return 1;
    else if(square[22]==square[23] && square[23]==square[24] && square[24]==square[25])
        return 1;

    //Checking Vertical Rows for Win
        //col 1
    if(square[1]==square[6] && square[6]==square[11] && square[11]==square[16])
        return 1;
    else if(square[6]==square[11] && square[11]==square[16] && square[16]==square[21])
        return 1;
        //col 2
    else if(square[2]==square[7] && square[7]==square[12] && square[12]==square[17])
        return 1;
    else if(square[7]==square[7] && square[12]==square[17] && square[17]==square[22])
        return 1;
        //col 3
    else if(square[3]==square[8] && square[8]==square[13] && square[13]==square[18])
        return 1;
    else if(square[8]==square[13] && square[13]==square[18] && square[18]==square[23])
        return 1;
        //col 4
    else if(square[4]==square[9] && square[9]==square[14] && square[14]==square[19])
        return 1;
    else if(square[9]==square[14] && square[14]==square[19] && square[19]==square[24])
        return 1;
        //col 5
    else if(square[5]==square[10] && square[10]==square[15] && square[15]==square[20])
        return 1;
    else if(square[10]==square[15] && square[15]==square[20] && square[20]==square[25])
        return 1;

    //Checking Diagonal Rows
    //left diagonals - d1,d2,d3,d4
    //right diagonals - d5,d6,d7,d8
        //d1
    else if(square[2]==square[8] && square[8]==square[14] && square[14]==square[20])
        return 1;
        //d2
    else if(square[1]==square[7] && square[7]==square[13] && square[13]==square[19])
        return 1;
        //d3
    else if(square[7]==square[13] && square[13]==square[19] && square[19]==square[25])
        return 1;
        //d4
    else if(square[6]==square[12] && square[12]==square[18] && square[18]==square[24])
        return 1;
        //d5
    else if(square[4]==square[8] && square[8]==square[12] && square[12]==square[16])
        return 1;
        //d6
    else if(square[5]==square[9] && square[9]==square[13] && square[13]==square[17])
        return 1;
        //d7
    else if(square[9]==square[13] && square[13]==square[17] && square[17]==square[21])
        return 1;
        //d8
    else if(square[10]==square[14] && square[14]==square[18] && square[18]==square[22])
        return 1;

    //Checking for Match Draw
    else if(square[1]!=1  && square[2]!=2 && square[3]!=3 && square[4]!=4 &&
            square[5]!=5 && square[6]!=6 && square[7]!=7 && square[8]!=8 &&
            square[9]!=9 && square[10]!=10 && square[11]!=11 && square[12]!=12 &&
            square[13]!=13 && square[14]!=14 && square[15]!=15 && square[16]!=16 &&
            square[17]!=17 && square[18]!=18 && square[19]!=19 && square[20]!=20 &&
            square[21]!=21 && square[22]!=22 && square[23]!=23 && square[24]!=24 &&
            square[25]!=25)
        return 0;
    //Continuing the Game
    else
        return -1;
}
void TTT::drawboard(){
    system("cls");
    cout<<endl<<endl<<"Tic Tac Toe - 5x5 Multiplayer"<<endl;
    cout<<"Game Objective : First person to get 4-in-a-row to Win"<<endl<<endl;
    cout<<p1<<" (X) and "<<p2<<" (O)"<<endl<<endl<<endl;
    //5x5 Tic Tac Toe Board Starts
    cout<<"        |        |        |        |\n";
    for(int i=1;i<26;i++){
        if(i>=1 && i<=10){
            if(square[i]=='X' || square[i]=='O'){
                if(i%5==0)
                    cout<<"    "<<char(square[i]);
                else
                    cout<<"    "<<char(square[i])<<"   |";
            }else if(i%5==0)
                cout<<"    "<<square[i];
            else
                cout<<"    "<<square[i]<<"   |";
            if(i%5==0){
                cout<<endl<<"________|________|________|________|________";
                cout<<endl<<"        |        |        |        |"<<endl;
            }
        }else if(i>=11 && i<=20){
            if(square[i]=='X' || square[i]=='O'){
                if(i%5==0)
                    cout<<"    "<<char(square[i]);
                else
                    cout<<"    "<<char(square[i])<<"   |";
            }else if(i%5==0)
                cout<<"    "<<square[i];
            else
                cout<<"    "<<square[i]<<"  |";
            if(i%5==0){
                cout<<endl<<"________|________|________|________|________"<<endl;
                cout<<"        |        |        |        |"<<endl;
            }
        }else{
            if(square[i]=='X' || square[i]=='O'){
                if(i%5==0)
                    cout<<"    "<<char(square[i]);
                else
                    cout<<"    "<<char(square[i])<<"   |";
            }else if(i%5==0)
                cout<<"    "<<square[i];
            else
                cout<<"    "<<square[i]<<"  |";
            if(i%5==0){
                cout<<endl<<"        |        |        |        |"<<endl;
            }
        }
    }
}
char TTT::change(int choice,int player){
    char mark=(player==1)?'X':'O';
    if(choice==1 && square[1]==1){
        square[1]=mark;
    }else if(choice==2 && square[2]==2){
        square[2]=mark;
    }else if(choice==3 && square[3]==3){
        square[3]=mark;
    }else if(choice==4 && square[4]==4){
        square[4]=mark;
    }else if(choice==5 && square[5]==5){
        square[5]=mark;
    }else if(choice==6 && square[6]==6){
        square[6]=mark;
    }else if(choice==7 && square[7]==7){
        square[7]=mark;
    }else if(choice==8 && square[8]==8){
        square[8]=mark;
    }else if(choice==9 && square[9]==9){
        square[9]=mark;
    }else if(choice==10 && square[10]==10){
        square[10]=mark;
    }else if(choice==11 && square[11]==11){
        square[11]=mark;
    }else if(choice==12 && square[12]==12){
        square[12]=mark;
    }else if(choice==13 && square[13]==13){
        square[13]=mark;
    }else if(choice==14 && square[14]==14){
        square[14]=mark;
    }else if(choice==15 && square[15]==15){
        square[15]=mark;
    }else if(choice==16 && square[16]==16){
        square[16]=mark;
    }else if(choice==17 && square[17]==17){
        square[17]=mark;
    }else if(choice==18 && square[18]==18){
        square[18]=mark;
    }else if(choice==19 && square[19]==19){
        square[19]=mark;
    }else if(choice==20 && square[20]==20){
        square[20]=mark;
    }else if(choice==21 && square[21]==21){
        square[21]=mark;
    }else if(choice==22 && square[22]==22){
        square[22]=mark;
    }else if(choice==23 && square[23]==23){
        square[23]=mark;
    }else if(choice==24 && square[24]==24){
        square[24]=mark;
    }else if(choice==25 && square[25]==25){
        square[25]=mark;
    }else if(choice>25 || choice<0){
        cout<<"Oops! Invalid Input!\nPress any key to continue!";
        player--;
        getch();
    }else{
        cout<<"Oops! Position already taken!\nPress any key to continue!";
        player--;
        getch();
    }
    return mark;
}

int main(){
    int i,choice,c;
    char mark;
    while(1){
        start:
        system("cls");
        cout<<endl<<endl<<"Tic Tac Toe - 5x5 Multiplayer"<<endl;
        cout<<"==============================="<<endl;
        cout<<"(1) Start Game"<<endl<<"(2) View Previous Winners"<<endl<<"(3) Exit Game"<<endl;
        cout<<"==============================="<<endl;
        cout<<"Enter your choice (1/2/3) :";
        cin>>c;
        if(c==2){
            viewScores();
        }else if(c==3){
            return 0;
        }else if(c==1){
            TTT t;
            player=1;
            /* Getting name input of player 1 and player 2 names */
            t.getNames();
            do{
                t.drawboard();
                player=(player%2)?1:2;
                if(player==1)
                    cout<<p1<<", Enter your choice : ";
                else if(player==2)
                    cout<<p2<<", Enter your choice : ";
                cin>>choice;
                mark=t.change(choice,player);
                i=t.checkWin();
                player++;
            }while(i==-1);

            t.drawboard();
            if(i==1){
                --player;
                if(player==1){
                    cout<<endl<<"====> "<<p1<<" won!!";
                    writeScores(p1);
                }else if(player==2){
                    cout<<endl<<"====> "<<p2<<" won!!";
                    writeScores(p2);
                }
                cout<<endl<<"Press any key!";
                getch();
            }else{
                cout<<endl<<"====> Match Draw!!";
                cout<<endl<<"Press any key!";
                getch();
            }
        }else{
            cout<<endl<<"Invalid Input! Try Again!"<<endl;
            getch();
            goto start;
        }
    }
}
