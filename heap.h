//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            return -1;
        }

        int minIdx = data[0];
        data[0] = data[size - 1];
        size--;
        downheap(0, weightArr);
        return minIdx;
    }

    void upheap(int pos, int weightArr[]) {
        // bubble the new element up while it's smaller than its parent
        while (pos > 0) {
            int parent = (pos - 1) / 2;

            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                int temp = data[pos];
                data[pos] = data[parent];
                data[parent] = temp;

                pos = parent; // keep checking higher
            } else {
                break; // heap property is good
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // push the root down until both children are heavier
        while (true) {
            int leftChild  = 2 * pos + 1;
            int rightChild = 2 * pos + 2;
            int smallest = pos;

            // check left child
            if (leftChild < size &&
                weightArr[data[leftChild]] < weightArr[data[smallest]]) {
                smallest = leftChild;
            }

            // check right child
            if (rightChild < size &&
                weightArr[data[rightChild]] < weightArr[data[smallest]]) {
                smallest = rightChild;
            }

            // if parent is already the smallest, stop
            if (smallest == pos) {
                break;
            }

            // swap parent with the smaller child
            int temp = data[pos];
            data[pos] = data[smallest];
            data[smallest] = temp;

            pos = smallest; // continue from child's position
        }
    }
};

#endif
