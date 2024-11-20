#include<iostream>
#include<iomanip>
#include<string.h>
#include<malloc.h>
#include<unistd.h>
using namespace std;
void insert(string,float,int);
void display();
void order();
void display_rd_hist();
class hotel
{
        private:
                struct node
                {
                        int id;
                        int date;
                        string name,type;
                        node*next;
                };
        public:
                node*head=NULL;
                void insert();
                void update();
                void menu();
                void search();
                void del();
                void sort();
                void show();
};
struct item
{
        string name;
        float rating;
        float price;
        int food_id_no;
        struct item*next;
        struct item*prev;
};
int cust_id=1;
struct item*head;
struct item*last;
int today_customer=0;
float total_income=0;

struct order_hist
{
        int customer_id;
        int items[10][2];
        float amount;
        char date[11];
        struct order_hist*next;
        struct order_hist*prev;
};
struct order_hist*head1;
struct order_hist*last1;
struct item*getnewnode(string a,float p,int fin)
{
        struct item*temp=new item;
        temp->food_id_no=fin;
        temp->name=a;
        temp->rating=4.0;
        temp->price=p;
        temp->next=NULL;
        temp->prev=NULL;
        return temp;
};
struct order_hist*getnewnode_hist()
{
        struct order_hist*temp=new order_hist;
        temp->next=temp->prev=NULL;
        return(temp);
};
int main()
{
        hotel h;
        int final;
        cout<<"\033[34m=================================================================================================\n";
        cout<<"                                        WELCOME                                          \n";
        cout<<"\033[34m=================================================================================================\n\033[0m";
        cout<<"\n\n\t\tEnter 1 to enter into the ROOM MANAGEMENT  "<<endl;
        cout<<"\n\n\t\tEnter 2 to enter into the FOOD MANAGEMENT  "<<endl;
        cout<<"\n\n\t\tEnter your choice:  ";
        cin>>final;
        switch(final)
        {
                case 1:
                        h.menu();
                        break;
                case 2:
                        head=NULL;
                        last=NULL;
                        insert("Burger            ",70.30,1);
                        insert("Pizza             ",230.50,2);
                        insert("Hot Coffee        ",50,3);
                        insert("Ice Cream         ",70.12,4);
                        insert("Sandwich          ",60.23,5);
                        insert("Bread             ",35.55,6);
                        insert("Cold Drinks       ",20.13,7);
                        insert("Fries             ",150,8);
                        int choice;
                        do
                        {
                                cout<<"\n\t\t\033[31m------------------------------------------------------------\033[0m";
                                cout<<"\n\t\t\033[32m-----------------------WELCOME------------------------------\033[0m";
                                cout<<"\n\t\t\033[31m------------------------------------------------------------\033[0m";
                                cout<<endl;
                                cout<<"\033[33m\n\t\t1............FOOD PART\033[0m";
                                cout<<"\033[33m\n\t\t2............ADMIN PANEL\033[0m";
                                cout<<"\033[33m\n\t\t3............EXIT\033[0m\n";
                                cout<<"\n\t\tEnter your choice:   ";
                                cin>>choice;

                                cout<<endl;
                                switch(choice)
                                {
                                        case 1:
                                        int ex;
                                         do
                                        {
                                                        						cout<<"\033[35m------------------------------------------------------------------------\033[0m"<<endl;
                                                        cout<<"\033[36m1.          FOOD LIST\n\033[0m\033[36m2.          ORDER\n\033[0m";
                                                        			cout<<"\033[35m------------------------------------------------------------------------\033[0m"<<endl;
                                                        int t;
                                                        cout<<"Enter the choice:  ";
                                                        cin>>t;
                                                        cout<<endl;
                                                        switch(t)
                                                        {
                                                                case 1:
                                                                                display();
                                                                                break;
                                                                case 2:
                                                                                order();
                                                                                break;
                                                        }
                                                        cout<<"1.FOOD PART\n2.MAIN MENU\n";
                                                        cin>>ex;
                                        }while(ex==1);
                                        break;
                                        case 2:
                                                cout<<"\n";
                                                cout<<"\n";
                                                int ch;
                                                do
                                                        {
                                                                			cout<<"\033[33m------------------------------------------------------------------------------------"<<endl;
                                                                cout<<"\033[34m1.                       ADD NEW DISH"<<endl;
                                                                cout<<"\033[34m2.                       TODAY'S TOTAL INCOME"<<endl;
                                                                cout<<"\033[34m3.                       TODAY'S TOTAL NUMBER OF CUSTOMERS"<<endl;
                                                                cout<<"\033[34m4.                       ORDER HISTORY"<<endl;
                                                                cout<<"\033[34m5.                       LIST OF ITEMS"<<endl;
                                                                cout<<"\033[34m6.                        Exit"<<endl;
                                                                		cout<<"\033[33m------------------------------------------------------------------------------------\n\033[0m";
                                                                cout<<"Enter your choice:  "<<endl;
                                                                cin>>ch;
                                                                switch(ch)
                                                                {
                                                                        case 1:
                                                                                        cout<<"  "<<endl;
                                                                                        float p;
                                                                                        int fin;
                                                                                        char n[50];
                                                                                        cout<<"Enter the name of the Item:  "<<endl;
                                                                                        cin>>n;
                                                                                        cout<<"Enter the Price of the Item:   "<<endl;
                                                                                        cin>>p;
                                                                                        cout<<"Enter thr food ID number of item:   "<<endl;
                                                                                        cin>>fin;
                                                                                        insert(n,p,fin);
                                                                                        cout<<"---------------------------------------------------------------------\n";
                                                                                        cout<<"                      NEW DISH ADDED SUCCESSFULLY.........\n";
                                                                                        cout<<"---------------------------------------------------------------------\n";
                                                                                        cout<<endl;
                                                                                        break;
                                                                        case 2:
                                                                                        cout<<"---------------------------------------------------------------------\n";
                                                                                        cout<<"                 TODAY'S TOTAL INCOME IS:         "<<total_income<<endl;
                                                                                        cout<<"---------------------------------------------------------------------\n";
                                                                                        break;
                                                                        case 3:
                                                                                        cout<<"---------------------------------------------------------------------\n";
                                                                                        cout<<"               TODAY TOTAL NUMBER OF CUSTOMERS VISITED:        "<<today_customer<<endl;
                                                                                        cout<<"---------------------------------------------------------------------\n";
                                                                                        break;
                                                                        case 4:
                                                                                        cout<<"---------------------------------------------------------------------\n";
                                                                                        cout<<"                               ORDER SUMMARY                  "<<endl;
                                                                                        cout<<"---------------------------------------------------------------------\n";
                                                                                        display_rd_hist();
                                                                                        cout<<endl;
                                                                                        break;
                                                                        case 5:
                                                                                        cout<<endl;
                                                                                        display();
                                                                                        break;
                                                                        case 6:
                                                                                        int ex;
                                                                                        do
                                                                                        {
                                                                                        cout<<"\033[35m------------------------------------------------------------------------\033[0m"<<endl;
                                                                                        cout<<"\033[36m1.          FOOD LIST\n\033[0m\033[36m2.          ORDER\n\033[0m";
                                                                                        cout<<"\033[35m------------------------------------------------------------------------\033[0m"<<endl;
                                                                                        int t;
                                                                                        cout<<"Enter the choice:  ";
                                                                                        cin>>t;
                                                                                        cout<<endl;
                                                                                        switch(t)
                                                                                        {
                                                                                        case 1:
                                                                                                display();
                                                                                                break;
                                                                                        case 2:
                                                                                        order();
                                                                                        break;
                                                                                        }
                                                                                        cout<<"1.FOOD PART\n2.MAIN MENU\n";
                                                                                        cin>>ex;
                                                                                        }while(ex==1);

                                                                }

                                                        }while(ch);
                                }
                        }while(choice==1);

        }while(final==1);

}
void order()
{
        int a[10][3];
        int j=0,i=0,n;
        char v;
        do
        {
                cout<<"How many items you are sure to order?:  ";
                cin>>n;
                cout<<"Please enter the FOOD ID NUMBER OF ITEM AND ITS QUANTITY:  ";
                for(i=0;i<n;i++)
                {
                        for(j=0;j<2;j++)
                        {
                                cin>>a[i][j];
                        }
                }

                cout<<"Do you want any more item y/n:  ";
                cin>>v;
        }while(v=='y');

        float total_amount=0.0;
        char Name[25];
        char Date[10];
        cout<<"Enter your name:    ";
        cin>>Name;
        cout<<"Enter today's date:   ";
        cin>>Date;
        int k=0;
        cout<<"\n\033[31m--------------------------------------------------------------------\n";
        cout<<"\033[32m                          BILL                          ";
        cout<<"\n\033[31m--------------------------------------------------------------------\n\033[0m";
        cout<<"Name:  "<<Name;
        cout<<endl;
        cout<<"Date:  "<<Date;
        cout<<endl;
        for(k=0;k<n;k++)
        {
                struct item *temp=head;
                while(temp->food_id_no != a[k][0])
                {
                        temp=temp->next;
                }
                cout<<"---------------------------------------------------------------\n";
                float t=a[k][1]*temp->price;
                cout<<temp->food_id_no<<" "<<temp->name<< " "<<a[k][1]<<" "<<t<<endl;
                total_amount+=(a[k][1]*(temp->price));
        }
        cout<<"-----------------------------------------------------------\n";
        cout<<"\nTotal Payable Amount is :  \t\t"<<total_amount<<endl;
        cout<<"-----------------------------------------------------------\n";
        struct order_hist*temp2=getnewnode_hist();
        temp2->amount=total_amount;
        temp2->customer_id=cust_id++;
        int p,s;
        for(p=0;p<j;p++)
        {
                for(s=0;s<2;s++)
                {
                        temp2->items[p][s]=a[p][s];
                }
        }

        if(head1==NULL)
        {
                head1=last1=temp2;
        }
        else
        {
                last1->next=temp2;
                temp2->prev=last1;
                last1=temp2;
        }
        strcpy(temp2->date,Date);
        today_customer++;
        total_income+=total_amount;
}
void display_rd_hist()
{
        cout<<"                          ---------------------------------------                            \n";
        cout<<"-------------------------------------------ORDER HISTORY-----------------------------------------------\n";
        cout<<"                          ---------------------------------------                            \n";
        cout<<"NO                DATE                 TOTAL AMOUNT\n";
        struct order_hist*temp=head1;//
        if(head1==NULL)
        {
                cout<<"Linked list is empty\n";
        }
        while(temp!=NULL)
        {
                cout<<temp->customer_id<<"\t\t\t"<<temp->date<<"\t\t\t"<<temp->amount<<endl;
                temp=temp->next;
        }
}
void insert(string n,float p,int fin)
{
        struct item*temp1=getnewnode(n,p,fin);
        if(head==NULL)
        {
                head=temp1;
                last=temp1;
        }
        else
        {
                temp1->prev=last;
                last->next=temp1;
                last=temp1;
        }

}
void display()
{
        cout<<"\033[32m                                       --------------------                                     \n";
        cout<<"\033[31m-----------------------------------------------MENU----------------------------------------------\n";
        cout<<"\033[32m                                       --------------------                                      \n\033[0m";
        cout<<endl;
        cout<<"\033[34m-------------------------------------------------------------------------------------------------\n\033[0m";
        cout<<"\033[36mINDEX          ITEM NAME         PRICE         RATINGS\n\033[0m";
        cout<<"\033[34m-------------------------------------------------------------------------------------------------\n\033[0m";
        struct item*temp=head;
        if(head==NULL)
        {
                cout<<"The linked list is empty"<<endl;
        }
        while(temp!=NULL)
        {
                cout<<temp->food_id_no<<"\t\t"<<temp->name<<temp->price<<"\t\t"<<temp->rating<<endl;
                temp=temp->next;
        }
        cout<<"--------------------------------------------------------------------------------------------------"<<endl;
}
void hotel::menu()
{
         int choice;
         char ch;
         do
         {
                cout<<"\n\n\n\t\t\t\033[35m_____________HOTEL  MANAGEMENT  SYSTEM_____________\033[0m"<<endl;
                sleep(1);
                cout<<"\033[32m\n\t\t1\t\t\tAllocate Room\t\t\tInsert new room\033[0m"<<endl;
                sleep(1);
                cout<<"\033[32m\n\t\t2\t\t\tSearch for room\t\t\tSearch room with room ID\033[0m"<<endl;
                sleep(1);
                cout<<"\033[32m\n\t\t3\t\t\tUpdate room\t\t\tUpdate room record\033[0m"<<endl;
                sleep(1);
                cout<<"\033[32m\n\t\t4\t\t\tDelete room\t\t\tDelete room with room ID\033[0m"<<endl;
                sleep(1);
                cout<<"\033[32m\n\t\t5\t\t\tShow room records\t\tShow room records the is needed\033[0m"<<endl;
                sleep(1);
                cout<<"\033[32m\n\t\t6\t\t\tExit\t\t\t\tEnter n to exit\033[0m"<<endl;
                sleep(1);
                cout<<endl;
                cout<<"Enter your choice"<<endl;
                cin>>choice;
                switch(choice)
                {
                        case 1:
                                insert();
                                break;
                        case 2:
                                search();
                                break;
                        case 3:
                                update();
                                break;

                        case 4:
                                del();
                                break;
                        case 5:
                                sort();
                                show();
                                break;
                        default:
                                cout<<"Invalid"<<endl;
                                break;
                }
                cout<<"Do you wanna continue?? "<<endl;
                cin>>ch;

        }
        while(ch=='y');
}


void hotel::insert()
{
        cout<<"\033[34m\n\t__________HOTEL MANAGEMENT SYSTEM____________\033[0m"<<endl;
        node*new_node=new node;
        do
        {
                cout<<"\nEnter the room ID:  "<<endl;
                cin>>new_node->id;
        }while(!(new_node->id>=1));
        cout<<"\nEnter the customer name:  "<<endl;
        cin>>new_node->name;
        cout<<"\nEnter the allocated date:  "<<endl;
        cin>>new_node->date;
        cout<<"\nEnter the room type (single (or) double (or) twin):  "<<endl;
        cin>>new_node->type;
        if(head==NULL)
        {
                head=new_node;
        }
        else
        {
                node*ptr=head;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=new_node;
        }
        cout<<"\033[33m\n\n\t\t The New room is successfully inserted!\033[0m"<<endl;
        cout<<endl;
        cout<<endl;
}
void hotel::search()
{
        cout<<"\033[34m\n\t__________HOTEL MANAGEMENT SYSTEM____________\033[0m"<<endl;
        int t_id;
        node*ptr=head;

        if(head==NULL)
        {
                cout<<"\n\nLinked list is empty"<<endl;
        }
        else
        {
                cout<<"\nEnter the room ID:  ";
                cin>>t_id;
                node*ptr=head;
                while(ptr!=NULL)
                {
                        if(t_id==ptr->id)
                        {
                                cout<<"\n\nRoom ID:  "<<ptr->id;
                                cout<<"\n\nCustomer Name:  "<<ptr->name;
                                cout<<"\n\nRoom Allocated Date:  "<<ptr->date;
                                cout<<"\n\nRoom Type:  "<<ptr->type<<endl;
                        }
                ptr=ptr->next;
                }
        }
}
void hotel::update()
{
        cout<<"\033[34m\n\t__________HOTEL MANAGEMENT SYSTEM____________\033[0m"<<endl;
        int t_id;
        node*ptr=head;
        if(head==NULL)
        {
                cout<<"\n\nLinked list is empty"<<endl;
        }
        else
        {
                cout<<"\nEnter the room ID:  ";
                cin>>t_id;
                node*ptr=head;
                while(ptr!=NULL)
                {
                        if(t_id==ptr->id)
                        {
                                cout<<"\n\nRoom ID: "<<endl;
                                cin>>ptr->id;
                                cout<<"\n\nCustomer Name: "<<endl;
                                cin>>ptr->name;
                                cout<<"\n\nAllocated Date: "<<endl;
                                cin>>ptr->date;
                                cout<<"\n\nRoom Type: "<<endl;
                                cin>>ptr->type;
                                cout<<"\033[33m\n\n\t\tUpdated successfully!\033[0m"<<endl;
                        }
                        ptr=ptr->next;
                }
        }
}
void hotel::del()
{
        cout<<"\033[34m\n\t__________HOTEL MANAGEMENT SYSTEM____________\033[0m"<<endl;
        int t_id;
        if(head==NULL)
        {
                cout<<"\n\nLinked list is empty"<<endl;
        }
        else
        {
                cout<<"Enter the room ID:  ";
                cin>>t_id;
                if(t_id==head->id)
                {
                        node*ptr=head;
                        head=head->next;
                        delete ptr;
                        cout<<"\033[33m\n\t\tDeleted room record successfully\n\033[0m"<<endl;
                }
                else
                {
                        node*pre=head;
                        node*ptr=head;
                        while(ptr!=NULL)
                        {
                                if(t_id==ptr->id)
                                {
                                        pre->next=ptr->next;
                                        delete ptr;
                                        cout<<"\033[33mDeleted room record successfully\n\033[0m"<<endl;
                                        break;
                                }
                                pre=ptr;
                                ptr=ptr->next;
                        }
                }
        }
}
void hotel::show()
{
        node*ptr=head;
        while(ptr!=NULL)
        {
                cout<<"\033[34m\n\t__________HOTEL MANAGEMENT SYSTEM____________\033[0m"<<endl;
                cout<<"\n\nRoomID:  "<<ptr->id;
                cout<<"\n\nCustomer Name:  "<<ptr->name;
                cout<<"\n\nAllocated Date:  "<<ptr->date;
                cout<<"\n\nRoom Type:  "<<ptr->type<<endl;
                ptr=ptr->next;
        }
}
void hotel::sort()
{
        if(head==NULL)
        {
                cout<<"\n\nLinked list is empty"<<endl;
                menu();
        }
        int count=0;
        int t_date,t_id;
        string t_name,t_type;
        node*ptr=head;
        while(ptr!=NULL)
        {
                count++;
                ptr=ptr->next;
        }
        for(int i=1;i<=count;i++)
        {
                node*ptr=head;
                for(int j=1;j<count;j++)
                {
                        if(ptr->id > ptr->next->id)
                        {
                                t_id=ptr->id;
                                t_name=ptr->name;
                                t_date=ptr->date;
                                t_type=ptr->type;
                                //save date into current node
                                ptr->id=ptr->next->id;
                                ptr->name=ptr->next->name;
                                ptr->date=ptr->next->date;
                                ptr->type=ptr->next->type;
                                //save data into next node
                                ptr->next->id=t_id;
                                ptr->next->name=t_name;
                                ptr->next->date=t_date;
                                ptr->next->type=t_type;
                        }
                        ptr=ptr->next;
                }
        }
}




