#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include <iomanip>
#include<stdlib.h>
using namespace std;

int tt;
int updateorbs=0;
int acc,amount,a, pin, dp, wdraw,i, logout=0;
string username,password, iban,temp;
char c;
string gu,gp, giban, x;								//login function
int ga, gpin,choice;
float gb;
void menu(int a);
void PressToMenu(void);
void DelayToMenu(int);
float orbits =0,orb,temporbs; 

string date() {
    time_t now = time(0);
	string date;
	tm *ltm = localtime(&now);

   date= to_string(1900 + ltm->tm_year)+"/"+to_string(1 + ltm->tm_mon)+"/"+to_string(ltm->tm_mday);
   return date;
}
string time() {
   time_t now = time(0);
   tm *ltm = localtime(&now);
   string time;
   time=to_string(5+ltm->tm_hour)+" : "+to_string(30+ltm->tm_min)+" : "+to_string(ltm->tm_sec);
   return time;
}
void gotoxy (int x, int y)
    {
         COORD coordinates;     
         coordinates.X = x;     
         coordinates.Y = y;     
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
    }


class Account{
	protected:
			string uname;
			string pword;
			int atype;
			float balance;
			int pin1;
			string IBAN;
			
	public:
		Account(string a, string b, int c, float d, int e, string f){
			uname=a;
			pword=b;
			atype=c;
			balance = d;
			pin1=e;
			IBAN=f;
		}
		
		void setGlobalVar(){
			gu=uname;	
			gb=balance;		
			giban=IBAN;	
			ga=atype;
			gp=pword;
			gpin=pin1;
		}
		
		friend void PressToMenu(void);
		friend void DelayToMenu(int);
	
		
		void Details(){
			int x;
			x=rand()%2;
			cout<<"\tACCOUNT INFO\n";
			cout<<"\nUsername: "<<uname;
			cout<<"\n\nIBAN: "<<IBAN;
			cout<<"\n\nBalance: "<<balance;
			cout<<"\n\nAccount created on: "<<date();
			if(atype==3){
				cout<<"\n\nCard Type: Debit";
			}
			else if(x==0){
				cout<<"\n\nCard Type: Debit";
			}
			else if(x==1){
				cout<<"\n\nCard Type: Credit";
			}
			PressToMenu();
		}
		void orbitfunc(int amt){
			cout<<"\n\tYou Recieved "<<amt/100<<" Orbits";
			temporbs+=amt/100;
			fstream temp2("orbits.txt",ios::app);
			temp2<<username<<" "<<temporbs<<endl;
			temp2.close();
		}

void orbitswrite(){
	cout<<"\t\tVIEW ORBITS";
ifstream ob("orbits.txt");
	while(!ob.eof()&&ob>>username>>temporbs ){
		if (username == uname)
		tt += temporbs;
	}

	cout<<"\n\nCurrent orbits: "<<tt;
	tt = 0;

	cout<<"\n\nPress 1 to Redeeem:  ";
	cin>>choice;
	if (choice == 1)
		redeem();
	else{
		PressToMenu();
	}
	temporbs = 0;
}
void sessionSummary(){
		system("cls");
		cout<<"SESSION SUMMARY:"<<endl<<endl;
		for(int i=1;i<=rand()%10;i++){
			cout<<i<<"- "<<date()<<" "<<time()<<endl;
		
		}
		
		PressToMenu();
		
}
void redeem(){
	ifstream obj3("orbits.txt");

	cout<<"\nRedeem Offers:\n1. TV\t100 orbits\n2. Fridge\t120 orbits\n3. Biryani\t20 orbits\n4. Cancel\nPlease Select:  ";
	here12: cin>>choice;
	if (choice == 1){
		ifstream obb("orbits.txt");
		while(!obb.eof()&&obb>>username>>temporbs ){
			if (username == uname)
			tt += temporbs;
		}
		if (tt >= 100)
		{
			ofstream tempp1("orbits.txt",ios::app);
			tempp1<<uname<<" "<<-100<<endl;
			tt -= 100;
			cout<<"\nYour TV will be delivered\nUpdated Orbits:  "<<tt;
			tt=0;
		}
		else
		cout<<"\nInsufficient Orbits. Can't Redeem";
		PressToMenu();
	}
else if (choice == 2){
ifstream obb("orbits.txt");
while(!obb.eof()&&obb>>username>>temporbs ){
if (username == uname)
tt += temporbs;
}
if (tt >= 120)
{
ofstream tempp1("orbits.txt",ios::app);
tempp1<<uname<<" "<<-120<<endl;
tt -= 120;
   cout<<"\nYour fridge will be delivered\nUpdated Orbits:  "<<tt;
   tt=0;
}
else
cout<<"\nInsufficient Orbits. Can't Redeem";
PressToMenu();
}
else if (choice == 3){
ifstream obb("orbits.txt");
while(!obb.eof()&&obb>>username>>temporbs ){
if (username == uname)
tt += temporbs;
}
if (tt >= 20)
{
ofstream tempp1("orbits.txt",ios::app);
tempp1<<uname<<" "<<-20<<endl;
tt -= 20;
   cout<<"\nYour biryani will be delivered\nUpdated Orbits:  "<<tt;
   tt=0;
}
else
cout<<"\nInsufficient Orbits. Can't Redeem";
PressToMenu();
}
else if(choice == 4)
	menu(ga);
else {
cout<<"\nInvalid choice\nPlease select again:  ";
goto here12;
}


}
		
		
		void accountstatement(){
			int k=30;
			int h=3;
			system("CLS");
			cout<<"\t\tAccount Statement "<<endl<<endl;
			string ibann;
			int with, dep;
			ifstream Deposit("deposit.txt");
			ifstream Withdraw("withdraw.txt");
			cout<<"DEPOSIT\t\t\tWITHDRAW/TRANSFER"<<endl<<endl;
			while(!Deposit.eof()&&Deposit>>ibann>>dep){
				if(ibann==IBAN){
					cout<<dep<<endl;
				}
				
			}
			Deposit.close();
			while(!Withdraw.eof()&&Withdraw>>ibann>>dep){
				if(ibann==IBAN){
					gotoxy(k,h);
					cout<<dep<<endl;
					++h;
				}
				
			}
			Withdraw.close();
			cout<<"\n\n\n\n\tPress any key to go back to menu...";
			if(getche()){
				system("CLS");
				gu=uname;
				menu(ga);
			}
						
		}
		void settings(){
			cout<<"\t\t SETTINGS"<<endl;	
			cout<<"\n1) Change Password"<<endl;								//all transactions, deposit, withdraw, trasnferred
			cout<<"\n2) Change Card Pin"<<endl;								//k electric, sui gas, ptcl
			cout<<"\n3) Session Summary"<<endl;								//transaction
		//	cout<<"\n4) View Limits"<<endl;  						 		//change pin, show debit/credit card
			cout<<"\n4) Main Menu"<<endl; 
			
			cout<<"\nPlease Select:  ";
			c=getche();  

			fflush(stdin);
			if(c=='1'){
			here15:cout<<"\n\nEnter current password: ";
			getline(cin,gp);
		
			if(gp!=pword){
				cout<<"\n\nIncorrect password! ";
				goto here15;
			}
			ifstream a("user.txt");
			ofstream b("temp.txt");
			fflush(stdin);
			while(!a.eof()&&a>>gu>>gp>>ga>>gb>>gpin>>dp>>wdraw>>giban){
				if(uname==gu){
					cout<<"\nEnter New Password:  ";
					getline(cin,gp);
					pword=gp;
					
				}
				b<<gu<<" "<<gp<<" "<<ga<<" "<<gb<<" "<<gpin<<" "<<dp<<" "<<wdraw<<" "<<giban<<"\n";
							
			}
						a.close();
						b.close();
						
						ifstream obj1("temp.txt");
						ofstream obj2("user.txt");
					while(!obj1.eof()&&getline(obj1,x)){
							obj2<<x<<endl;							
						}
						obj1.close();
						obj2.close();
						cout<<"\n\n\n\n\n\tPassword Changed Sussessfully!";
						setGlobalVar();
						DelayToMenu(1000);
			}
			else if(c=='2'){
			here16:cout<<"\nEnter current pin: ";
			cin>>gpin;
			if(gpin!=pin1){
				cout<<"\nIncorrect PIN! ";
				goto here16;
			}
			ifstream abc("user.txt");
			ofstream dx("temp.txt");
			fflush(stdin);
			
			while(!abc.eof()&&abc>>gu>>gp>>ga>>gb>>gpin>>dp>>wdraw>>giban){
						if(uname==gu){
							cout<<"\nEnter New PIN:  ";
							cin>>gpin;
							pin1=gpin;
							while(gpin<1000||gpin>9999){
								cout<<"\nInvalid PIN!"<<endl;
								cout<<"\nEnter New PIN:  ";
								cin>>gpin;
							};
						 	
						 }
							dx<<gu<<" "<<gp<<" "<<ga<<" "<<gb<<" "<<gpin<<" "<<dp<<" "<<wdraw<<" "<<giban<<"\n";
							
						}
						abc.close();
						dx.close();
						ifstream obj11("temp.txt");
					ofstream obj22("user.txt");
					while(!obj11.eof()&&getline(obj11,x)){
							obj22<<x<<endl;							
						}
						obj11.close();
						obj22.close();
						cout<<"\n\n\n\n\n\tPIN Changed Sussessfully!";
						setGlobalVar();
						DelayToMenu(1000);
			}
			else if(c=='3'){
				sessionSummary();
				PressToMenu();
			}
			else if(c=='5'){
				system("CLS");
				setGlobalVar();
				menu(ga);
			}
		
		}
		virtual void billpay()=0;
		
		virtual void transfer()=0;
	
		
		
		void deposit(float x){
			balance+=x;
		}	
		string getusername(){
			return uname;
		}	
		void setbalance(float x){
			balance = x;
		} 
		float getbalance(){
			return balance;
		}
		Account(){
			uname="";
			pword="";
			atype=0;
			balance = 0;
			pin1=0;
			IBAN="";
		}
	

};
class CurrentAccount:public Account{
	public:
		CurrentAccount(string a, string b, int c, float d, int e, string f) : Account(a,b,c,d,e,f){}
		void billpay(){
			srand(time(0));
			string temp = "";
			cout<<"Bill Options: "<<endl;
			cout<<"\n1. K-Electric\n2. PTCL\n3. Sui Southern Gas Limited\n4. Karachi Water and Sewarage Board\n5. University fee"<<endl;
			c=getche();
			system("CLS");
			ofstream obj2("bills.txt");
    		
    for (int i = 3; i < IBAN.size(); ++i) {
            temp = temp + IBAN[i];
    }
			obj2<< "KE"+temp<<" "<<rand()%9999<<endl<< "PTCL"+temp <<" "<<rand()%9999<<endl<< "SSGL"+temp <<" "<<rand()%9999<<endl<< "KWSB"+temp <<" "<<rand()%9999<<endl<< "21k"+temp <<" "<<rand()%9999<<endl;
	        obj2.close();
	        
	        int xd, p;
			string f;
			int flag=0;
	        string ib;
	        
			here8: cout<<"Enter Bill number:  ";
			cin>>x;
			ifstream b("bills.txt",ios::in);
			while(!b.eof()){
				b>>f>>a;
				if(f == x){
					flag=1;
					cout<<"Bill amount is: "<<a;
					break;
				}
				
				}
				if(flag==0) {
					goto here8;
				}
				
					if(a > balance){
						cout<<"\nInsufficient funds! Cant pay bill...\n";
						Sleep(1000);
						system("CLS");
						gu=uname;
						gb=balance;
						menu(ga);
					}
					else 
					{
						balance-=a;
						
						ifstream in("user.txt");
						ofstream out("temp.txt");
						
						while(!in.eof()&&in>>gu>>gp>>ga>>gb>>gpin>>dp>>wdraw>>giban){
							if(gu == uname){
								gb -= a;
								wdraw=a;
								f=giban;
								p=dp;
							}
							if(ib==giban){
								gb+=a;
								dp=a;
								xd=wdraw;
								
							}
							out<<gu<<" "<<gp<<" "<<ga<<" "<<gb<<" "<<gpin<<" "<<dp<<" "<<wdraw<<" "<<giban<<"\n";
						}
						in.close();
						out.close();
					}
					ofstream Withdraw("withdraw.txt",ios::app);
					Withdraw<<IBAN<<" "<<a<<"\n";
					Withdraw.close();
					ifstream inrewrite("temp.txt");
					ofstream outre("user.txt");
					
					while(!inrewrite.eof()&&getline(inrewrite,x)){
							outre<<x<<endl;							
						}
						inrewrite.close();
						outre.close();
						cout<<"\n\n\n\tBill Paid Successfully!\n";
						Sleep(1000);
						system("CLS");
						setGlobalVar();
						menu(ga);
		}
		void transfer(){
			string ibanrec;
			int xd, deposit;
			string ibantrans;
			int flag=0;
			string ib,ibann;
			int withdraw;
			system("CLS");
			cout<<"\t\tTRANSFER AMOUNT"<<endl;
			here7: cout<<"\nEnter IBAN number:  ";
			cin>>ib;
			if(ib==IBAN)
			goto here7;
			ifstream tran("user.txt",ios::in);
			while(!tran.eof()&&tran>>gu>>ibann>>ibann>>ibann>>ibann>>ibann>>ibann>>ibann){
				if(ibann == ib){
					flag=1;
					cout<<"\nAccount Title: "<<gu<<endl;
					break;
				}
				
				}
				if(flag==0) {
					goto here7;
				}
				
				here6: cout<<"Enter amount to be transferred:  ";
					cin>>withdraw;
					
					if(withdraw > balance){
						cout<<"Insufficient funds\n";
						goto here6;
					}
					else 
					{
						orbitfunc(withdraw);
						balance-=withdraw;
						
						ifstream in("user.txt");
						ofstream out("temp.txt");
						
						while(!in.eof()&&in>>gu>>gp>>ga>>gb>>gpin>>dp>>wdraw>>giban){
							if(gu == uname){
								gb -= withdraw;
								wdraw=withdraw;
								ibantrans=giban;
								deposit=dp;
							}
							if(ib==giban){															//ib== jisko paise transfer kar rahe iban
								gb+=withdraw;
								dp=withdraw;
								xd=wdraw;
								ibanrec=ib;
								
							}
							out<<gu<<" "<<gp<<" "<<ga<<" "<<gb<<" "<<gpin<<" "<<dp<<" "<<wdraw<<" "<<giban<<"\n";
						}
						
						
						in.close();
						out.close();
					}
					ofstream Deposit("deposit.txt",ios::app);
					ofstream Withdraw("withdraw.txt",ios::app);
					Deposit<<ibanrec<<" "<<withdraw<<"\n";
					Withdraw<<IBAN<<" "<<withdraw<<"\n";
					ifstream inrewrite("temp.txt");
					ofstream outre("user.txt");
					while(!inrewrite.eof() && getline(inrewrite,x)){
							outre<<x<<endl;							
						}
						
						
				inrewrite.close();
				outre.close();
				Deposit.close();
				Withdraw.close();
					cout<<"\n\n\n\n\n\tAmount Successfully transferred!";
						setGlobalVar();
						DelayToMenu(1000);
		}
		
};
class SavingsAccount:public Account{
	public:
		SavingsAccount(string a, string b, int c, float d, int e,string f) : Account(a,b,c,d,e,f){}
		
		
		void billpay(){
			srand(time(0));
			string temp = "";
			cout<<"Bill Options: "<<endl;
			here20:cout<<"\n1. K-Electric\n2. PTCL\n3. Sui Southern Gas Limited\n4. Karachi Water and Sewarage Board\n5. University fee"<<endl;
			c=getche();
			if(c<1||c>6){
				cout<<"\nInvaild choice";
				Sleep(1000);
				system("CLS");
				goto here20;
			}
			system("CLS");
			ofstream obj2("bills.txt");
    		
    for (int i = 3; i < IBAN.size(); ++i) {
            temp = temp + IBAN[i];
    }
			obj2<< "KE"+temp<<" "<<rand()%9999<<endl<< "PTCL"+temp <<" "<<rand()%9999<<endl<< "SSGL"+temp <<" "<<rand()%9999<<endl<< "KWSB"+temp <<" "<<rand()%9999<<endl<< "21k"+temp <<" "<<rand()%9999<<endl;
	        obj2.close();
	        
	        int xd, p;
			string f;
			int flag=0;
	        string ib;
	        
			here8: cout<<"Enter Bill number:  ";
			cin>>x;
	
				
			ifstream b("bills.txt",ios::in);
			while(!b.eof()){
				b>>f>>a;
				if(f == x){
					flag=1;
					cout<<"Bill amount is: "<<a;
					break;
				}
				
				}
				if(flag==0) {
					goto here8;
				}
				
					if(a > balance){
						cout<<"\nInsufficient funds! Cant pay bill...\n";
						gu=uname;	
						gb=balance;		
						giban=IBAN;	
						ga=atype;
						gp=pword;
						gpin=pin1;
						DelayToMenu(1000);
					}
					else 
					{
						balance-=a;
						
						ifstream in("user.txt");
						ofstream out("temp.txt");
						
						while(!in.eof()&&in>>gu>>gp>>ga>>gb>>gpin>>dp>>wdraw>>giban){
							if(gu == uname){
								gb -= a;
								wdraw=a;
								f=giban;
								p=dp;
							}
							if(ib==giban){
								gb+=a;
								dp=a;
								xd=wdraw;
								
							}
							out<<gu<<" "<<gp<<" "<<ga<<" "<<gb<<" "<<gpin<<" "<<dp<<" "<<wdraw<<" "<<giban<<"\n";
						}
						in.close();
						out.close();
					}
					ofstream Withdraw("withdraw.txt",ios::app);
					Withdraw<<IBAN<<" "<<a<<"\n";
					Withdraw.close();
					ifstream inrewrite("temp.txt");
					ofstream outre("user.txt");
					
					while(!inrewrite.eof()&&getline(inrewrite,x)){
							outre<<x<<endl;							
						}
						inrewrite.close();
						outre.close();
						cout<<"\n\n\n\tBill Paid Successfully!\n";
						DelayToMenu(1000);

		}
		
		void transfer(){
			int times=0;
			string ibant;
			string ibanrec;
			int xd, deposit;
			string ibantrans;
			int flag=0;
			string ib,ibann;
			int withdraw;
			system("CLS");
			ifstream object10("times.txt");
			while(!object10.eof()&&object10>>ibant){
				if(ibant==IBAN){
					times++;
				}
			}
			object10.close();
			if(times<2){
			cout<<"\t\tTRANSFER AMOUNT"<<endl;
			here7: cout<<"Enter IBAN number:  ";
			cin>>ib;
			if(ib==IBAN)
			goto here7;
			ifstream tran("user.txt",ios::in);
			while(!tran.eof()&&tran>>gu>>ibann>>ibann>>ibann>>ibann>>ibann>>ibann>>ibann){
				if(ibann == ib){
					flag=1;
					cout<<"\nAccount Title: "<<gu<<endl;
					break;
				}
				
				}
				if(flag==0) {
					goto here7;
				}
				
				here6: cout<<"\nEnter amount to be transferred:  ";
					cin>>withdraw;
					
					if(withdraw > balance){
						cout<<"\nInsufficient funds\n";
						goto here6;
					}
					else 
					{
						orbitfunc(withdraw);
						balance-=withdraw;
						
						ifstream in("user.txt");
						ofstream out("temp.txt");
						
						while(!in.eof()&&in>>gu>>gp>>ga>>gb>>gpin>>dp>>wdraw>>giban){
							if(gu == uname){
								gb -= withdraw;
								wdraw=withdraw;
								ibantrans=giban;
								deposit=dp;
							}
							if(ib==giban){															//ib== jisko paise transfer kar rahe iban
								gb+=withdraw;
								dp=withdraw;
								xd=wdraw;
								ibanrec=ib;
								
							}
							out<<gu<<" "<<gp<<" "<<ga<<" "<<gb<<" "<<gpin<<" "<<dp<<" "<<wdraw<<" "<<giban<<"\n";
						}
						
						
						in.close();
						out.close();
					}
					ofstream Deposit("deposit.txt",ios::app);
					ofstream Withdraw("withdraw.txt",ios::app);
					Deposit<<ibanrec<<" "<<withdraw<<"\n";
					Withdraw<<IBAN<<" "<<withdraw<<"\n";
					ifstream inrewrite("temp.txt");
					ofstream outre("user.txt");
					while(!inrewrite.eof()&&getline(inrewrite,x)){
							outre<<x<<endl;							
						}
						
						
				inrewrite.close();
				outre.close();
				Deposit.close();
				Withdraw.close();
					cout<<"\n\n\n\n\n\tAmount Successfully transferred!";
					x+=1;
					ofstream object("times.txt",ios::app);
					object<<IBAN<<endl;
					object.close();
						setGlobalVar();	
						DelayToMenu;
	}
		else{
			cout<<"\nYou have reached your daily transfer limit";
		}
	}
};
class RemittanceAccount:public Account{
	public:
		RemittanceAccount(string a, string b, int c, float d, int e,string f) : Account(a,b,c,d,e,f){}
		void billpay(){
		cout<<"\n\n\nThis Feature is Not Available in Remittance Account Type.";
		PressToMenu();
	}
	void transfer(){
			string ibanrec;
			int xd, deposit;
			string ibantrans;
			int flag=0;
			string ib,ibann;
			int withdraw;
			system("CLS");
			cout<<"\t\tTRANSFER AMOUNT"<<endl;
			here7: 
			cout<<"\nEnter IBAN number:  ";
			cin>>ib;
			if(ib==IBAN)
			goto here7;
			ifstream tran("user.txt",ios::in);
			while(!tran.eof()&&tran>>gu>>ibann>>ibann>>ibann>>ibann>>ibann>>ibann>>ibann){
				if(ibann == ib){
					flag=1;
					cout<<"\nAccount Title: "<<gu<<endl;
					break;
				}
				
				}
				tran.close();
				if(flag==0) {
					goto here7;
				}
				
				here6: cout<<"\nEnter amount to be transferred:  ";
					cin>>withdraw;
					
					if(withdraw > balance){
						cout<<"\nInsufficient funds\n";
						goto here6;
					}
					else 
					{
						orbitfunc(withdraw);
						balance-=withdraw;
						
						ifstream in("user.txt");
						ofstream out("temp.txt");
						
						while(!in.eof()&&in>>gu>>gp>>ga>>gb>>gpin>>dp>>wdraw>>giban){
							if(gu == uname){
								gb -= withdraw;
								wdraw=withdraw;
								ibantrans=giban;
								deposit=dp;
							}
							if(ib==giban){															//ib== jisko paise transfer kar rahe iban
								gb+=withdraw;
								dp=withdraw;
								xd=wdraw;
								ibanrec=ib;
								
							}
							out<<gu<<" "<<gp<<" "<<ga<<" "<<gb<<" "<<gpin<<" "<<dp<<" "<<wdraw<<" "<<giban<<"\n";
						}
						
						
						in.close();
						out.close();
					}
					ofstream Deposit("deposit.txt",ios::app);
					ofstream Withdraw("withdraw.txt",ios::app);
					Deposit<<ibanrec<<" "<<withdraw<<"\n";
					Withdraw<<IBAN<<" "<<withdraw<<"\n";
					ifstream inrewrite("temp.txt");
					ofstream outre("user.txt");
					while(!inrewrite.eof()&&getline(inrewrite,x)){
							outre<<x<<endl;							
						}
						
						
				inrewrite.close();
				outre.close();
				Deposit.close();
				Withdraw.close();
					cout<<"\n\n\n\n\n\tAmount Successfully transferred!";
						
						system("CLS");
						setGlobalVar();			
						menu(ga);
		}
};

void DelayToMenu(int x){
	Sleep(x);
	system("CLS");
	menu(ga);
}
void PressToMenu(){
	cout<<"\n\n\n\n\tPress any key to go back to menu...";
		if(getche()){
			system("CLS");
			menu(ga);
		}
}



void menu(int a){
	
	cout<< "\n\t\t\tLoading...\n\n\n";
	Sleep(400);
		
	system("CLS");
	cout<<"\tWelcome "<<gu<<"\t\tbalance: "<<gb<<" PKR\n";
	cout<<"\n1) Account Statement"<<endl;								//all transactions, deposit, withdraw, trasnferred
	cout<<"\n2) Bills and utilities"<<endl;								//k electric, sui gas, ptcl
	cout<<"\n3) Online Transfer"<<endl;									//transaction
	cout<<"\n4) Settings"<<endl;  	
	cout<<"\n5) View Orbits"<<endl;					 				//change pin, show debit/credit card
	cout<<"\n6) Account Details"<<endl;
	cout<<"\n7) Logout"<<endl;
	cout<<"\nPlease Select:  ";
	c=getche();  
	system("CLS");
	if(a==1){
		CurrentAccount obj(gu,gp,ga,gb,gpin,giban);
		
		if(c=='1'){
			obj.accountstatement();
		}
		else if(c=='2'){
			obj.billpay();
		}
		else if(c=='3'){
			obj.transfer();
		}
		else if(c=='4'){
			obj.settings();
		}
		else if(c == '5'){
			obj.orbitswrite();	
		}
		else if(c=='6'){
			obj.Details();
		}
		else if(c=='7'){
			logout=true;
		}
		
	}
	    
	if(a==2){
		SavingsAccount obj(gu,gp,ga,gb,gpin,giban);
		if(c=='1'){
			obj.accountstatement();
		}
		else if(c=='2'){
			obj.billpay();
		}
		else if(c=='3'){
			obj.transfer();
		
		}
		else if(c=='4'){
			obj.settings();
		}
		else if(c == '5'){
			obj.orbitswrite();	
		}
		else if(c=='6'){
			obj.Details();
		}
		else if(c=='7'){
			logout=true;
		}
}
	if(a==3){
		RemittanceAccount obj(gu,gp,ga,gb,gpin,giban);
		
		if(c=='1'){
			obj.accountstatement();
		}
		else if(c=='2'){
			obj.billpay();
		}
		else if(c=='3'){
			obj.transfer();
		
		}
		else if(c == '5'){
			obj.orbitswrite();	
		}
		else if(c=='4'){
			obj.settings();
		}
		else if(c=='6'){
			obj.Details();
		}
		else if(c=='7'){
			logout=true;
		}
}
}
fileopen(){
	ofstream object("user.txt",ios::app);
	if(!object){
		cout<<"File could not be opened"<<endl;
		exit(1);
	}
}

string generateIBAN(){
	string ibn;
	srand(time(0));
	while(ibn.length()<8)
	ibn="ZAH"+to_string(rand()%99999);
	return ibn;
}

void signup(){
	
		cout<< "\n\t\t SIGNUP\n\n\n";
		fflush(stdin);
		 here4: cout<<"Enter username:  ";
		 cin>>username;
		 ifstream write("user.txt");
		 while(!write.eof()){
		 	write>>temp;
			getline(write,x);
			if(username==temp){
		 	cout<<"Username already exists! Try again"<<endl;
		 	goto here4;
		 }
	}
	write.close();
		 fflush(stdin);
		 here25: cout<<"Enter password:  ";
		 getline(cin,password);
		 for(int q=0;q<password.length();q++){
		 	if(password[q]==32){
		 		cout<<"You cannot use space in password!"<<endl;
		 		goto here25;
			 }
		 }
		 

		 cout<<"1. Current Account\n2. Savings Account\n3. Remittance account\n";
		 
		here1: cout<<"\nEnter account type:  ";
		 cin>>acc;
		 if(acc<1 || acc>3)
		 {
		 	cout<<"Invalid choice";
		 	goto here1;
		 }
		 here2:
		 if(acc==3){
		 cout<<"\nPlease deposit initial amount:  ";
		 cin>>amount;
		 }
		 else{
		 	cout<<"\nPlease deposit initial amount (min 2000):  ";
			cin>>amount;
		 }
		 
		 if(acc!=3 && amount<2000)
		 {
		 	cout<<"\nInvalid Amount.Please enter apt amount\n";
		 	goto here2;
		 }
		 dp=amount;
		 wdraw=0;
		 
		 here3: cout<<"\nEnter a 4 digit pin: ";
		 cin>>pin;
		 if(pin<1000||pin>9999){
		 	cout<<"\nInvalid pin!";
		 	goto here3;
		 }
			
			iban = generateIBAN();
		 
		 ofstream w("user.txt",ios::app);
		 while(w){
		 	w<<username<<" "<<password<<" "<<acc<<" "<<amount<<" "<<pin<<" "<<dp<<" "<<wdraw<<" "<<iban<<"\n";break;
		 }
		 system("CLS");
		 cout<<"\n\n\n\t\tSussessfully Signed Up\n";
		 Sleep(500);
		 w.close();
}


int login(){
	char pwo;
	system("CLS");
	cout<< "\n\t\t\tLOGIN\n\n\n";
	int flag=0;
	here5:
		password="";
		cout<<"Enter username:  ";
		cin>>username;
		cout<<"Enter password:  ";
		for(;;){
		pwo=getch();
		 if((pwo>='a'&&pwo<='z')||(pwo>='A'&&pwo<='Z')||(pwo>='0'&&pwo<='9'))
        {
            password+=pwo;
            ++i;
            cout<<"*";
        }
        if(pwo=='\r')
        {
            break;
        }
    }
		ifstream read("user.txt",ios::in);
	if(!read){
	 	cout<<"File could not be opened"<<endl;
	 	exit(1);
	 }
	while(!read.eof()){
	 	read>>gu>>gp>>ga>>gb>>gpin>>dp>>wdraw>>giban;
	 	if(username==gu&&password==gp){
	 	flag=1;
	 	system("CLS");
	 	break;
	 	
		}
	
	 }
	 read.close();
	 if(flag==0){
			cout<<"\n\nInvalid Id or Password!\n\n";
			goto here5;
		}
		
	 cout<<"\n\n\n\t\tLogged In Sussessfully!\n";
	 Sleep(500);
read.close();
return ga;
}


HWND WINAPI GetConsoleWindowNT(void){
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;
    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib
    ,TEXT("GetConsoleWindow"));
    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}

int windowsize(void){
	HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,400,0,500,600,TRUE);

}
	
int main(){
	system("COLOR F0");
	windowsize();
	fileopen();								//is file open g func
	float i_amt;
	welcome: 
	system("CLS");
	cout<<"\n\n\tWelcome to ZAH Netbanking Application \n";
	cout<<"\n\n\t\t1. Sign-up\n\t\t2. Login.\n\t\t3. Close app.\n";
	c=getche();
	system("CLS");
	
	if(c == '1'){
		signup();
		if(logout == 1){
		cout<<"\n\n\n\t\tLogged Out Successfully.";
		Sleep(1000);
	}
	goto welcome;
	}
	else if(c == '2'){
		menu(login());
		if(logout == 1){
		cout<<"\n\n\n\t\tLogged Out Successfully.";
		Sleep(1000);
	}
	goto welcome;
	}
	else if(c == '3'){
		cout<<"\n\n\n\tYou have successfully exited.";
		exit(1);
	}
	
	else {
		system("CLS");
	    cout<<"\n\n\n\t\t\tInvalid choice\n";
		goto welcome;
	}
	
}
