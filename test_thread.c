// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <pthread.h>
//
// #  include <unistd.h>
// #  define psleep(sec) sleep ((sec))
//
// #define INITIAL_STOCK   20
// #define NB_CLIENTS      5
//
//
// /* Structure stockant les informations des threads clients et du magasin. */
// typedef struct
// {
//    int stock;
//
//    pthread_t thread_store;
//    pthread_t thread_clients [NB_CLIENTS];
//
//    pthread_mutex_t mutex_stock;
//    pthread_cond_t cond_stock;
//    pthread_cond_t cond_clients;
// }
// store_t;
//
// static store_t store =
// {
//    .stock = INITIAL_STOCK,
//    .mutex_stock = PTHREAD_MUTEX_INITIALIZER,
//    .cond_stock = PTHREAD_COND_INITIALIZER,
//    .cond_clients = PTHREAD_COND_INITIALIZER,
// };
//
//
// /* Fonction pour tirer un nombre au sort entre 0 et max. */
// static int get_random (int max)
// {
//    double val;
//
//    val = (double) max * rand ();
//    val = val / (RAND_MAX + 1.0);
//
//    return ((int) val);
// }
//
//
// /* Fonction pour le thread du magasin. */
// static void * fn_store (void * p_data)
// {
//    while (1)
//    {
//       /* Debut de la zone protegee. */
//       pthread_mutex_lock (& store.mutex_stock);
//       pthread_cond_wait (& store.cond_stock, & store.mutex_stock);
//
//       store.stock = INITIAL_STOCK;
//       printf ("Remplissage du stock de %d articles !\n", store.stock);
//
//       pthread_cond_signal (& store.cond_clients);
//       pthread_mutex_unlock (& store.mutex_stock);
//       /* Fin de la zone protegee. */
//    }
//
//    return NULL;
// }
//
//
// /* Fonction pour les threads des clients. */
// static void * fn_clients (void * p_data)
// {
//    int nb = (int) p_data;
//
//    while (1)
//    {
//       int val = get_random (6);
//
//
//       psleep (get_random (3));
//
//       /* Debut de la zone protegee. */
//       pthread_mutex_lock (& store.mutex_stock);
//
//       if (val > store.stock)
//       {
//          pthread_cond_signal (& store.cond_stock);
//          pthread_cond_wait (& store.cond_clients, & store.mutex_stock);
//       }
//
//       store.stock = store.stock - val;
//       printf (
//          "Client %d prend %d du stock, reste %d en stock !\n",
//          nb, val, store.stock
//       );
//
//       pthread_mutex_unlock (& store.mutex_stock);
//       /* Fin de la zone protegee. */
//    }
//
//    return NULL;
// }
//
//
// int main (void)
// {
//    int i = 0;
//    int ret = 0;
//
//
//    /* Creation des threads. */
//    printf ("Creation du thread du magasin !\n");
//    ret = pthread_create (
//       & store.thread_store, NULL,
//       fn_store, NULL
//    );
//
//    /* Creation des threads des clients si celui du magasinn a reussi. */
//    if (! ret)
//    {
//       printf ("Creation des threads clients !\n");
//       for (i = 0; i < NB_CLIENTS; i++)
//       {
//          ret = pthread_create (
//             & store.thread_clients [i], NULL,
//             fn_clients, (void *)i);
//
//          if (ret)
//          {
//             fprintf (stderr, "%s", strerror (ret));
//          }
//       }
//    }
//    else
//    {
//       fprintf (stderr, "%s", strerror (ret));
//    }
//
//
//    /* Attente de la fin des threads. */
//    i = 0;
//    for (i = 0; i < NB_CLIENTS; i++)
//    {
//       pthread_join (store.thread_clients [i], NULL);
//    }
//    pthread_join (store.thread_store, NULL);
//
//
//    return EXIT_SUCCESS;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_1(int arg)
{
    int i;
    i = arg;
    printf("%d \n", i);
    printf("Nous sommes dans le thread.\n");

    /* Pour enlever le warning */
    pthread_exit(NULL);
}

void *thread_2(void *arg)
{
    printf("Nous sommes dans le thread2.\n");

    /* Pour enlever le warning */
    (void) arg;
    pthread_exit(NULL);
}

void *thread_3(void *arg)
{
    printf("Nous sommes dans le thread3.\n");

    /* Pour enlever le warning */
    (void) arg;
    pthread_exit(NULL);
}

void *thread_4(void *arg)
{
    printf("Nous sommes dans le thread4.\n");

    /* Pour enlever le warning */
    (void) arg;
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    int i = 1;
    void *plouf;

    printf("Avant la création du thread.\n");
    plouf = &i;
    printf("%d \n", plouf);
    if (pthread_create(&thread1, NULL, thread_1, i)) {
	perror("pthread_create");
	return EXIT_FAILURE;
    }
    if (pthread_create(&thread2, NULL, thread_2, NULL)) {
	perror("pthread_create");
	return EXIT_FAILURE;
    }
    if (pthread_create(&thread3, NULL, thread_3, NULL)) {
	perror("pthread_create");
	return EXIT_FAILURE;
    }
    if (pthread_create(&thread4, NULL, thread_4, NULL)) {
	perror("pthread_create");
	return EXIT_FAILURE;
    }

    if (pthread_join(thread1, NULL)) {
	perror("pthread_join");
	return EXIT_FAILURE;
    }
    if (pthread_join(thread2, NULL)) {
	perror("pthread_join");
	return EXIT_FAILURE;
    }
    if (pthread_join(thread3, NULL)) {
	perror("pthread_join");
	return EXIT_FAILURE;
    }
    if (pthread_join(thread4, NULL)) {
	perror("pthread_join");
	return EXIT_FAILURE;
    }

    printf("Après la création du thread.\n");

    return EXIT_SUCCESS;
}
