#include <iostream>
using namespace std;
void filling(int*& nums, int i, int n, bool mode)
{
	if (mode) {
		if (i < n) {
			nums[i] = rand() % 201 - 100;
			i++;
			filling(nums, i, n, mode);
		}
	}
	else {
		if (i < n) {
			do { cin >> nums[i]; } while (nums[i] < -100 || nums[i]>100);
			cout << " writed...\n";
			i++;
			filling(nums, i, n, mode);
		}
	}
}
void extract(int* nums, int i, int n)
{
	if (i < n) {
		cout << nums[i] << ' ';
		i++;
		extract(nums, i, n);
	}
}
void sorting(int*& numb, int n)
{
	int i, j, k, x;
	for (i = 0; i < n; i++) {
		k = i;
		x = numb[i];
		for (j = i + 1; j < n; j++) {
			if (numb[j] < x) {
				k = j;
				x = numb[j];
			}
		}
		numb[k] = numb[i];
		numb[i] = x;
	}
}
int clearing(int*& numb, int n)
{
	int curr, help = 0;
	for (int i = 0; i < n - help; i++)
	{
		curr = numb[i];
		for (int j = i+1; j < n - help; j++)
		{
			if (curr == numb[j])
			{
				numb[j] = numb[n - help-1];
				numb[n - help-1] = curr;
				help++;
			}
		}
	}
	return help;
}
int main()
{
	int n, modeint;
	bool mode;
	do {
		cout << "Enter array size(1 - 30000): ";
		cin >> n;
	} while (n <= 0 || n >= 30000);
	int* nums = new int[n];
	srand(time(NULL));
	do {
		cout << "Choose mode (1 - autoentering, 0 - enterig by yourself): ";
		cin >> modeint;
	} while (modeint < 0 || modeint > 1);
	mode = modeint;
	filling(nums, 0, n, mode);
	sorting(nums, n);
	extract(nums, 0, n);
	cout << "\n";
	n = n - clearing(nums, n);
	sorting(nums, n);
	extract(nums, 0, n);
}