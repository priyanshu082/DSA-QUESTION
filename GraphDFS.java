import javax.swing.* ;
import java.awt.* ;
import java.awt.event.ActionEvent ;
import java.awt.event.ActionListener ;
import java.util.List ;
import java.util.Scanner ;
import java.util.concurrent.ExecutionException ;

public class GraphDFS extends JFrame{
    private JPanel panel ;
    private JTextArea textArea ;
    private JButton dfsButton ;
    private java.util.Map<Integer , java.util.List<Integer>> graph ;  
    private boolean[] visited ;

    public GraphDFS(){
        setTitle("DFS Graph Traversal Visualization") ;
        setSize(600 , 600) ;
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE) ;
        setLocationRelativeTo(null) ;

        panel = new JPanel(){
            public void paintComponent(Graphics g){
                super.paintComponent(g) ;
                drawGraph(g) ;
            }
        } ;
        textArea = new JTextArea(5 , 40) ;
        dfsButton = new JButton("Start DFS") ;

        panel.setBackground(Color.WHITE) ;
        add(panel, BorderLayout.CENTER) ;
        add(textArea, BorderLayout.SOUTH) ; 
        add(dfsButton, BorderLayout.NORTH) ;

        dfsButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                startDFSVisualization() ;
            }
        }) ;

        // initizalize graph
        graph = new java.util.HashMap<>() ;  
        initializeGraphFromUserInput() ;

        // bool array
        visited = new boolean[graph.size()] ;
    }

    private void initializeGraphFromUserInput(){
        Scanner scanner = new Scanner(System.in) ;
        System.out.println("Enter the number of nodes in the graph:") ;
        int nodes = scanner.nextInt() ;
        System.out.println("enter the edges 'u v' where u and v are nodes (-1 -1 to stop):") ;

        // initialize graph nodes
        for (int i = 0 ; i < nodes ; i++){
            graph.put(i , new java.util.ArrayList<>()) ;  
        }

        while (true){
            int u = scanner.nextInt() ;
            int v = scanner.nextInt() ;
            if (u == -1 && v == -1) break ;

            if (!graph.containsKey(u)){
                graph.put(u, new java.util.ArrayList<>());
            }
            if (!graph.containsKey(v)){
                graph.put(v, new java.util.ArrayList<>());
            }
              graph.get(u).add(v) ;

            graph.get(v).add(u) ;
        }
    }

    private void startDFSVisualization(){
        java.util.Arrays.fill(visited, false) ;  
        textArea.setText("") ;  

        // swingWorker - background processing and ui updates
        SwingWorker<Void, Integer> worker = new SwingWorker<>(){
            protected Void doInBackground(){
                dfs(0) ;  
                return null ;
            }

            private void dfs(int node){
                visited[node] = true ;
                publish(node) ; 
                try{
                    Thread.sleep(500) ;  
                }catch (InterruptedException e){
                    e.printStackTrace() ;
                }
                for (int neighbor : graph.get(node)){
                    if (!visited[neighbor]){
                        dfs(neighbor) ;
                    }
                }
            }
            protected void process(List<Integer> chunks){
                for (int node : chunks){
                    textArea.append("Visited node: " + node + "\n") ;
                    panel.repaint() ;  
                }
            }
            protected void done(){
                try{
                    get() ;  // to catch and handle any exceptions that occurred in doInBackground
                }catch(InterruptedException | ExecutionException e){
                    e.printStackTrace() ;
                }
            }
        } ;

        worker.execute() ; 
    }

    private void drawGraph(Graphics g){
        int radius = 20 ; 
        int centerX = panel.getWidth() / 2 ;
        int centerY = panel.getHeight() / 2 ;
        int graphSize = graph.size() ;
        int angleStep = 360 / graphSize ;

        java.util.Map<Integer , Point> nodePositions = new java.util.HashMap<>() ;  
        for (int i = 0; i < graphSize; i++){
            int angle = i * angleStep ;
            int x = (int) (centerX + 200 * Math.cos(Math.toRadians(angle))) ;
            int y = (int) (centerY + 200 * Math.sin(Math.toRadians(angle))) ;
            nodePositions.put(i, new Point(x, y)) ;

            g.setColor(visited[i] ? Color.RED : Color.PINK) ;  
            g.fillOval(x - radius / 2, y - radius / 2, radius, radius) ;
            g.setColor(Color.BLACK) ;
            g.drawString(String.valueOf(i) , x - 5 , y + 5) ;
        }

        g.setColor(Color.BLUE) ;
        for(int u : graph.keySet()){
            for(int v : graph.get(u)){
                Point p1 = nodePositions.get(u) ;
                Point p2 = nodePositions.get(v) ;
                g.drawLine(p1.x, p1.y, p2.x, p2.y) ;
            }
        }
    }

    public static void main(String[] args){
        SwingUtilities.invokeLater(() -> new GraphDFS().setVisible(true)) ;
    }
}