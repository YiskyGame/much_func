//much_func: I/O function.
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#define fastcinout ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
namespace much {
	// 6
	template<typename T>
	T input(T &sth) {
		std::cin >> sth;
		return sth;
	}

	// 7
	template<typename T>
	void output(const T sth, const std::string Begin = "", const std::string end = " ") {
		std::cout << Begin << sth << end;
	}

	// 8
	void digit_output(const double n, const int sp) {
		std::cout << std::fixed << std::setprecision(sp) << n;
	}

	// 10_1
	template<typename T>
	void input_some(T *a, const int len) {
		for (int i = 0; i < len; ++i)
			input(a[i]);
	}

	// 11_1
	template<typename T>
	void output_some(const T *a, const int len, const std::string Begin = "", const std::string end = " ", const std::string Lend = "\n") {
		for (int i = 0; i < len; ++i)
			output(a[i], Begin, end);
		std::cout << Lend;
	}

	// 15
	std::string input_stlstr(void) {
		std::string str;
		std::getline(std::cin, str);
		return str;
	}

	// 18_1
	void nextl(void) {
		putchar ('\n');
	}

	// 18_2
	void backl(void) {
		putchar ('\b');
	}

	// 20_1
	template<typename T>
	void input_some_a_to_b(T *a, const int A, const int B) {
		for (int i = A; i <= B; ++i)
			input(a[i]);
	}

	// 21
	template<typename T>
	void output_some_a_to_b(const T *a, const int A, const int B, const std::string Begin = "", const std::string end = " ", const std::string Lend = "\n") {
		for (int i = A; i <= B; ++i)
			output(a[i], Begin, end);
		std::cout << Lend;
	}

	// 34
	long long fast_read(long long &m) {
		long long f = 1, n = 0;
		char c = getchar();
		while (c < '0' || c >= '9') {
			if (c == '-') f = -1;
			c = getchar();
		}
		while ('0' <= c && c <= '9') {
			n = (n << 3) + (n << 1) + (c ^ 48);
			c = getchar();
		}
		m = n * f;
		return n * f;
	}

	// 35
	void fast_write(long long n) {
		if(n < 0) {
			putchar('-');
			n = -n;
		}
		if(n > 9) fast_write(n / 10);
		putchar(n % 10 + '0');
	}
}
