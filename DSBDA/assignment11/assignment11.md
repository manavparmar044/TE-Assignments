# Hadoop WordCount MapReduce Project

A simple Hadoop MapReduce WordCount project using Java and Hadoop 3.3.3.

## Setup & Execution
Follow the steps below to compile, package, and run the job in your local Hadoop environment.

# Check Java version
java -version

# Check Hadoop version
hadoop version

# Start HDFS daemons
start-dfs.sh

# Start YARN daemons
start-yarn.sh

# Verify all Hadoop daemons are running
jps

# Create base directory in HDFS
hdfs dfs -mkdir /31352

# Create input directory inside the base directory
hdfs dfs -mkdir /31352/input

# Upload input file to HDFS
hdfs dfs -put /Users/macm2/Downloads/input.txt /31352/input
