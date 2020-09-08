#include <bits/stdc++.h>
#define HASH_SIZE 1000
using namespace std;

struct Node {
        string key;
        int value;
        Node *next = nullptr;
        Node *prev = nullptr;
        bool active = false;
};
