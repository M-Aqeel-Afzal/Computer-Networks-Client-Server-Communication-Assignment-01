
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include<iostream>
#include <fstream>
#define PORT	 8080
#define MAXLINE 1024
using namespace std;
int main() {
 
char hello[200] ;
	socklen_t  len;
	int  n,No_stds=5,serial=1;
	  

	char buf[256];
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);


	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// binding
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 5);



	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);




                          
	while(No_stds>0){


	cout<<"waiting for clinet\n\n"<<endl;


	recv(client_socket, &buf, sizeof(buf), 0);
	printf("Recived Information: \n %s \n", buf);
int y,d,m,h,mi,se,mi1,h1,d1;
    time_t t = time(NULL);
  struct tm tm = *localtime(&t);
y=tm.tm_year + 1900;

m=tm.tm_mon + 1;
d=tm.tm_mday;
h=tm.tm_hour;
mi=tm.tm_min;
mi1=mi+15;
h1=h;
d1=d;
if(mi1>=60)
{mi1=mi1%60;
h1++;
}
if(h1>=12)
{h1=h1%12;
d1++;
}
se=tm.tm_sec;
	string date_="0"+to_string(d);
	
	date_=date_+"/";
	date_=date_+to_string(m);
	date_=date_+"/";
	date_=date_+to_string(y);

	string time_=to_string(h);
	time_=time_+":";
	time_=time_+to_string(mi);
	time_=time_+":";
	time_=time_+to_string(se);

string date_1="0"+to_string(d1);
	
	date_1=date_1+"/";
	date_1=date_1+to_string(m);
	date_1=date_1+"/";
	date_1=date_1+to_string(y);

	string time_1=to_string(h1);
	time_1=time_1+":";
	time_1=time_1+to_string(mi1);
	time_1=time_1+":";
	time_1=time_1+to_string(se);

 string order="";
order="Order Noted: "+date_;
order=order+"  ";
order=order+time_;
order=order+"\n";
order=order+"Serving Time: ";
order=order+date_1;
order=order+"  ";
order=order+time_1;
strcpy(hello, order.c_str());




string name="",dept="",roll="",items="";
 char *pk;
    
    char *tk = strtok(buf, "-");
    
       pk=tk;

        tk = strtok(NULL, "-");
    	name=tk;
	 tk = strtok(NULL, "-");
	roll=tk;
	tk = strtok(NULL, "-");
	
    	items=tk;
char *tk2= strtok(pk, ":");
    tk2 = strtok(NULL, ":");
        dept=tk2;

cout<<"name: "<<name<<endl;
cout<<"dpet: "<<dept<<endl;
char *tk1 = strtok(tk, ":");
    tk1 = strtok(NULL, ":");
       items=tk1;
cout<<"order: "<<items<<endl;





string writer="";
writer=writer+roll;
writer=writer+"\t\t";
writer=writer+dept;
writer=writer+"\t\t";
writer=writer+date_;
writer=writer+"\t\t";
writer=writer+time_;
writer=writer+"\t\t";
writer=writer+name;
writer=writer+"\t\t";
writer=writer+items;

cout<<writer<<endl;
if(dept==" CS"||dept==" cs")
{
fstream file1;
file1.open ("CS.txt", ios::out | ios::in | ios::app );
file1 <<writer<< endl;
file1.close();
}
else if(dept==" DS"||dept==" ds")
{
fstream file1;
file1.open ("DS.txt", ios::out | ios::in | ios::app );
file1 <<writer<< endl;
file1.close();
}
else if(dept==" AI"||dept==" ai")
{
fstream file1;
file1.open ("AI.txt", ios::out | ios::in | ios::app );
file1 <<writer<< endl;
file1.close();
}
else if(dept==" SE"||dept==" se")
{
fstream file1;
file1.open ("SE.txt", ios::out | ios::in | ios::app );
file1 <<writer<< endl;
file1.close();
}

	send(client_socket, (const char *)hello, sizeof(hello), 0);
No_stds--;
serial--;
}
	
	close(server_socket);
	
	return 0;
}
