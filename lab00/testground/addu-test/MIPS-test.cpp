#include<iostream>
#include<string>
#include<vector>
#include<bitset>
#include<fstream>
using namespace std;
#define ADDU 1
#define SUBU 3
#define AND 4
#define OR  5
#define NOR 7
#define MemSize 65536 // memory size, in reality, the memory size should be 2^32, but for this lab, for the space resaon, we keep it as this large number, but the memory is still 32-bit addressable.


class RF
{
    public:
        bitset<32> ReadData1, ReadData2;
         RF()
        {
          Registers.resize(32);
          Registers[0] = bitset<32> (0);
        }

        void ReadWrite(bitset<5> RdReg1, bitset<5> RdReg2, bitset<5> WrtReg, bitset<32> WrtData, bitset<1> WrtEnable)
        {
            // implement the funciton by you.
        }

    void OutputRF() // write RF results to file
             {
               ofstream rfout;
                  rfout.open("RFresult.txt",std::ios_base::app);
                  if (rfout.is_open())
                  {
                    rfout<<"A state of RF:"<<endl;
                    for (int j = 0; j<32; j++)
                    {
                        rfout << Registers[j]<<endl;
                    }

                  }
                  else cout<<"Unable to open file";
                  rfout.close();

               }
    private:
            vector<bitset<32> >Registers;

};

class ALU
{
      public:
             bitset<32> ALUresult;
             bitset<32> ALUOperation (bitset<3> ALUOP, bitset<32> oprand1, bitset<32> oprand2)
             {
                 // implement the ALU operations by you.
                 return ALUresult;
               }
};

class INSMem
{
    public:
        bitset<32> Instruction;

        INSMem() // read instruction memory
        {   
            cout << "Read fron imem.txt" << endl;
            IMem.resize(MemSize);
            ifstream imem;
            string line;
            imem.open("imem.txt");
            if (imem.is_open())
            {
                int i = 0;
                while (getline(imem,line))
                {
                IMem[i] = bitset<8>(line);

                // out << endl;
                // cout << "IMem           " << IMem [i] << endl; // test
                // cout << "line           " << line << endl; // test

                i++;
                }

            }
            else cout<<"Unable to open file";
            imem.close();
        }
        void printImemLine(int n) // Print the first n lines 
        {
            int i = 0;
            while (i < n) 
            {
                cout << IMem[i] << endl;
                i++;
            }
        }
        
        bitset<32> ReadMemory (bitset<32> ReadAddress)
        {
            // implement by you. (Read the byte at the ReadAddress and the following three byte).

            int n = ReadAddress.count();

            //Instruction[3123] = IMem[ReadAddress + 0];
            //cout << IMem[0] << "yoyooy" << endl;

            cout << "Most Significant Byte" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << "LSB  ";
                for (int j = 0; j < 8; j++)
                {
                    Instruction[24 - i * 8 + j] = IMem[i + n][j]; // 24 = 0 + 8 * 3
                    //Instruction[i * 8 + j] = 1;
                    cout  << IMem[i][j];
                }
                cout << "  MSB" << endl;
            }
            cout << "Least Significant Byte" << endl;

            
            return Instruction;
        }

    private:
        vector<bitset<8> > IMem;

};

class DataMem
{
    public:
        bitset<32> readdata;
        DataMem() // read data memory
        {
            DMem.resize(MemSize);
             ifstream dmem;
                  string line;
                  int i=0;
                  dmem.open("dmem.txt");
                  if (dmem.is_open())
                  {
                  while (getline(dmem,line))
                       {
                        DMem[i] = bitset<8>(line);
                        i++;
                       }
                  }
                  else cout<<"Unable to open file";
                  dmem.close();

          }
          bitset<32> MemoryAccess (bitset<32> Address, bitset<32> WriteData, bitset<1> readmem, bitset<1> writemem)
          {

               // implement by you.
               return readdata;
          }

          void OutputDataMem()  // write dmem results to file
          {
               ofstream dmemout;
                  dmemout.open("dmemresult.txt");
                  if (dmemout.is_open())
                  {
                  for (int j = 0; j< 1000; j++)
                       {
                        dmemout << DMem[j]<<endl;
                       }

                  }
                  else cout<<"Unable to open file";
                  dmemout.close();

               }

      private:
           vector<bitset<8> > DMem;

};



int main()
{
    RF myRF;
    ALU myALU;
    INSMem myInsMem;
    DataMem myDataMem;

    std::cout<<"Now we are in the main." << std::endl;

    bitset<32> PC = 0;

    int temp = 0;
    while (temp < 2)
    {
        temp ++; 

        std::cout<< myInsMem.ReadMemory(PC) << std::endl;

        unsigned long newPCvalue = PC.to_ulong() + 4;
        PC =  bitset<32> (newPCvalue);


        // Fetch

        // If current insturciton is "11111111111111111111111111111111", then break;

        // decode(Read RF)

        // Execute

        // Read/Write Mem

        // Write back to RF

        myRF.OutputRF(); // dump RF;
    }
        myDataMem.OutputDataMem(); // dump data mem

        return 0;

}
