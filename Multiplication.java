import java.util.Random;
public class Multiplication
{
  // method takes two int parameters determining the size of the multiplication table
  static void multiplication(int row, int column) {
     int result;
     int i=0;

     // tab space for formatting 
     System.out.print("\t");

     // printer for column header
     for(int k =1; k<= column; k++)
	System.out.printf("%4s","<"+  k + ">\t ");

     while(i < row)
     {
         System.out.println();

         // printer for row header
         System.out.printf("%4s","<"+  (i+1) + ">\t");
	
         i++;
         for(int j=1; j <= column; j++)
         {
            result = i * j;
            System.out.print(" " + result + "\t");
	   
        }
        
     }
     System.out.println(" ");
  }

  public static void main(String[] args)
  {
      //two random digits for row and column 1-10
      int maxRow = (int)((Math.random() * 10)+1);
      int maxColumn = (int)((Math.random() * 10)+1);

      // call method for 10x10 multiplication table
      multiplication(10,10);

      System.out.println();
      System.out.println("--------------------------------------------------------");

      // call method for random multiplication table
      multiplication(maxRow, maxColumn);

}
}