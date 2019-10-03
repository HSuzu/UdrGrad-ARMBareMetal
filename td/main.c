#include <stdint.h>

int bss_variable[10];
int k;

int fibo(int n) {
  if(n <= 2)
    return 1;

  return fibo(n-1)+fibo(n-2);
}

int main() {
	k = fibo(8);

	while(1);
	return 0;
}
