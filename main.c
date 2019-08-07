//  Exam Grader Program
//  Created by Milan Patel on 4/3/18.
//  Copyright © 2018 Milan Patel. All rights reserved.
//

#include <stdio.h>

void fgetAnswers(char answers[], int n, FILE*inp);  //Declare function fgetAnswers

int main()
{
    FILE *inp;   //open the input file
    inp = fopen("examdat.txt", "r");
    int n, i;                   //declaring variables
    char ch;       //declaring variables
   
    fscanf(inp,"%d",&n);        //scan number of questions
    fscanf(inp,"%c",&ch);
    char answers[n];
    
    for(i=0;i<n;i++)                  //scanning for answers loop, input answers into array
    {
    fscanf(inp,"%c",&answers[i]);
    }
        fgetAnswers(answers, n, inp);   //call function fgetAnswers
    return (0);
}

void fgetAnswers(char answers[], int n, FILE*inp)
{
    FILE *outp;
    outp = fopen("report.txt", "w");      //file output
    
    int missed[n], i;               //declare variables
    int id =0;
    int correct;
    char choice;
    
    fprintf(outp, "Exam Report");       //printing in file
    
    fprintf(outp,"Question\t");
    
    for(i=0;i < n; i++);        //start loop for printing in file
    fprintf(outp,"%d",i);
    
    for(i=0;i<n;i++)
    fprintf(outp,"Answer\t\t");
    
    
    for(i = 0; i <n; i++);              // printing correct answers
    fprintf(outp,"%c",answers[i]);
    
    for(i=0;i<n;i++)            // initializing missed questions array
        missed[i]=0;
    
    fprintf(outp,"ID\tScore(%%)");
    
    do{      // calculates and displays grades of students
        
        correct = 0;
        fprintf(outp,"%d\t",id);        //print student id
        fscanf(inp,"%c",&choice);       // read first answer
        
        for(i=0;i<n;i++)
        {
            fscanf(inp,"%c",&choice);
            if(choice == answers[i])
            {
                correct++;              //add onto student score if correct
            }
            else
            {
                missed[i]++;            // add to missed array if incorrect
            }
        }
        fprintf(outp,"%d",(correct*100)/n);     //print percentage for student
    
    }while(feof(inp));
    
    
    
    fprintf(outp,"Question\t");             // list questions
    for(i=0;i<n;i++)
    {
        fprintf(outp,"%d ",i);
    }
    fprintf(outp,"Missed by\t");            // print misses
    for(i=0;i<n;i++)
    {
        fprintf(outp,"%d ",missed[i]);
    }
    
    fprintf(outp," ");
    
}
