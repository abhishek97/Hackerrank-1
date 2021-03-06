#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

typedef long long ll;
typedef vector < ll > row;
typedef vector < row > matrix;

ll MOD = (ll) 1e9 + 7;

void clear (matrix & A) {
  for (size_t i = 0; i < A.size (); i++)
    for (size_t j = 0; j < A[i].size (); j++)
      A[i][j] = 0;
}

matrix mul (const matrix & A, const matrix & B) {
  matrix C = A;
  clear (C);
  for (size_t i = 0; i < C.size (); i++)
    for (size_t j = 0; j < C[i].size (); j++)
      for (size_t k = 0; k < A[i].size (); k++)
  C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
  return C;
}

matrix pow (const matrix & A, ll p) {
  if (p == 0) {
      matrix C = A;
      clear (C);
      for (size_t i = 0; i < C.size (); i++)
        C[i][i] = 1;
      return C;
  }

  matrix C = pow (A, p / 2);
  C = mul (C, C);
  if (p & 1)
    C = mul (C, A);
  return C;
}

void solve () {
  ll L;
  scanf("%lld",&L);
  const int nn = 16;
  matrix Z = matrix (nn, row (nn, 0));
  matrix A = Z;
  for (int i = 1; i < nn; i++)
    A[i][i - 1] = 1;
  int k, l;
  inp(k);
  for (int i = 0; i < k; i++) {
      inp(l);
      A[0][l - 1]++;
  }
  matrix B = pow (A, L);
  B[0][0] = (B[0][0]*2)%MOD;
  printf("%lld\n",B[0][0]);
}

int main () {
  solve ();
  return 0;
}
