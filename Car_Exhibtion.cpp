#include <iostream>
using namespace std;
class node
{
 public:
 int Quantity;
 int Price;
 string Car_Model;
 node* next;
};
node* head=NULL;
string Car_Type;
void Add_Car(string Type,int Number,int price){
	node* new_node;
	node* last;
	new_node = new node;
	new_node -> Quantity=Number;
	new_node -> Car_Model=Type;
	new_node -> Price=price;
	if(head==NULL){
		head= new_node;
		new_node -> next = NULL;
	}
	else{
		last=head;
		while( last -> next !=NULL){
			last= last ->next;
		}
		last -> next =new_node;
		new_node ->next= NULL;
		}
}
int v=0;
string Search_Cars(node* n){
 
 cout<<"Enter Your Model: ";
 cin>>Car_Type;
 while (n != NULL) {
 if(Car_Type==n->Car_Model){
 	cout<<"Price of  "<< n->Car_Model<<" is: "<< n -> Price<<", Available: "<< n->Quantity<<"\n";
 	v=0;
 	return Car_Type;
 }
 else{n = n->next;}

	
} cout<<"Sorry, This Model is Not Available Right Now"<<"\n";
v=1;
}

bool search(node* head, string type)
	{
		node* current = head;
		 while (current != NULL)
		{
		 if (current->Car_Model == type){
		 return true;}
		 
		 current = current->next;
		 }
		 return false;
	}

int sell(string model)
{	
	node*ptr=head;
	
	if (search(head, model) == false)
	{cout<<"Sorry, progress Failed!"<<endl;}
	else if(search(head, model) == true)
	{
		while(ptr != NULL)
		{
			
			if (ptr->Car_Model == model)
			{
			 	cout<<"Progress Done"<<endl;
			 	ptr->Quantity=ptr->Quantity-1;
			 	return ptr->Quantity;}
			 	
			 ptr = ptr->next;
			}
		}
	
	}

void del_Car(node* head){
 node* current = head;
 node* prev = head;
 string key;
 cout<<"\nEnter Your Model: ";
 cin>>key;

 
 if (current != NULL && current->Car_Model == key)			//2
 {
 	head = current->next; 
 	delete current; 
 	return;
 }
 else 
 {
	 while (current != NULL && current->Car_Model != key) {
	 prev = current;	// >2
	 current = current->next;
	 }
	 
	 	if ( current == NULL)					//1
	 	return;
	 
	 prev->next = current->next;
	 
	 delete current;
	 }
}
void Our_Cars(node* n){
 while (n != NULL) {
 cout <<"Available Quantity of "<< n->Car_Model << " --> "<< n ->Quantity << ", Price: "<< n -> Price<<"\n";
 n = n->next;
 }
 
}

void update(node* head){
 	 Search_Cars(head);
 	 if (v==1){
 	 	return;
	  }
	 else{
	 cout<<"Update price or Quantity or both ?"<<"\n";
	 string ans;
	 int new_price;
	 int new_quantity;
	 cin>>ans;
	 if (ans=="price" || ans=="Price" || ans=="PRICE")
	    {cout<<"insert the new price : "<<"\n";
		cin>>new_price;
		head->Price=new_price;}
	 else if (ans=="Quantity" || ans=="quantity" || ans=="QUANTITY")
		{cout<<"insert new quantity :"<<"\n";
		cin>>new_quantity;
		head->Quantity=new_quantity;}
	 else if (ans=="both" || ans=="Both" || ans=="BOTH")
		{cout<<"firstly,insert the new price : "<<"\n";
		cin>>new_price;
		head->Price=new_price;
		cout<<"Secondly,insert new quantity :"<<"\n";
		cin>>new_quantity;
		head->Quantity=new_quantity;
		}
		else{cout<<"Invalid input..!";}
	}
	 cout<<"New Data Announcement , \nCar Type :"<< Car_Type<<" \nwith price : "<<head->Price<<" \nQuantity : "<<head->Quantity<<"\n";
}
		
int main()
{
 
 Add_Car("BMW",6,2200000);
 Add_Car("KIA",33,800000);
 Add_Car("Audi",16,1400000);
 Add_Car("Bentley",4,8000000);
 Add_Car("Jeep",13,1600000);
 Add_Car("Tesla",2,4500000);
 Add_Car("Mercedes",9,2100000);
 Add_Car("Toyota",22,600000);
	


	string Uinput;
	cout<<"Welcome...\n---\n";

	string type,password;
int temp =0;
while(true){

	switch(temp){
	case 0:
		cout<<"Are you User or Admin: ";
		cin>>type;
	
		if (type=="Admin" || type=="admin" || type=="ADMIN"){
			cout<<"ONLY CUSTOMERS!!!!!!\n";
	    	cout<<"Enter Password: ";
	    	cin>>password;
	 		if(password !="12345"){
	 			cout<<"Wrong Password Please Try again...\n";temp=0;}
	 	else{
		 temp=1;}
		break ;
 }
		else if(type=="User"||type=="user" || type=="USER")
		{temp=2;
		 break;
		}
		else{temp=0;
		break;
		}
	case 1:
		
		cout<<"You can choose service from(insert, delete, update, exit):\n";
		cin>>Uinput;	
	
	  	if (Uinput=="delete" || Uinput=="Delete" || Uinput=="DELETE")
	  	{del_Car(head);}
	
	  	else if (Uinput=="update" || Uinput=="Update" || Uinput=="UPDATE")
		  { update(head);}
	
        else if(Uinput=="insert" || Uinput=="Insert" || Uinput=="INSERT"){
            int p,q;string t;
			cout<<"Enter Car Type: ";
			cin>>t;
			cout<<"Enter quantity: ";
			cin>>q;
			cout<<"Enter Price: ";
			cin>>p;
			Add_Car(t,q,p);
			cout<<"Progress Done";
		}	
	 	else if(Uinput=="exit" || Uinput=="Exit" || Uinput=="EXIT")
			temp =0;
		else{cout<<"Erorr\n";}
		break;
		
	case 2:
		cout<<"You can choose service from(search, buy, show, exit):\n";
		cin>>Uinput;	
		if (Uinput=="search" || Uinput=="Search" || Uinput=="SEARCH")
			{Search_Cars(head);}
  	
		else if (Uinput=="buy" || Uinput=="Buy" || Uinput=="BUY")
		{
		string input;
		cout<<"Which Car:";
		cin>>input;
		sell(input);
		}
		else if (Uinput=="show" || Uinput=="SHOW" || Uinput=="Show")
		{Our_Cars(head);}
	  	
	  	else if (Uinput=="exit" || Uinput=="Exit" || Uinput=="EXIT"){temp=0;}
	  	else{cout<<"Erorr\n";}
	  	break;
	}
}
}
