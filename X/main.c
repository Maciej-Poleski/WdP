// Maciej Poleski
#ifndef DEBUG
#ifndef NDEBUG
#define NDEBUG
#endif
#define init(x,y)
#define end()
#define check(x)
#else
#include <stdio.h>
#include <stdlib.h>
void init(int argc, char **argv)
{
    if(argc != 3) {
        fprintf(stderr, "Potrzebne są dwa argumenty <wejście> <wyjście>\n");
        exit(1);
    }
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
}
void end(void)
{
}
#define check(x) assert(x)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <stdarg.h>
#include <math.h>

typedef struct node_t {
    char name[16];
    int value;
    int subtreeSize;
    struct node_t *left;
    struct node_t *right;
} Node;

Node *tree = NULL;

static void deleteTree(Node *node);
static inline void insert(const char *name, int value) __attribute__((nonnull));
static bool _insertInternal(Node **node) __attribute__((nonnull));
static inline void find(const char *name) __attribute__((nonnull));
static void _findInternal(const Node *node);
static inline void delete(const char *name) __attribute__((nonnull));
static bool _deleteInternal(Node **node) __attribute__((nonnull));
static inline int subtreeSize(const Node *node);
static int _lowerInternal(const Node *node);
static inline void lower(const char *name);
static int _upperInternal(const Node *node);
static inline void upper(const char *name);
static void print(const Node *node);

static void deleteTree(Node *node)
{
    if(node == NULL)
        return;
    Node *left = node->left;
    Node *right = node->right;
    free(node);
    deleteTree(left);
    deleteTree(right);
}

static const char *_insertInternal_name;
static int _insertInternal_value;

static bool _insertInternal(Node **node)
{
    if(*node == NULL) {
        *node = malloc(sizeof(Node));
        (*node)->left = NULL;
        (*node)->right = NULL;
        strcpy((*node)->name, _insertInternal_name);
        (*node)->subtreeSize = 1;
        (*node)->value = _insertInternal_value;
        return true;
    }
    int c = strcmp((*node)->name, _insertInternal_name);
    if(c == 0) {
        (*node)->value = _insertInternal_value;
        return false;
    } else if(c < 0) {
        if(_insertInternal(&((*node)->right))) {
            ++((*node)->subtreeSize);
            return true;
        } else {
            return false;
        }
    } else {
        if(_insertInternal(&((*node)->left))) {
            ++((*node)->subtreeSize);
            return true;
        } else {
            return false;
        }
    }
    check(false);
}

static inline void insert(const char *name, int value)
{
    _insertInternal_name = name;
    _insertInternal_value = value;
    _insertInternal(&tree);
}

static const char *_findInternal_name;

static void _findInternal(const Node *node)
{
    if(node == NULL) {
        printf("ERROR\n");
        return;
    }
    int c = strcmp(node->name, _findInternal_name);
    if(c == 0)
        printf("%d\n", node->value);
    else if(c < 0)
        _findInternal(node->right);
    else
        _findInternal(node->left);
}

static inline void find(const char *name)
{
    _findInternal_name = name;
    _findInternal(tree);
}

static inline int subtreeSize(const Node *node)
{
    if(node == NULL)
        return 0;
    return node->subtreeSize;
}

static const char *_deleteInternal_name;

static bool _deleteInternal(Node **node)
{
    if(*node == NULL) {
        printf("ERROR\n");
        return false;
    }
    int c = strcmp((*node)->name, _deleteInternal_name);
    if(c == 0) {
        printf("OK\n");
        check(node != NULL);
        check(*node != NULL);
        if((*node)->left == NULL) {
            Node *ptr = *node;
            *node = (*node)->right;
            free(ptr);
        } else if((*node)->right == NULL) {
            Node *ptr = *node;
            *node = (*node)->left;
            free(ptr);
        } else {
            Node **newInternalNode = &((*node)->left);
            while((*newInternalNode)->right != NULL) {
                --((*newInternalNode)->subtreeSize);
                newInternalNode = &((*newInternalNode)->right);
            }
            Node *selectedNode = *newInternalNode;
            *newInternalNode = (*newInternalNode)->left;
            Node *nodeToRemove = *node;
            *node = selectedNode;
            selectedNode->left = nodeToRemove->left;
            selectedNode->right = nodeToRemove->right;
            selectedNode->subtreeSize = subtreeSize(selectedNode->left) + subtreeSize(selectedNode->right) + 1;
            free(nodeToRemove);
        }
        return true;
    } else if(c < 0) {
        if(_deleteInternal(&((*node)->right))) {
            --((*node)->subtreeSize);
            return true;
        } else {
            return false;
        }
    } else {
        if(_deleteInternal(&((*node)->left))) {
            --((*node)->subtreeSize);
            return true;
        } else {
            return false;
        }
    }
    check(false);
}

static inline void delete(const char *name)
{
    _deleteInternal_name = name;
    _deleteInternal(&tree);
}

static const char *_lowerInternal_name;

static int _lowerInternal(const Node *node)
{
    if(node == NULL) {
        return -1;
    }
    int c = strcmp(node->name, _lowerInternal_name);
    if(c == 0)
        return subtreeSize(node->left);
    else if(c < 0) {
        int s = _lowerInternal(node->right);
        return s == -1 ? -1 : (s + subtreeSize(node->left)+1);
    } else
        return _lowerInternal(node->left);
}

static inline void lower(const char *name)
{
    _lowerInternal_name = name;
    int s = _lowerInternal(tree);
    printf(s == -1 ? "ERROR\n" : "%d\n", s);
}

static const char *_upperInternal_name;

static int _upperInternal(const Node *node)
{
    if(node == NULL) {
        return -1;
    }
    int c = strcmp(node->name, _upperInternal_name);
    if(c == 0)
        return subtreeSize(node->right);
    else if(c < 0) {
        return _upperInternal(node->right);
    } else {
        int s = _upperInternal(node->left);
        return s == -1 ? -1 : (s + subtreeSize(node->right)+1);
    }
}

static inline void upper(const char *name)
{
    _upperInternal_name = name;
    int s = _upperInternal(tree);
    printf(s == -1 ? "ERROR\n" : "%d\n", s);
}

static void print(const Node *node)
{
    if(node == NULL)
        return;
    print(node->left);
    printf("%s %d\n", node->name, node->value);
    print(node->right);
}

#ifdef DEBUG

static int checkTree(const Node *node);

#else

#define checkTree(x)

#endif

static inline void solution(void)
{
    int z;
    scanf("%d", &z);
    while(z--) {
        deleteTree(tree);
        tree = NULL;
        int n;
        scanf("%d", &n);
        while(n--) {
            char command[10];
            scanf("%s", command);
            if(*command == 'I') {
                check(strcmp(command, "INSERT") == 0);
                char name[16];
                int value;
                scanf("%s%d", name, &value);
                checkTree(tree);
                insert(name, value);
                checkTree(tree);
            } else if(*command == 'F') {
                check(strcmp(command, "FIND") == 0);
                char name[16];
                scanf("%s", name);
                checkTree(tree);
                find(name);
                checkTree(tree);
            } else if(*command == 'D') {
                check(strcmp(command, "DELETE") == 0);
                char name[16];
                scanf("%s", name);
                checkTree(tree);
                delete(name);
                checkTree(tree);
            } else if(*command == 'L') {
                check(strcmp(command, "LOWER") == 0);
                char name[16];
                scanf("%s", name);
                checkTree(tree);
                lower(name);
                checkTree(tree);
            } else if(*command == 'U') {
                check(strcmp(command, "UPPER") == 0);
                char name[16];
                scanf("%s", name);
                checkTree(tree);
                upper(name);
                checkTree(tree);
            } else {
                check(strcmp(command, "PRINT") == 0);
                checkTree(tree);
                print(tree);
                checkTree(tree);
            }
        }
    }
}

#ifdef DEBUG

static int checkTree(const Node *node)
{
    if(node == NULL)
        return 0;
    int w = checkTree(node->left) + checkTree(node->right) + 1;
    check(node->subtreeSize == w);
    return w;
}

static inline void checkAll(void)
{
}

#endif // DEBUG

int main(int argc, char **argv)
{
#ifdef DEBUG
    init(argc, argv);
    checkAll();
#endif // DEBUG
    solution();
#ifdef DEBUG
    end();
#endif // DEBUG
    return 0;
}

