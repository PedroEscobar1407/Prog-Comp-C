#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, op, x;
	while (cin >> n) {
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool isStack = true, isQueue = true, isPQueue = true; //indicadores para determinar que estructura de datos es

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &op, &x);

			if (op==1){
				if (isStack)
					s.push(x);
				if (isQueue)
					q.push(x);
				if (isPQueue)
					pq.push(x);
			}
				
			if (op==2){
				if (isStack) {
					if (s.empty() || s.top() != x)
						isStack = false;
					else
						s.pop();
				}
				if (isQueue) {
					if (q.empty() || q.front() != x)
						isQueue = false;
					else
						q.pop();
				}
				if (isPQueue) {
					if (pq.empty() || pq.top() != x)
						isPQueue = false;
					else
						pq.pop();
				}
			}
		}

		if (isStack == true && isQueue == false && isPQueue == false)
			cout << "stack" << endl;
		else if (isStack == false && isQueue == true && isPQueue == false)
			cout << "queue" << endl;
		else if (isStack == false && isQueue == false && isPQueue == true)
			cout << "priority queue" << endl;
		else if (isStack == false && isQueue == false && isPQueue == false)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;
	}
}