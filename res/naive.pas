program naive;
var
  i : integer;
  temp : integer;

procedure go1(a : integer);
begin
  i := a;
  if i mod 2 = 0 then
  begin
    i := i+1;
  end
  else
  begin
    i := i+2;
  end;
  if 0 then
  begin
    i := i+1;
  end;
  temp := i;
end
;

procedure go2();
var i:integer;
begin
  i:=100;
  while i>=0 do
  begin
    i := i-1;
  end;
end;

function go3():integer;
var i, sum:integer;
begin
  sum:=0;
  for i:=1 to 101 do
  begin
    sum := sum+i;
  end;
  go3 := sum;
end;

procedure testCase();
begin
  case i of
    temp:
      temp := 123;
    2:
      temp := 456;
  end;
end;

begin
  i := 1;
  temp := i+2;
  temp := temp*2;
end
.



