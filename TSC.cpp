#include<time.h>
#include<dos.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>

/**
* 17 December 2015
* Collaborators: Avinash Raja Amarchand, PSS Abishek, Tarun Subramanian
*/

int i;
class acc
{
	public:
	char name[15];
	int score;
}x;

void start();
void hs();
void help();
void about();

void line1(char*);
void line2(char*);
void line3(char*);
void line4(char*);
void line5(char*);

void main()
{
  int flag=1;
  while(flag)
  {
	 clrscr();
	 cout<<"\n\t\t  ********************************************"
		  <<"\n\t\t  *          Typing Speed Calculator         *"
		  <<"\n\t\t  ********************************************"
		  <<"\n\n"
		  <<"\n\t1.play"
		  <<"\n\t2.Highscores"
		  <<"\n\t3.Help"
		  <<"\n\t4.About"
		  <<"\n\t5.Exit";

	 int ch;
	 cout<<"\n\n\tEnter your choice!\n\n";
	 cin>>ch;
	 switch(ch)
	 {
		case 1:clrscr();start();
				 break;
		case 2:clrscr();hs();
				 break;
		case 3:clrscr();help();
				 break;
		case 4:clrscr();about();
				 break;
		case 5:exit(0);
				 break;
		default:cout<<"\nEnter a proper input!\nPress any key to continue!.";
		getch();
	 }
}
}

void start()
{
clrscr();
char entered_text[50],txt[50];
randomize();
time_t prev,now;

int num;
num=random(5)+1;
cout<<"\nType this:";
switch(num)
{
case 1:line1(txt);
cout<<txt;
break;
case 2:line2(txt);
cout<<txt;
break;
case 3:line3(txt);
cout<<txt;
break;
case 4:line4(txt);
cout<<txt;
break;
case 5:line5(txt);
cout<<txt;
break;
}
cout<<"\nPress any key to start!";
getch();
cout<<"\nGO!\n\n";

prev=time(0);

gets(entered_text);

now=time(0);
if(strcmp(entered_text,txt)==0)
{
		cout<<"\nYour time:";
		time_t tfinal=now-prev;
		cout<<tfinal<<"s";

		cout<<"\nPress any key to continue!";
		getch();



				acc temp;
				int flag=1;
				char name[15];
				cout<<"\nEnter name:";
				gets(name);
				ifstream filin("saves.dat",ios::in|ios::binary);

				while(filin.read((char *)&temp,sizeof(temp)))
				{
				if(strcmp(temp.name,name)==0)
				flag=0;
				else
				flag=1;
				}

				filin.close();

				strcpy(temp.name,name);
				temp.score=tfinal;

				if(flag)
				{
				ofstream file("saves.dat",ios::app|ios::binary);

				file.write((char *)&temp,sizeof(temp));
				cout<<"\nScore saved!.";
				cout<<"\nPress any key to continue!.";
				getch();

				file.close();
				}
				else
				{
						fstream f("saves.dat",ios::in|ios::binary|ios::out);
						//f.seekg(0);
						long pos;
						while(!f.eof())
						{
						pos=f.tellg();
						f.read((char *)&temp,sizeof(temp));
						if(strcmp(temp.name,name)==0)
						{
								if(temp.score>tfinal)
								{
								strcpy(temp.name,name);
								temp.score=tfinal;
								f.seekg(pos);
								f.write((char *)&temp,sizeof(temp));
								cout<<"\nScore updated!.";

								break;
								}
								else
								{
								cout<<"\nYou already have a best score, try harder!.";

								break;
								}
						}
						}
						f.close();






				cout<<"\npress any key to continue";
				getch();
				}

}
else
{
cout<<"\nWrong input, try again";
cout<<"\nPress any key to continue!";
getch();
}

}

void line1(char* output)
{
char line[]="Do not pray for an easy life, pray for the strength to endure a difficult one.";
strcpy(output,line);
}
void line2(char* output)
{
char line[]="If you spend too much time thinking about something, you'll never get it done.";
strcpy(output,line);
}
void line3(char* output)
{
char line[]="A goal is not always meant to be reached, it often serves simply as something to aim at.";
strcpy(output,line);
}
void line4(char* output)
{
char line[]="The key to immortality is first living a life worth remembering.";
strcpy(output,line);
}
void line5(char* output)
{
char line[]="If at first you don't succeed, try and try harder.";
strcpy(output,line);
}

void help()
{
clrscr();
cout<<"\n\t\t  ********************************************"
	 <<"\n\t\t  *          Typing Speed Calculator         *"
	 <<"\n\t\t  ********************************************"
	 <<"\n\n"
	 <<"\n * Timer starts when GO! appears."
	 <<"\n * Type as fast as you can!.\nPress any key to continue!.";

getch();
}

void about()
{

clrscr();
cout<<"\n\t\t  ********************************************"
	 <<"\n\t\t  *          Typing Speed Calculator         *"
	 <<"\n\t\t  ********************************************"
	 <<"\n\n"
	 <<"\n Type Speed Calcuator is an utility which aims to imporve"
	 <<"\n the typing speed of beginners."
	 <<"\n By:"
	 <<"\n\n\t Avinash Raja"
	 <<"\n\n\t P.S.S.Abishek"
	 <<"\n\n\t Tarun Subramanian\nPress any key to continue!.";
getch();
}
void hs()
{
acc temp;
ifstream filin("saves.dat",ios::in|ios::binary);
while(filin.read((char *)&temp,sizeof(temp)))
	{
		cout<<"Name:"<<temp.name<<"\tScore:"<<temp.score<<endl;
	}
	getch();
filin.close();
}
