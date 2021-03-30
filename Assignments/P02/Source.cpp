///////////////////////////////////////////////////////////////////////////////
// 
// Author:           Caleb Sneath
// Email:            ansengor@yahoo.com
// Label:            P02
// Title:            Program 02 - Graphviz Class
// Course:           CMPS 2143
// Semester:         Spring 2021
//
// Description:
//      This program creates an output file containing code that can be 
//		directly copy and pasted into Graphviz in order to produce a usable 
//		graph. This program has support for node ids, node edges, subgraphs,
//		as well as specifying shapes for nodes and edges.
//		Additionally, this program is an exercise in the use of OOP.
//       
// Usage: 
//      - This program was originally created in Visual Studios. First copy
//		and paste this program into a new project in Visual Studios.
//		- Place the "graphconfig.txt" file into the same directory.
//		- Place the input data file in the same directory. Name it whatever,
//		then change the input file field in the graphconfig.txt file in a 
//		text editor. If desired, also change the name of the future output file.
//		- If using a subgraph within your graph, create a copy of
//		the config file and place it in the same directory under a different name.
//		- If using a subgraph, rename one of the "null" fields of the config file
//		to the new name of the subgraph's config file. The output section doesn't
//		matter and won't be used.
//		- (Optional) If shapes are being used, the config file has a field for 
//		whether to verify if entered shape fields are valid or not.
//		- Run from local Windows Debugger
//
// Input Data Format:
//		- Begin with the graph type: (digraph, graph, or subgraph)
//		- In the next line list the number of nodes.
//		- In each subsequent line afterward, begin with the node id, a comma
//		and any label associated with that id.
//		- After listing each node on each line, list the number of edges on
//		a new line.
//		-List each edge on its own line in this format: from node, a comma, to
//		node, a comma, and finally the label for that edge.
//		- The input file can end here, or node and edge shapes can be specified
//		- If continuing, list the number of graph nodes to specify on a line
//		- List the node id, then a comma, then the chosen shape
//		- After specifiying any node ids if applicable, list the number of edge
//		shapes on a new line.
//		- Edge format is a little different from nodes. First list the desired 
//		shape on a new line, then a comma, and finally the node label
//		- The input file is now finished
//		
//      
// Files:            
//      main.cpp			: driver program 
//      graphconfig.txt		: default configuration file
//		"User named subgraph config file": one or more configs for subgraphs 
//										 if applicable
//		output.txt (configurable) : The default output file in graphconfig.txt.
//      test.txt (configurable)	: The default input file in graphconfig.txt
//      
///////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;


/**
 * GraphNode
 *
 * Description:
 *		This class handles most of the code necessary for an individual node.
 *		It can store and even later print a properly formatted for Graphviz
 *		node id, label, shape, and font size.
 *
 * Usage:
 *  Public:
 *		GraphNode()									// The default constructor
 *													// Sets shape to "default"
 *													// and randomizes id/label
 *		GraphNode(string inID, string inLabel		// Nondefault constructor,
 *													// Sets custom id and label
 *		GraphNode(string inID, string inLabel, string inShape) // Nondefault
 *													// constructor, does as
 *													// above but also adds shape
 *     setShape (string inShape)					// setter for shape
 *	   setId (string inId)							// setter id, assumes that
 *													// if id and label were 
 *													// already the same, the user
 *													// was just using the default
 *													// and wants them the same. 
 *													// To have them different, 
 *													// use setLabel first.
 *	   setLabel (string inLabel)					// setter for label
 *	   string getID()								// Getter that returns id
 *	   setFontSize(int inSetSize)					// setter for fontSize
 *	   checkValidAttribute(string checkAtt)			// Checks if the passed value
 *													// matches a valid attribute 
 *													// type for a graphviz node
 *													// and if so returns its type,
 *													// otherwise returns "invalid"
 *													// Currently supports shapes
 *	  printNode(ostream& outStream)					// Prints this node to the 
 *													// specified stream in a format
 *													// acceptable for an existing
 *													// graphviz graph. Example 
 *													// streams that can be passed
 *													// to print to are cout or 
 *													// an output file.
 * 
 *  Private:
 *		string shape								// Stores the shape of the node
 *		string id									// Stores the id of a node. 
 *													// Unlike labels, ids have
 *													// very strict formats and must
 *													// be unique, although a single
 *													// node object doesn't care 
 *													// about other nodes.
 *		string label								// The label for a node. 
 *		int fontSize								// The fontsize for the node,
 *													// equivalent to Graphviz scale
 *	Possible Modifications:							// If this keeps getting worked
 *													// on, each object might have 
 *													// better encapsulation if
 *                                                  // the forbidden character
 *													// remover is moved to nodes and
 *													// classes, with a method for 
 *													// each type of field's unique
 *													// forbidden characters rather
 *													// than a broad remover in the 
 *													// graph class. More Graphviz
 *													// node attributes can be added
 *													// easily by adding new 
 *													// attributes, getter and setter
 *													// methods, and changing the 
 *													// labeled output section.
 *													// Adding support for verifying
 *													// this is a valid graphviz 
 *													// for that type can be done by
 *													// editing checkValidNodeAttribute
 *													// with a new "else then" statement
 *													// after the shape field similar to
 *													// the shape. 
 */
class GraphNode
{
	private:
		string shape, label, id;
		int fontSize = 0;

	public:
		GraphNode()
		{
			//Generates a random id that can be 
			//overwritten later
			int randName = rand() % 100000;
			id = randName;
			label = randName;
			shape = "default";
		}
		GraphNode(string inID, string inLabel)
		{
			id = inID;
			label = inLabel;
			shape = "default";
		}
		GraphNode(string inID, string inLabel, string inShape)
		{
			id = inID;
			label = inLabel;
			shape = inShape;
		}

		void setShape(string inShape)
		{
			shape = inShape;
		}

		void setId(string inId)
		{
			//Sets the label to same as ID if they are using the default
			//or probably want them same.
			if (id == label)
			{
				label = inId;
			}
			id = inId;
		}

		string getID()
		{
			return id;
		}

		void setLabel(string inLabel)
		{
			label = inLabel;
		}

		void setFontsize(int setSize)
		{
			fontSize = setSize;
		}

		string checkValidNodeAttribute(string checkAtt)
		{
			bool foundValid = false;
			string foundType;

			//checks if passed value is valid shape
			if (checkAtt == "box" || "polygon" ||
				"ellipse" || "oval" || "circle" ||
				"point" || "egg" || "triangle" ||
				"plaintext" || "plain" || "diamond"
				|| "trapezium" || "parallelogram"
				|| "house" || "pentagon" ||
				"hexagon" || "septagon" || "octagon"
				|| "doublecircle" || "doubleoctagon"
				|| "tripleoctagon" || "invtriangle"
				|| "invtrapezium" || "invhouse" ||
				"Mdiamond" || "Msquare" || "Mcircle"
				|| "rect" || "rectangle" || "square"
				|| "star" || "none" || "underline"
				|| "cyclinder" || "note" || "tab"
				|| "folder" || "box3d" || "component"
				|| "promoter" || "cds" || "terminator"
				|| "utr" || "primersite" ||
				"restrictionsite" || "fivepoverhang"
				|| "threepoverhang" || "noverhang"
				|| "assembly" || "signature" ||
				"insulator" || "ribosite" || "rnastab"
				|| "proteasesite" || "proteinstab" ||
				"rpromoter" || "rarrow" || "larrow" ||
				"lpromoter")
			{
				foundValid = true;
				foundType = "shape";
			}//Add "else then" below for new data types.
			else
			{
				foundType = "invalid";
			}
		
			return foundType;
		}

		void printNode(ostream& outStream)
		{
			//Ends up looking like:
			//id [label = "label", fontsize = size, shape =shape]
			outStream << id << " [";
			outStream << "label = " << "\"" << label << "\"";
			if (fontSize != 0)
			{
				outStream << ", fontsize =" << fontSize;
			}
			if (shape != "default")
			{
				outStream << ", shape =" << shape;
			}
			//Add future node attributes here in same format as 
			//the shape field above
			outStream << "]" <<  endl;
		}
};


/**
 * GraphEdge
 *
 * Description:
 *		This class handles most of the code necessary for an individual 
 *		connection between two nodes. It exists independently and does not
 *		verify these nodes already exist within code.
 *		It can store and even later print a properly formatted for Graphviz
 *		edge label, shape, from node, edge node, and font size.
 *
 * Usage:
 *  Public:
 *		EdgeNode()									// The default constructor
 *													// Sets shape to "default"
 *													// , and connections to 
 *													// "undefined", with label
 *													// an empty space (which
 *													// won't print later)
 *		EdgeNode(string inNode, string outNode)		// Nondefault constructor
 *													// sets fromNode and toNode
 *													// to the passed values.
 *													// Sets label to " " which
 *													// won't print later.
 *		EdgeNode(string inNode,string outNode, string inLabel)		// Same as 
 *													// above but also sets label
 *		setNodes(string inNode, string outNode)		// Sets to fromNode and toNode
 *													// to the passed values.
 *		string getEdgeID()							// returns the edge label
 *		setEdgeLabel(string inLabel)				// Setter for edgeLabel
 *     setEdgeShape (string inShape)				// setter for shape
 *	   string getID()								// Getter that returns id
 *	   setFontSize(int inSetSize)					// setter for fontSize
 *	   checkValidEdgeAttribute(string checkAtt)		// Checks if the passed value
 *													// matches a valid attribute
 *													// type for a graphviz edge
 *													// and if so returns its type,
 *													// otherwise returns "invalid"
 *													// Currently supports shapes
 *	  printEdge(ostream& outStream)					// Prints this edge to the
 *													// specified stream in a format
 *													// acceptable for an existing
 *													// graphviz graph. Example
 *													// streams that can be passed
 *													// to print to are cout or
 *													// an output file.
 *
 *  Private:
 *		string edgeShape							// Stores the shape of the edge
 *		string edgeLbel								// Stores the label of the edge.
 *													// Works like the id in nodes, 
 *													// but has more lenient syntax
 *		int fontSize								// The fontsize for the edge,
 *													// equivalent to Graphviz scale
 *		string toNode								// The id of the node the edge
 *													// goes and usually points to
 *		string fromNode								// The id of the node the edge
 *													// comes from
 *	Possible Modifications:							// More Graphviz
 *													// edge attributes can be added
 *													// easily by adding new
 *													// attributes, getter and setter
 *													// methods, and changing the
 *													// labeled output section.
 *													// Adding support for verifying
 *													// this is a valid graphviz
 *													// for that type can be done by
 *													// editing checkValidEdgeAttribute
 *													// with a new "else then" statement
 *													// after the shape field similar to
 *													// the shape. Now that it's done,
 *													// noticing some overlap between all
 *													// three classes, like labels, shapes,
 *													// fontsizes, etc. Might be worth
 *													// reworking to have a core graphwiz
 *													// class and have nodes, edges, and
 *													// graphs encapsulate or inherit that.
 */
class GraphEdge
{
	private:

		string toNode;
		string edgeLabel;
		string edgeShape;
		string fromNode;
		int fontSize = 0;

	public:

		GraphEdge()
		{
			fromNode = "undefined";
			toNode = "undefined";
			edgeLabel = " ";
			edgeShape = "default";
		}
		GraphEdge(string inNode, string outNode)
		{
			fromNode = inNode;
			toNode = outNode;
			edgeLabel = " ";
			edgeShape = "default";
		}
		GraphEdge(string inNode, string outNode, string inLabel)
		{
			fromNode = inNode;
			toNode = outNode;
			edgeLabel = inLabel;
			edgeShape = "default";
		}

		void setNodes(string inNode, string outNode)
		{
			fromNode = inNode;
			toNode = outNode;
		}

		string getEdgeID()
		{
			return edgeLabel;
		}

		void setEdgeLabel(string inLabel)
		{
			edgeLabel = inLabel;
		}

		void setEdgeShape(string inShape)
		{
			edgeShape = inShape;
		}

		void setFontSize(int setSize)
		{
			fontSize = setSize;
		}

		string checkValidEdgeAttribute(string checkAtt)
		{
			bool foundValid = false;
			string foundType;

			//checks if passed value is valid shape
			if (checkAtt == "box" || "crow" || "diamond"
				|| "dot" || "icurve" || "inv" || "normal"
				|| "tee" || "vee" || "lbox" || "lcrow" ||
				"lcurve" || "ldiamond" ||
				"licurve" || "linv" || "lnormal" || "ltee"
				|| "lvee" || "rbox" || "rcrow" || "rcurve"
				|| "rdiamond" || "ricurve" || 
				"rinv" || "rnormal" || "rtee" || "rvee"
				|| "obox" || "odiamond" || "dot"
				|| "oinv" || "onormal" || "otee" || "none")
			{
				foundValid = true;
				foundType = "shape";
			}//Add new else if check below for new attributes
			else
			{
				foundType = "invalid";
			}

			return foundType;
		}
		
		void printEdge(ostream& outStream)
		{
			//Ends up looking like:
			//fromnode -> tonode [label ="label", shape =shape]
			outStream << fromNode << "->" << toNode;

			if (edgeLabel != " ")
			{
				outStream << " [label =\"" << edgeLabel << "\"";
				if (fontSize != 0)
				{
					outStream << ", fontsize =" << fontSize;
				}
				if (edgeShape != "default")
				{
					outStream << ", shape =" << edgeShape;
				}
				//Add new attribute prints here like above shape
				outStream << "]" << endl;
			}
		}
};


/**
 * GraphNode
 *
 * Description:
 *		This class handles most of the code necessary for an individual node.
 *		It can store and even later print a properly formatted for Graphviz
 *		node id, label, shape, and font size.
 *
 * Usage:
 *  Public:
 * GraphVizGraph()									// The default constructor
 *													// Uses the default
 *													// graphconfig.txt file as
 *													// the graph's config.
 * GraphVizGraph(string conFileName)				// Nondefault constructor.
 *													// The same as the default,
 *													// except it uses the passed
 *													// string as the config name
 * GraphVizGraph(ifstream& conFile)					// Nodefault constructor.
 *													// Works with the stream
 *													// for an already opened 
 *													// config file.
 * void printGraph()								// Prints the graph 
 *													// including general graph
 *													// formatting, subgraphs,
 *													// nodes, and edges to the
 *													// file specified by the 
 *													// config file.
 * void printGraph(ostream& outStream)				// Overload for the above
 *													// that prints to the
 *													// passed stream, such
 *													// as an output file or cout
 *
 *	
 *  Private:
 *	string GraphID									// The unique label for 
 *													// this graph.
 *													// '#' Sets it to not print.
 *  vector<GraphNode*> nodeList						// The list of all nodes 
 *													// within this graph, in
 *													// pointer form.
 *  vector<GraphNode*> edgeList						// The list of all edges 
 *													// within this graph, in
 *													// pointer form.
 *  vector<GraphNode*> graphList					// The list of all subgraphs
 *													// within this graph, in
 *													// pointer form. A subgraph
 *													// is the same class. Pointing
 *													// to a nonspubgraph
 *													// can lead to infinite 
 *													// recursion in the worst case
 *													// and a broken output at best
 * string graphType									// The type of graph, should
 *													// be graph, digraph, or
 *													// subgraph.
 * string outFileName								// A string that contains 
 *													// where the program will try
 *													// to save the output file to.
 *													// Default to "output.txt"
 * string validCheck								// Determines if the graph
 *													// will try to catch invalid
 *													// attributes and warn the 
 *													// user. Disabled by default.
 *													// Potentially helpful, but
 *													// might impact performance.
 * scanConfig(ifstream& conFile, ifstream& inFile)	// Processes the information
 *													// on the passed config
 *													// file stream and loads
 *													// the passed inFile stream
 *													// with the input file.
 *													// Also loads up the 
 *													// subgraphs.
 * string extractConfigString(ifstream& conFile)	// The config file has a 
 *													// specific format. This
 *													// function returns the 
 *													// important information from
 *													// the passed config stream
 *													// and ignores the rest.
 * void scanInput(ifstream& inFile)					// Processes the input
 *													// file passed to it for
 *													// information on nodes
 *													// and edges.
 * string extractString(ifstream& inFile)			// Grabs an item from the
 *													// input file that is not
 *													// separated by the end
 *													// of the line or a comma.
 *													// Then it cleans it up
 *													// of characters that tend
 *													// to cause problems for 
 *													// graphwiz.
 * string extractString(ifstream& inFile, char dummyOverride) //An override
 *													// of the above that
 *													// doesn't clean up things.
 *													// The passed char does
 *													// nothing.
 * forbiddenCharacterRemover(string& uncleanedString) //Cleans the passed 
 *													// string of characters
 *													// that cause issues
 *													// often for graphwiz
 * ~GraphVizGraph()									// Destructor, clears
 *													// dynamic memory of
 *													// objects stored in 
 *													// the vector of pointers
 */
class GraphVizGraph
{
	private:
		string graphID;
		vector<GraphNode*> nodeList;//List of all scanned nodes
		vector<GraphEdge*> edgeList;//List of all scanned edges
		//A graph can apparently be a graph of graphs so
		//this is a list of all graphs, including itself
		//Each graph will need a separate config file
		vector<GraphVizGraph*> graphList;

		string graphType;//subgraph, graph or digraph
		string outFileName = "output.txt";
		string validCheck = "no";

		void scanConfig(ifstream& conFile, ifstream& inFile)
		{
			string inFileName = "#";//Stores input file name

			inFileName = extractConfigString(conFile);


			//Opens input name. Also give users a chance to manually enter filenames with
			//multiple consecutive spaces.
			inFile.open(inFileName);
			while (inFile.fail())//Fix missing file or just warn user
			{
				cout << "No file found matching entered name. Please ensure the " << endl;
				cout << "input file is in the right directory and typed correctly" << endl;
				cout << "There is a known limitation with support for filenames " << endl;
				cout << "with multiple consecutive spaces in the config file." << endl;
				cout << "If your error is caused by that, enter the name here." << endl;

				cin >> inFileName;

				inFile.open(inFileName);
			}

			outFileName = extractConfigString(conFile);
			graphID = extractConfigString(conFile);
			validCheck = extractConfigString(conFile);

			//This block loads the graph with its subgraphs
			while (!conFile.eof())
			{
				string subFileName = extractConfigString(conFile);

				//Checks if this has the string which indicates no subgraph file,
				//specifically, "null". Doesn't run any subgraphs if so.
				if (subFileName != "null")
				{
					GraphVizGraph *subGraph = new GraphVizGraph(subFileName);
					graphList.push_back(subGraph);
				}
			}

		}

		string extractConfigString(ifstream& conFile)
		{
			string endCheck = "#";
			string tempStringVar;
			string stringName = "#";

			//Grab input file from config. The loop is necessary to support file names
			//that have spaces in them. 
			while (endCheck != "/")
			{
				conFile >> tempStringVar;
				if (tempStringVar.length() > 0)
				{
					endCheck = tempStringVar.at(0);//Grabs first character of string to check
				}
				else
				{
					stringName = "null";
					endCheck = "/";
				}

				if (endCheck != "/")
				{
					//Checks if it's the first time through this loop first, no filename
					//should use #
					if (stringName == "#")
					{
						stringName = tempStringVar;
					}
					else
					{
						//Add a space (since "confile >>" skips spaces. I guess this also
						//means filenames with multiple consecutive spaces aren't supported
						stringName.append(" ");
						stringName.append(tempStringVar);
					}
				}
				

			}
			conFile.ignore(1000, '\n');//Ignore the rest of the line which is documentation
			
			return stringName;
		}

		void scanInput(ifstream& inFile)
		{
			int nodeCount, edgeCount, shapeCount;

			inFile >> graphType;
			inFile >> nodeCount;

			//grab each node from input
			for (int loopCount = 0; loopCount < nodeCount; loopCount++)
			{

				string currentID = extractString(inFile);
				string currentLabel = extractString(inFile, 'n');
				GraphNode * newNode = new GraphNode(currentID, currentLabel);
				nodeList.push_back(newNode);

			}

			inFile >> edgeCount;
			//grab each edge from input

			for (int loopCount = 0; loopCount < edgeCount; loopCount++)
			{
				string currentFrom = extractString(inFile);
				string currentTo = extractString(inFile);
				string currentLabel = extractString(inFile, 'n');
				GraphEdge *newEdge = new GraphEdge(currentFrom, currentTo,
					currentLabel);
				edgeList.push_back(newEdge);

			}

			//This block below grabs node shapes
			int nodeShapeCount = 0;
			if (!inFile.eof())
			{
				inFile >> nodeShapeCount;
			}
			for (int outLoop = 0; outLoop < nodeShapeCount; outLoop++)
			{
				string currentID = extractString(inFile);
				
				string currentShape = extractString(inFile);
				if (validCheck == "yes")//Only verify if config says 
				{
					if(nodeList[0]->checkValidNodeAttribute
					(currentShape)!="shape")
					{
						cout << currentShape << endl;//Shows bad shape.
						cout << "Potential error in input file." << endl;
						cout << "Entered shape is not a valid " << endl;
						cout << "Graphviz shape. Input the shape " << endl;
						cout << "here or type 'y' to ignore" << endl;
						cout << "this warning." << endl;

						string tempMenu;
						cin >> tempMenu;

						if (tempMenu != "y")//If y, allows user to bypass
						{					//warning
							currentShape = tempMenu;//Sets to new
						}
					}
				}
				
				//Sets each shape to corresponding node id. Runs for each
				//shape in input file.
				for (int inLoop = 0; inLoop < nodeList.size(); inLoop++)
				{
					if (nodeList[inLoop]->getID() == currentID)
					{
						nodeList[inLoop]->setShape(currentShape);
						inLoop = nodeList.size();//Exit loop, found
					}
				}
			}

			//This block below grabs edge shapes
			//Merging this block and the block above into a single method
			//that passes a vector pointer and string if anymore code
			//like this is added is a good idea
			int edgeShapeCount = 0;
			if (!inFile.eof())
			{
				inFile >> edgeShapeCount;
			}
			for (int outLoop = 0; outLoop < edgeShapeCount; outLoop++)
			{
				string currentShape = extractString(inFile);
				string currentID = extractString(inFile, 'n');


				if (validCheck == "yes")//Runs if config set to verify
				{
					if (edgeList[0]->checkValidEdgeAttribute
					(currentShape) != "shape")//Input file didn't enter shape
					{
						cout << currentShape << endl;
						cout << "Potential error in input file." << endl;
						cout << "Entered shape is not a valid " << endl;
						cout << "Graphviz shape. Input the shape " << endl;
						cout << "here or type 'y' to ignore" << endl;
						cout << "this warning." << endl;

						string tempMenu;
						cin >> tempMenu;

						if (tempMenu != "y")
						{
							currentShape = tempMenu;
						}
					}
				}

				//Sets shapes in input file to corresponding edges, runs
				//Until done with each shape
				for (int inLoop = 0; inLoop < edgeList.size(); inLoop++)
				{
					if (edgeList[inLoop]->getEdgeID() == currentID)
					{
						edgeList[inLoop]->setEdgeShape(currentShape);
						inLoop = edgeList.size();//Exit loop, found
					}
				}
			}
		}

		string extractString(ifstream& inFile)
		{
			char endCheck = '\n';
			string stringName = " ";
			string tempStringVar;

			//Loops until it finds a ',' or the file ends.
			while (endCheck != ',' && !inFile.eof())
			{
				inFile >> tempStringVar;//Stores string to be manipulated
										//before the final string is ready

				//Grabs the last character of tempStringVar
				endCheck = tempStringVar.at(tempStringVar.size()-1);


				//Checks if it's the first time through this loop first
				if (stringName == " ")
				{
					stringName = tempStringVar;
				}
				else
				{
					//Add a space (since "infile >>" skips spaces. I guess this also
					//means words with consecutive spaces aren't fully supported
					stringName.append(" ");
					stringName.append(tempStringVar);
				}


				//End of line without comma loop end check
				if (inFile.peek() == '\n')
				{
					endCheck = ',';
				}

			}

			forbiddenCharacterRemover(stringName);//Clean up any bad characters

			return stringName;
		}
		//This is an override of the above for extracting text without cleaning 
		//characters
		string extractString(ifstream& inFile, char dummyOverride)
		{
			char endCheck = '\n';
			string stringName = " ";
			string tempStringVar;

			//Runs while no comma found and the file didn't end
			while (endCheck != ',' && !inFile.eof())
			{
				inFile >> tempStringVar;

				//Grabs the last character of tempStringVar
				endCheck = tempStringVar.at(tempStringVar.size() - 1);


				//Checks if it's the first time through this loop first
				if (stringName == " ")
				{
					stringName = tempStringVar;
				}
				else
				{
					//Add a space (since "infile >>" skips spaces. I guess this also
					//means words with consecutive spaces aren't fully supported
					stringName.append(" ");
					stringName.append(tempStringVar);
				}


				//End of line without comma loop end check
				if (inFile.peek() == '\n')
				{
					endCheck = ',';
				}

			}

			return stringName;
		}

		void forbiddenCharacterRemover(string& uncleanedString)
		{
			int stringLength = uncleanedString.length();
			string charChecker;

			//Runs for each character in string
			for (int loopCounter = 0; stringLength > loopCounter; loopCounter++)
			{
				charChecker = uncleanedString.at(loopCounter);

				//Checks for any characters not usable in graphviz
				if (charChecker == "-"|| charChecker == "," || charChecker ==" ")
				{
					//Remove unusable character
					uncleanedString.erase(uncleanedString.begin()+loopCounter);

					//Acount for there being one less character in the string now
					loopCounter--;
					stringLength--;
				}
			}

		}

	public:
		GraphVizGraph()
		{
			vector<GraphNode*> nodeList;
			vector<GraphEdge*> edgeList;
			vector<GraphVizGraph*> graphList;

			//Have to handle config file this constructor since it isn't done already
			ifstream conFile;
			ifstream inFile;

			conFile.open("graphconfig.txt");//Default config name
			while (conFile.fail())//Fix missing default config file or just warn user
			{
				cout << "No file found matching entered name. Please ensure the " << endl;
				cout << "input file is in the right directory and typed correctly" << endl;
				cout << "To use a custom file, input the config file name below." << endl;

				string customConfigName;
				cin >> customConfigName;

				conFile.open(customConfigName);
			}

			scanConfig(conFile, inFile);
			conFile.close();

			scanInput(inFile);
			inFile.close();

			printGraph();
		}
		GraphVizGraph(string conFileName)
		{
			vector<GraphNode*> nodeList;
			vector<GraphEdge*> edgeList;
			vector<GraphVizGraph*> graphList;

			//Have to handle config file this constructor since it isn't done already
			ifstream conFile;
			ifstream inFile;

			conFile.open(conFileName);//Default config name
			while (conFile.fail())//Fix missing default config file or just warn user
			{
				cout << "No file found matching entered name. Please ensure the " << endl;
				cout << "input file is in the right directory and typed correctly" << endl;
				cout << "To use a custom file, input the config file name below." << endl;

				string customConfigName;
				cin >> customConfigName;

				conFile.open(customConfigName);
			}

			scanConfig(conFile, inFile);
			conFile.close();//Done with it, return system resources

			scanInput(inFile);
			inFile.close();
		}
		GraphVizGraph(ifstream& conFile)
		{
			ifstream inFile;
			scanConfig(conFile, inFile);
			conFile.close();

			scanInput(inFile);
			inFile.close();
		}

		void printGraph()
		{
			//Change output.txt to rename output file
			//Opens the stream to print to
			ofstream outStream;
			outStream.open(outFileName);


			//Looks like 
			//graphtype graphlabel{
			//subgraph sub1{
			//sub1data
			//}
			//node1 
			//node2
			//edge1
			//}
			//See node and graph class for their formatting
			outStream << graphType;
			if (graphID != "#")
			{
				outStream << " " << graphID;
			}
			outStream << " {" << endl << endl;

			if (!graphList.empty())//Prints subgraphs if there are any
			{	//Loops through each edge
				for (int loopCounter = 0; loopCounter < graphList.size(); loopCounter++)
				{
					graphList[loopCounter]->printGraph(outStream);
				}
			}
			outStream << endl;

			if (!nodeList.empty())//Prints nodes if there are any
			{	//Loops through each edge
				for (int loopCounter = 0; loopCounter < nodeList.size(); loopCounter++)
				{
					nodeList[loopCounter]->printNode(outStream);
				}
			}

			outStream << endl;

			if (!edgeList.empty())//Prints edges if there are any
			{	//Loops through each edge
				for (int loopCounter = 0; loopCounter < edgeList.size(); loopCounter++)
				{
					edgeList[loopCounter]->printEdge(outStream);
				}
			}

			outStream << endl << " }" << endl;

			//Close output file and return system resources
			outStream.close();
		}

		void printGraph(ostream& outStream)
		{
			//Looks like 
			//graphtype graphlabel{
			//subgraph sub1{
			//sub1data
			//}
			//node1 
			//node2
			//edge1
			//}
			//See node and graph class for their formatting
			outStream << graphType;
			if (graphID != "#")
			{
				outStream << " " << graphID;
			}
			outStream << " {" << endl << endl;

			if (!graphList.empty())//Print subgraphs if there are any
			{	//Loops through each edge
				for (int loopCounter = 0; loopCounter < graphList.size(); loopCounter++)
				{
					graphList[loopCounter]->printGraph(outStream);
				}
			}
			outStream << endl;

			if (!nodeList.empty())//Print nodes if there are any
			{	//Loops through each edge
				for (int loopCounter = 0; loopCounter < nodeList.size(); loopCounter++)
				{
					nodeList[loopCounter]->printNode(outStream);
				}
			}

			outStream << endl;

			if (!edgeList.empty())//Print edges if there are any
			{	//Loops through each edge
				for (int loopCounter = 0; loopCounter < edgeList.size(); loopCounter++)
				{
					edgeList[loopCounter]->printEdge(outStream);
				}
			}

			outStream << endl << " }" << endl;
		}

		~GraphVizGraph()
		{

			//Clear stored graph dynamic memory
			while (!graphList.empty())
			{
				delete graphList[graphList.size() - 1];
				graphList.pop_back();
			}

			//Clear stored node dynamic memory
			while (!nodeList.empty())
			{
				delete nodeList[nodeList.size() - 1];
				nodeList.pop_back();
			}

			//Clear stored edge dynamic memory
			while (!edgeList.empty())
			{
				delete edgeList[edgeList.size() - 1];
				edgeList.pop_back();
			}
		}
};


/**
 * Main
 *
 * Description:
 *		Demonstrates the program works correctly by making a graph object
 *		with the default constructor, then printing it to the output listed
 *		in the config file as well as cout. Then returns 0 on end.
 *
 */
int main()
{
	GraphVizGraph graph1 = GraphVizGraph();

	//Prints it to the output file.
	graph1.printGraph();

	//Prints it to the console too
	graph1.printGraph(cout);

	return 0;
}