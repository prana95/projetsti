#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct input_s{
	int n;
	char text[65];
}input_t;


char key[16][49];

input_t cle;



input_t  text_to_hexa(char *a);
void print(char * a);
void key_generation(char * k);
void permutation(char*k1,char * k2,int * p, int n);
void shift(char * k,int x);
void concat(char * k, char * l,char * r,int n);



int main(int argc,char**argv){
	char key[17];
	int tmp[5],i;
	
	/*printf("enter the message:");
	scanf("%s",key);*/
	strcpy(key,argv[1]);

	//input_t text=decimal_to_binary(message);
	cle=text_to_hexa(key);
	//printf("%d  %c\n",strlen(cle.text),cle.text[64]);
	
	

	key_generation(cle.text);
	
	return 0;

}

input_t text_to_hexa(char * a){
	int i=0;
	char tmp[5];
	tmp[4]='\0';
	input_t  res;
	res.n=0;
	    while (res.n!=64)
	    {
		   switch (a[i])
		   {
		   
		   case '0':
		       tmp[0]='0';
		       tmp[1]='0';
		       tmp[2]='0';
		       tmp[3]='0';
		       res.n+=4; break;
		   case '1':
		       tmp[0]='0';
		       tmp[1]='0';
		       tmp[2]='0';
		       tmp[3]='1';
		       res.n+=4; break;
		   case '2':
		       tmp[0]='0';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='0';
		       res.n+=4; break;
		   case '3':
		       tmp[0]='0';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='1';
		       res.n+=4; break;
		   case '4':
		       tmp[0]='0';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='0';
		       res.n+=4; break;
		   case '5':
		       tmp[0]='0';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='1';
		       res.n+=4; break;
		   case '6':
		       tmp[0]='0';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='0';
		       res.n+=4; break;
		   case '7':
		       tmp[0]='0';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='1';
		       res.n+=4; break;
		   case '8':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='0';
		       tmp[3]='0';
		       res.n+=4; break;
		   case '9':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='0';
		       tmp[3]='1';
		       res.n+=4; break;
		   case 'A':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='0';
		       res.n+=4; break;
		   case 'B':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='1';
		       res.n+=4; break;
		   case 'C':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='0';
		       res.n+=4; break;
		   case 'D':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='1';
		       res.n+=4; break;
		   case 'E':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='0';
		       res.n+=4; break;
		   case 'F':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='1';
		       res.n+=4; break;
		   case 'a':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='0';
		       res.n+=4; break;
		   case 'b':
		       tmp[0]='1';
		       tmp[1]='0';
		       tmp[2]='1';
		       tmp[3]='1';
		       res.n+=4; break;
		   case 'c':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='0';
		       res.n+=4; break;
		   case 'd':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='0';
		       tmp[3]='1';
		       res.n+=4; break;
		   case 'e':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='0';
		       res.n+=4; break;
		   case 'f':
		       tmp[0]='1';
		       tmp[1]='1';
		       tmp[2]='1';
		       tmp[3]='1';
		       res.n+=4; break;
		   default:
		       printf("\n Invalid hexa digit %c ", a[i]);
		      exit(-1);

		   }
		   strcat(res.text,tmp);
		   i++;
	    }
	    res.text[64]='\0';
	    return res;
}








/*input_t decimal_to_binary(char *a){
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
}*/

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
	print(left);
	print(right);
	printf("%d\n",strlen(right));
	
	while(j!=16){
		shift(left,left_shift[j]);
		shift(right,left_shift[j]);
		concat(key_bis,left,right,28);
		permutation(key[j],key_bis,pc2,48);
		
		
		
		//print(key_bis);
		//print(key[j]);
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










