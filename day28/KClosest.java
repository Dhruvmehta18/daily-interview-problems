/*
    Hi, here's your problem today. This problem was recently asked by AirBNB:

    Given a list of sorted numbers, and two integers k and x, find k closest numbers to the pivot x.
*/
class KClosest {

    private static int findCrossOver(int[] arr, int low, int high, int x) {
        while (low <= high) {

            if (arr[high] <= x) {
                return high;
            }
            if (arr[low] >= x) {
                return low;
            }

            int mid = low + (high - low) / 2;
            if (arr[mid] <= x && arr[mid + 1] > x) {
                return mid;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    public static int[] getKClosestNums(int[] arr, int k, int x) {
        int len = arr.length;
        int[] result = new int[k];

        // get the nearest numbers to the pivot x using binary search.
        int crossOverIndex = findCrossOver(arr, 0, len - 1, x);

        // use two pointer approach to get the closest k numbers
        int rightIndex = crossOverIndex + 1;
        int leftIndex = arr[crossOverIndex] == x ? crossOverIndex - 1 : crossOverIndex;

        int count = 0;

        while (leftIndex > 0 && rightIndex < len && count < k) {
            if (x - arr[leftIndex] <= arr[rightIndex] - x) {
                result[count++] = arr[leftIndex--];
            } else {
                result[count++] = arr[rightIndex++];
            }
        }

        while (leftIndex > 0 && count < k) {
            result[count++] = arr[leftIndex--];
        }

        while (rightIndex < len && count < k) {
            result[count++] = arr[rightIndex++];
        }

        return result;
    }

    private static void printArr(int[] kClosestNums) {
        StringBuilder sb = new StringBuilder("[");
        for (int num : kClosestNums) {
            sb.append(num).append(", ");
        }
        sb.append("]");
        System.out.println(sb.toString());
    }

    public static void main(String[] args) {
        int[] arr = { 12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56 };

        printArr(getKClosestNums(arr, 4, 35));

    }

}