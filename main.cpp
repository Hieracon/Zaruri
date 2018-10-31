#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Zaruri{
    public:
        int dice_value;
        int dice_roll(){
            int tmp = rand()%6+1;
            return tmp;
        }
};

int main()
{
    int consecutiv[3] = {0};
    int consecutiv_max[3] = {0};
    int frecventa[7] = {0};
    int apparition[7][7];
    int dice_1;
    int dice_2;
    int temp;
    int temp_1;

    for(int iterator_1 = 1; iterator_1 <= 6; iterator_1++){
        for(int iterator_2 = 1; iterator_2 <= 6; iterator_2++){
                apparition[iterator_1][iterator_2] = 0;
        }
    }

    Zaruri obj;
    srand(time(0));
    consecutiv[1]=0;
    for(int iterator = 1; iterator <= 9000; iterator ++){
        dice_1 = obj.dice_roll();
        dice_2 = obj.dice_roll();

        frecventa[dice_1]++;
        frecventa[dice_2]++;

        if(dice_1 > dice_2){
            temp_1 = dice_1;
            dice_1 = dice_2;
            dice_2 = temp_1;
        }

        apparition[dice_1][dice_2]++;

        temp = dice_1*10 + dice_2;

        if(consecutiv[2] == temp){
            consecutiv[1]++;
        }
        else{
            if(consecutiv[1] >= consecutiv_max[1]){
                consecutiv_max[1] = consecutiv[1];
                consecutiv_max[2] = consecutiv[2];
            }
            consecutiv[1] = 1;
            consecutiv[2] = temp;
        }
    }

    int max[3] = {0};
    int min[3];

    min[1] = 800;
    min[2]=0;

    for(int iterator_1 = 1; iterator_1 <= 6; iterator_1++){
        for(int iterator_2 = 1; iterator_2 <= 6; iterator_2++){
            if(apparition[iterator_1][iterator_2] >= max[1]){
                max[1] = apparition[iterator_1][iterator_2];
                max[2] = iterator_1 * 10 + iterator_2;
            }
            if(apparition[iterator_1][iterator_2] <= min[1] && apparition[iterator_1][iterator_2] != 0){
                min[1] = apparition[iterator_1][iterator_2];
                min[2] = iterator_1 * 10 + iterator_2;
            }
        }
    }

    for(int iterator_1 = 1; iterator_1 <= 6; iterator_1++){
        double result = frecventa[iterator_1] / 90;
        cout <<"Frecventa fetei "<<iterator_1<<" este "<<result<<"%"<<endl;
    }

    cout<<"Min este " << min[1]<<" "<<min[2]<<endl;
    cout<<"Max este " << max[1]<<" "<<max[2]<<endl;
    cout<<"aparitii consec "<<consecutiv_max[1]<<" "<<consecutiv_max[2];

    return 0;
}
