 /* ALGORITHM

1. Start
 
 2. Read Order of Matrix (n) and Tolerable Error (e)
 
 3. Read Matrix A of Size n x n
 
 4. Read Initial Guess Vector X of Size n x 1
 
 5. Initialize: Lambda_Old = 1
 
 6. Multiply: X_NEW = A * X 
 
 7. Replace X by X_NEW
 
 8. Find Largest Element (Lamda_New) by Magnitude from X_NEW
 
 9. Normalize or Divide X by Lamda_New
 
 10. Display Lamda_New and X

 11. If |Lambda_Old - Lamda_New| > e then 
     set Lambda_Old = Lamda_New and goto 
     step (6) otherwise goto step (12)
 
 12. Stop  */
 
 
 
 
 
 
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<math.h>

#define SIZE 10

using namespace std;

int main()
{
	 float a[SIZE][SIZE], x[SIZE],x_new[SIZE];
	 float temp, lambda_new, lambda_old, error;
	 int i,j,n, step=1;

    
	 /* Inputs */
	 /* Reading order of square matrix */
	 cout<<"Enter Order of Matrix: ";
	 cin>>n;

     /* Reading tolerable error */
	 cout<<"Enter Tolerable Error: ";
	 cin>>error;

	 /* Reading Square Matrix of Order n */
	 cout<<"Enter Coefficient of Matrix: "<< endl;
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n;j++)
		  {
			   cout<<"a["<< i<<"]"<< j<<"]= ";
               cin>>a[i][j];
		  }
	 }

	 /* Reading Intial Guess Vector */
	 cout<<"Enter Initial Guess Vector: "<< endl;
	 for(i=1;i<=n;i++)
	 {
		  cout<<"x["<< i<<"]= ";
		  cin>>x[i];
	 }

	 /* Initializing Lambda_Old */
	 lambda_old = 1;
	 /* Multiplication */

	 /* Setting label for repetition */
	 up:
	 for(i=1;i<=n;i++)
	 {
		  temp = 0.0;
		  for(j=1;j<=n;j++)
		  {
		   	temp = temp + a[i][j]*x[j];
		  }
		  x_new[i] = temp;
	 }

	 /* Replacing x by x_new */
	 for(i=1;i<=n;i++)
	 {
	  	x[i] = x_new[i];
	 }

	 /* Finding largest value from x*/
	 lambda_new = fabs(x[1]);
	 for(i=2;i<=n;i++)
	 {
		  if(fabs(x[i])>lambda_new)
		  {
		   	lambda_new = fabs(x[i]);
		  }
	 }

	 /* Normalization */
	 for(i=1;i<=n;i++)
	 {
	  	x[i] = x[i]/lambda_new;
	 }

	 /* Display */
	 cout<< endl<< endl<<"STEP-"<< step<< endl;
	 cout<<"Eigen Value = "<< lambda_new<< endl;
	 cout<<"Eigen Vector: "<< endl;
	 cout<<"[";
	 for(i=1;i<=n;i++)
	 {
	  	cout<< x[i]<<"\t";
	 }
     cout<<"\b\b\b]"; /* \b is for backspace */

	 /* Checking Accuracy */
	 if(fabs(lambda_new-lambda_old)>error)
	 {
		  lambda_old=lambda_new;
		  step++;
		  goto up;
	 }

	 return(0);
}

