# [Gold II] 교차개수세기 - 1615 

[문제 링크](https://www.acmicpc.net/problem/1615) 

### 성능 요약

메모리: 26808 KB, 시간: 840 ms

### 분류

자료 구조(data_structures), 세그먼트 트리(segtree), 정렬(sorting)

### 문제 설명

<p>각각 N(1 ≤ N ≤ 2,000)개의 쌍으로 이루어진 2N개의 정점과 M(1 ≤ M ≤ N×(N-1)/2)개의 간선으로 구성된 이분그래프가 주어질 때 서로 교차하는 총 개수를 구하는 것이다.</p>

<ul>
	<li>교차 조건 : 한 독립 집합 A와 다른 독립 집합 B가 연결된 두 개의 간선을 (A<sub>1</sub>, B<sub>1</sub>), (A<sub>2</sub>, B<sub>2</sub>)라 한다면 A<sub>1</sub> < A<sub>2</sub>, B<sub>1</sub> > B<sub>2</sub> 또는 A<sub>1</sub> > A<sub>2</sub>, B<sub>1</sub> < B<sub>2</sub>를 만족한다면 두 간선을 교차한다고 한다.</li>
</ul>

<p style="text-align: center;"><img alt="" height="227" src="https://www.acmicpc.net/upload/201004/ryck.png" width="152"></p>

<p>예를 들어 위에 예에서 (3, 2)는 (1, 5)와 (5, 1)과 교차한다. 이 문제를 해결하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫 줄에 N과 간선의 개수 M이 주어진다. 그 다음 줄부터 M+1번째 줄까지 두 개의 수(i, j)가 주어지는데 이는 왼쪽 그룹의 i번 정점과 오른쪽 그룹의 j번 정점을 연결하는 간선이 있다는 의미이다. 중복되는 간선이 입력으로 주어지지 않는다.</p>

### 출력 

 <p>입력에서 주어진 간선이 교차하는 총 개수를 출력한다.</p>

