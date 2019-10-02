#include <stdint.h>

int bss_variable[10];

int fibo(int n) {
  if(n <= 1)
    return 1;

  return fibo(n-1)+fibo(n-2);
}

int main() {
	fibo(8);

	while(1);
	return 0;
}
