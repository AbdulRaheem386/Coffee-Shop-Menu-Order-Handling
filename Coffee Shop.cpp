#include<iostream>
using namespace std;
class Menuitem{
	private:
		string name;
		double price;
		string type;
		
		public:
			Menuitem(string n ="" , double p = 0.0 , string t = "") : name(n) , price(p) , type(t){
			}
			
			string getname() const{
			return name;
			}
			
			double getprice() const{
			return price;
			}
			
			string gettype() const{
			return type;
			}
		};

class Coffeeshop : public Menuitem{
	private:
		string shopname;
		public:
			Menuitem menu[15];
			string orders[10];
			int ordercount;
			int menusize;
			
			Coffeeshop(string sn , Menuitem items[] , int ordersize) : shopname(sn) , ordercount(0) , menusize(ordersize){
				for ( int i =0 ; i < 15 && i < ordersize ; i++){
					menu[i] = items[i];
				}
			}
				
				string addorder(string orderitemname){
					for ( int i = 0 ; i < menusize ; i++ ){
						if ( menu[i].getname() == orderitemname){
							if ( ordercount < 10){
								orders[ordercount++] = orderitemname;
								return "order added!";
							}
							return "Order list is full!";
						}
					}
					return " This item is not currently Available!";
					
				}
				
				string fullfill(){
					if ( ordercount > 0 ){
						string item = orders[0];
					for ( int i=0 ; i < ordercount -1 ; i++){
						orders[i] = orders[i + 1];
					}
					ordercount--;
					return "This " + item + " is ready";
					}
					return "All orders have been fullfilled!";
					
				}
				
				void listorders(){
					cout<<"Order List"<<endl;
					for ( int i = 0 ; i < ordercount ; i++){
						cout<<i+1<<" . "<<orders[i]<<endl;
					}
				}
				
				double dueamount(){
					double total=0.0;
					for ( int i=0 ; i < ordercount ; i++){
						for ( int j=0 ; j < menusize ; j++){
							if ( menu[j].getname() == orders[i]){
								total += menu[j].getprice();
							break;
							}
						}
					}
					return total;
				}
				
				string cheapestitem(){
					if ( menusize==0){
						return "No item you Order!";
					}
					int cheapestindex = 0;
					for (int i=1 ; i< menusize ; i++){
						if ( menu[i].getprice() < menu[cheapestindex].getprice()){
							cheapestindex =i;
						}
					}
					return menu[cheapestindex].getname();
				}
				
				void Teaonly(){
					cout<<"Tea"<<endl;
					for (int i=0 ; i < menusize ; i++){
						if ( menu[i].gettype() == "Tea"){
							cout<<"- "<<menu[i].getname()<<endl;
						}
					}
				}
				
				void Snacksonly(){
					cout<<"Snacks"<<endl;
					for ( int i=0 ; i < menusize ; i++){
						if (menu[i].gettype() == "Snacks"){
							cout<<"- "<<menu[i].getname()<<endl;
						}
					}
				}
			
			void Coffeeonly(){
					cout<<"Coffee"<<endl;
					for ( int i=0 ; i < menusize ; i++){
						if (menu[i].gettype() == "Coffee"){
							cout<<"- "<<menu[i].getname()<<endl;
						}
					}
				}
				
			void showbyCategory(const string& category) {
                   cout << category << " Menu:" << endl;
                for (int i = 0; i < menusize; i++) {
                string type = menu[i].gettype();
                if (type == category) { 
                    cout << ". " << menu[i].getname() << " (Rs. " << menu[i].getprice() << ")" << endl;
        }
    }
}
			
			
};

int main(){
	Menuitem menu[] = {
	Menuitem("Chai", 100.0,"Tea"),
	Menuitem("GreenTea", 150.0,"Tea"),
	Menuitem("kahwa", 120.0,"Tea"),
	Menuitem("HoneyTea", 250.0,"Tea"),
	Menuitem("ChocolateTea", 300.0,"Tea"),
	Menuitem("Sandwich", 200.0,"Snacks"),
	Menuitem("Fries", 150.0,"Snacks"),
	Menuitem("Frenchfries", 200.0,"Snacks"),
	Menuitem("Platter", 500.0,"Snacks"),
	Menuitem("Burger", 250.0,"Snacks"),
	Menuitem("Blackcoffee", 200.0,"Coffee"),
	Menuitem("Capachino", 250.0,"Coffee"),
	Menuitem("Machinato", 300.0,"Coffee"),
	Menuitem("VanillaLatte", 350.0,"Coffee"),
	Menuitem("coffeeMilk", 150.0,"Coffee"),
	};
	 
	 int shopmenu = sizeof(menu)/sizeof(menu[0]);
	 
	 Coffeeshop cs("Coffee house",menu,shopmenu);
	 cout<<"---WELCOME TO COFFEE HOUSE---"<<endl;
	 
	 cs.showbyCategory("Tea");
	 cs.showbyCategory("Snacks");
	 cs.showbyCategory("Coffee");
	 
	 
	 string item;
	 cout<<"\nEnter up to 10 orders (Type 'done' to finish: "<<endl;
	 while(true){
	 	cout<<"Enter item: ";
	 	cin>>item;
	 	if(item == "done") break;
	 	cout<<cs.addorder(item)<<endl;
	 }
	 
	  cout << "\nOrder List:\n";
    cs.listorders();

    cout << "\nTotal Due Amount: Rs. " << cs.dueamount() << endl;

    cout << "\nFulfilling orders..." << endl;
    while (cs.dueamount() > 0) {
        cout << cs.fullfill() << endl;
    }

    cout << "\nCheapest Item: " << cs.cheapestitem() << endl;

	 return 0;
	 
	 
}
