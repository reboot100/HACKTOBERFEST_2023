public class SubArrayWithGivenSum {
    public static void find(int arr[],int sum){
        int currSum=0;
        int start=0;
        for(int i=0;i<arr.length;i++){
            currSum+=arr[i];
            while(currSum>sum && start<=i){
                currSum -= arr[start];
                start++;
            }
            if(currSum==sum){ 
                System.out.println("Subarray with given sum found between index = "+start+" to "+i);
                return;
            }
        }
        System.out.println("No subarray exists");
    }
    public static void main(String[] args) {
        int arr[]={4,5,1,2,6,7};
        int sum=8;
        find(arr, sum);
    }
}
