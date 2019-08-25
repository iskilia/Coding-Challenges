// Complete the mergeLists function below.

/*
    * For your reference:
    *
    * SinglyLinkedListNode {
    *     int data;
    *     SinglyLinkedListNode next;
    * }
    *
    */
static SinglyLinkedListNode mergeLists(SinglyLinkedListNode head1, SinglyLinkedListNode head2) {
    if(head1 == null){
        return head2;
    } else if(head2 == null){
        return head1;
    }

    if(head1.data < head2.data){
        return mergeHelper(head1, head2);
    } else {
        return mergeHelper(head2, head1);
    }
}

static SinglyLinkedListNode mergeHelper(SinglyLinkedListNode head1, SinglyLinkedListNode head2){
    if(head1 == null){
        head1.next = head2;
        return head1;
    }

    SinglyLinkedListNode curr1 = head1, next1 = head1.next;
    SinglyLinkedListNode curr2 = head2, next2 = head2.next;

    while(next1 != null && next2 != null){
        if(curr2.data > curr1.data && curr2.data < next1.data){
            next2 = curr2.next;
            curr1.next = curr2;
            curr2.next = next1;
            curr1 = curr2;
            curr2 = next2;
        } else {
            if (next1.next != null) {
                next1 = next1.next;
                curr1 = curr1.next;
            } else {
            // else point the last node of first list
            // to the remaining nodes of second list
                next1.next = curr2;
                return head1;
            }
        }
    }

    return head1;
}