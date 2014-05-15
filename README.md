Input: set of coordinates C, with |C| = n+1
Output: set splines which is composed of n 5-tuples.

Create new array a of size n + 1 and for i = 0 ,..., n set a<sub>i</sub> = y<sub>i</sub>
Create new arrays b and d each of size n.
Create new array h of size n and for i = 0 ,..., n-1 set h<sub>i</sub> = x<sub>i+1</sub> - x<sub>i</sub>
Create new array α of size n and for i = 1 ,..., n-1 set α<sub>i</sub> = (3 / h[i] * (a<sub>i+1</sub> - a<sub>i</sub>)) - (3 / h<sub>i-1</sub> * (a<sub>i</sub> - a<sub>i-1</sub>)).
Create new arrays c, l, μ, and z each of size n+1
Set  l<sub>0</sub> = 1, u<sub>0</sub> = z<sub>0</sub> = 0
For  i = 1 ,..., n-1
*Set l<sub>i</sub> = 2 *( {x}<sub>i+1</sub>-{x}<sub>i-1</sub>) - {h}<sub>i-1</sub>u<sub>i-1</sub>.
*Set {\mu}_{i}= \frac{ {h}_{i}}{{l}_{i} } .
*Set {z}_{i} =  \frac{ {\alpha}_{i}-{h}_{i-1}{z}_{i-1}}{{l}_{i} } .
*Set  l_n = 1; z_n = c_n = 0. \,
For  j = n-1 , n-2 , \ldots , 0 
Set  c_j = z_j - {\mu}_j c_{j+1} \,
Set  b_j = \frac{{a}_{j+1}-{a}_{j} }{{h}_{j} } -  \frac{ {h}_{j} \left ( {c}_{j+1} +2{c}_{j}  \right ) }{ 3} 
Set  d_j = \frac{{c}_{j+1}-{c}_{j} }{3{h}_{j} } 
Create new set Splines and call it output_set. Populate it with n splines S.
For i = 0 , \ldots , n-1
Set Si,a = ai
Set Si,b = bi
Set Si,c = ci
Set Si,d = di
Set Si,x = xi
Output output_set