#include<stdio.h>
#include<string.h>
#include<string>
#include<cstdio>
#include <ctype.h>
using namespace std;
//instead of calling startonly.h cause we have to submit one file
//...................declaration of functions....................
void print(char *argv[],int argc);
void reverse(char *argv[],int argc);
void shuffle(char *argv[],int argc);
void upper (char *argv[],int argc);
void shuffleStatment (char *argv[],int argc);
bool isNumberwithabs(char* s) ;
bool isNumberwithoutabs(char* s) ;
void delete1 (char *argv[],int argc);
void middle2 (char *argv[],int argc);
//3.8 add function declaration
void add (char *argv[],int argc);

//3.9 random function declaration
void random (char *argv[],int argc);

/*.....................................................................*/
//.....................main function...............
//argc is the number of words including the program name
//argv is a pointer to array of strings i.e: argv[0]=first word (program name)
int main(int argc,char *argv[]){
	//char command[]="print";
	//int x= strcmp(argv[1], command);
if(  !strcmp(argv[1], "print")){
print(argv,argc);
}
else if(!strcmp(argv[1], "reverse")){
	reverse(argv,argc);
}
else if(!strcmp(argv[1], "upper")){
	upper(argv,argc);
}
else if(!strcmp(argv[1], "shuffle")){
	shuffle(argv,argc);
}
else if(!strcmp(argv[1], "shuffleStatement")){
	shuffleStatment(argv,argc);
}
else if(!strcmp(argv[1], "delete")){
	delete1(argv,argc);
}
else if(!strcmp(argv[1], "middle")){
	middle2(argv,argc);
}
//3.8 add function
else if(!strcmp(argv[1], "add")){
	add(argv,argc);
}

//3.9 random function
else if(!strcmp(argv[1], "random")){
	random(argv,argc);
}


else{
	printf("Undefined Command");
}

return 0;
}
void print(char *argv[],int argc){
	if(argv[2]==0) printf("%s","Incorrect Number of Arguments");
	else{
	printf("%s",argv[2]);
for(int i = 3; argv[i]!=0;i++){
	printf(" %s",argv[i]);
}
}
}

void reverse(char *argv[],int argc){
	if(argv[2]==0) printf("%s","Incorrect Number of Arguments");
	else{
		printf("%s",argv[argc-1]);
		for(int i = argc-2;i>1;i--){
			printf(" %s",argv[i]);
		}

	}

}
void upper(char *argv[],int argc){
	if(argv[2]==0) printf("%s","Incorrect Number of Arguments");
	else{ for(int i =2;i<argc;i++){
//		std:: string *st=*argv[i];
		for(int j =0;j<strlen(argv[i]);j++){
		if(argv[i][j]>=97 && argv[i][j]<=122){
			argv[i][j]=argv[i][j]-32;}
		}}

//	std::locale loc;
//	  std::string str="Test String.\n";
//	  for (std::string::size_type i=0; i<str.length(); ++i)
//	    std::cout << std::toupper(str[i],loc);

		print(argv,argc);
	}
	}
void shuffle(char *argv[],int argc){
	if(argv[2]==0) printf("%s","Incorrect Number of Arguments");
	else if(argc==3){
		for(int j =0;j<strlen(argv[2])-1;j+=2){
//			if(argv[2][j+1]!='/0'){
					char temp= argv[2][j];
					argv[2][j]=argv[2][j+1];
					argv[2][j+1]=temp;
					}
		print(argv,argc);
	}


	else{
		printf("%s","Incorrect Number of Arguments");

	//		std:: string *st=*argv[i];

}

}

void shuffleStatment (char *argv[],int argc){
	if(argv[2]==0) printf("%s","Incorrect Number of Arguments");
		else{ for(int i =2;i<argc-1;i+=2){
		char *temp=argv[i];
		argv[i]=argv[i+1];
		argv[i+1]=temp;

		}
		print(argv,argc);
		}

}
void delete1 (char *argv[],int argc){
	//int x=argc-3;
	int x=0;
	for(int i =0;argv[i]!=0 ;i++){
				x+=1;
			}
	x=x-3;


	if(argv[2]==0 ) printf("%s","Incorrect Number of Arguments");
	else if(! isNumberwithoutabs(argv[2])){
		printf("%s","Incorrect Data Type");
	}
	else{
		int myint1 = stoi(argv[2]);
	 if(myint1>x) {
		printf("%s","Incorrect Number of Arguments");
//		printf("   %d",x);

	}
	else{
	//	delete (argv[(argv[2]+2)]);
		for(int i =myint1+2;argv[i]!=0 ;i++){
			argv[i]=argv[i+1];
		}
		if(myint1!=0){
		for(int i =3;argv[i]!=0 ;i++){
			if(i==3) printf("%s",argv[i]);
			else{
					printf(" %s",argv[i]);
				}}
		}//end if

		else if(myint1==0){
		//argv[2]="";
		print(argv,argc);
	}
//	print(argv,argc);

	}
	}


}
bool isNumberwithoutabs(char* s) {
	for (int i = 0; i < strlen(s); i++)
	        if (isdigit(s[i]) == false){

	            return false;
	        }
	    return true;
}

bool isNumberwithabs(char* s)
{
    for (int i = 0; i < strlen(s); i++)
    { if (s[i]==45) continue;
    	if (isdigit(abs(s[i])) == false){
    	return false;
    }
    }
    return true;
}

//bool is_number(const std::string& s)
//{
//    std::string::const_iterator it = s.begin();
//    while (it != s.end() && std::isdigit(*it)) ++it;
//    return !s.empty() && it == s.end();
//}
void middle2 (char *argv[],int argc){
	if(argv[2]==0 ) printf("%s","Incorrect Number of Arguments");
	else{
	if(argc%2==0){
		char* temp=argv[(argc-2)/2+2];
		argv[2]=argv[(argc-2)/2-1+2];
		argv[3]=temp;
		argv[4]=0;
	}
	else{
		argv[2]=argv[(argc-2)/2+2];
		argv[3]=0;

	}
	print(argv,argc);
}//end else
}//end function middle2

//3.8 add function initialization
void add (char *argv[],int argc){
	if(argv[2]==0 ) printf("%s","Incorrect Number of Arguments");
		else{
			int notNumberFound=0;
			for (int i=2;argv[i]!=0;i++){
				//int absolute = abs(argv[i]);

				if(! isNumberwithabs(argv[i])){
				//for(int j=0;j<strlen(argv[i]);j++){
//					int x = *argv[i];
//					if (x<0)  x =-x;
//				if(! isdigit(x)){
				    printf("%s","Incorrect Data Type");
			        notNumberFound =1;
			    	break;

				}
		}
if(notNumberFound==0){
	int sum=0;
	for(int i=2;argv[i]!=0;i++){
		int myint1 = stoi(argv[i]);
		sum+=myint1;
	}

printf("%d",sum);
}
		}

}

//3.9 random function initialization
void random (char *argv[],int argc){
	int numOfArgTrue = 1;
	int allNums=1;
	int errorminmax=0;
int morethan4args =0;
if(argc>6) morethan4args=1;
	for(int i=2;i<=5;i++){
	if(argv[i]==0 || morethan4args) {printf("%s","Incorrect Number of Arguments");
	numOfArgTrue=0;
	break;
	}//end if
	}//end for

	if(numOfArgTrue ==1 ){
				for (int i=2;argv[i]!=0;i++){
					if(i==2 || i==5){
					if(! isNumberwithabs(argv[i])){
						printf("%s","Incorrect Data Type");
						allNums =0;
						break;
					}//end if
					else{
						//min and max can be negatives
						if(! isNumberwithabs(argv[i])){
												printf("%s","Incorrect Data Type");
												allNums =0;
												break;
						}//end if
					}//end else
					}//end if
			}//end for

	if(allNums==1  ){
//if 4 arguments provided(length,min,max,seed) and all arguments are integers
		int seed = stoi(argv[5]);
								int min =  stoi(argv[3]);
								int max =  stoi(argv[4]);
								int length=stoi(argv[2]);
								if(min>max) {
									errorminmax=1;
									//printf error min greater than max
								printf("%s","Incorrect Number of Arguments");
								}//end if
								else{
		srand(seed);
		int i=0;
		while(i<length){
			int x= rand()%(max-min+1) + min ;
			i++;
			printf("%d ",x);
//			if(x>=min && x<=max){
//				printf("%d ",x);
//				i++;
//			}//end if

		}//end while

}//end else

	}//end if
	}//end if
}// end random function
