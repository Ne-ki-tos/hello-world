#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Row{
public:
	Row(int l = 0, double *v = nullptr){
		len = l;
		vector = v;
	}
	~Row(){}
	const double operator[](int i) const{
		if (i >= len)
			assert(!"index out of range");
		return vector[i];
	}
	double operator[](int i){
		if (i >= len)
			assert(!"index out of range");
		return vector[i];
	}
private:
	int len;
	double *vector;
};

class Matrix{
public:
	Matrix(int r, int c){
		rows = r;
		cols = c;
		matrix = new double[r*c];
	}
	~Matrix(){
		delete[] matrix;
	}
	const Row& operator[](int i) const{
		if (i >= rows)
			assert(!"index out of range");
		col = Row(cols, &matrix[i*cols]);
		return col;
	}
	Row& operator[](int i){
		if (i >= rows)
			assert(!"index out of range");
		col = Row(cols, &matrix[i*cols]);
		return col;
	}
private:
	int rows;
	int cols;
	double *matrix;
	mutable Row col;
};

int main(){
	
	return 0;
}