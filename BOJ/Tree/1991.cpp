#include <cstdio>

typedef struct {
	char left;
	char right;
} node;
node tree[27];

void preorder(char node) {
	if (node == '.') return;
	printf("%c", node);

	preorder(tree[node].left);
	preorder(tree[node].right);
}

void inorder(char node) {
	if (node == '.') return;
	
	inorder(tree[node].left);
	printf("%c", node);
	inorder(tree[node].right);
}

void postorder(char node) {
	if (node == '.') return;

	postorder(tree[node].left);
	postorder(tree[node].right);
	printf("%c", node);
}

int main() {
	int n;
	scanf("%d", &n);
	char root, l, r; // root, left, right
	for (int i = 0; i < n; i++) {
		scanf(" %1c %1c %1c", &root, &l, &r);
		tree[root].left = l;
		tree[root].right = r;
	}

	preorder('A'); // 전위순회 (루트 -> 왼 -> 오)
	printf("\n");
	inorder('A'); // 중위순회 (왼 -> 루트 -> 오)
	printf("\n");
	postorder('A'); // 후위순회 (왼 -> 오 -> 루트)
	printf("\n");

	return 0;
}
