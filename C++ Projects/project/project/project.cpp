#include<iostream>
//electronics device inventory management system
using namespace std;
int lap=0,tab=0,Ph=0,Pc=0,i;
void count_device(int a)
{
	switch(a)
	{
	case 1:lap++;break;
	case 2:tab++;break;
	case 3:Ph++;break;
	case 4:Pc++;break;
	}
}
class LAPTOP;
class PC;
class TABLET;
class PHONE;
class config
{
public:
	string brand,model,chip,os;
	float scr,price;
	int stock;
	void set()
	{
		cout<<"Enter Brand: ";
		cin>>brand;
		cout<<"Enter Model: ";
		cin>>model;
		cout<<"Enter Chip: ";
		cin>>chip;
		cout<<"Enter OS: ";
		cin>>os;
		cout<<"Enter Screen size: ";
		cin>>scr;
		cout<<"Enter Price: ";
		cin>>price;
		cout<<"Enter Stock: ";
		cin>>stock;
	}
	void get()
	{
		cout<<"Brand: "<<brand<<endl;
		cout<<"Model: "<<model<<endl;
		cout<<"Chip: "<<chip<<endl;
		cout<<"OS: "<<os<<endl;
		cout<<"Screen size: "<<scr<<endl;
		cout<<"Price: "<<price<<endl;
		cout<<"Stock remaining: "<<stock<<endl;
	}
}c;
class LAPTOP:public config
{
	string colour[4]={"silver","blue","black","white"};
	int col;
public:
	 void setL()
	{
		cout<<"ENTER COLOUR NO."<<endl;
		for(int i=0;i<4;i++)
			cout<<i<<" - "<<colour[i]<<"\t";
		cin>>col;
		if(col<0 || col>3)
			cout<<"INVALID INPUT";
		else
		{
			set();
			count_device(1);
		}
	}
	 void getL()
	 {
		 get();
		 cout<<"Colour: "<<colour[col]<<endl;
	 }
}l[5];
class TABLET:public config
{
	string colour[3]={"gray","black","white"};
	int col;
public:
 void setT()
{
	cout<<"ENTER COLOUR NO."<<endl;
	for(int i=0;i<3;i++)
		cout<<i<<" - "<<colour[i]<<"\t";
	cin>>col;
	if(col<0 || col>2)
		cout<<"INVALID INPUT";
	else
	{
		set();
		count_device(2);
	}
}
 void getT()
 {
	 get();
	 cout<<"Colour: "<<colour[col]<<endl;
 }

}t[5];
class PHONE:public config
{
	string colour[4]={"silver","gray","black","white"};
		int col,sim;
	public:
		 void setPH()
		{
			cout<<"ENTER COLOUR NO."<<endl;
			for(int i=0;i<4;i++)
				cout<<i<<" - "<<colour[i]<<"\t";
			cin>>col;
			cout<<"ENTER NO. OF SIM CARD SLOTS";
			cin>>sim;
			if(col<0 || col>3)
				cout<<"INVALID INPUT";
			else
			{
				set();
				count_device(3);
			}
		}
		 void getPH()
		 {
			 get();
			 cout<<"Colour: "<<colour[col]<<endl;
			 cout<<"SIM :"<<sim<<endl;
		 }

}ph[5];
class PC:public config
{
	string colour[2]={"silver","black"};
	int col;
public:
 void setPC()
{
	cout<<"ENTER COLOUR NO."<<endl;
	for(int i=0;i<2;i++)
		cout<<i<<" - "<<colour[i]<<"\t";
	cin>>col;
	if(col<0 || col>1)
		cout<<"INVALID INPUT";
	else
	{
		set();
		count_device(4);
	}
}
 void getPC()
 {
	 get();
	 cout<<"Colour: "<<colour[col]<<endl;
 }
}pc[5];

void sortLAP()
{
	LAPTOP temp;
	for(int i=0;i<lap-1;i++)
		for(int j=0;j<lap-1-i;j++)
		{
			if(l[j].price>l[j+1].price)
			{
				temp=l[j];
				l[j]=l[j+1];
				l[j+1]=temp;
			}
		}
}

void sortTAB()
{
	TABLET temp;
	for(int i=0;i<tab-1;i++)
		for(int j=0;j<tab-1-i;j++)
		{
			if(t[j].price>t[j+1].price)
			{
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
		}
}

void sortPH()
{
	PHONE temp;
	for(int i=0;i<Ph-1;i++)
		for(int j=0;j<Ph-1-i;j++)
		{
			if(ph[j].price>ph[j+1].price)
			{
				temp=ph[j];
				ph[j]=ph[j+1];
				ph[j+1]=temp;
			}
		}
}

void sortPC()
{
	PC temp;
	for(int i=0;i<Pc-1;i++)
		for(int j=0;j<Pc-1-i;j++)
		{
			if(pc[j].price>pc[j+1].price)
			{
				temp=pc[j];
				pc[j]=pc[j+1];
				pc[j+1]=temp;
			}
		}
}
void sales(int a)
{
	switch(a)
	{
	case 1:
		if(l[i].stock>0)
			l[i].stock-=1;
		else
			cout<<"NO STOCK AVAILABLE"<<endl;
		break;
	case 2:
		if(t[i].stock>0)
			t[i].stock-=1;
		else
			cout<<"NO STOCK AVAILABLE"<<endl;
		break;
	case 3:
		if(ph[i].stock>0)
			ph[i].stock-=1;
		else
			cout<<"NO STOCK AVAILABLE"<<endl;
		break;
	case 4:
		if(pc[i].stock>0)
			pc[i].stock-=1;
		else
			cout<<"NO STOCK AVAILABLE"<<endl;
		break;
	}
}
int main()
{
	int ch,device,cnt=0,j;
	string mod;
	while(1)
	{
		cout<<"\nENTER 1 for INSERTING"<<endl;
		cout<<"ENTER 2 for DISPLAY"<<endl;
		cout<<"ENTER 3 for SORT"<<endl;
		cout<<"ENTER 4 for SEARCH BY BRAND NAME"<<endl;
		cout<<"ENTER 5 for DELETE DATA"<<endl;
		cout<<"ENTER 6 for SALES ENTRY"<<endl;
		cout<<"ENTER 7 for EXIT"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"ENTER 1 for LAPTOP"<<endl;
				cout<<"ENTER 2 for TABLET"<<endl;
				cout<<"ENTER 3 for PHONE"<<endl;
				cout<<"ENTER 4 for DESKTOP"<<endl;
				cin>>device;
				switch(device)
				{
					case 1:
							l[lap].setL();
						break;
					case 2:
							t[tab].setT();
						break;
					case 3:
							ph[Ph].setPH();
						break;
					case 4:
							pc[Pc].setPC();
						break;
					default:
						cout<<"INVALID INPUT"<<endl;
						break;
				}
				break;
			case 2:
				cout<<"ENTER 1 for LAPTOP"<<endl;
				cout<<"ENTER 2 for TABLET"<<endl;
				cout<<"ENTER 3 for PHONE"<<endl;
				cout<<"ENTER 4 for DESKTOP"<<endl;
				cout<<"ENTER 5 for ALL devices"<<endl;
				cin>>device;
				switch(device)
				{
					case 1:
						for(i=0;i<lap;i++)
						{
							cout<<"LAPTOP "<<i+1<<endl;
							l[i].getL();
						}
						break;
					case 2:
						for(i=0;i<tab;i++)
						{
							cout<<"TABLET "<<i+1<<endl;
							t[i].getT();
						}
						break;
					case 3:
						for(i=0;i<Ph;i++)
						{
							cout<<"PHONE "<<i+1<<endl;
							ph[i].getPH();
						}
						break;
					case 4:
						for(i=0;i<Pc;i++)
						{
							cout<<"PC "<<i+1<<endl;
							pc[i].getPC();
						}
						break;
					case 5:
						cout<<"----LAPTOP----"<<endl;
						cout<<"\n----------------------------------"<<endl;
						for(i=0;i<lap;i++)
						{
							cout<<i+1<<endl;
							l[i].getL();
						}
						cout<<"\n----------------------------------"<<endl;
						cout<<"----TABLET----"<<endl;
						cout<<"\n----------------------------------"<<endl;

						for(i=0;i<tab;i++)
						{
							cout<<i+1<<endl;
							t[i].getT();
						}
						cout<<"\n----------------------------------"<<endl;
						cout<<"----PHONE----"<<endl;
						cout<<"\n----------------------------------"<<endl;

						for(i=0;i<Ph;i++)
						{
							cout<<i+1<<endl;
							ph[i].getPH();
						}
						cout<<"\n----------------------------------"<<endl;
						cout<<"----DESKTOP----"<<endl;
						cout<<"\n----------------------------------"<<endl;
						for(i=0;i<Pc;i++)
						{
							cout<<"PC "<<i+1<<endl;
							pc[i].getPC();
						}
						cout<<"\n----------------------------------"<<endl;
						break;
					default:
						cout<<"INVALID INPUT"<<endl;
						break;
				}
				break;
			case 3:
				cout<<"ENTER 1 for LAPTOP"<<endl;
				cout<<"ENTER 2 for TABLET"<<endl;
				cout<<"ENTER 3 for PHONE"<<endl;
				cout<<"ENTER 4 for DESKTOP"<<endl;
				cout<<"ENTER 5 for ALL devices"<<endl;
				cin>>device;
				switch(device)
				{
					case 1:
						sortLAP();
					break;
					case 2:
						sortTAB();
					break;
					case 3:
						sortPH();
					break;
					case 4:
						sortPC();
					break;
					case 5:
						sortLAP();
						sortTAB();
						sortPH();
						sortPC();
					break;
					default:
						printf("Invalid Input");
						break;
				}
				break;
			case 4:
				//SEARCH
				cout<<"ENTER 1 for LAPTOP"<<endl;
				cout<<"ENTER 2 for TABLET"<<endl;
				cout<<"ENTER 3 for PHONE"<<endl;
				cout<<"ENTER 4 for DESKTOP"<<endl;
				cin>>device;

				cout<<"Enter brand name";
				cin>>mod;
				cnt=0;
				switch(device)
				{
					case 1:
						for(i=0;i<lap;i++)
						{
							if(mod==l[i].brand)
							{
								cout<<"LAPTOP "<<i+1<<endl;
								l[i].getL();
								cnt++;
							}
						}
						break;
					case 2:
						for(i=0;i<tab;i++)
						{
							if(mod==t[i].brand)
							{
								cout<<"TABLET "<<i+1<<endl;
								t[i].getT();
								cnt++;
							}
						}
						break;
					case 3:
						for(i=0;i<Ph;i++)
						{
							if(mod==ph[i].brand)
							{
								cout<<"PHONE "<<i+1<<endl;
								ph[i].getPH();
								cnt++;
							}
						}
						break;
					case 4:
						for(i=0;i<Pc;i++)
						{
							if(mod==pc[i].brand)
							{
								cout<<"PC "<<i+1<<endl;
								pc[i].getPC();
								cnt++;
							}
						}
						break;
					default:
						cout<<"INVALID INPUT"<<endl;
						break;
				}
				if(cnt==0)
					cout<<"NO SUCH DATA FOUND";

				break;
				case 5:
					cout<<"ENTER 1 for LAPTOP"<<endl;
					cout<<"ENTER 2 for TABLET"<<endl;
					cout<<"ENTER 3 for PHONE"<<endl;
					cout<<"ENTER 4 for DESKTOP"<<endl;
					cin>>device;
					cout<<"Enter model name to be deleted";
					cin>>mod;
					cnt=0;
					switch(device)
					{
						case 1:
							for(i=0;i<lap;i++)
							{
								if(mod==l[i].model)
								{
									cnt++;
									for(j=i;j<lap-1;j++)
									{
										l[j]=l[j+1];
									}
									lap--;
									break;
								}
							}
							break;
						case 2:
							for(i=0;i<tab;i++)
							{
								if(mod==t[i].model)
								{
									cnt++;
									for(j=i;j<tab-1;j++)
									{
										t[j]=t[j+1];
									}
									tab--;
									break;
								}
							}
							break;
						case 3:
							for(i=0;i<Ph;i++)
							{
								if(mod==ph[i].model)
								{
									cnt++;
									for(j=i;j<Ph-1;j++)
									{
										ph[j]=ph[j+1];
									}
									Ph--;
									break;
								}
							}
							break;
						case 4:
							for(i=0;i<Pc;i++)
							{
								if(mod==pc[i].model)
								{
									cnt++;
									for(j=i;j<Pc-1;j++)
									{
										pc[j]=pc[j+1];
									}
									Pc--;
									break;
								}
							}
							break;
						default:
							cout<<"INVALID INPUT";
							break;
					}
					if(cnt==0)
						cout<<"NO SUCH DATA FOUND";

					break;
					break;
			case 6:
				cout<<"ENTER 1 for LAPTOP"<<endl;
				cout<<"ENTER 2 for TABLET"<<endl;
				cout<<"ENTER 3 for PHONE"<<endl;
				cout<<"ENTER 4 for DESKTOP"<<endl;
				cin>>device;
				cout<<"Enter model name that's sold";
				cin>>mod;
				cnt=0;
				switch(device)
				{
					case 1:
						for(i=0;i<lap;i++)
						{
							if(mod==l[i].model)
							{
								sales(1);
								cnt++;
							}
						}
						break;
					case 2:
						for(i=0;i<tab;i++)
						{
							if(mod==t[i].model)
							{
								sales(2);
								cnt++;
							}
						}
						break;
					case 3:
						for(i=0;i<Ph;i++)
						{
							if(mod==ph[i].model)
							{
								sales(3);
								cnt++;
							}
						}
						break;
					case 4:
						for(i=0;i<Pc;i++)
						{
							if(mod==pc[i].model)
							{
								sales(4);
								cnt++;
							}
						}
						break;
					default:
						cout<<"INVALID INPUT";
						break;
				}
				if(cnt==0)
					cout<<"NO SUCH DATA FOUND";
				break;
			case 7:
				exit(0);
				break;
		}
	}
	return 0;
}


