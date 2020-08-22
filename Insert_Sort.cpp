procedure InsertSort( a: Array[1...n] of Type)
    for k:=2 to n do
    i=a[k]
    j=k-1
    while j>=1 && a[j]>k do a[j+1] := a[j--];
    a[j+1] := i
    

