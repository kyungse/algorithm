//
//  main.cpp
//  task136
//
//  Created by 박경세 on 2018. 1. 10..
//  Copyright © 2018년 박경세. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define swap(a, b, t)((t) = (a), (a) = (b), (b) = (t))
#define max_size 10

using namespace std;

// quicksort;
void quicksort(int left, int right, int arr[]){
    if(left < right){
        int i = left;
        int j = right+1;
        int temp = 0;
        int pivot = arr[left];
        do{
            do{
                i++;
            }while(arr[i] < pivot);
            do{
                j--;
            }while(arr[j] > pivot);
            if(i <= j) swap(arr[i], arr[j], temp);
        }while(i <= j);
        swap(arr[j], arr[left], temp);
        quicksort(left, j-1, arr);
        quicksort(j+1, right, arr);
    }
}

// circular queue;
int front = 0;
int back = 0;
int queue[10] = {0,};
void push(int n){
    if(((back+1)%max_size) == front){       // full check;
        printf("circular queue is full.\n");
    }
    else{
        queue[back] = n;
        back = (back+1)%max_size;
    }
}

int pop(){
    if(back == front){                      // empty check;
        printf("circular queue is empty.\n");
        return -1;
    }
    else{
        int item = queue[front];
        queue[front] = 0;                   // 0이면 비어있다고 가정 - 하나 비운다고 생각;
        front = (front+1)%max_size;
        return item;
    }
}

// stack;
int top = 0;
int stack[10] = {0,};
void push_stack(int n){
    if((top+1) == max_size){
        printf("stack is full.\n");
    }
    else{
        stack[top++] = n;
    }
}

int pop_stack(){
    return stack[--top];
}

// linked-list;
typedef struct node{
    int value;
    node* prev = NULL;
    node* next = NULL;
}NODE;

NODE* head = NULL;

void insert(int n){
    NODE* temp = new NODE();
    temp->value = n;
    if(head==NULL){
        head = temp;
        head->next = head;
        head->prev = head;
    }
    else{
        NODE* pre = head->prev;
        pre->next = temp;
        head->prev = temp;
        temp->next = head;
        temp->prev = pre;
    }
}

bool search(int n){
    if(head==NULL){
        return false;
    }
    else{
        NODE* cur = head;
        do{
            if(cur->value == n){
                return true;
            }
            else cur = cur->next;
        }while(cur!=head);
        return false;
    }
}

void destroy(int n){
    if(head!=NULL){
        NODE* cur = head;
        do{
            if(cur->value == n){
                (cur->prev)->next = cur->next;
                (cur->next)->prev = cur->prev;
                if(cur==head) head = cur->next;
                delete cur;
                printf("[%d] is deleted!\n", n);
                return;
            }
            else cur = cur->next;
        }while(cur!=head);
    }
}

// dijkstra algorithm;
int dist[10];                                       // 시작점 제외 전부 INT_MAX로 초기화;
int visit[10];                                      // 현재 접근할수있는 가장가까운 위치라면 1로 표시 -  visit;
int map[10][10];                                    // 연결되있지 않은 경우 INT_MAX로 초기화;
void dijkstra(int n){
    dist[n] = 0;
    for(int i=1; i<8; i++){
        int v = 0;
        int min = 100000;
        for(int j=1; j<8; j++){
            if(visit[j] == 0 && dist[j] < min){
                min = dist[j];
                v = j;
            }
        }
        visit[v] = 1;
        for(int j=1; j<8; j++){
            if(dist[j] > dist[v] + map[v][j]){      // 추가된 방문위치를 기반으로 더 짧아질 수 있는 거리를 update;
                dist[j] = dist[v] + map[v][j];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
