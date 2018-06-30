#ifndef INC_0X06_SORTED_ARRAY_TO_AVL_BINARY_TREES_H
#define INC_0X06_SORTED_ARRAY_TO_AVL_BINARY_TREES_H
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *tree);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *create_new_node(int data, avl_t *parent);
avl_t *array_to_avl_helper(int *array, int start, int finish, avl_t *parent);
avl_t *sorted_array_to_avl(int *array, size_t size);
#endif
