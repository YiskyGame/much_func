#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
namespace much{
    // operator
    template<typename T>
    std::ostream& operator <<(std::ostream& outs, std::vector<T>& a) {
        for (auto x : a)
            outs << x << ' ';
        return outs;
    }

    template<typename T>
    std::istream& operator >>(std::istream& ins, std::vector<T>& a) {
        for (int i = 0; i < a.size(); i++)
            ins >> a[i];
        return ins;
    }
	// iofunc.h
	// 10_2
	template<typename T>
	void input_some(std::vector<T>& a, const int len) {
		for (int i = 0; i < len; i++) {
			T sth = input(sth);
			a.push_back(sth);
		}
	}

	// 11_2
	template<typename T>
	void output_some(std::vector<T>& a, const std::string Begin = "", const std::string end = " ", const std::string Lend = "\n") {
		for (T x : a)
			output(x, Begin, end);
		std::cout << Lend;
	}

	// 20_2
	template<typename T>
	void input_some_a_to_b(std::vector<T>& a, const int A, const int B) {
		for (int i = A; i <= B; ++i)
			input(a[i]);
	}

	// 21_2
	template<typename T>
	void output_some_a_to_b(std::vector<T>& a, const int A, const int B, const std::string Begin = "", const std::string end = " ", const std::string Lend = "\n") {
		for (int i = A; i <= B; ++i)
			output(a[i], Begin, end);
		std::cout << Lend;
	}


	// much_func.h
	// 5_2
	template<typename T>
	double avg(std::vector<T>& nums) {
		T sum = std::accumulate(nums.begin(), nums.end(), T(0));
		return static_cast<double>(sum) / nums.size();
	}

	// 9_2
	template<typename T>
	T sum_some(std::vector<T>& a) {
		return std::accumulate(a.begin(), a.end(), T(0));
	}

	// 12_2
	template<typename T>
	void n_to_some(std::vector<T>& a, const T n) {
		std::fill_n(a.begin(), a.size(), n);
	}

	// 16_2
	template<typename T>
	T nums_max(std::vector<T>& nums) {
		return *std::max_element(nums.begin(), nums.end());
	}

	// 17_2
	template<typename T>
	T nums_min(std::vector<T>& nums) {
		return *std::min_element(nums.begin(), nums.end());
	}

	// 22_2
	template<typename T>
	void run_to_some(std::vector<T>& a, const int step = 1) {
		for (int i = 0; i < a.size(); i += step)
			a[i] = i;
	}

	// 25_2
	template<typename T>
	void reverse_some(std::vector<T>& a) {
		std::reverse(a.begin(), a.end());
	}

	// 27_2
	//The return value is the number of sorting times.
	template<typename T>
	int bubble_sort(std::vector<T> nums, bool compare(T(a), T(b))) {
		int cnt = 0, len = nums.size();
		for(int j = 0; j < len; j++)
			for (int k = 0; k < len; k++)
				if(compare(nums[k], nums[k + 1])) {
					std::swap(nums[k],nums[k + 1]);
					cnt++;
				}
		return cnt;
	}

    // 33_2
	//Please call srand(time(NULL))
	template <typename T>
	void fill_random(std::vector<T>& nums, int len, long long max_rand) {
		for (int i = 0; i < len; i++)
			nums[i] = rand() % max_rand;
	}

	// 34
	template<typename T>
	std::vector<long long> vector_range(int len, int step = 1) {
		std::vector<long long> Range;
		long long num = 0;
		for (int i = 0; i < len; i++) {
			Range.push_back(num);
			num += step;
		}
		return Range;
	}
}
