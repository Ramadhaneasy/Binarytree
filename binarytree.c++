#include <iostream>
using namespace std;

// node
struct Node{
  int ticketNumber;
  Node *left, *right, *parent;
};

// variabel pointer global
Node *root, *newNode;

// create New Tree
void createNewTree( int ticketNumber )
{
  if( root != NULL )
    cout << "\nTree sudah dibuat" << endl;
  else{
    root = new Node();
    root->ticketNumber = ticketNumber;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\nNode " << ticketNumber << " berhasil dibuat menjadi root." << endl;
  }
}

// insert Left
Node *insertLeft( int ticketNumber, Node *node )
{
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->left != NULL ){
      // kalau ada
      cout << "\nNode "<< node->ticketNumber << " sudah ada anak kiri!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->ticketNumber = ticketNumber;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;
      cout << "\nNode " << ticketNumber << " berhasil ditambahkan ke anak kiri " << newNode->parent->ticketNumber << endl;
      return newNode;
    }
  }
}

// insert Right
Node *insertRight( int ticketNumber, Node *node )
{
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kanan ada atau tidak
    if( node->right != NULL ){
      // kalau ada
      cout << "\nNode " << node->ticketNumber << " sudah ada anak kanan!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->ticketNumber = ticketNumber;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->right = newNode;
      cout << "\nNode " << ticketNumber << " berhasil ditambahkan ke anak kanan " << newNode->parent->ticketNumber << endl;
      return newNode;
    }
  }
}

// Empty
bool empty()
{
  return root == NULL;
}

// update
void update(int ticketNumber, Node *node)
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ingin diganti tidak ada!!" << endl;
    else{
      int temp = node->ticketNumber;
      node->ticketNumber = ticketNumber;
      cout << "\nTicket number node " << temp << " berhasil diubah menjadi " << ticketNumber << endl;
    }
  }
}

// retrieve
void retrieve( Node *node )
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else{
      cout << "\nTicket number node : " << node->ticketNumber << endl;
    }
  }
}

// Find
void find( Node *node )
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else{
      cout << "\nTicket Number Node : " << node->ticketNumber << endl;
      cout << "Root Node : " << root->ticketNumber << endl;
      
      if( !node->parent )
        cout << "Parent Node : (tidak punya orang tua)" << endl;
      else
        cout << "Parent Node : " << node->parent->ticketNumber << endl;

      if( node->parent != NULL && node->parent->left != node && node->parent->right == node )
        cout << "Saudara : " << node->parent->left->ticketNumber << endl;
      else if( node->parent != NULL && node->parent->right != node && node->parent->left == node )
        cout << "Saudara : " << node->parent->right->ticketNumber << endl;
      else
        cout << "Saudara : (tidak punya saudara)" << endl;

      if( !node->left )
        cout << "Anak Kiri Node : (tidak punya anak kiri)" << endl;
      else
        cout << "Anak Kiri Node : " << node->left->ticketNumber << endl;

      if( !node->right )
        cout << "Anak Kanan Node : (tidak punya anak kanan)" << endl;
      else
        cout << "Anak Kanan Node : " << node->right->ticketNumber << endl;
    }
  }
}

// Traversal
// preOrder
void preOrder( Node *node = root )
{
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    if( node != NULL ){
      cout << node->ticketNumber << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }
}

// inOrder
void inOrder( Node *node = root )
{
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    if( node != NULL ){
      inOrder(node->left);
      cout << node->ticketNumber << ", ";
      inOrder(node->right);
    }
  }
}

// postOrder
void postOrder( Node *node = root )
{
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    if( node != NULL ){
      postOrder(node->left);
      postOrder(node->right);
      cout << node->ticketNumber << ", ";
    }
  }
}

// deleteTree
void deleteTree( Node *node )
{
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    if( node != NULL ){
      if( node != root ){
        node->parent->left = NULL;
        node->parent->right = NULL;
      }
      deleteTree(node->left);
      deleteTree(node->right);
      
      if( node == root ){
        delete root;
        root = NULL;
      }else{
        delete node;
      }
    }
  }
}

// delete Subtree
void deleteSub(Node *node){
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    deleteTree(node->left);
    deleteTree(node->right);
    cout << "\nSubtree node " << node->ticketNumber << " berhasil dihapus."  << endl;
  }
}

// clear
void clear(){
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    deleteTree(root);
    cout << "\nTree berhasil dihapus."  << endl;
  }
}

// size
int size(Node *node = root){
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return 0;
  }else{
    if( !node ){
      return 0;
    }else{
      return 1 + size( node->left ) + size(node->right);
    }
  }
}

// height
int height( Node *node = root )
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return 0;
  }else{
    if( !node ){
      return 0;
    }else{
      int heightKiri = height( node->left );
      int heightKanan = height( node->right );

      if( heightKiri >= heightKanan ){
        return heightKiri + 1;
      }else{
        return heightKanan + 1;
      }
    }
  }
}

// characteristic
void characteristic()
{
  cout << "\nSize Tree : " << size() << endl;
  cout << "Height Tree : " << height() << endl;
  cout << "Average Node of Tree : " << (size() / (height() ? height() : 1)) << endl;  // Avoid division by zero
}

int main()
{
  createNewTree(10);  // Root node ticket number

  Node *node20, *node30, *node40, *node50, *node60, *node70, *node80, *node90, *node100;

  node20 = insertLeft(20, root);
  node30 = insertRight(30, root);
  node40 = insertLeft(40, node20);
  node50 = insertRight(50, node20);
  node60 = insertLeft(60, node30);
  node70 = insertLeft(70, node50);
  node80 = insertRight(80, node50);
  node90 = insertLeft(90, node70);
  node100 = insertRight(100, node70);

  cout << "Tree empty? : " << empty() << endl;

  update(99, node30);
  update(30, node30);

  retrieve(node30);

  find(node30);

  cout << "\nPreOrder :" << endl;
  preOrder(node50);
  cout << "\n" << endl;
  cout << "InOrder :" << endl;
  inOrder(node50);
  cout << "\n" << endl;
  cout << "PostOrder :" << endl;
  postOrder(node50);
  cout << "\n" << endl;  

  characteristic();
  
  deleteSub(node50);
  cout << "\nPreOrder :" << endl;
  preOrder();
  cout << "\n" << endl;

  characteristic();
}
