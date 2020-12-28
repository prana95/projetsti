#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct input_s{
	int n;
	char text[65];
}input_t;


char key[64];



input_t  decimal_to_binary(char *a);
void print(char * a);
void key_generation(char * k);
void permutation(char*k1,char * k2,int * p, int n);
int main(int argc,char**argv){
	char key[9];
	int tmp[5],i;
	
	/*printf("enter the message:");
	scanf("%s",key);*/
	strcpy(key,argv[1]);
	printf("%s",key);
	printf("\n");
	//input_t text=decimal_to_binary(message);
	input_t cle=decimal_to_binary(key);
	//printf("%d  %c\n",strlen(key.text),key.text[64]);
	for(i=0;i<strlen(cle.text);i++){
		printf("%c",cle.text[i]);
		if(i%8==0){
			printf("\n");
		}
	}

	key_generation(cle.text);
	printf("hi");
	return 0;

}

input_t decimal_to_binary(char *a){
	input_t  res;
	int tmp,i=0,k,x;
	char tmp2[8];
	res.n=0;
	int j;

	while(res.n!=64){
		tmp=(int)a[i];
		x=0;
		for(j=7;j>=0;j--){
			k = tmp >>j;
			if(k & 1){
				tmp2[x]='1';
			}
			else{
				tmp2[x]='0';
			}
			res.n++;
			x++;
		}
		//print_text(tmp2);
		strcat(res.text,tmp2);
		i++;
		
	}
	res.text[res.n]='\0';
	return res;
}

void print(char * a){
	int i;
	for(i=0;i<strlen(a);i++){
		printf("%c",a[i]);
	}
	printf("\n");
}

void key_generation(char * k){
	int pc1[64]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,228,20,12,4};
	int pc2[56]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,377,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
	
	//printf("second\n");
	//print(k);
	char key_bis[65];
	//printf("\n%c\n",key[0]);
	printf("\n");
	permutation(key_bis,k,pc1,64);
	print(key_bis);
}


void permutation(char*k1,char * k2,int * p, int n){
	int i;
	for(i=0;i<n;i++){
		k1[i]=k2[p[i]-1];
	}
}










