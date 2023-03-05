
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<iostream>
#define PORT	 8080
#define MAXLINE 1024
using namespace std;
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char hello[] ="";
	struct sockaddr_in	 servaddr;

	                                                      // Creating socket
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int n;
	socklen_t len;
	char choice,choice1;
	char path[200]="";
	string movie,file="./";
		start:
		cout<<"\t\t\t<=====>Choose Movie name<=====>"<<endl;                         //menu for movie name selection
		cout<<"2012   ------------------------------------(1)"<<endl;
		cout<<"A Beautiful Mind   ------------------------(2)"<<endl;
		cout<<"Amadeus   ---------------------------------(3)"<<endl;
		cout<<"Avatar    ---------------------------------(4)"<<endl;
		cout<<"Clash of the Titans   ---------------------(5)"<<endl;
		cout<<"Les Miserables   --------------------------(6)"<<endl;
		cout<<"Star Wars Episode I - The Phantom Menace   (7)"<<endl;
		cout<<"The Expendables I   -----------------------(8)"<<endl;
		cout<<"The Godfather   ---------------------------(9)"<<endl;
		cout<<"The Matrix Revolutions   ------------------(0)"<<endl;
		cout<<"Exit                     ------------------(E)"<<endl;
		
		cin>>choice;
		switch(choice)
		{
    		case '0' :
		movie="The Matrix Revolutions";
		break;
   		case '1' :
		movie="2012";
		break;

   		case '2' :
		movie="A Beautiful Mind";
		break;

   		case '3' :
		movie="Amadeus";
		break;

   		case '4' :
		movie="Avatar";
		break;

   		case '5' :
		movie="Clash of the Titans";
		break;

   		case '6' :
		movie="Les Miserables";
		break;

   		case '7' :
		movie="Star Wars Episode I - The Phantom Menace";
		break;

   		case '8' :
		movie="2012";
		break;

   		case '9' :
		movie="The Expendables I";
                break;
		case 'E':
		case 'e' :
		
		exit(0);
		break;
		default:
                cout<<"\n\n<========> Wrong input!(Try Again:()<========>\n\n"<<endl;
                goto start;

		}
while(1)
{
file="./";		
start1:
cout<<"\t\t\t<=====>Choose Movie Attribute<=====>"<<endl;
										//menu for attributes selection
		
		cout<<"Plarity           ----------------------------(1)"<<endl;
		cout<<"Sentiments            ------------------------(2)"<<endl;
		cout<<"rating                    --------------------(3)"<<endl;
		cout<<"Exit                          ----------------(E)"<<endl;
		cout<<"Back to MainMenu                  ------------(4)"<<endl;
cin>>choice1;
string str;
		switch(choice1)
		{
    		
   		case '1' :
               file=file+movie;
		file=file+"/polarity.txt";
	break;

   		case '3' :
		file=file+movie;
		file=file+"/rating.txt";
		break;

   		case '2' :
		file=file+movie;
		file=file+"/sentiments.txt";
		break;
		case '4' :
		goto start;
		break;
		case 'E':
		case 'e' :
		
		exit(0);
		break;
		default:
                cout<<"\n\n<========> Wrong input!(Try Again:()<========>\n\n"<<endl;
                goto start1;
		}
strcpy(hello, file.c_str());
		sendto(sockfd, (const char *)hello, strlen(hello),
			0, (const struct sockaddr *) &servaddr,
				sizeof(servaddr));
		cout<<"Message has been sent.\n"<<endl;
			
		n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, (struct sockaddr *) &servaddr,
					&len);
		buffer[n] = '\0';
		printf("\n\n\nRecived: %s\n", buffer);
		cout<<"\n\n\n";

}
	close(sockfd);
	return 0;
}
