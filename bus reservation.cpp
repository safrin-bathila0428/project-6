#include<conio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
static int p=0;
class a
{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
		void install();
		void reservation();
		void empty();
		void show ();
		void available();
		void position(int i);
}
bus[10];
void vline(char ch)
{
	for(int i=50;i>0;i--)
	cout<<ch;
}
void a:: install()
{
	cout<<"enter Bus no:";
	cin>>bus[p].busn;
	cout<<"\nenter Drivers name:";
	cin>>bus[p].driver;
	cout<<"\nArrival time:";
	cin>>bus[p].arrival;
	cout<<"\nDeparture:";
	cin>>bus[p].depart;
	cout<<"\nFrom:\t\t\t";
	cin>>bus[p].from;
	cout<<"\nTo:\t\t\t";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
	}
	void a::reservation()
	{
		int seat;
		char number[5];
		top:
		cout<<"Bus no:";
		cin>>number;
		int n;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busn,number)==0)
			break;
		}
		while(n<=p)
		{
			cout<<"\nseat number:";
			cin>>seat;
			if(seat>32)
			{
				cout<<"\nThere are 32 are available in this bus.";
			}
			else
			{
				if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
				{
					cout<<"enter passengers name:";
					cin>>bus[n].seat[seat/4][(seat%4)-1];
					break;
				}
			else
			cout<<"\nThe is already reserved.";
			}
		}
		if(n>p)
		{
			cout<<"Enter correct bus no.\n";
			goto top;
		}
	}
	void a::empty()
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				strcpy(bus[p].seat[i][j],"Empty");
			}
		}
	}
	void a:: show()
	{
		int n;
		char number[5];
		cout<<"\nEnter bus no:";
		cin>>number;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busn,number)==0)
			break;
		}
		while(n<=p)
		{
			cout<<"\n*******\n";
			cout<<"Bus no:\t"<<bus[n].busn<<"\nDriver:\t"<<bus[n].driver<<"\t\tArrival time:\t"<<bus[n].arrival
			<<"\tDeparture time:"<<bus[n].depart<<"\nFrom:\t\t"<<bus[n].from<<"\t\tTo:\t\t"<<bus[n].to<<"\n";
			bus[0]. position(n);
			int a=1;
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<4;j++)
				{
					a++;
					if(strcmp(bus[n].seat[i][j],"Empty")!=0)
					cout<<"\nThe seat no"<<(a-1)<<"is resered for"<<bus[n].seat[i][j]<<".";
				}
			}
			break;
		}
		if(n>p)
		cout<<"Enter correct bus no:";
	}
	void a::position(int l)
	{
		int s=0;p=0;
		for(int i=0;i<8;i++)
		{
			cout<<"\n";
			for(int j=0;j<4;j++)
			{
				s++;
				if(strcmp(bus[l].seat[i][j],"Empty")==0)
				{
					cout.width(5);
					cout.fill(' ');
					cout<<s<<".";
					cout.width(10);
					cout.fill(' ');
					cout<<bus[l].seat[i][j];
					p++;
				}
			}
		}
		cout<<"\n\nThere are"<<p<<"seats empty in Bus No:"<<bus[l].busn;
	}
	void a::available()
	{
		for(int n=0;n<p;n++)
		{
			cout<<"\n*******\n";
			cout<<"Bus no:\t"<<bus[n].busn<<"\nDriver:\t"<<bus[n].driver<<"\t\tArrival time:\t"<<bus[n].arrival
			<<"\tDeparture time:\t"<<bus[n].depart<<"\nFrom:\t\t"<<bus[n].from<<"\t\tTo:\t\t\t"<<bus[n].to<<"\n";
		}
		}
		int main()
		{
			system("cls");
			int W;cout<<"\t\t\t\t******AK TRAVEL AGENCY*******"<<"\n"<<"\n";
			while(1)
			{
				cout<<"\n\n\n\n\n";
				cout<<"\t\t\t1.Install\n\t\t\t"
				<<"2.Reservation\n\t\t\t"
				<<"3.Show\n\t\t\t"
				<<"4. Available.\n\t\t\t"
				<<"5.Exit";
				cout<<"Enter your choice:";
				cin>>W;
				switch(W)
				{
					case 1:bus[p].install();break;
					case 2:bus[p].reservation();break;
					case 3:bus[0].show();break;
					case 4:bus[0]. available();break;
					case 5:cout<<"Thankyou"<<"visit again!"<<"\n"<<"\n";
					case 6:exit[0];
					
				}
			}
			return 0;
		}
	


