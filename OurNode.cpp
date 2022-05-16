#include "OurNode.h"

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
	if (v >= value) {
		if (right != nullptr) {
			right->Insert(v);
		}
		else {
			right = new OurNode(v);
		}
	}
	else {
		if (left != nullptr) {
			left->Insert(v);
		}
		else {
			left = new OurNode(v);
		}
	}
	size++;
	// check if balanced
}

void OurNode::InsertRaw(OurNode* node) {
	size += node->size;
	if (node->value >= value) {
		if (right != nullptr) {
			right->InsertRaw(node);
			return;
		}
		right = node;
		return;
	}
	if (left != nullptr) {
		left->InsertRaw(node);
		return;
	}
	left = node;
}

void OurNode::Balance() {
	OurNode* parent = previous;
	std::vector<OurNode*> sorted = GetSorted();
	int sizeCache = sorted.size();
	for (int i = 0; i < sizeCache; i++) {
		OurNode* n = sorted[i];
		n->size = 1;
		n->right = nullptr;
		n->left = nullptr;
		n->previous = nullptr;
	}
	int iHalf = sizeCache / 2;
	OurNode* middle = sorted[iHalf];
	
	int iLeft = iHalf - 1;
	int iRight = iHalf + 1;
	while (iRight < sizeCache || iLeft >= 0) {
		middle->InsertRaw(sorted[iLeft]);
		middle->InsertRaw(sorted[iRight]);
		iLeft--;
		iRight++;
	}
	parent->InsertRaw(middle);
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