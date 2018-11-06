import javax.swing.*;
import javax.swing.border.*;
import java.awt.event.*;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.io.*;
import java.net.*;

public class GUI extends JFrame{
	
	private static final long serialVersionUID = 1L;
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;
	private static Socket sock;
	private static BufferedReader input;
	private static BufferedWriter output;
	static JTextArea textA;
	static JTextField search;
	static String answer;
	JButton browse,play,quit;
	JScrollPane scroll;
	JPanel panel;
	JMenuBar menuBar;
	JMenu menu;
	JMenuItem menuItem;
	
	/**
	 * Server function
	 */
	
	public void serverControl(String request) {
		 // Envoyer la requete au serveur
		 try {
		   request += "\n";  // ajouter le separateur de lignes
		   output.write(request, 0, request.length());
		   output.flush();
		 }
		 catch (java.io.IOException e) {
		   System.err.println("Client: Couldn't send message: " + e);
		   JOptionPane.showMessageDialog(null, "Client: Couldn't send message","Error",JOptionPane.ERROR_MESSAGE);
		 }
		 
		 try {
			 answer = input.readLine();
			 System.out.println(answer);
			 if(answer.equals("No multimedia found ;No group found "))
				 JOptionPane.showMessageDialog(null, "No Media or Group Found","Error",JOptionPane.ERROR_MESSAGE);
			 else if(answer.equals("No multimedia to play"))
				 JOptionPane.showMessageDialog(null, "No Media or Group to play","Error",JOptionPane.ERROR_MESSAGE);
			 else {
				 textA.append(answer.replace(";", "\n")+"\n"); 
			 }
		 }
		 catch (java.io.IOException e) {
		   System.err.println("Client: Couldn't receive message: " + e);
		 //  JOptionPane.showMessageDialog(null, "Client: Couldn't receive message","Error",JOptionPane.ERROR_MESSAGE);
		 }
	}


	/**
	 *  Abstract actions 
	 */

	class txt1Act extends AbstractAction{
		 public txt1Act() {}
		
		 public void actionPerformed(ActionEvent e){
			 textA.append(search.getText()+"\n");
			 serverControl("SEARCH>"+search.getText());
			 search.setText("");
		 }
	}
	class txt2Act extends AbstractAction{
		 public txt2Act() {}
		
		 public void actionPerformed(ActionEvent e){
			 textA.append(search.getText()+"\n");
			 serverControl("PLAY>"+search.getText());
			 search.setText("");
		 }
	}
	class quitAct extends AbstractAction{
		 public quitAct() {}
		
		 public void actionPerformed(ActionEvent e){
			 System.exit(0);
		 }
	}
	
	quitAct quitAct= new quitAct();
	txt1Act bbtnAct =  new txt1Act();
	txt2Act bbtn2Act =  new txt2Act();
	
	/**
	 *  GUI fonction
	*/
	public GUI() {
		
		
		setSize(new Dimension(400,600));
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		
		browse = new JButton(bbtnAct);
		browse.setText("SEARCH");
	
		play = new JButton(bbtn2Act);
		play.setText("PLAY");
		
	    quit = new JButton(quitAct);
	    quit.setText("QUIT");
	    
	    textA = new JTextArea(20,50);
	    textA.setEditable(false);
	    
	    search = new JTextField("SEARCH");
        getContentPane().add(search, BorderLayout.NORTH);
	    
    
	    panel = new JPanel();
	    
	    scroll = new JScrollPane(textA,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);	    
	    getContentPane().add(scroll, BorderLayout.CENTER);
	
	    
		panel.add(browse);
	    panel.add(play);
	    panel.add(quit);
	    
	    getContentPane().add(panel, BorderLayout.SOUTH);
	    	   	   
	    menuBar = new JMenuBar();
	    menu = new JMenu("Menu");
	    menu.setMnemonic(KeyEvent.VK_A);
	    menu.getAccessibleContext().setAccessibleDescription("The only menu in this program that has menu items");
	    menuBar.add(menu); 
	    
	    menuItem = new JMenuItem(bbtnAct);
	    menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_1, ActionEvent.ALT_MASK));
	    menuItem.setText("Search");
	    menu.add(menuItem);

	    menuItem = new JMenuItem(bbtn2Act);
	    menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_2, ActionEvent.ALT_MASK));
	    menuItem.setText("Play");
	    menu.add(menuItem);
	    
	    menuItem = new JMenuItem(quitAct);
	    menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_3, ActionEvent.ALT_MASK));
	    menuItem.setText("Exit");
	    menu.add(menuItem);

	   this.setJMenuBar(menuBar);
	    
	    
		setTitle("GUI");
		pack();
		setVisible(true);
	}
	
	public static void main(String argv[] ) throws IOException{
		
		GUI gui = new GUI();
		
		String host = DEFAULT_HOST;
		int port = DEFAULT_PORT;
		if (argv.length >=1) host = argv[0];
		if (argv.length >=2) port = Integer.parseInt(argv[1]);
	
		try {
			   sock = new java.net.Socket(host, port);
			 }
			 catch (java.net.UnknownHostException e) {
			   System.err.println("Client: Couldn't find host "+host+":"+port);
			   JOptionPane.showMessageDialog(null, "Client: Couldn't find host "+host+":"+port,"Error",JOptionPane.ERROR_MESSAGE);
			   throw e;
			 }
			 catch (java.io.IOException e) {
			   System.err.println("Client: Couldn't reach host "+host+":"+port);
			   JOptionPane.showMessageDialog(null, "Client: Couldn't reach host "+host+":"+port,"Error",JOptionPane.ERROR_MESSAGE);
			   throw e;
			 }			 
			 try {
			   input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			   output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
			 }
			 catch (java.io.IOException e) {
			   System.err.println("Client: Couldn't open input or output streams");
			   JOptionPane.showMessageDialog(null, "Client: Couldn't open input or output streams","Error",JOptionPane.ERROR_MESSAGE);
			   throw e;
			 }
		System.out.println("Client connected to "+host+":"+port);
		
	}	
}
