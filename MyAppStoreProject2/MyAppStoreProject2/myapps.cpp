#include"defn.h"
#include<iostream>
#include<string.h>
#include<fstream>
#include<string>
using namespace std;

void main() {
	int categories_number = -1;
	cin >> categories_number;
	categories* category_type = new categories[categories_number];
	bst* bst_category = new bst[categories_number];
	
	for (int i = 0; i < categories_number; i++)
	{
		cin >> category_type[i].category;
		category_type[i].root = &bst_category[i];
	}

	int numOfApps = -1;
	char currentCategory[25];
	cin >> numOfApps;
	cin >> currentCategory;

	for (int j = 0; j < numOfApps; j++)
	{
		for (int i = 0; i < categories_number; i++)
		{
			//fill in bst
			if (strcmp(currentCategory, category_type[i].category) == 0) //check if the cin is one of the current categories
			{
				if (category_type[i].root->record.category == NULL)//root of bst; number 0
				{
					strncpy(category_type[i].root->record.category, currentCategory, 25);
					cin >> category_type[i].root->record.app_name;
					cin >> category_type[i].root->record.version;
					cin >> category_type[i].root->record.size;
					cin >> category_type[i].root->record.units;
					cin >> category_type[i].root->record.price;
				}
				else if (category_type[i].root->left->record.category == NULL) {//1st leaf of root; left of root; number 1
					strncpy(category_type[i].root->left->record.category, currentCategory, 25);
					cin >> category_type[i].root->left->record.app_name;
					cin >> category_type[i].root->left->record.version;
					cin >> category_type[i].root->left->record.size;
					cin >> category_type[i].root->left->record.units;
					cin >> category_type[i].root->left->record.price;
				}
				else if (category_type[i].root->right->record.category == NULL) {//2nd leaf of root; right of root; number 2
					strncpy(category_type[i].root->right->record.category, currentCategory, 25);
					cin >> category_type[i].root->right->record.app_name;
					cin >> category_type[i].root->right->record.version;
					cin >> category_type[i].root->right->record.size;
					cin >> category_type[i].root->right->record.units;
					cin >> category_type[i].root->right->record.price;
				}
				else if (category_type[i].root->left->left->record.category == NULL) { //left of 1st leaf; number 3
					strncpy(category_type[i].root->left->left->record.category, currentCategory, 25);
					cin >> category_type[i].root->left->left->record.app_name;
					cin >> category_type[i].root->left->left->record.version;
					cin >> category_type[i].root->left->left->record.size;
					cin >> category_type[i].root->left->left->record.units;
					cin >> category_type[i].root->left->left->record.price;
				}
				else if (category_type[i].root->left->right->record.category == NULL) {//right of 1st leaf; number 4
					strncpy(category_type[i].root->left->right->record.category, currentCategory, 25);
					cin >> category_type[i].root->left->right->record.app_name;
					cin >> category_type[i].root->left->right->record.version;
					cin >> category_type[i].root->left->right->record.size;
					cin >> category_type[i].root->left->right->record.units;
					cin >> category_type[i].root->left->right->record.price;
				}
			}
			else if (category_type[i].root->right->left->record.category == NULL) {//left of 2nd leaf; number 5
				strncpy(category_type[i].root->right->left->record.category, currentCategory, 25);
				cin >> category_type[i].root->right->left->record.app_name;
				cin >> category_type[i].root->right->left->record.version;
				cin >> category_type[i].root->right->left->record.size;
				cin >> category_type[i].root->right->left->record.units;
				cin >> category_type[i].root->right->left->record.price;
			}
				else if (category_type[i].root->right->right->record.category == NULL) {//right of 2nd leaf; number 6
					strncpy(category_type[i].root->right->right->record.category, currentCategory, 25);
					cin >> category_type[i].root->right->right->record.app_name;
					cin >> category_type[i].root->right->right->record.version;
					cin >> category_type[i].root->right->right->record.size;
					cin >> category_type[i].root->right->right->record.units;
					cin >> category_type[i].root->right->right->record.price;
				}
		}
		cin >> currentCategory;
	}


	int NumOfQueries = -1;
	string query;
	string delimiter = " ";
	int pos = 0;
	string token;
	cin >> NumOfQueries;

	for (int i = 0; i < NumOfQueries; i++)
	{
		std::string array[6];
		int stringPos = 0;
		int result = 0;
		cin >> query;
		while ((pos = query.find(delimiter)) != std::string::npos)//splits string
		{
			token = query.substr(0, pos);
			array[stringPos] = token;
			stringPos++;
			query.erase(0, pos + delimiter.length());
		}
	
		if (array[0].compare("print-apps") == 0)
		{
			strcpy(currentCategory,  array[2].c_str());
			for (int c = 0; c <= categories_number; c++)
			{
				if (c==categories_number) {//checks if category exists
					cout << "Category not found";
					break;
				}

				if (category_type[i].root->record.category == NULL)//checks if the bst is filled
				{
					cout << "Category: " << currentCategory << " no apps found";
				}
				else if (strcmp(currentCategory, category_type[i].category) == 0) //check if the currentcategory is one of the current categories
				{
					if (category_type[i].root->record.category != NULL)//root of bst; number 0
					{
						cout << endl;
						cout << category_type[i].root->record.category << endl;
						cout << category_type[i].root->record.app_name << endl;
						cout << category_type[i].root->record.version << endl;
						cout << category_type[i].root->record.size << endl;
						cout << category_type[i].root->record.units << endl;
						cout << category_type[i].root->record.price << endl;
						cout << endl;
						
					}
					else if (category_type[i].root->left->record.category != NULL) {//1st leaf of root; left of root; number 1
						cout << category_type[i].root->left->record.category << endl;
						cout << category_type[i].root->left->record.app_name << endl;
						cout << category_type[i].root->left->record.version << endl;
						cout << category_type[i].root->left->record.size << endl;
						cout << category_type[i].root->left->record.units << endl;
						cout << category_type[i].root->left->record.price << endl;
						cout << endl;
					}
					else if (category_type[i].root->right->record.category != NULL) {//2nd leaf of root; right of root; number 2
						cout << category_type[i].root->right->record.category << endl;
						cout << category_type[i].root->right->record.app_name << endl;
						cout << category_type[i].root->right->record.version << endl;
						cout << category_type[i].root->right->record.size << endl;
						cout << category_type[i].root->right->record.units << endl;
						cout << category_type[i].root->right->record.price << endl;
						cout << endl;
					}
					else if (category_type[i].root->left->left->record.category != NULL) { //left of 1st leaf; number 3
						cout << category_type[i].root->left->left->record.category << endl;
						cout << category_type[i].root->left->left->record.app_name << endl;
						cout << category_type[i].root->left->left->record.version << endl;
						cout << category_type[i].root->left->left->record.size << endl;
						cout << category_type[i].root->left->left->record.units << endl;
						cout << category_type[i].root->left->left->record.price << endl;
						cout << endl;
					}
					else if (category_type[i].root->left->right->record.category != NULL) {//right of 1st leaf; number 4
						cout << category_type[i].root->left->right->record.category << endl;
						cout << category_type[i].root->left->right->record.app_name << endl;
						cout << category_type[i].root->left->right->record.version << endl;
						cout << category_type[i].root->left->right->record.size << endl;
						cout << category_type[i].root->left->right->record.units << endl;
						cout << category_type[i].root->left->right->record.price << endl;
						cout << endl;
					}
				}
				else if (category_type[i].root->right->left->record.category != NULL) {//left of 2nd leaf; number 5
					cout << category_type[i].root->right->left->record.category << endl;
					cout << category_type[i].root->right->left->record.app_name << endl;
					cout << category_type[i].root->right->left->record.version << endl;
					cout << category_type[i].root->right->left->record.size << endl;
					cout << category_type[i].root->right->left->record.units << endl;
					cout << category_type[i].root->right->left->record.price << endl;
					cout << endl;
				}
				else if (category_type[i].root->right->right->record.category != NULL) {//right of 2nd leaf; number 6
					cout << category_type[i].root->right->right->record.category << endl;
					cout << category_type[i].root->right->right->record.app_name << endl;
					cout << category_type[i].root->right->right->record.version << endl;
					cout << category_type[i].root->right->right->record.size << endl;
					cout << category_type[i].root->right->right->record.units << endl;
					cout << category_type[i].root->right->right->record.price << endl;
					cout << endl;
				}

			}
		}

	}

}