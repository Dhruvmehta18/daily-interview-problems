
/*
    Hi, here's your problem today. This problem was recently asked by Apple:

    Given a string, we want to remove 2 adjacent characters that are the same, and repeat the process with the new string until we can no longer perform the operation.
*/

public class RemoveAdjDupChar {

    public static String removeAdjDupChar(String string) {
        char[] strArr = string.toCharArray();
        for (int i = 0; i < strArr.length;) {
            int offset = 0;
            boolean flag = false;
            while (i - offset > -1 && i + 1 + offset < strArr.length && strArr[i - offset] != '\0'
                    && strArr[i + 1 + offset] != '\0' && strArr[i - offset] == strArr[i + 1 + offset]) {
                strArr[i - offset] = '\0';
                strArr[i + 1 + offset] = '\0';
                offset++;
                flag=true;
            }
            if(flag) {
                i = i - offset - 1;
            } else{
                i++;
            }
            
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < strArr.length; i++) {
            if (strArr[i] != '\0') {
                sb.append(strArr[i]);
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        String string = "cabba";
        System.out.println(removeAdjDupChar(string));
    }
}
