# Navigate to Downloads
cd Downloads

# Create project directory
mkdir WordCountProject
cd WordCountProject

# Create classes directory for compiled files
mkdir classes

# Create Java program
nano WordCount.java

# Compile Java program with Hadoop classpath
javac -classpath $(hadoop classpath) -d classes WordCount.java

# Package compiled classes into a jar
jar -cvf wordcount.jar -C classes/ .

# Run Hadoop WordCount job
hadoop jar /Users/macm2/Downloads/WordCountProject/wordcount.jar WordCount /31352/input /31352/output

# View output from HDFS
hdfs dfs -cat "/31352/output/*"
