#include <stdio.h>

const int TASK_NUMBER = 100;
const int LEN = 100;

typedef struct Task {
    char task_name[LEN];
    int time;
} Task;

struct Queue {
    int head;
    int tail;
    Task task[TASK_NUMBER];
    void (*enqueue)(Task t);
    Task (*dequeue)();
} queue;

void enqueue(Task t) {
    queue.task[queue.tail] = t;
    queue.tail = (queue.tail + 1) % TASK_NUMBER;
}

Task dequeue() {
    Task t = queue.task[queue.head];
    queue.head = (queue.head + 1) % TASK_NUMBER;
    return t;
}

void insert_func() {
    queue.enqueue = enqueue;
    queue.dequeue = dequeue;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main(int argc, char const *argv[]) {
    insert_func();
    int task_count;
    int basic_time = 0;
    int pass_time = 0;

    scanf("%d %d", &task_count, &basic_time);

    for (int i = 1; i <= task_count; i++) {
        scanf("%s", queue.task[i].task_name);
        scanf("%d", &queue.task[i].time);
    }
    
    queue.head = 1;
    queue.tail = task_count + 1;

    while (queue.head != queue.tail) {
        Task t = queue.dequeue();
        int m = min(basic_time, t.time);
        t.time -= m;
        pass_time += m;

        if (t.time > 0) {
            queue.enqueue(t);
        } else {
            printf("%s %d\n", t.task_name, pass_time);
        }
    }

    return 0;
}