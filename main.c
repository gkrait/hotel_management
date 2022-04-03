/*
This is basically a C code implementation of a Hotel Management System

The code when compiled generates an .exe file on Windows which can be both accessed by the user and the admin

Although accessing admin privileges requires a password
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>



//Method Declaration

void enter_name();
void find_name();
void find_room();
void checkout_guest();
void view_bookings();

//Instance Field Declaration
FILE* view;
FILE *fp;
FILE* enter;
int client_admin;
char admin_entry[20] = {'y'};
char user_entry[20] = {'y'};

//structure defined to store name, room, bf and wifi required
struct client
{
    char name[20];
    char prenom[20];
    char id[20] ;
    char tel[20];
    char room [20];
    char wifi [20];
    char bf [20];

}h,h2,h3;


struct Room
{
    char num[20];
    char type[20];
    char tv[20] ;
    char avail[20];

}ro,ro2,ro3;

struct Reservation
{
    char id_res[20];
    char days[20];
    char date[20] ;
    char nmb[20];
    char room [20];
    char cli [20];
}r,r2,r3;

struct {
 int year;
 int month;
 int day;
} Date;
float price(char  *pri){
if( strcmp(&pri, "1")==0){ return 4500.0;}
 else if( strcmp(&pri, "2")==0) {return 6000.0;}
  else if( strcmp(&pri, "3")==0) {return 6500.0; }
  else{
   return 4;}}


float CoefSaison(char* da){
int d,m;
int values[3];
size_t converted;
stringToIntList(da, values, sizeof values / sizeof values[0], &converted);
d = values[0];
m= values[1];
if (  ( (m == 8 ) || (m==9 && m <=29  ) || ( m==7 && d>= 21 )  )) { return 1.4; } // Summer
else if ( (m==9 && d > 29 ) || (m==12 && d < 21 ) || (m==11 ) ) { return 1.1; }
else if ( (m==3 && d >= 20 ) || (m==12 && d >= 21 ) || (m==1 || m== 2 ) ) { return 0.8; }
else if ( (m==3 && d < 20 ) || (m==7 && d < 21 ) || (m==4 || m== 5 ) ) { return 1.0; }
else { return 0.0 ;}


return 0.0;
}


 void roomssharedf(struct Room ** rooms_pairs){
int del;
FILE *enter, *enter2;
struct Room  ro1, ro2;
enter = fopen("rooms.txt","r");
struct Room rooms_list[10];
struct Room   rooms_list2[10];
//struct Room   rooms_pairs[100][2];
struct Room *roompPinter;
int i=0;
while (fscanf(enter,"%s %s %s %s",ro1.num, ro1.type , ro1.tv, ro1.avail ) != EOF){
    fgetc(enter);
    rooms_list[i]= ro1 ;
    i = i+1;}
int j;
int k = 0;
for (i=0; i< 4; i++){
for (j=i+1; j <= 5; j++){
//ro2 = rooms_list[j];
if (1==1) /*( (strcmp( rooms_list[i].num,rooms_list[j].num )==1)
 &&  (strcmp( rooms_list[i].type, rooms_list[j].type )==0) && ((strcmp(rooms_list[i].tv, "1" )==1))
  && ((strcmp( rooms_list[j].tv, "1" )==1)) )*/{

 //roompPinter =  &rooms_list[i];
 memcpy(ro1.num ,  rooms_list[i].num,200 ); memcpy(ro1.tv,  rooms_list[i].tv,200 );memcpy(ro1.type,  rooms_list[i].type,200 );memcpy(ro1.avail,  rooms_list[i].avail,200 );

rooms_list2[k]=ro1;
 k= k+1;
memcpy(ro1.num ,  rooms_list[j].num,200 ); memcpy(ro1.tv,  rooms_list[j].tv,200 );memcpy(ro1.type,  rooms_list[j].type,200 );memcpy(ro1.avail,  rooms_list[j].avail,200 );
rooms_list2[k]=ro1;
 k= k+1;
printf("\n %s \n",rooms_list2[k].num);


;
 //roompPinter =  &rooms_list[j];
 //rooms_pairs[k][1] =*roompPinter;


    //printf("%s %s","rooms_pairs[k][0].num", "rooms_pairs[k][1].num");
  }


}}

    }


void view_bookings_room(char * str1){

    enter = fopen("reservations.txt","r");
    struct Reservation Res;
    printf("Le histoire de la chambre est: \n");
    while(fscanf(enter,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli ) != -1){
    fgetc(enter);
    if (strcmp(Res.room ,str1)==0 ) {
        printf("%s %s %s %s %s %s \n",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli);
    }
}}

void view_bookings_client(char * str1){
    enter = fopen("reservations.txt","r");
    struct Reservation Res;
    printf("Le client a fait les réservations suivantes \n");
    while(fscanf(enter,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli ) != -1){
    fgetc(enter);
    if (strcmp(Res.cli ,str1)==0 ) {
        printf("%s %s %s %s %s %s \n",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli);
    }
}}



void stringToIntList(char *str, int *arr, size_t arrSize, size_t *count)
{
  /**
   * The token variable holds the next token read from the input string
   */
  char *token;

  /**
   * Make a copy of the input string since we are going to use strtok(),
   * which modifies its input.
   */
  char *localStr = malloc(strlen(str) + 1);
  if (!localStr)
  {
    /**
     * malloc() failed; we're going to treat this as a fatal error
     */
    exit(-1);
  }
  strcpy(localStr, str);

  /**
   * Initialize our output
   */
  *count = 0;

  /**
   * Retrieve the first token from the input string.
   */
  token = strtok(localStr, "/");
  while (token && *count < arrSize)
  {
    char *chk;
    int val = (int) strtol(token, &chk, 10);
    if (isspace(*chk) || *chk == 0)
    {
      arr[(*count)++] = val;
    }
    else
    {
      printf("\"%s\" is not a valid integer\n", token);
    }

    /**
     * Get the next token
     */
    token = strtok(NULL, "/");
  }

  /**
   * We're done with the dynamic buffer at this point.
   */
  free(localStr);
}


void factures(){
    struct Reservation Res;
    FILE *fptr1 , *fpt;
    printf("la liste des factures: \n");
    char  file1[20]="reservations.txt";
    char  file2[20]="rooms.txt";
    fptr1 = fopen(file1,"r");
    struct Reservation  Res2;
    while(fscanf(fptr1,"%s %s %s %s %s %s",Res.id_res, Res.days,Res.date,Res.nmb,Res.room ,Res.cli ) != -1){
    fgetc(fptr1);
    fpt = fopen(file2,"r");//printf(Res.room);printf("\n");
    while(fscanf(fpt,"%s %s %s %s",ro.num,ro.type,ro.tv,ro.avail) != -1 ){
    fgetc(fpt);
    strcpy(ro2.num,ro.num);
    if (strcmp(ro.num, Res.room) ==0  ) { float resu= price(ro2.type) *  CoefSaison(Res.date) ;
    printf(" Room num: %s , Client: %s ,Reserv ID %s , Num Days: %s, Price %.6f\n ",
    Res.room,Res.cli, Res.id_res,Res.days, resu  );
    }
    }


} fclose(fptr1);
}


void fifthquestion(){//(struct client * final_list){

   struct Room room_pairs[100][2];
   struct Reservation reservation_list[100];
   struct client clients_list[100] , final_list[100];
   struct Room ro1,ro2;
   struct Reservation r1,r2, Res;
   FILE *enter, *fp;
  roomssharedf(room_pairs);
    enter = fopen("reservations.txt","r");
    fp= fopen("clients.txt","r");
   int k=0 ;

   while(fscanf(enter,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli ) != -1){
   fgetc(enter);
     reservation_list[k] = Res; k ++;}
    int clint= 0;
    while(fscanf(fp,"%s" "%s" "%s" "%s" ,h.name,h.prenom,h.id, h.tel) != -1){
    fgetc(fp); clients_list[clint] =h; clint++;   }
    char str1[20];
    struct Reservation Res1, Res2;
    int roomsNmb =  sizeof(room_pairs);
    int i,j ;
    int k2=0;
    int k3=0;

    for (i=0; i< roomsNmb; i++){
     ro1 = room_pairs[i][0] ;
     ro2 = room_pairs[i][1] ;
     //printf("%s", "room_pairs[i][0].num");
     //printf("%s", "room_pairs[i][1].num");
     printf("\n %s \n", room_pairs[i][0].num);
     for (j=0; j< roomsNmb; j++){
        if ( strcmp( reservation_list[j].room,ro1.num)==0 ) {r1 = reservation_list[j];}
         if ( strcmp( reservation_list[j].room,ro2.num)==0 ) {  r2 = reservation_list[j];  }
        for ( k3=0; k3  <  sizeof(clients_list)  ; k3 ++  ) {

         if( 1==1) //strcmp( clients_list[clint].id , r1.cli)  ==0  || ( strcmp( clients_list[clint].id , r2.cli) ==0  )  )
         {
         final_list[k2]= clients_list[clint]; k2++;  }
            }

   }

     }

//return final_list;




    /*struct Reservation Res;
    printf("Les qui partage les meme chose sont: \n");
    while(fscanf(enter,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli ) != -1){
    fgetc(enter);

    while(fscanf(enter2,"%s %s %s %s %s %s",Res2.id_res,Res2.days,Res2.date,Res2.nmb,Res2.room ,Res2.cli ) != -1){
    fgetc(enter2);
    if ((strcmp(Res1.cli, Res2.cli) ==1 ) & (strcmp(Res1.cli, Res2.cli) ==1)) {
    int T ;
    }
}
}
printf("It is  not good");scanf("%s", str1);;
fclose(enter);fclose(enter2);*/
}


//main method
int main(){
    int a,b,c;

     //Welcome screen

 	printf("\n\n\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*            WELCOME TO HOTEL Benkahla          *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n\n\n");

    /*printf("\n>>>>>>>>>>>>\tFor ADMIN access enter --> 1 \t\t\t<<<<<<<<<<<<");
    printf("\n>>>>>>>>>>>>\tFor USER access enter --> 2 \t\t\t<<<<<<<<<<<<");
    printf("\n>> ");
     scanf("%d",&a);*/


                char pass[10];
                 //re-entry if
                while(admin_entry[0] =='y'){
                 printf("\n>>>>>>>>>>>>\t Pour gestion des client --> 1 \t\t\t<<<<<<<<<<<<");
                printf("\n>>>>>>>>>>>>\t  Pour gestion des reservations  --> 2 \t\t\t<<<<<<<<<<<<");
                printf("\n>>>>>>>>>>>>\t Afficher les réservations d'un client --> 3 \t<<<<<<<<<<<<");
   	            printf("\n>>>>>>>>>>>>\t Afficher les histoire d'un client --> 4 \t<<<<<<<<<<<<");
                printf("\n>>>>>>>>>>>>\tTo FIND guest of occupied room --> 5 \t<<<<<<<<<<<<");
                printf("\n>>>>>>>>>>>>\tTo CHECKOUT room number of existing guest --> 6 <<<<<<<<<<<<\n");
                printf("\n>>>>>>>>>>>>\tTo liste des factures --> 7 <<<<<<<<<<<<\n");
                printf(">> ");
                scanf("%d",&b);

                switch(b){
                    case 1:{
                        gestion_des_client();
                        break;
                    }
                    case 2:{
                        gestion_des_reservs();
                         break;
                    }
                    case 3:{
                         char str1[20];
                         printf("\n Donnez l'identifiant du client : --> 3 \t");
                        scanf("%s",str1);
                        view_bookings_client(&str1);
                        break;
                    }
                    case 4:{
                         char str1[20];
                         printf("\n Donnez l'identifiant du client : --> 3 \t");
                        scanf("%s",str1);
                        view_bookings_room(&str1);
                        break;
                    }
                    case 5:{
                        //struct client clients_list[100];

                        fifthquestion();
                        printf("Done\n");
                        break;
                    }
                case 6:{
                    checkout_guest();
                    break;
                    }

                    case 7:{
                    factures();
                    break;
                    }
                    default:{
                        printf("\n Wrong entry!");
                    }
                }
                //enter again?
                printf("Would you like to continue? (y/n)\n");
                scanf("%s",admin_entry);

                }
                if(strcmp(admin_entry,"n") == 0){
                    printf("Exiting...\n");
                    printf("\e[1;1H\e[2J");
                    printf("\n >Exited<\n\n");
                    //system("clear");
                    return 0;
                }
                else{
                    printf("Wrong entry!\nExiting...\n");
                    return 0;
                }

}




gestion_des_reservs(){
int d ;
    printf("\n>>>>>>>>>>>>\t Ajouter un reservation --> 1 \t\t\t<<<<<<<<<<<<");
    printf("\n>>>>>>>>>>>>\t Modifier un reservation --> 2 \t\t\t<<<<<<<<<<<<");
    printf("\n>>>>>>>>>>>>\t Supprimer un reservation --> 3 \t\t\t<<<<<<<<<<<<");
    printf("Entrez votre choix: ");
    scanf("%d",& d);
     switch(d){
     case 1 : { enter_res();  break; }
       case 2 : {
     modifier_res(); break;
     }
     case 3 : {printf("donnez le ID de reservations a  supprimer: ");
     char del[20];
     scanf("%s",del);
       suprrimer_res(&del);
       printf("\n le reservations est supprime \n"); break;}

     default:{
                        printf("\n try again! \n"); scanf("%d",& d);}

     }
}


void enter_res(){
    FILE *tmp1;
    FILE *tmp2;
    printf("\n Entrez le ID de le reservation:  --> ");
    scanf("%s",r.id_res);
    printf("\n How many days to stay? --> ");
    scanf("%s",r.days);
    printf("\n starting dates --> ");
    scanf("%s", r.date);
    printf("\n Number of guests?  --> ");
    scanf("%s",r.nmb);
    printf("\n Number of room?  --> ");
    scanf("%s",r.room);
    printf("\n reservation by client  --> ");
    scanf("%s",r.cli);
    //entering guests
    fp = fopen("reservations.txt","a");
    if( fp == NULL){
        printf("\nFile not found");
        exit(1);
    }
    else{
        fprintf(fp,"%s %s %s %s %s %s",r.id_res,r.days,r.date,r.nmb,r.room ,r.cli );
        printf("\n Le reservation est ajouté.\n");
    }
    fprintf(fp,"\n");

    fclose(fp);
}

void suprrimer_res(char* del){
    FILE *fptr1, *fptr2;
    char file1[24] ="reservations.txt";
    char file2[20] ="file2.txt";
    char r[20];
    struct Reservation Res ;
    //char curr[20];
    fptr1 = fopen(file1,"r");
    fptr2 = fopen(file2, "w");
    while(fscanf(fptr1,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli ) != -1){
      fgetc(fptr1);


      if(strcmp( del, Res.id_res)==0){ int T;}
       else  {
         fprintf(fptr2,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli);
         fprintf(fptr2,"\n");
        }
       }
        fclose(fptr1);
        fclose(fptr2);

       fptr1 = fopen(file1,"w");
       fptr2 = fopen(file2,"r");
       while(fscanf(fptr2,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli) != -1){
       fgetc(fptr2);
       fprintf(fptr1,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli);
       fprintf(fptr1,"\n");}

        fclose(fptr1);
        fclose(fptr2);


}

void modifier_res(){
    int id ;
    int guestFound =0;
    printf("\n Entrez le numbre de identite de le reservation -->\n");
      char str1[10], str2[10];
      int x,y;
      struct Reservation Res, Res2 ;
     FILE * F2;
     fp = fopen("reservations.txt","r");
     F2= fopen("file2.txt","w");
     scanf("%s",str1);

     while(fscanf(fp,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli ) != -1){
     fgetc(fp);
    if (strcmp(Res.id_res ,str1)==0 ) {

                     guestFound = 1;
        printf("\n Entrez le  nouveau ID de le reservation:  --> ");
    scanf("%s",Res2.id_res);
    printf("\n How many days to stay? --> ");
    scanf("%s",Res2.days);
    printf("\n starting dates --> ");
    scanf("%s", Res2.date);
    printf("\n Number of guests?  --> ");
    scanf("%s",Res2.nmb);
    printf("\n Number of room?  --> ");
    scanf("%s",Res2.room);
    printf("\n reservation by client  --> ");
    scanf("%s",Res2.cli);

    //fp = fopen("clients.txt","a");

       if( F2 == NULL){
        printf("\nFile not found");
        exit(1);
    }
    else{
        fprintf(F2,"%s %s %s %s %s %s",Res2.id_res,Res2.days,Res2.date,Res2.nmb,Res2.room ,Res2.cli);
         fprintf(F2,"\n");
         }

   }
   else {fprintf(F2,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli);
         fprintf(F2,"\n");}


   }

fclose(F2);
fclose(fp);
FILE *fptr1, *fptr2;
       fptr1 = fopen("reservations.txt","w");
       fptr2 = fopen("file2.txt","r");
       while(fscanf(fptr2,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli) != -1){
       fgetc(fptr2);
       fprintf(fptr1,"%s %s %s %s %s %s",Res.id_res,Res.days,Res.date,Res.nmb,Res.room ,Res.cli);
         fprintf(fptr1,"\n");}
        fclose(fptr1);
        fclose(fptr2);
   printf("\n Le client est modifié.\n");

//}
}



void gestion_des_client()
{
int d ;
    printf("\n>>>>>>>>>>>>\t Ajouter un client --> 1 \t\t\t<<<<<<<<<<<<");
    printf("\n>>>>>>>>>>>>\t ModModifier un client --> 2 \t\t\t<<<<<<<<<<<<");
    printf("\n>>>>>>>>>>>>\t Supprimer un client --> 3 \t\t\t<<<<<<<<<<<<");
    printf("Entrez votre choix: ");
    scanf("%d",& d);
     switch(d){
     case 1 : { enter_name();  break; }
       case 2 : {
     modifier_client(); break;
     }
     case 3 : {printf("donnez le ID de cliente a  Supprimer");
     char del[20];
     scanf("%s",del);
       suprrimer(&del);
       printf("\n le client est supprime \n"); break;}

     default:{
                        printf("\n try again! \n"); scanf("%d",& d);}

     }
}

//method declare to enter name
void enter_name(){
    FILE *tmp1;
    FILE *tmp2;
    printf("\n Entrez le nom de le client:  --> ");
    scanf("%s",h.name);
    printf("\n Entrez le prenom de le client --> ");
    scanf("%s",h.prenom);
    printf("\n Entrez le numbre de identite --> ");
    scanf("%s", h.id);
    printf("\n Entrez le numbre de telephone  --> ");
    scanf("%s",h.tel);
    //entering guests
    fp = fopen("clients.txt","a");
    if( fp == NULL){
        printf("\nFile not found");
        exit(1);
    }
    else{
        fprintf(fp,"%s %s %s %s",h.name,h.prenom,h.id,h.tel);
        printf("\n Le client est ajouté.\n");
    }
    fprintf(fp,"\n");

    fclose(fp);
}

void suprrimer(char* del){
    FILE *fptr1, *fptr2;
    char file1[20] ="clients.txt";
    char file2[20] ="file2.txt";
    char r[20];
    //char curr[20];
    int line_number = 0;
    fptr1 = fopen(file1,"r");
    fptr2 = fopen(file2, "w");
    while(fscanf(fptr1,"%s" "%s" "%s" "%s" ,h.name,h.prenom,h.id, h.tel) != -1){
      fgetc(fptr1);

      if(strcmp( del, h.id)==0){int T;}
       else  {
        fprintf(fptr2,"%s %s %s %s\n",h.name,h.prenom,h.id,h.tel);
        }
       }
        fclose(fptr1);
        fclose(fptr2);
       fptr1 = fopen(file1,"w");
       fptr2 = fopen(file2,"r");
       while(fscanf(fptr2,"%s" "%s" "%s" "%s \n" ,h.name,h.prenom,h.id, h.tel) != -1){
       fgetc(fptr2);
       fprintf(fptr1,"%s %s %s %s\n",h.name,h.prenom,h.id,h.tel);}
        fclose(fptr1);
        fclose(fptr2);


}

void modifier_client(){
    int id ;
    char buffer[20];
    char entered_name[20];
    int guestFound =0;
    printf("\n Entrez le numbre de identite de le client -->\n");
      char str1[10], str2[10];
      int x,y;

     FILE * F2;
     fp = fopen("clients.txt","r");
     F2= fopen("file2.txt","w");
     scanf("%s",str1);

    while(fscanf(fp,"%s" "%s" "%s" "%s" ,h.name,h.prenom,h.id, h.tel) != -1){
     fgetc(fp);
    //y= fgets(h.id, 20, (FILE*)fp);
    if (strcmp(h.id ,str1)==0 ) {

                     guestFound = 1;
                    printf("\n Guest found!");
                    printf("\n Nom %s",h.name);
                    printf("\n Prenom %s",h.prenom);
                    printf("\n Ident %s",h.id);
                    printf("\n Tel %s\n",h.tel);

    printf("\n saisir le nouveau nom de le client:  --> ");
    scanf("%s",h2.name);
    printf("\n Entrez  saisir le nouveau prenom de le client --> ");
    scanf("%s",h2.prenom);
    printf("\n  saisir le nouveau  le numbre de identite --> ");
    scanf("%s",h2.id);
    printf("\n  saisir le nouveau le numbre de telephone  --> ");
    scanf("%s",h2.tel);

    //fp = fopen("clients.txt","a");

       if( F2 == NULL){
        printf("\nFile not found");
        exit(1);
    }
    else{
        fprintf(F2,"%s %s %s %s\n ",h2.name,h2.prenom,h2.id,h2.tel);
         }

   }
   else { fprintf(F2,"%s %s %s %s\n ",h.name,h.prenom,h.id,h.tel); }


   }

    //entering guests

fclose(F2);
fclose(fp);
FILE *fptr1, *fptr2;
       fptr1 = fopen("clients.txt","w");
       fptr2 = fopen("file2.txt","r");
       while(fscanf(fptr2,"%s" "%s" "%s" "%s \n" ,h.name,h.prenom,h.id, h.tel) != -1){
       fgetc(fptr2);
       fprintf(fptr1,"%s %s %s %s\n",h.name,h.prenom,h.id,h.tel);}
        fclose(fptr1);
        fclose(fptr2);
   printf("\n Le client est modifié.\n");

//}
}
//method defined to find quest name
void find_name(){
    int id;
    char buffer[20];
    char entered_name[20];
    int guestFound =0;

    printf("\nEnter guest name to find -->");
    scanf("%id",&id);

    fp = fopen("clienrs.txt","r");
    while(fscanf(fp,"%s %s %s",h.name,h.prenom,&h.id,&h.tel) != -1){
    fgetc(fp);
    fgets(h.id, 20, (FILE*)fp);
    if(strcmp(h.id,id) == 0){
                     guestFound = 1;
                    printf("\n Guest found!");
                    printf("\n Name  is %s",h.name);
                    printf("\n Room number is %s",h.room);
                    printf("\n WiFi plan is %s",h.wifi);
                    printf("\n Breakfast included %s",h.bf);

      }
   }
   if(guestFound == 0){
         printf("\nGuest %s not found!\n", entered_name);
      }
   fclose(fp);
}

//method definition for guest checkout
void checkout_guest(){
    char buffer2[20];
    char checkout_name[20];
    char add_room[20];

    FILE *tmp;

    printf("Enter guest too checkout ");
    scanf("%s",checkout_name);

    fp = fopen("hotelnew.txt","r");
    tmp = fopen("tmp.txt","w");

    if(fp == NULL){
    printf("File not found");
    exit(1);
    }
	else{
        while(fscanf(fp,"%s %s %s",h.name,h.room,h.wifi) != -1){
            fgetc(fp);
		    fgets(h.bf, 20, (FILE*)fp);
			    if(strcmp(h.name,checkout_name) != 0){
                    fprintf(tmp,"%s %s %s %s",h.name,h.room,h.wifi,h.bf);
                }
                else{
                   strcpy(add_room,h.room);
                }
        }
        printf("Room checked out!");
    }

    fclose(fp);
    fclose(tmp);
    remove("hotelnew.txt");
    rename("tmp.txt","hotelnew.txt");

    //enter room back into available rooms list
    view = fopen("rooms.txt","a");
    printf(" add is %s",add_room);
    fprintf(view,"%s",add_room);
    fclose(view);

}

//method definition for finding rooms avalaible
void find_room(){
    char buffer[20];
    char entered_room[20];
    int roomFound =0;
    FILE *fp;
    printf("\nEnter room number to find -->");
    scanf("%s",entered_room);

    fp = fopen("hotelnew.txt","r");
    while(fscanf(fp,"%s %s %s",h.name,h.room,h.wifi) != -1){
    fgets(h.bf, 255, (FILE*)fp);
    if(strcmp(h.room,entered_room) == 0){
                     roomFound = 1;
                    printf("\n Room found!");
                    printf("\n Name  is %s",h.name);
                    printf("\n Room number is %d",h.room);
                    printf("WiFi plan is %s",h.wifi);
                    printf("\n Breakfast included %d",h.bf);
      }
    }
    if(roomFound == 0){
         printf("\nRoom %s not found!\n", entered_room);
      }
   fclose(fp);
}

//method defined to view bookings

