#include <iostream>
#include <climits>
#include <cmath>

#define TIENDAS 10
#define SIZE 100

using namespace std;

int Distancia (int, int, int*, int*, int);
void Print (int [][SIZE], int, int);

int main (int argc, char const* argv[])
{
	int N, M, T;
	int x[TIENDAS], y[TIENDAS];
	int mapa[SIZE][SIZE];
	
	cin >> N >> M;
	cin >> T;
	
	for (int i = 0; i < T; i += 1) {
		cin >> x[i] >> y[i];
		mapa[x[i]][y[i]] = -1;
	}
	
	Print(mapa, N, M);
	
	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < M; j += 1) {
			if (mapa[i][j] != -1)
				mapa[i][j] = Distancia(i, j, x, y, T);
		}
	}
	
	Print(mapa, N, M);
	
	return 0;
}

int Distancia (int currentx, int currenty, int *x, int *y, int T){
	int minx = SIZE + 1, miny = SIZE + 1;
	int tempx, tempy;
	int distance;
	for (int i = 0; i < T; i += 1) {
		tempx = abs(currentx - x[i]);
		tempy = abs(currenty - y[i]);
		if ( (tempx + tempy) < (minx + miny) ) {
			minx = tempx;
			miny = tempy;
			distance = minx + miny;
		}
	}
	return distance;
}


void Print (int A[SIZE][SIZE], int N, int M) {
	cout << endl;
	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < M; j += 1) {
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}













