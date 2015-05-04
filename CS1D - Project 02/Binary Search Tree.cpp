#include "Project 02.h"

bTree::bTree()
{
	root = NULL;
}


void bTree::insertStadium(stadiumNode *data)
{
	node *newNode;
	node *parent;

	// Allocates memory, puts data into field, and sets pointers to NULL
	newNode = new node;
	newNode->data.stadiumName = data->stadiumName;
	newNode->data.teamName = data->teamName;
	newNode->data.address1 = data->address1;
	newNode->data.address2 = data->address2;
	newNode->data.phone = data->phone;
	newNode->data.opening = data->opening;
	newNode->data.capacity = data->capacity;
	newNode->data.fieldType = data->fieldType;
	newNode->data.league = data->league;
	newNode->left = NULL;
	newNode->right = NULL;

	// This is now a blank pointer
	parent = NULL;

	// Checks to see if tree is empty and if it is sets it as the root
	if (root == NULL)
	{
		root = newNode;
	}
	// If the tree is not empty
	else
	{
		// Declares temp node and sets to root
		node *current;
		current = root;

		// While current != NULL
		while (current)
		{
			// Sets parent = current so we can compare down branches
			parent = current;

			// If data > than what is currently there
			if (newNode->data.stadiumName > current->data.stadiumName)
			{
				current = current->right;
			}
			// If data < what is currently there
			else
			{
				current = current->left;
			}
		}

		// Now that parent is pointing to the correct location we compare against
		// the incoming data and chooses the right or left tree
		if (newNode->data.stadiumName < parent->data.stadiumName)
		{
			parent->left = newNode;
		}
		else
		{
			parent->right = newNode;
		}
	}
}

void bTree::insertTeam(stadiumNode *data)
{
	node *newNode;
	node *parent;

	// Allocates memory, puts data into field, and sets pointers to NULL
	newNode = new node;
	newNode->data.stadiumName = data->stadiumName;
	newNode->data.teamName = data->teamName;
	newNode->data.address1 = data->address1;
	newNode->data.address2 = data->address2;
	newNode->data.phone = data->phone;
	newNode->data.opening = data->opening;
	newNode->data.capacity = data->capacity;
	newNode->data.fieldType = data->fieldType;
	newNode->data.league = data->league;
	newNode->left = NULL;
	newNode->right = NULL;

	// This is now a blank pointer
	parent = NULL;

	// Checks to see if tree is empty and if it is sets it as the root
	if (root == NULL)
	{
		root = newNode;
	}
	// If the tree is not empty
	else
	{
		// Declares temp node and sets to root
		node *current;
		current = root;

		// While current != NULL
		while (current)
		{
			// Sets parent = current so we can compare down branches
			parent = current;

			// If data > than what is currently there
			if (newNode->data.teamName > current->data.teamName)
			{
				current = current->right;
			}
			// If data < what is currently there
			else
			{
				current = current->left;
			}
		}

		// Now that parent is pointing to the correct location we compare against
		// the incoming data and chooses the right or left tree
		if (newNode->data.teamName < parent->data.teamName)
		{
			parent->left = newNode;
		}
		else
		{
			parent->right = newNode;
		}
	}
}

void bTree::insertCapacity(stadiumNode *data)
{
	node *newNode;
	node *parent;

	// Allocates memory, puts data into field, and sets pointers to NULL
	newNode = new node;
	newNode->data.stadiumName = data->stadiumName;
	newNode->data.teamName = data->teamName;
	newNode->data.address1 = data->address1;
	newNode->data.address2 = data->address2;
	newNode->data.phone = data->phone;
	newNode->data.opening = data->opening;
	newNode->data.capacity = data->capacity;
	newNode->data.fieldType = data->fieldType;
	newNode->data.league = data->league;
	newNode->left = NULL;
	newNode->right = NULL;

	// This is now a blank pointer
	parent = NULL;

	// Checks to see if tree is empty and if it is sets it as the root
	if (root == NULL)
	{
		root = newNode;
	}
	// If the tree is not empty
	else
	{
		// Declares temp node and sets to root
		node *current;
		current = root;

		// While current != NULL
		while (current)
		{
			// Sets parent = current so we can compare down branches
			parent = current;

			// If data > than what is currently there
			if (newNode->data.capacity > current->data.capacity)
			{
				current = current->right;
			}
			// If data < what is currently there
			else
			{
				current = current->left;
			}
		}

		// Now that parent is pointing to the correct location we compare against
		// the incoming data and chooses the right or left tree
		if (newNode->data.capacity < parent->data.capacity)
		{
			parent->left = newNode;
		}
		else
		{
			parent->right = newNode;
		}
	}
}

// Calls private method
void bTree::inorder()
{
	inorder(root);
}

// Inorder traversal outputting stadium names in alpha order
void bTree::inorder(node *tree)
{
	// Checks to see if the tree is empty
	if (tree != NULL)
	{
		// If it has a left child
		if (tree->left != NULL)
		{
			// Recursively scales down tree
			inorder(tree->left);
		}

		// Outputs the element
		cout << "STADIUM NAME: " << "\t\t"
			 << tree->data.stadiumName << endl;

		cout << "ADDRESS: " << "\t\t"
			 << tree->data.address1 << ", "
			 << tree->data.address2 << endl;

		cout << "PHONE: " << "\t\t\t"
			 << tree->data.phone << endl;

		cout << "DATE CONSTRUCTED: " << "\t"
			 << tree->data.opening << endl;

		cout << "SEATING CAPACITY: " << "\t"
			 << tree->data.capacity << endl;

		cout << "FIELD TYPE: " << "\t\t"
			 << (tree->data.fieldType == false ? "Grass" : "Astroturf" )
			 << endl;

		cout << "TEAM: " << "\t\t\t"
			 << tree->data.teamName << endl;

		cout << "LEAGUE: " << "\t\t"
			 << (tree->data.league == false ? "American" : "National")
			 << endl << endl;


		// If it has a right child
		if (tree->right != NULL)
		{
			// Recursively scales down the tree
			inorder(tree->right);
		}
	}
}
