import java.util.Arrays;
import java.util.*;
public class Sort
{
 
    static void sorted(String arr[], int n)
    {
        // base case
        if (n == 1)
            return;
      
        // general case
        // compares two strings
        // swap if i>i+1
        for (int i=0; i<n-1; i++)
            if (arr[i].compareTo(arr[i+1]) > 0)
            {
	        // create temp string to hold value of a[i]
                String temp = arr[i];
   	        // swap a[i] with a[i+1]
                arr[i] = arr[i+1];
	        // set arr[i+1] = temp holding a[i]
                arr[i+1] = temp;
            }
      
        // recursive call
        // decrease size by one each iteration
        sorted(arr, n-1);
    }
     
public static void main(String[] args)
{
     Scanner s = new Scanner(System.in);

     // prompt user to declare number of elements to be put into array
     System.out.println("Enter number of elements: ");
     int m = s.nextInt();

     // verify user enters more than two numbers
     // if user enters less than 3, exit program
     if(m<3)
     {
         System.out.println("Error. Exiting Program");
	 return;
     }


     // create string based off of how many elements the user enters
     String[] array = new String[m];


     // prompt user to enter strings to be put into the array 
     System.out.println("enter strings to be sorted: ");
     for(int i=0; i < m; i++)
     {
	 array[i] = s.next();
     } 
     
     // print out the elements of array on separate lines 
     for(int i=0; i<array.length; i++)
     {
	System.out.println(array[i]);
     }

     // concatenate the array of strings into one string with spaces
     String str = "";
     for(int i=0; i<array.length; i++)
     {
        str += array[i]+" ";
     }

     // print out concatenated string
     System.out.println();
     System.out.println(str);
     System.out.println();



     // call sort function
     sorted(array,m);
     

     // print sorted array 
     System.out.println("Sorted Array:");
     for(int i=0; i < m; i++)
     {
	System.out.println(array[i]);
     }



     // copy array into string buffer
     StringBuffer sb = new StringBuffer();
     for(int i=0; i < m; i++)
     {
	sb.append(array[i]);
	
     }
     
     // print string buffer on one line 
     System.out.println();
     System.out.println("String Buffer:");
     System.out.println(sb);

   
     // string buffer with spaces between words
     StringBuffer concatBuff = new StringBuffer();
     for(int i=0; i < m; i++)
     {
	concatBuff.append(array[i]);
	concatBuff.append(" ");
	
     }

     // print out string buffer with spaces in-between words
     System.out.println();
     System.out.println("String Buffer with spaces:");
     System.out.println(concatBuff);
     
}
}

     

        
   