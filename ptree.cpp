#include <iostream>
using namespace std;

struct node {
	node* next[26];
	int strings;
	node() {
		for (int i = 0; i < 26; i++) {
			next[i] = nullptr;
		}
		strings = 0;
	}
};

node* root = new node();

void add(const string& s) {
	node* cur_v = root;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if (cur_v->next[c - 'a'] == nullptr) {
			cur_v->next[c - 'a'] = new node();
		}

		cur_v = cur_v->next[c - 'a'];
	}

	cur_v->strings++;
}

bool has(const string& s) {
	node* cur_v = root;

	for (int i = 0; i < s.length(); i++) {
		cur_v = cur_v->next[s[i] - 'a'];
		if (cur_v == nullptr) {
			return false;
		}
	}

	return cur_v->strings > 0;
}

string cur_str = "";

void write(node* v = root) {
	for (int i = 0; i < v->strings; i++) {
		cout << cur_str << endl;
	}

	for (int i = 0; i < 26; i++) {
		if (v->next[i] != nullptr) {
			cur_str.push_back('a' + i);
			write(v->next[i]);
			cur_str.pop_back();
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int n;
	cout << "Введите количество слов, которые нужно добавить в префиксное дерево: ";
	cin >> n;
	cout << endl;
	cout << "Вводите слова по порядку:" << endl;
	string word;
	for (size_t i = 0; i < n; i++) {
		cin >> word;
		add(word);
	}
	cout << endl;
	cout << "----------------------------------------------------";
	cout << endl << endl;
	cout << "Вывод всех слов в отсортированном порядке префиксного дерева при помощи DFS:" << endl;
	write(root);
}

