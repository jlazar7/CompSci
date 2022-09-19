#include "UnsortedType.h"

//constructor
UnsortedType::UnsortedType()
{
  length = 0;
}

//check whether the list is full
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEM);
}

//check how many elements are in this list
int UnsortedType::GetLength( ) const
{
  return length;
}

//check whether there is element in this list
bool UnsortedType::IsEmpty() const
{
  return (length == 0);
}

//Pre: the list should not be full
// Post: item is in the list.
void UnsortedType::InsertItem(ItemType item)
{
  info[length] = item;
  length++;
}

// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged.
void UnsortedType::RetrieveItem(ItemType& item, bool& found) 
{
  bool moreToSearch;
  int location = 0;
  found = false;
  moreToSearch = (location < length);
  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    { case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}

// Pre: item's key has been inititalized.
//	One and only one element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item�s.
void UnsortedType::DeleteItem ( ItemType  item ) 
{    
  int  location  =  0 ;

  while (item.ComparedTo (info[location])  !=  EQUAL)
         location++;
  // move last element into position where item was located

  info [location] = info [length - 1 ] ;
  length-- ; //the length of the list is decreased
}

// Pre:  N/A   
// Post: the list is empty
void UnsortedType::MakeEmpty()
{
   length = 0;
}


// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
void UnsortedType::ResetList ( )  
{    
  currentPos  =  -1 ;
}

// Pre:  List has been initialized. Current position is 
//       defined. 
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
void UnsortedType::GetNextItem ( ItemType&  item )  
{
  currentPos++  ;
  item = info [currentPos] ;
}

//Pre: List has been initialized and is not empty. The list has at least one copy of the item.
//Post: List does not have any copies of the item.  
void UnsortedType:: DeleteAllItems ( ItemType item )
{
   ResetList();
   length = GetLength(); 
   for(int i=0; i<length; i++)
   {
      ItemType current = info [i] ;
      GetNextItem(current);
      
      if(current.ComparedTo (item) == EQUAL && i != length)
      { 
	   DeleteItem(item);
	   info[i]=info[length-1];
	   //DeleteItem(info[length]);
	   GetNextItem(current);
      }
   }
}

// Pre: List has been initialized
// Post: List should have at least one copy of the item. 
void UnsortedType:: InsertItem ( ItemType item, bool & done) 
{
   ResetList();
   int length = GetLength();
   for(int i=0; i < length; i++)
   {
      ItemType current = info[i];
      GetNextItem(current);  
      if(current.ComparedTo(item) == EQUAL) 
      {   
	done = false;
        break;
      }
      else
      {
	GetNextItem(current);
	if(i==length-1 && current.ComparedTo(item) != EQUAL)
	{
	    InsertItem(item);
	    done = true;
 	}
      }

      
}
}
// Pre: ListONE has been initialized & is not empty
// Post: The List1 contains all the numbers less than or equal to the defined 'item'
// 	 List2 contains all the numbers greater than the defined 'item'
void UnsortedType::SplitList(ItemType item, UnsortedType& listOne, UnsortedType& listTwo) 
{
 
  ResetList(); 
  listOne.MakeEmpty();
  listTwo.MakeEmpty();

  for(int i=0; i< GetLength(); i++)
  {
     ItemType current = info [i] ;
     GetNextItem(current);
     if(GREATER == current.ComparedTo(item))
     {
	listTwo.InsertItem(current);
     }
     else
     {
        listOne.InsertItem(current);
     }
  }
}

// Pre: List has been initialized. listOne and listTwo have been initialized. 
// Post: List contains all items from listOne and listTwo. 
// If there are duplicate items, keep all of them in the list.
void UnsortedType::MergeList(UnsortedType& listOne, UnsortedType& listTwo)
{
   listOne.ResetList();
   for(int i = 0; i < GetLength(); i++)
   {
      ItemType current = info [i] ;
      GetNextItem(current);
      InsertItem(current);
   }

   listTwo.ResetList();
   for(int i=0; i < GetLength(); i++)
   {
      ItemType current = info [i] ;
      GetNextItem(current); 
      InsertItem(current);
   }
}




