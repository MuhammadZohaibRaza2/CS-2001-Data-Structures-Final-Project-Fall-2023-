#pragma once
#include "File.h"
class BTreeNode {
private:
    File** files;
    int order;
    BTreeNode** children;
    int numberOfFiles;
    bool leaf;

public:
    BTreeNode(int _t, bool _leaf);

   
    void traversetoCopy(File** arr,int& index);
    void traverse();
    int getNumberOfFiles() {
		return numberOfFiles;
	}

    File* search(BigInt Id);

    int findFileIndex(BigInt id);

    void insertNonFull(File* file);

    void splitChild(int i, BTreeNode* y);

    void deletion(BigInt Id);

    void removeFromLeaf(int idx);

    void removeFromNonLeaf(int idx);

    BigInt getPredecessor(int idx);

    BigInt getSuccessor(int idx);

    void fill(int idx);

    void borrowFromPrev(int idx);

    void borrowFromNext(int idx);

    void merge(int idx);

    friend class BTree;
};

class BTree {
private:
    BTreeNode* root;
    int order;

public:
    BTree(int _t) {
        root = nullptr;
        order = _t;
    }

   

    void traverse() {
        if (root) {
            root->traverse();
        }
    }

    void traversetoCopy(File** arr, int& index) {
        if (root) {
            int sizeee= root->getNumberOfFiles();
            arr = new File * [sizeee];
            root->traversetoCopy( arr, index);
        }
    }


    File* search(BigInt Id) {
        return (root == nullptr) ? nullptr : root->search(Id);
    }

    File* searchByName(string name) {
        if(root){
			string searchHash = sha1(name);
            BigInt Id = convertHextoDec(searchHash);
            return this->search(Id);
		}
    }

    void insertion(File* file);

    bool deletion(File* file);
};

// B tree node
BTreeNode::BTreeNode(int t, bool leafNode) {
    order = t;
    leaf = leafNode;

    files = new File * [2 * order - 1];
    children = new BTreeNode * [2 * order];

    numberOfFiles = 0;
}

int BTreeNode::findFileIndex(BigInt Id) {
    int idx = 0;
    while (idx < numberOfFiles && files[idx]->getFileId() < Id) {
        ++idx;
    }
    return idx;
}

void BTreeNode::deletion(BigInt Id) {
    int idx = findFileIndex(Id);

    if (idx < numberOfFiles && files[idx]->getFileId() == Id) {
        if (leaf) {
            removeFromLeaf(idx);
        }
        else {
            removeFromNonLeaf(idx);
        }
    }
    else {
        if (leaf) {
            cout << "The file with Id " << Id << " does not exist in the tree\n";
            return;
        }

        bool flag = (idx == numberOfFiles);

        if (children[idx]->numberOfFiles < order) {
            fill(idx);
        }

        if (flag && idx > numberOfFiles) {
            children[idx - 1]->deletion(Id);
        }
        else {
            children[idx]->deletion(Id);
        }
    }
    return;
}

void BTreeNode::removeFromLeaf(int idx) {
    for (int i = idx + 1; i < numberOfFiles; ++i) {
        files[i - 1] = files[i];
    }

    numberOfFiles--;

    return;
}

void BTreeNode::removeFromNonLeaf(int idx) {
    BigInt Id = files[idx]->getFileId();

    if (children[idx]->numberOfFiles >= order) {
        BigInt pred = getPredecessor(idx);
        files[idx]->setFileId(pred);
        children[idx]->deletion(pred);
    }
    else if (children[idx + 1]->numberOfFiles >= order) {
        BigInt succ = getSuccessor(idx);
        files[idx]->setFileId(succ);
        children[idx + 1]->deletion(succ);
    }
    else {
        merge(idx);
        children[idx]->deletion(Id);
    }
    return;
}

BigInt BTreeNode::getPredecessor(int idx) {
    BTreeNode* cur = children[idx];
    while (!cur->leaf) {
        cur = cur->children[cur->numberOfFiles];
    }

    return cur->files[cur->numberOfFiles - 1]->getFileId();
}

BigInt BTreeNode::getSuccessor(int idx) {
    BTreeNode* cur = children[idx + 1];
    while (!cur->leaf) {
        cur = cur->children[0];
    }

    return cur->files[0]->getFileId();
}

void BTreeNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->numberOfFiles >= order) {
        borrowFromPrev(idx);
    }
    else if (idx != numberOfFiles && children[idx + 1]->numberOfFiles >= order) {
        borrowFromNext(idx);
    }
    else {
        if (idx != numberOfFiles) {
            merge(idx);
        }
        else {
            merge(idx - 1);
        }
    }
    return;
}

void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx - 1];

    for (int i = child->numberOfFiles - 1; i >= 0; --i) {
        child->files[i + 1] = child->files[i];
    }

    child->files[0] = files[idx - 1];

    if (!child->leaf) {
        for (int i = child->numberOfFiles; i >= 0; --i) {
            child->children[i + 1] = child->children[i];
        }
    }

    child->children[0] = sibling->children[sibling->numberOfFiles];

    files[idx - 1] = sibling->files[sibling->numberOfFiles - 1];

    child->numberOfFiles += 1;
    sibling->numberOfFiles -= 1;

    return;
}

void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->files[child->numberOfFiles] = files[idx];

    if (!child->leaf) {
        child->children[child->numberOfFiles + 1] = sibling->children[0];
    }

    files[idx] = sibling->files[0];

    for (int i = 1; i < sibling->numberOfFiles; ++i) {
        sibling->files[i - 1] = sibling->files[i];
    }

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->numberOfFiles; ++i) {
            sibling->children[i - 1] = sibling->children[i];
        }
    }

    child->numberOfFiles += 1;
    sibling->numberOfFiles -= 1;

    return;
}

void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->files[order - 1] = files[idx];

    for (int i = 0; i < sibling->numberOfFiles; ++i) {
        child->files[i + order] = sibling->files[i];
    }

    if (!child->leaf) {
        for (int i = 0; i <= sibling->numberOfFiles; ++i) {
            child->children[i + order] = sibling->children[i];
        }
    }

    for (int i = idx + 1; i < numberOfFiles; ++i) {
        files[i - 1] = files[i];
    }

    for (int i = idx + 2; i <= numberOfFiles; ++i) {
        children[i - 1] = children[i];
    }

    child->numberOfFiles += sibling->numberOfFiles + 1;
    numberOfFiles--;

    // Recursively delete the merged sibling and its children
    for (int i = 0; i <= sibling->numberOfFiles; ++i) {
        delete sibling->children[i];
    }
    delete sibling;

    return;
}



void BTreeNode::insertNonFull(File* file) {
    int i = numberOfFiles - 1;

    if (leaf) {
        while (i >= 0 && files[i]->getFileId() > file->getFileId()) {
            files[i + 1] = files[i];
            i--;
        }

        files[i + 1] = file;
        numberOfFiles = numberOfFiles + 1;
    }
    else {
        while (i >= 0 && files[i]->getFileId() > file->getFileId()) {
            i--;
        }

        if (children[i + 1]->numberOfFiles == 2 * order - 1) {
            splitChild(i + 1, children[i + 1]);

            if (files[i + 1]->getFileId() < file->getFileId()) {
                i++;
            }
        }
        children[i + 1]->insertNonFull(file);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->order, y->leaf);
    z->numberOfFiles = order - 1;

    for (int j = 0; j < order - 1; j++) {
        z->files[j] = y->files[j + order];
    }

    if (!y->leaf) {
        for (int j = 0; j < order; j++) {
            z->children[j] = y->children[j + order];
        }
    }

    y->numberOfFiles = order - 1;

    for (int j = numberOfFiles; j >= i + 1; j--) {
        children[j + 1] = children[j];
    }

    children[i + 1] = z;

    for (int j = numberOfFiles - 1; j >= i; j--) {
        files[j + 1] = files[j];
    }

    files[i] = y->files[order - 1];

    numberOfFiles = numberOfFiles + 1;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < numberOfFiles; i++) {
        if (!leaf) {
            children[i]->traverse();
        }
        cout << files[i]->getFileName()<< "   " << files[i]->getFileId() << endl;
       
    }

    if (!leaf) {
        children[i]->traverse();
    }
}

File* BTreeNode::search(BigInt Id) {
    int i;
    for (i = 0; i < numberOfFiles; i++) {
        if (!leaf) {
            children[i]->traverse();
        }
        if(files[i]->getFileId() == Id)
		{
			return files[i];
		}
    }

    if (!leaf) {
        children[i]->traverse();
    }
}

void BTree::insertion(File* file) {
    if (root == nullptr) {
        root = new BTreeNode(order, true);
        root->files[0] = file;
        root->numberOfFiles = 1;
    }
    else {
        if (root->numberOfFiles == 2 * order - 1) {
            BTreeNode* s = new BTreeNode(order, false);

            s->children[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->files[0]->getFileId() < file->getFileId()) {
                i++;
            }
            s->children[i]->insertNonFull(file);

            root = s;
        }
        else {
            root->insertNonFull(file);
        }
    }
}

bool BTree::deletion(File* file) {
    if (!root) {
        cout << "The tree is empty\n";
        return false;
    }

    root->deletion(file->getFileId());

    if (root->numberOfFiles == 0) {
        BTreeNode* tmp = root;
        if (root->leaf) {
            root = nullptr;
        }
        else {
            root = root->children[0];
        }

        delete tmp;
        return true;
    }
    return false;
}

void BTreeNode::traversetoCopy(File** arr, int& index) {
	int i;
    for (i = 0; i < numberOfFiles; i++) {
        if (!leaf) {
			children[i]->traversetoCopy(arr,index);
		}
		arr[index]=files[i];
        index++;
		
	}

    if (!leaf) {
		children[i]->traversetoCopy(arr,index);
	}
} 
