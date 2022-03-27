/*
This is basically a C code implementation of a Hotel Management System

The code when compiled generates an .exe file on Windows which can be both accessed by the user and the admin

Although accessing admin privileges requires a password
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

char price(struct Room  pri){ if( strcmp(pri.type, "1")==0) return "4500";
 if( strcmp(pri.type, "2")==0) return "6000";
  if( strcmp(pri.type, "3")==0) return "6500"; }

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
                        find_room();
                        break;
                    }
                case 6:{
                    checkout_guest();
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




           /* case 2:{
                while(user_entry[0] =='y'){
                printf("\nHello user and welcome to Hotel!");
                printf("\n>>>>>>>>>>>>\tTo view available rooms --> 1 \t\t\t<<<<<<<<<<<<");
   	            printf("\n>>>>>>>>>>>>\tTo request booking of room --> 2 \t<<<<<<<<<<<<");
                printf("\n>> ");
                scanf("%d",&c);
                switch(c){
                    case 1:{
                        FILE* view;
                        view = fopen("rooms.txt","r");
                        printf("Available rooms are:\n");
                        while(fscanf(view,"%s",h.name) != -1){
                        printf("%s \n",h.name);
                        }
                        fclose(view);
                        break;
                    }

                    case 2:{
                        printf("Enter your name: ");
                        scanf("%s",h.name);
                        printf("Enter room to book: ");
                        scanf("%s",h.name);
                        printf("Enter WiFI plan (1GB/5GB): ");
                        //scanf("%s",h.wifi);
                        printf("Enter if bf (yes/no): ");
                       // scanf("%s",h.bf);

                        enter = fopen("bookings.txt","a");

                       // fprintf(enter,"%s %s %s %s",h.name,h.room,h.wifi,h.bf);
                        fprintf(enter,"\n");

                        printf("Succesfully requested booking\n");
                        fclose(enter);

                    }
                }

                printf("Would you like to continue? (y/n)\n");
                scanf("%s",user_entry);

                }
                if(strcmp(user_entry,"n") == 0){
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
                break;
            }
        }*/
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

