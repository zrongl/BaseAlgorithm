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

static pthread_key_t key;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;
pthread_mutex_t env_mutex = PTHREAD_MUTEX_INITIALIZER;
extern char **environ;

void
destroy(void *p)
{
    printf("begin destroy\n");
    free(p);
}

static void
thread_init(void)
{
    pthread_key_create(&key, destroy);
}

char *
getenv(const char *name)
{
    unsigned long i, len;
    char *envbuf;
    pthread_once(&init_done, thread_init);
    pthread_mutex_lock(&env_mutex);
    envbuf = (char *)pthread_getspecific(key);
    if (envbuf == NULL) {
        envbuf = malloc(ARG_MAX);
        if (envbuf == NULL) {
            pthread_mutex_unlock(&env_mutex);
            return(NULL);
        }
        pthread_setspecific(key, envbuf);
    }
    len = strlen(name);
    for (i = 0; environ[i] != NULL; i++) {
        if ((strncmp(name, environ[i], len) == 0) &&(environ[i][len] == '=')) {
            strcpy(envbuf, &environ[i][len+1]);
            pthread_mutex_unlock(&env_mutex);
            return(envbuf);
        }
    }
    pthread_mutex_unlock(&env_mutex);
    return(NULL);
}
