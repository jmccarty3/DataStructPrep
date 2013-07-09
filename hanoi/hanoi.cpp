#include <iostream>
#include <stack>
#include <assert.h>

#define DISK_MAX 64
#define STACK_COUNT 3

typedef std::stack<short> diskStack;

void init_stacks(diskStack stacks[])
{
   std::cout << "Initilaizing Stacks" << std::endl;
   
   for (short j=DISK_MAX; j > 0; j--)
      stacks[0].push(j);
}

void print_stacks(const diskStack stacks[])
{
   short temp;   
   
   std::cout << "\n";
   for(short stack=0; stack < STACK_COUNT; stack++)
   {
       diskStack tempStack = stacks[stack];
       
       while(tempStack.size() > 0)
       {
          temp = tempStack.top();
          tempStack.pop();
          
          if (temp < 0) //No reason to continue
             break;
          std::cout << temp << " ";
       }
      
       std::cout << "| Stack: " << stack << std::endl;
                     
   }
          
}

void move_disks(diskStack stacks[],int disk, int toMove, int destination, int spare)
{
   //Exit: Stack 1, element DISK_MAX -1  > 0
   //std::cout << "Moving Stacks" << std::endl;

   if(disk == 1)
   {
       short value = stacks[toMove].top();
       stacks[toMove].pop();
       stacks[destination].push(value);
   }
   else
   {
 //  std::cout << "Moving index: " << toMove << std::endl;
 //  print_stacks(stacks);

   move_disks(stacks, disk-1, toMove, spare, destination);
   short value = stacks[toMove].top();
   stacks[toMove].pop();
   stacks[destination].push(value);
   move_disks(stacks, disk-1, spare, destination, toMove);
}
}


int main(int, char**)
{

   diskStack stacks[STACK_COUNT];
   
   init_stacks(stacks);
   
   std::cout << "Init: \n";
   print_stacks(stacks);
   
   std::cout << std::endl;
   move_disks(stacks,DISK_MAX , 0, 1, 2);
   std::cout << std::endl<< "Final: " << std::endl;

   print_stacks(stacks);


   return 0;
}
