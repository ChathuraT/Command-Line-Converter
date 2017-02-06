/* Author  : Gamage C.T.N.
 * E-Number: E/13/107
 * Date    : 14/02/2016
 * project : project-01
 * */
 
#include<stdio.h>
#include<stdlib.h>
//------------------------------------------------Prototyping available functions-----------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
//utility functions
double power(int,int);
double aToF(char*);
double fracPower(int,int);
long long aToL(char*);
//------------------------------------------------------------------------------------------------------------------------------------------
//validity checking functions
int intChecker(char**);
int hexaChecker(char**);
int binaryChecker(char**);
int floatChecker(char**);

//------------------------------------------------------------------------------------------------------------------------------------------
//error handling functions
void errorNumberOfArguments();
void errorInputArgument(char**);
void errorOutputArgument(char**);
void errorInputSize();
void errorInputFormat(int);
void errorImpossibleConversion();
void warningPrecisonLoss();

//------------------------------------------------------------------------------------------------------------------------------------------
//conversion functions
int binaryToBinary(char**);
int binaryToHexa(char**);
int binaryToInt(char**);	
int binaryToFloat(char**);
int binaryToDouble(char**);

int intToBinary(char**);
int intToInt(char**);	
int intToHexa(char**);
int intToFloat(char**);
int intToDouble(char**);

int hexaToBinary(char**);
int hexaToHexa(char**);
int hexaToInt(char**);
int hexaToFloat(char**);
int hexaToDouble(char**);

int floatToBinary(char**);
int floatToHexa(char**);
int floatToInt(char**);
int floatToFloat(char**);
int floatToDouble(char**);

int doubleToBinary(char**);
int doubleToHexa(char**);
int doubleToInt(char**);
int doubleToFloat(char**);
int doubleToDouble(char**);
//------------------------------------------------------------------------------------------------------------------------------------------


int main (int argc, char** argv) {
	if(argc==4){
		
		errorInputArgument(argv);
		errorOutputArgument(argv);
		
		// B to B conversion
		if(argv[1][1]=='B' && argv[2][1]=='B'){
			binaryToBinary(argv);	
		}
		// B to H conversion
		if(argv[1][1]=='B' && argv[2][1]=='H'){
			binaryToHexa(argv);	
		}
		// B to I conversion
		if(argv[1][1]=='B' && argv[2][1]=='I'){
			binaryToInt(argv);	
		}
		// B to F conversion
		if(argv[1][1]=='B' && argv[2][1]=='F'){
			binaryToFloat(argv);	
		}
		// B to D conversion
		if(argv[1][1]=='B' && argv[2][1]=='D'){
			binaryToDouble(argv);	
		}
		
		
		//I to I conversion
		if(argv[1][1]=='I' && argv[2][1]=='I'){
			intToInt(argv);	
		}
		// I to B conversion
		if(argv[1][1]=='I' && argv[2][1]=='B'){
			intToBinary(argv);	
		}
		//I to H conversion
		if(argv[1][1]=='I' && argv[2][1]=='H'){
			intToHexa(argv);	
		}
		//I to F conversion
		if(argv[1][1]=='I' && argv[2][1]=='F'){
			intToFloat(argv);	
		}
		//I to D conversion
		if(argv[1][1]=='I' && argv[2][1]=='D'){
			intToDouble(argv);	
		}
		
		// H to B conversion
		if(argv[1][1]=='H' && argv[2][1]=='B'){
			hexaToBinary(argv);	
		}
		// H to H conversion
		if(argv[1][1]=='H' && argv[2][1]=='H'){
			hexaToHexa(argv);	
		}
		// H to I conversion
		if(argv[1][1]=='H' && argv[2][1]=='I'){
			hexaToInt(argv);	
		}
		// H to F conversion
		if(argv[1][1]=='H' && argv[2][1]=='F'){
			hexaToFloat(argv);	
		}
		// H to D conversion
		if(argv[1][1]=='H' && argv[2][1]=='D'){
			hexaToDouble(argv);	
		}
		
		// F to B conversion
		if(argv[1][1]=='F' && argv[2][1]=='B'){
			floatToBinary(argv);	
		}
		// F to H conversion
		if(argv[1][1]=='F' && argv[2][1]=='H'){
			floatToHexa(argv);
		}
		// F to I conversion
		if(argv[1][1]=='F' && argv[2][1]=='I'){
			floatToInt(argv);
		}
		// F to F conversion
		if(argv[1][1]=='F' && argv[2][1]=='F'){		
			floatToFloat(argv);
		}
		// F to D conversion
		if(argv[1][1]=='F' && argv[2][1]=='D'){		
			floatToDouble(argv);
		}
		
		// D to B conversion
		if(argv[1][1]=='D' && argv[2][1]=='B'){
			doubleToBinary(argv);	
		}
		// D to H conversion
		if(argv[1][1]=='D' && argv[2][1]=='H'){
			doubleToHexa(argv);	
		}
		// D to I conversion
		if(argv[1][1]=='D' && argv[2][1]=='I'){
			doubleToInt(argv);	
		}		
		// D to F conversion
		if(argv[1][1]=='D' && argv[2][1]=='F'){
			doubleToFloat(argv);	
		}
		// D to D conversion
		if(argv[1][1]=='D' && argv[2][1]=='D'){
			doubleToDouble(argv);	
		}
	}else{ //wrong number of arguments
		errorNumberOfArguments();
		}
	
	return 0; //EXIT_SUCCESS
}

//------------------------------------------------Declaring available functions-------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
//utility functions

double power(int num,int order){ //this function returns the power of a given number
	double powe=1;
	for(;order>0;order--){
		powe=num*powe;	//power is taken by multipling the same number again and again
		}
	return powe;
	}
	
//------------------------------------------------------------------------------------------------------------------------------------------
double aToF(char* num){		//this function returns the float conversion of a input string(atof) 
     if (!num || !*num)
         return 0; 
     double intNum=0,fracNum=0;
     int fracSeparator=1,sign=1,fraction= 0;
    
     if (*num == '-'){	//checking for the sign
         ++num;
         sign = -1;
     }
     else if (*num == '+'){
         ++num;
     }
     while (*num != '\0'){	// iterating the whole string
         if (*num >= '0' && *num <= '9'){
             if (fraction){
                fracNum = fracNum*10 + (*num - '0');
                 fracSeparator*= 10;
             }else{
                intNum = intNum*10 + (*num - '0');
             }
         }else if (*num == '.'){	//recognizing the fraction part
             if (fraction)
                 return sign * (intNum + fracNum/fracSeparator);
             else
                fraction=1;
         }else{
             return sign*(intNum + fracNum/fracSeparator);
         }
         ++num;
     }
     return sign*(intNum + fracNum/fracSeparator); //returning the float value by giving the sign
 }
 
//------------------------------------------------------------------------------------------------------------------------------------------
double  fracPower(int num,int order){ //this function returns the negative power of a given number
	double  powe=1;
	order=-1*order;
	
	for(;order>0;order--){
		powe=powe*1/num;	//power is taken by multipling the same number again and again
		}
	return powe;
	}

//------------------------------------------------------------------------------------------------------------------------------------------

long long aToL(char* num){		//this function returns the long conversion of a input string 
     if (!num || !*num)
         return 0; 
     long long intNum=0,fracNum=0;
     int fracSeparator=1,sign=1,fraction= 0;
    
     if (*num == '-'){	//checking for the sign
         ++num;
         sign = -1;
     }
     else if (*num == '+'){
         ++num;
     }
     while (*num != '\0'){	// iterating the whole string
         if (*num >= '0' && *num <= '9'){
             if (fraction){
                fracNum = fracNum*10 + (*num - '0');
                 fracSeparator*= 10;
             }else{
                intNum = intNum*10 + (*num - '0');
             }
         }else if (*num == '.'){	//recognizing the fraction part
             if (fraction)
                 return sign * (intNum + fracNum/fracSeparator);
             else
                fraction=1;
         }else{
             return sign*(intNum + fracNum/fracSeparator);
         }
         ++num;
     }
     return sign*(intNum + fracNum/fracSeparator); //returning the float value by giving the sign
 }
 
//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
//validity checking functions

int intChecker(char** argv){
	int i,j,count,temp;
	if((aToF(argv[3])<=2147483647) && (aToF(argv[3])>=-2147483647-1)){ //checking whether the input in 32 bit int range
		for(count=0;count<16;count++){	// this is to check the digits in the input
			if(argv[3][count]=='\0'){	// checking the end of input array
				break;
				}
			}
		
			if(argv[3][0]== '-'){	//for negative numbers
				for(i=1;i<count;i++){
					temp=0;	//checking whether the number is 0-9
					for(j=0;j<10;j++){
						if((argv[3][i]-'0'== j)){
							temp=1;
							}
						}
					if(temp==0){	//if it doesn't belong to any category above the input is wrong
						errorInputFormat(i);
						}
				}
			}else if(argv[3][0]!= '-'){
				for(i=0;i<count;i++){
					temp=0;	//checking whether the number is 0-9
					for(j=0;j<10;j++){
						if((argv[3][i]-'0'== j)){
							temp=1;
							}
						}
					if(temp==0){	//if it doesn't belong to any category above the input is wrong
						errorInputFormat(i);
						}
				}
			}
		}else{
			errorInputSize();
			}
	return 0;
	}
	
//------------------------------------------------------------------------------------------------------------------------------------------

int binaryChecker(char** argv){
	int i,count;
	
	for(count=0;count<65;count++){
		if(argv[3][count]=='\0'){	//end of input array
			break;
			}
		}
		
	if(count!=32&&count!=64){	//check whether the number is 32 bit or 64 bit
		errorInputSize();
		}
	for(i=0;i<count;i++){
		if((argv[3][i]-'0'!=0 )&&(argv[3][i]-'0'!= 1)){	//checking for illegal characters
			errorInputFormat(i);
		}
	}
	
	return count;
	}
		
//------------------------------------------------------------------------------------------------------------------------------------------

int hexaChecker(char** argv){
	int i,j,count,temp;
	
	for(count=0;count<64;count++){	// this is to check the digits in the input
		if(argv[3][count]=='\0'){	// checking the end of input array
			break;
			}
		}
	
	if(count!=8&&count!=16){	//check whether the number is 8 digit or 16 digit
		errorInputSize();
		}
	
	
	for(i=0;i<count;i++){
		temp=0;	//checking whether the number is 0-9
		for(j=0;j<10;j++){
			if((argv[3][i]-'0'== j)){
				temp=1;
				}
			}
		for(j=65;j<=70;j++){	//checking whether the number is A-F
			if((int)argv[3][i]==j){
				temp=1;
				}
			}
		for(j=97;j<=102;j++){	//checking whether the number is a-f
			if((int)argv[3][i]==j){
				temp=1;
				}
			}
		if(temp==0){	//if it doesn't belong to any category above the input is wrong
			errorInputFormat(i);
		}
	}
		
	return count;
	}
//-------------------------------------------------------------------------------------------------------------------------------------------

int floatChecker(char** argv){
	int i,j,count,temp,dPoint;
	for(count=0;;count++){	// this is to check the digits in the input
		if(argv[3][count]=='\0'){	// checking the end of input array
			break;
			}
	}

	//if((aToF(argv[3])<=3.4028234664e+38) && (aToF(argv[3])>=1.1754943508e-38)){ //checking whether the input in float range
	if(count<=38){ //checking whether the input in float digit range
	
			if(argv[3][0]== '-'){
				i=1;//for negative numbers
				} 
			else if(argv[3][0]!= '-'){
				i=0; // for positive numbers
				}
			dPoint=0;	// to capture the decimal point
			for(;i<count;i++){
				temp=0;	//checking whether the number is 0-9
				for(j=0;j<10;j++){
					if((argv[3][i]-'0'== j)){
						temp=1;
					}
				}
				if(argv[3][i]== '.'){
					dPoint++;	//if decimal place is found
					temp=1;
				}
				if(temp==0 || dPoint==2){	//if it doesn't belong to any category above the input is wrong
					errorInputFormat(i);
				}
			}
		}else{
			errorInputSize();
			}
	return count;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int doubleChecker(char** argv){
	int i,j,count,temp,dPoint;
	for(count=0;;count++){	// this is to check the digits in the input
		if(argv[3][count]=='\0'){	// checking the end of input array
			break;
			}
	}
	
	if(count<=308){ //checking whether the input in float digit range
			if(argv[3][0]== '-'){
				i=1;//for negative numbers
				} 
			else if(argv[3][0]!= '-'){
				i=0; // for positive numbers
				}
			dPoint=0;	// to capture the decimal point
			for(;i<count;i++){
				temp=0;	//checking whether the number is 0-9
				for(j=0;j<10;j++){
					if((argv[3][i]-'0'== j)){
						temp=1;
					}
				}
				if(argv[3][i]== '.'){
					dPoint++;	//if decimal place is found
					temp=1;
				}
				if(temp==0 || dPoint==2){	//if it doesn't belong to any category above the input is wrong
					errorInputFormat(i);
				}
			}
		}else{
			errorInputSize();
			}
	return count;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
//conversion functions

int binaryToBinary(char** argv){
	binaryChecker(argv);	//check whether the input is compatoble wit binary type
	printf("%s",argv[3]);	//if so printing the input itself
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
int binaryToHexa(char** argv){
	int count=binaryChecker(argv);//check the validity of the input number and getting whether thr number is 32 bit or 64 bit
	
	int i,j,sum;
	
	printf("0x");		// starting printing the hexa
	for(i=0;i<count;i=i+4){
		sum=0;
		for(j=i;j<i+4;j++){	//calculating the hexa value by adding sets of 4 digits by digit 
			sum=sum+(argv[3][j]-'0')*power(2,3-(j-i));
			}
		
		switch(sum){	//if the sum is greater than 10 printing the corrsponding hex value
			case 10 :
			printf("A");
		break;
			case 11 :
			printf("B");
		break;
			case 12 :
			printf("C");
		break;
			case 13 :
			printf("D");
		break;
			case 14 :
			printf("E");
		break;
			case 15 :
			printf("F");
		break;
			default:
			printf("%d",sum);
			}
		}
	return 0;

	}
//------------------------------------------------------------------------------------------------------------------------------------------
int binaryToInt(char** argv){
	int i;
	int sum=0;	
	int ar[32]={0};	//array to store value after reversing the 2's complement
	int count=binaryChecker(argv);//check the validity of the input number and getting whether thr number is 32 bit or 64 bit
	for(i=0;i<32;i++){
		ar[i]=argv[3][i]-'0';
		}
	
	if(count==32){ //the conversion is possible only if the number is 32 bit
		if(argv[3][0]-'0'==0){	// check whether it is a positive number
			/*for(i=1; i<count ;i++){
				sum=sum+(argv[3][i]-'0')*power(2,count-1-i);
				}*/
		}else{ //if negative reverse back from 2's complement
				for(i=0;i<32;i++){
						if(ar[32-i]==1){ //reducing 1
							ar[32-i]=0;
							break;
						}else{
							ar[32-i]=1;
						}
					}
				for(i=0;i<32;i++){
					if(ar[32-i]==1){ //taking complement
						ar[32-i]=0;
					}else{
						ar[32-i]=1;
						}
				}
			printf("-");
			}
		}else{	//cant represent 64 bit binary using 32 bit int
			errorImpossibleConversion();
		}
		for(i=1; i<count ;i++){	//calculation byt taking powers of 2
			sum=sum+(ar[i])*power(2,count-1-i);
			}
	printf("%d",sum);
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------

int intToBinary(char** argv){
	int i;
	int ar[32]={0}; //array to which binary is stored
	int num=aToF(argv[3]); //it is taken in float so that int range can be determined conveniently
	intChecker(argv); // Check the validity of the input
	
		if(num<0){
			num=-1*num; //taking the absolute value of the input
			}
		for(i=0;num>=1;i++){
				ar[31-i]=num%2;	//storing the int to the array in binary form 
				num=num/2;
				}
		if(aToF(argv[3])<0){ //calculating 2's complement for the negative integers
			for(i=0;i<32;i++){
					if(ar[i]==0){	//calculating 1's complement for the negative integers
						ar[i]=1;
					}else{
						ar[i]=0;	
						}
					}
					
					for(i=0;i<32;i++){
						if(ar[32-i]==0){
							ar[32-i]=1;
							break;
						}else{
							ar[32-i]=0;
						}
					}
				}
				for(i=0;i<32;i++){
						printf("%d",ar[i]);
					}
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
int intToInt(char** argv){
	intChecker(argv); //checking the validity of the input as an int
	printf("%s",argv[3]); // if valid printing the input itself
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
int intToHexa(char** argv){
	int i,j,sum;
	int ar[32]={0}; //array to which binary is stored
	int num=aToF(argv[3]); //it is taken in float so that int range can be determined conveniently
	intChecker(argv); // Check the validity of the input
	
		if(num<0){
			num=-1*num; //taking the absolute value of the input
			}
		for(i=0;num>=1;i++){
				ar[31-i]=num%2;	//storing the int to the array in binary form 
				num=num/2;
				}
		if(aToF(argv[3])<0){ //calculating 2's complement for the negative integers
			for(i=0;i<32;i++){
					if(ar[i]==0){	//calculating 1's complement for the negative integers
						ar[i]=1;
					}else{
						ar[i]=0;	
						}
					}
					for(i=0;i<32;i++){
						if(ar[32-i]==0){
							ar[32-i]=1;
							break;
						}else{
							ar[32-i]=0;
						}
					}
				}


	printf("0x");		// starting printing the hexa
	for(i=0;i<32;i=i+4){
		sum=0;
		for(j=i;j<i+4;j++){	//calculating the hexa value by adding sets of 4 digits by digit 
			sum=sum+(ar[j])*power(2,3-(j-i));
			}
		
		switch(sum){	//if the sum is greater than 10 printing the corrsponding hex value
			case 10 :
			printf("A");
		break;
			case 11 :
			printf("B");
		break;
			case 12 :
			printf("C");
		break;
			case 13 :
			printf("D");
		break;
			case 14 :
			printf("E");
		break;
			case 15 :
			printf("F");
		break;
			default:
			printf("%d",sum);
			}
		}
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
int intToFloat(char** argv){
	intChecker(argv);	//checking the input compatibility
	printf("%.2f",aToF(argv[3]));
	return 0;
	}

//------------------------------------------------------------------------------------------------------------------------------------------
int intToDouble(char** argv){
	intChecker(argv);
	errorImpossibleConversion();
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
	
int binaryToFloat(char** argv){
	int i,sign=1,exp=0;	
	float mantissa;

	int count=binaryChecker(argv);//check the validity of the input number and getting whether thr number is 32 bit or 64 bit
	
	
	if(count==32){ //if the input is 32 bit
		int ar[32]={0};		//array to store value after converting to noraml binary
		for(i=0;i<32;i++){	//storing in a array
			ar[i]=argv[3][i]-'0';
		}
		
		if(argv[3][0]-'0'==1){	// check whether it is a positive number
			sign=-1;
		}
		
		for(i=1; i<=8 ;i++){	//calculation exponent by taking powers of 2
			exp=exp+(ar[i])*power(2,8-i);
		}
		exp=exp-127;
		
		//calculating mantissa
		for(i=9; i<=31 ;i++){	//calculation mantissa by taking powers of 2
			mantissa=mantissa+(ar[i])*fracPower(2,8-i);
		}
	}else{	//if the input is 64 bit binary we can't store it in 32 bit float
		errorImpossibleConversion();
	}
	if(exp>=0){
			printf("%.2f",sign*(1+mantissa)*power(2,exp));
		}else{
			printf("%.2f",sign*(1+mantissa)*fracPower(2,exp));
			}
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------
int binaryToDouble(char** argv){
	int i,sign=1,exp=0;	
	float mantissa;

	int count=binaryChecker(argv);//check the validity of the input number and getting whether thr number is 32 bit or 64 bit
	
	
	if(count==32){ //if the input is 32 bit the conversion is not possible
		/*int ar[32]={0};		//array to store value after converting to noraml binary
		for(i=0;i<32;i++){	//storing in a array
			ar[i]=argv[3][i]-'0';
		}
		
		if(argv[3][0]-'0'==1){	// check whether it is a positive number
			sign=-1;
		}
		
		for(i=1; i<=8 ;i++){	//calculation exponent by taking powers of 2
			exp=exp+(ar[i])*power(2,8-i);
		}
		exp=exp-127;
		//calculating mantissa
		for(i=9; i<=31 ;i++){	//calculation mantissa by taking powers of 2
			mantissa=mantissa+(ar[i])*fracPower(2,8-i);
		}
		*/
		errorImpossibleConversion();
	}else{	//if the input is 64 bit binary
		
		int ar[64]={0};		//array to store value after converting to noraml binary
		for(i=0;i<64;i++){	//storing in a array
			ar[i]=argv[3][i]-'0';
		}
		
		if(argv[3][0]-'0'==1){	// check whether it is a positive number
			sign=-1;
		}
		for(i=1; i<=11 ;i++){	//calculation exponent by taking powers of 2
			exp=exp+(ar[i])*power(2,11-i);
		}
		exp=exp-1023;
		//calculating mantissa
		for(i=12; i<=63 ;i++){	//calculation mantissa by taking powers of 2
			mantissa=mantissa+(ar[i])*fracPower(2,11-i);
		}
	}
	if(exp>=0){
			printf("%f",sign*(1+mantissa)*power(2,exp));
		}else{
			printf("%f",sign*(1+mantissa)*fracPower(2,exp));
			}
	return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------------
	
int hexaToBinary(char** argv){
	int count=hexaChecker(argv);//check the validity of the input number and getting whether the number is 32 bit or 64 bit
	int i,j,k;
	int *temp;
	if(count==8){
		int ar[32]={0};	
		temp=ar;
		}
	if(count==16){
		int ar[64]={0};	
		temp=ar;
		}
	for(i=0;i<count;i++){
			switch(argv[3][i]){	//if the sum is greater than 10 printing the corrsponding hex value
			case 65 :
			case 97 :
			k=10;
		break;
			case 66 :
			case 98 :
			k=11;
		break;
			case 67 :
			case 99 :
			k=12;
		break;
			case 68 :
			case 100 :
			k=13;
		break;
			case 69 :
			case 101 :
			k=14;
		break;
			case 70 :
			case 102 :
			k=15;
		break;
			default:
			k=argv[3][i];
			}
			for(j=0;j<4;j++){
				temp[4*i+3-j]=k%2;	//storing the int to the array in binary form 
				k=k/2;
				}
		}
		for(i=0;i<4*count;i++){
			printf("%d",temp[i]);
			}
	
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------
int hexaToHexa(char** argv){
	int i=0,count=0;
	count=hexaChecker(argv);	//checking the input compatibility
	while(i<count){
		switch(argv[3][i]){	//if the sum is greater than 10 printing the corrsponding hex value
			case 97 :
			printf("A");
		break;
			case 98 :
			printf("B");
		break;
			case 99 :
			printf("C");
		break;
			case 100 :
			printf("D");
		break;
			case 101:
			printf("E");
		break;
			case 102:
			printf("F");
		break;
			default:
			printf("%c",argv[3][i]);
			}
		i++;
		}	
	return 0;
	}

//------------------------------------------------------------------------------------------------------------------------------------------
int hexaToInt(char** argv){
	int count=hexaChecker(argv);//check the validity of the input number and getting whether the number is 32 bit or 64 bit
	int i,j,k,sum;
	if(count==8){
		int ar[32]={0};	
		for(i=0;i<count;i++){
			switch(argv[3][i]){	//if the sum is greater than 10 printing the corrsponding hex value
			case 65 :
			case 97 :
			k=10;
		break;
			case 66 :
			case 98 :
			k=11;
		break;
			case 67 :
			case 99 :
			k=12;
		break;
			case 68 :
			case 100 :
			k=13;
		break;
			case 69 :
			case 101 :
			k=14;
		break;
			case 70 :
			case 102 :
			k=15;
		break;
			default:
			k=argv[3][i]-'0';
			}
			for(j=0;j<4;j++){
				ar[4*i+3-j]=k%2;	//storing the int to the array in binary form 
				k=k/2;
				}
			
			}
		for(i=0; i<count*4 ;i++){	//calculation by taking powers of 2
			sum=sum+(ar[i])*power(2,count*4-1-i);
			}
			
		}
	if(count==16){
		errorImpossibleConversion();
		}

	printf("%d",sum);	

	return 0;
}
	
//------------------------------------------------------------------------------------------------------------------------------------------
	
int hexaToFloat(char** argv){
	int count=hexaChecker(argv);//check the validity of the input number and getting whether the number is 32 bit or 64 bit
	int i,j,k;
	int sign=1,exp=0;	
	float mantissa;
	int *temp;
	if(count==8){
		int ar[32]={0};	
		temp=ar;
		}
	if(count==16){
		errorImpossibleConversion();
		}
	for(i=0;i<count;i++){
			switch(argv[3][i]){	//if the sum is greater than 10 printing the corrsponding hex value
			case 65 :
			case 97 :
			k=10;
		break;
			case 66 :
			case 98 :
			k=11;
		break;
			case 67 :
			case 99 :
			k=12;
		break;
			case 68 :
			case 100 :
			k=13;
		break;
			case 69 :
			case 101 :
			k=14;
		break;
			case 70 :
			case 102 :
			k=15;
		break;
			default:
			k=argv[3][i]-'0';
			}
			for(j=0;j<4;j++){
				temp[4*i+3-j]=k%2;	//storing the int to the array in binary form 
				k=k/2;
				}
			
		}

		if(temp[0]==1){	// check whether it is a positive number
			sign=-1;
		}
		
		for(i=1; i<=8 ;i++){	//calculation exponent by taking powers of 2
			exp=exp+(temp[i])*power(2,8-i);
		}
		exp=exp-127;
		
		//calculating mantissa
		for(i=9; i<=31 ;i++){	//calculation mantissa by taking powers of 2
			mantissa=mantissa+(temp[i])*fracPower(2,8-i);
		}
		if(exp>=0){
			printf("%.2f",sign*(1+mantissa)*power(2,exp));
		}else{
			printf("%.2f",sign*(1+mantissa)*fracPower(2,exp));
			}

	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------
int hexaToDouble(char** argv){
	int count=hexaChecker(argv);//check the validity of the input number and getting whether the number is 32 bit or 64 bit
	int i,j,k;
	int sign=1,exp=0;	
	double mantissa;
	int *temp;
	if(count==8){
		errorImpossibleConversion();
		}
	if(count==16){
		int ar[64]={0};	
		temp=ar;
		}
	for(i=0;i<count;i++){
			switch(argv[3][i]){	//if the sum is greater than 10 printing the corrsponding hex value
			case 65 :
			case 97 :
			k=10;
		break;
			case 66 :
			case 98 :
			k=11;
		break;
			case 67 :
			case 99 :
			k=12;
		break;
			case 68 :
			case 100 :
			k=13;
		break;
			case 69 :
			case 101 :
			k=14;
		break;
			case 70 :
			case 102 :
			k=15;
		break;
			default:
			k=argv[3][i]-'0';
			}
			for(j=0;j<4;j++){
				temp[4*i+3-j]=k%2;	//storing the int to the array in binary form 
				k=k/2;
				}
				
		}
	
	/*if(count==8){ //if the input is 32 bit
				
		if(temp[0]==1){	// check whether it is a positive number
			sign=-1;
		}
		
		for(i=1; i<=8 ;i++){	//calculation exponent by taking powers of 2
			exp=exp+(temp[i])*power(2,8-i);
		}
		exp=exp-127;
		//calculating mantissa
		for(i=9; i<=31 ;i++){	//calculation mantissa by taking powers of 2
			mantissa=mantissa+(temp[i])*fracPower(2,8-i);
		}
	}else{	//if the input is 64 bit binary
			*/
		if(temp[0]==1){	// check whether it is a positive number
			sign=-1;
		}
		
		for(i=1; i<=11 ;i++){	//calculation exponent by taking powers of 2
			exp=exp+(temp[i])*power(2,11-i);
		}
		exp=exp-1023;
		
		//calculating mantissa
		for(i=12; i<=63 ;i++){	//calculation mantissa by taking powers of 2
			mantissa=mantissa+(temp[i])*fracPower(2,11-i);
		}
	//}
		
	if(exp>=0){
			printf("%f",sign*(1+mantissa)*power(2,exp));
		}else{
			printf("%f",sign*(1+mantissa)*fracPower(2,exp));
			}	
	
	return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------------

int floatToBinary(char** argv){
	int count=floatChecker(argv);
	char integral[40]; //to store the integer part of the string
	char fractional[40]; //to store the decimal part in input
	int i=0,j=0,k,m;
	long long numIntegral,temp;
	double numFractional;
	int *binary;
	
	while(argv[3][i]!= '.'&& argv[3][i]!='\0'){//iterating till we find the decimal part
		integral[i]=argv[3][i];
		i++;
		}

	k=count-i;
	for(j=0;j<k;j++){ //storing the decimal part
		fractional[j]=argv[3][i];
		
		i++;
		}
	numIntegral=aToF(integral);
	numFractional=aToF(fractional);
	//handling the intgral part to store in the IEEE754
	if(numIntegral!=0){
		if(numIntegral < 9.223372036854775808E18 && numIntegral>-9.223372036854775808E18){
			 numIntegral=aToL(integral);
			}
			
		int finalBinary[255]={0};
		
		if( numIntegral<0){		//allocating first digit to 0 or 1 according to the sign of int
			finalBinary[0]=1;
			numIntegral=-1*numIntegral;
			}
		temp=numIntegral;
		i=1;
		for(numIntegral=numIntegral/2;numIntegral>=1;){ //calculating the number of digits in the binary
			numIntegral=numIntegral/2;
			i++;
			}
		m=i;
		for(;i>1;){
			finalBinary[8+i-1]=temp%2;	//storing the int to the array in binary form 
			temp=temp/2;	//printf("temp= %lld\n",temp);
			i--;
			}	
		j=(m-1+127);	//calculating the exponent value
		int l=1;	
		for(;j>=1;){	//storing the exponent to the array in binary form
			finalBinary[9-l]=j%2;
			j=j/2;
			l++;
			}

		l=m;
		for(;m<=25;m++){	//handling the fractional part to store in the IEEE754
			finalBinary[8+m]=(int)(numFractional*2);	//storing the int to the array in binary form 
			numFractional=numFractional*2;
			if(numFractional>=1){
				numFractional=numFractional-1;
				}
			
			}
		if((finalBinary[32] && finalBinary[33])||(finalBinary[32] && l >23 )){//rounding off function
			for(i=0;i<32;i++){	//adding 1
				if(finalBinary[31-i]==0){
					finalBinary[31-i]=1;
					break;
				}else{
					finalBinary[31-i]=0;
					}
			}
			}
		binary=finalBinary;			
	}else{//if the input just includes only a fraction part
		int finalBinary[34]={0};
		if( argv[3][0]== '-'){		//allocating first digit to 0 or 1 according to the sign of int
			finalBinary[0]=1;
			}
		
		i=0,j=1;
		if(numFractional!=0){
			while(!(int)(numFractional*2)){
				numFractional=numFractional*2;
				i++;
				}
				k=(-i-1+127);	
		}else{
			k=0;
		}	
		int l=1;
		for(;k>=1;){	//storing the exponent to the array in binary form
			finalBinary[9-l]=k%2;
			k=k/2;
			l++;
		}
		numFractional=numFractional*2;
		if(numFractional>=1){
			numFractional=numFractional-1;
			}
		for(;j<=25;j++){
		finalBinary[8+j]=(int)(numFractional*2);	//storing the int to the array in binary form 
		numFractional=numFractional*2;
		if(numFractional>=1){
			numFractional=numFractional-1;
			}
		}
		if(finalBinary[32] && finalBinary[33]){//rounding off function
			for(i=0;i<32;i++){	//adding 1
				if(finalBinary[31-i]==0){
					finalBinary[31-i]=1;
					break;
				}else{
					finalBinary[31-i]=0;
					}
			}
		}
		binary=finalBinary;		
	}
	for(i=0;i<=31;i++){	//printing the array element by element to form the final 32bit binary
		printf("%d",binary[i]);
			}
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------
	
int floatToHexa(char** argv){
	int count=floatChecker(argv);
	char integral[40]; //to store the integer part of the string
	char fractional[40]; //to store the decimal part in input
	int i=0,j=0,k,m;
	long long numIntegral,temp;
	double numFractional;
	int *binary;
	
	while(argv[3][i]!= '.'&& argv[3][i]!='\0'){//iterating till we find the decimal part
		integral[i]=argv[3][i];
		i++;
		}

	k=count-i;
	for(j=0;j<k;j++){ //storing the decimal part
		fractional[j]=argv[3][i];
		
		i++;
		}
	numIntegral=aToF(integral);
	numFractional=aToF(fractional);
	//handling the intgral part to store in the IEEE754
	if(numIntegral!=0){
		if(numIntegral < 9.223372036854775808E18 && numIntegral>-9.223372036854775808E18){
			 numIntegral=aToL(integral);
			}
			
		int finalBinary[255]={0};
		
		if( numIntegral<0){		//allocating first digit to 0 or 1 according to the sign of int
			finalBinary[0]=1;
			numIntegral=-1*numIntegral;
			}
		temp=numIntegral;
		i=1;
		for(numIntegral=numIntegral/2;numIntegral>=1;){ //calculating the number of digits in the binary
			numIntegral=numIntegral/2;
			i++;
			}
		m=i;
		for(;i>1;){
			finalBinary[8+i-1]=temp%2;	//storing the int to the array in binary form 
			temp=temp/2;	//printf("temp= %lld\n",temp);
			i--;
			}	
		j=(m-1+127);	//calculating the exponent value
		int l=1;	
		for(;j>=1;){	//storing the exponent to the array in binary form
			finalBinary[9-l]=j%2;
			j=j/2;
			l++;
			}

		l=m;
		for(;m<=25;m++){	//handling the fractional part to store in the IEEE754
			finalBinary[8+m]=(int)(numFractional*2);	//storing the int to the array in binary form 
			numFractional=numFractional*2;
			if(numFractional>=1){
				numFractional=numFractional-1;
				}
			
			}
		if((finalBinary[32] && finalBinary[33])||(finalBinary[32] && l >23 )){//rounding off function
			for(i=0;i<32;i++){	//adding 1
				if(finalBinary[31-i]==0){
					finalBinary[31-i]=1;
					break;
				}else{
					finalBinary[31-i]=0;
					}
				}
			}
			binary=finalBinary;				
	}else{//if the input just includes only a fraction part
		int finalBinary[34]={0};
		if( argv[3][0]== '-'){		//allocating first digit to 0 or 1 according to the sign of int
			finalBinary[0]=1;
			}
		
		i=0,j=1;
		if(numFractional!=0){
			while(!(int)(numFractional*2)){
				numFractional=numFractional*2;
				i++;
				}
				k=(-i-1+127);	
		}else{
			k=0;
			}	
		int l=1;
		for(;k>=1;){	//storing the exponent to the array in binary form
			finalBinary[9-l]=k%2;
			k=k/2;
			l++;
		}
		numFractional=numFractional*2;
		if(numFractional>=1){
			numFractional=numFractional-1;
			}
		for(;j<=25;j++){
		finalBinary[8+j]=(int)(numFractional*2);	//storing the int to the array in binary form 
		numFractional=numFractional*2;
		if(numFractional>=1){
			numFractional=numFractional-1;
			}
		}
		if(finalBinary[32] && finalBinary[33]){//rounding off function
			for(i=0;i<32;i++){	//adding 1
				if(finalBinary[31-i]==0){
					finalBinary[31-i]=1;
					break;
				}else{
					finalBinary[31-i]=0;
					}
			}
		}
		binary=finalBinary;
	}
	
	i=0,j=0;
	int sum=0;
	printf("0x");		// starting printing the hexa
	for(i=0;i<32;i=i+4){
		sum=0;
		for(j=i;j<i+4;j++){	//calculating the hexa value by adding sets of 4 digits by digit 
			sum=sum+(binary[j])*power(2,3-(j-i));
			}
		
		switch(sum){	//if the sum is greater than 10 printing the corrsponding hex value
			case 10 :
			printf("A");
		break;
			case 11 :
			printf("B");
		break;
			case 12 :
			printf("C");
		break;
			case 13 :
			printf("D");
		break;
			case 14 :
			printf("E");
		break;
			case 15 :
			printf("F");
		break;
			default:
			printf("%d",sum);
			}
		}
	return 0;

}
//------------------------------------------------------------------------------------------------------------------------------------------
int floatToInt(char** argv){
	floatChecker(argv);
	if((aToF(argv[3])<=2147483647) && (aToF(argv[3])>=(-2147483647-1))){
		warningPrecisonLoss();
		printf("%d",(int)aToF(argv[3]));
		
	}else{
		errorImpossibleConversion();
		}
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
int floatToFloat(char** argv){
	int count=floatChecker(argv);
	int i=0,k;
	
	while(argv[3][i]!= '.'&& argv[3][i]!='\0'){//iterating till we find the decimal part
		i++;
		}
	k=count-i;
	if(k-1>9){
		errorInputSize();
		}
	else if(k-1>2){
		warningPrecisonLoss();	//if there are more than 2 decimal places there is a precision loss
		}
	else if((aToF(argv[3])>9.999999999999998E15)||(aToF(argv[3])<-9.999999999999998E15)){
		warningPrecisonLoss();
		}
	printf("%.2f",aToF(argv[3]));
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
int floatToDouble(char** argv){
	floatChecker(argv);
	errorImpossibleConversion();
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------

int doubleToBinary(char** argv){
	int count=doubleChecker(argv);
	char integral[40]; //to store the integer part of the string
	char fractional[40]; //to store the decimal part in input
	int i=0,j=0,k,m;
	long long numIntegral,temp;
	double numFractional;
	int *binary; //to pass the array reference
	
	while(argv[3][i]!= '.'&& argv[3][i]!='\0'){//iterating till we find the decimal part
		integral[i]=argv[3][i];
		i++;
		}
	
	k=count-i;
	for(j=0;j<k;j++){ //storing the decimal part
		fractional[j]=argv[3][i];
		i++;
		}
	numIntegral=aToF(integral);
	numFractional=aToF(fractional);

	//handling the intgral part to store in the IEEE754
	if(numIntegral!=0){
		if(numIntegral < 9.223372036854775808E18 && numIntegral>-9.223372036854775808E18){
			 numIntegral=aToL(integral);
			}
			
		int finalBinary[255]={0};	//to store the binary number
		
		if( numIntegral<0){		//allocating first digit to 0 or 1 according to the sign of int
			finalBinary[0]=1;
			numIntegral=-1*numIntegral;
			}
		temp=numIntegral;
		i=1;
		for(numIntegral=numIntegral/2;numIntegral>=1;){ //calculating the number of digits in the binary
			numIntegral=numIntegral/2;
			i++;
			}
		m=i;
		for(;i>1;){
			finalBinary[11+i-1]=temp%2;	//storing the int to the array in binary form 
			temp=temp/2;	//printf("temp= %lld\n",temp);
			i--;
			}	
		j=(m-1+1023);	//calculating the exponent value
		int l=1;	
		for(;j>=1;){	//storing the exponent to the array in binary form
			finalBinary[12-l]=j%2;
			j=j/2;
			l++;
			}

		l=m;
		for(;m<=54;m++){	//handling the fractional part to store in the IEEE754
			finalBinary[11+m]=(int)(numFractional*2);	//storing the int to the array in binary form 
			numFractional=numFractional*2;
			if(numFractional>=1){
				numFractional=numFractional-1;
				}
			
			}
		if((finalBinary[64] && finalBinary[65])||(finalBinary[64] && l >52 )){//rounding off function
			for(i=0;i<64;i++){	//adding 1
				if(finalBinary[63-i]==0){
					finalBinary[63-i]=1;
					break;
				}else{
					finalBinary[63-i]=0;
					}
			}
			}
			binary=finalBinary;
	}else{	//if the input just includes only a fraction part
		int finalBinary[66]={0};
		if( argv[3][0]== '-'){		//allocating first digit to 0 or 1 according to the sign of int
			finalBinary[0]=1;
			}
		
		i=0,j=1;
		if(numFractional!=0){ //if the input is zero
			while(!(int)(numFractional*2)){
				numFractional=numFractional*2;
				i++;
				}
				k=(-i-1+1023);	
		}else{
			k=0;
			}	
		
		int l=1;
		for(;k>=1;){	//storing the exponent to the array in binary form
			finalBinary[12-l]=k%2;
			k=k/2;
			l++;
		}
	
		numFractional=numFractional*2;
		if(numFractional>=1){
			numFractional=numFractional-1;
			}
		j=0;
		for(;j<=54;j++){
		finalBinary[12+j]=(int)(numFractional*2);	//storing the int to the array in binary form 
		numFractional=numFractional*2;
		if(numFractional>=1){
			numFractional=numFractional-1;
			}
		}
		if(finalBinary[64] && finalBinary[65]){//rounding off function
			for(i=0;i<64;i++){	//adding 1
				if(finalBinary[63-i]==0){
					finalBinary[63-i]=1;
					break;
				}else{
					finalBinary[63-i]=0;
					}
			}
		}
		binary=finalBinary;
	}
	for(i=0;i<=63;i++){	//printing the array element by element to form the final 32bit binary
			printf("%d",binary[i]);
			}
				
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------

int doubleToHexa(char** argv){
	int count=doubleChecker(argv);
	char integral[40]; //to store the integer part of the string
	char fractional[40]; //to store the decimal part in input
	int i=0,j=0,k,m;
	long long numIntegral,temp;
	double numFractional;
	int *binary; //to pass the array reference
	
	while(argv[3][i]!= '.'&& argv[3][i]!='\0'){//iterating till we find the decimal part
		integral[i]=argv[3][i];
		i++;
		}
	
	k=count-i;
	for(j=0;j<k;j++){ //storing the decimal part
		fractional[j]=argv[3][i];
		i++;
		}
	numIntegral=aToF(integral);
	numFractional=aToF(fractional);

	//handling the intgral part to store in the IEEE754
	if(numIntegral!=0){
		if(numIntegral < 9.223372036854775808E18 && numIntegral>-9.223372036854775808E18){
			 numIntegral=aToL(integral);
			}
			
		int finalBinary[255]={0};	//to store the binary number
		
		if( numIntegral<0){		//allocating first digit to 0 or 1 according to the sign of int
			finalBinary[0]=1;
			numIntegral=-1*numIntegral;
			}
		temp=numIntegral;
		i=1;
		for(numIntegral=numIntegral/2;numIntegral>=1;){ //calculating the number of digits in the binary
			numIntegral=numIntegral/2;
			i++;
			}
		m=i;
		for(;i>1;){
			finalBinary[11+i-1]=temp%2;	//storing the int to the array in binary form 
			temp=temp/2;	//printf("temp= %lld\n",temp);
			i--;
			}	
		j=(m-1+1023);	//calculating the exponent value
		int l=1;	
		for(;j>=1;){	//storing the exponent to the array in binary form
			finalBinary[12-l]=j%2;
			j=j/2;
			l++;
			}

		l=m;
		for(;m<=54;m++){	//handling the fractional part to store in the IEEE754
			finalBinary[11+m]=(int)(numFractional*2);	//storing the int to the array in binary form 
			numFractional=numFractional*2;
			if(numFractional>=1){
				numFractional=numFractional-1;
				}
			
			}
		if((finalBinary[64] && finalBinary[65])||(finalBinary[64] && l >52 )){//rounding off function
			for(i=0;i<64;i++){	//adding 1
				if(finalBinary[63-i]==0){
					finalBinary[63-i]=1;
					break;
				}else{
					finalBinary[63-i]=0;
					}
			}
			}
			binary=finalBinary;
	}else{	//if the input just includes only a fraction part
		int finalBinary[66]={0};
		if( argv[3][0]== '-'){		//allocating first digit to 0 or 1 according to the sign of int
			finalBinary[0]=1;
			}
		
		i=0,j=1;
		if(numFractional!=0){ //if the input is zero
			while(!(int)(numFractional*2)){
				numFractional=numFractional*2;
				i++;
				}
				k=(-i-1+1023);	
		}else{
			k=0;
			}	
		
		int l=1;
		for(;k>=1;){	//storing the exponent to the array in binary form
			finalBinary[12-l]=k%2;
			k=k/2;
			l++;
		}
	
		numFractional=numFractional*2;
		if(numFractional>=1){
			numFractional=numFractional-1;
			}
		j=0;
		for(;j<=54;j++){
		finalBinary[12+j]=(int)(numFractional*2);	//storing the int to the array in binary form 
		numFractional=numFractional*2;
		if(numFractional>=1){
			numFractional=numFractional-1;
			}
		}
		if(finalBinary[64] && finalBinary[65]){//rounding off function
			for(i=0;i<64;i++){	//adding 1
				if(finalBinary[63-i]==0){
					finalBinary[63-i]=1;
					break;
				}else{
					finalBinary[63-i]=0;
					}
			}
		}
		binary=finalBinary;
	}

	i=0,j=0;
	int sum=0;
	printf("0x");		// starting printing the hexa
	for(i=0;i<64;i=i+4){
		sum=0;
		for(j=i;j<i+4;j++){	//calculating the hexa value by adding sets of 4 digits by digit 
			sum=sum+(binary[j])*power(2,3-(j-i));
			}
		
		switch(sum){	//if the sum is greater than 10 printing the corrsponding hex value
			case 10 :
			printf("A");
		break;
			case 11 :
			printf("B");
		break;
			case 12 :
			printf("C");
		break;
			case 13 :
			printf("D");
		break;
			case 14 :
			printf("E");
		break;
			case 15 :
			printf("F");
		break;
			default:
			printf("%d",sum);
			}
		}
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------------
int doubleToInt(char** argv){
	doubleChecker(argv);
	errorImpossibleConversion();
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
int doubleToFloat(char** argv){
	doubleChecker(argv);
	errorImpossibleConversion();
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
int doubleToDouble(char** argv){
	doubleChecker(argv);
	int count=doubleChecker(argv);
	int i=0,k;
	
	while(argv[3][i]!= '.'&& argv[3][i]!='\0'){//iterating till we find the decimal part
		i++;
		}
	k=count-i;
	if(k-1>9){
		errorInputSize();
		}
	else if(k-1>6){
		warningPrecisonLoss();	//if there are more than 2 decimal places there is a precision loss
		}
	//else if((aToF(argv[3])>9.999999999999998E15)||(aToF(argv[3])<-9.999999999999998E15)){
	//	warningPrecisonLoss();
	//	}
	printf("%f",aToF(argv[3]));
	return 0;
	}
//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------

//error handling functions
void errorNumberOfArguments(){
	fprintf(stderr,"ERROR: The number of arguments is wrong.\nUsage: ./clc -<input format> -<output format> <input>"); //error message for Wrong number of arguments
	exit(1);
	
	}
void errorInputArgument(char** argv){
	int count=0;
	if(argv[1][0]=='-'){
		count++;
	}
	if(argv[1][1]=='B'||argv[1][1]=='H'||argv[1][1]=='I'||argv[1][1]=='F'||argv[1][1]=='D'){
		count++;
	}
	int i=0;
	while(argv[1][i]!='\0'){
		i++;
		}
	if(count!=2 || i!=2){
		fprintf(stderr,"ERROR: The input argument is wrong.\nPossible input arguments are -B, -H, -I, -F  and -D"); //error message for Wrong input argument
		exit(1);
	}
}
void errorOutputArgument(char** argv){
	int count=0;
	if(argv[2][0]=='-'){
		count++;
	}
	if(argv[2][1]=='B'||argv[2][1]=='H'||argv[2][1]=='I'||argv[2][1]=='F'||argv[2][1]=='D'){
		count++;
	}
	int i=0;
	while(argv[2][i]!='\0'){
		i++;
		}
	if(count!=2 || i!=2){
		fprintf(stderr,"ERROR: The output argument is wrong.\nPossible output arguments are -B, -H, -I, -F  and -D"); //error message for Wrong output argument
		exit(1);
	}
}
void errorInputSize(){
	fprintf(stderr,"ERROR: The input size is wrong."); //error message for wrong input size
	exit(1);
	
	}
void errorInputFormat(int i){
	fprintf(stderr,"ERROR:  Input format error at location %d.",i); //error message for illegal charaters
	exit(1);
	}
void errorImpossibleConversion(){
	fprintf(stderr,"ERROR:  This conversion is not possible.");	//error message for conversions that are not possible
	exit(1);
	
	}
void warningPrecisonLoss(){
	fprintf(stderr,"WARNING:  There is a possibility for a precision loss.");//error message for conversions that will lose/reduce precision
	}
//---------------------------------------------------------------------END------------------------------------------------------------------
