var
n,i:integer;
a:array[0..100000]of integer;

{
this is comment
}
procedure QuickSort(l,r:integer);
var
i,j,mid:integer;
begin
    if l>=r then exit;
    i:=l;j:=r;mid:=a[(l+r) div 2];
    repeat
         while a[i]<mid do i:=i+1;
         while a[j]>mid do j:=j-1;
         if i<=j then
         begin
             a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
             inc(i);dec(j);
         end;
    until i>j;
    kp(l,j);
    kp(i,r)
end;


begin
    read(n);
    for i:=1 to n do
    read(a[i]);
    QuickSort(1,n);
    for i:=1 to n do
    write(a[i],' ');
end.
