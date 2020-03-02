/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

bool has_cycle(SinglyLinkedListNode* head) {
    if(head == nullptr){
        return false;
    }
    SinglyLinkedListNode* fast = head;
    SinglyLinkedListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}