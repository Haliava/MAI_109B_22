template<typename T>
Tree<T>::Tree() {
    this->root = new TreeNode<T>(T(0));
    this->linear = true;
}

template<typename T>
Tree<T>::Tree(const T& data) {
    this->root = new TreeNode<T>(data);
    this->linear = true;
}

template<typename T>
TreeNode<T>* Tree<T>::getRoot() const {
    return root; //this->root
}

template<typename T>
TreeNode<T>* Tree<T>::deleteNode(const T& deleteData, TreeNode<T>* node) {
    if (node == nullptr) {
        return node;
    }

    for (size_t i = 0; i < node->children.size(); ++i) {
        node->children[i] = deleteNode(deleteData, node->children[i]);
    }

    if (node->data == deleteData) {
        delete node;
        return nullptr;
    }

    return node;
}

template<typename T>
void Tree<T>::addNode(const T& newData, TreeNode<T>* node) {
    if (node->data > newData) {
        if (node->children.empty()) {
            TreeNode<T>* newNode = new TreeNode<T>(newData);
            node->children.push_back(newNode);
        }
        else {
            addNode(newData, node->children[0]);
        }
    }
    else if (node->data <= newData) {
        TreeNode<T>* newNode = new TreeNode<T>(newData);
        node->children.push_back(newNode);
    }
}

template<typename T>
void Tree<T>::visualize(TreeNode<T>* node) const {
    if (node == nullptr) {
        return;
    }

    std::cout << node->data << std::endl;

    for (size_t i = 0; i < node->children.size(); ++i) {
        TreeNode<T>* child = node->children[i];
        visualize(child);
    }
}

template<typename T>
bool Tree<T>::linearize(TreeNode<T>* node) {
    if (node == nullptr) {
        std::cout << "This tree is linear!" << std::endl;
        return true;
    }

    if (node->children.size() > 1) {
        std::cout << "This tree is not linear" << std::endl;
        return false;
    }

    for (size_t i = 0; i < node->children.size(); ++i) {
        TreeNode<T>* child = node->children[i];
        if (!linearize(child)) {
            std::cout << "This tree is not linear" << std::endl;
            return false;
        }
    }
    std::cout << "This tree is linear!" << std::endl;
    return true;
}

template<typename T>
void Tree<T>::deleteTree(TreeNode<T>* node) {
    if (node == nullptr) {
        return;
    }

    for (size_t i = 0; i < node->children.size(); ++i) {
        TreeNode<T>* child = node->children[i];
        deleteTree(child);
    }

    delete node;
}

template<typename T>
Tree<T>::~Tree(){
    deleteTree(root);
    root = nullptr;
}
