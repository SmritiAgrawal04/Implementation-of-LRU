#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<list>
#define ll long long

using namespace std;

//template <typename t,typename t2 >
class myLRUcache{
  private:	
  		// mru = 1st , lru = last
  		list<int> lru; 
  		// <key , < value , key iterator>>
		unordered_map<int , pair<int , list<int>::iterator>> my_hash;
		int capacity;

	public:
		myLRUcache(int size){
			capacity = size;
		}


		int get_key(int key){
			auto it = my_hash.find(key);
			if(it != my_hash.end()){
				update(it);
			 return(it->second.first);
			}

			else
				return -1;
		}
		void set_cache(int key, int value){
			if(get_key(key) == -1){
		if(my_hash.size() == capacity){
			my_hash .erase(lru.back());
			lru.pop_back();
		}
		lru.push_front(key);
		my_hash.insert({key , {value , lru.begin()}});
	}
	else{
		auto it = my_hash.find(key);
		update(it);
		my_hash[key] = {value , lru.begin()};
		return;
	}
		}
		void update(unordered_map<int , pair<int , list<int>::iterator>>:: iterator& it){
			lru.erase(it->second.second);
			lru.push_front(it->first);
			it->second.second = lru.begin();
		}
};



int main(){                  
	ll size;
	cin >> size;
	ll q;
	cin >> q;
	myLRUcache *cache = new myLRUcache(size);

	for(ll i = 0 ; i < q; i++){
		string s;
		cin >> s;
		int val;
		if(s[0] == 'G'){
			int key;
			cin >> key;
			val = cache->get_key(key);
			cout << val <<endl;
		}
		
		if(s[0] == 'S'){
			int key ,value;
			cin >> key >> value;
			cache->set_cache(key , value);
		}
	}

	return 0;
}


