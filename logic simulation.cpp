#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int N, i, j,flag;
int output;
string input; // to read string from file
string text;

class node // class to strore inputs to the node,gate and value of the node
{
	public:
	node();
	void initialize(vector<int> v);
	vector<int> inputs;
	int gate;
	bool value;
};

node::node(){
	gate=0;
}

void node::initialize (vector<int> v) {
	for (int i = 1; i < v.size(); ++i)
	{
		inputs.push_back(v[i]);
	}
};

vector <node> signal; // to store the node values

void simulate(int sig){ // function to simulate the value of nodes
 
	const int AND = 1;
 const int OR  = 2;
 const int NAND = 3;
 const int NOR = 4;
 const int XOR = 5;
 const int NOT = 6;
 
	switch ( signal[sig].gate ){
	  
   case (AND) :
   {
				signal[sig].value = 1;
    for(int p=0;p<signal[sig].inputs.size();p++)
				{
            signal[sig].value &= signal[signal[sig].inputs[p]].value;
    }
    break;
   }
   case OR :
   {
   signal[sig].value = 0;
   for(int p=0;p<signal[sig].inputs.size();p++)
			{
   								signal[sig].value |= signal[signal[sig].inputs[p]].value;
			}
   break;
   }
   case (NAND) :
   {
				signal[sig].value = 1;
    for(int p=0;p<signal[sig].inputs.size();p++)
				{
            signal[sig].value &= signal[signal[sig].inputs[p]].value;
    }
    signal[sig].value = !signal[sig].value;
    break;
   }
   case NOR :
   {
   signal[sig].value = 0;
   for(int p=0;p<signal[sig].inputs.size();p++)
			{
   								signal[sig].value |= signal[signal[sig].inputs[p]].value;
			}
   signal[sig].value = !signal[sig].value;
   break;
   }
   case (XOR) :
   {
				signal[sig].value = 0;
    for(int p=0;p<signal[sig].inputs.size();p++)
				{
            signal[sig].value ^= signal[signal[sig].inputs[p]].value;
    }
    break;
   }
   case NOT :
   {
   for(int p=0;p<signal[sig].inputs.size();p++)
			{
   								signal[sig].value = !signal[signal[sig].inputs[p]].value;
			}
   break;
   }
 } 
 cout<<"bool value of node "<<sig<<" is "<<signal[sig].value<<endl;
}

int main(int argc, char** argv)
{
	fstream file("input.txt", ios::in);
 vector <int> values;
 while(getline(file, input, '\n')) {  
 
	   // converting input from file to char array
 			char * temp = new char [input.length()+1];
	   strcpy (temp, input.c_str());

				// splitting char array at spaces
	   char * current = strtok(temp, "#(,)= ");
	   flag = 0;
	   while(current!=NULL){
				   
							int k = atoi(current);
 						if(k==0 && flag==0)
							{
															flag = 1;
															text = current;
							}
							else
							{
         						values.push_back(k);
							}
							current = strtok(NULL,"#(,)= ");
    }
    
    if(flag == 1){
												
												if( text == "nodes")
    								{
																 N = values[0];
																	signal.resize(values[0]+1);
												}
												else if( text == "OUTPUT" )
												{
																	output = values[0];
												}
												else if(text == "INPUT")
												{
																	signal[values[0]].value = values[1];
												}
												else if(text == "AND")
												{
																	signal[values[0]].initialize(values); 
					 											signal[values[0]].gate = 1;						 
												}
												else if(text == "OR")
												{
					 											signal[values[0]].initialize(values); 
					 											signal[values[0]].gate = 2;
												}
														else if(text == "NAND")
												{
																	signal[values[0]].initialize(values); 
					 											signal[values[0]].gate = 3;						 
												}
												else if(text == "NOR")
												{
					 											signal[values[0]].initialize(values); 
					 											signal[values[0]].gate = 4;
												}
												else if(text == "XOR")
												{
					 											signal[values[0]].initialize(values); 
					 											signal[values[0]].gate = 5;
												}
													else if(text == "NOT")
												{
					 											signal[values[0]].initialize(values); 
					 											signal[values[0]].gate = 6;
												}
				}
    values.erase(values.begin(),values.end());              
 }

 
 for ( i=1;i<N+1;++i){                // for verification
 				cout<<"node "<<i<<endl;
     cout<<"gate "<<signal[i].gate<<endl;
 				if(signal[i].gate != 0){
					  cout<<"inputs ";
					  for (j=0;j<signal[i].inputs.size();j++)
       {
       				cout<<signal[i].inputs[j]<<" ";
       }
       cout<<endl;
     }
     else 
     {
					  cout<<"input value "<<signal[i].value<<endl;
     }
     cout<<endl;
}

   cout<<endl;
                              
// breadth first search algortithm
			int k;
   vector < vector<int> > layer;
   int count;
    
   k=0;
   count=0;
   layer.resize(1);
   layer[0].push_back(output);
    do
    {   
								count = 0;
						  k = k+1;
						  flag = 0;
    				for( j=0 ; j<layer[k-1].size() ; j++)
        {
        if(signal[layer[k-1][j]].gate != 0 )
        {   
												if(flag==0)
												{
        				layer.resize(k+1);
        				flag=1;
												}
            for( i=0; i<signal[layer[k-1][j]].inputs.size(); i++)
       					{   
            				layer[k].push_back(signal[layer[k-1][j]].inputs[i]);
            }
            cout<<endl;
        }
        else
        {
    				count = count + 1;
        }
        }
    } while(count != layer[k-1].size());
    
    cout<<"layers"<<endl;
    cout<<endl;
    
    for(j=0;j<layer.size();j++)
    {
				  for(i=0;i<layer[j].size();i++)
      {
							cout<<layer[j][i]<<" ";
      }
    cout<<endl;
    } 
    
// logic simulation    
 		cout<<endl;
 		
   for(j=layer.size()-2;j>=0;j--)
   {
   	 for(i=0;i<layer[j].size();i++)
   		{
					   if(signal[layer[j][i]].gate != 0)
        {
        simulate(layer[j][i]);
        }
     }
   }
   
                                                                                                                                                                  
 cin.get();
	return 0;
}
