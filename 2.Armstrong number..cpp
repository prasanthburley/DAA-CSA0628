#include <stdio.h>
int main()
{
	int n,temp = n,sum = 0;
	printf("enter the number:");
	scanf("%d",&n);
	while (n > 0) {
		int r = n % 10;
		sum = (sum) + (r* r * r);
		n = n / 10;
	}
	if (temp == sum) {
		printf("It is Armstrong Number");
	}
	else {
		printf("It is not an Armstrong Number");
	}
	return 0;
}
