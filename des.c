#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct input_s{
	int n;
	char * text;
}input;

input * init_input(int m){
	input * res=malloc(sizeof(input));
	res->text=malloc(sizeof(char)*m);
	res->n=0;
	return res;
}

void destroy_input(input * i){
	free(i->text);
	free(i);
}



input * text_to_hexa(char *a);
void print(char * a);
void key_generation(char * k);
void permutation(char*k1,char * k2,int * p, int n);
void shift(char * k,int x);
void concat(char * k, char * l,char * r,int n);
void encryption(char * p);
void fk(char * fk_p4,char * k);
void fonction_xor(char * xor,char * chaine1,char * chaine2,int n);
int bit2_compare(char a, char b);
int bit4_compare(char a,char b,char c,char d);
void operation(char* new,char * b1, char *b2, char *b3, char *b4, char *b5, char *b6, char *b7, char *b8);
void sw(char * left ,char * right);

void decryption(char * c);

char round_key[16][49];



char key[17];
char plaintext[17];
char plaintext_bis[65];
char ciphertext[65];
char decodec[65];


int main(int argc,char**argv){
	input * cle=init_input(65);
	input * message=init_input(65);
	
	
	
	strcpy(key,argv[1]);
	cle=text_to_hexa(key);
	
	strcpy(plaintext,argv[2]);
	message=text_to_hexa(plaintext);
	
	printf("cle init:\t");
	print(cle->text);
	printf("message init:\t");
	print(message->text);
	key_generation(cle->text);
	encryption(message->text);
	decryption(ciphertext);
	
	
	
	return 0;

}

input *text_to_hexa(char * a){
	int i=0;
	char tmp[5];
	tmp[4]='\0';
	input * res=init_input(65);
	
	    while (res->n!=64)
	    {
		   switch (a[i])
		   {
		   
		   case '0':
		       tmp[0]='0';
		       tmp[1]='0';
		       tmp[2]='0';
		       tmp[3]='0';
		       res->n+=4; break;
		   case '1':
		       tmp[0]='0';
		       tmp[1]='0';
		       tmp[2]='0';
		       tmp[3]='1';
		       res->n+=4; break;
		   case '2':
		       tmp[0]='0';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='0';
		       res->n+=4; break;
		   case '3':
		       tmp[0]='0';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='1';
		       res->n+=4; break;
		   case '4':
		       tmp[0]='0';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='0';
		       res->n+=4; break;
		   case '5':
		       tmp[0]='0';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='1';
		       res->n+=4; break;
		   case '6':
		       tmp[0]='0';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='0';
		       res->n+=4; break;
		   case '7':
		       tmp[0]='0';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='1';
		       res->n+=4; break;
		   case '8':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='0';
		       tmp[3]='0';
		       res->n+=4; break;
		   case '9':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='0';
		       tmp[3]='1';
		       res->n+=4; break;
		   case 'A':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='0';
		       res->n+=4; break;
		   case 'B':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='1';
		       res->n+=4; break;
		   case 'C':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='0';
		       res->n+=4; break;
		   case 'D':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='1';
		       res->n+=4; break;
		   case 'E':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='0';
		       res->n+=4; break;
		   case 'F':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='1';
		       res->n+=4; break;
		   case 'a':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='0';
		       res->n+=4; break;
		   case 'b':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='1';
		       res->n+=4; break;
		   case 'c':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='0';
		       res->n+=4; break;
		   case 'd':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='1';
		       res->n+=4; break;
		   case 'e':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='0';
		       res->n+=4; break;
		   case 'f':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='1';
		       res->n+=4; break;
		   default:
		       printf("\n Invalid hexa digit %c ", a[i]);
		      exit(-1);

		   }
		   strcat(res->text,tmp);
		   i++;
	    }
	    res->text[64]='\0';
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
	int  pc1[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
	int pc2[48]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
	int left_shift[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
	
	int i,j=0;
	char left[29],right[29];
	
	char key_bis[57];
	
	permutation(key_bis,k,pc1,56);
	key_bis[56]='\0';
	
	for(i=0;i<28;i++)                             
	{
		left[i]=key_bis[i];
		right[i]=key_bis[i+28];
	}
	left[28]='\0';
	right[28]='\0';
	
	
	while(j!=16){
		shift(left,left_shift[j]);
		shift(right,left_shift[j]);
		concat(key_bis,left,right,28);
		permutation(round_key[j],key_bis,pc2,48);
		
		
		
		//print(key_bis);
		//print(round_key[j]);
		//print(right);
		//printf("\n");
		j++;
		
	}
}


void permutation(char*k1,char * k2,int * p, int n){
	int i;
	for(i=0;i<n;i++){
		k1[i]=k2[p[i]-1];
	}
}

void shift(char * k,int x){
	int i;
	int tmp,tmp_2;
	if(x==1){
		tmp=k[0];
		for(i=0;i<strlen(k);i++){
			if(i==27){
				k[i]=tmp;
			}
			else{
				k[i]=k[i+1];
			}
		}
		
	}
	else if(x==2){
		tmp=k[0];
		tmp_2=k[1];
		for(i=0;i<strlen(k);i++){
			if(i==26){
				k[i]=tmp;
			}
			else if(i==27){
				k[i]=tmp_2;
			}
			else{
				k[i]=k[i+2];
			}
		}
		
	}
}

void concat(char * k, char * l,char * r,int n){
	int i;
	for(i=0;i<n;i++){
		k[i]=l[i];
		k[i+n]=r[i];
	}
}

void encryption(char * p){
	int ip[64]={58, 50, 42, 34, 26, 18, 10, 2,60, 52, 44, 36, 28, 20, 12, 4,62, 54, 46, 38, 30, 22, 14, 6,64, 56, 48, 40, 32, 24, 16, 8,57, 49, 41, 33, 25, 17,  9, 1,59, 51, 43, 35, 27, 19, 11, 3,61, 53, 45, 37, 29, 21, 13, 5,63, 55, 47, 39, 31, 23, 15, 7};
	
	int ip_inverse[64]={40,  8, 48, 16, 56, 24, 64, 32,39,  7, 47, 15, 55, 23, 63, 31,38,  6, 46, 14, 54, 22, 62, 30,37,  5, 45, 13, 53, 21, 61, 29,36,  4, 44, 12, 52, 20, 60, 28,35,  3, 43, 11, 51, 19, 59, 27,34,  2, 42, 10, 50, 18, 58, 26,33,  1, 41,  9, 49, 17, 57, 25};

	
	char left[33],right[33];
	char * fk_p4=malloc(sizeof(char)*33);
	char * xor=malloc(sizeof(char)*33);
	int i,j=0;

	permutation(plaintext_bis,p,ip,64);
	plaintext_bis[64]='\0';
	while(j!=16){
		for(i=0;i<32;i++)                             
		{
			left[i]=plaintext_bis[i];
			right[i]=plaintext_bis[i+32];
		}
		left[32]='\0';
		right[32]='\0';
		
		
		fk(fk_p4,round_key[j]);
		
		fonction_xor(xor,left,fk_p4,32);
		xor[32]='\0';
		concat(plaintext_bis,right,xor,32);
		j++;
	}
	for(i=0;i<32;i++)                             
		{
			left[i]=plaintext_bis[i];
			right[i]=plaintext_bis[i+32];
		}
	
	//print(right);
	
	sw(right,left);
	
	
	permutation(ciphertext,plaintext_bis,ip_inverse,64);
	ciphertext[64]='\0';
	printf("ciphertext:\t");
	print(ciphertext);
	
}

void decryption(char * c){
	int ip[64]={58, 50, 42, 34, 26, 18, 10, 2,60, 52, 44, 36, 28, 20, 12, 4,62, 54, 46, 38, 30, 22, 14, 6,64, 56, 48, 40, 32, 24, 16, 8,57, 49, 41, 33, 25, 17,  9, 1,59, 51, 43, 35, 27, 19, 11, 3,61, 53, 45, 37, 29, 21, 13, 5,63, 55, 47, 39, 31, 23, 15, 7};
	
	int ip_inverse[64]={40,  8, 48, 16, 56, 24, 64, 32,39,  7, 47, 15, 55, 23, 63, 31,38,  6, 46, 14, 54, 22, 62, 30,37,  5, 45, 13, 53, 21, 61, 29,36,  4, 44, 12, 52, 20, 60, 28,35,  3, 43, 11, 51, 19, 59, 27,34,  2, 42, 10, 50, 18, 58, 26,33,  1, 41,  9, 49, 17, 57, 25};

	
	char left[33],right[33];
	char * fk_p4=malloc(sizeof(char)*33);
	char * xor=malloc(sizeof(char)*33);
	int i,j=15;

	permutation(plaintext_bis,c,ip,64);
	plaintext_bis[64]='\0';
	while(j>=0){
		for(i=0;i<32;i++)                             
		{
			left[i]=plaintext_bis[i];
			right[i]=plaintext_bis[i+32];
		}
		left[32]='\0';
		right[32]='\0';
		
		
		fk(fk_p4,round_key[j]);
		
		fonction_xor(xor,left,fk_p4,32);
		xor[32]='\0';
		concat(plaintext_bis,right,xor,32);
		j--;
	}
	for(i=0;i<32;i++)                             
		{
			left[i]=plaintext_bis[i];
			right[i]=plaintext_bis[i+32];
		}
	
	//print(right);
	
	sw(right,left);
	
	
	permutation(decodec,plaintext_bis,ip_inverse,64);
	decodec[64]='\0';
	printf("decodec:\t");
	print(decodec);
	
}


void sw(char * left ,char * right){
	int i;
	for(i=0;i<32;i++) {
		plaintext_bis[i]=left[i];
		plaintext_bis[i+32]=right[i];
	}	
}



void fk(char * fk_p4,char * k){

	int ep[48]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
	int p32[32]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
	char ep_bis[49],xor[49];
	char * new=malloc(sizeof(char)*33);
	char b1[7],b2[7],b3[7],b4[7],b5[7],b6[7],b7[7],b8[7];
	int i;
	
	
	for(i=0;i<48;i++){
		ep_bis[i]=plaintext_bis[(ep[i]-1)+32];
	}
	
	
	fonction_xor(xor,ep_bis,k,48);
	
	
	for(i=0;i<6;i++){
		b1[i]=xor[i];
		b2[i]=xor[i+6];
		b3[i]=xor[i+12];
		b4[i]=xor[i+18];
		b5[i]=xor[i+24];
		b6[i]=xor[i+30];
		b7[i]=xor[i+36];
		b8[i]=xor[i+42];
	}
	b1[i]='\0';b2[i]='\0';b3[i]='\0';b4[i]='\0';b5[i]='\0';b6[i]='\0';b7[i]='\0';b8[i]='\0';
	
/*	print(b1);*/
/*	print(b2);*/
/*	print(b3);print(b4);*/
/*	print(b5);print(b6);*/
/*	print(b7);print(b8);*/
	//operation Sbox
	operation(new,b1,b2,b3,b4,b5,b6,b7,b8);
	
	permutation(fk_p4,new,p32,32);
	fk_p4[32]='\0';
	
	
	

}


void fonction_xor(char * xor,char * chaine1,char * chaine2,int n){
	int i,tmp;
	for(i=0;i<n;i++){
		tmp= (int)chaine1[i]+chaine2[i];
		if(tmp==96){
			xor[i]='0';
		}
		else if(tmp == 97){
			xor[i]='1';
		}
		else if(tmp == 98){
			xor[i]='0';
		}
	}
}

int bit2_compare(char a, char b){
	if(a=='0' && b== '0'){
		return 0;
	}
	else if(a=='0' && b== '1'){
		return 1;
	}
	else if(a=='1' && b== '0'){
		return 2;
	}
	else if(a=='1' && b== '1'){
		return 3;
	}
	return -1;
}
int bit4_compare(char a,char b,char c,char d){
	if(a=='0' && b=='0' && c=='0' && d=='0'){
		return 0;
	}
	else if(a=='0' && b=='0' && c=='0' && d=='1'){
		return 1;
	}
	else if(a=='0' && b=='0' && c=='1' && d=='0'){
		return 2;
	}
	else if(a=='0' && b=='0' && c=='1' && d=='1'){
		return 3;
	}
	else if(a=='0' && b=='1' && c=='0' && d=='0'){
		return 4;
	}
	else if(a=='0' && b=='1' && c=='0' && d=='1'){
		return 5;
	}
	else if(a=='0' && b=='1' && c=='1' && d=='0'){
		return 6;
	}
	else if(a=='0' && b=='1' && c=='1' && d=='1'){
		return 7;
	}
	else if(a=='1' && b=='0' && c=='0' && d=='0'){
		return 8;
	}
	else if(a=='1' && b=='0' && c=='0' && d=='1'){
		return 9;
	}
	else if(a=='1' && b=='0' && c=='1' && d=='0'){
		return 10;
	}
	else if(a=='1' && b=='0' && c=='1' && d=='1'){
		return 11;
	}
	else if(a=='1' && b=='1' && c=='0' && d=='0'){
		return 12;
	}
	else if(a=='1' && b=='1' && c=='0' && d=='1'){
		return 13;
	}
	else if(a=='1' && b=='1' && c=='1' && d=='0'){
		return 14;
	}
	else if(a=='1' && b=='1' && c=='1' && d=='1'){
		return 15;
	}
	return -1;
}

void operation(char* new,char * b1, char *b2, char *b3, char *b4, char *b5, char *b6, char *b7, char *b8){
	int s1[64]={14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
			 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
			 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
			15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13};
	int s2[64]={15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
			 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
			 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
			13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9};
	int s3[64]={10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
			13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
			13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
			 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12};
	int s4[64]={ 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
			13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
			10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
			 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14};
	int s5[64]={ 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
			14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
			 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
			11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3};
	int s6[64]={12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
			10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
			 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
			 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13};
	int s7[64]={ 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
			13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
			 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
			 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12};
	int s8[64]={13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
			 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
			 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
			 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11};
			 
	int tmp[16];
	int val_b1,val_b2,val_b3,val_b4,val_b5,val_b6,val_b7,val_b8;
	char b1_bis[5],b2_bis[5],b3_bis[5],b4_bis[5],b5_bis[5],b6_bis[5],b7_bis[5],b8_bis[5];
	char zero[5]={'0','0','0','0','\0'};
	char un[5]={'0','0','0','1','\0'};
	char deux[5]={'0','0','1','0','\0'};
	char trois[5]={'0','0','1','1','\0'};
	char quatre[5]={'0','1','0','0','\0'};
	char cinq[5]={'0','1','0','1','\0'};
	char six[5]={'0','1','1','0','\0'};
	char sept[5]={'0','1','1','1','\0'};
	char huit[5]={'1','0','0','0','\0'};
	char neuf[5]={'1','0','0','1','\0'};
	char dix[5]={'1','0','1','0','\0'};
	char onze[5]={'1','0','1','1','\0'};
	char douze[5]={'1','1','0','0','\0'};
	char treize[5]={'1','1','0','1','\0'};
	char quatorze[5]={'1','1','1','0','\0'};
	char quinze[5]={'1','1','1','1','\0'};
	
	
	
	
	tmp[0]= bit2_compare(b1[0],b1[5]);
	tmp[1]= bit4_compare(b1[1],b1[2],b1[3],b1[4]);
	tmp[2]= bit2_compare(b2[0],b2[5]);
	tmp[3]= bit4_compare(b2[1],b2[2],b2[3],b2[4]);
	tmp[4]= bit2_compare(b3[0],b3[5]);
	tmp[5]= bit4_compare(b3[1],b3[2],b3[3],b3[4]);
	tmp[6]= bit2_compare(b4[0],b4[5]);
	tmp[7]= bit4_compare(b4[1],b4[2],b4[3],b4[4]);
	tmp[8]= bit2_compare(b5[0],b5[5]);
	tmp[9]= bit4_compare(b5[1],b5[2],b5[3],b5[4]);
	tmp[10]= bit2_compare(b6[0],b6[5]);
	tmp[11]= bit4_compare(b6[1],b6[2],b6[3],b6[4]);
	tmp[12]= bit2_compare(b7[0],b7[5]);
	tmp[13]= bit4_compare(b7[1],b7[2],b7[3],b7[4]);
	tmp[14]= bit2_compare(b8[0],b8[5]);
	tmp[15]= bit4_compare(b8[1],b8[2],b8[3],b8[4]);
	
	
	val_b1=s1[tmp[0]*16+tmp[1]];
	val_b2=s2[tmp[2]*16+tmp[3]];
	val_b3=s3[tmp[4]*16+tmp[5]];
	val_b4=s4[tmp[6]*16+tmp[7]];
	val_b5=s5[tmp[8]*16+tmp[9]];
	val_b6=s6[tmp[10]*16+tmp[11]];
	val_b7=s7[tmp[12]*16+tmp[13]];
	val_b8=s8[tmp[14]*16+tmp[15]];
	
	
	b1_bis[4]='\0';b2_bis[4]='\0';b3_bis[4]='\0';b4_bis[4]='\0';b5_bis[4]='\0';b6_bis[4]='\0';b7_bis[4]='\0';b8_bis[4]='\0';
	
	//b1
	if(val_b1==0) strcpy(b1_bis,zero);
	if(val_b1==1) strcpy(b1_bis,un);
	if(val_b1==2) strcpy(b1_bis,deux);
	if(val_b1==3) strcpy(b1_bis,trois);
	if(val_b1==4) strcpy(b1_bis,quatre);
	if(val_b1==5) strcpy(b1_bis,cinq);
	if(val_b1==6) strcpy(b1_bis,six);
	if(val_b1==7) strcpy(b1_bis,sept);
	if(val_b1==8) strcpy(b1_bis,huit);
	if(val_b1==9) strcpy(b1_bis,neuf);
	if(val_b1==10) strcpy(b1_bis,dix);
	if(val_b1==11) strcpy(b1_bis,onze);
	if(val_b1==12) strcpy(b1_bis,douze);
	if(val_b1==13) strcpy(b1_bis,treize);
	if(val_b1==14) strcpy(b1_bis,quatorze);
	if(val_b1==15) strcpy(b1_bis,quinze);
	
	//b2
	if(val_b2==0) strcpy(b2_bis,zero);
	if(val_b2==1) strcpy(b2_bis,un);
	if(val_b2==2) strcpy(b2_bis,deux);
	if(val_b2==3) strcpy(b2_bis,trois);
	if(val_b2==4) strcpy(b2_bis,quatre);
	if(val_b2==5) strcpy(b2_bis,cinq);
	if(val_b2==6) strcpy(b2_bis,six);
	if(val_b2==7) strcpy(b2_bis,sept);
	if(val_b2==8) strcpy(b2_bis,huit);
	if(val_b2==9) strcpy(b2_bis,neuf);
	if(val_b2==10) strcpy(b2_bis,dix);
	if(val_b2==11) strcpy(b2_bis,onze);
	if(val_b2==12) strcpy(b2_bis,douze);
	if(val_b2==13) strcpy(b2_bis,treize);
	if(val_b2==14) strcpy(b2_bis,quatorze);
	if(val_b2==15) strcpy(b2_bis,quinze);
	
	//b3
	if(val_b3==0) strcpy(b3_bis,zero);
	if(val_b3==1) strcpy(b3_bis,un);
	if(val_b3==2) strcpy(b3_bis,deux);
	if(val_b3==3) strcpy(b3_bis,trois);
	if(val_b3==4) strcpy(b3_bis,quatre);
	if(val_b3==5) strcpy(b3_bis,cinq);
	if(val_b3==6) strcpy(b3_bis,six);
	if(val_b3==7) strcpy(b3_bis,sept);
	if(val_b3==8) strcpy(b3_bis,huit);
	if(val_b3==9) strcpy(b3_bis,neuf);
	if(val_b3==10) strcpy(b3_bis,dix);
	if(val_b3==11) strcpy(b3_bis,onze);
	if(val_b3==12) strcpy(b3_bis,douze);
	if(val_b3==13) strcpy(b3_bis,treize);
	if(val_b3==14) strcpy(b3_bis,quatorze);
	if(val_b3==15) strcpy(b3_bis,quinze);
	
	
	//b4
	if(val_b4==0) strcpy(b4_bis,zero);
	if(val_b4==1) strcpy(b4_bis,un);
	if(val_b4==2) strcpy(b4_bis,deux);
	if(val_b4==3) strcpy(b4_bis,trois);
	if(val_b4==4) strcpy(b4_bis,quatre);
	if(val_b4==5) strcpy(b4_bis,cinq);
	if(val_b4==6) strcpy(b4_bis,six);
	if(val_b4==7) strcpy(b4_bis,sept);
	if(val_b4==8) strcpy(b4_bis,huit);
	if(val_b4==9) strcpy(b4_bis,neuf);
	if(val_b4==10) strcpy(b4_bis,dix);
	if(val_b4==11) strcpy(b4_bis,onze);
	if(val_b4==12) strcpy(b4_bis,douze);
	if(val_b4==13) strcpy(b4_bis,treize);
	if(val_b4==14) strcpy(b4_bis,quatorze);
	if(val_b4==15) strcpy(b4_bis,quinze);
	
	//b5
	if(val_b5==0) strcpy(b5_bis,zero);
	if(val_b5==1) strcpy(b5_bis,un);
	if(val_b5==2) strcpy(b5_bis,deux);
	if(val_b5==3) strcpy(b5_bis,trois);
	if(val_b5==4) strcpy(b5_bis,quatre);
	if(val_b5==5) strcpy(b5_bis,cinq);
	if(val_b5==6) strcpy(b5_bis,six);
	if(val_b5==7) strcpy(b5_bis,sept);
	if(val_b5==8) strcpy(b5_bis,huit);
	if(val_b5==9) strcpy(b5_bis,neuf);
	if(val_b5==10) strcpy(b5_bis,dix);
	if(val_b5==11) strcpy(b5_bis,onze);
	if(val_b5==12) strcpy(b5_bis,douze);
	if(val_b5==13) strcpy(b5_bis,treize);
	if(val_b5==14) strcpy(b5_bis,quatorze);
	if(val_b5==15) strcpy(b5_bis,quinze);
	
	//b6
	if(val_b6==0) strcpy(b6_bis,zero);
	if(val_b6==1) strcpy(b6_bis,un);
	if(val_b6==2) strcpy(b6_bis,deux);
	if(val_b6==3) strcpy(b6_bis,trois);
	if(val_b6==4) strcpy(b6_bis,quatre);
	if(val_b6==5) strcpy(b6_bis,cinq);
	if(val_b6==6) strcpy(b6_bis,six);
	if(val_b6==7) strcpy(b6_bis,sept);
	if(val_b6==8) strcpy(b6_bis,huit);
	if(val_b6==9) strcpy(b6_bis,neuf);
	if(val_b6==10) strcpy(b6_bis,dix);
	if(val_b6==11) strcpy(b6_bis,onze);
	if(val_b6==12) strcpy(b6_bis,douze);
	if(val_b6==13) strcpy(b6_bis,treize);
	if(val_b6==14) strcpy(b6_bis,quatorze);
	if(val_b6==15) strcpy(b6_bis,quinze);
	
	//b7
	if(val_b7==0) strcpy(b7_bis,zero);
	if(val_b7==1) strcpy(b7_bis,un);
	if(val_b7==2) strcpy(b7_bis,deux);
	if(val_b7==3) strcpy(b7_bis,trois);
	if(val_b7==4) strcpy(b7_bis,quatre);
	if(val_b7==5) strcpy(b7_bis,cinq);
	if(val_b7==6) strcpy(b7_bis,six);
	if(val_b7==7) strcpy(b7_bis,sept);
	if(val_b7==8) strcpy(b7_bis,huit);
	if(val_b7==9) strcpy(b7_bis,neuf);
	if(val_b7==10) strcpy(b7_bis,dix);
	if(val_b7==11) strcpy(b7_bis,onze);
	if(val_b7==12) strcpy(b7_bis,douze);
	if(val_b7==13) strcpy(b7_bis,treize);
	if(val_b7==14) strcpy(b7_bis,quatorze);
	if(val_b7==15) strcpy(b7_bis,quinze);
	
	//b8
	if(val_b8==0) strcpy(b8_bis,zero);
	if(val_b8==1) strcpy(b8_bis,un);
	if(val_b8==2) strcpy(b8_bis,deux);
	if(val_b8==3) strcpy(b8_bis,trois);
	if(val_b8==4) strcpy(b8_bis,quatre);
	if(val_b8==5) strcpy(b8_bis,cinq);
	if(val_b8==6) strcpy(b8_bis,six);
	if(val_b8==7) strcpy(b8_bis,sept);
	if(val_b8==8) strcpy(b8_bis,huit);
	if(val_b8==9) strcpy(b8_bis,neuf);
	if(val_b8==10) strcpy(b8_bis,dix);
	if(val_b8==11) strcpy(b8_bis,onze);
	if(val_b8==12) strcpy(b8_bis,douze);
	if(val_b8==13) strcpy(b8_bis,treize);
	if(val_b8==14) strcpy(b8_bis,quatorze);
	if(val_b8==15) strcpy(b8_bis,quinze);
	
	new[32]='\0';
	strcat(new,b1_bis);
	strcat(new,b2_bis);
	strcat(new,b3_bis);
	strcat(new,b4_bis);
	strcat(new,b5_bis);
	strcat(new,b6_bis);
	strcat(new,b7_bis);
	strcat(new,b8_bis);
	
	


}





























