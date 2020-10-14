
typedef struct node_type{

	char* item; //the node's item
	struct node_type* next; //the node's next node
} Node;

typedef struct {

	Node* head; //the list's head node
	int size;
} List;


Node* make_node(char* data, Node* next);
List* make_list();
void free_node(Node* node);
void free_list(List* list);
void add_to_list(List* list, int index, char* data);
char* get(List* list, int index);
void set(List* list, int index, char* data);
