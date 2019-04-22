/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

public class PC {
    
    static Scanner reader = new Scanner(System.in);
    static int[] array =new int[100];
    static Semaphore full = new Semaphore(0);
    static Semaphore empty = new Semaphore(5);
    static Semaphore mutex = new Semaphore(1);
    static int head=0;
    static int item=0;
    
    static class Consumer implements Runnable{
        @Override
        public void run(){
            
            try {
                while(true){
                full.acquire();
                mutex.acquire();
                System.out.println("Output: "+array[head-1]);
                item--;
                    System.out.println(head);
                head--;
                mutex.release();
                empty.release();
                Thread.sleep(1000);
                }
            } 
          /*  catch (InterruptedException ex) {
                Logger.getLogger(ReaderWriterProblem.class.getName()).log(Level.SEVERE, null, ex);
            }*/
          catch(Exception e){
              System.out.println(e.getMessage());
          }
                
            
        }
    }
    
    static class Producer implements Runnable{
        @Override
        public void run(){
            try{
                while(true){
                empty.acquire();
                mutex.acquire();
                int random=(int) (Math.random()+2);
                array[head++]=item;
                    System.out.println("Input: "+item++);
                
                mutex.release();
                full.release();
                Thread.sleep(2000);
                }
               
                
            }
            catch(Exception e){
              System.out.println(e.getMessage());
          }
        }
    }
    
    public static void main(String[] args) {
        
        Producer read = new Producer();
        Consumer write = new Consumer();
        
        Thread t1 = new Thread(read);
        t1.setName("Producer1");
       
        
        Thread t3 = new Thread(write);
        t3.setName("Consumer1");
        
        Thread t4 = new Thread(write);
        t4.setName("Consumer2");
        
        
        
      
        
        
        
       
        t3.start();
        t1.start();
    }
    
    
}
