#include <iostream>
#include <vector>
#include <string>
class block_number {
public:
	void init_block();
	void retain_original(int row,int cloum);
	void move(int row, int column, int row2);
	//void moveall(int row, int column, int row2);
	void location(int x, int& x_b, int& x_h);
	void solve();
	void print();
private:
	int n;
	std::vector<int> blocks[30];
};

void block_number::init_block()
{
	std::cout << "plase input array size" << std::endl;
	std::cin >> n;
	for (int i = 0;i < n;i++)
		blocks[i].push_back(i);
}

void block_number::retain_original(int row, int column)
{
	for (int i = column + 1;i < blocks[row].size();i++) {
		int k = blocks[row][i];
		blocks[k].push_back(k);
	}
	int x = column + 1;
	blocks[row].resize(x);
}


void block_number::move(int row, int column, int row2)
{
	for (int i = column;i < blocks[row].size();i++) {
		int k = blocks[row][i];
		blocks[row2].push_back(k);
	}
	blocks[row].resize(column);

	//int k = blocks[row][column];
	//blocks[row2].push_back(k);
	//int x = column + 1;
	//blocks[row].resize(x);
}


//void block_number::moveall(int row,int column,int row2)
//{
//	for (int i = column;i < blocks[row].size();i++) {
//		int k = blocks[row][i];
//		blocks[row2].push_back(k);
//	}
//	blocks[row].resize(column);
//}

void block_number::location(int x,int& x_b,int& x_h)
{
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < blocks[i].size();j++) {
			if (blocks[i][j] == x) {
				x_b = i;
				x_h = j;
			}
		}
	}
}

void block_number::solve()
{
	std::string s1,s2;
	int num1, num2;
	init_block();
	while (std::cin >> s1 >> num1 >> s2 >> num2)
	{
		if (s1 == "quit")
			break;
		/*std::cout << s1 << std::endl;
		std::cout << num1 << std::endl;
		std::cout << s2 << std::endl;
		std::cout << num2 << std::endl;*/
		int num1_b = 0, num1_h = 0, num2_b = 0, num2_h;
		location(num1, num1_b, num1_h);
		location(num2, num2_b, num2_h);
		if (num1_b == num2_b)
			continue;
		/*if(s2=="onto")
			retain_original(num2_b, num2_h);
		if(s1=="move")
			retain_original(num1_b, num1_h);
		moveall(num1_b, num1_h, num2_b);*/
		if (s1 == "move") {
			if (s2 == "onto") {
				retain_original(num1_b, num1_h);
				retain_original(num2_b, num2_h);
				move(num1_b, num1_h, num2_b);
			/*	print();*/
			}
			if (s2 == "over") {
				retain_original(num1_b, num1_h);
				move(num1_b, num1_h, num2_b);
			}
		}
		if (s1 == "pile") {
			if (s2 == "onto") {
				retain_original(num2_b, num2_h);
				move(num1_b, num1_h, num2_b);
			}
			if (s2 == "over") {
				move(num1_b, num1_h, num2_b);
			}
		}
		//print();
	}
	std::cout << "Jump out loop" << std::endl;
	print();
}

void block_number::print() {
	for (int i = 0;i < n;i++) {
		std::cout << i <<" : ";
		for (int j = 0;j < blocks[i].size();j++) {
			std::cout << blocks[i][j]<<" ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	block_number bn;
	bn.solve();
}

