#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
void main(){
	clrscr();
	int count1=5,count2=5;
	int posA[5][2],posB[5][2];//positions of each pawn
	for(int i=0;i<5;i++){
		posA[i][0]=posB[i][0]=10*i+1;
		posA[i][1]=5;
		posB[i][1]=1;
	}
	char choice,A[9][5],B[9][5];//move made by the player. press q to quit
	//Show the empty board
	for(i=0;i<5;i++){
		for(int j=0;j<5;j++){
			gotoxy(10*j+1,i+1);
			cout<<"-";
		}
	}
	//adding the pawns
	gotoxy(1,10);
	cout<<"Player A pawns: (max length 10)";
	for(i=0;i<5;i++){
		gotoxy(1,11+i);
		cin>>A[i];
		if(!strcmp(A[i],"exit"))
		{	cout<<"exit cannot be pawn name";
			i--;
			continue;
		}
		gotoxy(10*i+1,5);
		cout<<"A"<<A[i];
	}
	gotoxy(1,16);
	cout<<"Player B pawns: (max length 10)";
	for(i=0;i<5;i++){
		gotoxy(1,17+i);
		cin>>B[i];
		if(!strcmp(B[i],"exit"))
		{	cout<<"exit cannot be pawn name";
			i--;
			continue;
		}
		gotoxy(10*i+1,1);
		cout<<"B"<<B[i];
	}
	char name[9];
	do{//!!!!!type exit to quit instead!!!!!
	    int pos=0;
	    int flag=0;
	    int temp;
	    do{
	    do{
	    clrscr();
	    for(i=0;i<5;i++){
		for(int j=0;j<5;j++){
			gotoxy(10*j+1,i+1);
			cout<<"-";
		}
	    }
	    for(i=0;i<5;i++){
		if(posA[i][0]!=-1)//Pawn is not out
		{	gotoxy(posA[i][0],posA[i][1]);
			cout<<"A"<<A[i];
		}
		if(posB[i][0]!=-1)
		{
			gotoxy(posB[i][0],posB[i][1]);
			cout<<"B"<<B[i];
		}
	    }
	    gotoxy(1,6);
	    cout<<"Type \"exit\" to exit the game";
	    gotoxy(1,12);
	    cout<<"A move:";
	    cin>>name;
	    if(strcmp(name,"exit")==0)
		exit(0);
	    for(pos=0;pos<5;pos++){
		if(strcmp(A[pos],name)==0&&posA[pos][0]!=-1)
			break;
	    }
	    if(pos==5)
	    {	cout<<"Invalid name";
		getch();
	    }
	    }while(pos==5);
	    gotoxy(1,14);
	    cout<<A[pos]<<":";
	    choice=getch();
	    if(choice=='L'||choice=='l'){
		temp=posA[pos][0]-10;
		if(temp<1)
		{	cout<<"Invalid Choice";
			getch();
			continue;
		}
		for(i=0;i<5;i++){
			if(posA[i][0]==temp&&posA[i][1]==posA[pos][1]){
				temp=-1;
				break;
			}
		}
		if(temp==-1)
		{	cout<<"Invalid Choice";
			continue;
		}
		posA[pos][0]-=10;
		for(i=0;i<5;i++){
			if(posB[i][0]==temp&&posB[i][1]==posA[pos][1]){
				posB[i][0]=-1;
				count2--;
				break;
			}
		}
	    }
	    else if(choice=='R'||choice=='r'){
		temp=posA[pos][0]+10;
		if(temp>45)
		{	cout<<"Invalid Choice";
			continue;
		}
		for(i=0;i<5;i++){
			if(posA[i][0]==temp&&posA[i][1]==posA[pos][1]){
				temp=-1;
				break;
			}
		}
		if(temp==-1)
		{	cout<<"Invalid Choice";
			continue;
		}
		posA[pos][0]+=10;
		for(i=0;i<5;i++){
			if(posB[i][0]==posA[pos][0]&&posB[i][1]==posA[pos][1]){
				posB[i][0]=-1;
				count2--;
				break;
			}
		}
	    }
	    else if(choice=='U'||choice=='u'){
		temp=posA[pos][1]-1;
		if(temp<1)
		{	cout<<"Invalid Choice";
			continue;
		}
		for(i=0;i<5;i++){
			if(posA[i][1]==temp&&posA[i][0]==posA[pos][0]){
				temp=-1;
				break;
			}
		}
		if(temp==-1)
		{	cout<<"Invalid Choice";
			continue;
		}
		posA[pos][1]--;
		for(i=0;i<5;i++){
			if(posB[i][0]==posA[pos][0]&&posB[i][1]==posA[pos][1]){
				posB[i][0]=-1;
				count2--;
				break;
			}
		}
	    }
	    else if(choice=='D'||choice=='d'){
		temp=posA[pos][1]+1;
		if(temp>5)
		{	cout<<"Invalid Choice";
			continue;
		}
		for(i=0;i<5;i++){
			if(posA[i][1]==temp&&posA[i][0]==posA[pos][0]){
				temp=-1;
				break;
			}
		}
		if(temp==-1)
		{	cout<<"Invalid Choice";
			continue;
		}
		posA[pos][1]++;
		for(i=0;i<5;i++){
			if(posB[i][0]==posA[pos][0]&&posB[i][1]==posA[pos][1]){
				posB[i][0]=-1;
				count2--;
				break;
			}
		}
	    }
	    else
	    {	cout<<"Invalid choice";
		continue;
	    }
	    flag=1;
	    }while(!flag);

	    do{
	    flag=1;
	    do{
	    clrscr();
	    for(i=0;i<5;i++){
		for(int j=0;j<5;j++){
			gotoxy(10*j+1,i+1);
			cout<<"-";
		}
	    }
	    for(i=0;i<5;i++){
		if(posA[i][0]!=-1)//Pawn is not out
		{	gotoxy(posA[i][0],posA[i][1]);
			cout<<"A"<<A[i];
		}
		if(posB[i][0]!=-1)
		{
			gotoxy(posB[i][0],posB[i][1]);
			cout<<"B"<<B[i];
		}
	    }
	    gotoxy(1,5);
	    cout<<"Type \"exit\" to exit the game";
	    gotoxy(1,12);
	    cout<<"B move:";
	    if(strcmp(name,"exit")==0)
		exit(0);
	    cin>>name;
	    for(pos=0;pos<5;pos++){
		if(strcmp(B[pos],name)==0&&posB[pos][0]!=-1)
			break;
	    }
	    if(pos==5)
		cout<<"Invalid name";
	    }while(pos==5);
	    gotoxy(1,14);
	    cout<<B[pos]<<":";
	    choice=getch();
	    if(choice=='L'||choice=='l'){
		temp=posB[pos][0]-10;
		if(temp<1)
		{	cout<<"Invalid Choice";
			flag=0;
		}
		for(i=0;i<5;i++){
			if(posB[i][0]==temp&&posB[i][1]==posB[pos][1]){
				temp=-1;
				break;
			}
		}
		if(temp==-1)
		{	cout<<"Invalid Choice";
			flag=0;
		}
		if(flag==1)
		{	posB[pos][0]-=10;
			for(i=0;i<5;i++){
			if(posA[i][0]==posB[pos][0]&&posA[i][1]==posB[pos][1]){
				posA[i][0]=-1;
				count1--;
				break;
			}

		}
		}
	    }
	    else if(choice=='R'||choice=='r'){
		temp=posB[pos][0]+10;
		if(temp>45)
		{	cout<<"Invalid Choice";
			flag=0;
		}
		for(i=0;i<5;i++){
			if(posB[i][0]==temp&&posB[i][1]==posB[pos][1]){
				temp=-1;
				break;
			}
		}
		if(temp==-1)
		{	cout<<"Invalid Choice";
			flag=0;
		}
		if(flag==1)
		{	posB[pos][0]+=10;
			for(i=0;i<5;i++){
			if(posA[i][0]==posB[pos][0]&&posA[i][1]==posB[pos][1]){
				posA[i][0]=-1;
				count1--;
				break;
			}
			}
		}
	    }
	    else if(choice=='U'||choice=='u'){
		temp=posB[pos][1]-1;
		if(temp<1)
		{	cout<<"Invalid Choice";
			flag=0;
		}
		for(i=0;i<5;i++){
			if(posB[i][1]==temp&&posB[i][0]==posB[pos][0]){
				temp=-1;
				break;
			}
		}
		if(temp==-1)
		{	cout<<"Invalid Choice";
			flag=0;
		}
		if(flag==1)
		{	posB[pos][1]--;
			for(i=0;i<5;i++){
			if(posA[i][0]==posB[pos][0]&&posA[i][1]==posB[pos][1]){
				posA[i][0]=-1;
				count1--;
				break;
			}
			}
		}
	    }
	    else if(choice=='D'||choice=='d'){
		temp=posB[pos][1]+1;
		if(temp>5)
		{	cout<<"Invalid Choice";
			flag=0;
		}
		for(i=0;i<5;i++){
			if(posB[i][1]==temp&&posB[i][0]==posB[pos][0]){
				temp=-1;
				break;
			}
		}
		if(temp==-1)
		{	cout<<"Invalid Choice";
			flag=0;
		}
		if(flag==1)
		{	posB[pos][1]++;
			for(i=0;i<5;i++){
			if(posA[i][0]==posB[pos][0]&&posA[i][1]==posB[pos][1]){
				posA[i][0]=-1;
				count1--;
				break;
			}
			}
		}
	    }
	    else
	    {	cout<<"Invalid choice";
		flag=0;
	    }
	    }while(!flag);
	}while(count1>0&&count2>0);
	clrscr();
	if(count1<=0)
		 cout<<"B wins";
	else if(count2<=0)
		cout<<"A wins";
	getch();
}
