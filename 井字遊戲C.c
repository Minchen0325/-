#include <stdio.h>
#include <time.h>
int a[10]={0};
int pyone;
int pytwo;
//�P�_��Ĺ���K���u 
int L[8][3]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{3,5,7},{1,5,9}} ;
//�P�_�T�I�O�_�s���@�u 
int f(int x){
	int x1=a[L[x][0]];
	int x2=a[L[x][1]];
	int x3=a[L[x][2]];
	return x1*x2+x2*x3+x3*x1;
}
//�C���ѽL 
void printGame(){
	int i;
	printf("+-+-+-+-+-+\n");
	for(i=1;i<=9;i++){
		if(a[i]==1)
			printf("��X");
		else if (a[i]==2)
			printf("��O");
		else
			printf("��%d",i);
		if (i%3==0){
			printf("��\n");
			printf("+-+-+-+-+-+\n");
		}	
	}
} 
//�C���D�t�� 
void play(int player){
	int i;
	char C;
	printGame();
	if(player==1){
		C='X';
	}else{
		C='O';
	}
	printf("player=%d--->%c\n",player,C);
	do{
		do{
			printf("�Ш����U���Ʀr:");
			scanf("%d",&i);
		}while(i<1||i>9);
	}while(a[i]!=0);
	a[i]=player;
	printf("===============\n");
	
}
//�P�_�ֿ��Ĺ 
int whowin(){
	int p;
	for(p=0;p<=7;p++){
		switch(f(p)){
			case 3:
				printGame();
				printf("player 1  win\n\n");
				pyone++;
				return 1;
				break;
			
			case 12:
				printGame();
				printf("player 2  win\n\n");
				pytwo++;
				return 2;
				break;
				
			default:
				continue;	
		}	
	}
	return 0;
}
void Game(){
	int j,winner=0;
	play(1);
	for(j=2;j<=9;j+=2){
		play(2);winner=whowin();if(winner!=0) break;
		play(1);winner=whowin();if(winner!=0) break;
	}
	if(winner==0){
		printf("����\n\n");
	}
}

int main(){
	system("color F0");
	int start=0,counter=0,i;
	time_t  timer = time(NULL);
    printf("time is %s\n", ctime(&timer));
    printf("�I���}�l�C��\n\n");
    system("pause");
	do{
		printf("�ثeplayer 1 --->X �� %d ��\n",pyone);
		printf("�ثeplayer 2 --->O �� %d ��\n",pytwo);
		printf("------------------\n");
		printf("�C������%d��\n\n",counter+=1);
		if(start==1){
			printf("�C�����s�}�l\n");
			for(i=1;i<=10;i++){
				a[i]=0; 
			}
		}
		
		Game();
		printf("���s�}�l�п�J1�A�����п�J2 : ");
		scanf("%d",&start);
		printf("\n");
	}while(start==1);
	printf("�C������\n");
	system("pause");
	
	return 0;
}
