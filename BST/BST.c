#include <stdio.h>
#include <stdlib.h>


struct node {
	struct node *parent;
	struct node *left;
	struct node *right;
	int val;
};

void add_node(struct node *parent, int val);
struct node *mk_node(struct node * parent,int val);
void balance_tree(struct node *root, int val);
struct node *find_node(struct node *current_node, int val);

struct node root = {
	NULL,
	NULL,
	NULL,
	0
};

struct node * mk_node(struct node * parent, int val){
	struct node *new_node = malloc(sizeof(struct node));
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->val = val;
	return new_node;
}

void add_node(struct node *parent, int val){
	if (val > parent->val){
		if (parent->right == NULL)
			parent->right = mk_node(parent,val);
		add_node(parent->right, val);
	}
	else if (val < parent->val){
		if (parent->left == NULL)
			parent->left = mk_node(parent,val);
		add_node(parent->left, val);
	}	
};

struct node *find_node(struct node * current_node, int val){
	if (current_node == NULL)
		return NULL;
	if (val > current_node->val)
		return find_node(current_node->right, val);
	else if (val < current_node->val)
		return find_node(current_node->left, val);
	else if (val == current_node->val)
		return current_node;
};


int main(){
	root.val = 5;
	add_node(&root,5);
	add_node(&root, 7);
	add_node(&root, 1);
	add_node(&root, 3);
	struct node *result_node;
	result_node = find_node(&root, 3);
	printf ("Выполнен поиск ноды со значением 3, содержимое ноды %d\n", result_node->val);
	result_node = find_node(&root, 4);
	if (result_node == NULL)
		printf("Нода со значением  1 не найдена\n");
}

