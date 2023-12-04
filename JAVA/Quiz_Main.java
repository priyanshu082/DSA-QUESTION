
                                              //GROUP BETWEEN TWO STUDENTS

             //NAME : ARSALAN MURTAZA                                              // NAME : AQDUS BIN BARI

             //FACULTY NUMBER : 21COB640                                          // FACULTY NUMBER : 21COB537

             //ENROLLMENT NUMBER : GM6295                                         //ENROLLMENT NUMBER : GM8005
        



import java.awt.event.*; //importing AWT and Swing packages
import java.awt.*;
import javax.swing.*;

//Implementation of Quiz Class
class Quiz implements ActionListener{

    //Questions for the Quiz
    String[] questions = { 
                            "\tIn Which Course You Are Enrolled ?",
                            "\tWhat Is Name Of Your College ?",
                            "\tWhere Is Your College Located ?",
                            "\tYou Were Admitted In Which Year ?"
                         };
    
    //Options for the Quiz
    String[][] options = {
                            { "Bsc" , "B Tech", "B A", "B Com"},
                            { "ZHCET", "AIIMS", "IIIT", " MIT"},
                            { "Delhi", "Agra", "Jaipur", "Aligarh"},
                            { "2019", "2020", "2021", "2022"}
                          };

    //Correct Answers
    char[] answers = {
                        'B',
                        'A',
                        'D',
                        'C'
                     };

    char guess;
    char answer;
    int index;
    int correct_guesses = 0;
    int total_questions = questions.length;
    int result;
    int seconds = 10;

    //Instance of a JFrame Object
    JFrame frame = new JFrame();

    //Instances of a JTextField and JTextArea Objects
    JTextField textfield = new JTextField();
    JTextArea textarea = new JTextArea();

    //Instances of a JButton Object
    JButton buttonA = new JButton();
    JButton buttonB = new JButton();
    JButton buttonC = new JButton();
    JButton buttonD = new JButton();

    //Instances of a JLabel Object
    JLabel answer_labelA = new JLabel();
    JLabel answer_labelB = new JLabel();
    JLabel answer_labelC = new JLabel();
    JLabel answer_labelD = new JLabel();
    JLabel time_label = new JLabel();
    JLabel seconds_left = new JLabel();
    
    //Instances of JTextField Objects for Results
    JTextField number_right = new JTextField();
    JTextField percentage = new JTextField();

    //Setting up the timer for each question for 10 seconds
    Timer timer = new Timer(2500, new ActionListener(){
        @Override
        public void actionPerformed(ActionEvent e){
            seconds--;
            seconds_left.setText(String.valueOf(seconds));
            if (seconds <= 0)
            {
                displayAnswer();
            }

        }
    });

    //Quiz Constructor setting up the JFrame
    public Quiz(){
        //frame functionality
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(650,650);
        frame.getContentPane().setBackground(new Color(10,90,90));
        frame.setLayout(null);
        frame.setResizable(false);

        //textfield functionality
        textfield.setBounds(0,0,650,50);
        textfield.setBackground(new Color(25,25,25));
        textfield.setForeground(new Color(255,255,255));
        textfield.setFont(new Font("Andalus",Font.ITALIC,35));
        textfield.setBorder(BorderFactory.createBevelBorder(1));
        textfield.setHorizontalAlignment(JTextField.CENTER);
        textfield.setEditable(false);

        //textarea functionality
        textarea.setBounds(0,50,650,50);
        textarea.setLineWrap(true);
        textarea.setWrapStyleWord(true);
        textarea.setBackground(new Color(51,154,198));
        textarea.setForeground(new Color(255,255,255));
        textarea.setFont(new Font("Aharoni",Font.ITALIC,25));
        textarea.setBorder(BorderFactory.createBevelBorder(1));
        textarea.setEditable(false);

        //buttons functionality
        buttonA.setBounds(0,100,100,100);
        buttonA.setFont(new Font("Dialog",Font.BOLD,35));
        buttonA.setBackground(new Color(25,25,25));
        buttonA.setForeground(new Color(255,255,255));
        buttonA.setFocusable(true);
        buttonA.addActionListener(this);
        buttonA.setText("A");

        buttonB.setBounds(0,200,100,100);
        buttonB.setFont(new Font("Italic",Font.BOLD,35));
        buttonB.setBackground(new Color(25,25,25));
        buttonB.setForeground(new Color(255,255,255));
        buttonB.setFocusable(true);
        buttonB.addActionListener(this);
        buttonB.setText("B");

        buttonC.setBounds(0,300,100,100);
        buttonC.setFont(new Font("Italic",Font.BOLD,35));
        buttonC.setBackground(new Color(25,25,25));
        buttonC.setForeground(new Color(255,255,255));
        buttonC.setFocusable(true);
        buttonC.addActionListener(this);
        buttonC.setText("C");

        buttonD.setBounds(0,400,100,100);
        buttonD.setFont(new Font("Italic",Font.BOLD,35));
        buttonD.setBackground(new Color(25,25,25));
        buttonD.setForeground(new Color(255,255,255));
        buttonD.setFocusable(true);
        buttonD.addActionListener(this);
        buttonD.setText("D");

        //answer labels functionality
        answer_labelA.setBounds(115,100,500,100);
        answer_labelA.setFont(new Font("Times New Roman",Font.PLAIN,35));
        answer_labelA.setForeground(new Color(2,25,255));
        answer_labelA.setBackground(new Color(170,12,10));
        answer_labelA.setHorizontalAlignment(JTextField.CENTER);
        answer_labelA.setOpaque(true);
        answer_labelA.setBorder(BorderFactory.createBevelBorder(1));

        answer_labelB.setBounds(115,200,500,100);
        answer_labelB.setFont(new Font("Times New Roman",Font.PLAIN,35));
        answer_labelB.setForeground(new Color(255,255,255));
        answer_labelB.setBackground(new Color(120,120,120));
        answer_labelB.setHorizontalAlignment(JTextField.CENTER);
        answer_labelB.setOpaque(true);
        answer_labelB.setBorder(BorderFactory.createBevelBorder(1));

        answer_labelC.setBounds(115,300,500,100);
        answer_labelC.setFont(new Font("Times New Roman",Font.PLAIN,35));
        answer_labelC.setForeground(new Color(255,255,255));
        answer_labelC.setBackground(new Color(120,120,120));
        answer_labelC.setHorizontalAlignment(JTextField.CENTER);
        answer_labelC.setOpaque(true);
        answer_labelC.setBorder(BorderFactory.createBevelBorder(1));

        answer_labelD.setBounds(115,400,500,100);
        answer_labelD.setFont(new Font("Times New Roman",Font.PLAIN,35));
        answer_labelD.setForeground(new Color(255,255,255));
        answer_labelD.setBackground(new Color(120,120,120));
        answer_labelD.setHorizontalAlignment(JTextField.CENTER);
        answer_labelD.setOpaque(true);
        answer_labelD.setBorder(BorderFactory.createBevelBorder(1));

        //timer functionality
        seconds_left.setBounds(500,535,100,70);
        seconds_left.setFont(new Font("Ink Free",Font.BOLD,60));
        seconds_left.setBackground(new Color(64,64,64));
        seconds_left.setForeground(new Color(255,255,255));
        seconds_left.setBorder(BorderFactory.createBevelBorder(1));
        seconds_left.setOpaque(true);
        seconds_left.setHorizontalAlignment(JTextField.CENTER);
        seconds_left.setText(String.valueOf(seconds));

        //time label funtionality
        time_label.setBounds(500,510,100,25);
        time_label.setFont(new Font("Arial",Font.BOLD,16));
        time_label.setBackground(new Color(64,64,64));
        time_label.setForeground(new Color(255,255,255));
        time_label.setBorder(BorderFactory.createBevelBorder(1));
        time_label.setHorizontalAlignment(JTextField.CENTER);
        time_label.setOpaque(true);
        time_label.setText("Timer:");

        //right number of questions label functionality
        number_right.setBounds(225,225,200,100);
        number_right.setBackground(new Color(90,90,90));
        number_right.setForeground(new Color(255,255,255));
        number_right.setBorder(BorderFactory.createBevelBorder(1));
        number_right.setFont(new Font("Ink Free", Font.BOLD,50));
        number_right.setHorizontalAlignment(JTextField.CENTER);
        number_right.setEditable(false);

        //percentage functionality
        percentage.setBounds(225,325,200,100);
        percentage.setBackground(new Color(25,25,25));
        percentage.setForeground(new Color(255,255,255));
        percentage.setBorder(BorderFactory.createBevelBorder(1));
        percentage.setFont(new Font("Ink Free", Font.BOLD,50));
        percentage.setHorizontalAlignment(JTextField.CENTER);
        percentage.setEditable(false);
        
        //adding tools to frame
        frame.setVisible(true);
        frame.add(textfield);
        frame.add(textarea);
        frame.add(buttonA);
        frame.add(buttonB);
        frame.add(buttonC);
        frame.add(buttonD);
        frame.add(answer_labelA);
        frame.add(answer_labelB);
        frame.add(answer_labelC);
        frame.add(answer_labelD);
        frame.add(seconds_left);
        frame.add(time_label);

        //calling the nextQuestion functions
        nextQuestion();
    }

    //Implementing nextQuestion function
    public void nextQuestion(){
      //when all questions are attempted
      if (index>=total_questions)
      {
        results();
      }
      //diplaying the question and its options
      else
      {
        textfield.setText("QUESTION NO : "+(index+1));
        textarea.setText(questions[index]);
        answer_labelA.setText(options[index][0]);
        answer_labelB.setText(options[index][1]);
        answer_labelC.setText(options[index][2]);
        answer_labelD.setText(options[index][3]);

        //staring the timer also
        timer.start();
      }
    }
    
    //Implementation of actionPerformed used for detect the right answers
    public void actionPerformed(ActionEvent e){
      //Disabling the buttons
      buttonA.setEnabled(false);
      buttonB.setEnabled(false);
      buttonC.setEnabled(false);
      buttonD.setEnabled(false);

      //Incrementing correct_guesses for each right answer
      if(e.getSource()==buttonA)
      {
        answer = 'A';
        if(answer == answers[index])
        {
          correct_guesses++;
        }
      }

      if(e.getSource()==buttonB)
      {
        answer = 'B';
        if(answer == answers[index])
        {
          correct_guesses++;
        }
      }

      if(e.getSource()==buttonC)
      {
        answer = 'C';
        if(answer == answers[index])
        {
          correct_guesses++;
        }
      }

      if(e.getSource()==buttonD)
      {
        answer = 'D';
        if(answer == answers[index])
        {
          correct_guesses++;
        }
      }
      //Displaying the correct answer among the options given
      displayAnswer();
    }

    //Implementing displayAnswer function
    public void displayAnswer(){
      //stoping the timer
      timer.stop();

      //Disabling the buttons
      buttonA.setEnabled(false);
      buttonB.setEnabled(false);
      buttonC.setEnabled(false);
      buttonD.setEnabled(false);

      //Changing the colour to red for wrong options
      if(answers[index] != 'A')
          answer_labelA.setForeground(new Color(255,0,0));
      if(answers[index] != 'B')
          answer_labelB.setForeground(new Color(255,0,0));
      if(answers[index] != 'C')
          answer_labelC.setForeground(new Color(255,0,0));
      if(answers[index] != 'D')
          answer_labelD.setForeground(new Color(255,0,0));
      
      //Getting forward to the next question after 2.5 seconds pause
      Timer pause = new Timer(2500, new ActionListener(){
        @Override
        public void actionPerformed(ActionEvent e){
          //changing the colours back to White
          answer_labelA.setForeground(new Color(255,255,255));
          answer_labelB.setForeground(new Color(255,255,255));
          answer_labelC.setForeground(new Color(255,255,255));
          answer_labelD.setForeground(new Color(255,255,255));

          //restoring the variables
          answer = ' ';
          seconds = 10;
          seconds_left.setText(String.valueOf(seconds));

          //Enabling the buttons
          buttonA.setEnabled(true);
          buttonB.setEnabled(true);
          buttonC.setEnabled(true);
          buttonD.setEnabled(true);

          //Incrementing the index for the next question
          index++;

          //calling nextQuestion function
          nextQuestion();
        }
      });

      //calling the start method of pause object and stopping it from repition
      pause.start();
      pause.setRepeats(false);
    }

    //Implemeting results function
    public void results(){
      //Disabling the buttons
      buttonA.setEnabled(false);
      buttonB.setEnabled(false);
      buttonC.setEnabled(false);
      buttonD.setEnabled(false);
      
      //calculating the result percentage
      result = (int)((correct_guesses/(double)total_questions)*100);

      //Displaying the RESULTS message
      textfield.setText("\tResults ");
      textarea.setText("\tYour Results Are Below : ");

      //Removing the labels and buttons from RESULT frame
      answer_labelA.setVisible(false);
      answer_labelB.setVisible(false);
      answer_labelC.setVisible(false);
      answer_labelD.setVisible(false);
      buttonA.setVisible(false);
      buttonB.setVisible(false);
      buttonC.setVisible(false);
      buttonD.setVisible(false);
      time_label.setVisible(false);
      seconds_left.setVisible(false);
      
      //Dispalaying the PERCENTAGE and No. of correct answers
      number_right.setText("["+correct_guesses+"/"+total_questions+"]");
      percentage.setText("("+result+"%)");
      
      //Finally adding the PERCENTAGE and No. of correct answers to the frame
      frame.add(number_right);
      frame.add(percentage);
    }
}

//Main Driving Class
public class Quiz_Main
{
  public static void main(String[] args) throws Exception
  {
       Quiz quiz = new Quiz(); //Creating a quiz object
  }
}