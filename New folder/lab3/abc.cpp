
#include <bits/stdc++.h>

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
fin2.open("grades01.csv", ios::in);
fin3.open("courses01.csv", ios::in);
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
}




void swap(int *a,int *b)
{
	int c=*a;
	*a=*b;
	*b=c;
}

int partition(int A[],int a,int b)
{
	int i=a-1;
	int j=a;
	for(j=a;j<b;j++)
	{
		if(A[j]<=A[b])
		{
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[b]);
	return(i+1);
}

void random_partition(int A[],int a,int b,int pivot_type)
{	
	int n=b-a;
	if(pivot_type==0)
		swap(&A[a],&A[b]);
	else if(pivot_type==1)
	{
		srand(0);
		int random=rand()%2;
		swap(&A[a+n],&A[b]);
	}
	else if(pivot_type==2)
	{
		int B[3]={A[a],A[a+(n/2)],A[b-1]};
		sort(B,B+3);
		if(B[1]==A[a])
			swap(&A[a],&A[b]);
		else if(B[1]==A[a+(n/2)])
			swap(&A[a+(n/2)],&A[b]);
		else
			swap(&A[b-1],&A[b]);
	}
	else if(pivot_type==3)
	{
		int B[3]={A[a+n/4],A[a+(n/2)],A[a+3*n/4]};
		sort(B,B+2);
		if(B[1]==A[a+n/4])
			swap(&A[a+n/4],&A[b]);
		else if(B[1]==A[a+(n/2)])
			swap(&A[a+(n/2)],&A[b]);
		else
			swap(&A[a+3*n/4],&A[b]);
	}
	
}

void quick_sort(int A[],int a,int b,int pivot_type)
{
	if(a<b)
	{
		random_partition(A,a,b,pivot_type);
		int q=partition(A,a,b);	
		quick_sort(A,a,q-1,pivot_type);
		quick_sort(A,q+1,b,pivot_type);
	}
}

void print(int A[],int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
int main() {

 ifstream myfile;

 myfile.open("grades01.csv");A

  int n;
  cin>>n;

  int arr[n*10000];


   for(int i=0; i<n*10000; i++){

  myfile>> arr[i];

} 

partition(arr,0,n*10000-1);

ofstream outfile;

outfile.open("qi80k.txt");

   for(int i=0; i<n*10000; i++){

    outfile<< arr[i] << endl;
}
  return 0;
}









}
