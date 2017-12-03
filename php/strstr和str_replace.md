###strstr和str_replace
```php
$subject = ' hi nihao ';
echo strstr($subject,'hi','hello'),PHP_EOL;//PHP_EOL是换行(随系统的变化而变化)
//尽量使用','代替'.'
echo str_replace(['hi','nihao'],['nihao','hi'],$subject),PHP_EOL;
//第一次替换字符串中的'hi'为'nihao',第二次替换字符串中'nihao'为'hi'
```
###php用yield实现协程
```php
function getLines($file){
  $f = fopen($file,'r');
  try{
    while($line = fgets($f)){
      yield $line;
    }
  }finally{
    fclose($f);
  }
}
foreach(getLines('file.txt') as $n => $line){
  if($n > 5) break;
  echo $line;
}
```

###php用**计算幂运算
```php
$num = 5**5;//5的5次方
```
###使用'...'定义变长的数组
```php
function arrayToStr(...$arr){
  
}
arrayToStr(array(1,23,23,324,));
```