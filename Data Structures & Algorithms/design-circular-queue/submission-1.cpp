class MyCircularQueue {
public:
    vector<int> circular_queue;
    int front, rear, k;
    int curr_size;

    MyCircularQueue(int k) {
        this->k = k;
        circular_queue.resize(k);
        front = -1;
        rear = -1;
        curr_size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % k;
        circular_queue[rear] = value;
        curr_size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        if (curr_size == 1) {
            // queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % k;
        }

        curr_size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return circular_queue[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return circular_queue[rear];
    }

    bool isEmpty() {
        return curr_size == 0;
    }

    bool isFull() {
        return curr_size == k;
    }
};

// class MyCircularQueue {
// public:
//     vector<int> circular_queue;
//     int front, rear, k;
//     int curr_size=0;
//     MyCircularQueue(int k) {
//         this->k = k;
//         circular_queue.resize(k,-1);
//         front = -1, rear = -1;
//     }
    
//     bool enQueue(int value) {
//         if(isFull()) return false;
//         rear = (rear+1)%k;
//         circular_queue[rear] = value;
//         curr_size++;
//         return true;
//     }
    
//     bool deQueue() {
//         if(isEmpty())return false;
//         front = (front+1)%k;
//         circular_queue[front] = -1;
//         curr_size--;
//         return true;    
//     }
    
//     int Front() {
//          if(isEmpty())  return -1;
//          return circular_queue[front];
//     }
    
//     int Rear() {
//         if(isEmpty())  return -1;
//         return circular_queue[rear];
//     }
    
//     bool isEmpty() {
//         return curr_size==0;
//     }
    
//     bool isFull() {
//         return curr_size==k;
//     }
// };

// /**
//  * Your MyCircularQueue object will be instantiated and called as such:
//  * MyCircularQueue* obj = new MyCircularQueue(k);
//  * bool param_1 = obj->enQueue(value);
//  * bool param_2 = obj->deQueue();
//  * int param_3 = obj->Front();
//  * int param_4 = obj->Rear();
//  * bool param_5 = obj->isEmpty();
//  * bool param_6 = obj->isFull();
//  */