#include<iostream>
#include<vector>
using namespace std;

// using ll = long long;

//tao class Node
class Node{
private:
	int  value;
	Node* left;
	Node* right;
    Node* parent;
public:
    //constructor:
   Node() {
      left = nullptr;
      right = nullptr;
      parent = nullptr;
	};
    
	Node(int value) {
		left = nullptr;
		right = nullptr;
        parent = nullptr;
   //this la de phan biet 2 cai value :
		this->value = value;
	}
    //getter : lay gia tri tu cac thuoc tinh private:
    int getValue() {
        return value;
    }
    Node *getParent() {	
        return parent;
    }
	Node *getLeft() {
        return left;
    }
	Node *getRight() { 
        return right;
    }   
    //setter : dinh danh cai gia tri ma m nhap vao 
    void setValue(int value) {
        this->value = value;
    }   
    void setParent(Node *newNode) {
         parent = newNode;
    }
	void setLeft(Node *newNode) { 
            left = newNode;
    }
	void setRight(Node *newNode) { 
            right = newNode; 
    }

    bool hasLeft(Node* node){
		return node!=nullptr && node->left !=nullptr;
	}
	bool hasRight(Node* node){
		return node!=nullptr && node->right != nullptr;
	}
};


class BinaryTree{
private:
	Node* root ;
public:
   //getter : 
   Node* getRoot() { 
    return root;
   }
   //constructor:
	BinaryTree(){
		root = nullptr;
	}
	Node* insert(Node* parent , int value) { 
        Node* newNode = new Node(value);
        newNode->setParent(parent);
        //danh sach dang rong 
        if(parent == nullptr) { 
            root = newNode;
            return nullptr ;
        }
        if(!parent->hasLeft(parent)) {
           parent->setLeft(newNode);
        }else {
            if(!parent->hasRight(parent))
			   parent->setRight(newNode);
			else{
                return nullptr;
            } 
        }
        return newNode;
    }

	//duyet tien tu
    void preOrder(Node* node) {
		if(node == NULL) return;	//C2:neu node hien tai = null thi dung 
		
		cout<< node->getValue()<<" ";
			
		preOrder(node->getLeft());
			
		preOrder(node->getRight());
	}
    

	//Liet ke tat ca duong di tu goc den la
    void rootPath(Node* node , vector<int>& path) {
        //danh sach rong:
		if(node == nullptr ) {
			return ;
		}
        //B1:
		path.push_back(node->getValue());
    
		if(node->getLeft() == nullptr && node->getRight() ==nullptr) {
			cout<<"Path: ";
			for(int value : path){
				cout<<value<<" -> ";
			}	
			cout<<"NULL\n";
			}
		else{
            //B2
			rootPath(node->getLeft() , path);
            //B4
			rootPath(node->getRight() , path);
		}
        //B4
		path.pop_back();
	}
    
 	//tinh tong tat ca duong di
    void sumPath(Node* node , vector<int>& path , int& sumRoads) {
            //danh sach rong:
            if(node == nullptr) {
                return ;
            }
            path.push_back(node->getValue());
            if(node->getLeft() == nullptr && node->getRight() == nullptr) {
                int sum = 0;
                for(int value : path){
                    sum = sum*10+ value;   
                }
            sumRoads+=sum;
     			cout<<"Tong cua duong di: "<<sum<<endl;
            }
            else{
                sumPath(node->getLeft() , path , sumRoads);
						
                sumPath(node->getRight() , path , sumRoads);
            }
            path.pop_back();

        }

      void findPath(Node* node , vector<int>& path , int& findRoads,int a) {
        	//danh sach rong:
   		if(node == nullptr) {
             return ;
         }
         vector<int>tmp;
         path.push_back(node->getValue());
         tmp.push_back(node->getValue());
         if(node->getLeft() == nullptr && node->getRight() ==nullptr) {
             int sum = 0;
             for(int value : path){
                 sum += value;                 
             }
         	if(sum==a){
         		cout<<"True,ton tai duong di ";
         		for(int tmp : path){
						cout<<tmp<<" -> ";
					}
					cout<<"NULL\n";
					cout<<"Tong cua duong di: "<<sum<<endl; 
         	}
         	else{
         		cout<<"Khong ton tai duong di = "<<a<<endl;
         	}
         }
         else{
             findPath(node->getLeft() , path , findRoads , a);					
             findPath(node->getRight() , path , findRoads , a);
         }
         path.pop_back();     
     	}

        //ham xoa node va cac con cua node do
      void remove(Node* v){
      	if(v!=nullptr){
        		remove(v->getLeft());
       		remove(v->getRight());
       		delete v;
       	}
     	}
};


int main(){
	BinaryTree  tree;
	BinaryTree 	findTree;
   vector<int> path;
   int sumRoads = 0;

//nhap vao cay nhi phan thu 1
	tree.insert(tree.getRoot(),0);
	Node* l = tree.insert(tree.getRoot(),1);
	Node* r = tree.insert(tree.getRoot(),2);
	Node* lL = tree.insert(l,3);
	Node* lR = tree.insert(l,4);
	Node* rL = tree.insert(r,5);
	Node* rR = tree.insert(r,6);
	tree.insert(lL,7);
	tree.insert(lL,8);
	tree.insert(lR,9); 
// Nhap vao cay nhi phan thu 2
	findTree.insert(findTree.getRoot(),5);
	Node* l1 = findTree.insert(findTree.getRoot(),4);
	Node* r1 = findTree.insert(findTree.getRoot(),8);
	Node* lL1 = findTree.insert(l,11);
	Node* rL1 = findTree.insert(r,13);
	Node* rR1 = findTree.insert(r,4);
	findTree.insert(lL1,2);
	findTree.insert(rL1,7);
	findTree.insert(rR1,1); 

	cout<< "==========================================\n";
   cout<<"Duyet cay nhi phan theo tien tu: \n";
	tree.preOrder(tree.getRoot());
   cout << endl;
	cout<< "==========================================\n";
	cout<<"Danh sach duong di cua cay tu goc den la: \n";
   tree.rootPath(tree.getRoot(),path);
	cout<< "==========================================\n";
   cout<<"Tong cac duong di cua cay nhi phan: \n";
	tree.sumPath(tree.getRoot(),path,sumRoads);
	cout<<"Tong tat ca duong di: "<<sumRoads<<endl;
	cout<< "==========================================\n";
   cout<<"Tim duong co tong do dai tu goc -> la = a: \n";
   int a;
   cout<<"Nhap vao gia tri a: ";
   cin>>a;
	findTree.findPath(findTree.getRoot(),path,sumRoads,a);
	return 0;
}