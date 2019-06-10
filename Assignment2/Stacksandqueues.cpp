#include <iostream>
  using namespace std;



class node {
public:
	int val;
	node*next;
	//constructor
	node( int newval) {
		val = newval;
		next = NULL;
	}
};




        class linkedlist  {
        public:
        node*head;
        //node*getTail;
       // constructor
       linkedlist() {
       head = NULL;
       //tail = NULL;
         }
           
 


      void insert (int  newval) {
       node*temp = new node(newval);
       temp->next = head;
       head = temp;
        }

     

    node* getTail () {
       node*curr = head;
       while ( curr!= NULL) {
         curr = curr->next;
             }
          return curr;
              }


      
        void delet () {
        node*temp = head;
        head = head->next;
        delete temp;
          }

    
int countitems () {
	node*curr = head;
	int count = 1;
	while (curr->next != NULL) {
		curr = curr->next;
		count ++; 
	}
	return count;
}




void deletAt (int pos) {
	if (pos > countitems()) {
		cout << "Not a valid position" << endl;
	}

	if ( pos==1) {
		delet();
	}

	else {
		node*curr = head;
		int count = 0;
		while ( count != (pos-1)) {
			curr = curr->next;
			count++;
		}
		node * temp = curr->next;
		curr->next=(curr->next)->next;
		delete temp;
	}
}






void display() {
	node*curr = head;
	while ( curr != NULL) {
		cout << curr->val << "->";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}
    
};

  
      
class stack {
	public:
	node*top;
	linkedlist l1;
	stack () {
		top = l1.head;
	}


	int count () {
		return l1.countitems();
	}


	void push (int val) {
		l1.insert (val);
		top = l1.head;
	}


	void pop () {
		l1.delet();
		top = l1.head;
	} 


	void display(){
		l1.display();
	}


	bool isEmpty() {
		if (top == NULL) { return true;}
		return false ;
	}

};



          class queue {
		     public:
		      node*front;
		      node*end;
		      linkedlist l1;
		             queue () {
		             front = l1.head;
		             end = l1.getTail();
                         }

          int count () {	

             return l1.countitems(); 

                }



           void enqueue (int val) {
		      l1.insert (val);
		     front = l1.head;
                 }


            void dequeue () {

             	 l1.deletAt (6);

                  }




            void display () {	

                	l1.display();

                   }


            bool isEmpty () {

		       if (front == NULL) { return true;}
		         return false;
                   }


                 };
 
                   

int main () {
	linkedlist l1;
	for (int i= 6; i>0; i--) {
		l1.insert (i);
	}
	l1.display();
	l1.delet();
	l1.deletAt(2);
        l1.display();

	stack s1;
	for (int i= 6; i>0; i--) {
		s1.push (i);
	}

	s1.display();
	s1.pop();


	queue q1;
	for (int i=6; i>0; i--) {
		q1.enqueue(i);
	}
	q1.display();
	q1.dequeue();
}



