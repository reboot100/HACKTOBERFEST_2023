import java.util.*;
public class KthMinMax {
    public static void kthMaxMinNo(int arr[],int k){
        Arrays.sort(arr);
        System.out.println("Kth minimum element is = "+ arr[k-1]);
        System.out.println("Kth maximum number is = "+ arr[arr.length-k]);
    }
    public static void main(String[] args) {
        int arr[]={4,5,2,6,1,0,7};
        int k=3;
        kthMaxMinNo(arr,k);
    }
}
