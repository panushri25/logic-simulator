# logic-simulator

Logic Simulator

Idea:

The given circuit is interpreted as graph and breadth first search algorithm is implemented so as to layerize the graph.And further simulation is carried out layer wise.

Inputs: 

The input to the simulator should be given in text document and should follow the layout as described in the test cases.

Gates Allowed :

AND,OR,NAND,NOR,NOT,XOR ( Program can be extended to include other gates too )

The input format is case sensitive and hence should be followed strictly.

outputs : 

The simulator gives as output the value of the node in interest and  values of the subsequent nodes used in its evaluation.

For verification purpose the contents of the objects read from text document and layers as computed by Breadth first search algorithm are also presented.

Algorithm used :

Breadth First search algorithm
Logic simulation

Limitations :

1) Only one output node can be evaluated at a time.

2) Only combinational ciruits without feedback can be evaluated.

3) Ensure that none of the nodes are tagged 0 node i.e. the nodes are numbered starting from 1.


