package Cpu;

public class Register
{
    private byte reg_memory;

    public void SetMemory(byte value)
    {
//        if (value > 255)
//        {
//            //overflo
//        }
        reg_memory = value;
    }

    public byte GetMemory()
    {
        return reg_memory;
    }


}


