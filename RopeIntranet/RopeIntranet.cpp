#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<pair<int, int> > &rope);
void makeupTree(vector<pair<int, int> > &rope, vector<int> &segmentTree);
int rangeSum(vector<int> &segmentTree, int lowerBound, int upperBound);
void subtractElement(vector<int> &segmentTree, int element);

static const int M = 10000;

int main() {
    int T = 0;
    scanf("%d", &T);

    for(int tc = 1 ; tc <= T ; ++tc
        ) {
        int N = 0;
        scanf("%d", &N);

        vector<pair<int, int> > rope;
        for(int i = 0 ; i < N ; ++i) {
            int a = -1;
            int b = -1;

            scanf("%d%d", &a, &b);
            rope.push_back(make_pair(a,b));
        }

        printf("Case #%d: %d\n", tc, solve(rope));
    }
    return 0;
}

int solve(vector<pair<int, int> > &rope) {
    int ret = 0;

    vector<int> segmentTree(M * 2 + 1, 0);
    makeupTree(rope, segmentTree);
    
    for(auto ele : rope) {
        ret += rangeSum(segmentTree, 1, ele.second);
        subtractElement(segmentTree, ele.second);
    }
    return ret;
}

void makeupTree(vector<pair<int, int> > &rope, vector<int> &segmentTree) {
    sort(rope.begin(), rope.end());

    for(auto ele : rope) {
        segmentTree[M + ele.second] = 1;
    }
    for(int i = M-1 ; i >= 1 ; --i) {
        segmentTree[i] = segmentTree[i*2] + segmentTree[i*2 +1];
    }
}

int rangeSum(vector<int> &segmentTree, int lowerBound, int upperBound) {
    // return sum of [lowerBound, upperbound)
    int ret = 0;

    int left = M + lowerBound;
    int right = M + upperBound - 1;

    while(left <= right) {
        if(left % 2 == 1) {
            ret += segmentTree[left];
        }
        if(right % 2 == 0) {
            ret += segmentTree[right];
        }

        left = (left + 1) / 2;
        right = (right -1) / 2;
    }

    return ret;
}

void subtractElement(vector<int> &segmentTree, int element) {
    int index = element + M;

    while(index >= 1) {
        --segmentTree[index];
        index /= 2;
    }
}