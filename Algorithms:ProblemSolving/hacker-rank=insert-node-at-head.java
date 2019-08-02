    static SinglyLinkedListNode insertNodeAtHead(SinglyLinkedListNode llist, int data) {
        if(llist == null){
            llist = new SinglyLinkedListNode(data);
            return llist;
        } else {
            SinglyLinkedListNode newHead = new SinglyLinkedListNode(data);
            newHead.next = llist;
            return newHead;
        }
    }