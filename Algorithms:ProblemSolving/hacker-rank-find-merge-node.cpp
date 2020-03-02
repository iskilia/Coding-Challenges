/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* curr1 = head1;
    SinglyLinkedListNode* curr2 = head2;

    while(curr1 != curr2){
        if(curr1 -> next == nullptr){
            curr1 = head2;
        } else{
            curr1 = curr1->next;
        }
        if(curr2 -> next == nullptr){
            curr2 = head1;
        } else{
            curr2 = curr2->next;
        }
    }
    return curr2->data;
}

// You could also take the count of number of nodes in each list, move one forward the diff and then get the merge point