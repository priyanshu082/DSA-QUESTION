#include<iostream>
#include<stack>

using namespace std;


vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	stack<int> stack;
	int i=n-1;
	int j=m-1;
	int carry=0;
	while(i>=0 && j>=0){
		int sum=a[i]+b[j]+carry;
		if(sum>=10){
			sum=sum%10;
			stack.push(sum);
			carry=1;
		} else{
			sum=sum%10;
			stack.push(sum);
			carry=0;
		}
		i--;
		j--;
	}


	while(i>=0 && n>m){
		int sum=a[i]+carry;
		if(sum>=10){
			sum=sum%10;
			stack.push(sum);
			carry=1;
		} else{
			sum=sum%10;
			stack.push(sum);
			carry=0;
		}
		i--;
	} while(m>n && j>=0){
		int sum=b[j]+carry;
		if(sum>=10){
			sum=sum%10;
			stack.push(sum);
			carry=1;
		} else{
			sum=sum%10;
			stack.push(sum);
			carry=0;
		}
		j--;
	}

	if(carry==1) stack.push(carry);


	vector<int> vec;

while(!stack.empty()){
	vec.push_back(stack.top());
	stack.pop();
}
	return vec;
}

int main(){

    return 0;
}