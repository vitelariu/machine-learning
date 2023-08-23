#include <iostream>
#include <ctime>

double train_data[][2] = {
	{0, 1},
	{1, 3},
	{2, 5},
	{3, 7},
	{4, 9},
	{5, 11},

};

#define train_size sizeof(train_data)/sizeof(train_data[0])



double cost(double a, double b, double c) {
	double result{};
	for(int i{}; i < train_size; i++) {
		double x = train_data[i][0];

		double y = a*x*x + b*x + c;

		double expected = train_data[i][1];
		double d = y - expected;
		result += d*d;
	}
	result /= train_size;

	return result;
}

int main() {
//	srand(time(0));
	srand(69);
	double a = (double) rand() / (double) RAND_MAX * 10;
	double b = (double) rand() / (double) RAND_MAX * 10;
	double c = (double) rand() / (double) RAND_MAX * 10;


	double eps = 1e-6;
	double rate = 1e-3;
	for(int i{}; i < 1000 * 100; i++) {	
		std::cout << "cost: " << cost(a, b, c) << ", a: " << a << ", b: " << b << ", c: " << c << '\n';

		double og = cost(a,b,c);

		double der_a = (cost(a + eps, b, c) - og) / eps;
		double der_b = (cost(a, b + eps,  c) - og) / eps;
		double der_c = (cost(a, b, c + eps) - og) / eps;
	

		a -= rate*der_a;
		b -= rate*der_b;
		c -= rate*der_c;



	}
	std::cout << "cost: " << cost(a, b, c) << ", a: " << a << ", b: " << b << ", c: " << c << '\n';


	std::cout << '\n';
	for(int i{}; i < train_size; i++) {
		std::cout << train_data[i][0] << "    " << train_data[i][1] << " -> ";
		std::cout << a*train_data[i][0]*train_data[i][0] + b*train_data[i][0] + c << '\n';
	}

	return 0;
}
