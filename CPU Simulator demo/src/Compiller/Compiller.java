package Compiller;

import java.nio.file.Files;
import java.util.HashMap;
import java.io.*;
import java.util.ArrayList;
import java.nio.file.Path;
import java.io.IOException;

public class Compiller {
    private HashMap<String, String> commands = new HashMap<String, String>();
    private ArrayList<String> wordlist = new ArrayList<>();
    private HashMap<String, String> reginfo = new HashMap<String, String>();
    private HashMap<String, String> addressinfo = new HashMap<String,String>();
    private HashMap<String, String> OperandTypes = new HashMap<>();

    private ArrayList<String> ReadFile(String file_path) {

        try {
            if (!Files.exists(Path.of(file_path))) {
                Files.createFile(Path.of(file_path));
            }


            File file = new File(file_path);
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            String line;
            while ((line = br.readLine()) != null) {
                String[] words = line.split("[ ,]+");
                for (String word : words) {
                    wordlist.add(word);
                }
            }

            br.close();
            fr.close();

            return wordlist;
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }

        return wordlist;
    }

    private void CopyFile(String file_path_s, String file_path_d) {
        try {
            if (!Files.exists(Path.of(file_path_d))) {
                Files.createFile(Path.of(file_path_d));
            }
            FileInputStream fis = new FileInputStream(file_path_s);
            FileOutputStream fos = new FileOutputStream(file_path_d);
            byte[] buffer = new byte[1024];
            int length;
            while ((length = fis.read(buffer)) > 0) {
                fos.write(buffer, 0, length);
            }
            fis.close();
            fos.close();
            System.out.println("File copied successfully.");
        } catch (IOException ioe) {
            System.out.println("Error while copying file: " + ioe.getMessage());
        }
    }

    private ArrayList<HashMap<String, String>> operandInfoList = new ArrayList<>();

    private void convertNumbersToBinary(ArrayList<String> wordList) {
        for (int i = 0; i < wordList.size(); i++) {
            String word = wordList.get(i);
            if (word.matches("\\d+")) {
                int number = Integer.parseInt(word);
                String binary = Integer.toBinaryString(number);
                wordList.set(i, binary);
            }
        }
    }
    private void writeArrayListToFile(ArrayList<String> arrayList, String filename) {
        try {
            FileWriter writer = new FileWriter(filename);

            StringBuilder lineBuilder = new StringBuilder();
            int counter = 0;

            for (String element : arrayList) {
                lineBuilder.append(element);
                counter++;

                if (counter % 5 == 0) {
                    writer.write(lineBuilder.toString().trim() + "\n");
                    lineBuilder.setLength(0);
                }
            }

            if (lineBuilder.length() > 0) {
                writer.write(lineBuilder.toString().trim());
            }

            writer.close();
            System.out.println("ArrayList elements written to file successfully!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private void Parsing(String file_path, HashMap<String, String> hashMap) {
        try {
            File file = new File(file_path);
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            String line;
            int index = 0;
            while ((line = br.readLine()) != null) {
                String[] words = line.split("[ ,]+");
                for (int i = 0; i < words.length; i++) {
                    String word = words[i];
                    if (hashMap.containsKey(word)) {
                        wordlist.set(index + i, hashMap.get(word));
                    }
                }
                index += words.length;
            }

            br.close();
            fr.close();

        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    public void WordlistConvertOperands()
    {
        for (String word : wordlist)
        {
            for (String key : OperandTypes.keySet())
            {
                if (word.equals(key))
                {
                    wordlist.set(wordlist.indexOf(word), OperandTypes.get(key));
                }
            }
        }
    }

    public int GetSizeOfInstructions()
        {
            return wordlist.size() / 3;
        }

        public Compiller(String file_path)
        {
            commands.put("MOV", "0000");
            commands.put("ADD", "0001");
            commands.put("SUB", "0010");
            commands.put("MUL", "0011");
            commands.put("DIV", "0100");
            commands.put("AND", "0101");
            commands.put("OR", "0110");
            commands.put("NOT", "0111");
            commands.put("CMP", "1000");
            commands.put("JMP", "1001");
            commands.put("JG", "1010");
            commands.put("JL", "1011");
            commands.put("JE", "1100");

            reginfo.put("AYB", "000");
            reginfo.put("BEN", "001");
            reginfo.put("GIM", "010");
            reginfo.put("DA", "011");
            reginfo.put("ECH", "100");
            reginfo.put("ZA", "101");

            OperandTypes.put("{0}", "00"); //reg
            OperandTypes.put("{1}", "01"); //addres
            OperandTypes.put("{2}", "10"); //literal


            for (int i = 0; i <= 96; ++i)
            {
                String binaryAddress = Integer.toBinaryString(i);
                String paddedAddress = String.format("%5s", binaryAddress).replace(' ', '0');
                String key = "[" + i + "]";
                addressinfo.put(key, paddedAddress);
            }

            ReadFile(file_path);

            CopyFile("src/Compiller/words.txt", "src/Compiller/CopyFile.txt");

            convertNumbersToBinary(wordlist);
            Parsing("src/Compiller/CopyFile.txt", commands);
            Parsing("src/Compiller/CopyFile.txt", reginfo);
            Parsing("src/Compiller/CopyFile.txt", addressinfo);
            writeArrayListToFile(wordlist, "src/Compiller/CopyFile.txt");
            CalculatingOperands(wordlist); //working with words.txt
            WordlistConvertOperands();
            writeArrayListToFile(wordlist, "src/Compiller/CopyFile.txt");
//            System.out.println(wordlist);
        }


    private ArrayList<HashMap<String, String>> OperandInfo(String file_path) {
        try {

            File file = new File(file_path);
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            String line;
            while ((line = br.readLine()) != null) {
                String[] words = line.split("[ ,]+");

                HashMap<String, String> operandMap = new HashMap<>();
                operandMap.put("op1", words[1]);
                operandMap.put("op2", words[2]);

                operandInfoList.add(operandMap);
            }

            br.close();
            fr.close();

            return operandInfoList;
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }

        return null;
    }

    private ArrayList<HashMap<String, String>> GetArrayList()
    {
        return operandInfoList;
    }

    private void CalculatingOperands(ArrayList<String> arrayList) {
        ArrayList<HashMap<String, String>> al = new ArrayList<>();
        al = OperandInfo("src/Compiller/words.txt");
        int index = 0;
        int state = 0;
        int offset = 0; // Смещение при добавлении элементов
        for (int i = 0; i < al.size(); ++i) {
            for (String key : reginfo.keySet()) {
                if (al.get(i).get("op1").equals(key)) {
                    for (String key2 : reginfo.keySet()) {
                        if (al.get(i).get("op2").equals(key2)) {
                            // Добавляем два значения "{0}" перед текущим индексом index
                            wordlist.add(index + offset, "{0}");
                            wordlist.add(index + offset, "{0}");
                            offset += 2; // Увеличиваем смещение на 2
                            index += 3; // Увеличиваем индекс на 3 для следующей тройки элементов
                            state = 1;
                        }
                    }
                }
            }

            for (String key : addressinfo.keySet()) {
                if (al.get(i).get("op1").equals(key)) {
                    for (String key2 : addressinfo.keySet()) {
                        if (al.get(i).get("op2").equals(key2)) {
                            // Добавляем два значения "{0}" перед текущим индексом index
                            wordlist.add(index + offset, "{1}");
                            wordlist.add(index + offset, "{1}");
                            offset += 2; // Увеличиваем смещение на 2
                            index += 3; // Увеличиваем индекс на 3 для следующей тройки элементов
                            state = 1;
                        }
                    }
                }
            }

            for (String key : reginfo.keySet()) {
                if (al.get(i).get("op1").equals(key)) {
                    for (String key2 : addressinfo.keySet()) {
                        if (al.get(i).get("op2").equals(key2)) {
                            // Добавляем два значения "{0}" перед текущим индексом index
                            wordlist.add(index + offset, "{1}");
                            wordlist.add(index + offset, "{0}");
                            offset += 2; // Увеличиваем смещение на 2
                            index += 3; // Увеличиваем индекс на 3 для следующей тройки элементов
                            state = 1;
                        }
                    }
                }
            }

            for (String key : addressinfo.keySet()) {
                if (al.get(i).get("op1").equals(key) && state != 1) {
                    for (String key2 : reginfo.keySet()) {
                        if (al.get(i).get("op2").equals(key2)) {
                            // Добавляем два значения "{0}" перед текущим индексом index
                            wordlist.add(index + offset, "{0}");
                            wordlist.add(index + offset, "{1}");
                            offset += 2; // Увеличиваем смещение на 2
                            index += 3; // Увеличиваем индекс на 3 для следующей тройки элементов
                            state = 1;
                        }
                    }
                }
            }

            for (String key : reginfo.keySet()) {
                if (al.get(i).get("op1").equals(key) && state != 1) {
                        wordlist.add(index + offset, "{2}");
                        wordlist.add(index + offset, "{0}");
                        offset += 2; // Увеличиваем смещение на 2
                        index += 3; // Увеличиваем индекс на 3 для следующей тройки элементов
                        state = 1;
                }
            }

            for (String key : addressinfo.keySet()) {
                if (al.get(i).get("op1").equals(key) && state != 1) {
                    wordlist.add(index + offset, "{2}");
                    wordlist.add(index + offset, "{1}");
                    offset += 2; // Увеличиваем смещение на 2
                    index += 3; // Увеличиваем индекс на 3 для следующей тройки элементов
                    state = 1;
                }
            }






            state = 0;
        }


    }

}
