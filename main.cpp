//  Created by Milan Patel on 10/2/18.
//  Copyright © 2018 Milan Patel. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

float Display(float, int);

using namespace std;

int main()
{
    ifstream inputfile;         //Set input and output steams
    ofstream outputfile;
    
    float score, total, fscore;     //Declare test variables
    int rscore;
    
    inputfile.open("score.txt");        //open input file
    outputfile.open("final score.txt"); //open output file
    inputfile >> score >> total;        //read input file and store variables
    fscore = (score / total)*100;       //calculate final score
    rscore = ceil(fscore);              //round final score
    
    //Write results in output file
    outputfile << fixed << "Final score is " << setprecision(0) << rscore << "%" << endl;
    outputfile << fixed << "Final score is " << setprecision(5) << fscore << "%" << endl;
    
    // Display results function
    Display ( fscore, rscore);
    
    getchar();          //hold curser for user
    inputfile.close();  //close input file
    return 0;
}

float Display(float fscore, int rscore)       //Display function
{
    //Display results
    cout << fixed << "Final score is " << setprecision(0) << rscore << "%" << endl;
    cout << fixed << "Final score is " << setprecision(5) << fscore << "%" << endl;
    
    if (fscore > 90) {
        cout << "Excellent" << endl;
    }
    else if (fscore > 80) {
        cout << "Well Done" << endl;
    }
    else if (fscore > 70) {
        cout << "Good" << endl;
    }
    else if (fscore >= 60) {
        cout << "Need Improvement" << endl;
    }
    else if (fscore <= 50) {
        cout << "Fail" << endl;
    }
    return (0);
}
