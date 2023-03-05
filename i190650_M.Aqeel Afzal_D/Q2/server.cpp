
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fstream>
#include<iostream>
#define PORT	 8080
#define MAXLINE 1024
using namespace std;

int main() {
	int sockfd;
	char buffer[MAXLINE];
	char hello[] = "";
	struct sockaddr_in servaddr, cliaddr;
	
	
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	
	
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Binding
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("binding failed");
		exit(EXIT_FAILURE);
	}
	
	int n;
	socklen_t len;
	len = sizeof(cliaddr); 
	while(1){
		
		printf("Waiting for client\n");

		n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, ( struct sockaddr *) &cliaddr,
					&len);
	
		buffer[n] = '\0';
                fstream file1;


file1.open (buffer, ios::out | ios::in | ios::app );
string str1,str2="";
	while (std::getline(file1, str1))
	    {
	str2=str2+str1;
	      
	    }
	

strcpy(buffer, str2.c_str());

		
				
		sendto(sockfd, (const char *)buffer, strlen(buffer),
			0, (const struct sockaddr *) &cliaddr,
				len);
	cout<<"Required Information has been sent to clinet\n\n"<<endl;
 str2="";
    
 	


		
	}
	return 0;
}
