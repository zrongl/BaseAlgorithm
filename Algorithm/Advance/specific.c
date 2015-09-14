//
//  specific.c
//  Algorithm
//
//  Created by ronglei on 15/7/2.
//  Copyright (c) 2015年 ronglei. All rights reserved.
//

// http://blog.csdn.net/cywosp/article/details/26469435

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <pthread.h>
#include <stddef.h>
#include <unistd.h>

#define NUM_THREADS 5

static pthread_key_t key;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;
pthread_mutex_t env_mutex = PTHREAD_MUTEX_INITIALIZER;
extern char **environ;

void
destroy(void *p)
{
    printf("%p thread destroy\n", pthread_self());
    free(p);
}

static void
specific_init(void)
{
    pthread_key_create(&key, destroy);
}

void *
thread_fun()
{
    char *buf;
    printf("%lu specific key\n", key);
    buf = pthread_getspecific(key);
    
    if (buf == NULL) {
        buf = malloc(50 * sizeof(char));
        sprintf(buf, "%p thread function", pthread_self());
        pthread_setspecific(key, buf);
    }
    
    printf("%s\n", pthread_getspecific(key));
    
    return NULL;
}

void
thread_specific()
{
    pthread_once(&init_done, specific_init);
    
    specific_init();
    
    int rc,t;
    pthread_t thread[NUM_THREADS];
    
    for( t = 0; t < NUM_THREADS; t++){
        rc = pthread_create(&thread[t], NULL, thread_fun, &t);
        if (rc){
            printf("ERROR; return code is %d\n", rc);
            break;
        }
    }
    
//    pthread_key_delete(key);
    sleep(5);
    
    specific_init();
    
    for( t = 0; t < NUM_THREADS; t++){
        rc = pthread_create(&thread[t], NULL, thread_fun, &t);
        if (rc){
            printf("ERROR; return code is %d\n", rc);
            break;
        }
    }
    
//    pthread_key_delete(key);
}
