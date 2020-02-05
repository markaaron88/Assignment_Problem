/*
Title: Assignment.cpp
Abstract: Write a C++ program called assignment.cpp that solves the Assignment Problem in Chap
3.4. Your program should read the assignment costs of each person from a user and determine the best
assignment. In the program, you can assume that the number of all jobs is less than 15. To get the full
credits, your program should display all combinations of assignments.
Author: Mark Mariscal
ID: 7198
Date: 02/04/2020
*/




#include <algorithm>
#include<vector>
#include <iostream>
using namespace std;
int main ()
{
    int job;
    cout<<"Enter number of jobs:";
    cin>>job;
    int twodarray[job][job];
    cout<<"Enter Assignment cost of "<<job<<" persons:"<<endl;
    for(int i =0 ;i<job;i++){
        cout<<"Person "<<i+1<<" : ";
        for(int j = 0 ; j<job;j++){
            cin>>twodarray[i][j];
        }
    }
    int num[job];
    for(int i = 0;i<job;i++){
        num[i]=i+1;
    }
    vector<vector<int>> vectorsPermutation;
    vector<int> totalCostVector;
    sort (num,num+job);
    cout<<endl;
    int permutation = 1;
    do {
        cout<<"Permutation "<<permutation<<": <";
        vector<int> x; //
        for(int i = 0 ;i<job;i++)
            x.push_back(num[i]);
        vectorsPermutation.push_back(x);
        for (int i = 0; i < x.size(); i++) {
            if(i!=x.size()-1)
                cout << x.at(i) << ", ";
            else
                cout<<x.at(i);
        }permutation++;
        int totalCost = 0;
        for(int i=0;i<job;i++)
        {
            totalCost+=twodarray[i][num[i]-1];
        }
        totalCostVector.push_back(totalCost);
        cout<<"> => total cost:"<<totalCost;
        cout<<'\n';
    } while ( next_permutation(num,num+job) );
    vector<int> smallest = vectorsPermutation.at(distance(totalCostVector.begin(),
            find(totalCostVector.begin(),totalCostVector.end(), *min_element(totalCostVector.begin(),
                    totalCostVector.end()))));
    cout<<"\nSolution: <";
    for (int i = 0; i < smallest.size(); i++) {
        if(i!=smallest.size()-1)
            cout << smallest.at(i) << ", ";
        else
            cout<<smallest.at(i);
    }
    cout<<"> => total cost: "<<*min_element(totalCostVector.begin(), totalCostVector.end());
    return 0;
}