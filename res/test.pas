program test;
var
  i : integer;

function go(var a : integer): integer;
begin
  if a = 1 then
  begin
    go := 1;
  end
  else
  begin
    if a = 2 then
    begin
      go := 1;
    end
    else
    begin
      go := go(a - 1) + go(a - 2);
    end
  ;
  end
;
end
;

begin
  i := go(10);
  writeln(i);
end
.


