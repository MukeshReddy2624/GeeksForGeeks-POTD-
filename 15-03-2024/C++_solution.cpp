_______________________________ Linked List that is Sorted Alternatingly _________________________________________


/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *merge(Node *head1, Node *head2)
    {
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        Node *temp = head1;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head2;

        return head1;
    }

    void reverse(Node *&head)
    {
        Node *prev = NULL, *curr = head, *next;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void splitList(Node *head, Node **Ahead, Node **Dhead)
    {
        if (!head)
            return;

        *Ahead = new Node(0);
        *Dhead = new Node(0);

        Node *ascn = *Ahead;
        Node *dscn = *Dhead;
        Node *curr = head;
        while (curr)
        {
            ascn->next = curr;
            ascn = ascn->next;
            curr = curr->next;

            if (curr)
            {
                dscn->next = curr;
                dscn = dscn->next;
                curr = curr->next;
            }
        }

        ascn->next = NULL;
        dscn->next = NULL;

        *Ahead = (*Ahead)->next;
        *Dhead = (*Dhead)->next;
    }

    void sort(Node **head)
    {
        if (!(*head) || !((*head)->next))
            return;

        Node *Ahead, *Dhead;
        splitList(*head, &Ahead, &Dhead);

        reverse(Dhead);

        *head = merge(Ahead, Dhead);
    }
};
