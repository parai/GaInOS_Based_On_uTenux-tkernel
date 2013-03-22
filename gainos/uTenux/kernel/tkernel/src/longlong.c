#include "longlong.h"
//#ifdef __GNUC__
#if   (defined __GNUC__)  || (defined _APP_MC9S12_ ) || (defined _APP_MPC56XX_) \
    || (defined _APP_XC23XX_)
#else
longlong	ltoll( long a )			/* (longlong)a */
{
    longlong ll;
    ll.hi=0;
    ll.lo=a;
    return ll;
}
longlong	ultoll( unsigned long a )		/* (longlong)a */
{
    longlong ll;
    ll.hi=0;
    ll.lo=a;
    return ll;
}
longlong	uitoll( UINT a )			/* (longlong)a */
{
    longlong ll;
    ll.hi=0;
    ll.lo=a;
    return ll;
}
long	lltol( longlong a )			/* (long)a */
{
    /* data loss cann't be avoid */
    return (long)a.lo;
}
unsigned long	lltoul( longlong a )	/* (unsigned long)a */
{
    /* data loss cann't be avoid */
    return a.lo;
}
longlong	ll_add( longlong a, longlong b )	/* a+b */
{
    longlong ll;
    unsigned long tmp;
    ll.hi==a.hi+b.hi;
    tmp = 0xFFFFFFFFu-a.lo;
    if(tmp < b.lo)    /* overflow,add with carry */
    {
        ll.hi++;
    }
    ll.lo=a.lo+b.lo; /* if overflow,ignored it */
    return ll;
}
longlong	ll_sub( longlong a, longlong b )	/* a-b */
{
    longlong ll;
    long tmp;
    ll.hi==a.hi-b.hi;
    tmp=a.lo-b.lo;
    if(tmp<0)    /* overflow,sub hi */
    {
        ll.hi--;
    }
    ll.lo=0xFFFFFFFFu+tmp; /* if overflow,ignored it */
    return ll;
}
extern longlong	ll_mul( longlong a, longlong b );	/* a*b */
extern longlong	li_mul( longlong a, long b );		/* a*b */
longlong	lui_mul( longlong a, UINT b )		/* a*b */
{
    longlong ll;
    ll.hi=a.hi;
    ll.lo=a.lo*b;
    return ll;
}
extern longlong	ll_div( longlong a, longlong b );	/* a/b */
extern longlong	li_div( longlong a, long b );		/* a/b */
longlong	lui_div( longlong a, UINT b )		/* a/b */
{
    longlong ll;
    ll.hi=a.hi;
    ll.lo=a.lo/b;
    return ll;
}
extern longlong	ll_mod( longlong a, longlong b );	/* a%b */
extern long	li_mod( longlong a, long b );		/* a%b */
extern long	lui_mod( longlong a, UINT b );		/* a%b */
int ll_cmp( longlong a, longlong b )	/* +:a>b,0:a=b,-:a<b */
{
    if(a.hi>b.hi)
    {
        return 1;
    }
    else if(a.hi==b.hi)
    {
         if(a.lo>b.lo)
         {
            return 1;
         }
         else if(a.lo==b.lo)
         {
            return 0;
         }
    }
    return -1;
}
extern int	ll_sign( longlong a );			/* +:a>0,0:a=0,-:a<0 */
extern longlong ll_neg( longlong a );			/* -a */
void	ll_inc( longlong *a )			/* (*a)++ */
{
    if(a->lo == 0xFFFFFFFFu)
    {
        a->lo=0u;
        a->hi=a->hi+1;
    }
    else
    {
        a->lo=a->lo+1u;
    }
}

extern void	ll_dec( longlong *a );			/* (*a)-- */
#endif