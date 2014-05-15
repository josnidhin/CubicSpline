[Algorithm from Wiki](http://en.wikipedia.org/w/index.php?title=Spline_%28mathematics%29&oldid=288288033#Algorithm_for_computing_natural_cubic_splines)

Input: set of coordinates C, with |C| = n+1

Output: set splines which is composed of n 5-tuples.

Create new array a of size n + 1 and for i = 0 ,..., n set a<sub>i</sub> = y<sub>i</sub>

Create new arrays b and d each of size n.

Create new array h of size n and for i = 0 ,..., n-1 set h<sub>i</sub> = x<sub>i+1</sub> - x<sub>i</sub>

Create new array α of size n and for i = 1 ,..., n-1 set α<sub>i</sub> = (3 / h[i] x (a<sub>i+1</sub> - a<sub>i</sub>)) - (3 / h<sub>i-1</sub> x (a<sub>i</sub> - a<sub>i-1</sub>)).

Create new arrays c, l, μ, and z each of size n+1

Set l<sub>0</sub> = 1, u<sub>0</sub> = z<sub>0</sub> = 0

For i = 1 ,..., n-1
    *Set l<sub>i</sub> = 2 x( x<sub>i+1</sub>-x<sub>i-1</sub>) - h<sub>i-1</sub> x u<sub>i-1</sub>.
    *Set u<sub>i</sub> = h<sub>i</sub>/l<sub>i</sub>.
    *Set z<sub>i</sub> = (α<sub>i-1</sub> - (h<sub>i-1</sub> x z<sub>i-1</sub>)) / l<sub>i</sub>
    *Set  l<sub>n</sub> = 1; z<sub>n</sub> = c<sub>n</sub> = 0

For  j = n-1 , n-2 ,..., 0 
    *Set  c<sub>j</sub> = z<sub>j</sub> - u<sub>j</sub> x c<sub>j+1</sub>
    *Set  b<sub>j</sub> = ((a<sub>j+1</sub> - a<sub>j</sub>) / h<sub>j</sub>) - (h<sub>j</sub> x (c<sub>j+1</sub> + 2 x c<sub>j</sub>) / 3)
    *Set  d<sub>j</sub> = (c<sub>j+1</sub> - c<sub>j</sub>) / (3 x h<sub>j</sub>)

Create new set Splines and call it output_set. Populate it with n splines S.

For i = 0 ,..., n-1
    *Set Si,a = ai
    *Set Si,b = bi
    *Set Si,c = ci
    *Set Si,d = di
    *Set Si,x = xi

Output output_set