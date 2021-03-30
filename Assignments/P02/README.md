## P02 - Program 02: Graphviz Class
### Caleb Sneath
### Description:

This folder displays the use of classes to create a program that can convert an input file into Graphviz code.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [main.cpp](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/main.cpp)         | Main program that compiles game      |
|   2   | [Asteroid Dodger Screenshot.png](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/Asteroid%20Dodger%20Screenshot.png)  | A screenshot that shows gameplay         |
|   3   | [Banner.txt](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/Banner.txt) | My banner |
|   4   | [main.exe](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/main.exe)     | Game executable |
|   5   | [main.o](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/main.o)     | File you should get while following compile instructions |
|   6   | [arial.ttf](https://github.com/CalebSneath/2143-OOP-sneath/blob/main/Assignments/P01/arial.ttf)     | Game font file, obtained from zyedidia |
|   7   | Everything else | Miscellaneous SFML libraries |


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

<img src="Asteroid Dodger Screenshot.png" width="800">
