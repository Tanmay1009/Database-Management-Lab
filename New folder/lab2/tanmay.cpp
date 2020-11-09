#include <bits/stdc++.h>

using namespace std;
# define pb push_back 
struct dt
{
	string s0,s1,s2,s3,s4;
};

struct student
{
	string name;
	string roll;
	dt data[63];
};
struct student arr[158];;

float grade(string str)
{
	if(str=="AA")
		return 10.0;
	else if(str=="AB")
		return 9.0;
	else if(str=="BB")
		return 8.0;
	else if(str=="BC")
		return 7.0;
	else if(str=="CC")
		return 6.0;
	else if(str=="CD")
		return 5.0;
	else
		return 4.0;
}
void clearVector(vector <float> v) 
{
    for (int i=0;i<8;i++) 
	{
        	v.erase(v.begin());
    	}
}

void CPI(vector <float> S, vector <float> cred, float* C) 
{
		int  ss_cal=0;
		int cred_cal=0;

		for(int r=0;r<8;r++)
		{
			ss_cal=0;
			cred_cal=0;
			for(int p=0;p<=r;p++)
			{
				ss_cal+=S[p]*cred[p];
				cred_cal+=cred[p];
			}
			
			C[r] = ((float)ss_cal)/cred_cal;
		}

}
void print(vector <float> S, float* C, char* filename)
{
		fstream fout;
                fout.open(filename, ios::out  |  ios :: app);
		for(int r=1;r<=8;r++)
		{
			fout << r << endl;
		}
		fout << endl;
		fout << "ss" << endl;

		for(int r=0;r<8;r++)
			fout << S[r] << endl;
		fout << endl;
		fout << "CPI" << endl;

		for(int r=0;r<8;r++)
			fout << C[r] << endl;
		fout << endl;


}

int main()
{

	ifstream fin1,fin2,fin3; 
        fin2.open("grades.csv");
	fin1.open("students.csv");
        fin3.open("courses.csv");
	
	 
	string spaces, texts, variable; 

	int count=0; 
	for(int i=0;i<158;i++)
	{
		
                vector<string> row;
		getline(fin1, spaces); 
		stringstream s(spaces);
		while (getline(s, texts, ',')) { 
			row.pb(texts); 
		}
		arr[count].name=row[0];
		arr[count].roll=row[1];
		count++;
	}
	for(int i=0;i<63;i++)
	{
			vector<string> row;
			getline(fin3,spaces);
			stringstream s(spaces);
			while (getline(s, texts, ',')) 
			{ 
				row.pb(texts); 
			}
		for(int j=0;j<158;j++)
		{
			arr[j].data[i].s4=row[2];
			arr[j].data[i].s1=row[6];
			arr[j].data[i].s2=row[0];
			
		}
	}

	for(int i=0;i<63;i++)
	{
		for(int j=0;j<158;j++)
		{
			
			getline(fin2,spaces);
			stringstream s(spaces);
			vector<string> row;
			while (getline(s, texts, ',')) { 
				row.pb(texts); 
			}
			arr[j].data[i].s0=row[2];
			arr[j].data[i].s3=row[1];
			
		}
	}



	for(int i=0;i<158;i++)
	{
		ofstream fout;

		
		char ch[13];
                string x;
		for(int z=0;z<9;z++)
		{
			x = x+ arr[i].roll[z];
		}
		x = x+ ".txt";
			for(int z=0;z<13;z++)
			{
				ch[z]=x[z];
			}
		char* filename=ch;

		fout.open(filename);
		fout << "Name:" << arr[i].name << endl;
		fout << "Roll:" << arr[i].roll << endl; 
		
		int flag=0;
		fout << "Sem 1" << endl;
		for(int j=0;j<63;j++)
		{
			
			if(j!=0 && arr[i].data[j].s2!=arr[i].data[j-1].s2)
			{
				flag=0;
				fout << endl;
				fout << "sem" << arr[i].data[j].s2 << endl;
			}
			if(flag==0)
			{
				fout << "CourseNumber" << endl <<"Course Name"<< endl <<"C" << endl <<"Grades" << endl;
				flag=1;
			}

			fout << arr[i].data[j].s3 << endl << endl << arr[i].data[j].s4<< endl << arr[i].data[j].s1<< endl << arr[i].data[j].s0<<endl;

		}
		fout << endl;
		fout << endl;

		vector <float> S;
		vector <float> cred;
		float ss=0.0;
		float total_cred=0.0;	
                float C[8];
		for(int j=0;j<63;j++)
		{
			if(j!=0 && arr[i].data[j].s2!=arr[i].data[j-1].s2)
			{
				ss=ss/total_cred;
				S.pb(ss);
				cred.pb(total_cred);
				total_cred=0;
				ss=0;
			}
			ss=ss+(arr[i].data[j].s1[0]-48)*(grade(arr[i].data[j].s0));
			total_cred=total_cred + arr[i].data[j].s1[0]-48;
		}

		S.pb(ss/total_cred);
		cred.pb(total_cred);
		CPI(S,cred,C);
		fout << endl;
                fout.close();
                print(S,C,ch);
		clearVector(S);
		clearVector(cred);
	} 
	
} 
