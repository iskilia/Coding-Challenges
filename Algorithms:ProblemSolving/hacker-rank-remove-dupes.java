    /*
     * For your reference:
     *
     * SinglyLinkedListNode {
     *     int data;
     *     SinglyLinkedListNode next;
     * }
     *
     */
    static SinglyLinkedListNode removeDuplicates(SinglyLinkedListNode head) {
        if(head == null || head.next == null){
            return head;
        }

        SinglyLinkedListNode curr, prev;
        curr = head;

        while(curr.next != null){
            if(curr.data != curr.next.data){
                curr = curr.next;
            } else {
                curr.next = curr.next.next;
            }
        }

        return head;
    }