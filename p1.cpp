//#include "StaticQueues.h"
//#include "circularqueue.h"
//...............static inorder circuilar queue...........

//#ifndef STATICQUEUES_H_
//#define STATICQUEUES_H_

const int maxQueue = 200;
template <class QueueElementType>
class StaticQueue {
public:
    StaticQueue();
    bool enqueue(const QueueElementType& item);
    bool dequeue(QueueElementType& item);
    bool front(QueueElementType& item);
    bool isEmpty();
    bool isExist(const QueueElementType& item);


private:
    int front_index; // indicates front
    int rear_index; // indicates rear
    QueueElementType queueArray[maxQueue];
    int nextPosition(int pointer);
    int pastPosition(int pointer);

};

template <class QueueElementType>
StaticQueue<QueueElementType>::StaticQueue()
{
    front_index = 0;
    rear_index = 0;
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::enqueue(const QueueElementType& item)
{
    if (nextPosition(rear_index) == front_index) {
        return false; // Queue is Full
    }
    else {//if empty or item(inserted)< front item then insert in front next position
    	//if not empty while(item>array[i] i++
    	//shift and put item in array[i]
    	//insert item.
    	if(isEmpty() || item<queueArray[nextPosition(front_index)] )
    	{    		for(int i=nextPosition(rear_index); i>front_index;i--){
    			queueArray[i]=queueArray[pastPosition(i)];
    	}
    	queueArray[nextPosition(front_index)]=item;
    	}
    	else{
    		int i =nextPosition(front_index);
    		while(item>queueArray[i] && i<=rear_index) i=nextPosition(i);
      for(int j=nextPosition(rear_index); j>i;j--){
    		   queueArray[j]=queueArray[pastPosition(j)];
    		    	}
		queueArray[i]=item;

    	}
        rear_index = nextPosition(rear_index);
        return true;
    }
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::dequeue(QueueElementType& item)
{
    if (rear_index == front_index) {
        return false; // Queue is Empty
    }
    else {
        front_index = nextPosition(front_index);
        item = queueArray[front_index];
        return true;
    }
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::front(QueueElementType& item)
{
    if (rear_index == front_index) {
        return false; // Queue is Empty
    }
    else {
        item = queueArray[nextPosition(front_index)];
        return true;
    }
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::isEmpty()
{
    return bool(rear_index == front_index);
}

template <class QueueElementType>
int StaticQueue<QueueElementType>::nextPosition(int pointer)
{
    return ((pointer + 1) % maxQueue);
}

template <class QueueElementType>
int StaticQueue<QueueElementType>::pastPosition(int pointer)
{
     pointer=(pointer - 1) % maxQueue;
    if(pointer<0) pointer+=maxQueue;
    return pointer;
}

template <class QueueElementType>
bool StaticQueue<QueueElementType>::isExist(const QueueElementType& item)
{
	if(isEmpty()) return false;

	for(int i=(rear_index); i>front_index;i=pastPosition(i)){
	if(item==queueArray[i]) return true;
}
	return false;
}


//#endif /* STATICQUEUES_H_ */

//.......circular queue(not in order) for drop queue.................


//#ifndef CIRCULARQUEUE_H_
//#define CIRCULARQUEUE_H_
const int maxQueue2=200;

template <class QueueElementType>
class circularqueue {
public:
    circularqueue();
    bool enqueue(const QueueElementType& item);
    bool dequeue(QueueElementType& item);
    bool front(QueueElementType& item);
    bool isEmpty();



private:
    int front_index; // indicates front
    int rear_index; // indicates rear
    QueueElementType queueArray[maxQueue2];
    int nextPosition(int pointer);
};

 template <class QueueElementType>
    circularqueue<QueueElementType>::circularqueue()
    {
        front_index = 0;
        rear_index = 0;

    }

template <class QueueElementType>
bool circularqueue<QueueElementType>::enqueue(const QueueElementType& item)
{
    if (nextPosition(rear_index) == front_index) {
        return false; // Queue is Full
    }
    else {
        rear_index = nextPosition(rear_index);
        queueArray[rear_index] = item;
        return true;
    }
}

template <class QueueElementType>
bool circularqueue<QueueElementType>::dequeue(QueueElementType& item)
{
    if (rear_index == front_index) {
        return false; // Queue is Empty
    }
    else {
        front_index = nextPosition(front_index);
        item = queueArray[front_index];
        return true;
    }
}

template <class QueueElementType>
bool circularqueue<QueueElementType>::front(QueueElementType& item)
{
    if (rear_index == front_index) {
        return false; // Queue is Empty
    }
    else {
        item = queueArray[nextPosition(front_index)];
        return true;
    }
}

template <class QueueElementType>
bool circularqueue<QueueElementType>::isEmpty()
{
    return bool(rear_index == front_index);
}

template <class QueueElementType>
int circularqueue<QueueElementType>::nextPosition(int pointer)
{
    return ((pointer + 1) % maxQueue2);
}

//#endif /* circularqUEUES_H_ */



#include<string.h>
#include<string>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<cstdio>
#include <ctype.h>
using namespace std;

//...................global variables...................
int maxSeq=0;
int numofbits=0;
int winsize=1;
int error=0;
int maxSeqError=0;
int initialSeq=0;
int expected=0;
int rangeMax=0;
int recieved=0;
int flag=0;
int expectedWithoutMod=0;
int diff=1;
StaticQueue<int> Rqueue;
StaticQueue<int> Wqueue;
circularqueue<int> Dqueue;
int x=0;

//...................functions..........................
bool is_number(const std::string& s);
int power(int x,int y);
int convertToInt(char* a, int size) ;
void packetsdivision(int argc,char*argv[]);

//...................main..........................
int main(int argc,char *argv[]){
	error=0;

//...................error handling..........................
//...................number of arguments.........................

	if(argc<=4){
		printf("Invalid number of arguments");
		error=1;
	}
	if(argc<2) return 0;

	//.................number of bits......................
if(!is_number(argv[1])){
	if(error==1)
			printf(" %s","Invalid seqNumBits");
		else printf("%s","Invalid seqNumBits");
	error=1;
	maxSeqError=1;
}
else {
	 numofbits = convertToInt(argv[1],sizeof(argv[1]));
	 if(numofbits<=0) {
			if(error==1)
					printf(" %s","Invalid seqNumBits");
				else printf("%s","Invalid seqNumBits");
			error=1;
			maxSeqError=1;
	 }
	maxSeq=power(2,numofbits)-1;
}
if(argc<3) return 0;
//....................window size not a number...............
if(!is_number(argv[2])){
	if(error==1)
				printf(" %s","Invalid winSize");
			else printf("%s","Invalid winSize");
	error=1;
}
else // then it is a number
	{
	winsize = convertToInt(argv[2],sizeof(argv[2]));
if(winsize<=0 ||(maxSeqError==0 && winsize>maxSeq)) {
	if(error==1)
				printf(" %s","Invalid winSize");
			else printf("%s","Invalid winSize");
	error=1;
}
	}
if(argc<4) return 0;

//....................init seq not a number...............
if(!is_number(argv[3])){
	if(error==1)
				printf(" %s","Invalid initSeq");
			else printf("%s","Invalid initSeq");
	error=1;
}
else{//then it is a num
	initialSeq = convertToInt(argv[3],sizeof(argv[3]));
if (initialSeq<0 ||(maxSeqError==0 && initialSeq>maxSeq)){
	if(error==1)
						printf(" %s","Invalid initSeq");
					else printf("%s","Invalid initSeq");
			error=1;}
}

//..............check if packets ids are nums and less than max Seq.............
for(int i=4;i<argc;i++){
	int packetId=0;
	if (!is_number(argv[i])){
		if(error==1){
					printf(" %s","Invalid packet ID");
					}
				else{ printf("%s","Invalid packet ID");
				}
		error=1;
	}
	else // then a num (check if greater than maxseq)
	{
		packetId = convertToInt(argv[i],sizeof(argv[i]));
		if(packetId<0 || (maxSeqError==0 && packetId>maxSeq )){
			if(error==1)
								printf(" %s","Invalid packet ID");
							else printf("%s","Invalid packet ID");
		error=1;
		}
	}//end else
	}//for
if(error==1) return 0;

//....................no error(main program:) .........................
else{ // then all packets are available from argc-1 to 4
expected=initialSeq;
expectedWithoutMod=expected;
rangeMax=(expected+winsize-1);
// function packets division...............
packetsdivision(argc,argv);

//..................printing packets..................
printf("R ");
for(int i=4; i<argc;i++){
	if(Rqueue.dequeue(x)){
      if(x>maxSeq) x=x%(maxSeq+1);

	printf("%d ",x);
}
}
if(expected>maxSeq) printf("E %d",(expected%(maxSeq+1)));
else
printf("E %d",expected);

printf(" W");

for(int i=4; i<argc;i++){
	if(Wqueue.dequeue(x)){
      if(x>maxSeq) x-=(maxSeq+1);

	printf(" %d",x);
}
}

printf(" D");

while(Dqueue.dequeue(x)){

      if(x>maxSeq) x-=(maxSeq+1);

	printf(" %d",x);

}

}//end else(no error)


return 0;
}//main

//...................functions.................
bool is_number(const std::string& s)
	{
	    std::string::const_iterator it = s.begin();
	    while (it != s.end() && std::isdigit(*it)) ++it;
	    return !s.empty() && it == s.end();
	}

int power(int x,int y){
	int ans=1;
	for(int i=0; i<y; i++)
	       ans *= x;
	return ans;
}

// convert array of chars to int
int convertToInt(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    int n=stoi(s);
    return n;
}//convertToInt


//................packets division...........

void packetsdivision(int argc,char*argv[]){
	for(int i=4; i<argc;i++){
	recieved = convertToInt(argv[i],sizeof(argv[i]));
	if (recieved<expected){
		//this claculation to calculate recieved successfully
		diff=expected-recieved;
		diff=diff/(maxSeq+1);
		if(diff==0) diff=1;
		recieved= recieved +(maxSeq+1)*diff;
	}

	if(recieved<=rangeMax && recieved>=expected &&
		!Wqueue.isExist(recieved) && !Rqueue.isExist(recieved))
	{

	Wqueue.enqueue(recieved);
	while(Wqueue.dequeue(recieved)){

		if(recieved != expected)
			{
			Wqueue.enqueue(recieved);
			break;
			}

		Rqueue.enqueue(recieved);
		expected=(expected+1);
		rangeMax=(expected+winsize-1);
		flag=1;
	}


	}
	else{
		Dqueue.enqueue(recieved);
	}
	}//for loop
}//packets division

