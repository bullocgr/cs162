#include <stdio.h>
#include <stdlib.h>

typedef struct timeval time;
void print_array(int *, int);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void fill_array(int **, int *);
void add_num(int **, int *, int);

int main() {
   int *nums = NULL;
   int size = 0;
   time stop, start;

   fill_array(&nums, &size);
   print_array(nums, size);

   //Time the function here
   gettimeofday(&start, NULL);

   // bubble_sort(nums, size);
   // insertion_sort(nums, size);
   // merge_sort(nums, 0, size-1);
   selection_sort(nums, size);

   gettimeofday(&stop, NULL);

   printf("MicroSeconds: %d\n", stop.tv_usec - start.tv_usec);
   //printf("Seconds: %d\n", stop.tv_sec-start.tv_sec);

   print_array(nums, size);
   free(nums);

   return 0;
}

/*************************************************
 * Description: This prints the contents of an array
 * Params: array of integers and size of the array
 * Returns: none
 * Post-conditions: none
 * Pre-conditions: size is accurate number of
 *                 elements in the array >=0
 * **********************************************/
void print_array(int *nums, int size) {
   int i;

   printf("The array elements are:\n");
   for (i = 0; i < size; i++)
      printf("%d\t", nums[i]);
   printf("\n\n");
}

/*************************************************
* Description: this will be used in merge sort in order to put the pieces back together
* Parameters: you pass in the array, the left value, the middle value, and the right value
* Returns: it doesn't return anything
* Pre-Conditions: must pass in all the things and the values must be correct
* Post-Conditions: the list is put back together
 * ***********************************************/
void merge(int *nums, int left, int mid, int right) {
   int i, j, lower_half, upper_half;
   int temp[(right - left) + 1];

   lower_half = left; //What is this for?
   upper_half = mid + 1; //What is this for?

   //What does this loop do?
   for (i = 0; (lower_half <= mid) && (upper_half <= right); i++) {
      //What does this condition do?
      if (nums[lower_half] <= nums[upper_half]) {
         temp[i] = nums[lower_half];
         lower_half++;
      }
      //What does this condition do?
      else {
         temp[i] = nums[upper_half];
         upper_half++;
      }
   }

   //What does this condition and loop do?
   if (lower_half > mid)
      for (j = upper_half; j <= right; j++, i++)
         temp[i] = nums[j];
   //What does this else and loop do?
   else
      for (j = lower_half; j <= mid; j++, i++)
         temp[i] = nums[j];

   //What does this loop do?
   for (j = 0, i = left; i <= right; i++, j++)
      nums[i] = temp[j];
}

/*************************************************
* Description:  merge sort splits the list in half 
 until it gets to the smallest size and then compares the numbers
 in the index then combines the separated lists back together
* Parameters: pass in array of ints and reads in the first and the one after the first index
* Returns: doesn't return anything
* Pre-Conditions: array is properly initialized
* Post-Conditions: the function is called until the list is sorted properly
 * ***********************************************/
void merge_sort(int *nums, int left, int right) {
   int mid;
   if (left < right) {
      mid = (right + left) / 2;
      merge_sort(nums, left, mid);  //what does this call do?
      merge_sort(nums, mid + 1, right); //what does this call do?
      merge(nums, left, mid, right);  //what does this call do?
   }
}

/*************************************************
* Description: if the value is the largest value it is put at the end of the list
the algorithm then finds the next largest value and puts it right before the last value
* Parameters: read in the array and how big it is
* Returns: this returns nothing
* Pre-Conditions: the array must be created correctly and the size must be valid
* Post-Conditions: the array will then be sorted
 * ***********************************************/
void selection_sort(int *nums, int size) {
   int i, j;
   int temp, min;

   //What does this loop do?
   for (i = 0; i < size - 1; i++) {
      min = i;
      //What does this loop do?
      for (j = i; j < size; j++)
         if (nums[j] < nums[min])
            min = j;
      //What elements are being swaped?
      temp = nums[i];
      nums[i] = nums[min];
      nums[min] = temp;
   }
}

/*************************************************
* Description: the sorting starts with the first element and compares the first and second one
if the value on the right is less than the one on the left it moves it over
* Parameters: this reads in the list and how big the list is
* Returns: it does not return anything
* Pre-Conditions: the list should be initialized properly and not point to NULL
* Post-Conditions: the list should be sorted properly
 * ***********************************************/
void insertion_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   for (i = 0; i < size; i++) {
      temp = nums[i];
      //What does this loop do?
      for (j = i; j > 0 && nums[j - 1] > temp; j--)
         nums[j] = nums[j - 1];
      //What does this statment do?
      nums[j] = temp;
   }
}

/*************************************************
* Description: bubble sort compares the left and right number and if they left number
is smaller than the right then it does not swap and moves on to the next values
* Parameters: pass in the array and the size
* Returns: does not return anything
* Pre-Conditions: the array must be initialized correctly and cannot equal NULL
* Post-Conditions: the array will be sorted correctly
* ***********************************************/
void bubble_sort(int *nums, int size) {
   int i, j;
   int temp;

   //What does this loop do?
   for (i = 0; i < size; i++) {
      //What does this loop do?
      for (j = 0; j < size - i - 1; j++) {
         if (nums[j] > nums[j + 1]) {
            temp = nums[j];
            nums[j] = nums[j + 1];
            nums[j + 1] = temp;
         }
      }
   }
}

/*************************************************
 * Description: This adds an element to the array
 * and sets the contents to num
 * Params: address of array pointer to ints and
 *         address of size of the array
 * Returns: none
 * Post-conditions: size is increased by one and
 * nums points to new array with one more element
 * where the contents are the same with num at the end
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void add_num(int **nums, int *size, int num) {
   int *old_nums, i;

   *size += 1;
   old_nums = *nums;
   *nums = (int *) malloc(sizeof(int) * (*size));

   for (i = 0; i < *size - 1; i++)
      (*nums)[i] = old_nums[i];
   (*nums)[*size - 1] = num;

   free(old_nums);
}

/*************************************************
 * Description: This fills an array with contents
 * from a file
 * Params: address of array pointer to ints and
 *         address of size of the array
 * Returns: none
 * Post-conditions: array pointer is pointing to
 * valid array of integers or NULL and size has
 * a positive integer
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void fill_array(int **nums, int *size) {
   FILE *fptr;
   char filename[20], num[10];

   printf("Enter the filename: ");
   scanf("%s", filename);
   fptr = fopen(filename, "r");

   while (fscanf(fptr, "%s", num) != EOF) {
      add_num(nums, size, atoi(num));
   }

   fclose(fptr);
}