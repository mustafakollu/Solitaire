#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
string pile1[52];                           //global variables
string stock[24];
string waste[24];
string temple;
int coin=0;
int topi=0;
int topj=0;
int topS=0;
int top0=0;
int top1=1;
int top2=2;
int top3=3;
int top4=4;
int top5=5;
int top6=6;
int top00=0;
int top11=1;
int top22=2;
int top33=3;
int top44=4;
int top55=5;
int top66=6;
string tableArea[19][7];
string stockArea="@@@";
string waste1="___";
string waste2="___";
string waste3="___";
string heart="___";
string diamond="___";
string spade="___";
string club="___";
ofstream fout("output.txt");                          //It's create output.txt
void addTable(string card){
    if (topj==7){
        topi++;
        topj=topi;
    }
    if (topi==0){
        tableArea[topi][topj]=card;
        topj++;
    }
    if (topi==1){
        tableArea[topi][topj]=card;
        topj++;
    }
    if (topi==2){
        tableArea[topi][topj]=card;
        topj++;
    }
    if (topi==3){
        tableArea[topi][topj]=card;
        topj++;
    }
    if (topi==4){
        tableArea[topi][topj]=card;
        topj++;
    }
    if (topi==5){
        tableArea[topi][topj]=card;
        topj++;
    }
    if (topi==6){
        tableArea[topi][topj]=card;
        topj++;
    }
}                       // add card in deck to pileArray

void add2(string card){
    ++topS;
    stock[topS]=card;
}                           // add card in deck to stock
int check(string card){
    if(card.substr(1,2).compare("01")!=0&&heart.compare("___")==0){
        fout << "Invalid Move!"<<endl;
        return 3;
    }
    if(card.substr(1,2).compare("01")!=0&&diamond.compare("___")==0){
        fout << "Invalid Move!"<<endl;
        return 3;
    }
    if(card.substr(1,2).compare("01")!=0&&spade.compare("___")==0){
        fout << "Invalid Move!"<<endl;
        return 3;
    }
    if(card.substr(1,2).compare("01")!=0&&club.compare("___")==0){
        fout << "Invalid Move!"<<endl;
        return 3;
    }
    if(card.substr(1,2).compare("01")!=0&&card.substr(0,1).compare("H")==0){
        int y = stoi(heart.substr(1,2));
        int u = stoi(card.substr(1,2));
        if(u!=y+1){
            fout << "Invalid Move!"<<endl;
            return 3;
        }
    }
    if(card.substr(1,2).compare("01")!=0&&card.substr(0,1).compare("D")==0){
        int y = stoi(diamond.substr(1,2));
        int u = stoi(card.substr(1,2));
        if(u!=y+1){
            fout << "Invalid Move!"<<endl;
            return 3;
        }
    }
    if(card.substr(1,2).compare("01")!=0&&card.substr(0,1).compare("S")==0){
        int y = stoi(spade.substr(1,2));
        int u = stoi(card.substr(1,2));
        if(u!=y+1){
            fout << "Invalid Move!"<<endl;
            return 3;
        }
    }
    if(card.substr(1,2).compare("01")!=0&&card.substr(0,1).compare("C")==0){
        int y = stoi(club.substr(1,2));
        int u = stoi(card.substr(1,2));
        if(u!=y+1){
            fout << "Invalid Move!"<<endl;
            return 3;
        }
    }
}                           //It's checking to error like Hearts to Diamonds
int check2(string card,string card2){
    if(card.substr(0,1).compare("H")==0){
        if(card2.substr(0,1).compare("D")==0){
            fout << "Invalid Move!"<<endl;
            return 4;
        }
        else if(card2.substr(0,1).compare("H")==0){
            fout << "Invalid Move!"<<endl;
            return 4;
        }
        else{
            int y = stoi(card.substr(1,2));
            int u = stoi(card2.substr(1,2));
            if (u!=y+1){
                fout << "Invalid Move!"<<endl;
                return 4;
            }
        }
    }
    if(card.substr(0,1).compare("D")==0){
        if(card2.substr(0,1).compare("H")==0){
            fout << "Invalid Move!"<<endl;
            return 4;
        }
        else if(card2.substr(0,1).compare("D")==0){
            fout << "Invalid Move!"<<endl;
            return 4;
        }
        else{
            int y = stoi(card.substr(1,2));
            int u = stoi(card2.substr(1,2));
            if (u!=y+1){
                fout << "Invalid Move!"<<endl;
                return 4;
            }
        }
    }
    if(card.substr(0,1).compare("S")==0){
        if(card2.substr(0,1).compare("C")==0){
            fout << "Invalid Move!"<<endl;
            return 4;
        }
        else if(card2.substr(0,1).compare("S")==0){
            fout << "Invalid Move!"<<endl;
            return 4;
        }
        else{
            int y = stoi(card.substr(1,2));
            int u = stoi(card2.substr(1,2));
            if (u!=y+1){
                fout << "Invalid Move!"<<endl;
                return 4;
            }
        }
    }
    if(card.substr(0,1).compare("C")==0){
        if(card2.substr(0,1).compare("S")==0){
            fout << "Invalid Move!"<<endl;
            return 4;
        }
        else if(card2.substr(0,1).compare("C")==0){
            fout << "Invalid Move!"<<endl;
            return 4;
        }
        else{
            int y = stoi(card.substr(1,2));
            int u = stoi(card2.substr(1,2));
            if (u!=y+1){
                fout << "Invalid Move!"<<endl;
                return 4;
            }
        }
    }
}             //It's checking to error like Hearts to Diamonds
void show2(){
    int deger=0;
    if(top0>=top1&&top0>=top2&&top0>=top3&&top0>=top4&&top0>=top5&&top0>=top6){
        deger=top0;
    }
    else if(top1>=top0&&top1>=top2&&top1>=top3&&top1>=top4&&top1>=top5&&top1>=top6){
        deger=top1;
    }
    else if(top2>=top0&&top2>=top1&&top2>=top3&&top2>=top4&&top2>=top5&&top2>=top6){
        deger=top2;
    }
    else if(top3>=top0&&top3>=top1&&top3>=top2&&top3>=top4&&top3>=top5&&top3>=top6){
        deger=top3;
    }
    else if(top4>=top0&&top4>=top1&&top4>=top2&&top4>=top3&&top4>=top5&&top4>=top6){
        deger=top4;
    }
    else if(top5>=top0&&top5>=top1&&top5>=top2&&top5>=top3&&top5>=top4&&top5>=top6){
        deger=top5;
    }
    else if(top6>=top0&&top6>=top1&&top6>=top2&&top6>=top3&&top6>=top4&&top6>=top5){
        deger=top6;
    }

    fout << stockArea+" "+waste1+" "+waste2+" "+waste3+"         "+heart+" "+diamond+" "+spade+" "+club;
    fout << endl;
    for(int h=0;h<deger+1;h++){
        if(h==0){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==1){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==2){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==3){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==4){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==5){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==6){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==7){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==8){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==9){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==10){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==11){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==12){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==13){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==14){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==15){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==16){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==17){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }
        if(h==18){
            if(h<=top0){
                if(h<top00){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][0]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top1){
                if(h<top11){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][1]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top2){
                if(h<top22){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][2]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top3){
                if(h<top33){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][3]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top4){

                if(h<top44){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][4]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top5){
                if(h<top55){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][5]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            if(h<=top6){
                if(h<top66){
                    fout << "@@@" << "   ";
                }
                else{
                    fout << tableArea[h][6]<<"   ";
                }
            }
            else{
                fout << "      ";
            }
            fout<<endl;
        }

    }
    fout << endl;
}                                     //It's printing Tableau Area
void read(string arr){
    ifstream readFile(arr);
    string line;

    if ( readFile.is_open() ){
        int i=0;
        while ( getline(readFile, line) ){
            pile1[51-i].append(line,0,3);
            i++;
        }
        readFile.close();
        int sizeA = sizeof(pile1)/sizeof(pile1[0]);
        for(int j=0;j<sizeA;j++){
            if (j<=27){
                addTable(pile1[j]);
            }
            else{
                add2(pile1[j]);
            }
        }
    }
}                            //It's reading deck.txt

int main(int argc, char *argv[]){

    read(argv[1]);
    fout << endl;
    show2();
    ifstream readFile2(argv[2]);                      //It's reading commands.txt
    string line2;
    if ( readFile2.is_open() ) {
        while (getline(readFile2, line2)) {
            if (line2.find("exit")==0){
                fout << line2<<endl;
                fout << endl;
                fout << "****************************************" << endl;
                fout << endl;
                fout << "Game Over";
                fout << endl;
            }              // exit command
            else if(line2.find("waste")==19){
                fout << line2<<endl;
                fout << endl;
                fout << "****************************************" << endl;
                fout << endl;
                //işlem
                show2();
            }           // move to foundation waste command
            else if(line2.find("waste")==5){
                fout << line2<<endl;
                fout << endl;
                fout << "****************************************" << endl;
                fout << endl;
                //işlem
                show2();
            }            // move waste command
            else if(line2.find("pile")==5){
                fout << line2<<endl;
                fout << endl;
                if(line2.find("0")==10){
                    if(line2.find("1")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top0-g][0],tableArea[top1][1])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top0;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top1+1][1]=tableArea[i][0];
                                top1++;
                                top0--;
                                coin=1;
                                top00--;
                                temple="top00";
                            }
                            top00++;
                            show2();
                        }
                    }
                    if(line2.find("2")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top0-g][0],tableArea[top2][2])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top0;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top2+1][2]=tableArea[i][0];
                                top2++;
                                top0--;
                                coin=1;
                                top00--;
                                temple="top00";
                            }
                            top00++;
                            show2();
                        }
                    }
                    if(line2.find("3")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top0-g][0],tableArea[top3][3])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top0;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top3+1][3]=tableArea[i][0];
                                top3++;
                                top0--;
                                coin=1;
                                top00--;
                                temple="top00";
                            }
                            top00++;
                            show2();
                        }
                    }
                    if(line2.find("4")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top0-g][0],tableArea[top4][4])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top0;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top4+1][4]=tableArea[i][0];
                                top4++;
                                top0--;
                                coin=1;
                                top00--;
                                temple="top00";
                            }
                            top00++;
                            show2();
                        }
                    }
                    if(line2.find("5")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top0-g][0],tableArea[top5][5])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top0;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top5+1][5]=tableArea[i][0];
                                top5++;
                                top0--;
                                coin=1;
                                top00--;
                                temple="top00";
                            }
                            top00++;
                            show2();
                        }
                    }
                    if(line2.find("6")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top0-g][0],tableArea[top6][6])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top0;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top6+1][6]=tableArea[i][0];
                                top6++;
                                top0--;
                                coin=1;
                                top00--;
                                temple="top00";
                            }
                            top00++;
                            show2();
                        }
                    }
                }
                if(line2.find("1")==10){
                    if(line2.find("0")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top1-g][1],tableArea[top0][0])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top1;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top0+1][0]=tableArea[i][1];
                                top0++;
                                top1--;
                                coin=1;
                                top11--;
                                temple="top11";
                            }
                            top11++;
                            show2();
                        }
                    }
                    if(line2.find("2")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top1-g][1],tableArea[top2][2])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top1;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top2+1][2]=tableArea[i][1];
                                top2++;
                                top1--;
                                coin=1;
                                top11--;
                                temple="top11";
                            }
                            top11++;
                            show2();
                        }
                    }
                    if(line2.find("3")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top1-g][1],tableArea[top3][3])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top1;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top3+1][3]=tableArea[i][1];
                                top3++;
                                top1--;
                                coin=1;
                                top11--;
                                temple="top11";
                            }
                            top11++;
                            show2();
                        }
                    }
                    if(line2.find("4")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top1-g][1],tableArea[top4][4])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top1;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top4+1][4]=tableArea[i][1];
                                top4++;
                                top1--;
                                coin=1;
                                top11--;
                                temple="top11";
                            }
                            top11++;
                            show2();
                        }
                    }
                    if(line2.find("5")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top1-g][1],tableArea[top5][5])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top1;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top5+1][5]=tableArea[i][1];
                                top5++;
                                top1--;
                                coin=1;
                                top11--;
                                temple="top11";
                            }
                            top11++;
                            show2();
                        }
                    }
                    if(line2.find("6")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top1-g][1],tableArea[top6][6])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top1;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top6+1][6]=tableArea[i][1];
                                top6++;
                                top1--;
                                coin=1;
                                top11--;
                                temple="top11";
                            }
                            top11++;
                            show2();
                        }
                    }
                }
                if(line2.find("2")==10){
                    if(line2.find("0")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top2-g][2],tableArea[top0][0])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top2;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top0+1][0]=tableArea[i][2];
                                top0++;
                                top2--;
                                coin=1;
                                top22--;
                                temple="top22";
                            }
                            top22++;
                            show2();
                        }
                    }
                    if(line2.find("1")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top2-g][2],tableArea[top1][1])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top2;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top1+1][1]=tableArea[i][2];
                                top1++;
                                top2--;
                                coin=1;
                                top22--;
                                temple="top22";
                            }
                            top22++;
                            show2();
                        }
                    }
                    if(line2.find("3")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top2-g][2],tableArea[top3][3])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top2;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top3+1][3]=tableArea[i][2];
                                top3++;
                                top2--;
                                coin=1;
                                top22--;
                                temple="top22";
                            }
                            top22++;
                            show2();
                        }
                    }
                    if(line2.find("4")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top2-g][2],tableArea[top4][4])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top2;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top4+1][4]=tableArea[i][2];
                                top4++;
                                top2--;
                                coin=1;
                                top22--;
                                temple="top22";
                            }
                            top22++;
                            show2();
                        }
                    }
                    if(line2.find("5")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top2-g][2],tableArea[top5][5])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top2;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top5+1][5]=tableArea[i][2];
                                top5++;
                                top2--;
                                coin=1;
                                top22--;
                                temple="top22";
                            }
                            top22++;
                            show2();
                        }
                    }
                    if(line2.find("6")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top2-g][2],tableArea[top6][6])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top2;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top6+1][6]=tableArea[i][2];
                                top6++;
                                top2--;
                                coin=1;
                                top22--;
                                temple="top22";
                            }
                            top22++;
                            show2();
                        }
                    }
                }
                if(line2.find("3")==10){
                    if(line2.find("0")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top3-g][3],tableArea[top0][0])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top3;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top0+1][0]=tableArea[i][3];
                                top0++;
                                top3--;
                                coin=1;
                                top33--;
                                temple="top33";
                            }
                            top33++;
                            show2();
                        }
                    }
                    if(line2.find("1")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top3-g][3],tableArea[top1][1])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top3;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top1+1][1]=tableArea[i][3];
                                top1++;
                                top3--;
                                coin=1;
                                top33--;
                                temple="top33";
                            }
                            top33++;
                            show2();
                        }
                    }
                    if(line2.find("2")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top3-g][3],tableArea[top2][2])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top3;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top2+1][2]=tableArea[i][3];
                                top2++;
                                top3--;
                                coin=1;
                                top33--;
                                temple="top33";
                            }
                            top33++;
                            show2();
                        }
                    }
                    if(line2.find("4")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top3-g][3],tableArea[top4][4])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top3;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top4+1][4]=tableArea[i][3];
                                top4++;
                                top3--;
                                coin=1;
                                top33--;
                                temple="top33";
                            }
                            top33++;
                            show2();
                        }
                    }
                    if(line2.find("5")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top3-g][3],tableArea[top5][5])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top3;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top5+1][5]=tableArea[i][3];
                                top5++;
                                top3--;
                                coin=1;
                                top33--;
                                temple="top33";
                            }
                            top33++;
                            show2();
                        }
                    }
                    if(line2.find("6")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top3-g][3],tableArea[top6][6])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top3;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top6+1][6]=tableArea[i][3];
                                top6++;
                                top3--;
                                coin=1;
                                top33--;
                                temple="top33";
                            }
                            top33++;
                            show2();
                        }
                    }
                }
                if(line2.find("4")==10){
                    if(line2.find("0")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top4-g][4],tableArea[top0][0])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top4;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top0+1][0]=tableArea[i][4];
                                top0++;
                                top4--;
                                coin=1;
                                top44--;
                                temple="top44";
                            }
                            top44++;
                            show2();
                        }
                    }
                    if(line2.find("1")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top4-g][4],tableArea[top1][1])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top4;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top1+1][1]=tableArea[i][4];
                                top1++;
                                top4--;
                                coin=1;
                                top44--;
                                temple="top44";
                            }
                            top44++;
                            show2();
                        }
                    }
                    if(line2.find("2")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top4-g][4],tableArea[top2][2])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top4;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top2+1][2]=tableArea[i][4];
                                top2++;
                                top4--;
                                coin=1;
                                top44--;
                                temple="top44";
                            }
                            top44++;
                            show2();
                        }
                    }
                    if(line2.find("3")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top4-g][4],tableArea[top3][3])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top4;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top3+1][3]=tableArea[i][4];
                                top3++;
                                top4--;
                                coin=1;
                                top44--;
                                temple="top44";
                            }
                            top44++;
                            show2();
                        }
                    }
                    if(line2.find("5")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top4-g][4],tableArea[top5][5])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top4;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top5+1][5]=tableArea[i][4];
                                top5++;
                                top4--;
                                coin=1;
                                top44--;
                                temple="top44";
                            }
                            top44++;
                            show2();
                        }
                    }
                    if(line2.find("6")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top4-g][4],tableArea[top6][6])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top4;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top6+1][6]=tableArea[i][4];
                                top6++;
                                top4--;
                                coin=1;
                                top44--;
                                temple="top44";
                            }
                            top44++;
                            show2();
                        }
                    }
                }
                if(line2.find("5")==10){
                    if(line2.find("0")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top5-g][5],tableArea[top0][0])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top5;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top0+1][0]=tableArea[i][5];
                                top0++;
                                top5--;
                                coin=1;
                                top55--;
                                temple="top55";
                            }
                            top55++;
                            show2();
                        }
                    }
                    if(line2.find("1")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top5-g][5],tableArea[top1][1])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top5;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top1+1][1]=tableArea[i][5];
                                top1++;
                                top5--;
                                coin=1;
                                top55--;
                                temple="top55";
                            }
                            top55++;
                            show2();
                        }
                    }
                    if(line2.find("2")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top5-g][5],tableArea[top2][2])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top5;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top2+1][2]=tableArea[i][5];
                                top2++;
                                top5--;
                                coin=1;
                                top55--;
                                temple="top55";
                            }
                            top55++;
                            show2();
                        }
                    }
                    if(line2.find("3")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top5-g][5],tableArea[top3][3])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top5;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top3+1][3]=tableArea[i][5];
                                top3++;
                                top5--;
                                coin=1;
                                top55--;
                                temple="top55";
                            }
                            top55++;
                            show2();
                        }
                    }
                    if(line2.find("4")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top5-g][5],tableArea[top4][4])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top5;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top4+1][4]=tableArea[i][5];
                                top4++;
                                top5--;
                                coin=1;
                                top55--;
                                temple="top55";
                            }
                            top55++;
                            show2();
                        }
                    }
                    if(line2.find("6")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top5-g][5],tableArea[top6][6])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top5;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top6+1][6]=tableArea[i][5];
                                top6++;
                                top5--;
                                coin=1;
                                top55--;
                                temple="top55";
                            }
                            top55++;
                            show2();
                        }
                    }
                }
                if(line2.find("6")==10){
                    if(line2.find("0")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top6-g][6],tableArea[top0][0])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top6;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top0+1][0]=tableArea[i][6];
                                top0++;
                                top6--;
                                coin=1;
                                top66--;
                                temple="top66";
                            }
                            top66++;
                            show2();
                        }
                    }
                    if(line2.find("1")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top6-g][6],tableArea[top1][1])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top6;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top1+1][1]=tableArea[i][6];
                                top1++;
                                top6--;
                                coin=1;
                                top66--;
                                temple="top66";
                            }
                            top66++;
                            show2();
                        }
                    }
                    if(line2.find("2")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top6-g][6],tableArea[top2][2])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top6;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top2+1][2]=tableArea[i][6];
                                top2++;
                                top6--;
                                coin=1;
                                top66--;
                                temple="top66";
                            }
                            top66++;
                            show2();
                        }
                    }
                    if(line2.find("3")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top6-g][6],tableArea[top3][3])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top6;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top3+1][3]=tableArea[i][6];
                                top3++;
                                top6--;
                                coin=1;
                                top66--;
                                temple="top66";
                            }
                            top66++;
                            show2();
                        }
                    }
                    if(line2.find("4")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top6-g][6],tableArea[top4][4])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top6;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top4+1][4]=tableArea[i][6];
                                top4++;
                                top6--;
                                coin=1;
                                top66--;
                                temple="top66";
                            }
                            top66++;
                            show2();
                        }
                    }
                    if(line2.find("5")==14){
                        int g= stoi(line2.substr(12,1));
                        if(check2(tableArea[top6-g][6],tableArea[top5][5])==4){
                            fout << endl;
                            fout << "****************************************" << endl;
                            fout << endl;
                            show2();
                        }
                        else{
                            fout << "****************************************" << endl;
                            fout << endl;
                            int j=top6;
                            for (int i=j-g;i<j+1;i++){
                                tableArea[top5+1][5]=tableArea[i][6];
                                top6++;
                                top3--;
                                coin=1;
                                top66--;
                                temple="top66";
                            }
                            top66++;
                            show2();
                        }
                    }
                }
            }             // move pile command
            else if(line2.find("pile")==19){
                fout << line2<<endl;
                fout << endl;
                if(line2.find("6")==24){
                    if(check(tableArea[top6][6])==3){
                        fout << endl;
                        fout << "****************************************" << endl;
                        fout << endl;
                        show2();
                    }
                    else{
                        fout << "****************************************" << endl;
                        fout << endl;
                        if(tableArea[top6][6].substr(0,1).compare("D")==0){
                            diamond=tableArea[top6][6];
                            top6--;
                            show2();
                            temple="top66";
                            coin++;
                        }
                        if(tableArea[top6][6].substr(0,1).compare("H")==0){
                            heart=tableArea[top6][6];
                            top6--;
                            show2();
                            temple="top66";
                            coin++;
                        }
                        if(tableArea[top6][6].substr(0,1).compare("C")==0){
                            club=tableArea[top6][6];
                            top6--;
                            show2();
                            temple="top66";
                            coin++;
                        }
                        if(tableArea[top6][6].substr(0,1).compare("S")==0){
                            spade=tableArea[top6][6];
                            top6--;
                            show2();
                            temple="top66";
                            coin++;
                        }
                    }

                }
                if(line2.find("5")==24){
                    if(check(tableArea[top5][5])==3){
                        fout << endl;
                        fout << "****************************************" << endl;
                        fout << endl;
                        show2();
                        coin++;
                    }
                    else{
                        fout << "****************************************" << endl;
                        fout << endl;
                        if(tableArea[top5][5].substr(0,1).compare("D")==0){
                            diamond=tableArea[top5][5];
                            top5--;
                            show2();
                            temple="top55";
                            coin++;
                        }
                        if(tableArea[top5][5].substr(0,1).compare("H")==0){
                            heart=tableArea[top5][5];
                            top5--;
                            show2();
                            temple="top55";
                            coin++;
                        }
                        if(tableArea[top5][5].substr(0,1).compare("C")==0){
                            club=tableArea[top5][5];
                            top5--;
                            show2();
                            temple="top55";
                            coin++;
                        }
                        if(tableArea[top5][5].substr(0,1).compare("S")==0){
                            spade=tableArea[top5][5];
                            top5--;
                            show2();
                            temple="top55";
                            coin++;
                        }
                    }

                }
                if(line2.find("4")==24){
                    if(check(tableArea[top4][4])==3){
                        fout << endl;
                        fout << "****************************************" << endl;
                        fout << endl;
                        show2();
                    }
                    else{
                        fout << "****************************************" << endl;
                        fout << endl;
                        if(tableArea[top4][4].substr(0,1).compare("D")==0){
                            diamond=tableArea[top4][4];
                            top4--;
                            show2();
                            temple="top44";
                            coin++;
                        }
                        if(tableArea[top4][4].substr(0,1).compare("H")==0){
                            heart=tableArea[top4][4];
                            top4--;
                            show2();
                            temple="top44";
                            coin++;
                        }
                        if(tableArea[top4][4].substr(0,1).compare("C")==0){
                            club=tableArea[top4][4];
                            top4--;
                            show2();
                            temple="top44";
                            coin++;
                        }
                        if(tableArea[top4][4].substr(0,1).compare("S")==0){
                            spade=tableArea[top4][4];
                            top4--;
                            show2();
                            temple="top44";
                            coin++;
                        }
                    }

                }
                if(line2.find("3")==24){
                    if(check(tableArea[top3][3])==3){
                        fout << endl;
                        fout << "****************************************" << endl;
                        fout << endl;
                        show2();
                    }
                    else{
                        fout << "****************************************" << endl;
                        fout << endl;
                        if(tableArea[top3][3].substr(0,1).compare("D")==0){
                            diamond=tableArea[top3][3];
                            top3--;
                            show2();
                            temple="top33";
                            coin++;
                        }
                        if(tableArea[top3][3].substr(0,1).compare("H")==0){
                            heart=tableArea[top3][3];
                            top3--;
                            show2();
                            temple="top33";
                            coin++;
                        }
                        if(tableArea[top3][3].substr(0,1).compare("C")==0){
                            club=tableArea[top3][3];
                            top3--;
                            show2();
                            temple="top33";
                            coin++;
                        }
                        if(tableArea[top3][3].substr(0,1).compare("S")==0){
                            spade=tableArea[top3][3];
                            top3--;
                            show2();
                            temple="top33";
                            coin++;
                        }
                    }

                }
                if(line2.find("2")==24){
                    if(check(tableArea[top2][2])==3){
                        fout << endl;
                        fout << "****************************************" << endl;
                        fout << endl;
                        show2();
                    }
                    else{
                        fout << "****************************************" << endl;
                        fout << endl;
                        if(tableArea[top2][2].substr(0,1).compare("D")==0){
                            diamond=tableArea[top2][2];
                            top2--;
                            show2();
                            temple="top22";
                            coin++;
                        }
                        if(tableArea[top2][2].substr(0,1).compare("H")==0){
                            heart=tableArea[top2][2];
                            top2--;
                            show2();
                            temple="top22";
                            coin++;
                        }
                        if(tableArea[top2][2].substr(0,1).compare("C")==0){
                            club=tableArea[top2][2];
                            top2--;
                            show2();
                            temple="top22";
                            coin++;
                        }
                        if(tableArea[top2][2].substr(0,1).compare("S")==0){
                            spade=tableArea[top2][2];
                            top2--;
                            show2();
                            temple="top22";
                            coin++;
                        }
                    }

                }
                if(line2.find("1")==24){
                    if(check(tableArea[top1][1])==3){
                        fout << endl;
                        fout << "****************************************" << endl;
                        fout << endl;
                        show2();
                    }
                    else{
                        fout << "****************************************" << endl;
                        fout << endl;
                        if(tableArea[top1][1].substr(0,1).compare("D")==0){
                            diamond=tableArea[top1][1];
                            top1--;
                            show2();
                            temple="top11";
                            coin++;
                        }
                        if(tableArea[top1][1].substr(0,1).compare("H")==0){
                            heart=tableArea[top1][1];
                            top1--;
                            show2();
                            temple="top11";
                            coin++;
                        }
                        if(tableArea[top1][1].substr(0,1).compare("C")==0){
                            club=tableArea[top1][1];
                            top1--;
                            show2();
                            temple="top11";
                            coin++;
                        }
                        if(tableArea[top1][1].substr(0,1).compare("S")==0){
                            spade=tableArea[top1][1];
                            top1--;
                            show2();
                            temple="top11";
                            coin++;
                        }
                    }

                }
                if(line2.find("0")==24){
                    if(check(tableArea[top0][0])==3){
                        fout << endl;
                        fout << "****************************************" << endl;
                        fout << endl;
                        show2();
                    }
                    else{
                        fout << "****************************************" << endl;
                        fout << endl;
                        if(tableArea[top0][0].substr(0,1).compare("D")==0){
                            diamond=tableArea[top0][0];
                            top0--;
                            show2();
                            temple="top00";
                            coin++;
                        }
                        if(tableArea[top0][0].substr(0,1).compare("H")==0){
                            heart=tableArea[top0][0];
                            top0--;
                            show2();
                            temple="top00";
                            coin++;
                        }
                        if(tableArea[top0][0].substr(0,1).compare("C")==0){
                            club=tableArea[top0][0];
                            top0--;
                            show2();
                            temple="top00";
                            coin++;
                        }
                        if(tableArea[top0][0].substr(0,1).compare("S")==0){
                            spade=tableArea[top0][0];
                            top0--;
                            show2();
                            temple="top00";
                            coin++;
                        }
                    }

                }
            }            // move to foundation pile command
            else if(line2.find("from")==5){
                fout << line2<<endl;
                fout << endl;
                fout << "****************************************" << endl;
                fout << endl;
                //işlem
                show2();
            }             // open from stock command
            else{
                fout << line2<<endl;
                fout << endl;

                if(coin!=1){
                    fout << "Invalid Move!"<<endl<<endl;
                    fout << "****************************************" << endl;
                    fout << endl;
                    show2();
                }
                else{
                    if(temple.compare("top66")==0){
                        fout << "****************************************" << endl;
                        fout << endl;
                        top66--;
                        show2();
                        coin=0;
                    }
                    if(temple.compare("top55")==0){
                        fout << "****************************************" << endl;
                        fout << endl;
                        top55--;
                        show2();
                        coin=0;
                    }
                    if(temple.compare("top44")==0){
                        fout << "****************************************" << endl;
                        fout << endl;
                        top44--;
                        show2();
                        coin=0;
                    }
                    if(temple.compare("top33")==0){
                        fout << "****************************************" << endl;
                        fout << endl;
                        top33--;
                        show2();
                        coin=0;
                    }
                    if(temple.compare("top22")==0){
                        fout << "****************************************" << endl;
                        fout << endl;
                        top22--;
                        show2();
                        coin=0;
                    }
                    if(temple.compare("top11")==0){
                        fout << "****************************************" << endl;
                        fout << endl;
                        top11--;
                        show2();
                        coin=0;
                    }
                    if(temple.compare("top00")==0){
                        fout << "****************************************" << endl;
                        fout << endl;
                        top00--;
                        show2();
                        coin=0;
                    }
                }
            }                                          // open command
        }
        readFile2.close();
    }
    return 0;
}
