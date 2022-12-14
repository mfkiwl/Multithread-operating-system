//
// Created by os on 7/28/22.
//

#ifndef PROJECT_BASE_SYSCALL_CPP_H
#define PROJECT_BASE_SYSCALL_CPP_H
#include "syscall_c.h"
#include "../h/pcb.hpp"
#include "../h/kernelSem.hpp"
class PCB;
class KernelSem;
typedef PCB* thread_t;
typedef KernelSem* sem_t;

void* operator new (size_t);
void operator delete (void*);

class Thread {
public:
    Thread (void (*body)(void*), void* arg);
    virtual ~Thread ();
    int start ();
    static void dispatch ();
    //static int sleep (time_t);
    friend void wrapper(void *arg);
protected:
    Thread ();
    virtual void run () {}
private:
    thread_t myHandle;
};

class Semaphore {
public:
    Semaphore (unsigned init = 1);
    virtual ~Semaphore ();
    int wait ();
    int signal ();
private:
    sem_t myHandle;
};

/*class PeriodicThread : public Thread {
protected:
    PeriodicThread (time_t period);
    virtual void periodicActivation () {}
};*/
class Console {
public:
    static char getc ();
    static void putc (char);
};
#endif //PROJECT_BASE_SYSCALL_CPP_H
