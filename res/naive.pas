program naive;
var
  i : integer;

function go1(a : integer): integer;
begin
  i:=i+a;
  i:=i-2;
  i:=i*3;
  i:=i/-4;
end
;

function go2(a : integer): integer;
begin
  i:=i+a;
  i:=i-2;
  i:=i*3;
  i:=i/-4;
end
;

begin
  go1(123);
  go2(123);
  writeln(i);
end
.



