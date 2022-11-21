/**********************************************************************
 *  ps7-readme.txt                                                   
 *  Kronos PS7
 **********************************************************************/

Name: Jacob George


Hours to complete assignment (optional): 4-5 hours


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes I have successfully completed the assignment. I was able to implement two regex strings for me to compare
each line of the file, and I was able to implement the file parsing line-by-line, looking for specific
string messages that indicated if the server started, finished, or was an incomplete boot

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/

boost::regex bootStart("\\d{4}-\\d{2}-\\d{2}\\s\\d{2}:\\d{2}:\\d{2}:\\s\\log\\.c\\.166\\\\sserver\\sstarted\\s");
This regex will first read the date (Year-Month-Day), then it will read the time (hour:seconds:milliseconds). Then it
check to see if the line from the file will have the boot start message: log.c.166 server started


boot::regex bootCompleted("\\d{4}-\\d{2}-\\d{2}\\s\\d{2}:\\d{2}:\\d{2}.\\d{3}:INFO:oejs.AbstractConnector:Started\\sSelectChannelConnector@\\d{1}.\\d{1}.\\d{1}.\\d{1}:\\d{4}");
This regex will first read the date (Year-Month-Day), then it will read the time (hour:seconds:milliseconds). Then it
reads the 3-digit port number, the boot completed message: INFO:oejs.AbstractConnector:Started SelectChannelConnector, and finally
will read the IP address

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
I first created a while loop that read the file and called getline() inside of it. I stored the line of the file
into a string and did the substring of it just for printing out the date and time of the file later. The way that my
if statements work is that I have a boolean variable that is set to 0 at the start. We know that when you read
the first boot start message, it should look for a boot complete message. If getline() reads another boot start
message, that boot is deemed an incomplete boot. When the first boot start message is read, my boolean variable changes to a 1.
As it keeps reading and if it gets to another boot start message AND the boolean variable is 1 (to differentiate if it was the
first boot message or the second boot message) then it will run an incomplete boot and move on to the next boot start. Otherwise when it reads the
boot complete line, it will calculate the time duration from boot start, print out the boot complete message, and
print out the time duration in ms. 


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Learning about date and time:
https://www.boost.org/doc/libs/1_57_0/doc/html/date_time.html

Learning about substring:
https://www.geeksforgeeks.org/substring-in-cpp/

Class notes about Regex

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I did not run into any serious problems

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
how to run:
make
./ps7 <name of log file>
make clean

