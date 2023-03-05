
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<iostream>
#include <ctime>
#include<string.h>
#define PORT	 8080
#define MAXLINE 1024
using namespace std;
int main() {

	char buf[200];
	char hello[] ="";
	
	int sock;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);

	
	
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);



	int n,table,No_stds=5;

string rollno,dept;
char order[200],name[200];
socklen_t len;
connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
while(No_stds>0)
{
                                                       //User Input
		cout<<"Please Enter Roll number: "<<endl;
		cin>>rollno;
                cout<<"Please Enter Name: "<<endl;
		cin.ignore();
		cin.getline(name,200);
                cout<<"Please Enter Your Department(DS,CS,AI,SE): "<<endl;
		cin>>dept;
		while(1)
		{
		if(dept=="CS"||dept=="cs"||dept=="AI"||dept=="ai"||dept=="SE"||dept=="se"||dept=="DS"||dept=="ds")
		break;
			cout<<"Worng Depratment Name try Again!(DS,CS,AI,SE): "<<endl;
			cin>>dept;
		}
                
		cout<<"Please Enter Table.No(1 to 20): "<<endl;
		cin>>table;
		while(table<0||table>20)
		{cout<<"Wrong Input!-----Please Enter Table.No(1 to 20): "<<endl;
		cin>>table;
		}
		cout<<"Please Enter Order: "<<endl;
		cin.ignore();
		cin.getline(order,200);




  
	
string order_str;
order_str="Order By: "+dept;
order_str=order_str+"-";
order_str=order_str+name;
order_str=order_str+"-";
order_str=order_str+rollno;
order_str=order_str+"-";
order_str=order_str+to_string(table);
order_str=order_str+"\n";
order_str=order_str+"Order Items: ";

order_str=order_str+order;
	

strcpy(hello, order_str.c_str());

cout<<"\n\n\n";


   
   
    
	
	send(sock, (const char *)hello, 200, 0);

	recv(sock, &buf, sizeof(buf), 0);
	printf("Recvied: \n %s \n", buf);


No_stds--;

}
	close(sock);
	return 0;
}
