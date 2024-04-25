/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pbofpcustomerserviceapp;


public class ServiceChatProtocol {
    //Status in the protocol's logic
    private static final int WAITING = 0;
    private static final int ASK1 = 1;
    private static final int PEMBELI = 2;
    private static final int PENJUAL = 3;
    private static final int TOKO = 4;
    private static final int PEMBAYARAN = 5;
    private static final int PENGIRIMAN = 6;
    private static final int BARANG = 7;
    private static final int CHAT = 8;

    //first status is waiting for the client's first chat
    private int state = WAITING;
    public boolean chatLiveServer = false;
    
    public String processInput(String input){
        String output = "";

        //welcome the client and ask their roles in the application
        if(state == WAITING){
            output = "Welcome to the Shopepes's Customer Service.\nIn advance, could you tell us wheter you are a 'Buyer'/'Seller'?\n\nEnter 'exit' to cancel";
            state = ASK1;
        }else if(state == ASK1){
            //if they are "buyer", ask them which buyer's problem they are having and switch the state to "PEMBELI"
            //else if they are "seller", ask them which seller's problem they are having and switch the state to "PENJUAL"
            //if their answer is none of both, ask them again between those two
            if(input.equalsIgnoreCase("buyer")){
                output = "Hello, customer, how we may help you?\nCould you please give details?\nType 'Shipment' for shipping problem\nType 'Items' for items problem";
                state = PEMBELI;
            }else if(input.equalsIgnoreCase("seller")){
                output = "Hello partner, how we may help you?\nCould you please give details?\nType 'Store' for store problems\nType 'Payment' for payments problem";
                state = PENJUAL;
            }else{
                output = "Please type 'Buyer' / 'Seller'";
            }
        }else if(state == PEMBELI){
            //if the answer is "shipment", show the prefix solution and change the state to PENGIRIMAN
            //else if the answer is "items", show the prefix solution and change the state to BARANG
            //if none of both, ask them again
            if(input.equalsIgnoreCase("shipment")){
                output = "We are sorry for your inconvenience. We suggest you to read the shipment's problems in the link below\nhtttps:/shopepes-customerService-problem-buyer-shipment\n\nIs this helps you? (Yes/No)";
                state = PENGIRIMAN;
            }else if(input.equalsIgnoreCase("items")){
                output = "We are sorry for your inconvenience. We suggest you to read the item's problems in the link below\nhtttps:/shopepes-customerService-problem-buyer-items\n\nIs this helps you? (Yes/No)";
                state = BARANG;
            }else{
                output = "Please type 'Shipment'/'Items'";
            }
        }else if(state == PENJUAL){
            //if the answer is "store", show the prefix solution and change the state to TOKO
            //if the answer is "payment", show the prefix solution and change the state to PEMBAYARAN
            //if none of both, ask them again
            if(input.equalsIgnoreCase("store")){
                output = "We are sorry for your inconvenience. We suggest you to read the store's problems in the link below\nhtttps:/shopepes-customerService-problem-seller-store\n\nIs this helps you? (Yes/No)";
                state = TOKO;
            }else if(input.equalsIgnoreCase("payment")){
                output = "We are sorry for your inconvenience. We suggest you to read the payment's problems in the link below\nhtttps:/shopepes-customerService-problem-seller-payment\n\nIs this helps you? (Yes/No)";
                state = PEMBAYARAN;
            }else{
                output = "Please type 'Store'/'Payment'";
            }
        }
        else if(state == PENGIRIMAN ||state == BARANG || state == TOKO || state == PEMBAYARAN){
            //the last question is to ask them if the solution if sufficient for their problem
            //if yes, back to the beginning state - if no, offer them for liveChat with the customer service server
            //if none of both, ask them again
            if(input.equalsIgnoreCase("yes")){
                output = "We glad that we could help. We hope you have a great day:)";
                state = WAITING;
            }else if(input.equalsIgnoreCase("no")){
                output = "We are sorry if you still not finding the right solution.\nWe will connect you to our employee immediately.\nFeel free to ask everything related to your problem:)\n";
                state = CHAT;
            }else{
                output = "Please type 'yes' or 'no'";
            }
        }
        //chatLiveServer toggle on
        if(state == CHAT){
            chatLiveServer = true;
        }
        return output;
    }
}
