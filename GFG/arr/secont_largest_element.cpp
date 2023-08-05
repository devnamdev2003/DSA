class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int max=arr[0];
	    for(int i=0;i<n;i++){
	        if(max<arr[i]){
	            max=arr[i];
	        }
	    }
	    int smax=-1;
	    for(int i=0;i<n;i++){
	        if((smax<arr[i])&&(arr[i]!=max)){
	            smax=arr[i];
	        }
	    }
	    return smax;
	}
};