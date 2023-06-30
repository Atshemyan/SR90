package Ram;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Ram {
    private byte[] memory;

    public Ram() {
        memory = new byte[96];
    }

    public byte[] getMemory() {
        return memory;
    }

    public void loadProgram(String filePath) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            int address = 0;
            int bitCount = 0;
            byte byteValue = 0;

            while ((line = reader.readLine()) != null) {
                for (int i = 0; i < line.length(); i++) {
                    char bitChar = line.charAt(i);
                    byteValue <<= 1; // Сдвигаем значение на 1 бит влево
                    byteValue |= (bitChar == '1') ? 1 : 0; // Устанавливаем младший бит в соответствии с символом

                    bitCount++;
                    if (bitCount == 8) { // Если уже собраны 8 битов
                        memory[address++] = byteValue; // Сохраняем значение в массиве
                        bitCount = 0;
                        byteValue = 0;
                    }
                }
                // Проверяем, если строка закончилась, но еще не заполнены 3 элемента памяти
                while (bitCount < 8 && address % 3 != 0) {
                    // Дополняем оставшиеся элементы памяти нулями
                    while (bitCount < 8 && address % 3 != 0) {
                        byteValue <<= 1; // Сдвигаем значение на 1 бит влево
                        bitCount++;
                    }
                    memory[address++] = byteValue; // Сохраняем значение в массиве
                    bitCount = 0;
                    byteValue = 0;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }



    public void editMemory(int address, byte value) {
        if (address >= 0 && address < memory.length) {
            memory[address] = value;
        } else {
            System.out.println("Invalid memory address.");
        }
    }
}
