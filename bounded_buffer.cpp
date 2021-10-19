#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include <iostream>

#include <pthread.h>
#include <semaphore.h>
#include <atomic>

using namespace std;

// The length of time the program should run
int run_time;

// The buffer that will be produced into and consumed from. 
int *buffer;
int buffer_size;

// The number of producers and consumers we will have
int num_producers;
int num_consumers;

volatile int counter = 0;
pthread_mutex_t myMutex;
int argc, char *argv[]
void *mutex_testing(void *param)
{
        int i;
        for(i = 0; i < 5; i++) {
                pthread_mutex_lock(&myMutex;);
                counter++;
                printf("thread %d counter = %d\n", (int)param,  counter);
                pthread_mutex_unlock(&myMutex;);
        }
}

int main()
{
        int one = 1, two = 2, three = 3;
        pthread_t thread1, thread2, thread3;
        pthread_mutex_init(&myMutex;,0);
        pthread_create(&thread1;, 0, mutex_testing, (void*)one);
        pthread_create(&thread2;, 0, mutex_testing, (void*)two);
        pthread_create(&thread3;, 0, mutex_testing, (void*)three);
        pthread_join(thread1, 0);
        pthread_join(thread2, 0);
        pthread_join(thread3, 0);
        pthread_mutex_destroy(&myMutex;);
        return 0;
}

// TODO: Declare the semaphores that you will need to implement this algorithm
//       Semaphores are of type sem_t

// TODO: Declare a mutex that you will use in your implementation.
//       Use type pthread_mutex_t

// TODO: Declare any other global variables you will need to 
//       use to implement your algorithm



// These atomic variables will be used simply to generate unique numbers
// to identify each thread.
atomic_int producer_num(0);
atomic_int consumer_num(0);



// This is the function that will be executed by each producer thread.
void * producer(void * arg)
{

    // Set my unique thread number, to be used in the output statements below.
    int myNum = producer_num.fetch_add(1) + 1;
 
    while(true) 
    {
        void
inc(std::atomic<int>& a)
{
  while (true) {
    a = a + 1;
    printf("value %d\n", a.load());
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}
        // TODO: Sleep for a random amount of time between 1 and 5 seconds
        //       Make sure to save the amount of time that was slept, so it can 
        //       be printed out below.



        int item;
        
        {
  std::atomic<int> a(0);
  std::thread t1(inc, std::ref(a));
  std::thread t2(inc, std::ref(a));
  std::thread t3(inc, std::ref(a));
  std::thread t4(inc, std::ref(a));
  std::thread t5(inc, std::ref(a));
  std::thread t6(inc, std::ref(a));

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  return 0;

        // TODO: "Produce" an item by generating a random number between 1 and 100 and 
        //       assigning it to "item"

        

        // TODO: Implement the meat of the producer algorithm, using any semaphores and
        //       mutex locks that are needed to ensure safe concurrent access.
        //
        //       After producing your item and storing it in the buffer, print a line
        //       in the following format:
        //
        //       <myNum>: slept <seconds>, produced <item> in slot <buffer slot>
        //
        //       For example: 
        //       7: slept 5, produced 27 in slot 2

    }

}

void * consumer(void * arg)
{
    // Set my unique thread number, to be used in the output statements below.
    int myNum = consumer_num.fetch_add(1) + 1;
    
    while(true) {
         a = a + 1;
    printf("value %d\n", a.load());
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

        // TODO: Sleep for a random amount of time between 1 and 5 seconds
        //       Make sure to save the amount of time that was slept, so it can 
        //       be printed out below.

        
        // The item that will be consumed
        int item;
     {
  std::atomic<int> a(0);
  std::thread t1(inc, std::ref(a));
  std::thread t2(inc, std::ref(a));
  std::thread t3(inc, std::ref(a));
  std::thread t4(inc, std::ref(a));
  std::thread t5(inc, std::ref(a));
  std::thread t6(inc, std::ref(a));

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  return 0;
        
        // TODO: "Consume" an item by retrieving the next item from the buffer.

        

        // TODO: Implement the meat of the consumer algorithm, using any semaphores and
        //       mutex locks that are needed to ensure safe concurrent access.
        //
        //       After consuming your item and storing it in "item", print a line
        //       in the following format:
        //
        //       <myNum>: slept <seconds>, produced <item> in slot <buffer slot>
        //
        //       For example: 
        //       2: slept 3, consumed 22 from slot 2



    }
}


int main(int argc, char ** argv)
{
    pthread_mutex_init(&mutex;, 0);
    pthread_cond_init(&cond;, 0);

    pthread_t pThread, cThread;
    pthread_create(&pThread;, 0, producer, 0);
    pthread_create(&cThread;, 0, consumer, 0);
    pthread_join(pThread, NULL);
    pthread_join(cThread, NULL);

    pthread_mutex_destroy(&mutex;);
    pthread_cond_destroy(&cond;);
    return 0;
}
    // Usage: bounded_buffer <run_time> <buffer_size> <num_producers> <num_consumers>


    // TODO: Process the command line arguments. If there are not enough arguments, or if any of the 
    //       arguments is <= 0, exit with an error message.
    


    // TODO: Allocate your buffer as an array of the correct size based on the command line argument
    

    // TODO: Initialize the semaphore(s) you are using in your algorithm.
    //       Use the function sem_init() - see https://man7.org/linux/man-pages/man3/sem_init.3.html
    //   


    // Initialize the random number generator (see https://man7.org/linux/man-pages/man3/srand.3.html)
    srand(time(NULL));


    // Start the producer and consumer threads.

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for (int i = 0; i < num_producers; ++i) {
        pthread_t thread_id;
        pthread_create(&thread_id, &attr, producer, NULL);
    }

    for (int i = 0; i < num_consumers; ++i) {
        pthread_t thread_id;
        pthread_create(&thread_id, &attr, consumer, NULL);
    }


    // Now the main program sleeps for as long as the program is supposd to run (based on the command line
    // argument). While the main thread is sleeping, all of the child threads will be busily producing and consuming.
    sleep(run_time);

    // When the main program is done sleeping, we exit. This will cause all the threads to exit.
    // In other applications, the main program might want to wait for the child threads to complete. 
    // This is accomplished with the pthread_join() function (https://man7.org/linux/man-pages/man3/pthread_join.3.html)
    exit(0);
}
