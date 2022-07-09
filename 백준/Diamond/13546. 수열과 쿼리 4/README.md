# [Diamond V] 수열과 쿼리 4 - 13546 

[문제 링크](https://www.acmicpc.net/problem/13546) 

### 성능 요약

메모리: 73524 KB, 시간: 2288 ms

### 분류

mo's(mo), 오프라인 쿼리(offline_queries), 제곱근 분할법(sqrt_decomposition)

### 문제 설명

<p>1보다 크거나 같고, K보다 작거나 같은 수로 이루어져 있는 길이가 N인 수열 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.</p>

<ul>
	<li><code>l r</code>: max{|x − y| : l ≤ x, y ≤ r and A<sub>x</sub> = A<sub>y</sub>} 을 출력한다.</li>
</ul>

### 입력 

 <p>첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000), K (1 ≤ K ≤ 100,000)가 주어진다.</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. (1 ≤ A<sub>i</sub> ≤ K)</p>

<p>셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.</p>

<p>넷째 줄부터 M개의 줄에는 쿼리 l, r가 한 줄에 하나씩 주어진다. (1 ≤ l ≤ r ≤ n)</p>

### 출력 

 <p>각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.</p>

