
#include <bits/stdc++.h>
#include <fstream> 
#include <iostream>
using namespace std;



struct student
{
string name;
string roll;
string data[63][5];
};

struct student arr[158];

int main()
{

fstream fin1,fin2,fin3;
fin1.open("students01.csv", ios::in);

vector<string> row;
string line, word, temp;

int count=0;
for(int i=0;i<158;i++)
{
row.clear();
getline(fin1, line);
stringstream s(line);
while (getline(s, word, ',')) {
row.push_back(word);
}
arr[count].name=row[0];
arr[count].roll=row[1];
count++;
}


for(int i=0;i<63;i++)
{
for(int j=0;j<158;j++)
{
row.clear();
getline(fin2,line);
stringstream s(line);
while (getline(s, word, ',')) {
row.push_back(word);
}
arr[j].data[i][3]=row[1];//course_code
arr[j].data[i][0]=row[2];//course_grade
}
}

for(int i=0;i<63;i++)
{
row.clear();
getline(fin3,line);
stringstream s(line);
while (getline(s, word, ',')) {
row.push_back(word);
}
for(int j=0;j<158;j++)
{
arr[j].data[i][2]=row[0];//course_semester
arr[j].data[i][4]=row[2];//course_name
arr[j].data[i][1]=row[6];//course_credits
}


void Merge(int *a, int low, int high, int mid)
{

	int i, j, k;
	int temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 

void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		Merge(a, low, high, mid);
	}
}
 
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		Merge(a, low, high, mid);
	}
}
 
int main() {



fstream fin1;
fin1.open("students01.csv", ios::in);

vector<string> row;
string line, word, temp;

int count=0;
for(int i=0;i<158;i++)
{
row.clear();
getline(fin1, line);
stringstream s(line);
while (getline(s, word, ',')) {
row.push_back(word);
}
arr[count].name=row[0];
arr[count].roll=row[1];
count++;
}

  long long int n;
cin>> n;


int a[n*10000];
int data;

   for(long long int i=0; i<n*10000; i++){
    
   fin1>> data;
   a[i] = data ;

}
 
 MergeSort(a,0,n*10000-1);
ofstream fout;
fout.open("merged.csv", ios::in);

   for( long long int i=0; i<n*10000; i++){

    fout<<a[i]<<endl;
}
 
 
   return 0;
}


