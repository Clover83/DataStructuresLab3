#include "StandardNode.h"

StandardNode::StandardNode() : StandardNode(0) {}

StandardNode::StandardNode(int v) {
	left = nullptr;
	right = nullptr;
	value = v;
}

StandardNode::~StandardNode() {
	delete left;
	delete right;
}

void StandardNode::Insert(int v) {
	Insert(new StandardNode(v));
}

void StandardNode::Insert(StandardNode* node) {
	if (node->value >= value) {
		if (right != nullptr) {
			right->Insert(node);
			return;
		}
		right = node;
		return;
	}
	if (left != nullptr) {
		left->Insert(node);
		return;
	}
	left = node;
	return;
}

std::string StandardNode::PrintHelper(int space) {
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

void StandardNode::Print() {
	std::cout << PrintHelper(0);
}