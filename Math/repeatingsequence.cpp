// C++ program to find repeating sequence in a fraction 
#include <bits/stdc++.h> 
using namespace std; 

// This function returns repeating sequence of 
// a fraction. If repeating sequence doesn't 
// exits, then returns empty string 
string fraction(int numr, int denr) 
{ 
	string res; // Initialize result 

	// Create a map to store already seen remainders 
	// remainder is used as key and its position in 
	// result is stored as value. Note that we need 
	// position for cases like 1/6. In this case, 
	// the recurring sequence doesn't start from first 
	// remainder. 
	map <int, int> mp; 
	mp.clear(); 

    res+= to_string(numr/denr);
	// Find first remainder 
	int rem = numr%denr; 
    if(rem==0){
        return res;
    }

    res+=".";

    string second_part="";

    bool has_repeat=0;

    int second_idx=-1;


	// Keep finding remainder until either remainder 
	// becomes 0 or repeats 
	while (rem!=0) 
	{ 
		if((mp.find(rem) != mp.end())){
            has_repeat=1;
            second_idx=second_part.size();
            break;
        }
             
        // Store this remainder 
		mp[rem] = second_part.length(); 

		// Multiply remainder with 10 
		rem = rem*10; 

		// Append rem / denr to result 
		int res_part = rem / denr; 
		second_part += to_string(res_part); 

		// Update remainder 
		rem = rem % denr; 
	} 

	//res.substr(mp[rem]); 

    if(has_repeat){
        string repeated_seq= second_part.substr(mp[rem],second_idx);
        second_part.erase(mp[rem]);
        string newsecond= second_part+"("+repeated_seq+")";
        res+=newsecond;
    }

    else{
        res+=second_part;
    }

    return res;


} 

// Driver code 
int main() 
{ 
	int numr = 5, denr = 3; 
    //cout<<numr%denr<<endl;
	string res = fraction(numr, denr); 
	if (res == "") 
		cout << "No recurring sequence"; 
	else
		cout << "No " << res; 
	return 0; 
} 
