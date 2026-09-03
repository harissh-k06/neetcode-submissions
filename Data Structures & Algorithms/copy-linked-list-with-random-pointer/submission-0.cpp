class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> nodeMap;
        Node* temp = head;
        Node* prev = NULL;
        Node* copyHead = new Node(0);

        while (temp) {
            Node* newNode = new Node(temp->val);
            nodeMap[temp] = newNode;
            if (temp == head) {
                copyHead = newNode;
                prev = newNode;
                temp = temp->next;
                continue;
            }
            prev->next = newNode;
            prev = newNode;
            temp = temp->next;
        }

        temp = head;
        Node* temp2 = copyHead;
        while (temp) {
            if (temp->random) temp2->random = nodeMap[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }

        return copyHead;
    }
};

