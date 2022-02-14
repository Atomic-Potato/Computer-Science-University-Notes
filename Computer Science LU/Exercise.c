//Exercise
/*
    Print the pid of child 4 and its parent
    and print the pid of child 2 and 3 from the process p4

    image 1
*/

//Semi correct
/*int main()
{
    int pids[4], j, i;

    for( i=0; i<3; i++)
    {
        j = fork();
        if(!j)
        {
            pids[i]=j;
            break;
        }
        
    }
    if(i ==3){
        //print
    }

}
*///i think correct

#include<stdio.h>
#include<unistd.h>
int main()
{
    int pids[3];

    for(int i=0; i < 3; i++)
    {
        pids[i] = fork();
        if(pids[i] == 0 && i != 2)
            break;
        else if (i == 2)
        {
            //print parent
            //print itself pid
            //print i = 0 and i = 1 
        }
    }
}
/*
//Teacher's solution
int main()
{
    int child1, child2;
    
    if(child1 = fork())
    {
        if(child2 = fork())
            if(!fork)
                //print
    }
}
*/