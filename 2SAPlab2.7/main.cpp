#include <iostream>
#include <fstream>

using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};


void append(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void buildMatrixList(const char* filename, Node*& head) {
    ifstream file(filename);
    if (!file) {
        cerr << "File not found." << endl;
        return;
    }
    int rows, cols;
    file >> rows >> cols;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int val;
            file >> val;
            append(head, val);
        }
    }
    file.close();
}


void transposeMatrixList(Node* matrixList, Node*& transposedList, int rows, int cols) {
    for (int i = 0; i < cols; ++i) {
        Node* temp = matrixList;
        for (int j = 0; j < rows; ++j) {
            int index = j * cols + i;
            for (int k = 0; k < index; ++k)
                temp = temp->next;
            append(transposedList, temp->data);
            temp = matrixList;
        }
    }
}


void extractDiagonal(Node* matrixList, Node*& diagonalList, int rows, int cols) {
    Node* temp = matrixList;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == j)
                append(diagonalList, temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    Node* matrixList = nullptr;
    Node* transposedList = nullptr;
    Node* diagonalList = nullptr;

    
    buildMatrixList("matrix.txt", matrixList);

  
    cout << "Original Matrix List:" << endl;
    printList(matrixList);

    int rows = 3; 
    int cols = 3; 
   
    transposeMatrixList(matrixList, transposedList, rows, cols);

    
    cout << "Transposed Matrix List:" << endl;
    printList(transposedList);

    
    extractDiagonal(matrixList, diagonalList, rows, cols);

    
    cout << "Diagonal List:" << endl;
    printList(diagonalList);

    return 0;
}
