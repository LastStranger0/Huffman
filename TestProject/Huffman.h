#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <string>

using namespace std;

class Huffman
{
public:
	Huffman(string);
	class Node
	{
	public:
		Node();
		Node(Node*, Node*);
		int a;
		char c;
		Node* left;
		Node* right;
	};
	struct MyCompare
	{
		bool operator()(const Node*, const Node*) const;
	};
	vector<bool> code;
	map<char, vector<bool>> table;
	void BuildTable(Node*);
	void print(Node*, int);
	Node* root;
};
