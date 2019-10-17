#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	int Last;
};

List ReadInput(); 
Position BinarySearch(List L, ElementType X);
Position recur(List L, ElementType x, int left, int right);
int main()
{
	List L;
	ElementType X;
	L = ReadInput();
	scanf("%d", &X);
	if (BinarySearch(L, X) == 0)printf("迭代二分实现没找到\n");
	else printf("迭代二分实现找到的位置：%d\n", BinarySearch(L, X));
	if (recur(L, X, 1, L->Last) == 0)printf("递归二分实现没找到\n");
	else printf("递归二分实现找到的位置：%d\n", recur(L, X, 1, L->Last));
	system("pause");
	return 0;
}
List ReadInput() {
	List p;
	int i, n,x;
	p = (List)malloc(sizeof(struct LNode));
	p->Last = 0;
	scanf("%d", &n);
	for (i = 1; i <=n; i++) {
		scanf("%d", &x);
		p->Data[i] = x;
		p->Last++;
	}
	return p;
}
Position BinarySearch(List L, ElementType X) {
	int left=1, right=L->Last;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (L->Data[mid] == X)return mid;
		else if (L->Data[mid] > X)right = mid - 1;
		else left = mid + 1;
	}
	return 0;
}
Position recur(List L, int x, int left, int right) {
	if (left <= right) {
		int mid = (left + right) / 2;
		if (L->Data[mid] == x)return mid;
		else if (L->Data[mid] > x) return recur(L, x, left, mid - 1);
		else return recur(L, x, mid + 1, right);
	}
	return 0;
}

