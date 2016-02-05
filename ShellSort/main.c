//
//  main.c
//  ShellSort
//
//  Created by chenyufeng on 16/2/5.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include <stdio.h>

void shellSort(int *a,int n);

int main(int argc, const char * argv[]) {

    int a[] = {4,7,1,0,9,5};
    shellSort(a, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ",a[i]);
    }

    return 0;
}

void shellSort(int *a,int n){

    int i,j,gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) { //步长
        for (i = 0; i < gap; i++) {  //直接插入排序的次数；也就是在每个分组中需要进行几次直接插入排序；

            //开始进行插入排序，每次加gap的步长；
            for (j = i + gap; j < n; j = j + gap) {
                if (a[j] < a[j - gap]) {

                    //保存后面的值；
                    int temp = a[j];
                    int k = j - gap;
                    //后面的数小，往前面插；
                    while (k >= 0 && a[k] > temp) {

                        //先把前面的数往后移；
                        a[k + gap] = a[k];
                        k = k - gap;
                    }
                    a[k + gap] = temp;

                }
            }

        }
    }

}