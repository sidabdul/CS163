//
//  HW1.cpp
//  CS163 HW1
//
//  Sid-Ali Abdullahi
//
//

#include "HW1.h"
node::node()
{
    hint = NULL;
    like = 0;
}

node::~node()
{

if (hint)
{

    delete [] hint;
}

}


//Set Up Empty List
College_Life::College_Life()
{
    head_registering = NULL;
    head_materials = NULL;
    head_homework = NULL;
}


//Deallocate Dynamic Memory

College_Life::~College_Life()
{
    
    node * temp0 = head_registering;
    node * temp1 = head_materials;
    node * temp2 = head_homework;
    
    //Registration List Deallocation
    if(!head_registering)
        return;
    
    temp0 = head_registering;
    head_registering = head_registering -> next;
    delete temp0;
    temp0 = NULL;
    
    
    //Materials List Deallocation
    if(!head_materials)
        return;
    
    temp1 = head_materials;
    head_materials = head_materials -> next;
    delete temp1;
    temp1 = NULL;
    
    //Homework List Deallocation
    if(!head_homework)
        return;
    
    temp1 = head_homework;
    head_homework = head_homework -> next;
    delete temp2;
    temp2 = NULL;
    
    
    
}

int College_Life::Add_Hint(/*char category[], char hint[]*/)
{

    
    int category_choice;
    
    cout << " Please Enter A Category Choice  " << '\n' << endl;
    
    cout << " Enter 1 For Registration " << '\n' << endl;
    
    cout << " Enter 2 For Materials " << '\n' << endl;
    
    cout << " Enter 3 For Homework " << '\n' << endl;

    cin >> category_choice;
    cin.ignore(100, '\n');
    
    if(category_choice == 1)
    {
    
        node * temp = new node;
        node * current = head_registering;
        
        char temparray[100];
        
        cout << " You Have Selected Option 1, Please Type Any Hints, Regarding Registration " << '\n' << endl;
        
        
        cin.get(temparray, 100, '\n');
        cin.ignore(100, '\n');
        temp -> hint = new char[strlen(temparray) + 1];
        strcpy(temp->hint,temparray);
        
        if (!head_registering)
        {
            head_registering = temp;
            temp -> next = NULL;
            cout << "This is the hint inserted : "<< " " << temp->hint << endl;
            return 1;
        }
        
        while(current->next)
        {
            current=current->next;
        }
              current -> next = temp;
              temp-> next =NULL;
        return 1;
        
    }
    
    
    
    
    
    if(category_choice == 2)
    {
        
        node * temp = new node;
        node * current = head_materials;
        
        char temparray[100];
        
        cout << " You Have Selected Option 2, Please Type Any Hints, Regarding Materials " << '\n' << endl;
        
        
        cin.get(temparray, 100, '\n');
        cin.ignore(100, '\n');
        temp -> hint = new char[strlen(temparray) + 1];
        strcpy(temp->hint,temparray);
        
        if (!head_materials)
        {
            
            head_materials = temp;
            temp -> next = NULL;
            cout << "This is the hint inserted : " <<temp->hint << endl;
            
            return 2;
        
        }
        
        while(current->next)
        {
            current=current->next;
        }
        current -> next = temp;
        temp->next =NULL;
        return 2;
        
    }

    
    
    
    if(category_choice == 3)
    {
        
        node * temp = new node;
        node * current = head_homework;
        
        char temparray[100];
        
        cout << " You Have Selected Option 3, Please Type Any Hints, Regarding Homework " << '\n' << endl;
        
        
        cin.get(temparray, 100, '\n');
        cin.ignore(100, '\n');
        temp -> hint = new char[strlen(temparray) + 1];
        strcpy(temp->hint,temparray);
        
        if (!head_homework)
        {
            head_homework = temp;
            temp -> next = NULL;
            cout << "This is the hint inserted : " <<temp->hint << endl;
            
            return 3;
        }
        
        while(current->next)
        {
            current=current->next;
        }
        current -> next = temp;
        temp->next =NULL;
        return 3; // return that category
        
    }

 
    
    return 0;
}



int College_Life::Like(/*char category[], char hint[]*/) //you may alter these arguments
{
    char hintlike;
    node * current = head_registering;
    node * temp;
    node * prev = current;
  
    if(!current)
    {
        return 0;
    
    }
    
    
    
    
       cout << current->hint << endl;

    
       cout << " Like This Hint? Y or N";
       cin >> hintlike;
       cin.ignore(100, '\n');
    
    
       if(hintlike == 'Y')
       {
           current->like = current->like + 1;
           temp = current;
           current = head_registering;
           
           while (temp->like < current->like) // this is for sorting th data once it is liked
           {
               prev = current;
               current = current ->next;
               
           }
           
           temp->next = current;
           prev->next = temp;
           
           
           return 1;
           
           
       }
    
       if (hintlike == 'N')
       {
           prev = current;
           current = current->next;
    
       }
    
    

    return 1;
}








int College_Life::Display_All()//display all
{
    int save;
    
    cout << " Choose a list to display " <<endl;
    cout << " 1 for registration list"<<endl;
    cout << " 2 for materials list"<<endl;;
    cout << " 3 for homework list"<<endl;;


    
    
    cin >> save;
    cin.ignore(100, '\n');
    
    
    if (save == 1)
    {
        node * current = head_registering;
        
        
       while(current)
       {
        
           cout << " THIS IS THE LIST FOR Registering" << " -> -> " << current->hint <<endl;
           current = current->next;
       }
        return 1;
    }
    
    if (save == 2)
    {
        node * current = head_materials;
        while(current)
        {
            
            cout << " THIS IS THE LIST FOR Materials" << " -> -> " << current->hint <<endl;
            current = current->next;
        }
    }
    
    if (save == 3)
    {
        node * current = head_homework;
        while(current)
        {
            
            cout << " THIS IS THE LIST FOR HOMEWORK" <<  " -> -> " << current->hint <<endl;
            current = current->next;
        }
    }
    
    return 1;
}

int College_Life::Display(/*char category[]*/) //display all for a particular category
{
    return 1;
}