/*
中缀表达式求值
*/

#include <stdio.h>;

int compare(char a, char b) {
	if (b == '(') return 1;
	else if ((b == '*' || b == '%' || b == '/') && (a == '+' || a == '/' || a == '(')) return 1;
	else if ((b == '+' || b == '-') && a == '(') return 1;
	return 0;
}

int isNum(char c) {
	return c >= '0'&&c <= '9';
}

// 转化为后缀表达式
void infix_to_suffix(char* infix, char* suffix) {
	int i, k, j = 0, top = -1;
	char stack[1000];
	char c;
	for (i = 0; infix[i] != '\0'; i++) {
		c = infix[i];
		if (isNum(c)) {
			suffix[j++] = c;
			continue;
		}
		if(i!=0 && isNum(infix[i-1])) {
			suffix[j++] = ' ';
		}
		if (top == -1 || compare(stack[top], c)) {
			stack[++top] = c;
		}
		else if (c == ')') {
			while (stack[top] != '(') {
				suffix[j++] = stack[top--];
				suffix[j++] = ' ';
			}
			top--;
		}
		else {
			while (!compare(stack[top], c) && top>=0) {
				suffix[j++] = stack[top--];
				suffix[j++] = ' ';
			}
			stack[++top] = c;
		}
	}
	if (suffix[j - 1] != ' ') {
		suffix[j++] = ' ';
	}
	while (top != -1) {
		suffix[j++] = stack[top--];
		suffix[j++] = ' ';
	}
	suffix[j] = '\0';
}

// 对后缀表达式求值
int suffix_value(char* suffix) {
	int stack[1000];
	int top = -1;
	char c;
	int value = 0;
	for (int i = 0; suffix[i] != '\0'; i++) {
		c = suffix[i];
		if (isNum(c)) {
			value = value * 10 + c - '0';
		}
		else if (c == ' ') {
			stack[++top] = value;
			value = 0;
		}
		else {
			switch (c)
			{
			case '+':
				value = stack[top-1] + stack[top];
				break;
			case '-':
				value = stack[top - 1] - stack[top];
				break;
			case '*':
				value = stack[top - 1] * stack[top];
				break;
			case '/':
				value = stack[top - 1] / stack[top];
				break;
			}
			top -= 2;
		}
	}
	return stack[0];
}

int main() {
	char infix[1000];
	char suffix[1000];
	int n = 5;
	while (n--) {
		gets(infix);
		printf("中表达式：%s\n", infix);
		infix_to_suffix(infix, suffix);
		printf("后缀表达式：%s\n", suffix);
		int result = suffix_value(suffix);
		printf("值：%d\n", result);
	}
	
}