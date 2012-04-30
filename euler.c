/*



*/

#include "lib/eulib.h"
#include "euprobs.h"

int main(int argc, int** argv)
{
    char input[5];
    int option;
    
    while(1)
    {
        //ask which prob to run
        fputs("Which problem (1-20) would you like to run? : ", stdout);
        fflush(stdout);
    
        //get user input option, first as string then sscan to int
        if(fgets(input, sizeof(input), stdin))
        {
            if(sscanf(input, "%d", &option) == 1)
            {
                switch(option)
                {
                    case 1:
                        problem1();
                        break;
                    case 2:
                        problem2();
                        break;
                    case 3:
                        problem3();
                        break;
                    case 4:
                        problem4();
                        break;
                    case 5:
                        problem5();
                        break;
                    case 6:
                        problem6();
                        break;
                    case 7:
                        problem7();
                        break;
                    case 8:
                        problem8();
                        break;
                    case 9:
                        problem9();
                        break;
                    case 10:
                        problem10();
                        break;
                    case 11:
                        problem11();
                        break;
                    case 12:
                        problem12();
                        break;
                    case 13:
                        problem13();
                        break;
                    case 14:
                        problem14();
                        break;
                    case 15:
                        problem15();
                        break;
                    case 16:
                        problem16();
                        break;
                    case 17:
                        problem17();
                        break;
                    case 18:
                        problem18();
                        break;
                    case 19:
                        problem19();
                        break;
                    case 20:
                        problem20();
                        break;
                    case 21:
                        problem21();
                        break;
                    case 22:
                        problem22();
                        break;
                    case 23:
                        problem23();
                        break;
                    case 24:
                        problem24();
                        break;
                    case 25:
                        problem25();
                        break;
                    case 26:
                        problem26();
                        break;
                    case 27:
                        problem27();
                        break;
                    case 28:
                        problem28();
                        break;
                    case 29:
                        problem29();
                        break;
                    case 30:
                        problem30();
                        break;
                    case 31:
                        problem31();
                        break;
                    case 32:
                        problem32();
                        break;
                    case 33:
                        problem33();
                        break;
                    case 34:
                        problem34();
                        break;
                    case 35:
                        problem35();
                        break;
                    case 36:
                        problem36();
                        break;
                    case 37:
                        problem37();
                        break;
                    case 38:
                        problem38();
                        break;
                    case 39:
                        problem39();
                        break;
                    case 40:
                        problem40();
                        break;
                    case 41:
                        problem41();
                        break;
                    case 42:
                        problem42();
                        break;
                    case 43:
                        problem43();
                        break;
                    case 44:
                        problem44();
                        break;
                    case 45:
                        problem45();
                        break;
                    case 46:
                        problem46();
                        break;
                    case 47:
                        problem47();
                        break;
                    case 48:
                        problem48();
                        break;
                    case 49:
                        problem49();
                        break;
                    case 50:
                        problem50();
                        break;
                    default:
                        break;
                }
            }
            else break;
        }
    }
}

