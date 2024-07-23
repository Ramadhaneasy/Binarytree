#include <iostream>
#include <string>
using namespace std;

// Struktur data node untuk binary tree
struct Node {
    int ticketNumber;
    string passengerName;
    Node* left;
    Node* right;
    Node* parent;

    Node(int num, string name) : ticketNumber(num), passengerName(name), left(NULL), right(NULL), parent(NULL) {}
};

// Variabel pointer global
Node* root = NULL;
Node* newNode = NULL;

// Membuat tree baru
void createNewTree(int ticketNumber, string passengerName) {
    if (root != NULL)
        cout << "\nTree sudah dibuat" << endl;
    else {
        root = new Node(ticketNumber, passengerName);
        cout << "\nPenumpang " << passengerName << " dengan tiket nomor " << ticketNumber << " berhasil menjadi root." << endl;
    }
}

// Menambah penumpang ke kiri
Node* insertLeft(int ticketNumber, string passengerName, Node* node) {
    if (root == NULL) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->ticketNumber << " sudah ada anak kiri!!" << endl;
            return NULL;
        } else {
            newNode = new Node(ticketNumber, passengerName);
            newNode->parent = node;
            node->left = newNode;
            cout << "\nPenumpang " << passengerName << " dengan tiket nomor " << ticketNumber << " berhasil ditambahkan ke anak kiri " << newNode->parent->ticketNumber << endl;
            return newNode;
        }
    }
}

// Menambah penumpang ke kanan
Node* insertRight(int ticketNumber, string passengerName, Node* node) {
    if (root == NULL) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->ticketNumber << " sudah ada anak kanan!!" << endl;
            return NULL;
        } else {
            newNode = new Node(ticketNumber, passengerName);
            newNode->parent = node;
            node->right = newNode;
            cout << "\nPenumpang " << passengerName << " dengan tiket nomor " << ticketNumber << " berhasil ditambahkan ke anak kanan " << newNode->parent->ticketNumber << endl;
            return newNode;
        }
    }
}

// Fungsi untuk menampilkan antrian (in-order traversal)
void displayQueue(Node* root) {
    if (root != NULL) {
        displayQueue(root->left);
        cout << "Ticket Number: " << root->ticketNumber << ", Passenger Name: " << root->passengerName << endl;
        displayQueue(root->right);
    }
}

// Fungsi untuk mencari node terkecil (digunakan untuk penghapusan node)
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Fungsi untuk menghapus penumpang dari antrian
Node* deletePassenger(Node* root, int ticketNumber) {
    if (root == NULL) {
        return root;
    }

    if (ticketNumber < root->ticketNumber) {
        root->left = deletePassenger(root->left, ticketNumber);
    } else if (ticketNumber > root->ticketNumber) {
        root->right = deletePassenger(root->right, ticketNumber);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->ticketNumber = temp->ticketNumber;
        root->passengerName = temp->passengerName;
        root->right = deletePassenger(root->right, temp->ticketNumber);
    }

    return root;
}

int main() {
    createNewTree(1, "Alice");

    Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft(2, "Bob", root);
    nodeC = insertRight(3, "Charlie", root);
    nodeD = insertLeft(4, "David", nodeB);
    nodeE = insertRight(5, "Eve", nodeB);
    nodeF = insertLeft(6, "Frank", nodeC);
    nodeG = insertLeft(7, "Grace", nodeE);
    nodeH = insertRight(8, "Hannah", nodeE);
    nodeI = insertLeft(9, "Ivy", nodeG);
    nodeJ = insertRight(10, "Jack", nodeG);

    cout << "\nCurrent Queue:" << endl;
    displayQueue(root);

    cout << "\nDeleting ticket number 3:" << endl;
    root = deletePassenger(root, 3);
    displayQueue(root);

    return 0;
}
