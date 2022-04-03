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

void printGantt(struct gantt arr[], int n){
	printf("%d",arr[0].s);
	for(int i=0;i<=n;i++){
		printf("  |P%d|  %d",arr[i].id,arr[i].e);
	}
	printf("\n");
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
	int time=0,done=0,curr=-1,priority=1,currGantt=-1;
	while(done!=1){
		priority=1;curr=-1;
		for(int i=0;i<=n;i++){
			if(table[i].at<=time && table[i].bt>0 && table[i].p>priority){
				curr=table[i].id;
				priority=table[i].p;
			}
		}
		if(currGantt==-1){
			chart[0].id=curr;
			chart[0].s=0;
			chart[0].e=1;
			currGantt++;
			done=checkDone(table,n);
		}
		else if(chart[currGantt].id==curr){
			chart[currGantt].e++;
			done=checkDone(table,n);
		}
		else{
			chart[currGantt+1].id=curr;
			chart[currGantt+1].s=chart[currGantt].e;
			chart[currGantt+1].e=chart[currGantt].e+1;
			done=checkDone(table,n);
			if(done!=1) currGantt++;
		}
		table[curr-1].bt--;
		time++;
	}
	printGantt(chart,currGantt);		
	return 0;
}
