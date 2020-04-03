#include <iostream>
#include <bits/stdc++.h>
#include <list>
using namespace std;

//array size
const int M = 4;
const int N = 6;

class vec2d{
	public:
		int x, y;
		
		vec2d(int x, int y){
			this -> x = x;
			this -> y = y;
		}
};

//passing the memory address of stack result in modifying the stack
void printStack(stack<int> n){
	while(!n.empty()){
		cout << n.top() << endl;
		n.pop();
	}
	
	cout << "\n";
}

/*NOTE: not used in this program*/
stack<int> getNeighbors(int maze[M][N], int startX, int startY){
	stack<int> s;
	
	//getting all neighbors
	for(int x=-1;x<=1;x++){
		for(int y=-1;y<=1;y++){
			s.push(maze[startX+x][startY+y]);
		}
	}
	
	return s;
}

bool isValid(int x, int y){
	if(x >= 0 && x < 4 && y >= 0 && y < 6){
		return true;
	}
	else{
		return false;
	}
}

void flood_fill(int maze[M][N], int target, int replace, int x, int y){
	
	if(isValid(x, y) && maze[x][y] == target){
		maze[x][y] = replace;
		flood_fill(maze, target, replace, x+1, y);
		flood_fill(maze, target, replace, x-1, y);
		flood_fill(maze, target, replace, x, y+1);
		flood_fill(maze, target, replace, x, y-1);
	}
	
}

int main(void){
	
	int maze[M][N] = {{1,1,1,1,1,1}, {1,1,2,2,1,1}, {1,1,2,2,1,1}, {2,2,2,2,2,2}};
	
	//starting node
	vec2d start(0, 0);
	int startX = start.x;
	int startY = start.y;
	
	/*params: array of points, target col, replace col, 
	starting node(startX, startY)*/
	flood_fill(maze, 1, 0, startX, startY);
	flood_fill(maze, 2, 3, 2, 3);
		
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
