//----------------------------------------------------------
// CS260 Assignment 1 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include "Person.h"
#include <iostream>

using namespace std;

bool operator==(const Person& p1, const Person& p2){
	if(p1.kNum == p2.kNum)
		return true;
	else
		return false;
}

bool operator<(const Person& p1, const Person& p2) {
	if(p1.last < p2.last || 
	   p1.last == p2.last && p1.first < p2.first)
		return true;
	else
		return false;
}

void partialZipSort(Person* array, int start, int end) {
    int i, j, pass = 0;
    Person temp;
    for(i = start; i<end; i++) {
       for(j = i+1; j<end; j++)
       {
          if(array[j].zipCode < array[i].zipCode) {
             temp = array[i];
             array[i] = array[j];
             array[j] = temp;
          }
       }
       pass++;
    }
}
void nameSort(Person* array, int size) {
      quickSortInternal(array, 0, size-1);
}
void quickSortInternal (Person* array, int low, int high){
    if (low >= high) return; // base case : 1 or less item

    int pivot = partitionFunct(array, low, high);
    quickSortInternal(array, low, pivot-1);
    quickSortInternal(array, pivot+1, high);
}
int partitionFunct(Person* array, int low, int high){
    Person pivot = array[low];
    int i = low + 1;
    int j = high;


 while (i <= j)
    {
        while (i <= j && array[i] < pivot)
            i++;
        while (pivot < array[j] && i <= j)
            j--;
      if (i <= j)
        {
            Person temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    Person temp2 = array[low];
    array[low] = array[j];
    array[j] = temp2;

    return j;

}
void mergeFunc(Person arr[], int low, int mid, int high, Person temp[]) {
    //MergeSort

    int i=low;
    int j=mid + 1;
    int k=low;

    while(i<=mid && j<=high)
    {
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=high){
        temp[k++] = arr[j++];
    }
    for(int s = low; s <= high; s++)
    {
        arr[s] = temp[s];
    }

}

void mergeSortInternal (Person arr[], int low, int high, Person temp[]) {


    // base case: 1 or fewer elements is sorted
    if (low >= high)
        return;

    int mid = (low + high)/2;
    mergeSortInternal(arr,low,mid,temp);//Recursively sort first low to mid
    mergeSortInternal(arr,mid+1,high,temp);//Recursively sort second mid+1 to high

    mergeFunc(arr,low,mid,high,temp);//Call mergeFunc to merge the two halves
}

void mergeSort(Person arr[], int arrSize) {
    Person* temp = new Person[arrSize];
    mergeSortInternal (arr, 0, arrSize-1, temp);
    delete [] temp;
}

int countLastName(const std::string& lastName, const Person* array, int size) {
    int count = 0;
    for(int i = 0; i <= size-1; i++){
        if(array[i].last == lastName){
            count += 1;
        }
    }
    return count;
}

int binaryFindFirstByLastName(const std::string& value, const Person* array, int size) {

    int low = 0;
    int high = size -1;
    int result = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(array[mid].last == value){
            result = mid;
            high = mid -1;
        }
        else if(array[mid].last > value)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
}


int binaryFindLastByLastName(const std::string& value, const Person* array, int size) {
    int low = 0;
    int high = size -1;
    int mid = 0;
    int result = -1;
    while(low <= high){
        mid = (low + high) / 2;
        if(array[mid].last == value){
            result = mid;
            low = mid + 1;
        }
        else if(array[mid].last > value)
            high = mid - 1;
        else
            low = mid + 1;

    }
    return result;

}


int countLastNameInSorted(std::string lastName, const Person* array, int size) {
    int startIndex = binaryFindFirstByLastName(lastName, array, size);
    int endIndex = binaryFindLastByLastName(lastName,array,size);
    int counter = 0;
    for(int i = startIndex; i <= endIndex; i++){
        counter += 1;
    }
    return counter;

}

