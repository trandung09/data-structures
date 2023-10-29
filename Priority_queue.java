package learnjava;

import java.util.Vector;

class Heap{
    private Vector<Integer> heap = new Vector<Integer>();

    public void push(int elem){
        heap.add(elem);
        heapify_up(heap.size()-1);
    }

    public void pop(){
        heap.remove(0);
        heapify_down(0);
    }

    public int top(){ return heap.get(0); }
    public int size(){ return heap.size(); }
    public boolean empty(){ return heap.size() == 0; }

    public void heapify_up(int index){
        while(index > 0){
            int parent = (int)(1.0*(index-1)/2);
            if (heap.get(parent) > heap.get(index)){
                int temp = heap.get(parent);
                heap.set(parent, heap.get(index));
                heap.set(index, temp);
                index = parent;
            }
            else break;
        }
    }

    public void heapify_down(int index){
        int left = 2*index + 1;
        int right = 2*index + 2;
        int min = index;

        if (left < heap.size() && heap.get(left) < heap.get(min))
            min = left;
        if (right < heap.size() && heap.get(right) < heap.get(min))
            min = right;

        if (index != min){
            int temp = heap.get(index);
            heap.set(index, heap.get(min));
            heap.set(min, temp);
            heapify_down(min);
        }
    }
}

public class Priority_queue {
    private Heap heap_;

    public Priority_queue(){
        heap_ = new Heap();
    }

    public int size(){ return heap_.size(); }
    public boolean empty(){ return heap_.empty(); }
    public void push(int elem){ heap_.push(elem); }
    public void pop(){ heap_.pop(); }
    public int top(){ return heap_.top(); }

    public static void main(String[] args) {
        Priority_queue queue = new Priority_queue();

        queue.push(7);
        queue.push(2);
        queue.push(3);
        queue.push(1);
        queue.push(4);
        queue.push(1);

        while(!queue.empty()){
            System.out.println(queue.top());
            queue.pop();
        }
    }
}
