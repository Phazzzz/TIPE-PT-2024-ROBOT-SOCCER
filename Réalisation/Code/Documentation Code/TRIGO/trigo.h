#ifndef __TRIGO_H___
#define __TRIGO_H___

#ifdef __cplusplus
extern "C" {
#define __TR_INLINE__ inline
#endif

#include <math.h>

#ifndef __TR_INLINE__
#ifdef C99
#define __TR_INLINE__ inline
#else
#define __TR_INLINE__
#endif
#endif

/*-------------------------------
    Taille par défaut des 
    tableaux 
--------------------------------*/
#ifndef TRIGO_ARRAY_SIZE
#define TRIGO_ARRAY_SIZE  20000
#endif

/*------------------------------
  Constantes
--------------------------------*/
static const double size       = (double)TRIGO_ARRAY_SIZE;
static const double period     = 2.0 * M_PI;
static const double freq       = (double)TRIGO_ARRAY_SIZE / ( 2.0 * M_PI );
static const double step       = 2.0 * M_PI / (double)TRIGO_ARRAY_SIZE;
static const double i1         = -M_PI;
static const double i2         = M_PI;

/*---------------------------------------
    Tableaux pour stocker les résultats
    des fonctions de math.h
-----------------------------------------*/
static double v_cos[TRIGO_ARRAY_SIZE];
static double v_sin[TRIGO_ARRAY_SIZE];

/*---------------------------------
  Indique si les tableaux ont été 
  initialisés
-----------------------------------*/
static int is_init = 0;

/*-------------------------------
    Prototypes
--------------------------------*/
__TR_INLINE__ static void init();
__TR_INLINE__ double tr_cos(double);
__TR_INLINE__ double tr_sin(double);


/*-------------------------------
    Définitions
--------------------------------*/

/*
  Initialise les tableaux
*/
__TR_INLINE__ static void init()
{
    int i = -1;
    double *p_cos = v_cos, *p_sin = v_sin;

    while( ++i < TRIGO_ARRAY_SIZE )
    {
    	*p_cos++ = cos( i1 + (double)i * step );
    	*p_sin++ = sin( i1 + (double)i * step );
    }
    
    is_init = 1;
}


/*
  Retourne cos(n), n en radian
*/
__TR_INLINE__ double tr_cos(double n)
{
    if( !is_init ) init();

    n += M_PI;

    if( n < 0.0 ) while( (n += period) < 0.0 );
    else if( n > period ) while( (n -= period) > period );  

    return v_cos[ (int)( n * freq )  ];
}

/*
  Retourne sin(n), n en radian
*/
__TR_INLINE__ double tr_sin(double n)
{
    if( !is_init ) init();

    n += M_PI;

    if( n < 0.0 ) while( (n += period) < 0.0 );
    else if( n > period ) while( (n -= period) > period );

    return v_sin[ (int)( n * freq )  ];
}

#ifdef __cplusplus
}
#endif

#endif /* __TRIGO_H___ */



