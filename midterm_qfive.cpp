// midterm_qfive.cpp : Defines the entry point for the console application.
// James Potratz CS 223 Mid-term Question #5

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
//Movie Class
class movieType
{
public: //Class functions
	void getRating(int rating, int numOfRatings); //Used to input ratings
	void getAccValue(); //Used to calculate the Accumulated value
	void getAverageRating(); //Used to calculate the average rating
	int returnAccValue(); //Returns the accumulated value
	double returnAverageRating(); //Returns the average rating
	void setName(string n); //Set the name of the movie
	void setMPAArating(string r); //Set the MPAA rating of the movie
	void printInfo(); //Prints the movie name, MPAA rating, and average movie rating of the movie
	movieType(); //Default constructor
	movieType(string moviename, string movieMPAArating); //Constructor w/ parameters
private: //Variables used to store data about the movie
	string name; //#5.a
	string MPAArating; //#5.b
	double averageRating; //Variable to hold average of all the movie ratings
	int accValue = 0; //Variable to hold accumulated value
	int oneRating = 0; //#5.c
	int twoRating = 0; //#5.d
	int threeRating = 0; //#5.e
	int fourRating = 0; //#5.f
	int fiveRating = 0; //#5.g
};
//Get the ratings for the movie
void movieType::getRating(int rating, int numOfRatings)
{
	if (rating < 0 || rating > 5) {
		cout << "Not valid rating used in movieType.getRating function. Please input 1-5 in the first parameter." << endl; //Catch to ensure user is inputting rating properly
	}
	if (rating == 1) {
		oneRating = oneRating + numOfRatings; //Adds itself to current value incase more ratings are added later
	}
	if (rating == 2) {
		twoRating = twoRating + numOfRatings;
	}
	if (rating == 3) {
		threeRating = threeRating + numOfRatings;
	}
	if (rating == 4) {
		fourRating = fourRating + numOfRatings;
	}
	if (rating == 5) {
		fiveRating = fiveRating + numOfRatings;
	}
}
//get the Accumulated Value 
void movieType::getAccValue()
{
	accValue = oneRating + twoRating + threeRating + fourRating + fiveRating;
}
//get the Average rating
void movieType::getAverageRating()
{
	getAccValue();
	if (accValue == 0) //Catch to make ensure that ratings have been inputted before returning average rating
	{
		averageRating = 0;
	}
	else
	{
		averageRating = (oneRating + (twoRating * 2) + (threeRating * 3) + (fourRating * 4) + (fiveRating * 5)) / accValue; //Average calculation.
	} 
}
//Return the Accumulated value
int movieType::returnAccValue()
{
	getAccValue();
	return accValue;
}
//Return the Average rating
double movieType::returnAverageRating()
{
	getAverageRating();
	return averageRating;
}
//Set the name of the movie
void movieType::setName(string n)
{
	name = n;
}
//Set the MPAA rating
void movieType::setMPAArating(string r)
{
	MPAArating = r;
}
//Print basic movie info
void movieType::printInfo()
{
	cout << "Movie name is " << name << endl;
	cout << "MPAA rating is " << MPAArating << endl;
	getAverageRating();
	cout << "Average rating is " << averageRating << endl;
}
//Constructor w/ no parameters
movieType::movieType()
{
	name = "No movie name assigned";
	MPAArating = "No MPAA rating assigned";
}
//Constructor w/ parameters
movieType::movieType(string moviename, string movieMPAArating)
{
	name = moviename;
	MPAArating = movieMPAArating;
}
int main()
{
    //FIRST SET OF TESTS
	//Uses a movieType object w/ no parameters and ensures helper functions can set and retrieve data properly
	cout << "First set of tests" << endl;
	cout << "Creating a movieType object w/ a no parameter constructor" << endl;
	movieType thor;
	cout << "Return the info about the movie" << endl;
	thor.printInfo();
	cout << endl;
	cout << "Set the name of the movie and the  MPAA rating and then return basic movie info using printInfo" << endl;
	thor.setName("Thor");
	thor.setMPAArating("PG-13");
	thor.printInfo();
	cout << "Assign ratings to the movie. 5 ratings each for all five possible ratings. Return Accumulated and Average rating" << endl;
	thor.getRating(1, 5);
	thor.getRating(2, 5);
	thor.getRating(3, 5);
	thor.getRating(4, 5);
	thor.getRating(5, 5);
	cout << "Average rating is " << thor.returnAverageRating() << endl;
	cout << "Accumulated ratings is " << thor.returnAccValue() << endl;
	system("pause");
	cout << endl << endl;

	//SECOND SET OF TESTS
	//Uses a movieType object w/ no parameters and ensures helper functions can set and retrieve data properly
	cout << "Second set of tests" << endl;
	cout << "Creating a movieType object w/ a parameter constructor" << endl;
	movieType spiderman("Spidername", "R");
	cout << "Return the info about the movie." << endl;
	spiderman.printInfo();
	cout << endl;
	cout << "Set the name of the movie and the rating and then return basic movie info using printInfo" << endl;
	spiderman.setName("Spiderman-2");
	spiderman.setMPAArating("E");
	spiderman.printInfo();
	cout << "Assign ratings to the movie. 6 ratings each for all five possible ratings. Return Accumulated and Average rating" << endl;
	spiderman.getRating(1, 6);
	spiderman.getRating(2, 6);
	spiderman.getRating(3, 6);
	spiderman.getRating(4, 6);
	spiderman.getRating(5, 6);
	cout << "Average rating is " << spiderman.returnAverageRating() << endl;
	cout << "Accumulated ratings is " << spiderman.returnAccValue() << endl;
	system("pause");
}

