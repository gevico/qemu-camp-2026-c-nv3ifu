#include <stdio.h>
#include <stdbool.h>

#define MAX_PEOPLE 50

typedef struct {
    int id;
} People;

typedef struct {
    People data[MAX_PEOPLE];
    int head;
    int tail;
    int count;
} Queue;

int main() {
    Queue q;
    int total_people=50;
    int report_interval=5;

    q.head = 0; q.tail = total_people; q.count = total_people;
    for (int i = 0; i < total_people; i++) q.data[i].id = i + 1;
    int index = 0;
    while (q.count > 1) {
        index = (index + report_interval - 1) % q.count;
        printf("淘汰: %d\n", q.data[index].id);
        for (int i = index; i < q.count - 1; i++) q.data[i] = q.data[i + 1];
        q.count--;
    }
    
    printf("最后剩下的人是: %d\n", q.data[0].id);

    return 0;
}
