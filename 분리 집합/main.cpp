#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> parent(1000000, make_pair(0, 0));
//vector<int> node_rank(1000000, 0);
int n, m;
int find_root(int node) {

	if (parent[node].first == node)
		return node;
		//����� ����ȭ: �׻� �θ� ��Ʈ���� ����

	return parent[node].first = find_root(parent[node].first);

}

void combine_tree(int node1, int node2) {
	int root1 = find_root(node1);
	int root2 = find_root(node2);

	if (root1 != root2) {
		if (parent[root1].second < parent[root2].second) {
			parent[root1].first = root2;
		}
		else if (parent[root1].second > parent[root2].second){
			parent[root2].first = root1;
		}
		else {
			parent[root1].first = root2;
			parent[root2].second++;
			//node_rank[root1]++;
		}
			

	}

}

int main() {
	ios_base::sync_with_stdio(false); // c�� c++�� ǥ�� ����� ��Ʈ���� ����ȭ�� �����ʾ� �ӵ� ���
	cin.tie(nullptr); // cin���� ��� ���۸� �����(flush) �ʴ´�.
	cout.tie(nullptr);  // ���� ����

	int node1, node2, i, j, relation;
	cin >> n >> m;
	for (i = 0; i <= n; i++) {
		parent[i].first = i;
		//parent[i].second = 0;
		
	}

	for (i = 0; i < m; i++) {
		cin >>relation>> node1 >> node2;
		if (relation == 0)
			combine_tree(node1, node2);
		else {
			if (find_root(node1) != find_root(node2))
				cout << "NO" << "\n";
			else
				cout << "YES" << "\n";
		}
	}

	
}
