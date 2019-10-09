#include<stdio.h>
#include<math.h>

#define M 20

int main()
{
    double x[M] = {65.0,80.0,67.0,35.0,58.0,60.0,72.0,75.0,68.0,92.0,36.0,50.0,2.0,58.5,46.0,42.0,78.0,62.0,84.0,70.0};
    double y[M] = {44.0,87.0,100.0,63.0, 52.0, 60.0, 58.0, 73.0, 55.0, 86.0, 29.0, 56.0, 89.0, 23.0, 65.0, 84.0, 64.0, 27.0, 86.0, 84.0};
    double heikin_x = 0.0, heikin_y = 0.0;
    double bun_x = 0.0, bun_y = 0.0, bun = 0.0;
    double hensa_x, hensa_y, cor, tmp;
    int i, j;
 
    for(i = 0; i < M; i++)
    {
        heikin_x += x[i];
        heikin_y += y[i];
    }
    printf("理科の\n合計点は%f点です。\n", heikin_x);
    printf("英語の\n合計点は%f点です。\n", heikin_y);
    heikin_x = heikin_x / M;
    heikin_y = heikin_y / M;
    
    for(i = 0; i < M; i++)
    {
        bun_x += (x[i] - heikin_x) * (x[i] - heikin_x);
        bun_y += (y[i] - heikin_y) * (y[i] - heikin_y);
        bun += (x[i] - heikin_x) * (y[i] - heikin_y);
    }
    bun_x = bun_x / M;
    bun_y = bun_y / M;
    
    hensa_x = sqrt(bun_x);
    hensa_y = sqrt(bun_y);

    printf("理科の\n平均点は%f点です。\n", heikin_x);
    printf("英語の\n平均点は%f点です。\n", heikin_y);
    printf("理科の\n標準偏差は%fです。\n", hensa_x);
    printf("英語の\n標準偏差は%fです。\n", hensa_y);

    for (i=0; i<M; ++i) {
        for (j=i+1; j<M; ++j) {
            if (x[i] < x[j]) {
                tmp =  x[i];
                x[i] = x[j];
                x[j] = tmp;
	    }
            if (y[i] < y[j]) {
                tmp =  y[i];
                y[i] = y[j];
                y[j] = tmp;
	    }
        }
    }
    printf("理科\n");
    for(i=0; i<M; i++){
	printf("%f\n",x[i]);
    }
    printf("英語\n");
    for(i=0; i<M; i++){
        printf("%f\n",y[i]);
    }

}
