package learnjava;

class node<T>{
    T elem;
    node next;

    public node(){
    }
    public node(T elem, node next){
        this.elem = elem;
        this.next = next;
    }

    public T getElem() {return elem; }
    public void setElem(T elem) { this.elem = elem; }
    public node getNext() { return next; }
    public void setNext(node next) { this.next = next; }
}

public class List<T> {
    private int size;
    private node head, tail;

    public List(){
        size = 0;
        head = tail = null;
    }

    public int size(){ return size; }
    public boolean empty(){ return size == 0; }
    public T back(){ return (T) tail.getElem(); }
    public T front(){ return (T) head.getElem(); }

    public void push_front(T elem){
        head = new node(elem, head);
        if (size == 0) tail = head;
        size++;
    }

    public void push_back(T elem){
        if (size == 0) push_front(elem);
        else{
            tail.setNext(new node<>(elem, null));
            tail = tail.getNext();
            size++;
        }
    }

    public void pop_back(){
        if (size == 0) return;
        else if (size == 1){
            head = tail = null;
            size--;
            return;
        }
        else{
            node<T> p = head;
            while(p.getNext().getNext() != null)
                    p = p.getNext();
            p.setNext(null);
            tail = p;
            size--;
        }
    }

    public void pop_front(){
        if (size == 0) return;
        if (size == 1){
            head = tail = null;
            size--;
            return;
        }
        else{
            head = head.getNext();
            size--;
        }
    }

        public void remove(int pos){
        if (size == 0 || pos < 0 || pos > size) return;
        if (pos == 0) pop_front();
        else{
            int temp = 0;
            node<T> p = head;
            while(p.getNext() != null){
                if (temp == pos-1){
                    p.setNext(p.getNext().getNext());
                    size--; break;
                }
                p = p.getNext();
                temp++;
            }
        }
    }
    
    public static void main(String[] args) {
        List<Integer> myList = new List<Integer>();

        myList.push_back(1);
        myList.push_back(2);
        myList.push_back(3);
        myList.push_back(4);
        myList.push_back(5);

        System.out.println(myList.size);

        while(!myList.empty()){
            System.out.println(myList.front());
            myList.pop_front();
        }

    }
}
