    // Complete the getNode function below.

    /*
     * For your reference:
     *
     * SinglyLinkedListNode {
     *     int data;
     *     SinglyLinkedListNode next;
     * }
     *
     */
    static int getNode(SinglyLinkedListNode head, int positionFromTail) {
        SinglyLinkedListNode temp = head;

        while(positionFromTail > 0){
            positionFromTail--;
            temp = temp.next;
        }

        while(temp.next != null){
            temp = temp.next;
            head = head.next;
        }
        return head.data;
    }