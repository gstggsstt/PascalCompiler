program test;

const
  pi := 3.14;

var
  i : integer;
  temp : real;

function testRecursive(a : integer): integer;
begin
  if a = 1 then
    testRecursive := 1
  else
    if a = 2 then
      testRecursive := 1
    else
      testRecursive := testRecursive(a - 1) + testRecursive(a - 2)
;
end ;

function testFor(a: integer): integer;
var x,y,z :integer;
begin
  x:=1;
  y:=1;
  for i:=3 to a do
  begin
    z:=x+y;
    x:=y;
    y:=z;
  end;
  testFor:=y;
end;

function testWhile(a: integer): integer;
var x,y,z : integer;
begin
  x:=1;
  y:=1;
  i:=3;
  while i<=a do
  begin
    z:=x+y;
    x:=y;
    y:=z;
    i:=i+1;
  end;
  testWhile:=y;
end;

function testRepeat(n : real):real;
var x,z : real;
  y : integer;
begin
  x:=1;
  y:=1;
  z:=1.0;
  i:=3;
  repeat
    z:=x+y;
    x:=y;
    y:=z;
    i:=i+1;
  until i>n;
  testRepeat:=y;
end;

procedure testProced(a:integer; b:real);
begin
  writeln(a);
  writeln(b);
end;

procedure testLogical();
begin
  if (1>2) and (3<4) then writeln('1');
  if (1>2) or (3<4) then writeln('2');
  if not (1>2) and (3<4) then writeln('3');
  for i:=100 downto 1 do
  begin
    if i mod 2 = 0 then
    begin
      write(i, ' ');
    end;
  end;
  writeln();
end;

procedure testCase(x: char);
begin
  case x of
    'a': writeln('g','o','t',' ','A');
    'b': writeln('g','o','t',' ','B');
    'c': writeln('g','o','t',' ','C');
  end;
end;

function testConst(r : real) : real;
begin
  testConst := pi * r * r;
end;

begin
  { test assign and comment }
  i := testRecursive(10);
  writeln('F',':',i);

  writeln('F',':',testFor(11));
  writeln('F',':',testWhile(12));
  writeln('F',':',testRepeat(13));

  testProced(3.7, 5.6);
  testProced(2, 5.6);
  testLogical();
  testCase('b');
  testCase('d');

  testLabel:
  read(temp);
  writeln(testConst(temp));
  if temp>100 then goto testLabel2;
  goto testLabel;
  testLabel2:;
end
.



