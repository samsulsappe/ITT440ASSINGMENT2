import java.io.*;
import java.net.*;

public class server {
		public static void main(String[]args) throws IOException{
		ServerSocket s1=new ServerSocket(2345);
		while(true) {
		Socket connectionsocket=s1.accept();
		BufferedReader messagefromloadbalancer = new BufferedReader(new InputStreamReader(connectionsocket.getInputStream());
		String clientsentence = messagefromclient.readLine();

		if(clientsentence.contains("book")){
		Socket server =new Socket("192.168.120.128",2345);
		DataOutputStream outtoserver=new  DataOutputStream(server.getOutputStream());
		outtoserver.writeBytes(clientsentence+ "\n");
		server.close();

		}
	
		if(clientsentence.contains("pen")){
		Socket server =new Socket("192.168.120.129",2346);
		DataOutputStream outtoserver2=new  DataOutputStream(server2.getOutputStream());
		outtoserver2.writeBytes(clientsentence+ "\n");
		server2.close();

		}

		else 
		System.out.println("ERROR!");
		}

	}
}