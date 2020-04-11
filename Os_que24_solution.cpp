 #include<iostream> 
using namespace std; 

 
const int Process = 5; // Number of processes
const int Resource = 4; // Number of resources

void calNeed(int need[Process][Resource], int max[Process][Resource], 
				int allocat[Process][Resource]) 
{ 
	
	for (int i = 0 ; i < Process ; i++) 
		for (int j = 0 ; j < Resource ; j++) 
 
			need[i][j] = max[i][j] - allocat[i][j]; 
} 
 
bool Safe(int processes[], int avail[], int max[][Resource], 
			int allocat[][Resource]) 
{ 
	int need[Process][Resource]; 

	calNeed(need, max, allocat); 
	bool finish[Process] = {0}; 
	int safeSeq[Process]; 
	int work[Resource]; 
	for (int i = 0; i < Resource ; i++) 
		work[i] = avail[i]; 

	int count = 0; 
	while (count < Process) 
	{ 
		bool found = false; 
		for (int p = 0; p < Process; p++) 
		{ 
			if (finish[p] == 0) 
			{ 
				int j; 
				for (j = 0; j < Resource; j++) 
					if (need[p][j] > work[j]) 
						break; 
				if (j == Resource) 
				{ 
					for (int k = 0 ; k < Resource ; k++) 
						work[k] += allocat[p][k]; 
					safeSeq[count++] = p; 
					finish[p] = 1; 

					found = true; 
				} 
			} 
		} 
		if (found == false) 
		{ 
			cout << "System is not in safe state"; 
			return false; 
		} 
	} 

	cout << "System is in safe state."; 
	for (int i = 0; i < Process ; i++) 
		cout << safeSeq[i] << " "; 

	return true; 
} 

int main() 
{ 
	int processes[] = {0, 1, 2, 3, 4}; 
	int avail[] = {1,5,2,0}; 
	int max[][Resource] = {{0,0,1,2}, 
					{1,7,5,0}, 
					{2,3,5,6}, 
					{0,6,5,2}, 
					{0,6,5,6}}; 
	int allocat[][Resource] = {{0,0,1,2}, 
					{1,0,0,0}, 
					{1,3,5,4}, 
					{0,6,3,2}, 
					{0,0,1,4}};

	Safe(processes, avail, max, allocat); 

	return 0; 
} 

