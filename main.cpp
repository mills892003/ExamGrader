//  Created by Milan Patel on 9/4/18.
//  Copyright © 2018 Milan Patel. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputfile;         //Set input and output steams
    ofstream outputfile;
    
    float score, total, fscore;     //Declare test variables
    
    inputfile.open("score.txt");        //open input file
    outputfile.open("final score.txt"); //open output file
    inputfile >> score >> total;        //read input file and store variables
    fscore = (score / total)*100;             //calculate final score
    
    
    //Write results in output file
    outputfile << fixed << "Final score is " << setprecision(0) << ceil(fscore) << "%" << endl;
    outputfile << fixed << "Final score is " << setprecision(5) << fscore << "%" << endl;

    //Display results
    cout << fixed << "Final score is " << setprecision(0) << ceil(fscore) << "%" << endl;
    cout << fixed << "Final score is " << setprecision(5) << fscore << "%" << endl;
    
    getchar();          //hold curser for user
    inputfile.close();  //close input file
    return 0;
}
