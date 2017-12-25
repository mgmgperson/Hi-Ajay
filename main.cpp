#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata){
	string *temp=(string*)userdata;
	temp -> append(ptr,size*nmemb/sizeof(char));
	return size*nmemb;
}
const string url = "http://codeforces.com/api/problemset.problems?tags=";
int main(){
    string s,a,data;
   	getline(cin,s);
   	for(int i=0;i<s.length();i++){
   		if(s[i]==' '){
   			a += "%20";
   		} else{
   			a += s[i];
   		}
   	}
   	string query = url + a;
   	CURL *curl = curl_easy_init();
   	CURLcode res;
	curl_easy_setopt(curl, CURLOPT_URL, query.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	auto j = json::parse(data);
	for (auto &x:j["result"]["problems"]){
		cout << x["contestId"].get<int>() << x["index"].get<string>() << ": " << x["name"].get<string>() << endl;
 	}
}

