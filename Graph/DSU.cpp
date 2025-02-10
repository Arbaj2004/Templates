struct UnionFind {
	int n;
	vector<int> parent;
	vector<int> size;

    multiset<int>st;

	UnionFind(int n) {
		parent.resize(n);
		size.resize(n, 1);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
            st.insert(1);
		}
	}

	int get(int a) {
		return parent[a] = (parent[a] == a ? a : get(parent[a]));
	}

    //to get all available sizes in graph min or max
    void merge(int a,int b){
        st.erase(st.find(size[get(a)]));
        st.erase(st.find(size[get(b)]));
        st.insert(size[get(a)]+size[get(b)]);
    }

	void Union1(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) return;

		if (size[a] < size[b]) swap(a, b);
		parent[b] = a;
        merge(a,b);
		size[a] += size[b];
	}
};
