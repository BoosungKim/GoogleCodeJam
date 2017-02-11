#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int N, C, I;

int main() {
    scanf("%d",&N);

    for(int i=1;i<=N;++i) {
        scanf("%d%d",&C,&I);
        multimap<int, int> num2index;

        for(int j=1;j<=I;++j) {
            int p;
            scanf("%d",&p);
            num2index.insert(pair<int, int>(p, j));
        }

        multimap<int, int> num2index_copy(num2index);
        for(auto elem : num2index) {
            int num = elem.first;
            int index = elem.second;

            num2index_copy.erase(num2index_copy.find(num));

            auto found = num2index_copy.find(C-num);
            if(found != num2index_copy.end()) {
                int index2 = found->second;
                if(index > index2)
                    swap(index, index2);
                
                printf("Case #%d: %d %d\n", i, index, index2);
                break;
            } else {
                num2index_copy.insert(pair<int, int>(num, index));
            }
        }
    }
    return 0;
}
