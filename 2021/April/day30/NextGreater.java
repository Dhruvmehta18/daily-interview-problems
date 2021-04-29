import java.util.Stack;

class NextGreater {

    public static int[] getNextGreaterElementsIndex(int[] arr) {
        int[] result = new int[arr.length];
        Stack<Integer> stack = new Stack<>();

        for (int i = arr.length - 1; i >= 0; i--) {
            while (!stack.empty() && arr[stack.peek()] <= arr[i]) {
                stack.pop();
            }
            result[i] = stack.empty() ? -1 : stack.peek();
            stack.push(i);
        }

        return result;
    }

    private static void printResults(int[] arr) {
        StringBuilder sb = new StringBuilder();
        for (int element : arr) {
            sb.append(element).append(' ');
        }
        System.out.println(sb.toString());
    }

    public static void main(String[] args) {
        int[] arr = { 3, 2, 5, 6, 9, 8 };
        int[] result = getNextGreaterElementsIndex(arr);
        printResults(result);
    }

}