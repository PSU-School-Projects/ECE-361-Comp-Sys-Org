#include "BST.h"



/**
 * @brief Given a date, populates the passed in BST with the next 30 days
 * of temperature and humidity data
 *
 * @param root a pointer to the root node of the BST
 * @param data a temp_humid_data struct that holds the sample data for the node
 * that will be inserted into the binary search tree
 */
static void insert(struct BST* bst, struct temp_humid_data data) {
    // checks if the root exists, if not insert the node as the root node
    if (bst->root == NULL) {
        bst->root = malloc(sizeof(struct node));
        *(bst->root) = (struct node){.data=data, .left = NULL, .right = NULL};
    }
    else {
        struct node* current = bst->root;
        /* If current node value is greater than the time of the data navigate to the left node
        if it's less than navigate to the right node until the node you want to navigate to is NULL
        then set the node you want to navigate to to a node containing the data.
        */
        while (true) {
            if (current->data.timestamp > data.timestamp) {
                if (current->left != NULL) current = current->left;
                else {
                    current->left = malloc(sizeof(struct node));
                    *(current->left) = (struct node){.data=data, .left=NULL, .right=NULL};
                    break;
                }
            }
            else {
                if (current->right != NULL) current = current->right;
                else {
                    current->right = malloc(sizeof(struct node));
                    *(current->right) = (struct node){.data=data, .left=NULL, .right=NULL};
                    break;
                }
            }
        }
    }
}


/**
 * @brief Given a date, populates the passed in BST with the next 30 days
 * of temperature and humidity data
 *
 * @param root a pointer to the root node of the BST
 * @param date a char pointer to the date string
 */
static struct node* search(struct node* node, time_t time) {
    int matchRange = 86400-1; // if a time is found that is within a day in the future it counts as a match
    if (node == NULL) { // Invallid node pass in
        fprintf(stderr, "ERROR[search]: Tried to search NULL node.");
    }
    else {
        while (true) {
            // if the timestamp is a match or is within an acceptable range
            if (node->data.timestamp == time || 
            (node->data.timestamp > time && node->data.timestamp - matchRange < time)) {
                long int timestamp = node->data.timestamp;
                float temp = node->data.temp;
                float humid = node->data.humid;
                char date_str[MAX_DATE_STR_SIZE] = {"\0"}; //string to display the date later
                epoch_to_date(timestamp, date_str);
                printf("Found: %s, Temperature: %3.1fF, Relative Humidity: %3.1f%%\n",
                    date_str, temp, humid);
                return node;
            }
            // If the valid node check failed and both children are NULL then the time doesn't exist in the tree
            else if (node->left == NULL && node->right == NULL) {
                char date[MAX_DATE_STR_SIZE];
                epoch_to_date(time, date);
                printf("Could not find entry for %s", date);
                return NULL;
            }
            //Navigate left as values less than the current node are stored to the left of the node
            else if (node->left != NULL && node->data.timestamp > time) node = node->left;
            // Navigate left as values greater than the current node are stored to the right of the node
            else if (node->data.timestamp <= time) node = node->right;
            // if the right node is null but the left isn't this last case can trigger
            // Which means it's looking for a value greater than the current node but there are none in the tree
            else {
                char date[MAX_DATE_STR_SIZE];
                epoch_to_date(time, date);
                printf("Could not find entry for %s", date);
                return NULL;
            }
        }
    }
    char date[MAX_DATE_STR_SIZE];
    epoch_to_date(time, date);
    printf("Could not find entry for %s", date);
    return NULL;
}


/**
 * @brief Prints the data contained within a node
 *
 * @param node a pointer to the node of the BST that will be displayed
 */
static void displayNode(struct node* node) {
    // extracts the data from the node into a more print friendly form and prints it
    long int timestamp = node->data.timestamp;
    float temp = node->data.temp;
    float humid = node->data.humid;
    char date_str[MAX_DATE_STR_SIZE] = {"\0"}; //string to display the date later
    epoch_to_date(timestamp, date_str);
    printf("Time: %s, Temperature: %3.1fF, Relative Humidity: %3.1f%%\n",
               date_str, temp, humid);
}

/**
 * @brief traverses the BST in an inorder traversal and prints the data stored at each node
 * 
 * @param root a pointer to the root node of the BST
 */
static void displayTree(struct node* node) {
    if (node == NULL) {
        printf("Root Node is NULL");
        return;
    }
    // if the left child is not NULL recurse into it and it becomes the current node in that scope
    // this will display the epochs smaller than the current node's first
    if(node->left != NULL) displayTree(node->left);
    // display the current node
    displayNode(node);
    // recurse into the right side to display nodes with epochs greater than the current
    if (node->right != NULL) displayTree(node->right);
}

/**
 * @brief creates a new instance of a BST and sets up the function pointers for the BST
 */
struct BST* createBST() {
    struct BST* bst = (struct BST*)malloc(sizeof(struct BST));
    bst->insert = insert;
    bst->search = search;
    bst->displayTree = displayTree;

    return bst;
}