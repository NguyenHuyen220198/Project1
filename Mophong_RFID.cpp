#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stack>
#include<fstream>
#include<vector>

using namespace std;


int IDENTIFICATION = 0;

class Reader {
	int cycle;
	int IDLE; // Không nh?n ???c ph?n h?i
	int COLLISION; // Xung ??t
	int slot;

	string temp; // l?y ra giá tr? ??nh ng?n x?p
	stack<string> g;

public:
	Reader();
	Reader(int);
	Reader(Reader& R);

	void result();
	void creatPrefix(int l);
	void creatQuery(int, int);  // t?o truy v?n
	string sendQuery();   // g?i truy v?n
	void responsQuery(int); // ph?n h?i truy v?n 
};

Reader::Reader()
{
	cycle = 0;
	IDLE = 0;
	COLLISION = 0;
	slot = 0;
}

void Reader::creatPrefix(int l){
	char s[50];
	for (int i = pow(2, l) - 1; i >= 0; i--)
	{
		_itoa_s(i, s, 2);
		string temp = s;
		temp.insert(0, l - temp.length(), '0');
		g.push(temp);
		slot++;
	}
}

void Reader::creatQuery(int tagNum, int l = 1)
{
	if (l != 1 && l != 0)
	{
		creatPrefix(l);
		temp = g.top();
		g.pop();
	}
	else
	{
		if (tagNum > 1)
		{
			g.push(temp + "1");
			slot++;
			g.push(temp + "0");
			slot++;
			temp = g.top();
			g.pop();
		}
		if (tagNum == 1 || tagNum == 0)
		{
			temp = g.top();
			g.pop();
		}
	}


}

string Reader::sendQuery()
{
	cout << "\n";
	cycle++;
	cout << "____ " << cycle << " cycle" << " ____" << endl;
	return temp;
}

void Reader::responsQuery(int tagNum)
{
	if (tagNum == 1)
		IDENTIFICATION++;
	else if (tagNum == 0)
		IDLE++;
	else
		COLLISION++;
}

void Reader::result()
{
	cout << "\n";
	cout << "Tong so Slot: " << slot + 1 << endl;
	cout << "Tong so chu ky: " << cycle << " chu ky." << endl;
	cout << IDLE << " chu ky khong co the trung." << endl;
	cout << COLLISION << " chu ky xung dot." << endl;
	cout << IDENTIFICATION << " the duoc xac dinh." << endl;
}


class Tag
{
	string ID[100];
	int num; // s? l??ng Tag
	int count; // s? l??ng tag sau m?i l?n query

public:
	Tag();
	Tag(int);
	Tag(int, int);

	int getSize(){
		return num;
	}
	void receiveQuery(string); // nh?n truy v?n
	int sendReader(){ // gi? s? tag ph?n h?i sau m?i l?n query
		return count;
	};
	void tagprint(); // in th?
	void creat_bin(int, int); // t?o chu?i binary
};

Tag::Tag()
{
	string input;
	bool checkInput = false;
	vector<string> split;
	string::iterator t, t1;

	while (!checkInput){
		cout << "Nhap cac Tag cach nhau space: " << endl;
		fflush(stdin);
		getline(cin, input);
		checkInput = true;
		for (int i = 0; i < input.length(); i++){
			if (input[i] != '0' && input[i] != '1' && input[i] != ' ')
				checkInput = false;
		}
		if (!checkInput)
			cout << "Nhap lai! (Cac Tag phai la chuoi nhi phan va cac Tag cach nhau space)." << endl;
		else
		{
			split.clear();
			for (t = input.begin(); t < input.end();)
			{
				t1 = find(t, input.end(), ' ');
				if (t != t1)
					split.push_back(string(t, t1));
				if (t1 == input.end())
					break;
				t = t1 + 1;
			}
			for (int i = 1; i < split.size(); i++)
			if (split[i].length() != split[0].length())
				checkInput = false;
			if (!checkInput)
				cout << "Nhap lai! (Cac Tag phai co do dai bang nhau)." << endl;
		}
	}

	for (int i = 0; i < split.size(); i++)
		ID[i] = split[i];
	/*cout << ID;*/
	num = split.size();
	count = -1;
}

Tag::Tag(int n, int len)
{
	num = n;
	creat_bin(n, len);
	count = -1;
}

void Tag::receiveQuery(string querybag) // nh?n các truy v?n
{
	if (querybag.empty())
	{
		cout << "Query: e" << endl;
		for (int i = 0; i < num; i++)
			cout << "Response: " << ID[i] << " <TAG" << i << ">" << endl;
		count = num;
	}
	else
	{
		cout << "Query : " << querybag << endl;
		count = 0;
		for (int i = 0; i < num; i++)
		{
			bool check = true;
			for (int j = 0; j < querybag.length(); j++)
			if (querybag[j] != ID[i].at(j))
				check = false;
			if (check == true)
			{
				cout << "Response: " << ID[i] << " <TAG" << i << ">" << endl;
				count++;
			}
		}
		if (count == 0)
			cout << "Not Response" << endl;
	}
}

void Tag::tagprint()  // In ra các Tag
{
	for (int i = 0; i < num; i++)
		cout << "Tag" << i << ": " << ID[i] << endl;
}

void Tag::creat_bin(int n, int len) // t?o chu?i nh? phân ng?u nhiên
{
	int temp1[100];
	char temp2[100];

	for (int i = 0; i < n; i++)
	{
		int x = pow(2, len) - 1;
		temp1[i] = rand() % x;

		for (int j = 0; j < i; j++)
		{
			if (temp1[i] == temp1[j])
				i--;
		}
		_itoa_s(temp1[i], temp2, 2); //chuy?n h? th?p phân sang nh? phân

		string temp = temp2;
		temp.insert(0, len - temp.length(), '0');

		ID[i] = temp;
	}
}


class Simulator {
	int num;

public:
	Simulator(){ num = 0; }
	void start();
};

void Simulator::start()
{
	char a;
	int l;

	cout << "Option <1>: Nhap gia tri the Tag " << endl;
	cout << "Option <2>: Auto Tag" << endl;
	cout << "->";
	cin >> num;
	cout << "Nhap do dai prefix ban dau: l = ";
	cin >> l;
	while (1)
	{
		if (num == 1)
		{
			Tag T;
			Reader R;

			if (l != 1 && l != 0){
				R.creatQuery(T.sendReader(), l);
				T.receiveQuery(R.sendQuery());
				R.responsQuery(T.sendReader());
			}

			while (IDENTIFICATION < T.getSize())
			{
				R.creatQuery(T.sendReader());
				T.receiveQuery(R.sendQuery());
				R.responsQuery(T.sendReader());
			}
			R.result();

			break;
		}
		else if (num == 2)
		{
			int n = 0, lenTag;

			while (1)
			{
				cout << "\n";
				cout << "Nhap so luong the (Tag): ";
				cin >> n;
				cout << "Nhap do dai moi Tag: ";
				cin >> lenTag;

				if (lenTag > 0 && n > 0)
					break;
				else
					cout << "Nhap lai!";
			}

			Tag T(n, lenTag);
			Reader R;

			T.tagprint();
			cout << "Nhan phim bat ky de tiep tuc: ";
			cin >> a;

			if (l != 1 && l != 0){
				R.creatQuery(T.sendReader(), l);
				T.receiveQuery(R.sendQuery());
				R.responsQuery(T.sendReader());
			}

			while (IDENTIFICATION < T.getSize())
			{
				R.creatQuery(T.sendReader());
				T.receiveQuery(R.sendQuery());
				R.responsQuery(T.sendReader());
			}
			R.result();

			break;
		}
		else
			cout << "Nhap lai!" << endl;
	}

}

// D? li?u test: 001010 010110 110101 010010 110010 000101 111010
int main()
{
	srand((unsigned int)time(NULL));
	Simulator S;
	S.start();

	system("pause");
	return 0;
}
