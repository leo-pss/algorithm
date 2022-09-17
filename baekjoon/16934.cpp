#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int GO_MAX = 26; //트라이 노드마다 포인터 개수

struct Trie{
	Trie* go[GO_MAX]; //다음 노드를 가리키는 포인터 배열
	int output; // 이 노드에서 끝나는 아이디 개수
    bool exist; // 이 노드를 사용한 접두사가 있는가?
	
	//생성자
	Trie(){
		fill(go,go+GO_MAX,nullptr);
	 	output=0; exist = false;
	}
	//소멸자
	~Trie(){
		for(int i=0; i<GO_MAX; i++)
			if(go[i]) delete go[i];
	}

	void insert(const char* key, bool find){
		if(*key=='\0'){
            output++;
            if(output > 1) printf("%d",output);
            printf("\n");
            return;
		}
		int next = *key-'a';
        if(!find) printf("%c",*key);
		if(!go[next]) go[next]=new Trie;
        if(go[next]->exist) go[next]->insert(key+1, false);
        else{
            go[next]->exist = true;
            go[next]->insert(key+1, true);
        }
	}
};

int main(void){
    int n;

    Trie *root = new Trie;
    
    scanf("%d",&n);
    while(n--){
        char s[11];
        scanf("%s", s);
        root->insert(s, false);
    }

    delete root;
    return 0;
}