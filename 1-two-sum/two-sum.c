#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashNode;

int hash(int key, int size) {
    return abs(key) % size;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int size = numsSize * 2;
    HashNode* map = (HashNode*)malloc(sizeof(HashNode) * size);
    for (int i = 0; i < size; i++) {
        map[i].key = 0;
        map[i].value = -1;
    }

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int hashIndex = hash(complement, size);

        // Search complement
        for (int j = 0; j < size; j++) {
            int index = (hashIndex + j) % size;
            if (map[index].value == -1) break;
            if (map[index].key == complement) {
                result[0] = map[index].value;
                result[1] = i;
                free(map);
                return result;
            }
        }

        // Insert current number into hash table
        int insertIndex = hash(nums[i], size);
        while (map[insertIndex].value != -1)
            insertIndex = (insertIndex + 1) % size;

        map[insertIndex].key = nums[i];
        map[insertIndex].value = i;
    }

    free(map);
    return NULL;
}

    
    