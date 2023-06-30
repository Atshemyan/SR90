package Cpu;
import Cpu.Register;
import Compiller.Compiller;

public class Cpu {
    private Register AYB;
    private Register BEN;
    private Register GIM;
    private Register DA;
    private Register ECH;
    private Register ZA;
    private Register GH;

    public Cpu() {
        AYB = new Register();
        BEN = new Register();
        GIM = new Register();
        DA = new Register();
        ECH = new Register();
        ZA = new Register();
        GH = new Register();
    }

    void MOV(Register First, Register Second)
    {
        First.SetMemory(Second.GetMemory());
    }


    public void RunCPU(byte[] ram_bytes, int number_of_instructions) {
        int start = 0;
        int end = 23;
        for (int i = 0; i < number_of_instructions; ++i) {
            int instruction = ((ram_bytes[0] & 0xFF) << 16) |
                    ((ram_bytes[0 + 1] & 0xFF) << 8) |
                    (ram_bytes[0 + 2] & 0xFF);

            // Create a StringBuilder to store the bits
            StringBuilder bitString = new StringBuilder();

            // Read each bit of the instruction
            for (int j = end; j >= start; j--) {
                int bit = (instruction >> j) & 0x01;

                bitString.append(bit);
            }


            // Check the operand types
            String operandType = bitString.substring(0, 2);
            String operandType2 = bitString.substring(2, 4);

            String operand1value;
            String operand2value;

            // Get the instruction code
            String instructionCode = bitString.substring(4, 8);
            operand1value = bitString.substring(8, 11);
            operand2value = bitString.substring(11, 14);


            // Perform actions based on instruction and operand types
            switch (operandType) {
                case "00":
                    // Register operands
                    switch (operandType2) {
                        case "00":
                            // Register-Register operands
                            if (instructionCode.equals("0000")) {

                                switch (operand1value) {
                                    case "000":
                                        switch (operand2value) {

                                            case "000":
                                                MOV(AYB, AYB);
                                                break;
                                            case "001":
                                                BEN.SetMemory((byte) 1);
                                                MOV(AYB, BEN);
                                                break;
                                            case "010":
                                                MOV(AYB, GIM);
                                                break;
                                            case "011":
                                                MOV(AYB, DA);
                                                break;
                                            case "100":
                                                MOV(AYB, ECH);
                                            case "101":
                                                MOV(AYB, ZA);
                                                break;
                                            default:
                                                // Handle invalid operand2value
                                                break;
                                        }
                                        break;

                                }

                            }
                            break;

                        default:
                            // Invalid operand type
                            System.out.println("Invalid operand type");
                            break;
                    }
                    break;
                //other...
                default:
                    // Invalid operand type
                    System.out.println("Invalid operand type");
                    break;
            }

            // Clear the bitString for the next iteration
            bitString.setLength(0);
            start += 23;
            end += 23;
            System.out.println(AYB.GetMemory());
        }



    }


}

