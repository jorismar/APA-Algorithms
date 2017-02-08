
import Sorting.*;
import java.lang.reflect.Method;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;
import static java.util.concurrent.TimeUnit.SECONDS;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jorismar
 */
public class Main {
    private static void printErrMsg() {
        System.out.println("Invalid Arguments\n\nUsage:\n\n");
        System.out.println(" -s\tUse selection sort algorithm\n");
        System.out.println(" -i\tUse insertion sort algorithm\n");
        System.out.println(" -m\tUse merge sort algorithm\n");
        System.out.println(" -q\tUse quick sort algorithm\n");
        System.out.println(" -h\tUse heap sort algorithm\n\n");
        System.out.println(" -d\tUse default sort algorithm (Arrays.sort)\n\n");
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        boolean is_benchmark = false;
        
	// Check arguments
	if (args.length < 1) {
            printErrMsg();
            return;
	}

	if (args.length == 2) {
            if (args[1].equals("-b"))
                is_benchmark = true;
            else {
                printErrMsg();
                return;
            }
	} 

        SortAlgorithm algorithm;
        
        if(args[0].equals("-s"))
            algorithm = new Selection();
        else if(args[0].equals("-i"))
            algorithm = new Insertion();
        else if(args[0].equals("-m"))
            algorithm = new Merge();
        else if(args[0].equals("-q"))
            algorithm = new Quick();
        else if(args[0].equals("-h"))
            algorithm = new Heap();
        else if(args[0].equals("-d"))
            algorithm = new Default();
        else {
            printErrMsg();
            return;
        }
        
        Scanner scan = new Scanner (System.in);
        int size = scan.nextInt();
        
        int list[] = new int[size];
        
        for(int i = 0; i < size; i++)
            list[i] = scan.nextInt();
        
        long begin = System.nanoTime();//currentTimeMillis();//
        
        algorithm.Sort(list);

        long end = System.nanoTime();//currentTimeMillis();//
        
        if(is_benchmark) {
            double sec = ((double)end - (double)begin) / 1000000000.0;
            System.out.print("" + sec + ";");
        }
        else 
            for(int value: list)
                System.out.println(value);
    }
}
