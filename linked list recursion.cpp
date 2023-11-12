/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

 struct node {
  int data;
  node* next;
};

//////////////////////////////////////////////////////////////////////

class Linked_List 

{
    public:
    
    node* head;
    
    void append (node* current, int newdata) {
         
         if (head== NULL) 
         { 
             head = new node;
        head -> data = newdata;
        head -> next = NULL;
        
         }
         
        else if (current-> next == NULL) {
            
        node* newnode= new node;
        newnode -> data = newdata;
        newnode -> next = NULL;
        current -> next = newnode;
            
        }
         else {
                append (current->next, newdata);
                }
                
            }
        
        
        
        
    //////////////////////////////////////////////////////////////////
    
    void display (node* current) {
        
        
        if (current != NULL) {
            cout<<current -> data<<" ";
            display ( current -> next);
            
        }
        
    }
    
    ///////////////////////////////////////////////////////////////////
    
    int nodeCtr (){
        int c=0;
         node* current = head;
                    
                while(current != NULL) {
                    
                    current = current -> next;
                    c++;
                }
        
        return c;
    }
    
    /////////////////////////////////////////////////////////////////////
    
    void  insert (node* current , int newdata, int pos, node* prev ) {
        
        if (pos>nodeCtr()+1 ^ pos<=0)
        
        cout<<"Invalid"<<endl;
        
        else{
            
            if (pos == 1) {
            
            node* newnode= new node;
            newnode -> data = newdata;
            newnode -> next = NULL;
            
           if (current != head)
          { prev -> next = newnode; 
           newnode -> next = current;}
           
           else {head = newnode;
                 newnode -> next = current;}
               
           
           
        }
            else {
                
                insert (current->next, newdata , pos-1 , current);
                
            }
            
        }
        }
    
    ///////////////////////////////////////////////////////////////////////
    
    void delet (node* current , int pos , node* prev)
    
    {     
        if (current != NULL && pos > 0 && pos <= nodeCtr() ) {
              
         if(pos==1 && prev== NULL){ 
             
             head = head->next;
               delete current ;
         }
           
         else{
              
          if (pos == 1 ){
            
           prev -> next = current-> next ;
           delete current ;
           
         }
            else delet ( (current -> next) , pos-1 , current );
        }
            
        }
        else {cout<<"invalid"<<endl;} 
              
          
    }
    
    ////////////////////////////////////////////////////////////////////////
    
    int dequeue ()
    
    {   int x = head -> data;
        node* temp = head;
        head = head -> next;
        delete temp;
        return x;
    }
    
    //////////////////////////////////////////////////////////////////////////
    
    void revdisplay (node* current)
    
    {  if (current != NULL)
        {
        revdisplay (current-> next);
        cout<< current -> data << " ";
        }
        
     } 
    
  //////////////////////////////////////////////////////////
    
    void insertAtMid(int newdata)
    {
        insert(head, newdata, ((nodeCtr())/2)+1 , NULL);
    }
      
  /////////////////////////////////////////////////////////
  
    void empty(node* current)
    {   
        if (current != NULL) {
            
        empty (current -> next);
         delete current;
         
        }
        
        head=NULL;
    }
    
    /////////////////////////////////////////////////////////////
    
    int nodedata (node* current, int pos)
    {   
        if (head != NULL && pos <= nodeCtr() && pos > 0){
            
        if (pos == 1 && current != NULL ) {return current-> data;}
        else { return nodedata (current -> next, pos-1);} 
            
        }
        else return 0;
      
     }
    
    /////////////////////////////////////////////////////////////
    
    node* nodeptr (node* current, int pos)
    {   
        if (head != NULL && pos <= nodeCtr() && pos > 0) {
            
        if (pos == 1 && current != NULL ) { return current;}
        else { return nodeptr (current -> next, pos-1);} 
        }
        else return NULL;
    } 
    
   ///////////////////////////////////////////////////////////////
    
    int palcheck () {
        
        int n=1;
        for (int i = 1; i <= (nodeCtr()/2); i++ )
        {
            if (nodedata(head, i) != nodedata(head, nodeCtr()-i+1))
            n=0;
        }
        return n;
     }
    
    /////////////////////////////////////////////////////////////////////
    
    void remdup () {
        
        
        for (int i = 1; i <= nodeCtr(); i++ )
        
        {    for (int j=i+1 ; j <= nodeCtr(); j++ )
           {
            if (nodedata(head,i) == nodedata(head,j))
            {
                delet(head,j,NULL);
                j--;
             }
            
           }
            
        }
        
     }
    
    };
    
     //////////////////////////////////////////////////////////////
    void merge (Linked_List &a, Linked_List &b)
    
    { if (a.head != NULL && b.head != NULL) 
    
       {
        for (int i=1; i<= b.nodeCtr() ; i++ )
        {
            int j=1;
            
                while ((a.nodedata(a.head,j) < b.nodedata(b.head,i)) && (j <= a.nodeCtr()) )
                
                {
                    j++;
                }
                
                a.insert (a.head, b.nodedata (b.head,i) , j , NULL);
            
            
        } 
       }
        
      }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////




int main()
{
    Linked_List myll;
    
    //myll.append(myll.head, 1);
    //myll.append(myll.head, 7);
    //myll.append(myll.head, 8);
    //myll.insert(myll.head,9,4,NULL);
    //myll.insert(myll.head,11,5,NULL);
    //myll.append(myll.head,19);
    //myll.insert(myll.head,0,1,NULL);
    
    //myll.delet(myll.head,1,NULL);
    //myll.delet(myll.head,0,NULL);
    //myll.insertAtMid(16);
    //myll.insertAtMid(0);
    //cout<<myll.head<<endl;
    //cout<<myll.nodeCtr()<<endl;
    //cout<<myll.nodedata(myll.head,1)<<endl;
    //cout<<(myll.nodeptr(myll.head,1))->data<<endl;
    
    //myll.display(myll.head); cout<<endl;
    //myll.revdisplay(myll.head);
    //cout<<endl<<myll.palcheck()<<endl;
    //myll.remdup();
    myll.display(myll.head);
    cout<<endl;
    
    Linked_List myll2;
    //myll2.append(myll2.head, 5);
    //myll2.append(myll2.head, 3);
    //myll2.append(myll2.head, 6);
    //myll2.append(myll2.head, 7);
    //myll2.append(myll2.head, 11);
    //myll2.insert(myll2.head,6,0,NULL);
    //myll2.insertAtMid(6);
    
    myll2.display(myll2.head);
    cout<<endl;
    
    merge (myll, myll2);
    myll.display(myll.head);
 
    myll.empty(myll.head);
    //myll.display(myll.head);
    myll2.empty(myll2.head);
    //myll2.display(myll2.head);
  return 0;
}
