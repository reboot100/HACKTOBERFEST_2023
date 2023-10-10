public class SubArrayWithMaxSum {
    public static int sum(int arr[]){
        int maxStart=arr[0];
        int maxEnd=arr[0];
        for(int i=1;i<arr.length;i++){
            maxEnd=Math.max(arr[i],maxEnd+arr[i]);
            maxStart=Math.max(maxStart,maxEnd);
        }
        return maxStart;
    }
    public static void main(String[] args) {
        int arr[]={1,2,-3,-4,-5,6,7,8,-9};
        int maxSum=sum(arr);
        System.out.println("Max subarray sum is "+maxSum);
    }
}
