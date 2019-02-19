#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>

 char* bfilename = "bookings.txt";
 char* sfilename = "services.txt";
 char* pfilename = "rate.txt";
 char* efilename = "employees.txt";
int prices[3][4] = {{1100,1300,1800,2000},
					{1500,1800,2200,3000},
					{2000,2200,3000,4000}
				   };

char *carType[4] = {"Hatchback", "sedan", "SUV", "Luxury"};
char *serviceType[4] = {"Silver Wash","Gold Wash","Platinum Wash"};

struct booking
{
	int booking_id;
	char name[50];
	int car_type;
	char car_no[10];
	int service_type;
	char address[100];
	char phno[15];
	int bill_price;
};

struct booking carspaBookingDetails[100];
static int bookingIndex = 0;


//function declarations
int main_screen();

int admin_login();
int admin();
void Bookings_details();
void update_services();
void change_offers();
void employees_details();

int manager_login();
int manager();
void takeBookings();
void showServices();
void showOffers();
void empRecord();
void printBill(int bookingID,int shouldWriteToFile);
void show_prices();
void change_prices();

void readFile(char *filename);
void writeFile(char *filename);
int getch(void);


/*****************************************
Helper Functions
******************************************/

void readFile(char *filename){
	char ch;
	FILE *fp = fopen(filename, "r");

	if(fp == NULL){
		printf("\nCouldn't open the file\n");
		return;
	}
	while((ch = getc(fp)) != EOF)
	    printf("%c",ch);
	fclose(fp);
	return;
}

void writeFile(char *filename){
	char str[1000];
	FILE *fp = fopen(filename, "a");
	if(fp == NULL){
		printf("\nCouldn't open the file\n");
		return;
	}

	printf("\nEnter data : ");
	scanf("%s", str);
	fputs(str, fp);
	fclose(fp);
	return;

}


/******************************************************
Functions for Admin
******************************************************/

int admin_login()
{
    int passIndex;
    char userId[30],passwrd[30],ch;
    char uid[] = "admin",upassword[] = "carspa";
    int chances = 3,IdNo;
    while (chances)
    {
	printf("Enter USERNAME -- ");
	scanf("%s",userId);
	printf("\nEnter PASSWORD -- ");

	for(passIndex=0; passIndex<30; passIndex++)
	{
		ch = getch();
		if(ch == '\n' || ch=='\r')
			break;
		passwrd[passIndex]=ch;
		printf("*");
	}
		passwrd[passIndex] = '\0';
	       //	printf("%s",passwrd);


	if (strcmp(uid, userId) == 0 && strcmp(passwrd, upassword) == 0)
	{
		printf("\nCORRECT USERNAME AND PASSWORD\n");
		system("cls");
		return 1;
	}
	else
	{
	    printf("\nINVALID USERNAME OR PASSWORD\n");
	    printf("******************************************\n");
	    system("cls");
	    printf("\nPLEASE ENTER THE VALID USERNAME AND PASSWORD\n\n");
	    chances--;
	    printf("only %d chances left\n\n",chances);
	    if(!chances)
	    {
		int IDNo;
		printf("SORRY NO MORE CHANCES LEFT \n\nEnter your UNIQUE ID --\n");
		scanf("%d",&IdNo);

		if(IDNo != 9771)
			return 0;
	    }
	}
    }
    return 0;
}

int admin(){
	int opt;
	do{
		printf("\n\n***** WELCOME TO CARSPA *****\n\n");
		printf("1 : Bookings Details\n");
		printf("2 : Update Services\n");
		printf("3 : Modify prices\n");
		printf("4 : Employees Record\n");
		printf("5 : Exit\n");
		printf("PLEASE ENTER YOUR CHOICE\n");
		scanf("%d",&opt);
		system("cls");
		switch(opt){
			case 1 : Bookings_details ();
				system("cls");
					break;

			case 2 : update_services();
				system("cls");
					break;

			case 3 : change_prices();
				 system("cls");
					break;

			case 4 : employees_details();
				 system("cls");
					break;

			case 5 : main_screen();
					break;

			default : printf("PLEASE ENTER VALID INPUT\n");
					break;
		}

	 }while(opt!= 6);
		return 0;

}

void Bookings_details() {
	printf("Bookings_details\n");
	readFile(bfilename);
	return;
}

void update_services(){
	char choice;
	readFile(sfilename);
	printf("\n\nDo you want to update the content?(Y/N) : ");
	choice = getche();
	getch();
	if(choice == 'Y' || choice == 'y')
		writeFile(sfilename);
	return;

}

void change_prices(){
	char choice;
	readFile(pfilename);
	printf("\nDo you want to update the content?(Y/N) : ");
	choice = getche();
	getch();
	if(choice == 'Y' || choice == 'y')
	writeFile(pfilename);
	return;
}


void employees_details(){
		char choice;
	printf("employees_details\n");
	readFile(efilename);
	printf("\nDo you want to update the content?(Y/N) : ");
	choice = getche();
	getch();
	if(choice == 'Y' || choice == 'y')
		writeFile(efilename);
	return;

}



/******************************************************
Functions for Manager
******************************************************/
int manager_login()
{
  int passIndex;
    char userId[30],passwrd[30],ch;
    char uid[] = "manager",upassword[] = "carspa";
    int chances = 3,IdNo;
    while (chances)
    {
	printf("Enter USERNAME -- ");
	scanf("%s",userId);
	printf("\nEnter PASSWORD -- ");

	for(passIndex=0; passIndex<30; passIndex++)
	{
		ch = getch();
		if(ch == '\n' || ch=='\r')
			break;
		passwrd[passIndex]=ch;
		printf("*");
	}
		passwrd[passIndex] = '\0';

	if (strcmp(uid, userId) == 0 && strcmp(passwrd, upassword) == 0)
	{
		printf("\nCORRECT USERNAME AND PASSWORD\n");
		system("cls");
		return 1;
	}
	else
	{
	    printf("\nINVALID USERNAME OR PASSWORD\n");
	    printf("******************************************\n");
	    system("cls");
	    printf("\nPLEASE ENTER THE VALID USERNAME AND PASSWORD\n\n");
	    chances--;
	    printf("only %d chances left\n\n",chances);
	    if(!chances)
	    {
		int IDNo;
		printf("SORRY NO MORE CHANCES LEFT \n\nEnter your UNIQUE ID --\n");
		scanf("%d",&IdNo);

		if(IDNo != 0000)
			return 0;
	    }
	}
    }
    return 0;
}

int manager(){
	int option;
	int bID;
	do{
		printf("\n\n***** WELCOME TO CARSPA *****\n\n");
		printf("1 : Take Bookings\n");
		printf("2 : Services Available\n");
		printf("3 : Show Prices\n");
		printf("4 : Employees Record\n");
		printf("5 : Print Bill\n");
		printf("6 : Exit\n");
		printf("PLEASE ENTER YOUR CHOICE\n");
		scanf("%d",&option);
		system("cls");
		switch(option){
			case 1 : takeBookings();
				system("cls");
				break;


			case 2 : showServices();
				system("cls");
				break;

			case 3 : show_prices();
				system("cls");
				break;


			case 4 : empRecord();
				system("cls");
				break;

			case 5 : printf("Enter the booking ID  :  ");
					 scanf("%d", &bID);
					 printBill(bID, 0);
				break;


			case 6 : main_screen();
				break;


			default : printf("PLEASE ENTER VALID INPUT\n");
				break;
	    }
	}while(option!= 6);

	return 0;
}

void takeBookings(){
	struct booking b;

	printf("Enter your Name--> ");
	scanf("%s",b.name);
	printf("contact no.--> ");
	scanf("%s",b.phno);
	printf("Address --> ");
	scanf("%s",b.address);
	printf("Car no. --> ");
	scanf("%s",b.car_no);
	printf("Enter your Car type -->\n1 : Hatchback\n2 : sedan\n3 : SUV\n4 : Luxury\n");
	scanf("%d",&b.car_type);

	printf("Choose your Service type -->\n1 : Silver wash\n2 : Gold wash\n3 : Platinum wash\n");
	scanf("%d",&b.service_type);

	b.booking_id = bookingIndex;
	b.bill_price = prices[b.service_type-1][b.car_type-1];

	//Adding the details of booking b in the array
	carspaBookingDetails[bookingIndex] = b;
	bookingIndex++;

	//append the details of booking b in the file

	//print the bill
	printBill(bookingIndex - 1, 1);
}

void showServices(){
	char* filename = "services.txt";
	readFile(filename);
	getch();

}

void showOffers(){
	char* filename = "offers.txt";
	readFile(filename);
	getch();
}

void show_prices(){
	char* filename = "rate.txt";
	readFile(filename);
	getch();

}

void empRecord(){
	char* filename = "employees.txt";
	readFile(filename);
	getch();

}



void printBill(int bookingID, int shouldWriteToFile){
		struct booking curr_booking;
	FILE *fp = fopen("bookings.txt", "a");

	char snum[10];
	char str1[300];
	if(bookingID >= bookingIndex){
		printf("******* The Booking ID doesn't Exist. Please Enter a Valid ID *******\n");
		return;
	}

	curr_booking = carspaBookingDetails[bookingID];



	strcpy(str1, "\n\t******************** Bill Details *******************");
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);

	strcpy(str1, "\n\tBOOKING ID : CarSpa@");
	sprintf(snum, "%d", curr_booking.booking_id);
	strcat(str1, snum);
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);

	strcpy(str1, "\n\tNAME : ");
	strcat(str1, curr_booking.name);
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);

	strcpy(str1, "\n\tADDRESS : ");
	strcat(str1, curr_booking.address);
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);

	strcpy(str1, "\n\tPHONE NO. : ");
	strcat(str1, curr_booking.phno);
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);

	strcpy(str1, "\n\tCAR TYPE : ");
	strcat(str1, carType[curr_booking.car_type-1]);
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);

	strcpy(str1, "\n\tCAR NO. :");
	strcat(str1, curr_booking.car_no);
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);


	strcpy(str1, "\n\tSERVICE TYPE :");
	strcat(str1, serviceType[curr_booking.service_type-1]);
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);


	strcpy(str1, "\n\tBILL PRICE : ");
	sprintf(snum, "%d", curr_booking.bill_price);
	strcat(str1, snum);
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);

	strcpy(str1, "\n\t*******************************************************");
	printf("%s", str1);
	if(fp != NULL && shouldWriteToFile)
		fputs(str1, fp);


	fclose(fp);
	getch();
	return;

}


/******************************************************
Main functions
******************************************************/
int main_screen(){
	int choice;
	do{
		printf("\tENTER YOUR CHOICE \n\t1 ADMIN\n\t2 MANAGER\n\t3 EXIT\n\n\t");
		scanf("%d",&choice);
		system("cls");
		switch(choice){
			case 1 : 	printf("\t------ WELCOME ADMIN ------\n\n");
						if(admin_login())
						{
						     admin();
						}
						break;
			case 2 :   	printf("\t------ WELCOME MANAGER ------\n\n");
						if(manager_login()){
							manager();
						}
						break;
			case 3 :    exit(0);
						break;
			default:    printf("\nPLEASE ENTER THE VALID INPUT\n\n");
						break;
		}
	}while(choice!=3);
	return 0;
}

int runcar()
{
   int gd = DETECT, gm, x = 60, y = 25, font = 7,k,i,maxx,midy;
   initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
    maxx = getmaxx();
    midy = getmaxy()/2;
    for (i=0; i < maxx-150; i=i+5) {
	cleardevice();
	setcolor(WHITE);
	line(0, midy + 37, maxx, midy + 37);


	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, RED);

	line(i, midy + 23, i, midy);
	line(i, midy, 40 + i, midy - 20);
	line(40 + i, midy - 20, 80 + i, midy - 20);
	line(80 + i, midy - 20, 100 + i, midy);
	line(100 + i, midy, 120 + i, midy);
	line(120 + i, midy, 120 + i, midy + 23);
	line(0 + i, midy + 23, 18 + i, midy + 23);
	arc(30 + i, midy + 23, 0, 180, 12);
	line(42 + i, midy + 23, 78 + i, midy + 23);
	arc(90 + i, midy + 23, 0, 180, 12);
	line(102 + i, midy + 23, 120 + i, midy + 23);
	line(28 + i, midy, 43 + i, midy - 15);
	line(43 + i, midy - 15, 57 + i, midy - 15);
	line(57 + i, midy - 15, 57 + i, midy);
	line(57 + i, midy, 28 + i, midy);
	line(62 + i, midy - 15, 77 + i, midy - 15);
	line(77 + i, midy - 15, 92 + i, midy);
	line(92 + i, midy, 62 + i, midy);
	line(62 + i, midy, 62 + i, midy - 15);
	floodfill(5 + i, midy + 22, YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, DARKGRAY);
	/*  Draw Wheels */
	circle(30 + i, midy + 25, 9);
	circle(90 + i, midy + 25, 9);
	floodfill(30 + i, midy + 25, BLUE);
	floodfill(90 + i, midy + 25, BLUE);
	/* Add delay of 0.1 milli seconds */
	delay(50);
	}

      setbkcolor(0);
      {
      setcolor(6);
      settextstyle(font, HORIZ_DIR, 300);
      outtextxy(x, y, "CARSPA\n");
      }
      {x=100;y=150;
      do{
      for(k=1;k<=15;k++)
      {
      setcolor(k);
      settextstyle(font, HORIZ_DIR, 5);
      outtextxy(x, y,"...every car needs a spa!!");
      //}}while(!kbhit());
      settextstyle(7,HORIZ_DIR,2);
      outtextxy(x+150,y+250,"Developed by Sreyas and Shubham");
      delay(100);
      }
	    }while(!kbhit());	}
   getch();
   closegraph();
   return 0;
     }




int main(){

	char s;
	clrscr();
	printf("\n\t\t\t\tEVERY CAR NEEDS A SPA...\n\t\t\tSO WHY NOT BRING THAT NEW CAR FEELING\n");
	printf("\n\t\tCLEAN,SHINNY AND SPARKLING CARS only with carspa\n\n");
	printf("Press any key to start\n");
	scanf("%c",&s);
	runcar();
	main_screen();
	return 0;
}




