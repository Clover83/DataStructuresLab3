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

void OurNode::Balance() {
	int sizeCache = size;
	OurNode* parent = previous;
	std::vector<OurNode*> sorted = GetSorted();
	for (int i = 0; i < sizeCache; i++) {
		OurNode* n = sorted[i];
		n->size = 1;
		n->previous = nullptr;
		n->left = nullptr;
		n->right = nullptr;
	}

	int iMid = sizeCache / 2;
	OurNode* newRoot = sorted[iMid];
	int iLeft = iMid - 1;
	int iRight = iMid + 1;
	
	while (iLeft >= 0 || iRight < sizeCache) {
		if (iLeft >= 0) {
			newRoot->InsertRaw(sorted[iLeft]);
		}
		if (iRight < sizeCache) {
			newRoot->InsertRaw(sorted[iRight]);
		}
		iLeft--;
		iRight++;
	}

	if (parent != nullptr) {
		if (newRoot->value >= parent->value) {
			parent->right = newRoot;
			newRoot->previous = parent;
		}
		else {
			parent->left = newRoot;
			newRoot->previous = parent;
		}
	}
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

std::string OurNode::PrintHelper(int space) {
	std::string str;
	const int SPACING = 4;
	space += SPACING;
	if (right != nullptr) {
		str.append(right->PrintHelper(space));
	}
	str.append("\n");
	for (int i = SPACING; i < space; i++) {
		str.append(" ");
	}
	str.append(std::to_string(value) + "\n");

	if (left != nullptr) {
		str.append(left->PrintHelper(space));
	}

	return str;
}

void OurNode::Print() {
	std::cout << PrintHelper(0);
}