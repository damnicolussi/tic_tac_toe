#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

void init(int m[3][3]){
  for(int i=0; i<3; i++){ 
      for(int j=0; j<3; j++){ 
          m[i][j]=0;
      }       
   }  
} 

void print(int m[3][3]){
   cout<<"     1   2   3  "<<endl;
   cout<<"   +---+---+---+"<<endl; 
   for(int i=0; i<3; i++){
   	  cout<<i+1<<" ";
      for(int j=0; j<3; j++){ 
          cout << " | ";
          if(m[i][j]==0) cout<<" ";
          if(m[i][j]==1) cout<<"X";
          if(m[i][j]==2) cout<<"0";
      }
      cout<<" | "<< endl<<"   +---+---+---+"<<endl;
   }
}

void play(int m[3][3], int g){
   int x,y;
   do{
   	if(g==1)  	cout<<"'X' Where do you want to place your token?"<<endl;
   	else if(g==2) 	cout<<"'0' Where do you want to place your token?"<<endl;
    cout<<"row: "; cin>>x;
	cout<<"column: "; cin>>y;
	cout<<endl;
	if(m[x-1][y-1]!=0) cout<<"----------------- Retry! -----------------"<<endl;
   }
   while(m[x-1][y-1]!=0);
   m[x-1][y-1] = g;
}

int win(int m[3][3]){
   for(int i=0; i<3; i++)
       if(m[i][0]==m[i][1] and m[i][0]==m[i][2] and m[i][0]!=0 ) return m[i][0];
   
   for(int i=0; i<3; i++)
       if(m[0][i]==m[1][i] and m[0][i]==m[2][i] and m[0][i]!=0 ) return m[0][i];
   
       if(m[0][0]==m[1][1] and m[0][0]==m[2][2] and m[0][0]!=0 ) return m[0][0];
       if(m[0][2]==m[1][1] and m[0][2]==m[2][0] and m[0][2]!=0 ) return m[0][2];
   
   return 0;     
}


int main(){
   
   int m[3][3];
   int plays=0, player=1, winner;
   
   cout<<"+-------------------------------------------------------+"<<endl;
   cout<<"|                     WELCOME TO                        |"<<endl;
   cout<<"| -----  .  +---    ----- +---+ +---   ----- +---+ +--- |"<<endl;
   cout<<"|   |    |  |         |   |___| |        |   |   | |___ |"<<endl;
   cout<<"|   |    |  |         |   |   | |        |   |   | |    |"<<endl;
   cout<<"|   |    |  |___      |   |   | |___     |   |___| |___ |"<<endl;
   cout<<"|                     C++ VERSION                       |"<<endl;
   cout<<"|                                                       |"<<endl;
   cout<<"|    source code: github.com/damnicolussi/tic_tac_toe   |"<<endl;
   cout<<"+-------------------------------------------------------+"<<endl;
   cout<<endl;
   
   init(m);
   
   print(m);
   
   do{
       play(m, player);  
       print(m);
       if(player==1) player=2; else player=1; 
       winner=win(m);
    
       plays++;
   }while(plays<9 and winner==0);
 
   
   if(winner==1) {
       cout<<"Good Job X you have won! :)"<<endl;
   }
   else if(winner==2) {
       cout<<"Good Job 0 you have won! :)"<<endl;
   }
   else{
       cout<<"No one has won! :("<<endl;
   }
   
}
