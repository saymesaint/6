#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char *name;
        char *opens;
        char *closes;
	struct island *next;
} island;

void display(island *start){
	island *i=start;
	for (;i !=NULL; i=i->next){
		printf("Name: %s\topen: %s - %s\n",i->name,i->opens,i->closes);
	}
}

island* create(char* name){
	island* i = malloc(sizeof(island));
	i->name=strdup(name);
	i->opens="09:00";
	i->closes= "17:00";
	i->next=NULL;
	return i;
}
	
int main(){
	/*island amity ={"friendship","09:00","17:00",NULL};
        island craggy={"stones","09:00","17:00",NULL};
        island isla_nublar ={"smoky","09:00","17:00",NULL};
        island shutter ={"curse","09:00","17:00",NULL};
	amity.next=&craggy;
	craggy.next=&isla_nublar;
	isla_nublar.next=&shutter;
	island skull={"Skull","09:00","17:00",NULL};
	isla_nublar.next=&skull;
	skull.next=&shutter;

	display(&amity);*/
	island *start = NULL;
	island *i=NULL;
	island *next=NULL;
	char name[80];
	for (;fgets(name, 80,stdin)!=NULL; i=next){
		next = create (name);
		if (start==NULL)
			start=next;
		if(i !=NULL)
			i->next=next;
	}
	display(start);
	return 0;
}
