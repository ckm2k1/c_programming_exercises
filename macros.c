#define N 10
#define INC(x) x+1
#define SUB (x,y) x-y
#define SQR(x) ((x) * (x))
#define CUBE(x) (SQR(x) * (x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main(void) {
  int a[10], i, j, k, m;

  #ifdef N
    i = j;
  #else
    j = i;
  #endif

    i = 10 * j+1;
    i = (j,k) j-k;
    i = ((((j) * (j))) * (((j) * (j))));
    i = (((j) * (j) * (j)));
    i = jk;
    puts("i" "j");

    #undef SQR
      i = SQR(j)
    #define SQR
      i = SQR(j)

    IDENT(foo)
    #pragma ident "foo"

    return 0;
}