import Ram.Ram;
import Compiller.Compiller;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import Cpu.Cpu;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        String file_path = "src/Compiller/words.txt";
        Compiller compiller = new Compiller(file_path);
        Ram ram = new Ram();
        ram.loadProgram("src/Compiller/CopyFile.txt");
//        for (int i = 0; i < ram.getMemory().length; i += 3) {
//            int value = ((ram.getMemory()[i] & 0xFF) << 16) | ((ram.getMemory()[i + 1] & 0xFF) << 8) | (ram.getMemory()[i + 2] & 0xFF);
//            String binaryString = String.format("%24s", Integer.toBinaryString(value)).replace(' ', '0');
//            System.out.println(binaryString.substring(0, 8));
//            System.out.println(binaryString.substring(8, 16));
//            System.out.println(binaryString.substring(16, 24));
//        }
        Cpu cpu = new Cpu();
        cpu.RunCPU(ram.getMemory(), compiller.GetSizeOfInstructions());


    }





}
