/* Randy Randall
 * CS260 Assignment 1
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Person.h"
#include <algorithm>

using namespace std;

int main()
{
    //Request data size
    int size;//Number of records your program will read and work with
    cout << "Read in a single integer: ";
    cin >> size;

    //Allocate memory on the heap for dynamic array full of structs
    Person* persons = new Person[size];
    Person* personsSorted = new Person[size];

    //Read file
    ifstream read;
    read.open("people.txt");//Opens the file
    //if file doesn't open
    if(read.fail())
        cout << "Could not open file";
    else;

    string kNum, last, first, intHolder;
    int zip;

    for (int i=0; i < size; i++){
        getline(read, kNum, ',');
        persons[i].kNum = kNum;
        getline(read, last, ',');
        persons[i].last = last;
        getline(read, first, ',');
        persons[i].first = first;
        read >> zip;
        persons[i].zipCode = zip;

    }

    //Copy over array for sorting
    copy(persons, persons + size, personsSorted);
    sort(personsSorted, personsSorted + size);

    //Part 1
    cout << "-----------------------------Section 1-----------------------------\n";
    cout << "Last person in persons array: " << persons[size-1].last << ", " << persons[size-1].first << endl;


    //Part 2
    cout << "-----------------------------Section 2-----------------------------\n";
    cout << "Number of people with last name Mertz: " << countLastName("Mertz", personsSorted, size) << endl;

    //Time to run of countLastName
    const long TIMING_REPETITIONS = 10000;
    clock_t start = clock();

    int result;
    //Repeat work many times to get measurable duration
    for(int i = 0; i < TIMING_REPETITIONS; i++) {
        //Work we want to measure
        result = countLastName("Mertz", persons, size);
    }

    clock_t end = clock();

    //Figure out average time to do work one time
    double seconds = static_cast<double>(end - start)
            / CLOCKS_PER_SEC
            / TIMING_REPETITIONS;

    cout << endl << "Calculations took " << seconds << " seconds" << endl;



    //Part 3
    cout << "-----------------------------Section 3-----------------------------\n";

    cout << "Index of first and last people with last name: Abbott\nFirst index: "
    << binaryFindFirstByLastName("Abbott",personsSorted, size) << endl << "Last index: "
    << binaryFindLastByLastName("Abbott",personsSorted, size) << endl;

    cout << endl;
    cout << "Index of first and last people with last name: Zulauf\nFirst index: "
    << binaryFindFirstByLastName("Zulauf",personsSorted, size) << endl << "Last index: "
    << binaryFindLastByLastName("Zulauf",personsSorted, size) << endl;

    //Part 4
    cout << "-----------------------------Section 4-----------------------------\n";
    cout << "Total number of people with last name Mertz: " << countLastNameInSorted("Mertz",personsSorted, size) << endl;
    //Time to run of countLastName
    const long TIMING_REPETITIONS2 = 10000;
    clock_t start2 = clock();

    int result2;
    //Repeat work many times to get measurable duration
    for(int i = 0; i < TIMING_REPETITIONS2; i++) {
        //Work we want to measure
        result2 = countLastNameInSorted("Mertz", personsSorted, size);
    }

    clock_t end2 = clock();

    //Figure out average time to do work one time
    double seconds2 = static_cast<double>(end2 - start2)
            / CLOCKS_PER_SEC
            / TIMING_REPETITIONS2;

    cout << endl << "Calculations took " << seconds2 << " seconds" << endl;

    //Part 5
    cout << "-----------------------------Section 5-----------------------------\n";
    cout << "Indexes 2-7 sorted by zipcode. First 10 people are: \n";

    partialZipSort(persons,2,7);

    for(int i = 0;i<10;i++){
        cout << persons[i].last << ", "
        << persons[i].first << " " << persons[i].zipCode << endl;
    }

    //Part 6
    cout << "-----------------------------Section 6-----------------------------\n";

    //Choose either mergeSort or Quicksort/nameSort

    //mergeSort(persons,size);
    nameSort(persons,size);//QuickSort

    //Time to run of countLastName
    const long TIMING_REPETITIONS3 = 10000;
    clock_t start3 = clock();

    int result3;
    //Repeat work many times to get measurable duration
    for(int i = 0; i < TIMING_REPETITIONS; i++) {
        //Work we want to measure
        result3 = countLastNameInSorted("Mertz", personsSorted, size);
    }

    clock_t end3 = clock();

    //Figure out average time to do work one time
    double seconds3 = static_cast<double>(end3 - start3)
            / CLOCKS_PER_SEC
            / TIMING_REPETITIONS3;

    cout << endl << "Calculations took " << seconds3 << " seconds" << endl;

    //Print first 10 records to verify sort
    for(int i = 0;i<10;i++){
        cout << persons[i].last << ", "
        << persons[i].first << " " << persons[i].zipCode << endl;
    }

    //Delete memory
    delete [] persons;
    delete [] personsSorted;

    return 0;
}



