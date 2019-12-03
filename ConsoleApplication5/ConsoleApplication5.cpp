#include <iostream>
using namespace std;

int Partition(int Arr[], int Left, int Right)
{
	// 맨 첫번째의 인덱스를 피봇으로 하는 구현....
	// 내림차순 정렬 ( 우선순위가 큰 값의 인덱스가 작아야함 )
	// Low 는 Low 인덱스의 값이 피봇보다 큰 동안 루프를 돌면서 증가연산을 하고
	// 작은 값을 만나는 순간 탈출합니다. 
	int Pivot = Left;
	int Low = Left + 1;
	int High = Right;
	if(Left<=Right)
	{
		while ( Low <= High)
		{
			while (Arr[Low] >= Pivot && Low <= Right) Low++;

			while (Arr[High] <= Pivot && High>=(Left +1)) High--;

			if (Low <= High)
				std::swap(Arr[Low], Arr[High]);
		}
		std::swap(Arr[Pivot], Arr[High]);
		Pivot = High;
		return Pivot;
	}
};
void QuickSort(int Arr[], int Left, int Right)
{
	if (Left <= Right)
	{		
		int Pivot = Partition(Arr, Left, Right);
		QuickSort(Arr, Left, Pivot - 1);
		QuickSort(Arr, Pivot+1 , Right);
	}
};

int main()
{
	int Arr[] = { 3,5,7,12,56,8,9,1234,125,215,6312,643,745 };
	for(auto&E:Arr)
	{
		cout << E << endl;
		
	}
	QuickSort(Arr, 0,13);
	cout << endl << endl;
	for (auto& E : Arr)
	{
		cout << E << endl;

	}
}