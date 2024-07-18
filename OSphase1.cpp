
// #include <bits/stdc++.h>
// using namespace std;

// class OS
// {
// private:
//     char Memory[100][4]; // Memory
//     unsigned char R[4];  // Register
//     unsigned char IR[4]; // Instruction Registers
//     unsigned int IC;     // Instruction counter
//     bool C;              // Toggle Value
//     int SI;              // Interrupt
//     char buffer[200];    // Buffer

// public:
//     void INIT();
//     void LOAD();
//     void EXECUTE();
//     void MOS();
//     void Start();
//     int OppAdd();
//     void READ();
//     void WRITE();
//     void HALT();

//     fstream inputfile;
//     fstream outputfile;
// };

// void OS ::INIT()
// {

//     for (int i = 0; i < 100; i++)
//         for (int j = 0; j < 4; j++)
//             Memory[i][j] = ' ';

//     IR[3] = ' ';
//     R[3] = ' ';
//     C = false;
//     IC = 0;
// }

// void OS ::LOAD()
// {
//     cout << "Reading Data..." << endl;
//     int x = 0;
//     for (int i = 0; i < 100; i++)
//         for (int j = 0; j < 4; j++) // clear buffer
//             Memory[i][j] = ' ';
//     do
//     {

//         for (int i = 0; i <= 100; i++) // clear buffer
//             buffer[i] = ' ';

//         inputfile.getline(buffer, 42);

//         if (buffer[0] == '$' && buffer[1] == 'A' && buffer[2] == 'M' && buffer[3] == 'J')
//         {
//             INIT();
//         }
//         else if (buffer[0] == '$' && buffer[1] == 'D' && buffer[2] == 'T' && buffer[3] == 'A')
//         {
//             Start();
//         }
//         else if (buffer[0] == '$' && buffer[1] == 'E' && buffer[2] == 'N' && buffer[3] == 'D')
//         {
//             x = 0;
//             for (int i = 0; i < 100; i++)
//             {
//                 cout << "M[" << i << "]\t";
                
//                 for (int j = 0; j < 4; j++)
//                 {
//                     cout << Memory[i][j];
//                 }
//                 cout << endl;
//                 if (i % 10 == 9)
//                     cout << endl;
//             }
//             cin.get();
//             continue;
//         }
//         else
//         {
//             int k = 0;

//             int limit = x + 10;
//             for (; x < limit; ++x)
//             {
//                 for (int j = 0; j < 4; ++j)
//                 {
//                     Memory[x][j] = buffer[k];
//                     k++;
//                 }
//                 if (buffer[k] == ' ' || buffer[k] == '\n')
//                 {
//                     break;
//                 }
//             }
//         }
//     } while (!inputfile.eof());
// }

// int OS::OppAdd()
// {
//     int add = IR[2] - '0';
//     add = add * 10 + (IR[3] - '0');
//     return add;
// }
// void OS::Start()
// {
//     IC = 00;
//     EXECUTE();
// }

// void OS::EXECUTE()
// {
//     while (true)
//     {
//         for (int i = 0; i < 4; i++) // Load in register
//         {
//             IR[i] = Memory[IC][i];
//         }
//         IC++;

//         int loc = OppAdd();

//         if (IR[0] == 'G' && IR[1] == 'D') // GD
//         {
//             SI = 1;
//             MOS();
//         }
//         else if (IR[0] == 'P' && IR[1] == 'D') // PD
//         {
//             SI = 2;
//             MOS();
//         }
//         else if (IR[0] == 'H') // H
//         {
//             SI = 3;
//             MOS();
//             break;
//         }
//         else if (IR[0] == 'L' && IR[1] == 'R') // LR
//         {

//             for (int j = 0; j < 4; j++)
//                 R[j] = Memory[loc][j];
//         }
//         else if (IR[0] == 'S' && IR[1] == 'R') // SR
//         {

//             for (int j = 0; j < 4; j++)
//                 Memory[loc][j] = R[j];
//         }
//         else if (IR[0] == 'C' && IR[1] == 'R') // CR
//         {
//             int count = 0;

//             for (int j = 0; j <= 3; j++)
//                 if (Memory[loc][j] == R[j])
//                     count++;

//             if (count == 4)
//                 C = true;
//             else
//                 C = false;
//         }
//         else if (IR[0] == 'B' && IR[1] == 'T') // BT
//         {
//             if (C == true)
//             {
//                 IC = loc;
//                 C = false;
//             }
//         }
//     }
// }

// void OS::MOS()
// {
//     switch (SI)
//     {
//     case 1:
//         for (int i = 0; i <= 40; i++)
//             buffer[i] = ' ';
//         READ();
//         break;

//     case 2:
//         WRITE();
//         break;

//     case 3:

//         HALT();
//         break;
//     default:
//         break;
//     }
// }

// void OS::READ()
// {
//     inputfile.getline(buffer, 42);
//     IR[3] = '0';
//     int k = 0;
//     int loc = OppAdd();

//     for (int l = 0; l < 10; ++l)
//     {
//         for (int j = 0; j < 4; ++j)
//         {
//             Memory[loc][j] = buffer[k];
//             k++;
//         }
//         if (Memory[loc][0] == '$' && Memory[loc][1] == 'E' && Memory[loc][2] == 'N' && Memory[loc][3] == 'D')
//             return;

//         loc++;
//     }
// }

// void OS::WRITE()
// {
//     int k = 0;
//     IR[3] = '0';
//     int loc = OppAdd();
//     int i = 0;

//     for (int l = 0; l < 10; ++l)
//     {
//         for (int j = 0; j < 4; ++j)
//         {
//             outputfile << Memory[loc][j];
//             k++;
//         }
//         loc++;
//     }

//     outputfile << "\n";
// }
// void OS::HALT()
// {
//     outputfile << "\n\n";
// }

// int main()
// {
//     unsigned x;
//     OS os;
//     cout << "Implemented by Prathamesh Bhujbal- OS:Phase-01\n";
//     cout << "Press any key to continue...\n";
//     cin.get();
//     os.inputfile.open("input.txt", ios::in);
//     os.outputfile.open("output.txt", ios::out);

//     if (!os.inputfile)
//         cout << "File doesn't exist" << endl;
//     else
//         cout << "File Exist" << endl;

//     os.LOAD();
//     os.inputfile.close();
//     os.outputfile.close();
//     return 0;
// }

#include<iostream>
#include<fstream>
using namespace std;

class OS
{
    private:
        char M[100][4];     //Physical Memory
        char IR[4];         //Instruction Register (4 bytes)
        char R[4];          //General Purpose Register (4 bytes)
        int IC;             //Instruction Counter Register (2 bytes)
        int SI;             //Interrupt
        bool C;             //Toggle (1 byte)
        char buffer[40];
    public:
        void init();
        void LOAD();
        void Execute();
        void MOS();

        fstream infile;
        fstream outfile;
};

//initiallise everything to 0
void OS::init()
{

    for(int i = 0; i<100; i++)
    {
        for(int j = 0; j<4; j++ )
        {
            M[i][j]=0;

        }

    }
    IR[0] = {0};
    R[0] = {0};
    C = false;
}

//Master Mode
void OS::MOS()
{
    if(SI == 1)     //Read Mode
    {
        for(int i=0;i<=39;i++)
           buffer[i]='\0';
        infile.getline(buffer,40);
        int k = 0;
        int i = IR[2]-48;
        i = i*10;
        for( int l=0 ; l<10 ;  ++l)
        {
            for(int j = 0 ; j<4; ++j)
            {
                M[i][j] = buffer[k];
                k++;
            }
            if(k == 40)
            {
                break;
            }
            i++;
        }

        for(int i = 0; i<100; i++)
        {
            cout<<"M["<<i<<"]\t";
            for(int j = 0; j<4; j++ )
            {
                cout<<M[i][j];
            }
            cout<<endl;
        }
    }
    else if(SI == 2)        //Write Mode
    {
      for(int i=0;i<=39;i++)
           buffer[i]='\0';

        int k = 0;
        int i = IR[2]-48;
        i = i*10;


        for( int l=0 ; l<10 ;  ++l)
        {
            for(int j = 0 ; j<4; ++j)
            {
                buffer[k]=M[i][j];
                outfile<<buffer[k];

                k++;
            }
            if(k == 40)
            {
                break;
            }
            i++;
        }
           for(int i = 0; i<100; i++)
        {
            cout<<"M["<<i<<"]\t";
            for(int j = 0; j<4; j++ )
            {
                cout<<M[i][j];
            }
            cout<<endl;
        }

        outfile<<"\n";

    }
    else if(SI == 3)        //Terminate
    {

        outfile<<"\n";
        outfile<<"\n";
    }
}

//Execution
void OS::Execute()
{
    while(true)
    {
        for(int i = 0; i<4; i++)        //Load in register
        {
            IR[i] = M[IC][i];
        }
        IC++;

        if(IR[0] == 'G' && IR[1] == 'D')    //GD
        {
            SI = 1;
            MOS();
        }
        else if(IR[0] == 'P' && IR[1] == 'D')       //PD
        {
            SI = 2;
            MOS();
        }
        else if(IR [0] == 'H')      //H
        {
            SI = 3;
            MOS();
            break;
        }
        else if(IR[0] == 'L' && IR[1] == 'R')       //LR
        {
            int i = IR[2]-48;
            i = i*10 + ( IR[3]-48);

            for(int j=0;j<=3;j++)
                R[j]=M[i][j];

            //for(int j=0;j<=3;j++)
              // cout<<R[j];

            cout<<endl;
        }
        else if(IR[0] == 'S' && IR[1] == 'R')       //SR
        {
            int i = IR[2]-48;
            i = i*10 +( IR[3]-48) ;
            //cout<<i;
            for(int j=0;j<=3;j++)
                M[i][j]=R[j];

            cout<<endl;
        }
        else if(IR[0] == 'C' && IR[1] == 'R')       //CR
        {
            int i = IR[2]-48;
            i = i*10 + (IR[3] - 48);
            //cout<<i;
            int count=0;

            for(int j=0;j<=3;j++)
                if(M[i][j] == R[j])
                    count++;

            if(count==4)
                C=true;

            //cout<<C;
        }
        else if(IR[0] == 'B' && IR[1] == 'T')       //BT
        {
            if(C == true)
            {
                int i = IR[2]-48;
                i = i*10 + (IR[3] - 48);

                IC = i;

            }
        }
    }
}

//Load Function
void OS::LOAD()
{
    cout<<"Reading Data..."<<endl;
    int x=0;
    do
    {
        for(int i=0;i<=39;i++)      //clear buffer
           buffer[i]='\0';

        infile.getline(buffer,40);
        cout<<endl;
        for(int k=0;k<=39;k++)
           cout<<buffer[k];

        if(buffer[0] == '$' && buffer[1] == 'A' && buffer[2] == 'M' && buffer[3] == 'J')
        {
            init();

        }
        else if(buffer[0] == '$' && buffer[1] == 'D' && buffer[2] == 'T' && buffer[3] == 'A')
        {
            IC = 00;
            Execute();

        }
        else if(buffer[0] == '$' && buffer[1] == 'E' && buffer[2] == 'N' && buffer[3] == 'D')
        {
            x=0;
            continue;
        }
        else
        {
            int k = 0;

            for(; x <100; ++x)
            {
                for(int j = 0 ; j<4; ++j)
                {

                    M[x][j] = buffer[k];
                    k++;
                }

                if(k == 40 || buffer[k] == ' ' || buffer[k] == '\n')
                {
                    break;
                }

            }

        }

    }while(!infile.eof());         //continues to take input till eof

}

int main()
{
    OS os;

    os.infile.open("input.txt", ios::in);
    os.outfile.open("output.txt", ios::out);


    if(!os.infile)
    {
        cout<<"Failure"<<endl;
    }
    else
    {
        cout<<"File Exist"<<endl;
    }

    os.LOAD();
    return 0;
}
