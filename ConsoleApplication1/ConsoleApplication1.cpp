#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cstdlib>



using namespace std;


class Person {
private:
	string body[3];
	string gender[2];
	string shape[6];
protected:
	int health;
	int hit;
public:
	Person(int g, int b)
		:gender({ "Male","Female" }),
		body({ "slim","fat","muscled" })
		//		shape({"American Indian ","Asian","Black or African American","Hispanic or Latino","White","Native Hawaiian or Other Pacific Islander"})
	{
		setGender(g);
		setBody(b);

	};
	void setGender(int g) {
		if (getGender(g) == "Male") {
			health = 100;
		}
		else {
			health = 70;
		}
	}
	void setBody(int b) {
		if (getBody(b) == "slim") {
			hit = 15;
		}
		else if (getBody(b) == "fat") {
			hit = 25;
		}
		else if (getBody(b) == "muscled") {
			hit = 40;
		}
	}

	string getBody(int z) {
		string b = body[z - 1];
		return b;
	};
	string getGender(int n) {
		string g = gender[n - 1];
		return g;
	};
	string getShape(int m);
	void intro(int z, int n) {
		cout << "u are a person I am " << getGender(n) << " and I am " << getBody(z) << " my health is " << health << " and I hit with damage " << hit << endl;
	}
};

class Demon :public Person {
public:
	int demonHealth = 0;
	int demonHit = 0;
	Demon(int g, int b) :Person(g, b) {
		demonHealth = health *= 1.5;
		demonHit = hit *= 1.5;
	};
	void repairBody() {
		demonHealth += 5;
	};
	void introd(int z, int n) {
		cout << "your enemy is a demon it is " << getGender(z) << " and  is " << getBody(n) << " it's health is " << health << " it hits with damage " << hit << " be careful :o\n\n\n" << endl;
	}
};
class swordMan :public Person {
private:
	int sword;
	string breathing[4];
public:
	int swordManHealth = 0;
	int swordManHit = 0;
	swordMan(int g, int b)
		:Person(g, b), breathing({ "Fire breathing","Flame breathing","Water breathing","Thunder breathing" })
	{
		swordManHealth = health *= 1.25;
		swordManHit = hit *= 1.5;
	};
	string getBreathing(int br) {
		return breathing[br - 1];
	};
	void intro(int z, int n, int br) {
		cout << "u are a Swordman u are " << getGender(z) << " and u are " << getBody(n) << " ur health is " << health << " u hit with damage " << hit << " u use " << getBreathing(br) << endl;
	}

};
class Game :public Demon, public swordMan {
private:
	string Question[10];
	string Answer[30];
	int cor[10];
public:
	int i = 0;
	Game(int g, int b, int z, int f)
		:Question({ "Who played the part of Ben Harper in the TV series My Family?",
				   "Who, according to Roman myth, was the personification of the Earth",
				   "If there are 15 cows standing in line on a hill, how many are facing in the same direction?",
				   "Which one of these is NOT Flammable?",
				   "Who was the author of Tom Sawyer?",
				   "Rontgent was famous for inventing what?",
				   "President John Kennedy died in what year?",
				   "When was the first soccer world cup held?",
				   "On the Auckland coat of arms, there are two kiwis guarding a scroll. What is written on it?",
				   "Is it true that marijuana is legal in Australia?" }),
		Answer({ "Robert Linsday",
				"Kris Marshall",
				"Tim Roth",

				"Uranus",
				"Terra",
				"Pluto",

				"6",
				"8",
				"All of them",

				"Lead Nitrate",
				"Gallium",
				"Zinc",

				"Charles Dickens",
				"Fleur Adcock",
				"Mark Twain",

				"The printer",
				"The X-ray",
				"The telegram",

				"1974",
				"1963",
				"1950",

				"1945",
				"1917",
				"1930",

				"Advance",
				"Approach",
				"Auckland",

				"True",
				"False",
				"none" }),
		cor({ 1,2,3,3,3,2,2,3,1,1 }),
		Demon(g, b),
		swordMan(z, f)

	{
		introd(z, f);
	}

	void GameIntro() {

		cout << "\t\t\tHello and welcome to Demon Slayer game " << endl;
		cout << "\t\t\tGood luck Champion :> " << endl;
		cout << "\t\t\tu should kill the demon every correct answer damages ur health \n\t\t\tand every wrong answer damages u and demon get healed\n\n" << endl;
		while (i < 10) {
			int k = 1;
			cout << Question[i] << endl;
			for (int j = i * 3; j < i * 3 + 3; j++) {

				cout << k++ << ". " << Answer[j] << endl;
			}
			int ans;
			cin >> ans;

			if (ans == cor[i]) {

				demonHealth -= swordManHit;
				if (demonHealth <= 0) {
					cout << "demon died gj" << endl;
					break;
				}
				system("cls");
				cout << "\nDemon health now " << demonHealth << " well played champion\n" << endl;
				i++;

			}
			else {
				swordManHealth -= demonHit;
				if (swordManHealth <= 0) {
					cout << "you died :(" << endl;
					break;
				}
				repairBody();
				system("cls");
				cout << "\nSwordMan Health  now " << swordManHealth << " Work harder " << endl;
				i++;
			}

		}

	}
};

int main() {
	int gender, body, breathing;
	srand(time(0));

	cout << "Enter ur selected gender \n1.Male \n2.Female" << endl;
	cin >> gender;
	system("cls");
	cout << "Enter ur selected body \n1.slim \n2.fat \n3.muscled " << endl;
	cin >> body;
	system("cls");
	cout << "Enter ur selected gender \n1.Fire breathing \n2.flame breathing \n3.Water breathing \n4.Thunder breathing " << endl;
	cin >> breathing;
	system("cls");

	swordMan s(gender, body);
	s.intro(gender, body, breathing);
	Game g(gender, body, rand() % 2 + 1, rand() % 3 + 1);
	g.GameIntro();
}
