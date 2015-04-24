#ifndef THREADPOOL_H
#define THREADPOOL_H

class ThreadPool {
public:
    typedef (void*)() Job;

public:
    ThreadPool(size_t numThreads);
    void enqueueJob(Job job);
};

#endif // THREADPOOL_H
