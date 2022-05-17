#include "OurNode.h"

float OurNode::cValue = 0.5;

OurNode::OurNode() : OurNode(0) {}

OurNode::OurNode(int v) {
	previous = nullptr;
	right = nullptr;
	left = nullptr;
	value = v;
	size = 1;
}

OurNode::~OurNode() {
	if (previous != nullptr) {
		if (previous->left == this) {
			previous->left = nullptr;
		}
		if (previous->right == this) {
			previous->right = nullptr;
		}
	}
	delete right;
	delete left;
}

void OurNode::Insert(int v) {
	std::vector<OurNode*> path = InsertRaw(new OurNode(v));

	// int i = 0; i < path.size(); i++
	// int i = path.size()-1; i >= 0; i--
	for (int i = path.size() - 1; i >= 0; i--) {
		OurNode* n = path[i];
		int leftSize = n->left == nullptr ? 0 : n->left->size;
		int rightSize = n->right == nullptr ? 0 : n->right->size;
		int nodeSize = n->size;
		
		if ((leftSize < nodeSize / 2 || leftSize > cValue * nodeSize) ||
			(rightSize < nodeSize / 2 || rightSize > cValue * nodeSize)) {
			n->Balance();
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="node"></param>
/// <returns>Insertion path</returns>
std::vector<OurNode*> OurNode::InsertRaw(OurNode* node) {
	size += node->size;
	std::vector<OurNode*> insertionPath;
	insertionPath.push_back(this);
	if (node->value >= value) {
		if (right != nullptr) {
			std::vector<OurNode*> rv = right->InsertRaw(node);
			insertionPath.insert(insertionPath.end(), rv.begin(), rv.end());
			return insertionPath;
		}
		node->previous = this;
		right = node;
		return insertionPath;
	}
	if (left != nullptr) {
		std::vector<OurNode*> lv = left->InsertRaw(node);
		insertionPath.insert(insertionPath.end(), lv.begin(), lv.end());
		return insertionPath;
	}
	node->previous = this;
	left = node;
	return insertionPath;
}

OurNode* OurNode::BalanceHelper(std::vector<OurNode*>& nodes, int start, int end) {
	if (start > end) {
		return nullptr;
	}

	int iMid = (start + end) / 2;
	OurNode* newRoot = nodes[iMid];
	newRoot->size = 1;
	newRoot->left = BalanceHelper(nodes, start, iMid - 1);
	if (newRoot->left != nullptr) {
		newRoot->left->previous = newRoot;
		newRoot->size += newRoot->left->size;
	}
	newRoot->right = BalanceHelper(nodes, iMid + 1, end);
	if (newRoot->right != nullptr) {
		newRoot->right->previous = newRoot;
		newRoot->size += newRoot->right->size;
	}

	return newRoot;
}

OurNode* OurNode::Balance() {
	std::vector<OurNode*> sorted = GetSorted();
	OurNode* parent = previous;
	
	OurNode* newRoot = BalanceHelper(sorted, 0, size - 1);
	newRoot->previous = parent;
	if (parent != nullptr) {
		if (newRoot->value >= parent->value) {
			parent->right = newRoot;
		}
		else {
			parent->left = newRoot;
		}
	}
	return newRoot;
}


/// <summary>
/// Inorder walk to sort
/// </summary>
/// <returns></returns>
std::vector<OurNode*> OurNode::GetSorted() {
	std::vector<OurNode*> sorted;
	// Add left half
	if (left != nullptr) {
		std::vector<OurNode*> leftSorted = left->GetSorted();
		for (int i = 0; i < leftSorted.size(); i++) {
			sorted.push_back(leftSorted[i]);
		}
	}
	// Add root
	sorted.push_back(this);

	// Add right half
	if (right != nullptr) {
		std::vector<OurNode*> rightSorted = right->GetSorted();
		for (int i = 0; i < rightSorted.size(); i++) {
			sorted.push_back(rightSorted[i]);
		}
	}

	return sorted;
}

int OurNode::GetHeight() {
	int leftHeight = 0;
	int rightHeight = 0;
	if (left != nullptr) {
		leftHeight = left->GetHeight();
	}
	if (right != nullptr) {
		rightHeight = right->GetHeight();
	}
	// +1 for this node
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

std::string OurNode::PrintHelper(int space, bool printSize) {
	std::string str;
	const int SPACING = 4;
	space += SPACING;
	if (right != nullptr) {
		str.append(right->PrintHelper(space, printSize));
	}
	str.append("\n");
	for (int i = SPACING; i < space; i++) {
		str.append(" ");
	}
	if (printSize) {
		str.append(std::to_string(size) + "\n");
	}
	else {
		str.append(std::to_string(value) + "\n");
	}
	

	if (left != nullptr) {
		str.append(left->PrintHelper(space, printSize));
	}

	return str;
}

void OurNode::Print(bool printSize) {
	std::cout << PrintHelper(0, printSize);
}

OurNode* OurNode::GetRoot() {
	OurNode* root = this;
	while (root->previous != nullptr) {
		root = root->previous;
	}
	return root;
}