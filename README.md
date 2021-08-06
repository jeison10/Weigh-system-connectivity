# Weigh-system-connectivity
Node-red platform with dashboard and a Raspberry pi for remote controlling a weigh system

The project was firstly based on a PIC 18F controller, which is able to weigh ration for houses inside a poultry farm. This new system was developed to avoid having to go in front of controller every time you wanted to start and control the process. 
Using the node-red platform with dashboard and a Raspberry pi, users are able to visualize the whole process inside a local network. The interface between the controller and the Raspberry was made over serial connection .

![1](https://user-images.githubusercontent.com/43612824/128532975-1a4b8930-be23-4fa4-aaad-bb10819a0962.jpg)

## Requirements and dependencies <h2>

You must install the latest version of node-red on you PC or raspberry pi. After that, import the json project file.
 
  For compiling the poject on node-red, you must also have installed the following nodes:
* dashboard
* SQLite
* serial node
* telegram
* ui-table 

 To compile the .C file you need the whole project and the CCS compiler. Mplab 8.92 was the IDE used for the PIC project

##  License <h2>

Unfortunately it is  a commercial projects developed for a company, so I cannot offer the whole C project code. The RS232.C is the file of the project responsible to make the interface between the rest of the entire code and the node-red code. I hope It might help you guys offering you a good example of how good this tool might be on your projects.  
