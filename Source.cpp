/*main.cpp*/

//
// Grade Analysis program in modern C++.
//
// << Marek Zietek >>
// U. of Illinois, Chicago
// CS 341: Fall 2018
// Project 01
//
//#pragma warning (disable: 4101)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <stdio.h>      
#include <stdlib.h>

using namespace std; 


class Teacher
{
private: 
	string Prof;
	string Coarse;
	double NumStudents=0;
	int Distribution;
	int A;
	int B;
	int C;
	int D;
	int F;
	int I;
	int NR;
	int S;
	int U;
	int W;
	int CoarseNumber; 
	double totalA=0, totalB = 0, totalC = 0, totalD = 0, totalF = 0;
	double hisTotal = 0;
	double percent = 0;
	double DF = 0;

public:
	Teacher(string prof, string coarse, int coarsenumber, int a, int b, int c, int d, int f, int i, int nr, int s, int u,int w)
		: Prof(prof), Coarse(coarse), CoarseNumber(coarsenumber) ,A(a), B(b), C(c), D(d), F(f), I(i), NR(nr), S(s), U(u),W(w)
	{}

	//Methods
	string getDept() {
		return Coarse;
	}

	int getNumber() {
		return CoarseNumber;
	}

	string getProf() {
		return Prof;
	} 

	int getNumStudents() {
		NumStudents = 0;
		NumStudents = NumStudents + A + B + C + D + F + I + NR + S + U + W;  
		return NumStudents;
	}


	int getNumStudents2() {
		return NumStudents;
	}

	double DFW() {
		NumStudents = 0;
		DF = 0;
		DF += D + F + W;
		NumStudents += A + B + C + D + F + W;
		return (DF / NumStudents) * 100;
	}

	double getA() {
		hisTotal = 0;
		totalA += A;
		hisTotal += A + B + C + D + F + NR + S + U;
		percent = ( totalA / hisTotal ) * 100;
		return percent; 
	}  

	double getB() {
		hisTotal = 0;
		totalB += B;
		hisTotal += A + B + C + D + F + NR + S + U;
		percent = (totalB / hisTotal) * 100;
		return percent;
	}  

	double getC() {
		hisTotal = 0;
		totalC += C;
		hisTotal += A + B + C + D + F + NR + S + U;
		percent = (totalC / hisTotal) * 100;
		return percent;
	}

	double getD() {
		hisTotal = 0;
		totalD += D;
		hisTotal += A + B + C + D + F + NR + S + U;
		percent = (totalD / hisTotal) * 100;
		return percent;
	}

	double getF() {
		hisTotal = 0;
		totalF += F;
		hisTotal += A + B + C + D + F + NR + S + U;
		percent = (totalF / hisTotal) * 100;
		return percent;
	}

	void countA() {
		totalA += A;
		hisTotal += A + B + C + D + F + W;
	}

	void printA() {
		cout << totalA << endl;
		cout << hisTotal << endl;
	}

};



class Course
{
private:
	int NumCoarses;
	int NumGrades;
	int Distributions;
	string Dept;
	int A,B,C,D,F;

public:
	Course(int numcoarses, string dept, int a, int b, int c, int d, int f )
		: NumCoarses(numcoarses), Dept(dept), A(a),B(b),C(c),D(d),F(f)
	{}


	//Methods 
	void TotalCoarse() {
		NumCoarses++;
	}

	void TotalGrades() {
		NumGrades += NumGrades + A + B + C + D + F;
	}

	int getAs() {
		return A;
	}

	int getBs() {
		return B;
	}

	int getCs() {
		return C;
	}

	int getDs() {
		return D;
	}

	int getFs() {
		return F;
	}

	string getDEPT() {
		return Dept;
	}

	void PrintCoarse() {
		cout << NumCoarses << endl;
	}

	void PrintGrades() {
		cout << NumGrades << endl;
	}

};


int main()
{
	string excelFile;
	cin >> excelFile; 

	cout << std::fixed;
	cout << std::setprecision(2);
	cout << excelFile << endl << endl;
	
	ifstream file( excelFile );
	string  line; 
	string Dept, Number, Title, A, B, C, D, F, I, NR, S, U, W, Instructor;
	int iterator = 0;

	vector<Course> AllInformation;  //This is the vector for the department grades and only the grade

	vector<Teacher> Faculty;  //This is a vector for the faculty

	int total = 0;  //This int will count up the total Grades in general
	double totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalF = 0;
	
	int a, b, c, d, f, i, nr,s, u, w;  //ints for the alphbet letters
	int ClassNumber;

	//Check if file opened
	if (!file.good()) {
		cout << "cannot open file!" << endl;
		return -1;
	} 

	//Skip first line in file
	getline(file, line);

	//Main while loop
	while (getline(file, line) ) {
		
		stringstream ss(line); 
		
		getline( ss, Dept, ',' );
		getline(ss, Number, ',');
		getline(ss, Title, ',');
		getline(ss, A, ',');
		getline(ss, B, ',');
		getline(ss, C, ',');
		getline(ss, D, ',');
		getline(ss, F, ',');
		getline(ss, I, ',');
		getline(ss, NR, ',');
		getline(ss, S, ',');
		getline(ss, U, ',');
		getline(ss, W, ',');
		getline(ss, Instructor, ','); // might need to change to /0


		//1,2000,2,4;2,2005,2,5

		//Counts all the classes
		iterator++; 
		
		//Convert string to int
		a = stoi(A);
		b = stoi(B);
		c = stoi(C);
		d = stoi(D);
		f = stoi(F);
		i = stoi(I);
		nr = stoi(NR);
		s = stoi(S);
		u = stoi(U);
		w = stoi(W);
		ClassNumber = stoi(Number);

		//Object -- not really sure what to call this but it constructs everything
		Course AllGrades( 0, Dept, a, b, c, d, f ); 

		//Vector with all the information you need
		AllInformation.push_back(AllGrades);

		Teacher ThirdPart( Instructor, Dept, ClassNumber, a, b, c, d, f, i, nr, s, u, w );

		Faculty.push_back(ThirdPart);

	}


	//COLLEGE OF ENGINEERING while loop --- it will count up everything in general 
	i = 0;
	while (i < AllInformation.size()) {
		total = total + AllInformation[i].getAs() + AllInformation[i].getBs() + AllInformation[i].getCs() + AllInformation[i].getDs() + AllInformation[i].getFs();
		totalA = totalA + AllInformation[i].getAs();
		totalB = totalB + AllInformation[i].getBs();
		totalC = totalC + AllInformation[i].getCs();
		totalD = totalD + AllInformation[i].getDs();
		totalF = totalF + AllInformation[i].getFs();
		i++;
	}

	//Calculates the COLLEGE OF ENGINEERING percent in A,B,C,D,F
	double percentA = (totalA / total) * 100;
	double percentB = (totalB / total) * 100;
	double percentC = (totalC / total) * 100;
	double percentD = (totalD / total) * 100;
	double percentF = (totalF / total) * 100;  

	//cout the COLLEGE OF ENGINEERING information
	cout << "College Of Engineering:" << endl;
	cout << "  Num courses: " << iterator << endl;
	cout << "  Num Grades: " << total << endl;
	cout << "  Distribution: " << percentA << "%, " << percentB << "%, " << percentC << "%, " << percentD << "%, " << percentF << "%" << endl<<endl<<endl;

	//Reset everything back to normal
	totalA = totalB = totalC = totalD = totalF = 0.0;
	total = 0;
	percentA = percentB = percentC = percentD = percentF = 0; 
	iterator = 0;

	//Intitialize the vector string in here for comparison
	i = 0;
	bool door = true;
	vector<string> deptClasses; // Change this of type department
	deptClasses.push_back(AllInformation[0].getDEPT());
	for (auto s : AllInformation) {
		if (door) {
			door = false;
		}
		if (s.getDEPT() != deptClasses[i]) {
			deptClasses.push_back( s.getDEPT() );
			//depatrment s( deptClasses, )
			door = true;
			i++;
		}
	}


	//This algo matches and prints everything by department 
	for ( int j = 0; j < deptClasses.size(); j++)
	{
		bool whatever = false;
		bool last = false;
		if (j == deptClasses.size() - 1) {
			last = true;
		}
		for ( auto s : AllInformation )
		{

			if ( deptClasses[j] == s.getDEPT() )
			{
				total = total + s.getAs() + s.getBs() + s.getCs() + s.getDs() + s.getFs();
				totalA = totalA + s.getAs();
				totalB = totalB + s.getBs();
				totalC = totalC + s.getCs();
				totalD = totalD + s.getDs();
				totalF = totalF + s.getFs();
				iterator++;  
				whatever = true;
				
				if (last) {

					percentA = (totalA / total) * 100;
					percentB = (totalB / total) * 100;
					percentC = (totalC / total) * 100;
					percentD = (totalD / total) * 100;
					percentF = (totalF / total) * 100;

					cout << deptClasses[j] << ":" << endl;
					cout << "  Num courses: " << iterator << endl;
					cout << "  Num Grades: " << total << endl;
					cout << "  Distribution: " << percentA << "%, " << percentB << "%, " << percentC << "%, " << percentD << "%, " << percentF << "%" << endl;


					totalA = totalB = totalC = totalD = totalF = 0.0;
					total = 0;
					percentA = percentB = percentC = percentD = percentF = 0;
					iterator = 0;
					break;
				}
			}

			else if(whatever){
				percentA = (totalA / total) * 100;
				percentB = (totalB / total) * 100;
				percentC = (totalC / total) * 100;
				percentD = (totalD / total) * 100;
				percentF = (totalF / total) * 100;

				cout << deptClasses[j] <<":"<< endl;
				cout << "  Num courses: " << iterator << endl;
				cout << "  Num Grades: " << total << endl;
				cout << "  Distribution: " << percentA << "%, " << percentB << "%, " << percentC << "%, " << percentD << "%, " << percentF << "%" << endl;


				totalA = totalB = totalC = totalD = totalF = 0.0;
				total = 0;
				percentA = percentB = percentC = percentD = percentF = 0;
				iterator = 0;
				break;
			}
		}
	}

	//Create a seperate class / object for storing the teachers
	string userInput;

	cout << endl;
	cout << "Please enter instructor's name (or prefix or #)> ";
	cin >> userInput;
	
	//While loop that will allow user to input Professor's names
	while ( userInput !="#"  ) {


		for (auto x : Faculty) {
			if (x.getProf().rfind(userInput, 0) != string::npos) {

				if (x.DFW() == 100.00) {
					cout << x.getDept() << " " << x.getNumber() << " " << "(" << x.getProf() << ")" << ":" << endl;
					cout << "Num students: " << x.getNumStudents() << endl;
					cout << "Distribution: " << "no report" << endl;
					cout << "DFW rate: " << "100%" << endl;
					//cout << endl; 
					break;
				}

				if ( x.DFW() < 100.00 ){
					cout << x.getDept() << " " << x.getNumber() << " " << "(" << x.getProf() << ")" << ":" << endl;
					cout << "Num students: " << x.getNumStudents() << endl;
					cout << "Distribution: " << x.getA() << "%, " << x.getB() << "%, " << x.getC() << "%, " << x.getD() << "%, " << x.getF() << "%" << endl;
					cout << "DFW rate: " << x.DFW() << "%" << endl;
					//cout << endl;
					//x.countA();
					//x.printA();
					//cout << endl;
					//cout
				}

				else {

					cout << x.getDept() << " " << x.getNumber() << " " << "(" << x.getProf() << ")" << ":" << endl;
					cout << "Num students: " << x.getNumStudents() << endl;
					cout << "Distribution: " << "no report" << endl;
					cout << "DFW rate: " << "0.00%" << endl;
					//cout << endl;

				}

			}
		}
		cout << endl;

		//cout << endl;
		cout << "Please enter instructor's name (or prefix or #)> ";
		cin >> userInput;
	}
	return 0;
}