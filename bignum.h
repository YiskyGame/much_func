#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
// #include <string>
namespace much{
	class bignum {
	private:
		int len, s[450];
		void clean() { while (len > 1 && !s[len - 1]) len--; }
	public:
		bignum() { memset(s, 0, sizeof(s)); len = 1; }
		bignum(int num) { *this = num; }
		bignum(const char* num) { *this = num; }

		bignum operator = (int num) {
			char str[500];
			sprintf(str, "%d", num);
			*this = str;
			return *this;
		}
		bignum operator = (const char* num) {
			len = strlen(num);
			for (int i = 0; i < len; i++) s[i] = num[len - i - 1] - '0';
			return *this;
		}

		std::string to_str() const {
			std::string res = "";
			for (int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
			if (res == "") res = "0";
			return res;
		}

		int operator [](const int& i) {
			return s[len - 1 - i];
		}

		bignum operator +(const bignum& b) const {
			bignum c;
			c.len = 0;
			for (int i = 0, g = 0; g || i < std::max(len, b.len); i++) {
				int x = g;
				if (i < len) x += s[i];
				if (i < b.len) x += b.s[i];
				c.s[c.len++] = x % 10;
				g = x / 10;
			}
			return c;
		}
		bignum operator -(const bignum& b) {
			bignum c;
			c.len = 0;
			for (int i = 0, g = 0; i < len; i++) {
				int x = s[i] - g;
				if (i < b.len) x -= b.s[i];
				if (x >= 0) g = 0;
				else {
					g = 1;
					x += 10;
				}
				c.s[c.len++] = x;
			}
			c.clean();
			return c;
		}
		bignum operator *(const bignum& b) {
			bignum c;
			c.len = len + b.len;
			for (int i = 0; i < len; i++)
				for (int j = 0; j < b.len; j++)
					c.s[i + j] += s[i] * b.s[j];
			for (int i = 0; i < c.len - 1; i++) {
				c.s[i + 1] += c.s[i] / 10;
				c.s[i] %= 10;
			}
			c.clean();
			return c;
		}

		bool operator <(const bignum& b) const {
			if (len != b.len) return len < b.len;
			for (int i = len - 1; i >= 0; i--)
				if (s[i] != b.s[i]) return s[i] < b.s[i];
			return false;
		}
		bool operator >(const bignum& b) const { return b < *this; }

		bool operator <=(const bignum& b) { return !(b > *this); }
		bool operator >=(const bignum& b) { return !(b < *this); }
		bool operator ==(const bignum& b) { return !(b < *this) && !(*this < b); }

		bignum operator +=(const bignum& b) { *this = *this + b; return *this; }
		bignum operator -=(const bignum& b) { *this = *this - b; return *this; }
		bignum operator *=(const bignum& b) { *this = *this * b; return *this; }
	};

	std::istream& operator >> (std::istream& instr, bignum& x) {
		std::string s;
		instr >> s;
		x = s.c_str();
		return instr;
	}

	std::ostream& operator << (std::ostream& outstr, const bignum& x) {
		outstr << x.to_str();
		return outstr;
	}

	bignum big_fac(int num = 0) {
		bignum facn(1);
		for (int i = 2; i <= num; i++)
			facn *= bignum(i);
		return facn;
	}

	bignum big_pow(int n, int m = 0) {
		if (m == 0) return 1;
		bignum pown(1);
		for (int i = 1; i <= m; i++)
			pown *= bignum(n);
		return pown;
	}
}
