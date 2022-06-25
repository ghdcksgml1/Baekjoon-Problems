# [Diamond V] Matrix Queries - 16332 

[문제 링크](https://www.acmicpc.net/problem/16332) 

### 성능 요약

메모리: 18404 KB, 시간: 620 ms

### 분류

자료 구조(data_structures), 세그먼트 트리(segtree)

### 문제 설명

<p>You are given a matrix of size 2<sup>n</sup> × 2<sup>n</sup>, initially painted in white color. The color of a cell can be either black or white. Let’s define the price of a matrix as:</p>

<ol>
	<li>If a matrix is painted with only one color, the price will be 1 coin;</li>
	<li>Otherwise, you should split the matrix into 4 size-equal matrices, and the price of a matrix will be the sum of submatrices prices plus 1 coin.</li>
</ol>

<p>You are given q queries. Each query gives you the number of row/column x, and you have to change the color of all cells in this row/column (i.e., if a cell is white, it will be black; if a cell is black, it will be white) and find the price of the new matrix.</p>

### 입력 

 <p>The first line contains two integers n and q (0 ≤ n ≤ 20, 1 ≤ q ≤ 10<sup>6</sup>) where n means that the size of the matrix is 2<sup>n</sup> × 2<sup>n</sup> and q means that there are going to be q queries.</p>

<p>Each of the next q lines contains two integers t and x (0 ≤ t ≤ 1, 1 ≤ x ≤ 2<sup>n</sup>). If t = 0, then the x-th row will be changed; otherwise, the x-th column.</p>

### 출력 

 <p>For each query, print a matrix price.</p>

