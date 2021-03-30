## P02 - Program 02: Graphviz Class
### Caleb Sneath
### Description:

This folder displays the use of classes to create a program that can convert an input file into Graphviz code.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [Source.cpp](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P02/Source.cpp)         | Main program that compiles converter      |
|   2   | [banner.txt](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P02/banner.txt) | My banner |
|   3   | [graphconfig.txt](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P02/graphconfig.txt)  |    The default config file    |
|   4   | [input.txt](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P02/input.txt)     | An example input file. This one ends up too big for Graphvis online normally but it is converted correctly. |
|   5   | [output.txt](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P02/output.txt)     | The output file whenever test.txt is ran through the config file in this folder |
|   6   | [test graph.png](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P02/test%20graph.png)     | A screenshot of output.txt's contents ran through Graphviz online |
|   6   | [test.txt](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P02/test.txt)     | An example input with the output in this folder |


### Instructions

- This program was originally created in Visual Studios. First copyand paste this program into a new project in Visual Studios.
- Place the "graphconfig.txt" file into the same directory.
- Place the input data file in the same directory. Name it whatever, then change the input file field in the graphconfig.txt file in a text editor. If desired, also change the name of the future output file.
- If using a subgraph within your graph, create a copy of the config file and place it in the same directory under a different name.
- If using a subgraph, rename one of the "null" fields of the config file to the new name of the subgraph's config file. The output section doesn't matter and won't be used.
- (Optional) If shapes are being used, the config file has a field for whether to verify if entered shape fields are valid or not.
- Run from local Windows Debugger

### Input File Format

- Begin with the graph type: (digraph, graph, or subgraph)
- In the next line list the number of nodes.
- In each subsequent line afterward, begin with the node id, a comma and any label associated with that id.
- After listing each node on each line, list the number of edges on a new line.
- List each edge on its own line in this format: from node, a comma, to node, a comma, and finally the label for that edge.
- The input file can end here, or node and edge shapes can be specified
- If continuing, list the number of graph nodes to specify on a line
- List the node id, then a comma, then the chosen shape
- After specifiying any node ids if applicable, list the number of edge shapes on a new line.
- Edge format is a little different from nodes. First list the desired shape on a new line, then a comma, and finally the node label
- The input file is now finished

<img src="test graph.png" width="800">
