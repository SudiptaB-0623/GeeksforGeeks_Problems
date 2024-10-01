<h2><a href="https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Array Pair Sum Divisibility Problem</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of integers <strong>nums</strong> and a number <strong>k</strong>, write a function that returns <strong>true </strong>if given array can be divided into pairs such that sum of every pair is divisible by <strong>k</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input : <br>nums</strong> = [9, 5, 7, 3], <strong>k</strong> = 6
<strong>Output: <br></strong>True
<strong>Explanation: <br></strong>{(9, 3), (5, 7)} is a possible solution. 9 + 3 = 12 is divisible by 6 and 7 + 5 = 12 is also divisible by 6.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input : <br>nums </strong>= [4, 4, 4], <strong>k</strong> = 4
<strong>Output: <br></strong>False
<strong>Explanation: <br></strong>You can make 1 pair at max, leaving a single 4 unpaired.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity: </strong>O(n)<br><strong>Expected Space Complexity :&nbsp;</strong>O(n)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= length( nums ) &lt;= 10<sup>5</sup><br>1 &lt;= nums<sub>i</sub> &lt;= 10<sup>5</sup><br>1 &lt;= k &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Directi</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>STL</code>&nbsp;<code>Data Structures</code>&nbsp;