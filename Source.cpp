#include<iostream>
#include<fstream>
using namespace std;
const int Max = 50;
struct matrix {
	int n;
	int list[Max][Max];
};
void nhapMang(matrix& x) {
	do {
		cout << "\n nhap ma tran : ";
		cin >> x.n;
	} while (x.n<=0||x.n>Max);
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j< x.n; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> x.list[i][j];
		}
		cout << endl;
	}
}
void xuatMang(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			cout << x.list[i][j]<<" ";
		}
		cout << endl;
	}
}
void read(matrix& x) {
	ifstream infile("text.txt");
	infile >> x.n;
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			infile >> x.list[i][j];
		}
	}
}
void ghifile(matrix& x) {
	ofstream outfile("text1.txt");
	outfile << x.n;
	cout << endl;
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			outfile<< x.list[i][j]<<" ";
		}
		cout << endl;
	}
}
void xuatCheoChinh(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (i == j) {
				cout << x.list[i][j] << "\t";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
}
void xuatCheoPhu(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (j == x.n-1-i) {
				cout << x.list[i][j] << "\t";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
}
void tamGiacPhaiDuoi(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (j <= i) {
				cout << x.list[i][j]<<"\t";
			}
		}
		cout << endl;
	}
}
void tamGiacTraiDuoi(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (j >= i) {
				cout << x.list[i][j] << "\t";
			}
		}
		cout << endl;
	}
}
void tamGiacTraiTren(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (i+j<=x.n-1) {
				cout << x.list[i][j] << "\t";
			}
		}
		cout << endl;
	}
}
void tamGiacPhaiTren(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (i + j >= x.n - 1) {
				cout << x.list[i][j] << "\t";
			}
		}
		cout << endl;
	}
}
void dongDauVsCotDau(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (i==0 || j == 0) {
				cout << x.list[i][j] << "\t";
			}
		}
		cout << endl;
	}
}
void dongCuoiVsCotCuoi(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (i == x.n-1 || j == x.n-1) {
				cout << x.list[i][j]<<" ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}
void songSongCheoChinh(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (i == j+1 || i == j+2|| i+1== j || i+2 == j) {
				cout << x.list[i][j] << " ";
			}
			else
				cout << "  ";
		}
		cout << endl;
	}
}
int tong1Dong(matrix x,int k) {
	int sum = 0;
	/*do {
		cout << "\n nhap vao so dong can tinh: ";
		cin >> k;
		if (k<0 || k>x.n)
			cout << "\n khong hop le";
	} while (k<0||k>x.n);*/
		for (int j = 0; j< x.n; j++) {
			sum += x.list[k][j];
		}
	return sum;
}
int tong1Cot(matrix x) {
	int k, sum = 0;
	do {
		cout << "\n nhap vao so cot can tinh: ";
		cin >> k;
		if (k<0 || k>x.n)
			cout << "\n khong hop le";
	} while (k<0 || k>x.n);
	for (int i = 0; i < x.n; i++) {
		sum += x.list[i][k];
	}
	return sum;
}
int DongLonNhat(matrix x) {
	int idx = 0, s = tong1Dong(x,0);
	int i = 1;
	while ( i < x.n) {
		for (int j = 0; j < x.n; j++) {
			int k = tong1Dong(x, i);
			if (k > s) {
				s = k;
				idx = i;
			}
		}
		i++;
	}
	return idx;
}
int dongNhieuSoChan(matrix x) {
	int i = 0, dem = 0,idx = 0;
	while (i < x.n) {
		int s = 0;
		for (int j = 0; j < x.n; j++) {
			if (x.list[i][j] % 2 == 0) {
				s += 1;
			}
		}
		if (s > dem) {
			dem = s;
			idx = i;
		}
		i++;
	}
	return idx;
}
int cotNhieuSoChan(matrix x) {
	int j = 0, dem = 0, idx = 0;
	while (j < x.n) {
		int s = 0;
		for (int i = 0; i < x.n; i++) {
			if (x.list[i][j] % 2 == 0) {
				s += 1;
			}
		}
		if (s > dem) {
			dem = s;
			idx = j;
		}
		j++;
	}
	return idx;
}
bool tangDan(matrix x,int k) {
		for (int j = 0; j < x.n-1; j++) {
			if (x.list[k][j] > x.list[k][j + 1]) {
				return false;
			}
	}
	return true;
}
int demDongTangDan1(matrix x) {
	int i = 0,dem = 0;
	while (i < x.n) {
		if (tangDan(x, i) == true) {
			dem++;
		}
		i++;
	}
	return dem;
}
int demDongTangDan(matrix x) {
	int i = 0, dem = 0;
	while (i < x.n) {
		bool isTangDan = true;
		for (int j = 0; j < x.n - 1; j++) {
			if (x.list[i][j] > x.list[i][j + 1]) {
				isTangDan = false;
				break;
			}
		}
		if (isTangDan) {
			dem++;
		}
		i++;
	}
	return dem;
}
void dongCotGiua(matrix x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.n; j++) {
			if (i == x.n / 2 || j == x.n/2) {
				cout << x.list[i][j]<<" ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}
int cotCuoiNhieuChan(matrix x) {
	int idx = -1, s1 = 0;
	int j = 0;
	while (j < x.n) {
		int s = 0;
		for (int i = 0; i < x.n; i++) {
			if (x.list[i][j] % 2 == 0) {
				s++;
			}
		}
		if (s > s1) {
			s1 = s;
			idx = j;
		}
		j++;
	}
	return idx;
}
int main() {
	matrix a;
	int k;
	/*nhapMang(a);*/
	read(a);
	/*do {
		cout << "\n nhap vao so dong can tinh: ";
		cin >> k;
		if (k<0 || k>Max)
			cout << "\n khong hop le";
	} while (k<0||k>Max);*/
	//xuatCheoChinh(a);
	//cout << endl;
	//xuatCheoPhu(a);
	//cout << endl;
	//tamGiacPhaiTren(a);
	///*nhapMang(a);
	xuatMang(a);
	/*ghifile(a);*/
	/*cout << endl;
	dongCuoiVsCotCuoi(a);
	cout << endl;
	songSongCheoChinh(a);*/
	/*cout << "\n tong dong la: " << tong1Dong(a,k);
	cout << "\n tong cot la: " << tong1Cot(a);*/
	/*cout << "\n dong co tong lon nhat la: "<<DongLonNhat(a);
	cout << "\n tong la: " << tong1Dong(a, DongLonNhat(a));*/
	/*cout << "\n dong co nhieu so chan nhat la: " << dongNhieuSoChan(a);
	cout << "\n cot co nhieu so chan nhat la: " << cotNhieuSoChan(a);*/
	/*dongCotGiua(a);*/
	cout << "\n cot co nhieu so chan nhat: " << cotCuoiNhieuChan(a);
	return 0;
}