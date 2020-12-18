#include <iostream>
#include <thread>         
#include <chrono> 
  
using namespace std;
 
class Process_Manager
{
        private :
 
                int *arr ;
                 int *thread_Arr;
                int front, rear ;
                int MAX ;
        public :
                Process_Manager( int maxsize = 10 ) ;
                void addq (  ) ;
                void display_process(string str);
                void display_thread(string str);
                int delq( ) ;
                int moveThread( );
                void ready_queue(int data);
                void another_queue(Process_Manager obj);
                void unwait_fun(Process_Manager obj,bool flag);
                void createThread ( int id );
                void display_queue_list();
} ;
 
Process_Manager :: Process_Manager( int maxsize )
{
        MAX = maxsize ;
        arr = new int [ MAX ];
        thread_Arr = new int[MAX];
        front = -1 ;
        rear = -1 ;
}
 
void Process_Manager :: addq (  )
{
	int b ;
	while(b != -1){
		int pid ;
       cout << "Enter the process_pid that you want to create \n";
	   cin >> pid ;
	
        if ( rear == MAX - 1 )
        {
                cout << "\nQueue is full and you can't create new process'" ;
                return ;
        }
        rear++ ;
        arr[rear] = pid ;
        if ( front == -1 )
                front = 0 ;		
           
         cout << " A new process is create with process_id " << pid << endl;
         cout << " Futher creating process press any number excert -1 \n ";
		 cin >> b ;    
	}

}
void Process_Manager :: createThread ( int id )
{
	int b ;
	while(b != -1){
		int thread_id ;
       cout << "Enter the thread_pid that you want to create \n";
	   cin >> thread_id ;
	
        if ( rear == MAX - 1 )
        {
                cout << "Queue is full and you can't create new process \n'" ;
                return ;
        }
        rear++ ;
        thread_Arr[rear] = thread_id ;
        if ( front == -1 )
                front = 0 ;		
           
         cout <<  " A new thread is create with thread_id " << thread_id << endl;
         cout << " Futher creating thread press any number excert -1 \n ";
		 cin >> b ;    
	}

}
void Process_Manager ::  display_process(string str){
	 int i ;
	 int len = 0 ;
	 for(int i=0;i<5;i++){
	 	if(arr[i] != 0 && arr[i] < 1000){
	 		cout << arr[i] << " ";
	 		 	len++ ;
		 }
	 	
	
	 }
	 cout << endl ;
	 cout << len << " process in the " << str  << endl ;
}
void Process_Manager ::  display_thread(string str){
	 int i ;
	 int len = 0 ;
	 for(int i=0;i<5;i++){
	 	if(thread_Arr[i] != 0 && thread_Arr[i] < 1000){
	 		cout << "  tid_" << thread_Arr[i] << "  ";
	 		 	len++ ;
		 }
	 	
	
	 }
	 cout << endl ;
	 cout << len << " thread in the " << str  << endl ;
}

int Process_Manager :: delq( )
{
        int data ;
 
        if ( front == -1 )
        {
                cout << "\nQueue is Empty" ;
                return 0 ;
        }
 
        data = arr[front] ;
        arr[front] = 0 ;
        if ( front == rear )
                front = rear = -1 ;
        else
                front++ ;
 
        return  data ;
}
int Process_Manager :: moveThread( )
{
        int data ;
 
        if ( front == -1 )
        {
                cout << "\nQueue is Empty" ;
                return 0 ;
        }
 
        data = thread_Arr[front] ;
        thread_Arr[front] = 0 ;
        if ( front == rear )
                front = rear = -1 ;
        else
                front++ ;
 
        return  data ;
}

void Process_Manager::another_queue(Process_Manager obj){
	int data = obj.delq() ;

     if ( rear == MAX - 1 )
        {
                cout << "\nQueue is full and you can't create new process'" ;
                return ;
        }
        rear++ ;
        arr[rear] = data ;
        if ( front == -1 )
                front = 0 ;	
       cout << "one process enter into waiting queue \n";         
                
}
void Process_Manager :: display_queue_list() {
   const char* arr_item[] = {"Running_queue","Ready_queue","Waiting_Queue","New_Queue","Terminated_queue"};
   for(int i = 0;i<5;i++){
   	  cout << i+1 << " . " << arr_item[i] << endl ;
   } 
  
}
void Process_Manager::unwait_fun(Process_Manager obj ,bool flag){
	 if(flag){
	 	 this_thread::sleep_for (chrono::seconds(5));
	 } 
	
	int data = obj.moveThread() ;

     if ( rear == MAX - 1 )
        {
                cout << "\nQueue is full and you can't create new process'" ;
                return ;
        }
        rear++ ;
        thread_Arr[rear] = data ;
        if ( front == -1 )
                front = 0 ;	
       cout << "one process enter into ready  queue \n";         
                
}

int main( )
{
        
    Process_Manager running_queue(5);
    Process_Manager ready_queue(5);
    Process_Manager wait_queue(5);
    Process_Manager terminated_queue(5);
    Process_Manager new_queue(5);
    int choice ;
        
        cout <<  "For executing command choose the option \n"; 
        cout << " ------------------------------------------------- \n";
        cout << "  Press 1 for display the queue list \n";
        cout << "  Press 2 for creating a process in a queue \n";
        cout << "  Press 3 for display the process in a queue \n";
        cout << "  Press 4 for createing a thread in a queue \n";
        cout << "  Press 5 for display the thread in a queue \n";
        cout << "  Press 6 for Performing unwait_command to manipulate queue \n";
        cout << "  Press 7 for checking the manipulated waiting queue \n";
        cout << "  Press 8 for checking the manipulated ready queue \n";
        cout << "  Press 9 for performing EOQUANTUM command \n";
        cout << "  Press 10 for perforimg EOLIFE command \n";
        cout << "  Press 11 for perforimg WAIT command \n";
        cout << "  Press 12/13/14/15 for  displaying thread in a particular queue \n";
        cout << "  Press 16 for exit \n";
       
        cout << " ------------------------------------------------- \n";
      
         while( 1){
         	  
         	  cout << " choose a option : ";
              cin >> choice ;
                switch(choice){
          	case 1 :
          		new_queue.display_queue_list();
          		break;
         	case 2 :
                ready_queue.addq();
			  	break;
			case 3 :
			  	ready_queue.display_process("READY_QUEUE");	
			  	break;
			case 4:
			   ready_queue.createThread(10)  ;
			   break;     
			case 5:
			    ready_queue.display_thread("READY_QUEUE");
				break;  
			case 6:
			   ready_queue.unwait_fun(wait_queue ,false)  ;	
				break ;	
			case 7:
			    wait_queue.display_thread("WAIT_QUEUE");
				break;	
				  
			case 8:
			   ready_queue.display_thread("MANIPULATED_READY_QUEUE ");
			   break;	
			case 9:
			   ready_queue.unwait_fun(running_queue,true)  ;    
				break;	
			case 10:
			   terminated_queue.unwait_fun(running_queue,false)  ; 
			   break;	
			case 11:
			   wait_queue.unwait_fun(running_queue ,false)  ;   
				break ;	
			case 12 :
          		running_queue.createThread(10 ) ;
				  break;
			case 13:
			    running_queue.display_thread("running_queue");
			    break;
			case 14:
          		wait_queue.createThread(10 ) ;
				break;		
			case 15:
			    terminated_queue.display_thread("terminated_queue");      
			   break;	
			case 16 :
		    	exit(1);  	
			default:
			   break ;    
			    
		  }
		  
		 }
       
 
 
        return 0;
}
