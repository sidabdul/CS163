//
//  HW1.h
//  CS163 HW1
//
//  Created by Sid-Ali Isgow on 10/16/14.
//
//

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;


struct node
{
    node();
    ~node();
    char * hint;
    int like;
    node * next;


};


class College_Life

{

public:
    College_Life();
    ~College_Life ();
    int Add_Hint(/*char category[], char hint[]*/);
    int Like(/*char category[], char hint[]*/); //you may alter these arguments
    int Display_All(); //display all
    int Display(/*char category[]*/); //display all for a particular category
private:
    node * head_registering; //these will be replaced for the extra credit
    node * head_materials;
    node * head_homework;
};

