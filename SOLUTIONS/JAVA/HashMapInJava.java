import java.util.*;
public class HashMapInJava {
    public static void main(String args[]) {
        //Creation
        HashMap<String, Integer> map = new HashMap<>();
        
        //Insertion
        map.put("India", 120);
        map.put("US", 30);
        map.put("China", 150);
 
        System.out.println(map);
 
 
        map.put("China", 180);
        System.out.println(map);
 
        //Searching
        if(map.containsKey("Indonesia")) {
            System.out.println("key is present in the map");
        } else {
            System.out.println("key is not present in the map");
        }
 
        System.out.println(map.get("China")); //key exists
        System.out.println(map.get("Indonesia")); //key doesn't exist
 
        //Iteration (1)
        for( Map.Entry<String, Integer> e : map.entrySet()) {
            System.out.println(e.getKey());
            System.out.println(e.getValue());
        }
 
        //Iteration (2)
        Set<String> keys = map.keySet();
        for(String key : keys) {
            System.out.println(key+ " " + map.get(key));
        }
 
        //Removing
        map.remove("China");
        System.out.println(map);
 
 
    }
 
}

Java HashMap example to replace() elements
Here, we see different ways to replace elements.

import java.util.*;  
class HashMap3{  
 public static void main(String args[]){  
   HashMap<Integer,String> hm=new HashMap<Integer,String>();    
      hm.put(100,"Amit");    
      hm.put(101,"Vijay");    
      hm.put(102,"Rahul");   
      System.out.println("Initial list of elements:");  
     for(Map.Entry m:hm.entrySet())  
     {  
        System.out.println(m.getKey()+" "+m.getValue());   
     }  
     System.out.println("Updated list of elements:");  
     hm.replace(102, "Gaurav");  
     for(Map.Entry m:hm.entrySet())  
     {  
        System.out.println(m.getKey()+" "+m.getValue());   
     }  
     System.out.println("Updated list of elements:");  
     hm.replace(101, "Vijay", "Ravi");  
     for(Map.Entry m:hm.entrySet())  
     {  
        System.out.println(m.getKey()+" "+m.getValue());   
     }   
     System.out.println("Updated list of elements:");  
     hm.replaceAll((k,v) -> "Ajay");  
     for(Map.Entry m:hm.entrySet())  
     {  
        System.out.println(m.getKey()+" "+m.getValue());   
     }  
 }  
}  


