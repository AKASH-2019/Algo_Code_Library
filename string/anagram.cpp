// valid anagram
// tc: O(n)+O(n)+O(26/constant) -> O(n)
// sc: freq table is constant size so -> O(1)
#include <bits/stdc++.h>
using namespace std;


int main() {
	
	string s1 = "study", s2 = "dusty";
// 	string s1 = "google", s2 = "facebook";
// 	string s1 = "test", s2 = "atet";
	
	if(s1.length() != s2.length()){
	    cout<<"false"<<endl;
	    return 0;
	}
	
	int frq[26] = {0};
	
    /*
    // 1st approach
	for(int i=0; i<s1.length(); i++){
	    frq[s1[i]-'a'] +=1;
	}
	for(int i=0; i<s2.length(); i++){
	    frq[s2[i]-'a'] -=1;
	}
    */
    // 2nd approach
    for(int i=0; i<s1.length(); i++){
	    frq[s1[i]-'a'] +=1;
	    frq[s2[i]-'a'] -=1;
	}


	for(int i=0; i<26; i++){
	    if(frq[i] != 0){
	        cout<<"false"<<endl;
	        return 0;
	    }
	}
	cout<<"yes"<<endl;
	
	return 0;
}


/*
// using hashmap
// tc: O(n)
// sc: constant space user -> O(1)
bool isAnagram(string a,string b)
{

  if (a.length() != b.length()) {
    return false;
  }

  unordered_map<char,int> Map;

  for (int i = 0; i < a.length(); i++) {
    Map[a[i]]++;
  }

  for (int i = 0; i < b.length(); i++) {
    if (Map.find(b[i]) != Map.end()) {
      Map[b[i]] -= 1;
    } else {
      return false;
    }
  }
 
  for (auto items : Map) {
    if (items.second != 0) {
      return false;
    }
  }
  return true;
}
 

*/


