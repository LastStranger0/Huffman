#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>

using namespace std;

class Huffman
{
public:
	class Node
	{
	public:
		int a;
		char c;
		Node* left, * right;

		Node() { left = right = NULL; }

		Node(Node* L, Node* R)
		{
			left = L;
			right = R;
			a = L->a + R->a;
		}
	};


	struct MyCompare
	{
		bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
	};


	vector<bool> code;
	map<char, vector<bool> > table;

	void BuildTable(Node* root)
	{
		if (root->left != NULL)
		{
			code.push_back(0);
			BuildTable(root->left);
		}

		if (root->right != NULL)
		{
			code.push_back(1);
			BuildTable(root->right);
		}

		if (root->left == NULL && root->right == NULL) table[root->c] = code;


		if (!code.empty())
		{
			code.pop_back();
		}

	}

	void print(Node* root, int k = 0)
	{
		if (root != NULL)
		{
			print(root->right, k + 3);
			for (int i = 0; i < k; i++)
			{
				cout << " ";
			}
			if (root->c) cout << root->a << "(" << root->c << ")" << endl;
			else cout << root->a << endl;
			print(root->left, k + 3);
		}
	}
	Huffman(string);
	~Huffman();
	Node* root;
};

Huffman::Huffman(string s)
{
	map<char, int> m;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		m[c]++;
	}



	list<Node*> t;
	for (map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
	{
		Node* p = new Node;
		p->c = itr->first;
		p->a = itr->second;
		t.push_back(p);
	}


	//////  создаем дерево		

	while (t.size() != 1)
	{
		t.sort(MyCompare());

		Node* SonL = t.front();
		t.pop_front();
		Node* SonR = t.front();
		t.pop_front();

		Node* parent = new Node(SonL, SonR);
		t.push_back(parent);

	}

	Node* root = t.front();   //root - указатель на вершину дерева



	BuildTable(root);
	print(root);



	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		vector<bool> x = table[c];
		for (int n = 0; n < x.size(); n++)
			cout << x[n];
	}

}

Huffman::~Huffman() {

}

int main()
{
	string m;
	cin >> m;
	Huffman t(m);
}
