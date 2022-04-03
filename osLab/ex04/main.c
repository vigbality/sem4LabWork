#include<stdio.h>
#include<stdlib.h>


struct process{
	int id,at,bt,p;
};
struct gantt{
	int id,s,e;
};



int checkDone(struct process arr[], int n){
	for(int i=0;i<n;i++){
		if(arr[i].bt>0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int n=5;
	struct process table[69];
	struct gantt chart[69];
	for(int i=0;i<n;i++){
		printf("Enter process id: ");scanf("%d",&table[i].id);
		printf("Enter arrival time: ");scanf("%d",&table[i].at);
		printf("Enter burst time: ");scanf("%d",&table[i].bt);
		printf("Priority: ");scanf("%d",&table[i].p);
	}
	int time=0,done=0,curr=-1,priority=n,currGantt=0;
	while(done!=1){
		priority=n;curr=-1;
		for(int i=0;i<=n;i++){
			if(table[i].at<=time && table[i].bt>0 && table[i].p<=priority){
				curr=i;
				priority=table[i].p;
			}
		}
		if(chart[0].id==NULL){
			chart[0].id=
		}
		
	}		
}
