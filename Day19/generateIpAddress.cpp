// Hi, here's your problem today. This problem was recently asked by Microsoft:

// An IP Address is in the format of A.B.C.D, where A, B, C, D are all integers between 0 to 255.

// Given a string of numbers, return the possible IP addresses you can make with that string by splitting into 4 parts of A, B, C, D.

// Keep in mind that integers can't start with a 0! (Except for 0)

// Example:
// Input: 1592551013
// Output: ['159.255.101.3', '159.255.10.13']

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<string> v){
    cout<<"[";
    for(string s : v){
        cout << s << ", ";
    }
    cout<<"]";
} 

// Function checks whether IP digits
// are valid or not.
int is_valid(string ip)
{
	// Splitting by "."
	vector<string> ips;
	string ex = "";
	for (int i = 0; i < ip.size(); i++) {
		if (ip[i] == '.') {
			ips.push_back(ex);
			ex = "";
		}
		else {
			ex = ex + ip[i];
		}
	}
	ips.push_back(ex);

	// Checking for the corner cases
	// cout << ip << endl;
	for (int i = 0; i < ips.size(); i++) {
		// cout << ips[i] <<endl;
		if (ips[i].length() > 3
			|| stoi(ips[i]) < 0
			|| stoi(ips[i]) > 255)
			return 0;

		if (ips[i].length() > 1
			&& stoi(ips[i]) == 0)
			return 0;

		if (ips[i].length() > 1
			&& stoi(ips[i]) != 0
			&& ips[i][0] == '0')
			return 0;
	}
	return 1;
}

// Function converts string to IP address
vector<string> convert(string ip)
{
	int l = ip.length();

	// Check for string size
	if (l > 12 || l < 4) {
		cout << "Not Valid IP Address";
	}

	string check = ip;
	vector<string> ans;

	// Generating different combinations.
	for (int i = 1; i < l - 2; i++) {
		for (int j = i + 1; j < l - 1; j++) {
			for (int k = j + 1; k < l; k++) {
				check = check.substr(0, k) + "."
						+ check.substr(k, l - k + 2);
				check
					= check.substr(0, j) + "."
					+ check.substr(j, l - j + 3);
				check
					= check.substr(0, i) + "."
					+ check.substr(i, l - i + 4);

				// Check for the validity of combination
				if (is_valid(check)) {
					ans.push_back(check);
				}
				check = ip;
			}
		}
	}
    return ans;
}

// Driver code
int main()
{
	string A = "1592551013";

	printVector(convert(A));

	return 0;
}

