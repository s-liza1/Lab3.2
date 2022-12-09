#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double f( double x);
double div_metod(double x1, double x2, int N,  double eps);
double chord_metod(double x1, double x2, int N,  double eps);
double times;



int main () {

  double Time;
  int Method;
  double x1, x2, root;
  double eps = 0.00001;
  int iterat_count;
  int N=5;


    do
    {

        printf("\nEnter X1\n> ");

        scanf("%lf", &x1);

        printf("\nEnter X2\n> ");

        scanf("%lf", &x2);


        } while (f(x1)*f(x2)>0);

     do{
        system("cls");
        printf ("\nEnter you metod:");
        printf("\n   1 - Method of halving");
        printf("\n   2 - Method chord\n>");
        scanf("%d", &Method);
    } while(Method != 1 && Method != 2);

    Time = clock();
    if (Method == 1)
  {
      root = div_metod(x1, x2, N, eps);
      system("cls");
    printf("\n x = %lf  f(x) = %lf", root, f(root));
  }
    else
  {
      root = chord_metod (x1, x2, N, eps);
      system("cls");
    printf("\n x = %lf  f(x) = %lf", root, f(root));
  }
  printf("\n Times = %f Sec\n\n", ((clock() - Time)-times)/1000);
    return 0;
}

//-----------------------------------------------------
double div_metod(double x1, double x2, int N, double eps)
{
    double xi;
    int iterat_count = 0;
    unsigned int answer;
    times = 0;
    double t1, t2;


    do {
        iterat_count++;
        xi=(x1+x2)/2;

    if(f(xi)*f(x1)>0)
       {
                x1=xi;

       }

        else
        {
            x2=xi;
        }
        if (iterat_count % N == 0){
             printf ("\nNumber of iterations: %d", iterat_count);
             printf ("\n Current X - %.3lf", xi);
             printf ("\n Current f(x) - %.3lf", f (xi));
             printf ("\n What to do next?");
             printf ("\n\n1 - Continue with the same number of iterations");
             printf("\n\n3 - Execute programs until the roots are found");
             printf ("\n\n3 - Show current result and exit");
             printf ("\n Enter answer \n>");
            scanf ("%d", &answer);
            while (answer!=1 && answer!=2 && answer!=3)
            {
                scanf("%u", &answer);
            }
             t2 = clock() - t1;
        times = times + t2;
           if(answer == 1)
            {
                 N=N+iterat_count;
            }
            if(answer == 2)
            {
                N=N+iterat_count;
            }
            if(answer == 3)
            {
                break;
            }
        }
        }while(fabs(x1-x2)>=eps);
    printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}

//-----------------------------------------------------

double chord_metod (double x1, double x2, int N,  double eps)
{
    double xi;
    int iterat_count = 0;
    unsigned int answer;
    times=0;
    double t1, t2;



    do {
        iterat_count++;
       xi = (x1 * f(x2) - x2 * f(x1) ) / (f(x2) - f(x1));
         if (f(x1)*f(xi)>0)
        x1 = xi;

        else
        x2 = x1;

                if (iterat_count % N == 0){
             printf ("\nNumber of iterations: %d", iterat_count);
             printf ("\n Current X - %.3lf", xi);
             printf ("\n Current f(x) - %.3lf", f (xi));
             printf ("\n What to do next?");
             printf ("\n\n1 - Continue with the same number of iterations");
             printf("\n\n3 - Execute programs until the roots are found");
             printf ("\n\n3 - Show current result and exit");
             printf ("\n Enter answer \n>");
            scanf ("%d", &answer);
            while (answer!=1 && answer!=2 && answer!=3);
            {
                scanf("%u", &answer);
            }
            t2 = clock() - t1;
        times = times + t2;
           if(answer == 1)
            {
                 N=N+iterat_count;
            }
            if(answer == 2)
            {
                N=N+iterat_count;
            }
            if(answer == 3)
            {
                break;
            }
        }
        }while(fabs( f(xi))>= eps);
    printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}


//------------------------------------------------------
double f( double x)
{
    double y;

  y = 9 * pow(x , 3) + 1000;

    return y;

}
//------------------------------------------------------
