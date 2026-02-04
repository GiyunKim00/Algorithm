#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, root, a;
    long long int ans = 1;
    int arr[250000];
    set<int> s;
    cin >> n >> root;
    s.insert(root);
    arr[root] = 1;
    n--;
    /**
     * 10, 20, 30이 tree에 있고, root가 20이라고 가정하자.
     * 25를 추가로 넣는다면?
     *  - 25보다 작으면서 가장 큰 값은 20.
     *  - 25보다 크면서 가장 작은 값은 30.
     *  둘 중 하나에 붙여야 함. 이 때 20은 root이므로 depth가 1, 30은 depth가 2임. 따라서 30에 붙이는 것.
     *  lower_bound(25)하면, 25 이상인 값 중 가장 작은 값이므로 30이 나오게 됨.
     *
     *  위의 로직을 기반으로, 3가지 경우가 존재한다.
     *  제일 작은 수일 경우. 제일 큰 수일 경우, 중간에 삽입되는 수일 경우.
     *  상기 설명은 중간삽입의 경우이다.
     *  lower_bound 시 제일 작은 수라면 begin, 제일 큰 수라면 end가 나오게 된다.
     *  begin이라면 그 자체에 바로 붙어야 하고, end라면 prev해서 붙여야 한다.
     *
     */
    while (n--){
        cin >> a;
        auto it1 = s.lower_bound(a);
        if (it1 == s.begin()) arr[a] = arr[*it1] + 1;
        else if (it1 == s.end()) arr[a] = arr[*prev(it1)] + 1;
        else{
            auto it2 = prev(it1);
            arr[a] = max(arr[*it1], arr[*it2]) + 1;
        }
        s.insert(a);
        ans += arr[a];
    }

    cout << ans;

    return 0;
}
