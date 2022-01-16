#include <stdio.h>
int main() {
  char op;
  int num1, num2;
  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &op);
  printf("Enter two operands: ");
  scanf("%d %d", &num1, &num2);

  switch (op) {
    case '+':
      printf("%d",num1 + num2);
      break;
    case '-':
      printf("%d", num1 - num2);
      break;
    case '*':
      printf("%d", num1 * num2);
      break;
    case '/':
      printf("%d", num1/num2);
      break;

    default:
      printf("operator is not correct");
  }

  return 0;
}

