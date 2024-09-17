#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <numeric>
#include <vector>
#include "iofunc.h"
#include "bignum.h"

//--std=c++11, namespace much

namespace much {
#define V void
#define I_16 short
#define I_32 int
#define I_64 long long
#define _B bool
#define D double
#define C char
#define STR std::string
#define _T true
#define _F false
#define _R return
	
	const D math_PI = 3.1415926535;
	
	// The first one was deleted. Because of the "algorithm".
	// 1_2
	template<typename T>
	I_32 sth_len(const T *sth) {
		int len = 0;
		while (sth[len] != 0)
			len++;
		return len;
	}
	
	// 2
	template<typename T>
	_B is_prime(const T n) {
		if (n <= 1) _R _F;
		for (T i = 2; i * i <= n; ++i) {
			if (n % i == 0)
				_R _F;
		}
		_R _T;
	}
	
	// 3
	template<typename T>
	_B is_palindromes_num(T num) {
		T orig = num, rev = 0;
		while (num) {
			rev = rev * 10 + num % 10;
			num /= 10;
		}
		_R (rev == orig);
	}
	
	// 4
	I_64 fac(const I_32 n) {
		if (n > 20) _R LLONG_MIN;
		I_64 F = 1;
		for (I_32 i = 1; i <= n; ++i) F *= i;
		_R F;
	}
	
	// 5
	template<typename T>
	D avg(const T *nums, const I_32 len) {
		T sum = std::accumulate(nums, nums + len, T(0));
		_R static_cast<D>(sum) / len;
	}
	
	// 9
	template<typename T>
	T sum_some(const T *a, const I_32 len) {
		_R std::accumulate(a, a + len, T(0));
	}
	
	// 12
	template<typename T>
	V n_to_some(T *a, const T n, const I_32 len) {
		std::fill_n(a, len, n);
	}
	
	// 13_1
	template<typename T>
	V cstr_to_ascii(C *str, T *ascii, const I_32 len) {
		std::transform(str, str + len, ascii, [](C ch) { _R static_cast<I_32>(ch); });
	}
	
	// 13_2
	template<typename T>
	V stlstr_to_ascii(STR str, T *ascii, const I_32 len) {
		std::transform(str.begin(), str.begin() + len, ascii, [](C ch) { _R static_cast<I_32>(ch); });
	}
	
	// 14
	template<typename T>
	V bsome_to_asome(const T *b, T *a, const I_32 len) {
		std::copy(b, b + len, a);
	}
	
	// 16
	template<typename T>
	T nums_max(const T *nums, const I_32 len) {
		_R *std::max_element(nums, nums + len);
	}
	
	// 17
	template<typename T>
	T nums_min(const T *nums, const I_32 len) {
		_R *std::min_element(nums, nums + len);
	}
	
	// 19
	template<typename T>
	V n_to_some_a_to_b(T *a, const T n, const I_32 A, const I_32 B) {
		std::fill(a + A, a + B + 1, n);
	}
	
	// 22
	template<typename T>
	V run_to_some(T *a, const I_32 len, const I_32 step = 1) {
		for (I_32 i = 0; i < len; i += step)
			a[i] = i;
	}
	
	// 23
	template<typename T>
	V run_to_some_a_to_b(T *a, const I_32 A, const I_32 B, const I_32 step = 1) {
		I_32 j = 0;
		for (I_32 i = A; i <= B; i += step)
			a[i] = ++j;
	}
	
	// 24
	template<typename T>
	T reverse_sth(T &sth) {
		T rev = 0, n2 = sth;
		while (n2) {
			rev = rev * 10 + n2 % 10;
			n2 /= 10;
		}
		sth = rev;
		_R rev;
	}
	
	// 25
	template<typename T>
	V reverse_some(T *a, const I_32 len) {
		std::reverse(a, a + len);
	}
	
	// 26
	template<typename T>
	V bsome_to_asome_a_to_b(const T *b, T *a, const I_32 AA, const I_32 AB, const I_32 BA, const I_32 BB) {
		std::copy(b + BA, b + BB + 1, a + AA);
	}
	
	//27
	//The return value is the number of sorting times.
	template<typename T>
	I_32 bubble_sort(T *nums, const I_32 len, _B compare(T(a), T(b))) {
		I_32 cnt = 0;
		for(I_32 j = 0; j < len; j++) {
			for (I_32 k = 0; k < j; k++) {
				if(compare(nums[k], nums[k + 1])) {
					swap(nums[k],nums[k + 1]);
					cnt++;
				}
			}
		}
		_R cnt;
	}
	
	// 28
	STR cstr_to_stlstr(const char *cstr) {
		STR str(cstr);
		_R str;
	}
	
	// 29
	D circular_area(D r) {
		_R (math_PI * r * r);
	}
	
	// 30
	std::vector<I_64> vector_range(I_32 len, I_32 step = 1) {
		std::vector<I_64> Range;
		I_64 num = 0;
		for (I_32 i = 0; i < len; i++) {
			Range.push_back(num);
			num += step;
		}
		_R Range;
	}
	
	// 30
	I_64 fib(I_32 n) {
		I_64 a = 1, b = 1, c;
		if (n < 3) return a;
		for (I_32 i = 3; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		_R c;
	}
	
	// 31
	D circumference(D r) {
		_R (math_PI * 2 * r);
	}
	
	// 32, macro.
#define negation(BOOL_VAL) BOOL_VAL = !BOOL_VAL
	// 33_1
	template <typename T>
	//Please call srand(time(NULL))
	void fill_random(T *nums, I_32 len, I_64 max_rand) {
		for (I_32 i = 0; i < len; i++) 
			nums[i] = rand() % max_rand;
	} 
	
	// 33_2
	//Please call srand(time(NULL))
	template <typename T>
	void fill_random(std::vector<T>& nums, I_32 len, I_64 max_rand) {
		std::vector<T>().swap(nums);
		for (I_32 i = 0; i < len; i++)
			nums[i] = rand() % max_rand;
	} 
}


