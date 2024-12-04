#ifndef _BST_H
#define _BST_H

#include <time.h>
#include <stdio.h>
#include <stdint.h>

#include "../helperFuncs.h"

/**
 * @brief stores the time, temperature, and humidity data stored in each node
 */
struct temp_humid_data {
time_t timestamp;
uint32_t temp;
uint32_t humid;
};


/**
 * @brief A binary search tree that stores temperate and humidity data
 * and the time at which the sample was taken
 */
struct node {
   struct temp_humid_data data; 
   struct node *left;
   struct node *right;
};

/**
 * @brief A sudo class that holds the root of the tree and pointers
 * to BST tree functions that perform operations on the specific BST instance
 */
struct BST {
    struct node* root;
    void (*insert)(struct BST* bst, struct temp_humid_data);   
    struct node* (*search)(struct node* node, time_t time);   
    void (*displayTree)(struct node* node);  
};


/**
 * @brief Given a date, populates the passed in BST with the next 30 days
 * of temperature and humidity data
 *
 * @param root a pointer to the root node of the BST
 * @param data a temp_humid_data struct that holds the sample data for the node
 * that will be inserted into the binary search tree
 */
//static void insert(struct node* root, struct temp_humid_data data);

/**
 * @brief Given a date, populates the passed in BST with the next 30 days
 * of temperature and humidity data
 *
 * @param root a pointer to the root node of the BST
 * @param date a char pointer to the date string
 */
//static struct node* search(struct node* root, char* date);

/**
 * @brief Prints the data contained within a node
 *
 * @param node a pointer to the node of the BST that will be displayed
 */
//static void displayNode(struct node* node);

/**
 * @brief traverses the BST in an inorder traversal and prints the data stored at each node
 * 
 * @param root a pointer to the root node of the BST
 */
//static void displayTree(struct node* root);


/**
 * @brief creates a new instance of a BST and sets up the function pointers for the BST
 */
struct BST* createBST();

#endif // _BST_H