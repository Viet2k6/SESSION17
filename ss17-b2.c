#include <stdio.h>
#include <string.h>
void addString(char text[]);
void showString(char text[]);
void wordString(char text[],int count);
void numberString(char text[],int count2);
void spectialString(char text[],int count3);

int main(){
	char text[100];
	int n=0;
	int choice;
	int count=0,count2=0,count3=0;
		do{
		printf("Menu\n");
		printf("1.Nhap vao chuoi\n");
		printf("2.In ra chuoi\n");
		printf("3.Dem so luong chu cai trong chuoi\n");
		printf("4.Dem so luong chu so trong chuoi\n");
		printf("5.Dem so luong ki tu dac biet\n");
		printf("6.Thoat\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				addString(text);
				n++;
				break;
		    case 2:
		    	if(n==0){
		    		printf("Mang rong\n");
				}else{
					showString(text);
				}
				break;
			case 3:
				if(n==0){
		    		printf("Mang rong\n");
				}else{
					wordString(text,count);
				}
				break;
			case 4:
				if(n==0){
		    		printf("Mang rong\n");
				}else{
					numberString(text,count2);
				}
				break;
		    case 5:
		    	if(n==0){
		    		printf("nhap chuoi truoc\n");
				}else{
					spectialString(text,count3);
				}
				break;
			case 6:
				printf("Thoat chuong trinh\n");
				break;
			default :
				printf("Khong hop le\n");
		}
	}while(choice!=6);
	return 0;
}
void addString(char text[]){
	fflush(stdin);
	printf("Nhap vao chuoi ");
	fgets(text,100,stdin);
}
void showString(char text[]){
	printf("%s",text);
}
void wordString(char text[],int count){
	int size=strlen(text);
	for(int i=0;i<size;i++){
		if((text[i]>='a'&&text[i]<='z') || (text[i]>='A'&&text[i]<='Z')){
			count++;
		}
	}
	printf("So luong chu cai la %d\n",count);
}
void numberString(char text[],int count2){
	int size=strlen(text);
	for(int i=0;i<size;i++){
		if((text[i]>='0'&&text[i]<='9')){
			count2++;
		}
	}
	printf("So luong chu so la %d\n",count2);
}
void spectialString(char text[],int count3){
	int size=strlen(text);
	for(int i=0;i<size;i++){
	    if(!((text[i]>='a'&&text[i]<='z') || (text[i]>='A'&&text[i]<='Z') || (text[i]>='0'&&text[i]<='9'))){
	    	count3++;
		}
	}
	printf("So luong ki tu dac biet la %d\n",count3-1);
}
