#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int noop=0;     // this is number of passengers
int nobok=0;      //no of tickets booked

char city[4]= {'A','B','C','X'};


// defining passengers

typedef struct passenger
{
    char name[100];
    char gen;
    int age;
}passenger;

passenger pas[50];



// defining bus

typedef struct bus{
    char busno[20];
    int totseat;
    int avseat;
    int fare;
}buses;

buses bus;




// the function to take passenger info 

void booking(){

    printf("Please enter the number of passengers \n");
    scanf("%d",&noop);
    printf("Please enter your details bellow\n");
    for(int i=0;i<noop;i++){

        printf("Enter name of passenger %d : \n",i+1);
        getchar();
        fgets(pas[i].name,100,stdin);

        printf("Enter age of passenger %d : \n",i+1);
        scanf("%d",&pas[i].age);

        printf("Enter gender of passenger %d (Male - 'M'| Female - 'F') : \n",i+1);
        scanf(" %c", &pas[i].gen);
    }
}



char from;
char to;


void routecheck(){             //this function checks if a bus is available for the selected route 

    printf("\nEnter journey details.\n");
    printf("Available services in cities 'A' , 'B' , 'C' , 'X'.\n");
    printf("From : ");
    scanf(" %c", &from);
    printf("To : ");
    scanf(" %c", &to);

    int p=0;
    for(int i=0;i<5;i++){
        if(from == city[i]){
            for(int j=0;j<5;j++){
                if(to == city[j]){
                    if(from == 'X'){
                        if(to != 'A'){
                            p = 13;          // if p = 13 then there is no city other then A from X
                            break;
                        }
                    }
                    p = 23;            // if p = 23 then the from and to are citis with buses
                }
            }
        }
    }
    if(p==13){
        printf("\n\nBus is not available between the selected cities . Please select the right cityies.");
    }
    if(p == 23){
        printf("\n\nBus is available for the selected cities.");
    }
    
}





const char* busfind(){         // this function returns the bus number for the selected route
    
    if(from == 'A'){
        if(to =='B'){
           return "A-14";
        }
        if(to == 'C'){
           return "B-32";
        }
        if(to == 'X'){
           return "AP-99";
        }
    }
    if(from == 'B'){
        if(to == 'A'){
           return "X-44";
        }
        if(to == 'C'){
           return "Z-20";
        }
    }
    if(from == 'C'){
        if(to == 'A'){
           return "F-60";
        }
        if(to == 'B'){
           return "C-12";
        }
    }
    if((from == 'X') && (to == 'A')){
           return "PP-19";
    }

   
}

//this funtction gives the status of ticket and the ticket number 



int tick_num[100];





// this function gives details about bus and gives the running stasus of it
void bus_status(){

    char rand_char;
    srand(time(0));
    rand_char = 'A' + rand()%26;

    char sudonum[20];
    printf("Whitch bus do you want to track? \n Enter bus number : ");
    scanf("%s",sudonum);

    printf("\n");

    if(!strcmp(sudonum,"A-14")){
        printf("Bus goes from A to B\n");
        printf("The bus currently at city %c \n",rand_char);
    }


    if(!strcmp(sudonum,"B-32")){
        printf("Bus goes from A to c\n");
        printf("The bus currently at city %c \n",rand_char);
    }


    if(!strcmp(sudonum,"AP-99")){
        printf("Bus goes from A to X\n");
        printf("The bus currently at city %c \n",rand_char);
    }


    if(!strcmp(sudonum,"X-44")){
        printf("Bus goes from B to A\n");
        printf("The bus currently at city %c \n",rand_char);
    }


    if(!strcmp(sudonum,"Z-20")){
        printf("Bus goes from B to C\n");
        printf("The bus currently at city %c \n",rand_char);
    }


    if(!strcmp(sudonum,"F-60")){
        printf("Bus goes from C to A\n");
        printf("The bus currently at city %c \n",rand_char);
    }


    if(!strcmp(sudonum,"C-12")){
        printf("Bus goes from C to B\n");
        printf("The bus currently at city %c \n",rand_char);
    }


    if(!strcmp(sudonum,"PP-19")){
        printf("Bus goes from X to A\n");
        printf("The bus currently at city %c \n",rand_char);
    }
    printf("\n\n");

}



int i = 0;
//60
void ticket_status(){ 
    i++;             //gives the status of tickets and ticket number
    srand(time(0));
    tick_num[i] = rand()%100;

        printf("\nPassenger datails");
        for(int k =0; k<noop;k++){
            printf("\nName : %s \nJourney from %c to %c\n",pas[k].name,from,to);
            printf("Bus number %s\n",bus.busno);
        }
    printf("\nYour ticket number is %d\n\n\n",tick_num[i]);
    nobok = nobok + noop;

}





void cancel(){         // function to cancel ticket and reset the available seats 
    int tik;



    printf("Enter your ticket number ");
    scanf("%d",&tik);

    for(int j=i;j>=1;j--){

        if(tik == tick_num[j]){
            printf("\nTicket cancelled succsesfully\n\n");
            bus.avseat = bus.avseat + noop;
            break;
        }

        else if((j==1) && (tik != tick_num[j])){

            printf("No ticket was booked of this number \n\n");
        }
    }
    
}





int main(){

    int x;
    
    bus.totseat = 50;
    bus.avseat = 32;
    bus.fare = 1700;

    while(1){
        printf("--------MENUE PAGE---------\nSelect what you want to proceede with :\n");
        printf("1 -> booking\n2 -> Check bus status\n3 -> Cancel ticket\n4 -> Exit\nselect : ");
        scanf("%d",&x);

        switch(x){
            case 1 : booking();

                    routecheck();

                        int money;

                        strcpy(bus.busno , busfind());

                        printf("\nBus from %c to %c is available \n\nBus number is %s \n\n",from,to,bus.busno);
                        printf("Available seats are %d \nAnd fare for one passenger is Rs %d\n", bus.avseat , bus.fare);
                        
                        bus.avseat = bus.avseat - noop;

                        printf("\n\nPlease procede with the payment of sum ammount \n%dx%d = %d\n",noop,bus.fare,noop*bus.fare);
                        printf("\nEnter bank pin\n");
                        scanf("%d",&money);
                        printf("payment succesful\n");
                        printf("\n------Ticket booked-------");
                    
                        ticket_status();

                break;

            case 2 : bus_status();
            break;

            case 3 : cancel();
            break;

            case 4 : printf("You will now exit this page\n");
                    exit(0);

        }
    }
    
}
