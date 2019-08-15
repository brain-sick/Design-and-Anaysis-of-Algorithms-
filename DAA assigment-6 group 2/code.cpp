// C++ program to find adjoint and inverse of a matrix 
#include<bits/stdc++.h> 
using namespace std; 
const int M=10; 
int N;
// Function to get cofactor of A[p][q] in temp[][]. n is current 
// dimension of A[][] 
void getCofactor(int A[M][M], int temp[M][M], int p, int q, int n) 
{ 
	int i = 0, j = 0; 

	// Looping for each element of the matrix 
	for (int row = 0; row < n; row++) 
	{ 
		for (int col = 0; col < n; col++) 
		{ 
			// Copying into temporary matrix only those element 
			// which are not in given row and column 
			if (row != p && col != q) 
			{ 
				temp[i][j++] = A[row][col]; 

				// Row is filled, so increase row index and 
				// reset col index 
				if (j == n - 1) 
				{ 
					j = 0; 
					i++; 
				} 
			} 
		} 
	} 
} 

/* Recursive function for finding determinant of matrix. 
n is current dimension of A[][]. */
int determinant(int A[M][M], int n) 
{ 
	int D = 0; // Initialize result 

	// Base case : if matrix contains single element 
	if (n == 1) 
		return A[0][0]; 

	int temp[M][M]; // To store cofactors 

	int sign = 1; // To store sign multiplier 

	// Iterate for each element of first row 
	for (int f = 0; f < n; f++) 
	{ 
		// Getting Cofactor of A[0][f] 
		getCofactor(A, temp, 0, f, n); 
		D += sign * A[0][f] * determinant(temp, n - 1); 

		// terms are to be added with alternate sign 
		sign = -sign; 
	} 

	return D; 
} 

// Function to get adjoint of A[N][N] in adj[N][N]. 
void adjoint(int A[M][M],int adj[M][M]) 
{ 
	if (N == 1) 
	{ 
		adj[0][0] = 1; 
		return; 
	} 

	// temp is used to store cofactors of A[][] 
	int sign = 1, temp[M][M]; 

	for (int i=0; i<N; i++) 
	{ 
		for (int j=0; j<N; j++) 
		{ 
			// Get cofactor of A[i][j] 
			getCofactor(A, temp, i, j, N); 

			// sign of adj[j][i] positive if sum of row 
			// and column indexes is even. 
			sign = ((i+j)%2==0)? 1: -1; 

			// Interchanging rows and columns to get the 
			// transpose of the cofactor matrix 
			adj[j][i] = (sign)*(determinant(temp, N-1)); 
		} 
	} 
} 

// Function to calculate and store inverse, returns false if 
// matrix is singular 
bool inverse(int A[M][M], float inverse[M][M]) 
{ 
	// Find determinant of A[][] 
	int det = determinant(A, N); 
	if (det == 0) 
	{ 
		cout << "Singular matrix, can't find its inverse"; 
		return false; 
	} 

	// Find adjoint 
	int adj[M][M]; 
	adjoint(A, adj); 

	// Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
	for (int i=0; i<N; i++) 
		for (int j=0; j<N; j++) 
			inverse[i][j] = adj[i][j]/float(det); 

	return true; 
} 

// Generic function to display the matrix. We use it to display 
// both adjoin and inverse. adjoin is integer matrix and inverse 
// is a float. 
template<class T> 
void display(T A[M][M]) 
{ 
	for (int i=0; i<N; i++) 
	{ 
		for (int j=0; j<N; j++) 
			cout << A[i][j] << " "; 
		cout << endl; 
	} 
} 
void upper_traingular(int a[M][M],int n)
{

    for(int i=0;i<n-1;i++)
    {
        if(a[i][i]==0)
        continue;
        for(int j=i+1;j<n;j++)
        {
            int l = a[j][i]/a[i][i];
            for(int k=0;k<n;k++)
            {
                a[j][k]=a[j][k]-l*a[i][k];
            }
        }
    }
}
void matmul(int A[M][M],float B[M][M],float C[M][M],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                C[i][j] += (A[i][k]*B[k][j]);
            }
        }
    }
}
void Lnormalize(float L[M][M],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            if(i<j)
            L[i][j]=0;
        }
    
    }
}
// Driver program []
int main() 
{ 
    cin>>N;
	int A[M][M],U[M][M];
	float L[M][M]={0};
	for(int i=0;i<N;i++)
	{
	    for(int j=0;j<N;j++){
	        cin>>A[i][j];
	        U[i][j]=A[i][j];
	    }
	}
    upper_traingular(U,N);
	int adj[M][M]; // To store adjoint of A[][] 

	float inv[M][M]; // To store inverse of A[][] 

	cout << "Input matrix is :\n"; 
	display(A); 

	adjoint(U, adj); 

	if (!inverse(U, inv))
	{
	    cout<<"inverse not existant";
	    return 0;
	}
    matmul(A,inv,L,N);
    cout<<"Lower Traingular matrix :\n";
    Lnormalize(L,N);
    display(L);
    cout<<"Upper Traingular matrix :\n";
    display(U);
	return 0; 
} 
